#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

#define INFINITO 100000

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: A Lei vai a Cavalo! (SPOJ_CAVALOS || URI2123)
Implementação similar ao SPOJ_CAVALOS.cpp, mas usando o algoritmo de Edmonds-Karp.

Tags: fluxo máximo, bfs, busca em largura, Edmonds-Karp

*/

void zeraMatriz (int matriz[210][210], int N){
    int i = 0, j = 0;

    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            matriz[i][j] = 0;
        }
    }
}

int fluxoMaximo (int matriz[210][210], int N, int s, int t){
	int i = 0, no = 0, minAresta = 0, fluxo = 0, inicio = 0, final = 0;

	while (1){
		queue<int> fila;
		std::vector<int> visitados (N, 0);  
		std::vector<int> antecessores (N, -1);  

		visitados[s] = INFINITO;
		antecessores[s] = s;
		fila.push(s);

		while (!fila.empty()){
			no = fila.front();
			for (i=0; i<N; i++){
				if(matriz[no][i] != 0 && visitados[i] == 0){
					visitados[i] = min(visitados[no], matriz[no][i]);
					antecessores[i] = no;
					fila.push(i);
				}
			}
			fila.pop();
		}

		minAresta = visitados[t];

		if (minAresta == 0){
			break;
		}

		inicio = antecessores[t];
		final = t;
	
		while (final != s){
			matriz[inicio][final] -= minAresta;
			matriz[final][inicio] += minAresta;

			final = inicio;
			inicio = antecessores[final];
		}
		
		fluxo += minAresta;
	}

	return fluxo;
}

int main () {
    int N = 0, M = 0, K = 0, q = 0, u = 0, v = 0, i = 0, j = 0, t = 0, fluxo = 0, source = 0, target = 0;
	int matriz[210][210];

	while (fscanf(stdin, "%d %d %d", &N, &M, &K) != EOF){
		t++;

	  	zeraMatriz(matriz, N+M+2);
	  	source = 0;
		target = M+N+1;

	    for (i=1; i<=N; i++){
	    	fscanf(stdin, "%d", &q);
	    	matriz[source][i] = q;
	    }

	    for (i=0; i<K; i++){
	    	fscanf(stdin, "%d %d", &u, &v);

	        matriz[u][N+v] = 1;

	        if(matriz[N+v][target] == 0){
	        	matriz[N+v][target] = 1;
	        }
	    }

	  	fluxo = fluxoMaximo(matriz, M+N+2, source, target);

	  	printf("Instancia %d\n", t);
	  	printf("%d\n", fluxo);
	  	printf("\n");
	}
    return 0;
}