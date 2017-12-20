#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Angry Programmer (UVa 11506)

O problema consiste em determinar o custo mínimo de remover conexões entre computadores para que o
computador do chefe de um programador não consiga se comunicar com o servidor da empresa. A solução do 
problema envolve um conceito muito importante, o fluxo máximo. Antes de falar da implementação dessa 
função, é importante mencionar que a modelagem do problema usando grafo foi feita por uma matriz de 
adjacência na qual cada linha e coluna representa um nó do grafo que indicam os computadores e as 
células contém o valor referente ao custo de se cortar a conexão entre esses computadores. A modelagem
desse grafo, no entanto, é bem particular, uma vez que além de existir custo de se remover conexões, 
existe um custo adicional de se remover um computador. Dessa forma, o grafo foi montado da seguinte forma:
o source é representada pelo computador do chefe (nó 0) 
o target é representado pelo servidor (nó M-1 ou 2*M-3 na matriz2)
para os demais computadores, os mesmos são duplicados de forma que, cada computador se conecte à ele mesmo
com o custo referente à remoção do mesmo da rede. Além disso, essa divisão faz com que todas as arestas
que antes incidiam em um vétice v passam a incidir nos vértices v' correspondentes, ou seja, os vétices 
da primeira metada do grafo. E, as arestas que saíam desses vértices sairão de v''. Sob essa perspectiva, 
o id dos nós da primeira metade do grafo serão iguais a m-1 e, o id correspondente na segunda metade do
grafo será igual a M-2+(m-1). 
Após modelado o problema como um grafo, a função "fluxoMaximo" é criada de forma que, o fluxo máximo seja
calculado, fornecendo o custo de se remover a conexão entre o computador do chefe com o servidor. Além do
grafo modelado, a função recebe um vetor de visitados, um vetor de antecessor, um nó inicial (s = nó 0), 
um nó final (t = nó 2*M-3 na matriz) e o tamanho do grafo (matriz de adjacência). O "fluxoMaximo" é 
implementado de forma que, começando pelo nó inicial, é feita uma busca em largura para que seja encontrado 
um caminho no grafo que, preferencialmente, leve até o nó final. Enquanto a função "bfs" responsável por 
fazer a busca em largura retornar o vetor de visitados na posição referente ao identificador do nó final 
igual a 1, ou seja, o caminho encontrado chega ao nó final, a menor aresta desse caminho é retornada pela 
função "encontraMin". Essa função basicamente percorre o vetor de antecessor preenchido durante a execução da 
"bfs", buscando pela menor aresta dentre as arestas que fazem parte desse caminho. Após definido a menor 
aresta, basta atualizar a matriz de forma que todas as arestas na direção em que foram percorridas 
no caminho gerado pela "bfs" são decrementadas com o valor mínimo encontrado. Já as arestas entre 
os mesmos nós mas na direção contrária, são incrementadas com esse mesmo valor. Após inicializar novamente 
os vetores visitados e antecessores, a "bfs" é chamada novamente e os passos descritos se repetem de 
forma que, quando o vetor de visitados na posição final for igual a 0, ou seja, o caminho não chegou 
ao nó final, a função encerra retornando o valor do fluxo máximo. Nesse problema, as entradas terminam 
quando a quantidade de computadores, M, e o número de conexões entre eles, W, são iguais a 0. Sendo assim, 
enquanto a quantidade de computadores, M, e conexões, W, forem diferentes de 0, os valores são lidos, assim 
como os M-2 valores referentes ao custo de remover os computadores da rede e as W conexões entre dois 
computadores com seu respectivo custo de se cortar a conexão. Após isso, a matriz de adjacência é criada e 
inicializada com 0 e os valores são preenchidos de acordo com a leitura do valor referente aos custo 
aplicando-se a modelagem descrita anteriormente. Após isso, a função para encontrar o fluxo máximo é
chamanda, retornando o resultado.

Tags: fluxo máximo, corte mínimo, bfs, busca em largura, Ford-Fulkerson

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

void copiaMatriz (int **matriz, int **matrizAux, int N){
    int i = 0, j = 0;

    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            matrizAux[i][j] = matriz[i][j];
        }
    }
}

void zeraVetor (int *vetor, int N, int M){
	int i = 0;

	for (i=0; i<N; i++){
        vetor[i] = M;
    }
}

void bfs (int **matriz, int *visitados, int *antecessores, int N, int s, int t){
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

void atualizaMatriz (int **matriz, int *antecessores, int N, int s, int t, int minAresta){
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

int encontraMin (int **matriz, int *antecessores, int N, int s, int t){
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

int fluxoMaximo (int **matriz, int *visitados, int *antecessores, int N, int s, int t){
	int i = 0, minAresta = 0, fluxo = 0;

	while (1){
		bfs (matriz, visitados, antecessores, N, s, t);

		if (visitados[t] != 1){
			break;
		}

		minAresta = encontraMin(matriz, antecessores, N, s, t);
		atualizaMatriz (matriz, antecessores, N, s, t, minAresta);
		zeraVetor (visitados, N, 0);
		zeraVetor (antecessores, N, -1);
		fluxo += minAresta;
	}

	return fluxo;
}

int main () {
    int M = 0, W = 0, m = 0, c = 0, m1 = 0, m2 = 0, d = 0, i = 0, j = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    int fluxo = 0, source = 0, target = 0;
	int **matriz = criaMatriz(52);
	int **matriz2 = criaMatriz(100);

	while (1){

	    cin >> M;
	    cin >> W;

	    if (M == 0 && W == 0){
	    	break;
	    }

	    zeraMatriz(matriz, M);
	    zeraMatriz(matriz2, 2*M-2);

	    int *vertices = (int*)malloc((M+1)*sizeof(int));
	    zeraVetor (vertices, M, 0);

	    source = 0;
	    target = 2*M-3;

	    for (i=0; i<M-2; i++){
	    	cin >> m;
	    	cin >> c;
	    	vertices[m-1] = c;

	    	matriz2[m-1][M-2+m-1] = c;
	    	matriz2[M-2+m-1][m-1] = c;
	    }

	    for (i=0; i<W; i++){
	    	cin >> m1;
	    	cin >> m2;
	    	cin >> d;
	    	matriz[m1-1][m2-1] = d;
	    	matriz[m2-1][m1-1] = d;

	    	if (m1-1 == source){
	    		x1 = source;
	    		y1 = source;
	    	}

	    	else if (m1-1 == M-1){
	    		x1 = target;
	    		y1 = target;
	    	}

	    	else {
	    		y1 = m1-1;
	    		x1 = M-2+m1-1;
	    	}

	    	if (m2-1 == source){
	    		x2 = source;
	    		y2 = source;
	    	}

	    	else if (m2-1 == M-1){
	    		x2 = target;
	    		y2 = target;
	    	}

	    	else {
	    		y2 = m2-1;
	    		x2 = M-2+m2-1;
	    	}

	    	matriz2[x1][y2] = d;
	    	matriz2[x2][y1] = d;
	    }

	    int *visitados = (int*)malloc((2*M-2)*sizeof(int));
	    int *antecessores = (int*)malloc((2*M-2)*sizeof(int));
	    zeraVetor (visitados, 2*M-2, 0);
		zeraVetor (antecessores, 2*M-2, -1);

	  	fluxo = fluxoMaximo(matriz2, visitados, antecessores, 2*M-2, source, target);
	  	cout << fluxo << endl;
	}

    desalocaMatriz(matriz, 52);
    desalocaMatriz(matriz2, 100);
    return 0;
}