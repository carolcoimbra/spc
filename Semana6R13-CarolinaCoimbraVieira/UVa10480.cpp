#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Sabotage (UVa 10480)

O problema consiste em determinar o menor número de conexões, que se apagadas, impede completamente
a comunicação entre duas cidades, a capital (1, nó 0) e a maior cidade (2, nó 1). A solução do 
problema envolve dois conceitos muito importante, o fluxo máximo e o corte mínimo, uma vez que o corte
mínimo é derivado do fluxo máximo. Antes de falar da implementação dessa função, é importante mencionar 
que a modelagem do problema usando grafo foi feita por uma matriz de adjacência na qual cada linha e 
coluna representa um nó do grafo que indicam as cidades e as células contém o valor referente ao custo 
de se cortar a conexão entre essas cidades. Uma informação importante é que a matriz, inicialmente, 
será simétrica, isso porque o grafo não é direcionado. Entretanto, ao longo da execução do algoritmo 
para encontrar o fluxo máximo, a confiração da matriz mudará. Após modelado o problema como um grafo, 
a função "fluxoMaximo" é criada de forma que, ao final seja possível ver as arestas que restaram no grafo
após a execução do algoritmo. Além da matriz de adjacência, a função que calcula o fluxo máximo também 
recebe um vetor de visitados, um vetor de antecessor, um nó inicial (s = nó 0 na matriz), um nó final 
(t = nó 1 na matriz) e o tamanho do grafo (matriz de adjacência). O "fluxoMaximo" é implementado de forma
que, começando pelo nó inicial, é feita uma busca em largura para que seja encontrado um caminho no grafo 
que, preferencialmente, leve até o nó final. Enquanto a função "bfs" responsável por fazer a busca em 
largura retornar o vetor de visitados na posição referente ao identificador do nó final igual a 1, ou 
seja, o caminho encontrado chega ao nó final, a menor aresta desse caminho é retornada pela função 
"encontraMin". Essa função basicamente percorre o vetor de antecessor preenchido durante a execução da 
"bfs", buscando pela menor aresta dentre as arestas que fazem parte desse caminho. Após definido a menor 
aresta, basta atualizar a matriz de forma que todas as arestas na direção em que foram percorridas 
no caminho gerado pela "bfs" são decrementadas com o valor mínimo encontrado. Já as arestas entre 
os mesmos nós mas na direção contrária, são incrementadas com esse mesmo valor. Após inicializar novamente 
os vetores visitados e antecessores, a "bfs" é chamada novamente e os passos descritos se repetem de 
forma que, quando o vetor de visitados na posição final for igual a 0, ou seja, o caminho não chegou 
ao nó final, a função encerra. Após a execução do algoritmo de fluxo máximo, basta rodar uma busca em
profundidade começando pelo nó inicial (s = nó 0) sobre a matriz resultante do fluxo máximo e, após isso
imprimir todas os pares de vértices de forma que um deles foi visitado e o outro não, ou seja, não foi
possível chegar em um depois do outro mas que possuíam aresta na matriz original. Dessa forma, essas
arestas representam as arestas que foram excluídas pelo fluxo máximo. Nesse problema, as entradas terminam 
quando a quantidade de cidades, N, e o número de conexões entre elas, M, são iguais a 0. Sendo assim, 
enquanto a quantidade de cidades, N, e conexões, M, forem diferentes de 0, os valores referentes ao 
são lidos, assim como as M conexões entre duas cidades com seu respectivo custo de se cortar a conexão. 
Após isso, a matriz de adjacência é criada e inicializada com 0 e os valores são preenchidos de acordo com 
a leitura do valor referente ao custo, uma informação importante é que os valores recebidos como custo 
são incrementados na matriz, uma vez que pode-se receber mais de um custo pelas mesmas cidades, sendo assim, 
a cada leitura os valores da célula da matriz são incrementados e o default é 0. Essa matriz é copiada para
uma outra matriz auxiliar que será utilizada na função para encontrar o fluxo máximo bem como para a função 
que fará uma busca em profundidade para determinar os nós que não puderam ser alcançados. Por fim, a função para 
encontrar o fluxo máximo é chamada seguida da função para imprimir as arestas do corte mínimo.

Tags: fluxo máximo, corte mínimo, bfs, busca em largura, dfs, busca em profundidade,
	  Ford-Fulkerson

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

void zeraVetores (int *visitados, int *antecessores, int N){
	int i = 0;

	for (i=0; i<N; i++){
        visitados[i] = 0;
        antecessores[i] = -1;
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

void dfs (int **matriz, int *visitados, int N, int v){
	int i = 0;

	visitados[v] = 1;
	for (i=0; i<N; i++){
		if(matriz[v][i] == 1 && visitados[i] == 0){
			dfs(matriz, visitados, N, i);
		}
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
		zeraVetores (visitados, antecessores, N);
		fluxo += minAresta;
	}

	return fluxo;
}

void corteMinimo (int **matriz, int **matrizAux, int *visitados, int N, int s){
	int i = 0, j = 0;

    dfs(matrizAux, visitados, N, s);

    for (i=0; i<N; i++){
    	for (j=0; j<N; j++){
        	if (visitados[i] == 1 && visitados[j] == 0 && matriz[i][j] != 0){
            	cout << i+1 << " " << j+1 << endl;
        	}
        }
    }
}

int main () {
    int N = 0, M = 0, x = 0, y = 0, b = 0, i = 0, fluxo = 0;
	int **matriz = criaMatriz(52);
	int **matrizAux = criaMatriz(52);

	while (1){

	    cin >> N;
	    cin >> M;

	    if (N == 0 && M == 0){
	    	break;
	    }

	    zeraMatriz(matriz, N);
	    zeraMatriz(matrizAux, N);

	    for (i=0; i<M; i++){
	    	cin >> x;
		    cin >> y;
		    cin >> b;

	        matriz[x-1][y-1] += b;
	        matriz[y-1][x-1] += b;
	    }

	    int *visitados = (int*)malloc((N+1)*sizeof(int));
	    int *antecessores = (int*)malloc((N+1)*sizeof(int));
		zeraVetores (visitados, antecessores, N);

		copiaMatriz (matriz, matrizAux, N);

	  	fluxo = fluxoMaximo(matrizAux, visitados, antecessores, N, 0, 1);
	  	corteMinimo (matriz, matrizAux, visitados, N, 0);
	  	cout << "\n";
	}

    desalocaMatriz(matriz, 52);
    desalocaMatriz(matrizAux, 52);
    return 0;
}