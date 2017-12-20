#include <stdio.h>
#include <stdlib.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Pedido de Desculpas (SPOJ_DESCULPA)

O problema consiste em determinar o número máximo de vezes que a palavra "desculpe" aparece,
dados o número de caracteres que cabem no cartão e a quantidade de frases coletadas (com os 
respectivos comprimentos e os números de ocorrências da palavra "desculpe"). O problema possui
múltiplos casos de teste que terminam quando os valores que representam a quantidade de 
caracteres que cabem no cartão, C, e a quantidade de frases, F, são iguais a 0. Dessa forma, 
enquanto esses valores forem diferentes de 0, os mesmos são lidos assim como os F pares de 
valores que representam a quantidade de caracteres das frases e a quantidade de palavras 
"desculpe" em cada uma das F frases. Após ler os valores C e F, um for percorre todas as F
linhas, salvando em um vetor o número de caracteres e o números de "desculpe" de cada uma das
frases, para isso, foi criada uma estrutura chamada "frase" que armazena esses dois inteiros. 
Após preenchido todo o vetor com essas frases, uma matriz é construída de forma que cada uma
de suas colunas representam os caracteres que cabem na carta, ou seja, as colunas possuem
índices que vão de 0 até C (inclusive) e as linhas representam as frases, ou seja, as linhas
possuem índices que vão de 0 a F (inclusive). A linha 0 da matriz é inicializada com 0, pois 
quando não existe nenhuma frase, para qualquer quantidade de caracteres C haverá 0 palavras
"desculpe". A partir da linha 1 é necessário percorrer por todas as colunas para saber se a
quantidade de caracteres da frase representada por essa linha é menor ou igual à quantidade
de caracteres que cabe na carta até o momento (coluna). Caso não seja, a quantidade que coube
na carta anteriormente, ou seja, a quantidade de caracteres que coube na carta até esse ponto
na frase anterior é copiada (matriz[i][j] = matriz[i-1][j]). Porém, caso o número de caracteres
da frase seja menor ou igual à quantidade que cabe na carta até o momento, é necessário 
verificar o que é melhor, manter a quantidade que coube na carta anteriormente ou somar à 
quantidade que coube na carta anteriormente até o números de caracteres que coube até o momento
menos o número de caracteres que a frase possui com a quantidade de "desculpe" que a frase
possui (MAX(matriz[i-1][j], (matriz[i-1][j-(frases[i-1].num_caracteres)]+(frases[i-1].num_desculpas)))).
Dessa forma, quando toda a matriz tiver sido preenchida, basta imprimir o valor que está na
última linha e última coluna (matriz[F][C]) uma vez que esse valor representa a quantidade 
máxima de desculpas que podem ser colocadas em uma carta de tamanho C.
Em outras palavras, esse problema nada mais é do que o problema da mochila cuja solução é dado
por: 
m[0,w]=0
m[i,w] = m [i−1,w] se wi > w 
m[i,w] = max (m[i−1,w], m [i−1,w−wi] + vi) se wi <= w
Conforme explicado acima. 

Tags: problema da mochila, programação dinâmica, struct, vetor, matriz

*/

typedef struct {
	int num_caracteres;
	int num_desculpas;
} frase;

int maximo (int a, int b){
	if (a > b){
		return a;
	}
	return b;
}

int main (){
	int C = 0, F = 0, i = 0, j = 0, t = 0; 
	frase frases[50];
	int matriz[51][1001];

	while (1){
		t++;

		fscanf(stdin, "%d %d", &C, &F);

		if (C == 0 && F == 0){
			break;
		}

		for (i=0; i<F; i++){
			fscanf(stdin, "%d %d", &frases[i].num_caracteres, &frases[i].num_desculpas);
		}

		for (j=0; j<C; j++){
			matriz[0][i] = 0;
		}

		for (i=1; i<=F; i++){
			for (j=0; j<=C; j++){
				if (frases[i-1].num_caracteres > j){
					matriz[i][j] = matriz[i-1][j];
				}
				else{
					matriz[i][j] = maximo(matriz[i-1][j], (matriz[i-1][j-(frases[i-1].num_caracteres)] + (frases[i-1].num_desculpas)));
				}
			}
		}

		printf("Teste %d\n", t);
		printf("%d\n", matriz[F][C]);
		printf("\n");
	}
	
	return 0;
}
