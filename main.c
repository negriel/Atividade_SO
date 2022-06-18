#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h> 
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include "funcoes.h"
#define ever ; ;

typedef struct area_compartilhada{
    int x;
}shared_memory;

int main () {
    int fd;//identificador da área compartilhada
    shared_memory *shm;

    fd = shm_open("/sharedmem",O_RDWR|O_CREAT, S_IRUSR|S_IWUSR); //abre ou cria área compartilhada

    ftruncate(fd, sizeof(shared_memory));//ajusta o tamanho da área compartilhada para sizeof(value)
    
    shm = mmap(NULL, sizeof(shared_memory), PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    //mapeia a area no espaco de enderecamento deste processo

    for(ever){
        shm->x = rand() % 1000+1;
        printf("valor escrito %i/n",shm->x);
        
    }

    srand(time(NULL)); //crio uma seed pra gerar numero aleatório
    int i, pid;
    for (i = 1; i <= 3; ++i) { //loop para criar processos
        pid = fork();
        if (pid != 0) { //se sou o processo filho: saio do ciclo!
            break;
        }
    }
    if(i<=3){//se for um processo filho, gere numeros aleatórios 
    teste(i);
    }
    return 0;

}

