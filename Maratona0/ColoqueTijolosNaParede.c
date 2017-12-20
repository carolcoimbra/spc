#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
*/

void inicializaParede (int parede[10][10]){
    int i = 0, j = 0;
    for (i=0; i<9; i++){
        for (j=0; j<=i; j++){
            parede[i][j] = 0;
        }
    }
}

void completaParede (int parede[10][10]){
    int i = 0, j = 0;
    i = 8;
    for (j=1; j<=i; j+=2){
        parede[i][j] = (parede[i-2][j-1] - parede[i][j-1] - parede[i][j+1])/2;
    }

    for (i=7; i>0; i--){
        for (j=0; j<9; j++){
            parede[i][j] = parede[i+1][j] + parede[i+1][j+1];
        }
    }
}

void imprimeParede (int parede[10][10]){
    int i = 0, j = 0;
    for (i=0; i<9; i++){
        for (j=0; j<=i; j++){
            printf("%d", parede[i][j]);
            if (j != i){
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int N = 0, n = 0, i = 0, j = 0;
    int parede[10][10];

    fscanf(stdin, "%d", &N);
    for (n=0; n<N; n++){

        inicializaParede(parede);

        for (i=0; i<9; i+=2){
            for (j=0; j<=i; j+=2){
                fscanf(stdin, "%d", &parede[i][j]);
            }
        }

        completaParede(parede);
        imprimeParede(parede);
    }
    return 0;
}