#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define N 16
#define THREAD 4

long int sum = 0;

void * total(void *args) {
	int* array = (int *) args;
	
	for(int i=0 ; i<N/THREAD ; i++)
		sum += array[i];
	
	pthread_exit(NULL);
}

int main() {
	pthread_t t[THREAD];
	
	int A[N] = {68,34,64,95,35,78,65,93,51,67, 7,77, 4,73,52,91}; //masukin angkanya
	
	//buat jadi 4 thread
	for(int i=0 ; i< THREAD ; i++) {
		pthread_create(&t[i], NULL, total, &A[i*N/THREAD] );  //nah makanya dia dibagi bagi di sini
	}
	
	//gabungin threadnya pake join
	for(int i=0 ; i<THREAD ; i++) {
		pthread_join(t[i], NULL);
	}
	
	printf("Total : %ld\n", sum);
	return 0;
}
