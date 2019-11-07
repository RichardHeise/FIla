#include <stdio.h>
#include <stdlib.h>

typedef struct s_aviao {
    int ID;
    int UT;
} t_aviao;

struct t_nodo {
    t_aviao chave;
    struct t_nodo *prox;
    struct t_nodo *prev;
};
typedef struct t_nodo t_nodo;

struct t_fila {
    t_nodo *ini;
    t_nodo *atual;
    t_nodo *fim;
    int tamanho;
};
typedef struct t_fila t_fila;

int inicializa_fila(t_fila *l);

int fila_vazia(t_fila *l);

int tamanho_fila(t_fila *l);

int enfileira(t_aviao item, t_fila *l);

int desenfileira(t_aviao *item, t_fila *l);

int remove_fila(t_aviao chave, t_aviao *item, t_fila *l);

void imprime_fila(t_fila *l);