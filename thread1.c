#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 50

void *function(void *x) {
	long tid;
	tid = (long) x;
	printf("Se creó el thread no. %ld \n", tid);
}

int main(){
	pthread_t threads[NTHREADS];
	int tcreated;
	long i;

	for(i = 0; i<NTHREADS; i++){
		printf("Creando el hilo %ld \n", i);
		tcreated = pthread_create(&threads[i], NULL, function, (void *) i);
	}
	pthread_exit(NULL);
	return 1;
}
