#include <stdio.h>
#include <stdlib.h>

#define INFINITO 1000000

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Moedas (SPOJ_MOEDAS)

O problema consiste em determinar o número mínimo de moedas, caso seja possível, que podem
ser usadas para pagar uma mercadoria dados o preço de uma mercadoria e os valores das moedas 
disponíveis. O problema possui múltiplos casos de teste que terminam quando o valor que 
representa o preço da mercadoria, M, é igual a 0. Dessa forma, enquanto esse valor for
diferente de 0, ele é lido, assim como o valor referente à quantidade de moedas, N, e os
N valores que representam o valor de cada uma das N moedas. Após ler os valores M e N, um 
for percorre todas as N linhas, salvando em um vetor o o valor das moedas. Após preenchido 
todo o vetor com esses valores, uma matriz é construída de forma que cada uma de suas colunas 
representam os valores 0 incrementados de 1 até chegarem em M, ou seja, as colunas possuem
índices que vão de 0 até M (inclusive) e as linhas representam o valor das moedas, ou seja, 
as linhas possuem índices que vão de 0 a N (inclusive). A linha 0 da matriz é inicializada 
com INFINITO, pois quando não existe nenhuma moeda, é impossível atingir o valor M. Além 
disso, a primeira coluna é toda preenchida com 0, pois para um valor de mercadoria igual a 0
são necessárias 0 moedas. A partir da linha 1 é necessário percorrer por todas as colunas a 
partir da coluna 1, para saber se a moeda representada por essa linha é igual ao valor da
mercadoria até o momento (coluna). Caso isso seja verdade, é preciso apensa uma moeda desse
valor para comprar a mercadoria (matriz[i][j] = 1). Caso a moeda representada por essa linha 
seja maior do que o valor da mercadoria até o momento (coluna), significa que não é possível 
pagar a mercadoria com esse valor de moeda, sendo assim, basta copiar a quantidade de moedas 
anteriores que foram usadas para pagar a mercadoria (matriz[i][j] = matriz[i-1][j]). E, por
fim, caso contrário, é necessário verificar o que é melhor, manter a quantidade que foi da
moeda anterior, ou somar à quantidade dessas moedas usadas para representar o valor de 
mercadoria menos o valor da moeda a 1 (minimo (matriz[i-1][j], (1 + matriz[i][j-moedas[i-1]]))). 
Dessa forma, quando toda a matriz tiver sido preenchida, basta imprimir o valor que está na
última linha e última coluna (matriz[N][M]) uma vez que esse valor representa a quantidade 
mínima de moedas que podem ser usadas para comprar uma mercadoria que custa M. Porém, caso
esse valor seja maior ou igual à INFINITO, significa que não é possível comprar essa mercadoria
sem troco, sendo assim, basta imprimir "Impossivel".

Tags: Change-making problem, CMP, programação dinâmica, vetor, matriz

*/

int **criaMatriz (int N, int M){
    int i = 0, j = 0;
    int **matriz = (int**)malloc((N)*sizeof(int*));

    for (i=0; i<N; i++){
        matriz[i] = (int*)malloc((M)*sizeof(int));
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

int minimo (int a, int b){
	if (a < b){
		return a;
	}
	return b;
}

int main (){
	int N = 0, M = 0, i = 0, j = 0, count = 0;
	int moedas[100];
	int **matriz = criaMatriz (101, 50001);

	while (1){
		fscanf(stdin, "%d", &M);

		if (M == 0){
			break;
		}

		fscanf(stdin, "%d", &N);

		for (i=0; i<N; i++){
			fscanf(stdin, "%d", &moedas[i]);
		}

		for (i=0; i<=N; i++){
			matriz[i][0] = 0;
		}

		for (j=0; j<=M; j++){
			matriz[0][j] = INFINITO;
		}		

		for (i=1; i<=N; i++){
			for (j=1; j<=M; j++){
				if (moedas[i-1] == j){
					matriz[i][j] = 1;
				}
				else if (moedas[i-1] > j){
					matriz[i][j] = matriz[i-1][j];
				}
				else {
					matriz[i][j] = minimo (matriz[i-1][j], (1 + matriz[i][j-moedas[i-1]]));
				}
			}
		}

		if (matriz[N][M] >= INFINITO){
			printf("Impossivel\n");
		}
		else {
			printf("%d\n", matriz[N][M]);
		}
	}

	desalocaMatriz (matriz, 101);
	return 0;
}
