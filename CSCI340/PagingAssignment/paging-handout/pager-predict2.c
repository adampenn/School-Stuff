/*
 * File: pager-predict.c
 * Author:       Andy Sayler
 *               http://www.andysayler.com
 * Adopted From: Dr. Alva Couch
 *               http://www.cs.tufts.edu/~couch/
 *
 * Project: CSCI 3753 Programming Assignment 4
 * Create Date: Unknown
 * Modify Date: 2012/04/03
 * Description:
 * 	This file contains a predictive pageit
 *      implmentation.
 */

#include <stdio.h>
#include <stdlib.h>

#include "simulator.h"

void pageit(Pentry q[MAXPROCESSES]) {

		/* Local vars */
		int proc;
		int pc;
		int page;
		int out;
		static int prog5[MAXPROCESSES];
		static int prevpage[MAXPROCESSES];
		static int initialized=0;
		if(!initialized){
      for(proc=0;proc<MAXPROCESSES;proc++){
	  		prevpage[proc]=-1;
	  		prog5[proc]=-1;
	  	}
	  	initialized=1;
		}
		/* Select first active process */
		for (proc = 0; proc < MAXPROCESSES; proc++) {
			/* Is process active? */
			if (q[proc].active) {
				/* Dedicate all work to first active process*/
				pc = q[proc].pc; 		        // program counter for process
				page = pc / PAGESIZE; 		// page the program counter needs
				switch (page) {
					case 0:
						if(prevpage[proc]!=-1){
							if (prevpage[proc] == 3) {
								prog5[proc] = 1;
							} else {
								prog5[proc] = 0;
							}
						}
					  pagein(proc, 0);
					  pagein(proc, 1);
						for(out = 2; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
					case 1:
					  pagein(proc, 1);
						pagein(proc, 2);
						pagein(proc, 0);
						for(out = 3; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
					case 2:
					  pagein(proc, 2);
						pagein(proc, 3);
						pagein(proc, 0);
						for(out = 1; out <= 1; out++) {
							pageout(proc, out);
						}
						for(out = 4; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
					case 3:
						if (prog5[proc]==1) {
							pagein(proc, 3);
							pagein(proc, 0);
							for(out = 1; out <= 2; out++) {
					  		pageout(proc, out);
					  	}
					  	for(out = 4; out <= 19; out++) {
					  		pageout(proc, out);
					  	}
						} else if (prog5[proc] == -1) {
							pagein(proc, 0);
							pagein(proc, 3);
					  	pagein(proc, 10);
					  	pagein(proc, 11);
							pagein(proc, 4);
					  	for(out = 1; out <= 2; out++) {
					  		pageout(proc, out);
					  	}
					  	for(out = 5; out <= 9; out++) {
					  		pageout(proc, out);
					  	}
					  	for(out = 12; out <= 19; out++) {
					  		pageout(proc, out);
					  	}
					  } else {
					  	pagein(proc, 3);
					  	pagein(proc, 10);
					  	pagein(proc, 11);
							pagein(proc, 4);
							pagein(proc, 0);
					  	for(out = 1; out <= 2; out++) {
					  		pageout(proc, out);
					  	}
					  	for(out = 5; out <= 9; out++) {
					  		pageout(proc, out);
					  	}
					  	for(out = 12; out <= 19; out++) {
					  		pageout(proc, out);
					  	}
						}
					  prevpage[proc] = page;
					  break;
					case 4:
						pagein(proc, 4);
						pagein(proc, 5);
						for(out = 0; out <= 3; out++) {
							pageout(proc, out);
						}
						for(out = 6; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
					case 5:
						pagein(proc, 5);
						pagein(proc, 6);
						for(out = 0; out <= 4; out++) {
							pageout(proc, out);
						}
						for(out = 7; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
					case 6:
						pagein(proc, 6);
						pagein(proc, 7);
						for(out = 0; out <= 5; out++) {
							pageout(proc, out);
						}
						for(out = 8; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
					case 7:
						pagein(proc, 7);
						pagein(proc, 8);
						for(out = 0; out <= 6; out++) {
							pageout(proc, out);
						}
						for(out = 9; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
					case 8:
						pagein(proc, 8);
						pagein(proc, 9);
						pagein(proc, 0);
						for(out = 1; out <= 7; out++) {
							pageout(proc, out);
						}
						for(out = 10; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
					case 9:
						pagein(proc, 9);
						pagein(proc, 10);
						for(out = 0; out <= 8; out++) {
							pageout(proc, out);
						}
						for(out = 11; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
					case 10:
					  pagein(proc, 0);
						pagein(proc, 10);
						pagein(proc, 11);
						for(out = 1; out <= 9; out++) {
							pageout(proc, out);
						}
						for(out = 12; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
					case 11:
						pagein(proc, 0);
						pagein(proc, 11);
						pagein(proc, 12);
						for(out = 1; out <= 10; out++) {
							pageout(proc, out);
						}
						for(out = 13; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
					case 12:
						pagein(proc, 12);
						pagein(proc, 13);
						pagein(proc, 9);
						pagein(proc, 0);
						for(out = 1; out <= 8; out++) {
							pageout(proc, out);
						}
						for(out = 10; out <= 11; out++) {
							pageout(proc, out);
						}
						for(out = 14; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
					case 13:
						pagein(proc, 9);
						pagein(proc, 0);
						pagein(proc, 13);
						pagein(proc, 14);
						for(out = 1; out <= 8; out++) {
							pageout(proc, out);
						}
						for(out = 10; out <= 12; out++) {
							pageout(proc, out);
						}
						for(out = 15; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
					case 14:
						pagein(proc, 14);
						for(out = 0; out <= 13; out++) {
							pageout(proc, out);
						}
						for(out = 15; out <= 19; out++) {
							pageout(proc, out);
						}
						prevpage[proc] = page;
					  break;
				}
			}
		}
}
