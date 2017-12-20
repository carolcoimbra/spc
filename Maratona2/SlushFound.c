#include <stdio.h>
#include <stdlib.h>

#define INFINITO 10000000

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

void encontraAGMin (int **matriz, int *distancias, int *visitados, int *agm, int N, int s){
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


void encontraAGMax (int **matriz, int *distancias, int *visitados, int *agm, int N, int s){
    int i = 0, j = 0, no = 0, noNovo = 0, maximo = 0, count = 0;
    
    distancias[s] = 0;
    agm[s] = s;
    visitados[s] = 0;

    while (count < N-1){
        maximo = -1;
        for (i=0; i<N; i++){
            if (visitados[i] != -1){
                no = i;
            }

            for (j=0; j<N; j++){
                if (no != j && visitados[j] == -1 && distancias[j] > maximo){
                    noNovo = j;
                    maximo = distancias[j];
                }
            }
        }

        visitados[noNovo] = 0;
        count ++;

        for (j=0; j<N; j++){
            if (matriz[noNovo][j] != -1 && visitados[j] == -1 && matriz[noNovo][j] > distancias[j]){
                agm[j] = noNovo;
                distancias[j] = matriz[noNovo][j];
            }
        }
    }
}

int main () {
    int N = 0, M = 0, i = 0, X = 0, Y = 0, Z = 0, countMin = 0, countMax = 0;
    int **cidade = criaMatriz(10010);
  
    while (1){
        fscanf(stdin, "%d %d", &N, &M);
        if (N == 0 && M == 0){
            break;
        }

        zeraMatriz(cidade, N);

        for (i=0; i<M; i++){
            fscanf(stdin, "%d %d %d", &X, &Y, &Z);
            cidade[X-1][Y-1] = Z;
            cidade[Y-1][X-1] = Z;
        }

        int *distancias = (int*)malloc((N+1)*sizeof(int));
        int *visitados = (int*)malloc((N+1)*sizeof(int));
        int *agm = (int*)malloc((N+1)*sizeof(int));

        for (i=0; i<N; i++){
            distancias[i] = INFINITO;
            visitados[i] = -1;
            agm[i] = -1;
        }

        encontraAGMin(cidade, distancias, visitados, agm, N, 0);

        countMin = 0;
        for (i=1; i<N; i++){
            countMin += distancias[i];
        }


        for (i=0; i<N; i++){
            distancias[i] = -1;
            visitados[i] = -1;
            agm[i] = -1;
        }

        encontraAGMax(cidade, distancias, visitados, agm, N, 0);

        countMax = 0;
        for (i=1; i<N; i++){
            countMax += distancias[i];
        }

        printf("%d\n", countMax-countMin);
    }

    desalocaMatriz(cidade, 10010);
    return 0;
}