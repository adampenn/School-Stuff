#include "schedule.h"
#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  struct node* next;
  struct node* prev;
};

struct node* head;
struct node* cur;

/**
 * Function to initialize any global variables for the scheduler.
 */
void init(){
  head = cur = NULL;
}

/**
 * Function to add a process to the scheduler
 * @Param pid - the ID for the process/thread to be added to the
 *      scheduler queue
 * @return true/false response for if the addition was successful
 */
int addProcess(int pid){
	if (!head) {
    head = (struct node*) malloc( sizeof(struct node));
    head->value = pid;
    head->next = head;
    head->prev = head;
  } else {
    cur = (struct node*) malloc(sizeof(struct node));
    cur->value = pid;
    head->prev->next = cur;
    cur->prev = head->prev;
    head->prev = cur;
    cur->next = head;
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
	if (head) {
    if (head->value == pid) {
      if(head->next == head) {
        free(head);
        head = NULL;
        return 1;
      } else {
        cur = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        free(cur);
        return 1;
      }
    }
    cur = head;
	  while (cur->next != head && cur->value != pid) {
			cur = cur->next;
		}
		if (cur->value == pid) {
      cur->prev->next = cur->next;
      cur->next->prev = cur->prev;
      free(cur);
      return 1;
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
	*time = 4;
	if(head) {
    int value = head->value;
    head = head->next;
    return value;
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
