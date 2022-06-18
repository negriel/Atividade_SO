#define MAX 10

typedef struct Fila Fila;
void gera_numeros (int i);
Fila* cria_Fila();
void libera_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_cheia(Fila* fi);
int Fila_vazia(Fila* fi);
int insereFinal_Fila(Fila* fi, int numero);
int removeInicio_Fila(Fila* fi);
void imprime_fila(Fila* fi);

