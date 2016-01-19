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

	/* This file contains the stub for a predictive pager */
	/* You may need to add/remove/modify any part of this file */

	/* Static vars */
	static int initialized = 0;
	static int tick = 1; // artificial time
	static int previous[MAXPROCESSES];
	static int isProg5[MAXPROCESSES];

	/* Local vars */
	int proctmp;

	/* initialize static vars on first run */
	if (!initialized) {
		/* Init complex static vars here */
		for(proctmp=0; proctmp < MAXPROCESSES; proctmp++)
		{
			previous[proctmp]=-1;
			isProg5[proctmp]=-1;
		}
		initialized = 1;
	}

	/* TODO: Implement Predictive Paging */
	int process;
	int tmppage;
	int page;
	int iszero;

	for(process=0; process<MAXPROCESSES; process++)
	{
		iszero=0;
		for(tmppage=0; tmppage < MAXPROCPAGES; tmppage++)
		{
			if(q[process].pages[tmppage]==1)
			{
				iszero++;
			}
		}
		if(iszero==0)
		{
			isProg5[process]=-1;
		}


		if(q[process].active==1)
		{
			page=q[process].pc/PAGESIZE;
			if(page==0)
			{
				if(previous[process]==3)
				{
					isProg5[process]=1;
				}
				else if(previous[process]>0)
				{
					isProg5[process]=0;
				}
				//not process 5
				pagein(process,0);
				pagein(process,1);
				int i;
				for(i=2; i<=19; i++)
				{
					pageout(process,i);
				}
				previous[process]=page;
			}
			if(page==1)
			{
				pagein(process,1);
				pagein(process,2);
				int i;
				for(i=3; i<=19; i++)
				{
					pageout(process,i);
				}
				pageout(process,0);
				previous[process]=page;
			}
			if(page==2)
			{
				pagein(process, 2);
				pagein(process, 3);
				int i;
				for(i=4; i<=19; i++)
				{
					pageout(process,i);
				}
				pageout(process,0);
				pageout(process,1);
				previous[process]=page;
			}
			if(page==3)
			{
				if(isProg5[process]==1)
				{
					pagein(process,3);
					pagein(process,0);
					pageout(process,1);
					pageout(process,2);
                                        int i;
					for(i=4; i<=19; i++)
					{
						pageout(process,i);
					}
					previous[process]=page;
				}
				else if(isProg5[process]==-1)
				{
					pagein(process,3);
					pagein(process,4);
					pagein(process,10);
					pagein(process,11);
                                        pagein(process,0);
					int i;
					for(i=1; i<=2; i++)
					{
						pageout(process,i);
					}
					int j;
					for(j=5; j<=9; j++)
					{
						pageout(process,j);
					}
					int k;
					for(k=12; k<=19; k++)
					{
						pageout(process,k);
					}
					previous[process]=page;
				}
				else if(isProg5[process]==0)
				{
					pagein(process,3);
					pagein(process,4);
					pagein(process,10);
					pagein(process,11);
					int i;
					for(i=0; i<=2; i++)
					{
						pageout(process,i);
					}
					int j;
					for(j=5; j<=9; j++)
					{
						pageout(process,j);
					}
					int k;
					for(k=12; k<=19; k++)
					{
						pageout(process,k);
					}
					previous[process]=page;
				}
			}
			if(page==4)
			{
				pagein(process,4);
				pagein(process,5);
				int i;
				for(i=6; i<=19; i++)
				{
					pageout(process,i);
				}
                                int j;
                                for(j=0; j<=3; j++)
                                {
                                       pageout(process,j);
                                }
				previous[process]=page;
			}
			if(page==5)
			{
				pagein(process, 5);
				pagein(process, 6);
				int i;
				for(i=7; i<=19; i++)
				{
					pageout(process,i);
				}
				int j;
				for(j=0; j<=4; j++)
				{
					pageout(process,j);
                                }
				previous[process]=page;
			}
			if(page==6)
			{
				pagein(process, 6);
				pagein(process, 7);
				int i;
				for(i=8; i<=19; i++)
				{
					pageout(process,i);
				}
				int j;
				for(j=0; j<=5; j++)
				{
					pageout(process,j);
				}
				previous[process]=page;
			}
			if(page==7)
			{
				pagein(process, 7);
				pagein(process, 8);
				int i;
				for(i=9; i<=19; i++)
				{
					pageout(process,i);
				}
				int j;
				for(j=0; j<=6; j++)
				{
					pageout(process,j);
				}
				previous[process]=page;
			}
			if(page==8)
			{
				pagein(process, 8);
				pagein(process, 0);
                                pagein(process, 9);
				int i;
				for(i=10; i<=19; i++)
				{
					pageout(process,i);
				}
				int j;
				for(j=1; j<=7; j++)
				{
					pageout(process,j);
				}
				previous[process]=page;
			}
			if(page==9)
			{
                                pagein(process, 9);
                                pagein(process, 10);
				int i;
				for(i=11; i<=19; i++)
				{
					pageout(process,i);
				}
				int j;
				for(j=0; j<=8; j++)
				{
					pageout(process,j);
				}
				previous[process]=page;
			}
			if(page==10)
			{
				pagein(process,10);
				pagein(process,11);
                                pagein(process,0);
				int i;
				for(i=12; i<=19; i++)
				{
					pageout(process,i);
				}
				int j;
				for(j=1; j<=9; j++)
				{
					pageout(process,j);
				}
				previous[process]=page;
			}
			if(page==11)
			{
				pagein(process,11);
				pagein(process,12);
                                pagein(process,0);
				int i;
				for(i=13; i<=19; i++)
				{
					pageout(process,i);
				}
				int j;
				for(j=1; j<=10; j++)
				{
					pageout(process,j);
				}
				previous[process]=page;
			}
			if(page==12)
			{
				pagein(process, 12);
				pagein(process, 13);
				int i;
				for(i=14; i<=19; i++)
				{
					pageout(process,i);
				}
				int j;
				for(j=1; j<=8; j++)
				{
					pageout(process,j);
				}
				for(j=10; j<=11; j++)
				{
					pageout(process,j);
				}
				previous[process]=page;
			}
			if(page==13)
			{
				pagein(process, 13);
				pagein(process, 9);
				pagein(process, 0);
				pagein(process, 14);
				int i;
				for(i=15; i<=19; i++)
				{
					pageout(process,i);
				}
				int j;
				for(j=1; j<=8; j++)
				{
					pageout(process,j);
				}
				int k;
				for(k=10; k<=12; k++)
				{
					pageout(process,k);
				}
				previous[process]=page;
			}
			if(page==14)
			{
				pagein(process, 14);
				//pagein(process, 15);
				int i;
				for(i=15; i<=19; i++)
				{
					pageout(process,i);
				}
				int j;
				for(j=0; j<=13; j++)
				{
					pageout(process,j);
				}
				previous[process]=page;
			}
			if(page==15)
			{
				pagein(process, 15);
				pagein(process, 16);
				int i;
				for(i=17; i<=19; i++)
				{
					pageout(process,i);
				}
				int j;
				for(j=0; j<=14; j++)
				{
					pageout(process,j);
				}
				previous[process]=page;
			}
			if(page==16)
			{
				pagein(process, 16);
				pagein(process, 17);
				int i;
				for(i=18; i<=19; i++)
				{
					pageout(process,i);
				}
				int j;
				for(j=0; j<=15; j++)
				{
					pageout(process,j);
				}
				previous[process]=page;
			}
			if(page==17)
			{
				pagein(process, 17);
				pagein(process, 18);
				//pageout(process,19);
				int j;
				for(j=0; j<=16; j++)
				{
					pageout(process,j);
				}
                                pageout(process,19);
				previous[process]=page;
			}
			if(page==18)
			{
				pagein(process, 18);
				pagein(process, 19);
				int j;
				for(j=0; j<=17; j++)
				{
					pageout(process,j);
				}
				previous[process]=page;
			}
			if(page==19)
			{
				pagein(process, 19);
				pagein(process, 0);
				int j;
				for(j=1; j<=18; j++)
				{
					pageout(process,j);
				}
				previous[process]=page;
			}
		}
		/* advance time for next pageit iteration */
	}
	tick++;
}
