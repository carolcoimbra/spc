#include <stdio.h>
#include <math.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
*/

void main() {
    int N = 0, teste = 0, hanoi = 0;

    while (1){
        teste ++;

        fscanf(stdin, "%d", &N);

        if (N == 0){
            break;
        }

        hanoi = pow(2, N)-1;

        printf("Teste %d\n", teste);
        printf("%d\n", hanoi);
        printf("\n");
    }
}