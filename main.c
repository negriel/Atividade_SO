#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include "funcoes.h"

int main () {
    srand(time(NULL));
    int i, pid;
    for (i = 1; i <= 3; ++i) {
        pid = fork();
        if (pid != 0) { //se sou o processo filho: saio do ciclo!
            break;
        }
    }
    if(i<=3){
    teste(i);
    }
    return 0;

}

