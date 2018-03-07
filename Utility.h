#ifndef UTILITY_H
#define UTILITY_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "math.h"
#include <sys/time.h>
#include <pthread.h>

typedef struct {
	int* boundaries;
	int dimensions;
} Index;

typedef struct {
	int* array;
	Index index;
	size_t used;
	size_t size;
} Array;

typedef struct {
	Array *a;
    int numThreads;
    int ID;
}arg_struct;

int calculateRow(int n, int LinearIndex);

int calculateCol(int n, int LinearIndex);

int LinearIndex(Array *a, Index *i);

void calculateSize(Array *a);

void initIndex(Index *index, int n0, int n1);

void allocateArray(int **ptr_p_A , int size);

void initElements(Array *a, int startIndex);

void initArray(Array *a, int n0, int n1);

void freeArray(Array *a);

void printM(int *prnt, int size);

#endif
