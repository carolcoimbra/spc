#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Banda (SPOJ_BANDA09)
*/

int main() {
    int i = 0, j = 0, n = 0, N = 0, A = 0, B = 0, X1 = 0, X2 = 0, Y1 = 0, Y2 = 0, count = 0, menorX, menorY, maiorX, maiorY;
    int matriz[500][500];

    while (1){
        fscanf(stdin, "%d %d %d", &A, &B, &N);
        if (A == 0 && B == 0 && N == 0){
            break;
        }

        for (i=0; i<A; i++){
            for (j=0; j<B; j++){
                matriz[i][j] = 0;
            }
        }
        
        for (n=0; n<N; n++){
            fscanf(stdin, "%d %d %d %d", &X1, &Y1, &X2, &Y2);
            if (X1 > X2){
                maiorX = X1;
                menorX = X2;
            }
            else {
                maiorX = X2;
                menorX = X1;
            }
            if (Y1 > Y2){
                maiorY = Y1;
                menorY = Y2;
            }
            else {
                maiorY = Y2;
                menorY = Y1;
            }

            for (i=menorX-1; i<maiorX; i++){
                for (j=menorY-1; j<maiorY; j++){
                    matriz[i][j] = 1;
                }
            }
        }

        count = 0;
        for (i=0; i<A; i++){
            for (j=0; j<B; j++){
                if (matriz[i][j] == 0){
                    count ++;
                }
            }
        }

        if (count == 0){
            printf("There is no empty spots.\n");
        }
        else if (count == 1){
            printf("There is one empty spot.\n");
        }
        else {
            printf("There are %d empty spots.\n", count);
        }
    }
    return 0;
}
