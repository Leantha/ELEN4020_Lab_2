#ifndef TRANSPOSE_H
#define TRANSPOSE_H
#include <pthread.h>
#include "Utility.h"
#include <omp.h>

#define MAX_THREADS 128
//Tile struct is used to chunk memory for threads

void swap(int* elem1, int * elem2);

void *transpose (void * arg);

double getPTTransposeTime(int nthreads, int boundary);

double getOMPTransposeTime(int nthreads, int boundary);

pthread_t thread_id[MAX_THREADS];

#endif
