#include <stdio.h>
#include <stdlib.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Jogo do Bicho (SPOJ_BICHO)

O problema consiste em determinar a quantidade que um apostador de Jogo do Bicho irá ganhar.
Para isso, cada caso de teste do problema a entrada consiste de um valor V igual à quantidade
apostada pelo jogador, um número N igual ao número apostado e um número M correspondente ao 
número sorteado no jogo. O prêmio de cada apostador é calculado da seguinte forma:
* se M e N têm os mesmos quatro últimos dígitos (milhar, centena, dezena e unidade), o 
apostador recebe V × 3000 (por exemplo, N = 99301 e M = 19301): (N%10000 == M%10000)
* se M e N têm os mesmos três últimos dígitos (centena, dezena e unidade), o apostador recebe 
V × 500 (por exemplo, N = 38944 e M = 83944): (N%1000 == M%1000)
* se M e N têm os mesmos dois últimos dígitos (dezena e unidades), o apostador recebe V × 50 
(por exemplo, N = 111 e M = 552211): (N%100 == M%100)
* se M e N têm os dois últimos dígitos no mesmo grupo, correspondendo ao mesmo animal, o 
apostador recebe V × 16 (por exemplo, N = 82197 and M = 337600):
N/4 == M/4 || (N%4 == 0 && M/4 == N/4 - 1) || (M%4 == 0 && N/4 == M/4 - 1)
* se nenhum dos casos acima ocorrer, o apostador não recebe nada.
Uma informação importante é que, para que dois valores M e N sejam do mesmo grupo, a seguinte 
condição deve ser satisfeita: caso os dois últimos dígitos do número seja iguais a 0, significa 
que ele pertence ao grupo dos valores 97, 98, 99. Dessa forma, seu valor é atualizado para 100. 
Além disso, dois números pertencem ao mesmo grupo se a divisão de sua dezena por 4 é igual à 
divisão do outro valor por 4 ou se o resto da divisão por 4 de um desses valores é igual a 0 e 
a divisão do outro valor por 4 é igual a um valor uma unidade menor. Ou seja, 1, 2,  e 1, 4 são 
do mesmo grupo porque 1/4 = 0 e 2/4 = 0 e 1/4 = 0 e (4%4 = 0 e 4/4 = 1, 0+1).

Dessa forma, após ler os valores de V, N e M, basta verficar se os mesmos são diferentes de 0, 
uma vez os casos de testes se encerram quando todos os valores são iguais a 0. Caso o caso de 
teste seja válido, a entrada descrita acima é lida. Após a leitura da entrada, basta calcular 
o resultado do jogo de utilizando ifs sequenciais que verificam cada uma das condições apresentadas
acima na ordem em que aparecem. O resultado é retornado na primeira condição satisfeita e o mesmo
é calculado conforme apresentado anteriormente.

Tags = mod, divisão

*/

double jogoBicho (int N, int M, double V){
	double R = 0.0;

	if (N%10000 == M%10000){
		R = (V * 3000.00);
		return R;
	}

	else if (N%1000 == M%1000){
		R = (V * 500.00);
		return R;
	}

	else if (N%100 == M%100){
		R = (V * 50.00);
		return R;
	} 

	N = N%100;
	if (N == 0){
		N = 100;
	}

	M = M%100;
	if (M == 0){
		M = 100;
	}

	else if (N/4 == M/4 || (N%4 == 0 && M/4 == N/4 - 1) || (M%4 == 0 && N/4 == M/4 - 1)){
		R = (V * 16.00);
		return R;
	}

	return R;
}

int main (){
	int N = 0, M = 0, i = 0;
	double V = 0.0, R = 0.0;

	while (1){
		fscanf(stdin, "%lf %d %d", &V, &N, &M);

		if (V == 0.0 && N == 0 && M == 0){
			break;
		}

		R = jogoBicho(N, M, V);
			
		printf("%.2lf\n", R);
	}

	return 0;
}