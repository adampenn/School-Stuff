/*
 * File: pager-lru.c
 * Author:       Andy Sayler
 *               http://www.andysayler.com
 * Adopted From: Dr. Alva Couch
 *               http://www.cs.tufts.edu/~couch/
 *
 * Project: CSCI 3753 Programming Assignment 4
 * Create Date: Unknown
 * Modify Date: 2012/04/03
 * Description:
 * 	This file contains an lru pageit
 *      implmentation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "simulator.h"

void pageit(Pentry q[MAXPROCESSES]) {

	/* This file contains the stub for an LRU pager */
	/* You may need to add/remove/modify any part of this file */

	/* Static vars */
	static int initialized = 0;
	static int tick = 1; // artificial time
	static int timestamps[MAXPROCESSES][MAXPROCPAGES];

	/* Local vars */
	int proctmp;
	int pagetmp;
	int proc;
	int pc;
	int page;
	static int out[MAXPROCESSES][MAXPROCPAGES];

	/* initialize static vars on first run */
	if (!initialized) {
		for (proctmp = 0; proctmp < MAXPROCESSES; proctmp++) {
			for (pagetmp = 0; pagetmp < MAXPROCPAGES; pagetmp++) {
				timestamps[proctmp][pagetmp] = 0;
				out[proctmp][pagetmp] = 0;
			}
		}
		initialized = 1;
	}

	int minProc, minPage, minTime = INT_MAX;
	for (proc = 0; proc < MAXPROCESSES; proc++) {
		if (q[proc].active) {
			pc = q[proc].pc;
			page = pc / PAGESIZE;
			if (!q[proc].pages[page]) {
				if (!pagein(proc, page)) {
					if(!out[proc][page]) {
						for (proctmp = 0; proctmp < MAXPROCESSES; proctmp++) {
						  for (pagetmp = 0; pagetmp < MAXPROCPAGES; pagetmp++) {
							  if(q[proctmp].pages[pagetmp]){
								  if (timestamps[proctmp][pagetmp] < minTime) {
								    minTime = timestamps[proctmp][pagetmp];
								    minProc = proctmp;
								    minPage = pagetmp;
								  }
								}
							}
						}
					}
					pageout(minProc, minPage);
					out[proc][page] = 1;
				} else {
					out[proc][page] = 0;
				}
			} else {
			  timestamps[proc][page]=tick;
			}
		}
	}
	tick++;
}
