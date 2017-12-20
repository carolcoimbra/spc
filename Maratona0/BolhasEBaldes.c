#include <stdio.h>
#include <stdlib.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
*/

void trocaPosicoes (int A[100000], int i, int j, int aux){
    aux = A[i];
    A[i] = A[j];
    A[j] = aux;
}

int main() {
    int N = 0, i = 0, trocas = 0, aux = 0;
    int A[100000];

    while (1){
        fscanf(stdin, "%d", &N);

        if (N == 0){
            break;
        }

        for (i=0; i<N; i++){
            fscanf(stdin, "%d", &A[i]);
        }

        trocas = 0;
        for (i=0; i<N; i++){
            while (i != A[i]-1){
                trocaPosicoes(A, i, A[i]-1, aux);
                trocas += 1;
            }
        }

        if (trocas%2 == 0){
            printf("Carlos\n");
        }
        else{
            printf("Marcelo\n");
        }
    }
    return 0;
}