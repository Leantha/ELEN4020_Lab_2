#include "Transpose.h"

pthread_t thread_id[MAX_THREADS];

void swap(int* elem1, int * elem2)
{
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

void *transpose (void * arg)
{
	arg_struct* args = (arg_struct *)arg;
	int n = args->numThreads; 
	int id= args->ID;
	int b = *args->a->index.boundaries;
	int* ptrA = (args->a->array);

	for (int i=id; i< b-1; i=i+n)//row
	{
		for (int j = i+1; j <b; j++) //col
		{
			int x = i*b+j;
			int y = j*b+i;
			swap(ptrA+x, ptrA+y);
		}	
	
	}
	return NULL;
}

double runPThreads(arg_struct *ptr, int n, Array *a)
{	
	if(n > MAX_THREADS) n = MAX_THREADS;
	//pthread_t thread_id[MAX_THREADS];  
	double start= 0.0;
	for(int i = 0; i < n; i++)
   	 {
    		ptr->numThreads = n;
		ptr->a = a;
    		ptr->ID = i;
    		//printf ("i %d\n", i);
		if( i==0){start = omp_get_wtime();}
       		pthread_create(&thread_id[i], NULL, transpose, (void*) ptr);
       		ptr++;
    	}
	for(int i = 0; i < n; i++)
   	{
                pthread_join(thread_id[i], NULL);
    	}
	return start;
    
}

double getPTTransposeTime(int nthreads, int boundary)
{
	int n = nthreads;
	int b = boundary;
	  
	Array a;
	initArray(&a, b, b);
	
	
	arg_struct *args = malloc(sizeof(arg_struct)*n);
	args->numThreads = n;
	args->a = &a;
	arg_struct *ptr = args; 

	//begin pthreads
	double start = runPThreads(ptr, n, &a);
    
    	double end = omp_get_wtime();
    	
    
    	freeArray(&a);
    	free(args);
    
	return ((end - start)*1000);
}

double getOMPTransposeTime(int nthreads, int boundary)
{
	int n = nthreads;
	int b = boundary;
	
	if(n > MAX_THREADS) n = MAX_THREADS;
	omp_set_num_threads(n);
	
	Array a;
	initArray(&a, b, b);
	//printM(a.array, a.size);
	
	double start = 0.0;
	double end = start;
	start = omp_get_wtime();
	#pragma omp parallel
	{
    	arg_struct *args = malloc(sizeof(arg_struct));
		args->numThreads = n;
		args->a = &a;
		arg_struct *ptr = args;
		
    	int id = omp_get_thread_num();
		int nthrds = omp_get_num_threads();
		if (id == 0) n = nthrds;
    	ptr->numThreads = n;
		ptr->a = &a;
    	ptr->ID = id;
    	//printf ("i %d\n", ptr->ID);
        transpose((void*) ptr);
        //free(args);
    }
	end = omp_get_wtime();
    //printM(a.array, a.size);
    freeArray(&a);
    
	return ((end-start)*1000);
}
