#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Matriz 123 (URI1534)

O problema consiste em imprimir uma matriz quadrada cujo tamanho é especificado na 
entrada, de forma que a diagonal principal contenha somente o valor 1, a diagonal 
secundária contenha somente o valor 2 e as demais células da matriz contenham o valor 3.
A diagonal principal é formada pelos elementos i = j, a diagonal secundária é formada
pelos elementos i+j = n+1, entretanto, devido ao fato da matriz ter sido construída a partir
do zero, a diagonal secundária consiste dos elementos i = n-1-j. Para construção da matriz, 
o tamanho é lido e um for aninhado é feito para preenchê-la de acordo com as condições 
explicitadas anteriormente. Ou seja, a célula recebe 1 se i=j, 2 se i=n-1-j e 3 caso não se 
enquadre nessas duas condições anteriores. Porém, vale ressaltar que a diagonal secundária 
sobrescreve a diagonal principal, por exemplo, o elemento i=1, j=1 da matriz abaixo faz parte 
da diagonal principal e da diagonal secundária, dessa forma, recebe o valor 2.
                                       [1 3 2
                                        3 2 3
                                        2 3 1]
Nesse caso, como o fim da entrada é marcado pelo fim do arquivo "EOF", basta ler o valor N, 
que representa o tamanho da matriz enquanto não for o fim do arquivo, preencher adequadamente 
a matriz e imprimi-la utilizando um for aninhado.

Tags: matriz, diagonal principal, diagonal secundária

*/

void main() {
    int i = 0, j = 0, N = 0;

    while (fscanf(stdin, "%d", &N) != EOF){
        int matriz[N][N];
        for(i=0; i<N; i++){
            for (j=0; j<N; j++){
                if (i==j){
                    matriz[i][j] = 1;
                }
                if (i == N-1-j){
                    matriz[i][j] = 2;
                }
                if (i!=j && i!=(N-1-j)) {
                    matriz[i][j] = 3;
                }
            }
        }
        for (i=0; i<N; i++){
            for (j=0; j<N; j++){
                printf("%d", matriz[i][j]);
            }
            printf("\n");
        }
    }
}