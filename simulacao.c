#include <stdlib.h>
#include <stdio.h>
#include "lib_fila.h"


int main () {
    t_aviao aviao;
    t_aviao Res;

    aviao.ID = 2;
    aviao.UT = 39;

    t_fila Fila;
    inicializa_fila(&Fila);
    enfileira(aviao, &Fila);

    aviao.ID = 4;
    aviao.UT = 20;

    enfileira(aviao, &Fila);

    imprime_fila(&Fila);

    desenfileira(&Res, &Fila);

    imprime_fila(&Fila);

    aviao.ID = 4;
    aviao.UT = 20;

    if (remove_fila(aviao, &Fila)) {
        printf("YES\n");
    }

    imprime_fila(&Fila);

    return 1;
}
