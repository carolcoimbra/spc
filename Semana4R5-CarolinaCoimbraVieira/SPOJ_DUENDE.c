#include <stdio.h>
#include <stdlib.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Duende Perdido (SPOJ_DUENDE)

O problema consiste de dadas a configuração da caverna e a posição inicial de Gugo dentro da caverna, 
calcular qual o número mínimo de salões pelos quais o duende deve passar antes de sair da caverna. 
A solução do problema envolve um conceito muito importante, a busca em largura. Antes de falar da 
implementação dessa função, é importante mencionar que a simulação do problema usando grafo foi feita
por uma matriz na qual cada linha e coluna delimitam um salão da caverna e as células contém os valores: 
0 caso o salão não tenha parede de cristal e tenha saída para o exterior da caverna, 1 caso o salão não 
tenha parede de cristal e não tenha saída para o exterior, 2 caso o salão tenha parede de cristal e 3 
caso seja o salão no qual o duende está inicialmente. Após modelado o problema, a função "bfs" é criada 
para determinar o menor caminho que o duende percorrerá até sair da caverna. Para isso, além da matriz de 
representando os salões da caverna, a função recebe uma matriz de visitados, um vetor do tipo par para 
representar uma fila, outra representando as possíveis direções que o duende pode caminhar, o salão incial 
e o tamanho do matriz. A "bfs" é implementada da seguinte forma: para cada nó (coordenadas x,y do salão 
na matriz) adicionado à fila, começando pelo nó de origem, a matriz de visitados na posição referente ao 
x e y do nó recebe o valor do "nível" do nó através do qual se chegou nele somado de 1. Ou seja, os vizinhos 
de um nó estão em um nível maior do que eles. Sendo assim, os vizinhos do nó inicial terão sua posição na 
matriz de visitados igual a 1, uma vez que estão a um nível (um salão) de distância do nó inicial. Sendo 
assim, para cada novo nó descoberto, seus vizinhos são adicionados à fila e aos poucos, todos os nós da 
fila possuem a matriz de visitados preenchida e enfileram também seus vizinhos. É muito importante lembrar 
que, devido ao fato do duende poder se mover em quatro direções, esquerda, direita, pra cima e para baixo, 
cada nó possui, no máximo, 4 vizinhos, ou seja, as possíveis posições (salões) para onde o duende pode 
caminhar. Sendo assim, para cada novo nó, o mesmo pode ter vizinhos ao seu redor caso não exceda o tamanho 
da matriz que representa a caverna. Dessa forma, ao final, ao longo da execução do "bfs" é necessário checar 
os limites da matriz para que os vizinhos estejam sempre dentro dos mesmos, bem como as restrições dos salões, 
ou seja, o duendo não pode caminhar pelo salão 2. E, além disso, caso o duende visite o salão cuja posição na 
matriz é igual a 0, basta retornar o valor armazenado em sua célula da matriz de visitados, já que ele chegou 
à saída da caverna. Nesse problema, os casos de teste são individuais, dessa forma em cada teste é lido o valor 
referente ao número de linhas, N, e colunas, M, da matriz seguido dos valores que serão preenchidos na mesma 
representado o tipo de salão da caverna. Após isso, a matriz é criada e inicializada com 0 e os valores são 
preenchidos de acordo com a leitura dos tipos de salão em cada uma das posições (x, y) da matriz. Por fim, a 
função para fazer a busca em largura é chamada, retornando o caminho mínimo necessário para chegar em um salão 
de saída dado um salão de origem. Sendo assim, basta imprimir esse valor.

Tags: grafo, matriz de adjacência, busca em largura, bfs, typedef

*/

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

void zeraMatriz (int **matriz, int N, int M){
	int i = 0, j = 0;
	
	for (i=0; i<N; i++){
		for (j=0; j<M; j++){
			matriz[i][j] = 0;
		}
	}
}

void zeraMatrizVisitados (int **matriz, int N, int M){
	int i = 0, j = 0;
	
	for (i=0; i<N; i++){
		for (j=0; j<M; j++){
			matriz[i][j] = -1;
		}
	}
}


int bfs (int **matriz, int **visitados, par *fila, par *direcao, int N, int M, par v){
	int i = 0, inicio = 0, fim = 0, novoX = 0, novoY = 0;
	visitados[v.x][v.y] = 0;
	fila[fim] = v;
	fim ++;

	while (inicio < N*M && fila[inicio].x != -1){
		for (i=0; i<4; i++){
			novoX = fila[inicio].x + direcao[i].x;
			novoY = fila[inicio].y + direcao[i].y;

			if(novoX >= 0 && novoX < N && novoY >= 0 && novoY < M){
				if (matriz[novoX][novoY] != 2 && visitados[novoX][novoY] == -1){
					visitados[novoX][novoY] = visitados[fila[inicio].x][fila[inicio].y] + 1;

					if (matriz[novoX][novoY] == 0){
						return visitados[novoX][novoY];
					}

					fila[fim].x = novoX;
					fila[fim].y = novoY;
					fim ++;
				}
			}
		}
		inicio ++;
	}
}


int encontraCaminho (int **matriz, int **visitados, par *fila, int N, int M, par v){
	int i = 0;
	par *direcao = (par*)malloc((4)*sizeof(par));
	direcao[0].x = 0;
	direcao[0].y = 1;
	direcao[1].x = 1;
	direcao[1].y = 0;
	direcao[2].x = 0;
	direcao[2].y = -1;
	direcao[3].x = -1;
	direcao[3].y = 0;

	return bfs(matriz, visitados, fila, direcao, N, M, v);
}

int main (){
	int N = 0, M = 0, i = 0, j = 0, tamanhoCaminho = 0;
	int **matriz = criaMatriz(12);
	int **visitados = criaMatriz(12);
	par inicio;

	fscanf(stdin, "%d %d", &N, &M);

	zeraMatriz(matriz, N, M);	
	zeraMatrizVisitados(visitados, N, M);
	
	for (i=0; i<N; i++){
		for (j=0; j<M; j++){
			fscanf(stdin, "%d", &matriz[i][j]);
			if (matriz[i][j] == 3){
				inicio.x = i;
				inicio.y = j;
			}
		}
	}

	par *fila = (par*)malloc((N*M+1)*sizeof(par));
	for (i=0; i<N*M; i++){
		fila[i].x = -1;
		fila[i].y = -1;
	}

	tamanhoCaminho = encontraCaminho (matriz, visitados, fila, N, M, inicio);
	printf("%d\n", tamanhoCaminho);

	desalocaMatriz(matriz, 12);
	desalocaMatriz(visitados, 12);
	return 0;
}