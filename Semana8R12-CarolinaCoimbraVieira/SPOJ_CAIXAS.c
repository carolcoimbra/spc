#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Desempilhando Caixas (SPOJ_CAIXAS)

O problema consiste em, dado uma quantidade de caixas numeradas de 1 a N e uma quantidade
de pilhas P nas quais essas caixas foram empilhadas, determinar o número mínimo de caixas, 
além da caixa 1, que Joãozinho precisa desempilhar para recuperar o seu inventário que está
na caixa de número 1. O problema consiste de vários casos de teste, cada conjunto de teste é 
composto por uma linha, que contém um número inteiro positivo N, que indica a quantidade de
caixas e um número inteiro positivo P que indica a quantidade de pilhas de caixas. A seguir, 
existem P linhas que iniciam com um inteiro Q, indicando a quantidade de caixas que existe
em cada uma das P pilhas, seguido dos Q valores que representam o número das caixas empilhadas
na pilha. A solução do problema consiste em determinar a pilha e a altura na qual a caixa 
de número 1 se encontra. Após isso, o número de caixas que deve ser retirada de cima da caixa 
1 é igual à quantidade de pilhas que existe na pilha onde está a caixa 1 subtraído da altura
onde se encontra a caixa 1 (1 <= altura <= Q). Além disso, deve-se somar à essa quantidade, 
o mínimo entre a quantidades de caixas que deverão ser removidas dos lados da pilha onde se
encontra a caixa 1. Dessa forma, um for percorre o lado esquerdo dessa pilha enquanto outro 
percorre o lado direito, somando a quantidade de caixas que devem ser removidas dessas pilhas
para que a pilha fique menor do que a altura onde a caixa 1 se encontra, sendo assim, o valor
somado a cada pilha é igual a (pilhas[i] - altura) + 1 enquanto essas pilhas forem maiores
do que a altura da caixa 1. Após fazer esse cálcula para ambos os lados, basta determinar
qual dos lados requer que menos caixas sejam retiradas e somar esse valor à quantidade de
caixas que foram retiradas de cima da caixa 1. Vale resslatar que, caso a pilha onde está a 
caixa 1 esteja em uma das extremidades das pilhas, não é necessário percorrer as pilhas 
adjacentes, uma vez que ela se encontra na extremidade e somente as caixas de cima serão
removidas. Nesse caso, apenas o valor de pilhas[pilha] - altura é impresso. O final da 
entrada é indicado por N e P iguais a 0, dessa forma, enquanto N e P forem diferentes de 0, 
um caso de teste é processado. 

Tags: vetores

*/

int minimo (int a, int b){
	if (a < b){
		return a;
	}

	return b;
}
     
int main (){
 	int N = 0, P = 0, Q = 0, q = 0, i = 0, j = 0, pilha = 0, altura = 0, e = 0, d = 0;
 	int pilhas[1010];
   	
   while (1){
		fscanf (stdin, "%d %d", &N, &P);

		if (N == 0 && P == 0){
			break;
		}

		for (i=0; i<P; i++){
			fscanf (stdin, "%d", &Q);
			pilhas[i] = Q;

			for (j=1; j<=Q; j++){
				fscanf (stdin, "%d", &q);

				if (q == 1){
					pilha = i;
					altura = j;
				}
			}
		}

		if (pilha == 0 || pilha == P-1){
			printf("%d\n", (pilhas[pilha] - altura));
		}

		else {
			e = 0;
			d = 0;
			for (i=(pilha-1); i>=0; i--){
   			if (pilhas[i] >= altura){
   				e += (pilhas[i] - altura) + 1;
   			}
   			else {
   				break;
   			}
		   }

   		for (i=(pilha+1); i<P; i++){
   			if (pilhas[i] >= altura){
   				d += (pilhas[i] - altura) + 1;
   			}
   			else {
   				break;
   			}
   		}

		   printf("%d\n", (pilhas[pilha] - altura) + minimo(e, d));
	   }
   }

   return 0;
}