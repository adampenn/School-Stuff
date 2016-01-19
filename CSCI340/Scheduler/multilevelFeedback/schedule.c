#include "schedule.h"
#include <stdlib.h>
#include <stdio.h>


struct node {
  int pid, age;
  struct node* next;
};

struct node* array[3];
struct node* cur;
struct node* cur2;

/**
 * Function to initialize any global variables for the scheduler.
 */
void init(){
  array[0] = array[1] = array[2] = cur = cur2 = NULL;
}

/**
 * Function called every simulated time period to provide a mechanism
 * to age the scheduled processes and trigger feedback if needed.
 */
void age(){
  int i, removed;
  for (i = 1; i <= 2; i++) {
    do {
      if(array[i]) {
        cur = array[i];
        cur->age++;
        if (cur->age >= 1000) {
          int pid = cur->pid;
          if (i == 1) {
            removeProcess(pid);
            addProcess(pid, 0);
          } else {
            removeProcess(pid);
            addProcess(pid, 1);
          }
          removed = 1;
        } else {
          removed = 0;
        }
      } else {
        removed = 0;
      }
    } while (removed);
    if(array[i]) {
      cur = array[i]->next;
      while(cur != NULL) {
        cur->age++;
        if (cur->age >= 1000) {
          int pid = cur->pid;
          cur = cur->next;
          if (i == 1) {
            removeProcess(pid);
            addProcess(pid, 0);
          } else {
            removeProcess(pid);
            addProcess(pid, 1);
          }
        } else {
          cur = cur->next;
        }
      }
    }
  }
}

/**
 * Function to add a process to the scheduler
 * @Param pid - the ID for the process/thread to be added to the
 *      scheduler queue
 * @Param priority - priority of the process being added
 * @return true/false response for if the addition was successful
 */
int addProcess(int pid, int priority){
  if (!array[priority]) {
    array[priority] = (struct node*) malloc( sizeof(struct node));
    array[priority]->next = NULL;
    array[priority]->pid = pid;
    array[priority]->age = 0;
  } else {
    cur = array[priority];
    while (cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = (struct node*) malloc( sizeof(struct node));
    cur = cur->next;
    cur->next = NULL;
    cur->pid = pid;
    cur->age = 0;

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
  for (i = 0; i <= 2; i++) {
    if(array[i]) {
      if(array[i]->pid == pid) {
        cur = array[i];
        array[i] = array[i]->next;
        free(cur);
        return 1;
      }
    }
    if(array[i]) {
      cur = array[i];
      while (cur->next != NULL && cur->pid != pid) {
        cur = cur->next;
      }
      if(cur->pid == pid) {
        cur2 = array[i];
        while (cur2->next != cur) {
          cur2 = cur2->next;
        }
        cur2->next = cur->next;
        free(cur);
        return 1;
      }
    }
  }
  return 0;
}
/**
 * Function to get the next process from the scheduler
 * @Param time - pass by pointer variable to store the quanta of time
 *    the scheduled process should run for, returns -1 if should run to completion.
 * @Return returns the thread id of the next process that should be
 *      executed, returns -1 if there are no processes
 */
int nextProcess(int *time){
  if(array[0]) {
    *time = -1;
    int pid = array[0]->pid;
    removeProcess(pid);
    return pid;
  }
  if(array[1]) {
    *time = 4;
    int pid = array[1]->pid;
    removeProcess(pid);
    addProcess(pid, 1);
    return pid;
  }
  if(array[2]) {
    *time = 1;
    int pid = array[2]->pid;
    removeProcess(pid);
    addProcess(pid, 2);
    return pid;
  }
  return -1;
}

/**
 * Function that returns a boolean 1 True/0 False based on if there are any
 * processes still scheduled
 * @Return 1 if there are processes still scheduled 0 if there are no more
 *    scheduled processes
 */
int hasProcess(){
  int i, value = 0;
  for (i = 0; i <= 2; i++) {
    if(array[i])
      value = 1;
  }
  return value;
}
