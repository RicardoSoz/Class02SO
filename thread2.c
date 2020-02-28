#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS	5

struct thread_data{
		int thread_id;
		char *message;
		};

void *PrintValues(void *threadarg){
	struct thread_data *data;
	data = (struct thread_data *) threadarg;
	printf("Id del hilo: %i \n", data->thread_id);
	printf("Message: %s %i \n", data->message, data->thread_id);
}

int main(){
	pthread_t threads[NTHREADS];
	struct thread_data td[NTHREADS];
	int tcreated, i;

	for(i=0; i < NTHREADS; i++){
		printf("Creando al hilo %i\n", i);
		td[i].thread_id = i;
		td[i].message = "Este es el mensaje";
		tcreated = pthread_create(&threads[i], NULL, PrintValues, (void *)&td[i]);
	}
	pthread_exit(NULL);
}

