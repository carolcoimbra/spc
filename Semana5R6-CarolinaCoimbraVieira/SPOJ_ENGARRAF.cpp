#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

#define INFINITO 10000000
 
/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Engarrafamento (SPOJ_ENGARRAF)

O problema consiste em determinar se é possível alcançar determinado local em uma cidade 
saindo de um lugar. E, caso seja possível, determinar o tempo mínimo de trajeto. Ou seja,
deve ser possível viajar de s para d com um custo mínimo. A solução do problema envolve 
um conceito muito importante, o caminho mínimo. Antes de falar da implementação dessa 
função, é importante mencionar que a modelagem do problema usando grafo foi feita por uma 
matriz de adjacência na qual cada linha e coluna representa um local da cidade e as células 
contém o valor 0 caso não haja rua entre elas e 1 caso exista. Uma informação importante é 
que as ruas serão informadas como sendo de mão única, ou seja, a matriz não necessariamente 
será simétrica (pode haver ligação entre i-j e não haver entre j-i). Após modelado o problema 
como um grafo, a função "caminhoMinimo" é criada para determinar se dado um local de origem 
é possível alcançar o local de destino e qual será o menor caminho. Para isso, além da matriz 
de adjacência, a função recebe um vetor de distâncias, um nó inicial, um nó final e o tamanho 
do grafo (matriz de adjacência). O "caminhoMinimo" é implementada de forma que, começando pelo 
nó inicial, é feita uma espécie de busca em largura para que seja calculada a distância de todos
os vizinhos do nó atual para ele. Nesse caso, para cada vizinho é necessário saber se sua distância
será atualizada, uma vez que estamos buscando a distância mínima. Sendo assim, caso a distância do
nó atual somada à distância do nó atual para seu vizinho seja menor do que a distância do vizinho 
até o momento, a mesma é atualizada. O vetor de distâncias, inicializado com INFINITO (valor muito
grande), marca em cada posição a menor distância do nó inicial ao nó cujo valor é igual ao índice 
do vetor. Dessa forma, quando todos os vértices tiverem sido verificados, ou seja, a fila para 
calcular a distância de cada um dos nós está vazia, basta retornar o valor que está armazenado no 
vetor de distâncias na posição referente ao nó final. Caso a distância seja INFINITO, significa que 
não existe caminho do nó inicial até o nó final. Dessa forma, o valor que será impresso indica o 
tempo mínimo que uma pessoa leva para ir de um local a outro e, -1 caso isso não seja possível. 
Nesse problema, os casos de teste acabam quando o número de locais, N, e número de ruas, M, são 
iguais a 0. Sendo assim, os valores referentes ao número de locais, N, e o número de ruas, M, são 
lidos assim como os M valores referentes à conexão entre dois locais da cidade e seu respectivo 
tempo de cruzamento. Após isso, a matriz de adjacência é criada e inicializada com 0 e os valores 
são preenchidos de acordo com a leitura do tempo. Por fim, a função para encontrar o menor caminho é 
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
            matriz[i][j] = 0;
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
            if(matriz[no][i] != 0 && distancias[i] > distancias[no] + matriz[no][i]){
                distancias[i] = distancias[no] + matriz[no][i];
                fila.push(i);
            }
        }
        fila.pop();
    }

    if (distancias[d] < INFINITO){
        caminho = distancias[d];
    }

    return caminho;
}

int main () {
    int N = 0, M = 0, m = 0, i = 0, j = 0, t = 0, S = 0, D = 0, tempo = 0;
 	int **locais = criaMatriz(1002);
	
    while (1){
        cin >> N;
        cin >> M;
        if(N == 0 && M == 0){
            break;
        }

        zeraMatriz(locais, N);
        for (m=0; m<M; m++){
        	cin >> i;
        	cin >> j;
        	cin >> t;
        	
            locais[i-1][j-1] = t;
        }

        int *distancias = (int*)malloc((N+1)*sizeof(int));
        for (i=0; i<N; i++){
            distancias[i] = INFINITO;
        }

        cin >> S;
        cin >> D;
        tempo = caminhoMinimo(locais, distancias, N, S-1, D-1);
 
        cout << tempo << endl;
    }

    desalocaMatriz(locais, 1002);
    return 0;
}