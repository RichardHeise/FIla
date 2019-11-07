#include "lib_fila.h"

int inicializa_fila(t_fila *l){
    
    t_nodo *first, *last;
    
    first = (t_nodo *) malloc (sizeof(t_nodo));
    if (first == NULL)
        return 0;

    last = (t_nodo *) malloc (sizeof(t_nodo));
    if (last == NULL){
        free(first);
        return 0;
    }
    
    l->ini = first;
    first->prox = last;
    first->prev = NULL;

    l->fim = last;
    last->prox = NULL;
    last->prev = first;
    
    l->atual = NULL;
    
    l->tamanho = 0;

    return 1;
}

int fila_vazia(t_fila *l){
    return ((l->tamanho) ? 0 : 1 );
}

int tamanho_fila(t_fila *l) {
    return (fila_vazia(l)) ? -1 : l->tamanho;
}

int enfileira(t_aviao item, t_fila *l){

    t_nodo *new;
    new = (t_nodo *) malloc (sizeof(t_nodo));
    if (new == NULL)
        return 0;

    new->chave = item;

    new->prox = l->fim;
    new->prev = l->fim->prev;
    l->fim->prev->prox = new;
    l->fim->prev = new;

    l->tamanho++;

    return 1;
}

int desenfileira(t_aviao *item, t_fila *l){
    
    if (fila_vazia(l)){
        return 0;
    }

    *item = l->ini->prox->chave;
    l->ini->prox = l->ini->prox->prox;

    l->tamanho--;

    return 1;
}

int remove_fila(t_aviao chave, t_aviao *item, t_fila *l){

    t_nodo *p;

    if (fila_vazia(l)){
        return 0;
    }

    

    l->tamanho--;

    return 1;
}

void imprime_fila(t_fila *l){
    
    t_nodo *ptraux = (t_nodo *) malloc(sizeof(t_nodo));
    
    if (fila_vazia(l))
        return;
    ptraux = l->ini;
    while (ptraux->prox->prox != NULL) {
        printf("%d ", ptraux->prox->chave);
        ptraux = ptraux->prox;
    } 
    
    printf("\n");

}
