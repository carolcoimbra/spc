#include <stdio.h>
#include <stdlib.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Mesa da Sra Montagny! (SPOJ_MESA)

O problema consiste em determinar se é possível dispor os convidados de uma festa numa mesa 
de forma que cada convidado tenha todos os seus amigos no lado oposto da mesa. A solução do 
problema envolve dois conceitos muitos importantes, a busca em profundidade e o grafo bipartido.
Antes de falar da implementação dessas funções, é importante mencionar que a modelagem do problema 
usando grafo foi feita por uma matriz de adjacência na qual cada linha e coluna representa um 
convidado e as células contém o valor 0 caso não haja uma relação de amizade e 1 caso exista. 
Uma informação importante é que a matriz é simétrica, ou seja, trata-se de um grafo não direcionado 
(se há ligação entre i-j, há entre j-i). Após modelado o problema como um grafo, a função "dfs" 
é criada para determinar se dado um grafo com "restrições" eu consigo colocar todos sentados de 
forma que todos fiquem de frente para seus amigos. Para isso, além da matriz de adjacência, a 
função recebe um vetor de visitados, um nó inicial e o tamanho do grafo (matriz de adjacência). 
A "dfs" é implementada de forma recurssiva, de maneira que a visitação de novos nós ocorre em 
profundidade, ou seja, a cada passo, o nó visitado vai para o seu primeiro vizinho ainda não visitado 
e assim, sucessivamente, formando uma espécie de caminho, até que todos os nós possíveis de serem 
atingidos sejam visitados. Para esse problema, uma modificação na função de busca em profundidade 
é necessária uma vez que além de visitar os vizinhos, devemos determinar se ele poderá se sentar à
frente de seu amigo, isso porque pode ser que ele tenha mais amigos que queiram se sentar à sua frente.
Para isso, é necessário preencher o vetor de visitados com dois valores, para que seja possivel 
representar o fato de um amigo estar na frente do outro, ou seja, se um amigo foi visitado e o valor
atribuído à sua posição no vetor de visitados é igual a 1, sabe-se que ele está a frente de um amigo
cujo valor no vetor de visitados é igual a 2. Sendo assim, se for possível preencher todo o vetor de 
visitados sem que haja sobrescrição de valor significa que é possível atender a todos os desejos dos
convidados. Porém, caso haja sobrescrição, indica que não será possível. Por exemplo, se o vetor de 
visitados em um posição possui 1, ou seja, está sentado à frente de alguém que foi visitado com o valor
2, mas você que foi visitado com valor 2 gostaria de se sentar na frente dele, ou seja, colocar ele como 
sendo visitado igual a 2 implica que não é possível atender às restrições. O vetor de visitados, inicializado 
com 0, marca em cada posição se o convidado já foi "alocado" na mesa e o seu "valor" que indica sobretudo,
que ele já está na frente de um amigo (uma restrição ja foi satisfeita). Dessa forma, a função "dfs" termina
e o vetor de visitados já está todo preenchido, sendo assim, basta verificar se houve alguma restrição que 
não pôde ser atendida. Para isso, basta verificar um contador que foi utilizado na função que conta o número
de vezes que uma restrição não pôde ser atendida. Ou seja, se o valor do contador é maior do que 0 significa
que não foi possível alocar os convidade de forma a agradar a todos, porém, caso essa variável seja igual a 0,
a alocação foi um sucesso. Dessa forma, o valor retornado por essa função determina justamente se é possível 
(0 = "sim") ou não (>0 = "não") alocar todos os convidados da festa de acordo com as retrições de amizade 
impostas por eles. Nesse problema, os casos de teste terminam com o final do arquivo, ou seja, enquanto a 
leitura for diferente de EOF, os valores referentes ao número de convidados e restrições, N e M, são lidos 
assim como os M valores referentes aos pares de amigos que gostariam de sentar à frente um do outro. Após isso, 
a matriz de adjacência é criada e inicializada com 0 e os valores são preenchidos de acordo com a leitura
dos pares de amigos. Por fim, a função para verificar o grafo bipartido é chamada, retornando 0 em caso de 
sucesso ou um valor maior do que zero caso a não seja possível atender às exigências dos convidados. Caso 
seja retornado 0, basta imprimir "sim" e caso o retorno seja um valor maior do que 0, imprime-se "não". 
Vale lembrar que após imprimir o resultado deve ser deixada uma linha em branco e, antes do resultado deve 
aparecer o número do teste que é apenas o valor de uma variável incrementada a cada novo teste gerado.

Tags: grafo, matriz de adjacência, busca em profundidade, dfs, bipartido

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

void dfs (int **matriz, int *visitados, int N, int v, int *b){
	int i = 0, valor = 0;

	valor = visitados[v];
	for (i=0; i<N; i++){
		if (matriz[v][i] == 1){
			if (visitados[i] == valor){
				(*b)++;
			}
			else {
				if (visitados[i] == 0){
					if (valor == 1){
						visitados[i] = 2;
					}
					else {
						visitados[i] = 1;
					}
					dfs(matriz, visitados, N, i, b);
				}
			}
		}
	}
}

int verificaBipartido(int **matriz, int N){
	int i = 0, j = 0, b = 0;
	int *visitados = (int*)malloc((N+1)*sizeof(int));

	for (j=0; j<N; j++){
		visitados[j] = 0;
	}

	visitados[i] = 1;
	dfs(matriz, visitados, N, i, &b);

	return b;
}

int main (){
	int N = 0, M = 0, u = 0, v = 0, G = 0, i = 0, k = 0;
	int **mesa = criaMatriz(102);
	while (fscanf(stdin, "%d %d", &N, &M) != EOF){
		k++;

		zeraMatriz(mesa, N);

		for (i=0; i<M; i++){
			fscanf(stdin, "%d %d", &u, &v);
			mesa[u-1][v-1] = 1;
			mesa[v-1][u-1] = 1;
		}

		G = verificaBipartido(mesa, N);

		printf("Instancia %d\n", k);
		if (G == 0){
			printf("sim\n", G);
		}
		else {
			printf("nao\n");
		}
		printf("\n");
	}
	
	desalocaMatriz(mesa, 102);
	return 0;
}