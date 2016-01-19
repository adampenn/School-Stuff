#include "schedule.h"
#include <stdlib.h>

struct node {
  int pid;
  struct node* next;
  struct node* prev;
	int quanta;
};

struct node* cur;
struct node* array[4];
int queue;

/**
 * Function to initialize any global variables for the scheduler.
 */
void init(){
	queue = 1;
  array[0] = array[1] = array[2] = array[3] = cur = NULL;
}

/**
 * Function to add a process to the scheduler
 * @Param pid - the ID for the process/thread to be added to the
 *      scheduler queue
 * @Param priority - priority of the process being added
 * @return true/false response for if the addition was successful
 */
int addProcess(int pid, int priority){
  priority--;
  if (!array[priority]) {
  	array[priority] = (struct node*) malloc( sizeof(struct node));
  	array[priority]->pid = pid;
    int quanta = 4 - (priority);
  	array[priority]->quanta = quanta;
    array[priority]->next = array[priority];
    array[priority]->prev = array[priority];
  } else {
    cur = (struct node*) malloc(sizeof(struct node));
    cur->pid = pid;
		int quanta = 4 - (priority);
		cur->quanta = quanta;
    array[priority]->prev->next = cur;
    cur->prev = array[priority]->prev;
    array[priority]->prev = cur;
    cur->next = array[priority];
  }
	return 0;
}

/**
 * Function to remove a process from the scheduler queue
 * @Param pid - the ID for the process/thread to be removed from the
 *      scheduler queue
 * @Return true/false response for if the removal was successful
 */
int removeProcess(int pid){
  int i;
  for (i = 0; i <= 3; i++) {
		if (array[i]) {
			if (array[i]->pid == pid) {
				if(array[i]->next == array[i]) {
					free(array[i]);
					array[i] = NULL;
					return 1;
				} else {
					cur = array[i];
					array[i]->prev->next = array[i]->next;
					array[i]->next->prev = array[i]->prev;
					array[i] = array[i]->next;
					free(cur);
					return 1;
				}
			} else {
        cur = array[i]->next;
        while (cur != array[i] && cur->pid != pid) {
          cur = cur->next;
        }
        if (cur->pid == pid) {
          cur->prev->next = cur->next;
          cur->next->prev = cur->prev;
          free(cur);
          return 1;
        }
      }
		}
	}
	return 0;
}
/**
 * Function to get the next process from the scheduler
 * @Param time - pass by pointer variable to store the quanta of time
 * 		the scheduled process should run for
 * @Return returns the thread id of the next process that should be
 *      executed, returns -1 if there are no processes
 */
int nextProcess(int *time){
  int exicuted = 1;
  while (exicuted) {
    if(queue == 1) {
      if (array[0]) {
        *time = array[0]->quanta;
        if(array[0]) {
          int value = array[0]->pid;
          array[0] = array[0]->next;
          exicuted = 0;
          queue++;
          return value;
        }
      }
      queue++;
    } else if (queue == 2) {
      if (array[1]) {
        *time = array[1]->quanta;
        if(array[1]) {
          int value = array[1]->pid;
          array[1] = array[1]->next;
          exicuted = 0;
          queue++;
          return value;
        }
      }
      queue++;
    } else if (queue == 3) {
      if (array[2]) {
        *time = array[2]->quanta;
        if(array[2]) {
          int value = array[2]->pid;
          array[2] = array[2]->next;
          queue++;
          exicuted = 0;
          return value;
        }
      }
      queue++;
    } else if (queue == 4) {
      if (array[3]) {
        *time = array[3]->quanta;
        if(array[3]) {
          int value = array[3]->pid;
          array[3] = array[3]->next;
          exicuted = 0;
          queue = 1;
          return value;
        }
      }
      queue = 1;
    }
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
	int value = 0;
  int i;
	for (i = 0; i <= 3; i++) {
		if(array[i]) {
			value = 1;
		}
	}
	return value;
}
