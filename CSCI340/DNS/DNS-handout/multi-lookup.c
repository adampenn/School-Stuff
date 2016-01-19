/*
 * File: lookup.c
 * Author: Andy Sayler
 * Project: CSCI 3753 Programming Assignment 2
 * Create Date: 2012/02/01
 * Modify Date: 2012/02/01
 * Description:
 * 	This file contains the reference non-threaded
 *      solution to this assignment.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

#include "util.h"
#include "queue.h"

#define MINARGS 3
#define USAGE "<inputFilePath> <outputFilePath>"
#define SBUFSIZE 1025
#define INPUTFS "%1024s"

#define NUM_THREADS	3

struct CLAS{
  int argc;
  char** argv;
};


int requesting = 1;
pthread_mutex_t mutex;
queue q;
FILE* inputfp = NULL;
FILE* outputfp = NULL;

/* Function to read files */
void* ReadFiles(void* ptr) {
  /* Setup Local Vars and Handle void* */
  char errorstr[SBUFSIZE];
  char* hostname;

  int i;
  struct CLAS* hiimavariable = (struct CLAS*) ptr;
  int argc = hiimavariable->argc;
  char** argv = hiimavariable->argv;

  /* Check Arguments */
  if(argc < MINARGS){
	  fprintf(stderr, "Not enough arguments: %d\n", (argc - 1));
	  fprintf(stderr, "Usage:\n %s %s\n", argv[0], USAGE);
	  exit(EXIT_FAILURE);
  }

  /* Open Output File */
  outputfp = fopen(argv[(argc-1)], "w");
  if(!outputfp){
	  perror("Error Opening Output File");
    exit(EXIT_FAILURE);
  }

  /* Loop Through Input Files */
  for(i=1; i<(argc-1); i++){

	  /* Open Input File */
	  inputfp = fopen(argv[i], "r");
	  if(!inputfp){
	    sprintf(errorstr, "Error Opening Input File: %s", argv[i]);
	    perror(errorstr);
	    break;
    }

    /* Read File and Process*/
    hostname = ((char *) malloc(SBUFSIZE));
	  while(fscanf(inputfp, INPUTFS, hostname) > 0){
      pthread_mutex_lock(&mutex);
      while (queue_is_full(&q)) {
        pthread_mutex_unlock(&mutex);
        usleep((rand()%100));
        pthread_mutex_lock(&mutex);
      }
      queue_push(&q, ((void *) hostname));
      pthread_mutex_unlock(&mutex);
      hostname = ((char *) malloc(SBUFSIZE));
    }
  }

  /* Exit, Returning NULL*/
  return NULL;
}

void* resolver() {
  // Local Vars
  char* hostname;
  char firstipstr[INET6_ADDRSTRLEN];

  /* Lookup hostname and get IP string */
  pthread_mutex_lock(&mutex);
  while (!queue_is_empty(&q) || requesting) {
    while (queue_is_empty(&q)) {
      if (!requesting && queue_is_empty(&q)) {
        return NULL;
      }
      pthread_mutex_unlock(&mutex);
      usleep((rand()%100));
      pthread_mutex_lock(&mutex);
    }
    hostname = ((char *) queue_pop(&q));
    pthread_mutex_unlock(&mutex);
  	if(dnslookup(hostname,firstipstr,sizeof(firstipstr))==UTIL_FAILURE){
 	    fprintf(stderr, "dnslookup error: %s\n", hostname);
	    strncpy(firstipstr, "", sizeof(firstipstr));
  	}
	  /* Write to Output File */
    pthread_mutex_lock(&mutex);
	  fprintf(outputfp, "%s,%s\n", hostname, firstipstr);
    pthread_mutex_unlock(&mutex);
  }
  /* Exit, Returning NULL*/
  return NULL;
}


int main(int argc, char* argv[]){

  int numCPU = sysconf( _SC_NPROCESSORS_ONLN );
  int numThreads = 2, i;
  if (numCPU > 2) {
    numThreads = numCPU;
  }
  // printf("%d\n",  numCPU);

  /* Local Vars */
  pthread_t threads[NUM_THREADS];
  if(!queue_init(&q, 10)) {
    fprintf(stderr, "Failed to initilze the queue");
  }
  pthread_mutex_init(&mutex,NULL);

  // init class to hold argv and argc
  struct CLAS* ptr = (struct CLAS*) malloc( sizeof(struct CLAS));
  ptr->argv = argv;

  ptr->argc = argc;
  // create threads
  pthread_create(&threads[0],NULL,ReadFiles, (void *) ptr);

  // try numCPU = sysconf( _SC_NPROCESSORS_ONLN );

  for (i = 1; i <= numThreads; i++) {
    pthread_create(&threads[i],NULL,resolver, NULL);
  }
  // wait for requester to join back
  pthread_join(threads[0], NULL);
  requesting = 0;
  /* Close Output File */
  for (i = 1; i <= numThreads; i++) {
    pthread_join(threads[i], NULL);
  }

  fclose(inputfp);
  fclose(outputfp);

  return EXIT_SUCCESS;
}
