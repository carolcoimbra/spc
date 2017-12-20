#include <stdio.h>
#include <stdlib.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Ir e Vir (SPOJ_IREVIR)

O problema consiste em determinar se é possível viajar entre quaisquer duas interseções, 
isto é, dadas duas intersecções V e W, deve ser possível viajar de V para W e de W para V.
A solução do problema envolve dois conceitos muitos importantes, a busca em profundidade e
a conexidade. Antes de falar da implementação dessas funções, é importante mencionar que a
modelagem do problema usando grafo foi feita por uma matriz de adjacência na qual cada linha 
e coluna representa uma interseção e as células contém o valor 0 caso não haja conexão entre
elas e 1 caso exista. Uma informação importante é que as ruas podem ser de mão única ou dupla, 
sendo assim, a matriz não será simétrica (pode haver ligação entre i-j e não haver entre j-i).
Após modelado o problema como um grafo, a função "dfs" é criada para determinar se dado uma 
interseção, eu consigo atingir todas as outras. Para isso, além da matriz de adjacência, a 
função recebe um vetor de visitados, um nó inicial e o tamanho do grafo (matriz de adjacência).
A "dfs" é implementada de forma recurssiva, de maneira que a visitação de novos nós ocorre em 
profundidade, ou seja, a cada passo, o nó visitado vai para o seu primeiro vizinho ainda não
visitado e assim, sucessivamente, formando uma espécie de caminho, até que todos os nós possíveis
de serem atingidos sejam visitados. O vetor de visitados, inicializado com 0, marca em cada 
posição se a interseção cujo número é igual ao índice do vetor foi visitada, ou seja, a posição 
recebe 1 sempre que existir um caminho entre o nó inicial e o nó cujo número é igual ao índice do 
vetor. Dessa forma, se o vetor visitados está todo preenchido com 1 significa que todos os nós do 
grafo são alcançáveis a partir do nó inicial. Sendo assim, para verificar a conexidade do grafo, 
basta repetir esses processo para todos os nós, ou seja, é feito um for que atribui todos os 
possíveis nós para ser o nó inicial e assim, é feita a busca em profundidade para cada um deles. 
Caso algum dos nós retorne da função "dfs" com o vetor visitados com algum nó ainda sem visitar, 
ou seja, alguma posição do vetor é igual a 0, imediatamente, a função retona 0. Caso todos a 
função "dfs" retorne o vetor de visitados todo preenchido com 1 para todos os nós iniciais, a 
função retorna 1. Dessa forma, o valor retornado por essa função determina justamente se é 
possível (1) ou não (0) sair de qualquer interseção e chegar a outra, ou seja, se existe caminho 
para todos as interseções da cidade. Nesse problema, os casos de teste acabam quando o número de 
interseções, N, é igual a 0. Sendo assim, os valores referentes ao número de interseções, N, e o
número de ruas, M, são lidos assim como os M valores referentes à conexão entre duas interseções e
seu respectivo valor, 1 ou 2, caso seja de mão única ou dupla, respectivamente. Após isso, a matriz
de adjacência é criada e inicializada com 0 e os valores são preenchidos de acordo com a leitura do
tipo de mão entre as interseções. Por fim, a função para verificar a conexidade é chamada e retorna 
o resultado para o problema.

Tags: grafo, matriz de adjacência, busca em profundidade, dfs, conexidade

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
			matriz[i][j] = 0;
		}
	}
}

void dfs (int **matriz, int *visitados, int N, int v){
	int i = 0;

	visitados[v] = 1;
	for (i=0; i<N; i++){
		if(matriz[v][i] == 1 && visitados[i] == 0){
			dfs(matriz, visitados, N, i);
		}
	}
}

int verificaConexidade(int **matriz, int N){
	int i = 0, j = 0;
	int *visitados = (int*)malloc((N+1)*sizeof(int));

	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
			visitados[j] = 0;
		}

		dfs(matriz, visitados, N, i);

		for (j=0; j<N; j++){
			if(visitados[j] == 0){
				return 0;
			}
		} 
	}
	return 1;
}

int main (){
	int N = 0, M = 0, V = 0, W = 0, P = 0, G = 0, i = 0;
	int **ruas = criaMatriz(2002);
	
	while (1){
	
		fscanf(stdin, "%d", &N);
	
		if (N == 0){
			break;
		}

		fscanf(stdin, "%d", &M);

		zeraMatriz(ruas, N);

		for (i=0; i<M; i++){
			fscanf(stdin, "%d %d %d", &V, &W, &P);
			ruas[V-1][W-1] = 1;
	
			if(P == 2){
				ruas[W-1][V-1] = 1;
			}
		}

		G = verificaConexidade(ruas, N);
		printf("%d\n", G);
	}
	
	desalocaMatriz(ruas, 2002);
	return 0;
}