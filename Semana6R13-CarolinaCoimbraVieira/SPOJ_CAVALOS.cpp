#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

#define MAX 210

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: A Lei vai a Cavalo! (SPOJ_CAVALOS || URI2123)
				*ENVIADO NO URI!*

O problema consiste em determinar o emparelhamento máximo que pode ser formado entre soldados
e cavalos. Ou seja, determinar o número máximo de policiais que podem ter um cavalo para montar 
em uma atribuição, dado que um soldado só pode montar em um cavalo e os cavalos podem ser 
montados por mais de um soldado e para cada par de soldado e cavalo pode existir ou não
afinidade. A solução do problema envolve um conceito muito importante, o fluxo máximo. Antes 
de falar da implementação dessa função, é importante mencionar que a modelagem do problema usando 
grafo foi feita por uma matriz de adjacência. A modelagem da matriz ocorreu da seguinte forma:
inicialmente foi definido um source (nó 0) por onde saem todas as arestas que se ligam aos
cavalos (nós 1 até N). Além disso, foi definido um target (nó N+M+1) que se liga a todos os
soldados (nós N+1 até N+M). E, por fim, os cavalos se ligam aos soldados quando esse par possui
afinidade. Sendo assim, as linhas e colunas na matriz representam esses nós mencionados e cada
célula armazena o valor 1 caso o cavalo tenha afinidade com o soldado, 1 entre todos os soldados
e o target, uma vez que cada soldado só pode montar em um cavalo e, ci entre o source e o cavalo i, 
o que representa que o cavalo i pode ser montado por ci soldados. Uma informação importante é que 
a matriz não será simétrica e, ao longo da execução do algoritmo para encontrar o fluxo máximo, 
a confiração da matriz também mudará. Após modelado o problema como um grafo, a função "fluxoMaximo" 
é criada para determinar qual será o maior fluxo de dados que poderá passar pelas conexões saindo 
do source até chegar ao target. Além da matriz de adjacência, a função que calcula o fluxo máximo 
também recebe um vetor de visitados, um vetor de antecessor, um nó inicial (s = nó 0 na matriz), 
um nó final (t = nó N+M+1 na matriz) e o tamanho do grafo (matriz de adjacência). O "fluxoMaximo" 
é implementado de forma que, começando pelo nó inicial, é feita uma busca em largura para que seja 
encontrado um caminho no grafo que, preferencialmente, leve até o nó final. Enquanto a função "bfs" 
responsável por fazer a busca em largura retornar o vetor de visitados na posição referente ao 
identificador do nó final igual a 1, ou seja, o caminho encontrado chega ao nó final, a menor aresta 
desse caminho é retornada pela função "encontraMin". Essa função basicamente percorre o vetor de 
antecessor preenchido durante a execução da "bfs", buscando pela menor aresta dentre as arestas que 
fazem parte desse caminho. Após definido a menor aresta, basta atualizar a matriz de forma que todas 
as arestas na direção em que foram percorridas no caminho gerado pela "bfs" são decrementadas com o 
valor mínimo encontrado. Já as arestas entre os mesmos nós mas na direção contrária, são incrementadas 
com esse mesmo valor. Por fim, o fluxoMáximo é incrementado pelo menor valor encontrado entre as arestas 
desse caminho. Após inicializar novamente os vetores visitados e antecessores, a "bfs" é chamada novamente 
e os passos descritos se repetem de forma que, quando o vetor de visitados na posição final for igual a 0, 
ou seja, o caminho não chegou ao nó final, a função encerra retornando o valor do fluxo máximo. Nesse 
problema, as entradas terminam com o final do arquivo. Sendo assim, enquanto não for fim do arquivo, EOF, 
os valores referentes à quantidade de cavalos, soldados e afinidades são lidos, assim como o N valores
referentes à quantidade de soldados que pode montar em cada cavalo e os K pares de soldados e cavalos 
com sua respectiva afinidade. Após isso, a matriz de adjacência é criada e inicializada com 0 e os valores 
são preenchidos de acordo com a leitura. Por fim, a função para encontrar o fluxo máximo é chamada e retorna 
o resultado para o problema. Vale ressaltar que antes de cada resultado deve ser impresso o número do caso
de teste, para isso basta fazer um contador que, a cada caso de teste é incrementado em 1 e imprimir seu valor 
antes do resultado. E, ao fim do resultado deve-se deixar uma linha em branco ("\n").

Tags: fluxo máximo, bfs, busca em largura, Ford-Fulkerson

*/

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

int main () {
    int N = 0, M = 0, K = 0, q = 0, u = 0, v = 0, i = 0, j = 0, t = 0, fluxo = 0, source = 0, target = 0;
	int matriz[MAX][MAX];
	int visitados[MAX];
	int antecessores[MAX];

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
	    }

	    for (i=1; i<=M; i++){
	    	matriz[N+i][target] = 1;
	    }

		zeraVetores (visitados, antecessores, M+N+2);

	  	fluxo = fluxoMaximo(matriz, visitados, antecessores, M+N+2, source, target);

	  	printf("Instancia %d\n", t);
	  	printf("%d\n", fluxo);
	  	printf("\n");
	}
    return 0;
}