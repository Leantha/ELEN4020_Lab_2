#include "Utility.h"

int calculateRow(int n, int LinearIndex)
{	//Only true if array is square
	int ret = LinearIndex/n;
	return ret;
}

int calculateCol(int n, int LinearIndex)
{
 //Only true if array is square
 	int ret = LinearIndex%n;
	return (ret);
}

int LinearIndex(Array *a, Index *i)
{
	int boundaryA = *a->index.boundaries;
	int *in = i->boundaries;
	int row = *(in);
	in++;
	int col = *(in);
	int linearIndex = boundaryA*row + col;
	return linearIndex;
}

void calculateSize(Array *a)
{
	int count = 0;
	int *n = a->index.boundaries;
	a->size = 1;
	//printf ("%d\n", a->index.dimensions);
	while (count <  a->index.dimensions)
	{
		a->size *= (*n);
		n++;
		count ++;
	}
}

void initIndex(Index *index, int n0, int n1)
{
	index->boundaries = (int *)calloc(2, sizeof(int));
	int *temp = index->boundaries;
	*temp = n0;
	temp++;
	*temp = n1;
	index->dimensions = 2;
}

void allocateArray(int **ptr_p_A , int size)
{
 	*ptr_p_A = (int*)calloc(size, sizeof(int)); //	initiated to zero by default
}

void initElements(Array *a, int startIndex)
{
	int range = a->size - startIndex;
	int row = calculateRow( *a->index.boundaries, startIndex);
	int col = calculateCol( *a->index.boundaries, startIndex);
	int n = *a->index.boundaries;
	for (int i = 0; i < range; i++) 
	{
		*(a->array+startIndex) = row*n+col;	
		col ++;
		a->used++;
		startIndex++;
		if (col >= n)
		{ 
			row++; 
			col= 0;
		}
	}
	
}

void initArray(Array *a, int n0, int n1)
{	
	initIndex(&a->index, n0, n1);
	calculateSize(a);
	allocateArray(&a->array,a->size); 
	a->used = 0; 
	initElements(a, 0);	
}

/*void doubleArray(Array *a)
{
	if(a->used == a->size)
	{
		a->size *= 2;
		a->array = (int*)realloc(a->array, a->size * sizeof(int));
		initElements(a, a->size/2-1)
		
	}
}*/

/*void insertAtArray(Array *a, Index *index, int element)
{
	int i = LinearIndex(a, index);
	int *temp = a->array; 
	temp[i] = element;
	free(index->boundaries);
	index->boundaries = NULL;
}*/

void freeArray(Array *a)
{
	free(a->array);
	a->array = NULL;
	free(a->index.boundaries);
	a->index.boundaries = NULL;
	a->used = a->size = 0;
}

void printM(int *prnt, int size)
{
	int count = 0;
	for (int i=0; i < size; i++)
		{
			printf ("%d \t", *prnt);
			prnt++;
			count++;
			if(count==sqrt(size))
			{printf ("\n");
			count = 0;}
		}
}

