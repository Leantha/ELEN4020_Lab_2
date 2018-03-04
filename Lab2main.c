#include <stdlib.h>
#include <stdio.h>
#include "Lab_2.c"

int main()
{

int length=5;
int testArray[length][length];
//Allocate matrix
for (int i=0;i<length;i++)
{
	for (int j=0;j<length;j++)
	{
	testArray[i][j]=i*length+j;
	}
}
//Swap elements
for (int i=0;i<length-1;i++)
{
	for (int j=i+1;j<length;j++)
	{
	if (i != j)
	{swap(&testArray[i][j],&testArray[j][i]);}
	}
}
//Print transposed matrix
for (int i=0;i<length;i++)
{
	for (int j=0;j<length;j++)
	{
	printf("%d ", testArray[i][j]);
	if (j==length-1)
	 printf("\n\n");
	}
}

return 0;
}
