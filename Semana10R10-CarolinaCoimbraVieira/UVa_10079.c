#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Pizza Cutting (UVa_10079)

O problema consiste em ler um inteiro N e determinar a quantidade de pedaços que são gerados
cortando uma pizza N vezes. A solução desse problema envolve uma fórmula que, dado o número
de linhas que serão desenhadas no plano, retorna a quantidade de regiões que resultarão.
A fórmula é dada por: (N^2 + N)/2 + 1.
Dessa forma, com 0 cortes tem-se 1 pedaço, com 1 cortes tem-se 2 pedaços, com 2 cortes tem-se
4 pedaços, com 3 cortes tem-se 7 pedaços, e assim por diante... Sendo assim, para cada
inteiro N lido, o resultado consiste da substituição de N na fórmula acima. Vale lembrar que 
os casos de teste terminam quando o inteiro é negativo, ou seja, menor do que 0, sendo assim, 
quando isso ocorre, a leitura dos casos de teste se encerra.

Tags = divisibilidade, cortes

*/

int main (){
	long long int N = 0, resultado = 0;

	while (1){
		fscanf(stdin, "%lld", &N);

		if (N < 0){
			break;
		}

		resultado = (((N*N) + N)/2) + 1;
		printf("%lld\n", resultado);
	}

	return 0;
}