#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Figurinhas (URI_1028)

O problema consiste em ler dois inteiros que representam a quantidade de figurinhas que dois 
amigos possuem e determinar a quantidade máxima de figurinhas nas pilhas. Para solucionar
esse problema, após ler um inteiro, N, que representa a quantidade de casos de teste, um for 
é utilizado para considerar os N casos que deverão ser processados. A cada interação, a entrada
descrita acima é lida de forma que n1 e n2 representam, respectivamente, a quantidade de figurinhas
que os amigos possuem. Após a leitura da entrada, basta calcular o mdc entre n1 e n2, uma vez que o
valor do mdc determina justamente a quantidade máxima de figurinhas que deverão existir em cada uma
das pilhas para que os amigos possam trocar as figurinhas de forma que suas pilhas tenham a mesma 
quantidade de figurinhas. Para calcular o mdc, foi aplicado o algoritmo de euclides. Esse algoritmo 
funciona por meio de divisões sucessivas entre os valores que se deseja calcular o mdc. A cada divisão, 
um dos valores assume o valor do outro para que este assuma o valor do resto dessa divisão. O mdc será, 
portanto, o último resto não nulo do processo de divisões sucessivas. Após todo esse processo, o 
resultado do mdc é impresso.

Tags = divisibilidade, mdc, algoritmo de euclides

*/

int calculaMDC (int a, int b){
	int resto = 0, mdc = 0;

	while (a != 0){
		resto = b%a;
		b = a;
		a = resto;
	}

	mdc = b;

	return mdc;
}

int main (){
	int N = 0, i = 0, n1 = 0, n2 = 0, mdc = 0;

	fscanf(stdin, "%d", &N);
	for (i=0; i<N; i++){
		fscanf(stdin, "%d %d", &n1, &n2);

		mdc = calculaMDC(n1, n2);
		
		printf("%d\n", mdc);
	}

	return 0;
}