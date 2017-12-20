#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

#define QUANTIDADE 52

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Total Flow (SPOJ_MTOTALF)

O problema consiste em determinar o fluxo máximo de água que poderá passar de uma nascente 
até chegar na fazenda. A solução do problema envolve um conceito muito importante, o fluxo
máximo. Antes de falar da implementação dessa função, é importante mencionar que a modelagem 
do problema usando grafo foi feita por uma matriz de adjacência na qual cada linha e coluna 
representa um nó do grafo por onde passam os canos de água que conectam uns aos outros e as 
células contém o valor referente ao fluxo que por ali passa. Uma informação importante é que 
a matriz, inicialmente, será simétrica, isso porque o grafo não é direcionado. Entretanto, 
ao longo da execução do algoritmo para encontrar o fluxo máximo, a configuração da matriz 
mudará. Após modelado o problema como um grafo, a função "fluxoMaximo" é criada para determinar 
qual será o maior fluxo de água que poderá passar pelos canos saindo da nascente (s) e chegando à
fazenda (t). Vale ressaltar que esses pontos são determinados por caracteres, sendo assim, deve-se
encontrar o fluxo máximo no grafo entre os vértices 'A' e 'Z' dado que o grafo é formado por 
vértices cujo identificador fornecido é um caractere que pode ser minúsculo ou maiúsculo, ou seja,
existirá no máximo 52 nós. Portanto, a matriz de adjacência já é criada com essa quantidade de
linhas e colunas. Além da matriz de adjacência, a função que calcula o fluxo máximo também recebe 
um vetor de visitados, um vetor de antecessor, um nó inicial ('A' = nó 0), um nó final ('Z' = nó 25)
e o tamanho do grafo (matriz de adjacência). O "fluxoMaximo" é implementado de forma que, começando 
pelo nó inicial, é feita uma busca em largura para que seja encontrado um caminho no grafo que, 
preferencialmente, leve até o nó final. Enquanto a função "bfs" responsável por fazer a busca em 
largura retornar o vetor de visitados na posição referente ao identificador do nó final igual a 1, 
ou seja, o caminho encontrado chega ao nó final, a menor aresta desse caminho é retornada pela 
função "encontraMin". Essa função basicamente percorre o vetor de antecessor preenchido durante a 
execução da "bfs", buscando pela menor aresta dentre as arestas que fazem parte desse caminho. 
Após definido a menor aresta, basta atualizar a matriz de forma que todas as arestas na direção em
que foram percorridas no caminho gerado pela "bfs" são decrementadas com o valor mínimo encontrado.
Já as arestas entre os mesmos nós mas na direção contrária, são incrementadas com esse mesmo valor.
Por fim, o fluxoMáximo é incrementado pelo menor valor encontrado entre as arestas desse caminho.
Após inicializar novamente os vetores visitados e antecessores, a "bfs" é chamada novamente e os 
passos descritos se repetem de forma que, quando o vetor de visitados na posição final for igual a
0, ou seja, o caminho não chegou ao nó final, a função encerra retornando o valor do fluxo máximo.
Nesse problema, os casos de teste são individuais, sendo assim, o valor referente à quantidade de 
canos, N, é lido assim como os N valores referentes ao fluxo entre dois pontos por onde determinado
cano passa e seu respectivo valor (fluxo). Após isso, a matriz de adjacência é criada e inicializada 
com 0 e os valores são preenchidos de acordo com a leitura do valor fluxo, uma informação importante 
é que os valores recebidos como fluxo são incrementados na matriz, uma vez que pode-se receber mais
de um fluxo pelos mesmos pontos, sendo assim, a cada leitura os valores da célula da matriz são 
incrementados e o default é 0. Por fim, a função para encontrar o fluxo máximo é chamada e retorna o 
resultado para o problema.

Tags: fluxo máximo, bfs, busca em largura, Ford-Fulkerson

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

int modificaValores (char x){
	if (x >= 65 && x <= 90){
		return (x - 65);
	}

	if (x >= 97 && x <= 122){
		return (x - 71);
	}
}

int main () {
    int N = 0, f = 0, i = 0, fluxo = 0, x = 0, y = 0;
    char a, b;
	int **matriz = criaMatriz(QUANTIDADE);
    zeraMatriz(matriz, QUANTIDADE);

    cin >> N;

    for (i=0; i<N; i++){
        cin >> a;
        cin >> b;
       	cin >> f;

       	x = modificaValores (a);
       	y = modificaValores (b);

        matriz[x][y] += f;
        matriz[y][x] += f;
    }

    int *visitados = (int*)malloc((QUANTIDADE)*sizeof(int));
    int *antecessores = (int*)malloc((QUANTIDADE)*sizeof(int));
	zeraVetores (visitados, antecessores, QUANTIDADE);

  	fluxo = fluxoMaximo(matriz, visitados, antecessores, QUANTIDADE, 0, 25);

    cout << fluxo << endl;

    desalocaMatriz(matriz, QUANTIDADE);
    return 0;
}