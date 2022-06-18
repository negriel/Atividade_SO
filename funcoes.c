    #include <stdio.h>
    #include <stdlib.h>// necessário p/ as funções rand() e srand()
    #include <sys/types.h>
    #include <unistd.h>
    #include <time.h>//necessário p/ função time()
    #include "funcoes.h"

    
    void teste (int i){
    printf("o processo %d, com o pid %d, está gerando numeros aleatorios\n",i, getpid());
    int j;
    
  
    for (j=0; j < 10; j++)
    {
    // gerando valores aleatórios na faixa de 0 a 1000
    printf("%d\n", rand() % 1000);
    }

    struct Fila{
        int inicio, final, qtd;
        int numero[MAX];
    };

    Fila* cria_Fila(){
        Fila *fi;
        fi = (Fila*) malloc(sizeof(struct Fila));
        if(fi != NULL){
            fi->inicio = 0;
            fi-> final = 0;
            fi-> qtd = 0;
        }
        return fi;
    }
    void libera_Fila(Fila* fi){
        free(fi);
    }
    int tamanho_Fila(Fila* fi){
        if(fi == NULL){
            return -1;
        }
        return fi->qtd;
    }
    int Fila_cheia(Fila* fi){
        if(fi == NULL)
        return -1;
        if (fi->qtd == MAX)
            return 1;
        else
            return 0;
    }

    int Fila_vazia(Fila* fi){
        if(fi == NULL)
            return -1;
        if(fi->qtd == 0)
            return 1;
        else
            return 0;
    }

    int insereFinal_Fila(Fila* fi, int numero){
        if(fi == NULL || fi-> qtd == MAX)
            return 0;
        fi->numero[fi->final] = numero;
        fi->final = (fi->final+1)%MAX;
        fi->qtd++;
        return 1;
    }

    int removeInicio_Fila(Fila* fi){
        if(fi == NULL|| fi->qtd == 0)
            return 0;
        fi->inicio = (fi->inicio+1)%MAX;
        fi->qtd--;
        return 1;
    }

    void imprime_fila(Fila* fi){
        if(fi == NULL)
            return;
        int n, i = fi->inicio;
        for(n=0;n < fi->qtd; n++){
            printf("%d ",fi->numero[i]);
            i = (i+1)%MAX;
        }
    }

    }