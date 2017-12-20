#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Banda (SPOJ_BANDA09)

O problema consiste em determinar a melhor combinação de músicos em uma banda baseado no nível de 
entrosamento entre eles, ou seja, encontrar um trio de músicos que maximiza o entrosamento. O 
problema fornece uma lista de entrosamento entre músicos com valores inteiros que representam 
o nível de entrosamento entre dois músicos. Dessa forma, a solução do problema envolve armazenar
os valores de entrosamento entre cada par de músicos em uma matriz e, posteriormente, buscar pela
maior soma de entrosamentos entre três músicos diferentes. Para isso, após ler o valor que representa 
o número de músicos , N, e a quantidade de músicos que já tocaram juntos, M, basta criar uma matriz 
N x N, inicialmente zerada. Após isso, um for lê os M pares de músicos (índice da matriz) e seus
respectivos valores de entrosamento e salva na respectiva posição da matriz. Por fim, basta fazer
três for aninhados para que cada um armazene o índice de um músico que irá compor o trio. Uma 
verificação é necessária para que nenhum índice seja igual ao outro, evitando assim, computar o
entrosamento de um músico para ele mesmo. E, para cada trio, basta verificar se a soma do entrosamento
entre o músico 1 com o 2, o 2 com o 3 e o 3 com o 1 é maior do que a maior soma já encontrada. Caso
seja, basta atualizar o vetor do trio, armazenando o índice do músico 1 na primeira posição do
vetor (musicos[0]), o 2 na segunda posição (musicos[1]) e o terceiro na terceira (musicos[2]). Ao
final do caso de teste, basta imprimir o valor de cada posição desse vetor, que contém os índices 
dos músicos que possuem o melhor entrosamento.

Tags: grafo, comparação de valores, atualização de valores

*/

int main() {
    int i = 0, j = 0, N = 0, M = 0, a = 0, b = 0, c = 0, X = 0, Y = 0, Z = 0, soma = 0, maximo = 0;
    int matriz[101][101];
    int musicos[3];

    fscanf(stdin, "%d %d", &N, &M);

    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            matriz[i][j] = 0;
        }
    }
    
    for (i=0; i<M; i++){
        fscanf(stdin, "%d %d %d", &X, &Y, &Z);
        matriz[X-1][Y-1] = Z;
        matriz[Y-1][X-1] = Z;
    }

    for (a=0; a<N; a++){
        for (b=0; b<N; b++){
            if(a != b){
                for (c=0; c<N; c++){
                    if (c != a && c != b){
                        soma = matriz[a][b] + matriz[b][c] + matriz[c][a];
                        if (soma >= maximo){
                            maximo = soma;
                            musicos[0] = a+1;
                            musicos[1] = b+1;
                            musicos[2] = c+1;
                        }
                    }

                }
            }
        }
    }
       
    printf("%d %d %d\n", musicos[0], musicos[1], musicos[2]);
    return 0;
}
