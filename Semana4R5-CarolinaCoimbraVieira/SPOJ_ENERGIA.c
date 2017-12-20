#include <stdio.h>
#include <stdlib.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Transmissão de Energia (SPOJ_ENERGIA)

O problema consiste em determinar se é possível trasmitir energia entre qualquer par de estações.
A solução do problema envolve dois conceitos muitos importantes, a busca em profundidade e
a conexidade. Antes de falar da implementação dessas funções, é importante mencionar que a
modelagem do problema usando grafo foi feita por uma matriz de adjacência na qual cada linha 
e coluna representa uma estação de energia e as células contém o valor 0 caso não haja linha de
transmissão entre e 1 caso exista. Uma informação importante é que a matriz é simétrica, ou seja, 
trata-se de um grafo não direcionado (se há ligação entre i-j, há entre j-i). Após modelado o 
problema como um grafo, a função "dfs" é criada para determinar se dado uma estação, eu consigo 
atingir todas as outras. Para isso, além da matriz de adjacência, a função recebe um vetor de 
visitados, um nó inicial e o tamanho do grafo (matriz de adjacência). A "dfs" é implementada de 
forma recurssiva, de maneira que a visitação de novos nós ocorre em profundidade, ou seja, a cada 
passo, o nó visitado vai para o seu primeiro vizinho ainda não visitado e assim, sucessivamente, 
formando uma espécie de caminho, até que todos os nós possíveis de serem atingidos sejam visitados. 
O vetor de visitados, inicializado com 0, marca em cada posição se a estação cujo número é igual 
ao índice do vetor foi visitada, ou seja, a posição recebe 1 sempre que existir um caminho entre o 
nó inicial e o nó cujo número é igual ao índice do vetor. Dessa forma, se o vetor visitados está 
todo preenchido com 1 significa que todos os nós do grafo são alcançáveis a partir do nó inicial. 
Sendo assim, para verificar a conexidade do grafo, basta repetir esses processo para todos os nós, 
ou seja, é feito um for que atribui todos os possíveis nós para ser o nó inicial e assim, é feita a 
busca em profundidade para cada um deles. Caso algum dos nós retorne da função "dfs" com o vetor 
visitados com algum nó ainda sem visitar, ou seja, alguma posição do vetor é igual a 0, imediatamente, 
a função retona 0. Caso todos a função "dfs" retorne o vetor de visitados todo preenchido com 1 para 
todos os nós iniciais, a função retorna 1. Dessa forma, o valor retornado por essa função determina 
justamente se é possível (1 = "normal") ou não (0 = "falha") transmitir energia para qualquer par de 
estação. Nesse problema, os casos de teste acabam quando o número de estações e linhas de transmissão, 
E e L, respectivamente, é igual a 0. Sendo assim, os valores referentes ao número de estações e linhas 
de transmissão, E e L são lidos assim como os L valores referentes aos pares de estações que estão 
conectados. Após isso, a matriz de adjacência é criada e inicializada com 0 e os valores são preenchidos 
de acordo com a leitura dos pares de estações conectados. Por fim, a função para verificar a conexidade 
é chamada, retornando 0 em caso de falha ou 1 caso a trasmissão esteja normal. Caso seja retornado 0, basta
imprimir "falha" e caso o retorno seja 1, imprime-se "normal". Vale lembrar que após imprimir o resultado
deve ser deixada uma linha em branco e, antes do resultado deve aparecer o número do teste que é apenas o
valor de uma variável incrementada a cada novo teste gerado.

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
	int E = 0, L = 0, X = 0, Y = 0, G = 0, i = 0, t = 0;
	int **estacoes = criaMatriz(102);
	
	while (1){
		t++;
		fscanf(stdin, "%d %d", &E, &L);
		if (E == 0 && L == 0){
			break;
		}

		zeraMatriz(estacoes, E);

		for (i=0; i<L; i++){
			fscanf(stdin, "%d %d", &X, &Y);
			estacoes[X-1][Y-1] = 1;
			estacoes[Y-1][X-1] = 1;
		}

		G = verificaConexidade(estacoes, E);

		printf("Teste %d\n", t);
		if (G == 0){
			printf("falha\n", G);
		}
		else {
			printf("normal\n");
		}
		printf("\n");
	}

	desalocaMatriz(estacoes, 102);
	return 0;
}