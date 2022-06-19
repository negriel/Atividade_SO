#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <time.h>
#include "funcoes.h"
#define ever ; ;

typedef struct area_compartilhada{
    int x;
}shared_memory;

int main () {
    key_t key;
    int shmid;//identificador da área compartilhada
    shared_memory *shm;

    key = ftok("/sharedmem",'R');

    shmid = shmget(key,sizeof(shared_memory),0644|IPC_CREAT); //abre ou cria área compartilhada

    shm = shmat(shmid, (void *)0, 0);

    for(int i =0; i<=300;i++){
        shm->x = rand() % 1000+1;
        printf("valor escrito %i\n",shm->x);
        
    }
    shmdt(&shm);
    shmctl(shmid, IPC_RMID, NULL);

    /*srand(time(NULL)); //crio uma seed pra gerar numero aleatório
    int i, pid;
    for (i = 1; i <= 3; ++i) { //loop para criar processos
        pid = fork();
        if (pid != 0) { //se sou o processo filho: saio do ciclo!
            break;
        }
    }
    if(i<=3){//se for um processo filho, gere numeros aleatórios 
    teste(i);
    }*/
    return 0;

}

