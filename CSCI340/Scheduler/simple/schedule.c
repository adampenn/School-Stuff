#include "schedule.h"
#include <stdlib.h>

// Adam J. Penn

struct node {
  int value;
  struct node* next;
  struct node* prev;
};

struct node* head;
struct node* tail;
struct node* cur;

/**
 * Function to initialize any global variables for the scheduler.
 */
void init(){
  head = tail = cur = NULL;
}

/**
 * Function to add a process to the scheduler
 * @Param pid - the ID for the process/thread to be added to the
 *      scheduler queue
 * @return true/false response for if the addition was successful
 */
int addProcess(int pid){
  if (!head) {
    tail = head = (struct node*) malloc( sizeof(struct node));
    head->value = pid;
    head->next = NULL;
    head->prev = NULL;
  } else {
    cur = head;
    while (cur->next) {
      cur = cur->next;
    }
    cur->next = (struct node*) malloc( sizeof(struct node));
    cur->next->prev = cur;
    cur = cur->next;
    cur->value = pid;
    cur->next = NULL;
    tail = cur;
  }
  return 0;
}

/**
 * Function to get the next process from the scheduler
 *
 * @Return returns the thread id of the next process that should be
 *      executed, returns -1 if there are no processes
 */
int nextProcess(){
  if(head) {
    cur = head;
    head = head->next;
    if(head) {
      head->prev = NULL;
    }
    return cur->value;
    free(cur);
  }
	return -1;
}

/**
 * Function that returns a boolean 1 True/0 False based on if there are any
 * processes still scheduled
 * @Return 1 if there are processes still scheduled 0 if there are no more
 *		scheduled processes
 */
int hasProcess(){
  if(head) {
    return 1;
  }
	return 0;
}
