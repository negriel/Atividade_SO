#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include "funcoes.c"
#include "funcoes.h"

int main () {
 //preciso criar shared memory como função e ter a fila dentro, e criar pipes tb
    srand(time(NULL)); //crio uma seed pra gerar numero aleatório
    int i, pid;
    for (i = 1; i <= 3; ++i) { //loop para criar processos
        pid = fork();
        if (pid != 0) { //se sou o processo filho: saio do ciclo!
            break;
        }
    }
    if(i<=3){//se for um processo filho, gere numeros aleatórios 
    gera_numeros(i);
    }
    return 0;

}

