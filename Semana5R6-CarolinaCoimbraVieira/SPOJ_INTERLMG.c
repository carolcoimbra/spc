#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INFINITO 10000000.00

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Interligando a Sildávia (SPOJ_INTERLMG)

O problema consiste em determinar uma distância que garante que há caminho entre qualquer par 
de cidades. A solução do problema envolve um conceito muito imposrtante, a árvore geradora 
mínima. Antes de falar da implementação dessa função, é importante mencionar que a modelagem 
do problema usando grafo foi feita por uma matriz de adjacência na qual cada linha e coluna 
representa uma cidade e as células contém o valor referente à distância entre essas cidades.
A distância entre as cidades é calculada utilizando a fórmula de distância euclidiana entre 
dois pontos, ou seja, cada cidade possui uma coordenada x e y de forma que a distância entre 
duas cidades é dada por: dist(c1, c2) = sqrt((x1-x2)^2 + (y1-y2)^2).
Uma informação importante é que a matriz será simétrica (se há ligação entre i-j, há entre j-i), 
já que trata-se de um grafo não direcionado. Após modelado o problema como um grafo, a função 
"encontraAGM" é criada para determinar qual serão as menores distâncias que permitem que todas
as cidades sejam conectadas. Para isso, além da matriz de adjacência, a função recebe um vetor 
de distâncias, um vetor de visitados, um vetor "agm" para armazenar as arestas que irão compor 
a agm, um nó inicial e o tamanho do grafo (matriz de adjacência). A "encontraAGM" é implementada 
de forma que, começando por um nó inicial, é feita uma busca por todos os nós, que ainda não foram 
visitados, para encontrar um nó cuja distância para os nós que já compõem a agm seja a menor 
distância possível. Após isso, todas as arestas que se conectam ao novo nó adicionado à agm 
possuem suas distâncias atualizadas. Sendo assim, caso a distância do novo nó somada à distância 
do novo nó para seu vizinho seja menor do que a distância do vizinho até o momento, a mesma é 
atualizada. Quando todos os nós estão incluídos na agm, a função termina, fornecendo o vetor de 
distâncias preenchido com as distâncias para cada um dos nós atualizada, sendo assim, basta 
percorrer esse vetor usando um for e salvar a maior distância existente no mesmo. Essa distância
garante que todas as cidades sejam conectadas. Nesse problema, os casos de teste acabam quando o 
número de cidades, N, é igual a 0. Sendo assim, os valores referentes ao número de cidades, N, são 
lidos assim como os N valores referentes às coordenadas x e y das cidades. Após isso, a matriz de 
adjacência é criada e inicializada com -1 e os valores são preenchidos de acordo com as distâncias
calculadas entre cada par de cidades utilizando a fórmula descrita anteriormente. Por fim, a função 
para encontrar a agm é chamada, fornecendo o vetor que representa as distâncias da agm, cuja maior
delas será impressa, conforme explicado acima.

Tags: grafo, matriz de adjacência, prim, árvore geradora mínima, agm

*/

double **criaMatriz (int N){
    int i = 0, j = 0;
    double **matriz = (double**)malloc((N+1)*sizeof(double*));

    for (i=0; i<N; i++){
        matriz[i] = (double*)malloc((N+1)*sizeof(double));
    }
    
    return matriz;
}

void desalocaMatriz (double **matriz, int N){
    int i = 0;

    for (i=0; i<N; i++){    
        free (matriz[i]);
    }
    
    free(matriz);
}

void zeraMatriz (double **matriz, int N){
    int i = 0, j = 0;

    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            matriz[i][j] = -1.0;
        }
    }
}

void encontraAGM (double **matriz, double *distancias, int *visitados, int *agm, int N, int s){
    int i = 0, j = 0, no = 0, noNovo = 0, count = 0;
    double minimo = 0.00;
    
    distancias[s] = 0.00;
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
            if (i != j && visitados[j] == -1 && matriz[noNovo][j] < distancias[j]){
                agm[j] = noNovo;
                distancias[j] = matriz[noNovo][j];
            }
        }
    }
}

double distancia (double x1, double y1, double x2, double y2){
    double d = 0.0;
    d = sqrt(pow((x1-x2), 2.0) + pow((y1-y2), 2.0));

    return d;
}

int main () {
    int N = 0, i = 0, j = 0;
    double d = 0.0, maximo = 0.0;
    double coordX[1001], coordY[1001];
    double **cidades = criaMatriz(1010);
  
    while (1){
        fscanf(stdin, "%d", &N);
        if (N == 0){
            break;
        }

        zeraMatriz(cidades, N);

        for (i=0; i<N; i++){
            fscanf(stdin, "%lf %lf", &coordX[i], &coordY[i]);
        }

        for (i=0; i<N; i++){
            for (j=i+1; j<N; j++){
                d = distancia (coordX[i], coordY[i], coordX[j], coordY[j]);
                cidades[i][j] = d;
                cidades[j][i] = d;                
            }
        }

        double *distancias = (double*)malloc((N+1)*sizeof(double));
        int *visitados = (int*)malloc((N+1)*sizeof(int));
        int *agm = (int*)malloc((N+1)*sizeof(int));

        for (i=0; i<N; i++){
            distancias[i] = INFINITO;
            visitados[i] = -1;
            agm[i] = -1;
        }

        encontraAGM(cidades, distancias, visitados, agm, N, 0);

        maximo = 0.0;
        for (i=0; i<N; i++){
            if (distancias[i] > maximo){
                maximo = distancias[i];
            }
        }

        printf("%.4lf\n", maximo);
    }

    desalocaMatriz(cidades, 1010);
    return 0;
}