#include <cstdio>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef struct {
	int x;
	int y;
} par;

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

void zeraMatrizVisitados (int **matriz, int N){
	int i = 0, j = 0;
	
	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
			matriz[i][j] = -1;
		}
	}
}


int bfs (int **visitados, par *direcao, int N, par v1, par v2){
	int i = 0, inicio = 0, fim = 0, novoX = 0, novoY = 0;
	par no, novo;

	queue<par> fila;
	fila.push(v1);
	visitados[v1.x][v1.y] = 0;

	while (!fila.empty()){
		for (i=0; i<8; i++){
			no = fila.front();
			novoX = no.x + direcao[i].x;
			novoY = no.y + direcao[i].y;

			if(novoX >= 0 && novoX < N && novoY >= 0 && novoY < N){
				if (visitados[novoX][novoY] == -1){
					visitados[novoX][novoY] = visitados[no.x][no.y] + 1;

					//printf("%d %d\n", novoX, novoY);
					if (novoX == v2.x && novoY == v2.y){
						return (visitados[novoX][novoY]);
					}

					novo.x = novoX;
					novo.y = novoY;
					fila.push(novo);
				}
			}
		}
		fila.pop();
	}

	return 0;
}


int encontraCaminho (int **visitados, int N, par v1, par v2){
	int i = 0, r = 0;
	par *direcao = (par*)malloc((8)*sizeof(par));
	direcao[0].x = 1;
	direcao[0].y = 2;
	direcao[1].x = 1;
	direcao[1].y = -2;
	direcao[2].x = -1;
	direcao[2].y = 2;
	direcao[3].x = -1;
	direcao[3].y = -2;
	direcao[4].x = 2;
	direcao[4].y = 1;
	direcao[5].x = 2;
	direcao[5].y = -1;
	direcao[6].x = -2;
	direcao[6].y = 1;
	direcao[7].x = -2;
	direcao[7].y = -1;

	r = bfs(visitados, direcao, N, v1, v2);

	return r;
}

int main (){
	int N = 0, i = 0, j = 0, tamanhoCaminho = 0;
	int **visitados = criaMatriz(8);
	par inicio;
	par fim;
	char v1[3], v2[3];

	N = 8;

	while (fscanf(stdin, "%s %s", v1, v2) != EOF){	

		zeraMatrizVisitados(visitados, N);

		inicio.x = (int)v1[0]-97;
		inicio.y = (int)v1[1]-49;

		fim.x = (int)v2[0]-97;
		fim.y = (int)v2[1]-49;	

		if (inicio.x == fim.x && inicio.y == fim.y){
			printf("To get from %s to %s takes 0 knight moves.\n", v1, v2);
		}

		else {
			tamanhoCaminho = encontraCaminho (visitados, N, inicio, fim);
			printf("To get from %s to %s takes %d knight moves.\n", v1, v2, tamanhoCaminho);
		}
	}

	desalocaMatriz(visitados, 8);
	return 0;
}