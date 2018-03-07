#include <stdlib.h>
#include <stdio.h>
#include "Transpose.h"

int main()
{
	int threads []={4,8,16,64,128};
	int boundary []= {128,1024,8192};
	
	int numOfThreads= sizeof(threads)/sizeof(int);
	int numOfBoundaries= sizeof(boundary)/sizeof(int);
	double PT_time;
	double OMP_time;
	printf("--------------------------------------------------------------------------\n");
	printf("---Comparative Table Showing the Time Performance of 2 Thread Libraries---\n");
	printf("--------------------------------------------------------------------------\n");
	printf("|Libary\t|N0=N1=Boundary\t| Number of Threads \t| Time (s)\t|\n");
	printf("--------------------------------------------------------------------------\n");
	for (int i = 0; i<numOfBoundaries; i++)
	{
		for(int j = 0; j<numOfThreads; j++)
		{
			PT_time = getPTTransposeTime(threads[j],boundary[i]);
			OMP_time = getOMPTransposeTime(threads[j],boundary[i]);
			printf("|PT\t|%d\t\t|%d\t\t\t|%lf\t|\n", boundary[i],threads[j], PT_time);
			printf("|OMP\t|%d\t\t|%d\t\t\t|%lf\t|\n", boundary[i], threads[j], OMP_time);
			printf("--------------------------------------------------------------------------\n");
		}
		
	}

}




