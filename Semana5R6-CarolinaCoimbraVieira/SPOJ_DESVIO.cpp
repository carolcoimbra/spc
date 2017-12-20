#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

#define INFINITO 100000

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Desvio de Rota (SPOJ_DESVIO)

O problema consiste em determinar número mínimo de pedágios que uma empresa pagará saindo
de uma cidade onde o carro foi consertado até o destino das entregas. A solução do problema 
envolve um conceito muito importante, o caminho mínimo. Antes de falar da implementação dessa 
função, é importante mencionar que a modelagem do problema usando grafo foi feita por uma 
matriz de adjacência na qual cada linha e coluna representa uma cidade por onde passam as 
estradas que conectam umas as outras e as células contém o valor referente ao custo do pedágio
entre as cidades. Uma informação importante é que a matriz não será simétrica, isso porque 
existem algumas restrições quanto ao caminho que deverá ser percorrido pelo entregador, sendo
que as mesmas são especificadas a seguir:
* Se as duas cidades não fazem parte da rota, a estrada (aresta) é adicionada nos dois sentidos.
* Se uma pertence à rota e a outra não, apenas a estrada (aresta) que chega na cidade que está 
na rota é adicionada, isso porque caso o entregador chegue em uma cidade que faz parte da rota, 
ele deve seguir a rota.
* Se as cidades são vizinhas, a estrada (aresta) é adicionada nos dois sentidos.
Após modelado o problema como um grafo, a função "caminhoMinimo" é criada para determinar 
qual será o menor valor de pedágios que a empresa pagará saindo da cidade do conserto do carro
(cidade K) até o destino das entregas (cidade C-1). Para isso, além da matriz de adjacência, a 
função recebe um vetor de distâncias, um nó inicial, um nó final e o tamanho do grafo (matriz de 
adjacência). O "caminhoMinimo" é implementada de forma que, começando pelo nó inicial, é feita 
uma espécie de busca em largura para que seja calculada a distância de todos os vizinhos do nó 
atual para ele. Nesse caso, para cada vizinho é necessário saber se sua distância (custo de 
pedágios) será atualizada, uma vez que estamos buscando a distância mínima (menor custo de 
pedágios). Sendo assim, caso a distância do nó atual somada à distância do nó atual para seu 
vizinho seja menor do que a distância do vizinho até o momento, a mesma é atualizada. O vetor 
de distâncias, inicializado com INFINITO (valor muito grande), marca em cada posição a menor 
distância do nó inicial ao nó cujo valor é igual ao índice do vetor. Dessa forma, quando todos 
os vértices tiverem sido verificados, ou seja, a fila para calcular a distância de cada um dos 
nós está vazia, basta retornar o valor que está armazenado no vetor de distâncias na posição 
referente ao nó final. Nesse caso, como o problema garante que sempre haverá um caminho, basta 
imprimir o valor que está armazenado no vetor de distâncias na posição da cidade final. Nesse 
problema, os casos de teste acabam quando o número de cidades, N, o número de estradas, M, o 
número de cidades na rota, C, e a cidade onde o carro foi consertado, K, são iguais a 0. Sendo 
assim, os valores referentes ao número de cidades, N, o número de estradas, M, o número de cidades 
na rota, C, e a cidade onde o carro foi consertado, K, são lidos assim como os M valores referentes 
à estrada entre dois locais da cidade e seu respectivo custo de pedágio. Após isso, a matriz de 
adjacência é criada e inicializada com -1 e os valores são preenchidos de acordo com a leitura do 
custo do pedágio. Por fim, a função para encontrar o menor caminho é chamada e retorna o resultado 
para o problema.

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

int caminhoMinimo (int **matriz, int *distancias, int *visitados, int N, int s, int d){
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
        visitados[no] = 0;
        fila.pop();
    }

    if (distancias[d] != INFINITO){
        caminho = distancias[d];
    }

    return caminho;
}

int main () {
    int N = 0, M = 0, C = 0, K = 0, m = 0, i = 0, u = 0, v = 0, p = 0, S = 0, D = 0, pedagios = 0;
 	int **cidades = criaMatriz(255);
	
    while (1){
        cin >> N;
        cin >> M;
        cin >> C;
        cin >> K;

        if(N == 0 && M == 0 && C == 0 && K == 0){
            break;
        }

        zeraMatriz(cidades, N);

        for (m=0; m<M; m++){
        	cin >> u;
        	cin >> v;
        	cin >> p;

            if (u >= C && v >= C){
                cidades[u][v] = p;
                cidades[v][u] = p;
            }

            if (u >= C && v < C){
                cidades[u][v] = p;
            }

            if (v >= C && u < C){
                cidades[v][u] = p;
            }

            if (u == v+1 || v == u+1){
                cidades[u][v] = p;
                cidades[v][u] = p;
            }                
        }

        int *distancias = (int*)malloc((N+1)*sizeof(int));
        int *visitados = (int*)malloc((N+1)*sizeof(int));

        for (i=0; i<N; i++){
            distancias[i] = INFINITO;
            visitados[i] = -1;
        }

        pedagios = caminhoMinimo(cidades, distancias, visitados, N, K, C-1);
 
        cout << pedagios << endl;
    }

    desalocaMatriz(cidades, 255);
    return 0;
}