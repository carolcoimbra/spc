#include <cstdio>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

#define MAX 40

void zeraMatriz (int matriz[MAX][MAX], int N){
    int i = 0, j = 0;

    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            matriz[i][j] = 0;
        }
    }
}

void zeraVetores (int visitados[MAX], int antecessores[MAX], int N){
	int i = 0;

	for (i=0; i<N; i++){
        visitados[i] = 0;
        antecessores[i] = -1;
    }
}

void bfs (int matriz[MAX][MAX], int visitados[MAX], int antecessores[MAX], int N, int s, int t){
	int i = 0, inicio = 0, fim = 0, no = 0;
	queue<int> fila;

	visitados[s] = 1;
	antecessores[s] = s;
	fila.push(s);

	while (!fila.empty()){
		no = fila.front();
		for (i=0; i<N; i++){
			if(matriz[no][i] != 0 && visitados[i] == 0){
				visitados[i] = 1;
				antecessores[i] = no;
				fila.push(i);
			}
		}
		fila.pop();
	}
}

void atualizaMatriz (int matriz[MAX][MAX], int antecessores[MAX], int N, int s, int t, int minAresta){
	int i = 0, final = 0, inicio = 0;
	
	inicio = antecessores[t];
	final = t;
	
	while (final != s){
		matriz[inicio][final] -= minAresta;
		matriz[final][inicio] += minAresta;

		final = inicio;
		inicio = antecessores[final];
	}
}

int encontraMin (int matriz[MAX][MAX], int antecessores[MAX], int N, int s, int t){
	int i = 0, final = 0, inicio = 0, minAresta = 1000000;
	
	inicio = antecessores[t];
	final = t;

	while (final != s){
		if (matriz[inicio][final] < minAresta){
			minAresta = matriz[inicio][final];
		}

		final = inicio;
		inicio = antecessores[final];
	}

	return minAresta;
}

int fluxoMaximo (int matriz[MAX][MAX], int visitados[MAX], int antecessores[MAX], int N, int s, int t){
	int i = 0, minAresta = 0, fluxo = 0;

	while (1){
		bfs (matriz, visitados, antecessores, N, s, t);

		if (visitados[t] != 1){
			break;
		}

		minAresta = encontraMin(matriz, antecessores, N, s, t);
		atualizaMatriz (matriz, antecessores, N, s, t, minAresta);
		zeraVetores (visitados, antecessores, N);
		fluxo += minAresta;
	}

	return fluxo;
}

int encontraId (char c[4]){
	int i = 0;
	char vetor[6][4] = {"XXL", "XL", "L", "M", "S", "XS"};

	for (i=0; i<6; i++){
		if (strcmp (c, vetor[i]) == 0){
			return (i+1);
		}
	}
	return 0;
}

int main () {
    int C = 0, N = 0, M = 0, c = 0,  i = 0, j = 0, t = 0, q = 0, id1 = 0, id2 = 0, fluxo = 0, source = 0, target = 0;
    char c1[4], c2[4];
	int matriz[MAX][MAX];
	int visitados[MAX];
	int antecessores[MAX];

	fscanf(stdin, "%d", &C);
	for (c=0; c<C; c++){
		fscanf(stdin, "%d %d", &N, &M);

		q = N/6;
		N = 6;

	  	zeraMatriz(matriz, N+M+2);
	  	source = 0;
		target = M+N+1;

	    for (i=1; i<=N; i++){
	    	matriz[source][i] = q;
	    }

	    for (i=1; i<=M; i++){
	    	fscanf(stdin, "%s %s", c1, c2);

	    	id1 = encontraId (c1);
	    	id2 = encontraId (c2);

	        matriz[id1][N+i] = 1;
	        matriz[id2][N+i] = 1;
	    }

	    for (i=1; i<=M; i++){
	    	matriz[N+i][target] = 1;
	    }

		zeraVetores (visitados, antecessores, M+N+2);

	  	fluxo = fluxoMaximo(matriz, visitados, antecessores, M+N+2, source, target);

	  	if (fluxo == M){
	  		printf("YES\n");
	  	}
	  	else {
	  		printf("NO\n");
	  	}
	}
    return 0;
}