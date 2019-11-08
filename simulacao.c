#include <stdlib.h>
#include <stdio.h>
#include "lib_fila.h"

int min_fila (t_fila Prat[]) {
    int i, min;
    min = 0;
    for (i = 1; i < 4; ++i) {
        if (tamanho_fila(&Prat[min]) > tamanho_fila(&Prat[i])) {
            min = i;
        }
    }
    return min;
}

int main () {
    int i, j, uni_tempo, quant_avioes;

    t_aviao aviao;

    t_fila Prateleira[4];
    t_fila Decolagem[3];

    for (i = 0; i < 4; ++i) {
        inicializa_fila(&Prateleira[i]);
    }

    for (i = 0; i < 3; ++i) {
        inicializa_fila(&Decolagem[i]);
    }
    printf("Unidade de tempo: ");
    scanf("%d", &uni_tempo);
    printf("\n");

    aviao.ID = 1;
    int menor = 0;
    for (i = 0; i < uni_tempo; ++i) {
        scanf("%d", &quant_avioes);
        for (j = 0; j < quant_avioes; ++j) {
            scanf("%d", &aviao.UT);
            menor = min_fila(Prateleira);
            enfileira(aviao, &Prateleira[menor]);
            aviao.ID += 2;
        }
    }

    for (i = 0; i < 4; ++i) {
        printf("Prateleira %d:", i);
        imprime_fila(&Prateleira[i]);
        printf("\n");
    }

    return 1;
}
