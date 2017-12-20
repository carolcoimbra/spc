#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Elementar, meu caro Watson! (SPOJ_WCW)

O problema consiste em determinar o menor número de trocas de elementos de uma das 
sequências (os elementos não precisam estar em posições adjacentes na seqüência) que leva 
uma das sequências na outra. Ou seja, o número mínimo de trocas que ordena a sequência dada.
O problema consiste de um número T de casos de teste, dessa forma, basta ler esse valor e
fazer um for para ler cada um dos T casos de teste que seguem. Em cada caso haverá um inteiro
N que representa o tamanho da sequência e, em seguida os N valores da sequência. Essa sequência
é armazenada em um vetor que será passado como parâmetro para uma função que irá calcular o
número de ciclos que tal vetor possui. Cada ciclo encontrado indica que serão necessárias -1
trocas para ordenar o vetor, isso porque para se ordenar os x valores de um ciclo, basta x-1
trocas. Sendo assim, o tamanho do vetor N menos o número de ciclos corresponde à quantidade 
mínima de trocas que devem ser feitas no vetor para que o mesmo seja ordenado. 

Tags: ciclos, vetor, detecção de ciclos em vetores

*/

int encontraCiclos (int vetor[10001], int N){
	int i = 0, ciclo = 0, ciclos = 0, pos = 0, valor = 0;
	int visitados[N];

	for (i=0; i<=N; i++){
		visitados[i] = 0;
	}

	for (i=1; i<=N; i++){
		ciclo = 0;
		pos = i;
		valor = vetor[i];

		while (visitados[valor] == 0){
			pos = valor;
			visitados[pos] = 1;
			valor = vetor[pos]; 

			if (visitados[valor] == 1){
				ciclo = 1;
			}
		}

		if (ciclo == 1){
			ciclos ++;
			ciclo = 0;
		}
	}

	return ciclos;
}

int main (){
 	int T = 0, N = 0, i = 0, j = 0, ciclos = 0;
 	int vetor[10001];

	fscanf (stdin, "%d", &T);

	for (i=0; i<T; i++){
		fscanf(stdin, "%d", &N);

		vetor[0] = 0;
		for (j=1; j<=N; j++){
			fscanf(stdin, "%d", &vetor[j]);
		}

		ciclos = encontraCiclos (vetor, N);
		printf("%d\n", N-ciclos);

	}

	return 0;
}