#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

#define INFINITO 10000000
 
/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Caminho das Pontes (SPOJ_PONTES09)

O problema consiste em determinar o número mínimo de buracos nas pontes através das quais
um rapaz deve atravessar para o outro lado de um desfiladeiro. A solução do problema envolve 
um conceito muito importante, o caminho mínimo. Antes de falar da implementação dessa 
função, é importante mencionar que a modelagem do problema usando grafo foi feita por uma 
matriz de adjacência na qual cada linha e coluna representa um pilar por onde passam as pontes
que conectam uns aos outros e as células contém o valor referente à quatidade de buracos que 
existe em cada uma das pontes que conectam esses pilares. Uma informação importante é que a 
matriz será simétrica (se há ligação entre i-j, há entre j-i), já que trata-se de um grafo 
não direcionado. Após modelado o problema como um grafo, a função "caminhoMinimo" é criada 
para determinar qual será o menor número de buracos que o rapaz deverá pular saindo do ponto 
inicial (0) e chegando no acampamento (N+1). Para isso, além da matriz de adjacência, a função 
recebe um vetor de distâncias, um nó inicial, um nó final e o tamanho do grafo (matriz de 
adjacência). O "caminhoMinimo" é implementada de forma que, começando pelo nó inicial, é feita 
uma espécie de busca em largura para que seja calculada a distância de todos os vizinhos do nó 
atual para ele. Nesse caso, para cada vizinho é necessário saber se sua distância (número de 
buracos) será atualizada, uma vez que estamos buscando a distância mínima (menor número de buracos).
Sendo assim, caso a distância do nó atual somada à distância do nó atual para seu vizinho seja 
menor do que a distância do vizinho até o momento, a mesma é atualizada. O vetor de distâncias, 
inicializado com INFINITO (valor muito grande), marca em cada posição a menor distância do nó inicial 
ao nó cujo valor é igual ao índice do vetor. Dessa forma, quando todos os vértices tiverem sido 
verificados, ou seja, a fila para calcular a distância de cada um dos nós está vazia, basta 
retornar o valor que está armazenado no vetor de distâncias na posição referente ao nó final. 
Nesse caso, como o problema garante que sempre haverá um caminho, basta imprimir o valor que 
está armazenado no vetor de distâncias na posição do pilar final (acampamento). Nesse problema, 
os casos de teste são individuais, sendo assim os valores referentes ao número de pilares, N, e 
o número de pontes, M, são lidos assim como os M valores referentes à conexão entre dois pilares 
e sua respectiva quantidade de buracos que está sendo tratada como sendo a distância que deverá
ser pulada pelo jovem entre os dois pilares. Após isso, a matriz de adjacência é criada e 
inicializada com -1 já que o número de buracos que serão armazenados na mesma podem ser 0, ou seja, 
pode existir uma ponte que não tenha nenhum buraco e essa seria, certamente, a melhor opção. Depois
da inicialização, os valores são preenchidos de acordo com a leitura do número de buracos entre cada
um dos pares de pilares fornecidos na entrada. Por fim, a função para encontrar o menor caminho é 
chamada e retorna o resultado para o problema.

Tags: grafo, matriz de adjacência, dijkstra, caminho mínimo

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
            matriz[i][j] = -1;
        }
    }
}

int caminhoMinimo (int **matriz, int *distancias, int N, int s, int d){
    int i = 0, no = 0, inicio = 0, fim = 0, caminho = -1;
    queue<int> fila;

    distancias[s] = 0;
    fila.push(s);

    while (!fila.empty()){
        for (i=0; i<N; i++){
            no = fila.front();
            if(matriz[no][i] != -1 && distancias[i] > distancias[no] + matriz[no][i]){
                distancias[i] = distancias[no] + matriz[no][i];
                fila.push(i);
            }
        }
        fila.pop();
    }

    caminho = distancias[d];
    return caminho;
}

int main () {
    int N = 0, M = 0, m = 0, i = 0, j = 0, b = 0, buracos = 0;
 	int **pilares = criaMatriz(1010);
	
    cin >> N;
    cin >> M;

    zeraMatriz(pilares, N+2);
    for (m=0; m<M; m++){
      	cin >> i;
       	cin >> j;
       	cin >> b;
       	
        pilares[i][j] = b;
        pilares[j][i] = b;
    }

    int *distancias = (int*)malloc((N+3)*sizeof(int));
    for (i=0; i<N+2; i++){
        distancias[i] = INFINITO;
    }

    buracos = caminhoMinimo(pilares, distancias, N+2, 0, N+1);
 
    cout << buracos << endl;

    desalocaMatriz(pilares, 1010);
    return 0;
}