#include <stdio.h>
#include <stdlib.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Pedagio (SPOJ_PEDAGIO)

O problema consiste de conhecidas as cidades e estradas existentes no país, e a cidade onde 
Juquinha e sua família estão, encontrar cada cidade (que não a cidade onde eles estão) que 
possa ser visitada por eles, dada a restrição de que o Sr. Juca deseja pagar no máximo P pedágios 
(considerando apenas a viagem de ida). A solução do problema envolve um conceito muito importante, 
a busca em largura. Antes de falar da implementação dessa função, é importante mencionar que a 
modelagem do problema usando grafo foi feita por uma matriz de adjacência na qual cada linha e 
coluna representa uma cidade e as células contém o valor 0 caso não haja uma estrada entre elas e 
1 caso exista. Uma informação importante é que a matriz é simétrica, ou seja, trata-se de um grafo não 
direcionado (se há ligação entre i-j, há entre j-i), uma vez que todas as estradas possuem via dupla.
Após modelado o problema como um grafo, a função "bfs" é criada para determinar se dado um grafo 
conectando à todas as cidades é possível encontrar um conjunto cuja "distância" (número de arestas) para 
a cidade de origem é menor do que P, ou seja, a quantidade de pedágios que serão pagos. Para isso, além 
da matriz de adjacência, a função recebe um vetor de visitados, um vetor para representar uma fila, um 
nó inicial e o tamanho do grafo (matriz de adjacência). A "bfs" é implementada da seguinte forma: para 
cada nó adicionado à fila, começando pelo nó de origem, o vetor de visitados na posição referente ao número 
daquela cidade recebe o valor do "nível" do nó através do qual se chegou nele somado de 1. Ou seja, 
os vizinhos de um nó estão em um nível maior do que eles. Sendo assim, os vizinhos do nó inicial terão
sua posição no vetor de visitados igual a 1, uma vez que estão a um nível (uma aresta, um pedágio) de
distância do nó inicial. Sendo assim, para cada novo nó descoberto, seus vizinhos são adicionados à fila
e aos poucos, todos os nós da fila possuem o vetor de visitados preenchido e enfileram também seus vizinhos.
Dessa forma, ao final, teremos um vetor de visitados onde cada posição representa o número de pedágios 
existentes da cidade de origem à cidade representada pelo índice do vetor. Como o índice do vetor é 
ordenado, basta imprimir o índice do vetor de todas as posições cujo valor armazenado é maior do que 0 (porque
a cidade de origem não conta) e menor ou igual ao número de pedágios que a família poderá pagar. Nesse problema, 
os casos de teste terminam quando os valores de C (número de cidades), E (número de estradas), L (origem) e P 
(número máximo de pedágios) são iguais a 0. Sendo assim, enquanto isso não ocorre, os valores referentes ao 
número de cidades, estradas, cidade de origem e número máximo de pedágios são lidos assim como os E valores 
referentes aos pares de cidades que são ligadas por uma estrada de via dupla. Após isso, a matriz de adjacência 
é criada e inicializada com 0 e os valores são preenchidos de acordo com a leitura dos pares de cidades ligadas. 
Por fim, a função para fazer a busca em largura é chamada, fornecendo o vetor de visitados preenchido de acordo
com o número de pedágios existentes da cidade de origem a cada uma das demais cidades. As posições cujo valor 
está entre 0 e P são impressas. Vale lembrar que após imprimir o resultado deve ser deixada uma linha em branco e, 
antes do resultado deve aparecer o número do teste que é apenas o valor de uma variável incrementada a cada novo 
teste gerado.

Tags: grafo, matriz de adjacência, busca em largura, bfs

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

void bfs (int **matriz, int *visitados, int *fila, int N, int v){
	int i = 0, inicio = 0, fim = 0;

	visitados[v] = 0;
	fila[fim] = v;
	fim ++;

	while (inicio < N && fila[inicio] != -1){
		for (i=0; i<N; i++){

			if(matriz[fila[inicio]][i] == 1 && visitados[i] == -1){
				visitados[i] = visitados[fila[inicio]]+1;
				fila[fim] = i;
				fim ++;
			}
		}
		inicio ++;
	}
}


int main (){
	int C = 0, E = 0, L = 0, P = 0, X = 0, Y = 0, i = 0, t = 0;
	int **cidades = criaMatriz(52);
	
	while (1){
		t++;
		fscanf(stdin, "%d %d %d %d", &C, &E, &L, &P);
		if (C == 0 && E == 0 && L == 0 && P == 0){
			break;
		}

		zeraMatriz(cidades, C);

		for (i=0; i<E; i++){
			fscanf(stdin, "%d %d", &X, &Y);
			cidades[X-1][Y-1] = 1;
			cidades[Y-1][X-1] = 1;
		}

		int *visitados = (int*)malloc((C+1)*sizeof(int));
		int *fila = (int*)malloc((C+1)*sizeof(int));
		for (i=0; i<C; i++){
			visitados[i] = -1;
			fila[i] = -1;
		}

		bfs(cidades, visitados, fila, C, L-1);

		printf("Teste %d\n", t);
		for (i=0; i<C; i++){
			if(visitados[i] <= P && visitados[i] > 0){
				printf("%d ", i+1);
			}
		}
		printf("\n\n");
	}

	desalocaMatriz(cidades, 52);
	return 0;
}