//
// Adam J. Penn
//

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string>
#include <limits.h>
#include <sys/time.h>

#include "helper-routines.h"

/*Define Global Variables*/
#define READEND 0
#define WRITEEND 1
pid_t   childpid;
timeval t1, t2, st, sp;
int numtests, testsRan;
double elapsedTime, RTT, TRTT, mintime, maxtime;


void sigusr1_handler(int sig){
	if (testsRan != 0) {
		testsRan++;
		gettimeofday(&sp, NULL);
		RTT = (sp.tv_sec - st.tv_sec) * 1000.0;
		RTT += (sp.tv_usec - st.tv_usec) / 1000.0;
		// printf("SU1:%f\n",RTT);
		// fflush(stdout);
		TRTT += RTT;
		if (RTT < mintime) {
			mintime = RTT;
		}
		if (RTT > maxtime) {
			maxtime = RTT;
		}
	}
	if (testsRan == 0) {
		testsRan++;
	}
	gettimeofday(&st, NULL);
	kill(getppid(), SIGUSR2);
}

void sigusr2_handler(int sig){
	testsRan++;
	gettimeofday(&sp, NULL);
	RTT = (sp.tv_sec - st.tv_sec) * 1000.0;
	RTT += (sp.tv_usec - st.tv_usec) / 1000.0;
	TRTT += RTT;
	// printf("%f\n", RTT);
	if (RTT < mintime) {
		mintime = RTT;
	}
	if (RTT > maxtime) {
		maxtime = RTT;
	}
	gettimeofday(&st, NULL);
	if (testsRan != numtests) {
		kill(childpid, SIGUSR1);
	} else {
		kill(childpid, SIGTSTP);
	}
}

// Parents's Results for Signal IPC mechanisms
// Process ID is 79279, Group ID is 1000
// Round trip times
// Average 0.004312
// Maximum 0.854000
// Minimum 0.003000
// Elapsed Time 43.385000
void sigstop_handler(int sig){
	testsRan++;
	gettimeofday(&sp, NULL);
	RTT = (sp.tv_sec - st.tv_sec) * 1000.0;
	RTT += (sp.tv_usec - st.tv_usec) / 1000.0;
	TRTT += RTT;
	if (RTT < mintime) {
		mintime = RTT;
	}
	if (RTT > maxtime) {
		maxtime = RTT;
	}
	printf("Child's Results for Signal IPC mechanisms\n");
	printf("Process ID is %d, Group ID is %d\n", getpid(), getgid());
	double average = TRTT/numtests;
	printf("Average %f\n", average);
	printf("Maximum %f\n", maxtime);
	printf("Minimum %f\n", mintime);
	printf("Round trip times\n");
	gettimeofday(&t2, NULL);
	// compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	printf("Elapsed Time %f\n", elapsedTime);
	exit(0);
}


//
// main - The main routine
//
int main(int argc, char **argv){
	//Initialize Constants here

  //variables for Pipe
	int p2c[2], c2p[2], nbytes;
	//byte size messages to be passed through pipes
	char    childmsg[] = "1";
	char    parentmsg[] = "2";
	char    quitmsg[] = "q";
	char readbuffer[2];

  /*Three Signal Handlers You Might Need
   *
   *I'd recommend using one signal to signal parent from child
   *and a different SIGUSR to signal child from parent
   */
  Signal(SIGUSR1,  sigusr1_handler); //User Defined Signal 1
  Signal(SIGUSR2,  sigusr2_handler); //User Defined Signal 2
  Signal(SIGTSTP, sigstop_handler);

  //Default Value of Num Tests
	if(argc == 3) {
		numtests = atoi(argv[2]);
	} else {
		numtests=10000;
	}
	testsRan = TRTT = maxtime = 0;
	mintime = 99999;
  //Determine the number of messages was passed in from command line arguments
  //Replace default numtests w/ the commandline argument if applicable
  if(argc<2){
  	printf("Not enough arguments\n");
  	exit(0);
  }

  printf("Number of Tests %d\n", numtests);
  // start timer
	gettimeofday(&t1, NULL);
	if(strcmp(argv[1],"-p")==0){
	  //code for benchmarking pipes over numtests
		pipe(p2c);
		pipe(c2p);
		childpid = fork();
		if (childpid) {
			// parent
			close(p2c[READEND]);
			close(c2p[WRITEEND]);
			for (int i = 0; i < numtests; i++) {
				gettimeofday(&st, NULL);
				write(p2c[WRITEEND], childmsg, 2);
				nbytes = read(c2p[READEND], readbuffer, sizeof(readbuffer));
				gettimeofday(&sp, NULL);
				RTT = (sp.tv_sec - st.tv_sec) * 1000.0;
				RTT += (sp.tv_usec - st.tv_usec) / 1000.0;
				TRTT += RTT;
				if (RTT < mintime) {
					mintime = RTT;
				}
				if (RTT > maxtime) {
					maxtime = RTT;
				}
			}
			write(p2c[WRITEEND], quitmsg, 2);
			wait(NULL);
		} else {
			// child
			close(c2p[READEND]);
			close(p2c[WRITEEND]);
			nbytes = read(p2c[READEND], readbuffer, sizeof(readbuffer));
			while (strcmp(readbuffer,"q") != 0) {
				gettimeofday(&st, NULL);
				write(c2p[WRITEEND], parentmsg, 2);
				nbytes = read(p2c[READEND], readbuffer, sizeof(readbuffer));
				gettimeofday(&sp, NULL);
				RTT = (sp.tv_sec - st.tv_sec) * 1000.0;
				RTT += (sp.tv_usec - st.tv_usec) / 1000.0;
				TRTT += RTT;
				if (RTT < mintime) {
					mintime = RTT;
				}
				if (RTT > maxtime) {
					maxtime = RTT;
				}
			}
			printf("Child's Results for Pipe IPC mechanisms\n");
			printf("Process ID is %d, Group ID is %d\n", getpid(), getgid());
			printf("Round trip times\n");
			double average = TRTT/numtests;
			printf("Average %f\n", average);
			printf("Maximum %f\n", maxtime);
			printf("Minimum %f\n", mintime);
			gettimeofday(&t2, NULL);
			// compute and print the elapsed time in millisec
			elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
			elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
			printf("Elapsed Time %f\n", elapsedTime);
			exit(0);
		}
		printf("Parent's Results for Pipe IPC mechanisms\n");
		printf("Process ID is %d, Group ID is %d\n", getpid(), getgid());
		printf("Round trip times\n");
		double average = TRTT/numtests;
		printf("Average %f\n", average);
		printf("Maximum %f\n", maxtime);
		printf("Minimum %f\n", mintime);
  	// stop timer
  	gettimeofday(&t2, NULL);
	  // compute and print the elapsed time in millisec
	  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	  printf("Elapsed Time %f\n", elapsedTime);
	}
	if(strcmp(argv[1],"-s")==0){
		//code for benchmarking signals over numtests
    childpid = fork();
		if (childpid) {
			//parent
			gettimeofday(&st, NULL);
		  kill(childpid, SIGUSR1);
			wait(NULL);
		} else {
			//child
			while(1);
		}
		printf("Parent's Results for Signal IPC mechanisms\n");
		printf("Process ID is %d, Group ID is %d\n", getpid(), getgid());
		printf("Round trip times\n");
		double average = TRTT/numtests;
		printf("Average %f\n", average);
		printf("Maximum %f\n", maxtime);
		printf("Minimum %f\n", mintime);
		gettimeofday(&t2, NULL);
		// compute and print the elapsed time in millisec
		elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
		elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
		printf("Elapsed Time %f\n", elapsedTime);
	}
}
