#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/wait.h>
#include <time.h>

int codigoHijo(){
	srand(time(NULL));  //srand(getpid())
	int r = rand() % 10;
	printf("Hijo PID: %d\n", getpid());
	exit(r); //es igual que el return
}


int main(){
	int valor_fork;

	for(int i=0; i<5; i++){
		valor_fork = fork();
		if(valor_fork ==0){
			//hijo
			exit(codigoHijo()); //es igual que el return
		} else if(valor_fork>0){
			//padre
			continue;
		} else{
			//error
		}
	}

	int status;
	pid_t pid_hijo;
	for(int j= 0; j<5;j++){
		//cual de los 5 hijo terminó
		pid_hijo = wait(&status);
		printf("Padre dice: terminó el hijo %d con status %d", pid_hijo,WEXITSTATUS(status));
	}
}
