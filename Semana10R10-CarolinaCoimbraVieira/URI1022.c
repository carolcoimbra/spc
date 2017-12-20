#include <stdio.h>
#include <stdlib.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: TDA Racional (URI_1022)

O problema consiste em ler dois inteiros separados por um '/', representando uma fração, uma
operação, que pode ser '+', '-', '*', '/', seguida de outro par de inteiros separados por '/'
e determinar a fração resultante da operação, bem como a fração simplificada. Para solucionar
esse problema, após ler um inteiro, N, que representa a quantidade de casos de teste, um for 
é utilizado para considerar os N casos que deverão ser processados. A cada interação, a entrada
descrita acima é lida de forma que n1 e n2 representam, respectivamente, os numeradores da 
primeira e segunda fração e, d1 e d2 representam, respectivamente, os denominadores da primeira
e segunda fração. Após a leitura da entrada, quatro ifs são responsáveis por verificar qual o
operador está sendo utilizado entre as frações, de modo que, em os cálculos para cada um deles
é dado por:
//Soma: (N1*D2 + N2*D1) / (D1*D2)
//Subtração: (N1*D2 - N2*D1) / (D1*D2)
//Multiplicação: (N1*N2) / (D1*D2)
//Divisão: (N1/D1) / (N2/D2), ou seja (N1*D2)/(N2*D1)
Dessa forma, as variáveis n e d armazenam o resultado das operações antes e depois da '/', 
respectivamente. Já as variáveis n_aux e d_aux armazenam o numerador e o denominador após
aimplificação, ou seja, n dividido pelo mdc(n,d) e d dividido pelo mdc(n,d). Para calcular o mdc, 
foi aplicado o algoritmo de euclides. Esse algoritmo funciona por meio de divisões sucessivas entre
os valores que se deseja calcular o mdc. A cada divisão, um dos valores assume o valor do outro 
para que este assuma o valor do resto dessa divisão. O mdc será, portanto, o último resto não nulo 
do processo de divisões sucessivas. Vale ressaltar que, ao chamar a função para calcular o mdc, é 
passado o valor absoluto de n, uma vez que a fração pode ser negativa. Após todo esse processo, 
o resultado é impresso na seguinte forma: n/d = n_aux/d_aux.

Tags = divisibilidade, mdc, algoritmo de euclides, operações com frações

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
	int N = 0, i = 0, n1 = 0, n2 = 0, n = 0, n_aux = 0, d1 = 0, d2 = 0, d = 0, d_aux = 0, mdc = 0;
	char barra, operacao;

	fscanf(stdin, "%d", &N);
	for (i=0; i<N; i++){
		fscanf(stdin, "%d %c %d %c %d %c %d", &n1, &barra, &d1, &operacao, &n2, &barra, &d2);

		if (operacao == '+'){
			n = n1*d2 + n2*d1;
			d = d1*d2;
		}

		else if (operacao == '-'){
			n = n1*d2 - n2*d1;
			d = d1*d2;
		}

		else if (operacao == '*'){
			n = n1*n2;
			d = d1*d2;
		}

		else if (operacao == '/'){
			n = n1*d2;
			d = n2*d1;
		}

		mdc = calculaMDC(abs(n), d);
		
		n_aux = n/mdc;
		d_aux = d/mdc;
		
		printf("%d%c%d = %d%c%d\n", n, barra, d, n_aux, barra, d_aux);
	}

	return 0;
}