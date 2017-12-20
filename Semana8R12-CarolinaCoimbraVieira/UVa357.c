#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Let Me Count The Ways (UVa_357)

O problema consiste em determinar a quantidade de combinações que podem ser feitas utilizando
as 5 moedas dos EUA (1c, 5c, 10c, 25c e 50c) para formar um valor daddo, N. Os casos de teste
consistem de apenas um valor N e terminam com o fim do arquivo, ou seja, enquanto a leitura de
N for diferente de EOF, o caso de teste é processado. A solução do problema consiste em montar
um vetor de N+1 posições na qual cada posição indica o valor representado pelo seu índice.
Dessa forma, o vetor inicia preenchido com 0 e somente a posição zero possui o valor 1, isso
porque para formar o valor 0 só existe 1 forma: não usar moeda nenhuma. A seguir, para cada
valor de moeda, o vetor é percorrido de modo que o valor contido nas posições do vetor são 
incrementados de acordo com os valores calculados anteriormente, ou seja, o número de 
combinações em j é somado ao número de combinações que já existiam antes dessa moeda ser 
introduzida. Dessa forma, a fórmula geral para esse problema é dada por:
M(n,i) = M(n,i−1) + M(n−ci,i), sendo M(n,i) o número de maneiras de se obter moedas que 
totalizam n utilizando apenas i tipos de moedas distintas (0 < i ≤ 5).
 

Tags: programação dinâmica, coin change problem

*/

void zeraVetor (long int vetor[30001]){
	int i = 0;

	for (i=0; i<30001; i++){
		vetor[i] = 0;
	}
}

int main (){
 	int N = 0, i = 0, j = 0, moeda = 0;
 	long int M = 0;
 	int moedas[5] = {1, 5, 10, 25, 50};
 	long int vetor[30001];

 	while (fscanf (stdin, "%d", &N) != EOF){

 		zeraVetor (vetor);
 		vetor[0] = 1;

		for (i=0; i<5; i++){
			moeda = moedas[i];
			for (j=moeda; j<=N; j++){
				vetor[j] += vetor[j-moeda];
			}
		}

		M = vetor[N];
		if (M == 1){
			printf("There is only 1 way to produce %d cents change.\n", N);
		}
		else {
			printf("There are %ld ways to produce %d cents change.\n", M, N);
		}
	}

	return 0;
}