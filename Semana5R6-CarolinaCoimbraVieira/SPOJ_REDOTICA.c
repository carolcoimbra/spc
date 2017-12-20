#include <stdio.h>
#include <stdlib.h>

#define INFINITO 10000000
 
/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Rede Ótica (SPOJ_REDOTICA)

O problema consiste em determinar quais ramos devem ser construídos, de forma a possibilitar 
a comunicação entre todas as tabas, causando o menor impacto ambiental possível e conectando
todos em uma tribo. A solução do problema envolve um conceito muito imposrtante, a árvore 
geradora mínima. Antes de falar da implementação dessa função, é importante mencionar que a 
modelagem do problema usando grafo foi feita por uma matriz de adjacência na qual cada linha 
e coluna representa uma taba por onde passam os ramos de rede que conectam umas as outras e 
as células contém o valor referente ao impacto ambiental causado por cada uma das conexões.
Uma informação importante é que a matriz será simétrica (se há ligação entre i-j, há entre j-i), 
já que trata-se de um grafo não direcionado. Após modelado o problema como um grafo, a função 
"encontraAGM" é criada para determinar qual serão os ramos de redes que devem ser construídos.  
Para isso, além da matriz de adjacência, a função recebe um vetor de distâncias, um vetor de 
visitados, um vetor "agm" para armazenar as arestas que irão compor a agm, um nó inicial e o 
tamanho do grafo (matriz de adjacência). A "encontraAGM" é implementada de forma que, começando 
por um nó inicial, é feita uma busca por todos os nós, que ainda não foram visitados, para 
encontrar um nó cuja distância para os nós que já compõem a agm seja a menor distância possível.
Após isso, todas as arestas que se conectam ao novo nó adicionado à agm possuem suas distâncias 
atualizadas. Sendo assim, caso a distância do novo nó somada à distância do novo nó para seu 
vizinho seja menor do que a distância do vizinho até o momento, a mesma é atualizada. Quando 
todos os nós estão incluídos na agm, a função termina, fornecendo o vetor agm preenchido com o
identificador do nó que está ligado a cada um dos nós cujo indentificador é igual ao índice do
vetor. Por exemplo, o vetor [0, 0, 1] indica que as arestas são 0-1 e 1-2.
Um detalhe importante é que as tabas devem ser impressas na ordem crescente em cada uma das linhas, 
sendo assim, basta verificar qual das tabas que compõem a conexão é a menor e imprimí-la primeiro.
Nesse problema, os casos de teste acabam quando o número de tabas, N, é igual a 0. Sendo assim, os 
valores referentes ao número de tabas, N, e o número de ramos de redes possíveis, M, são lidos assim 
como os M valores referentes às redes entre duas tabas e seu respectivo custo ambiental. Após isso, 
a matriz de adjacência é criada e inicializada com -1 e os valores são preenchidos de acordo com a 
leitura do custo ambiental. Por fim, a função para encontrar a agm é chamada, fornecendo o vetor que
representa as arestas da agm, que serão impressas respeitando a ordem crescente de tabas, conforme
explicado acima.

Tags: grafo, matriz de adjacência, prim, árvore geradora mínima, agm

*/

int **criaMatriz (int N){
    int i = 0, j = 0;
    int **matriz = (int**)malloc((N+1)*sizeof(int*));

    for (i=0; i<N; i++){
        matriz[i] = (int*)malloc((N+1)*sizeof(int));
    }
    
    return matriz;
}

void desalocaMatriz (int **matriz, int N){
    int i = 0;

    for (i=0; i<N; i++){    
        free (matriz[i]);
    }
    
    free(matriz);
}

void zeraMatriz (int **matriz, int N){
    int i = 0, j = 0;

    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            matriz[i][j] = -1;
        }
    }
}

void encontraAGM (int **matriz, int *distancias, int *visitados, int *agm, int N, int s){
    int i = 0, j = 0, no = 0, noNovo = 0, minimo = 0, count = 0;
    
    distancias[s] = 0;
    agm[s] = s;
    visitados[s] = 0;

    while (count < N-1){
        minimo = INFINITO;
        for (i=0; i<N; i++){
            if (visitados[i] != -1){
                no = i;
            }

            for (j=0; j<N; j++){
                if (no != j && visitados[j] == -1 && distancias[j] < minimo){
                    noNovo = j;
                    minimo = distancias[j];
                }
            }
        }

        visitados[noNovo] = 0;
        count ++;

        for (j=0; j<N; j++){
            if (matriz[noNovo][j] != -1 && visitados[j] == -1 && matriz[noNovo][j] < distancias[j]){
                agm[j] = noNovo;
                distancias[j] = matriz[noNovo][j];
            }
        }
    }
}

int main () {
    int N = 0, M = 0, i = 0, X = 0, Y = 0, Z = 0, t = 0, primeiro = 0, segundo = 0;
    int **tabas = criaMatriz(110);
  
    while (1){
        t++;
        fscanf(stdin, "%d", &N);
        if (N == 0){
            break;
        }

        fscanf(stdin, "%d", &M);
        zeraMatriz(tabas, N);

        for (i=0; i<M; i++){
            fscanf(stdin, "%d %d %d", &X, &Y, &Z);
            tabas[X-1][Y-1] = Z;
            tabas[Y-1][X-1] = Z;
        }

        int *distancias = (int*)malloc((N+1)*sizeof(int));
        int *visitados = (int*)malloc((N+1)*sizeof(int));
        int *agm = (int*)malloc((N+1)*sizeof(int));

        for (i=0; i<N; i++){
            distancias[i] = INFINITO;
            visitados[i] = -1;
            agm[i] = -1;
        }

        encontraAGM(tabas, distancias, visitados, agm, N, 0);

        printf("Teste %d\n", t);

        for (i=0; i<N; i++){
            if (i != agm[i]){
                primeiro = i+1;
                segundo = agm[i]+1;
                if ((i+1) > (agm[i]+1)){
                    primeiro = agm[i]+1;
                    segundo = i+1;
                }
                printf("%d %d\n", primeiro, segundo);
            }
        }
        printf("\n");
    }

    desalocaMatriz(tabas, 110);
    return 0;
}