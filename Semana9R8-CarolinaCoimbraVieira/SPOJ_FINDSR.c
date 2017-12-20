#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Find String Roots (SPOJ_FINDSR)

O problema consiste em ler uma string e determinar um valor Q tal que uma substring T da string
concatenada N vezes dê a própria string. Para esse problema, basta ler a string e salvar seu
tamanho, N. Após isso, um for faz com que todos os valores entre N e 1, inclusive, sejam testados
como possíveis valores para dividir a string em substrings de N caracteres. Nesse caso, deve-se
verificar se esse N é divisível por esse valor, já que as substrings devem ter tamanhos iguais.
Além disso, busca-se o menor valor para que a string seja menor possível, maximizando assim, o 
Q, uma vez que Q é a quantidade de repetições dessa substring. Sendo assim, caso N seja divisível
pelos valores assumidos pela variável i no for, uma substring de tamanho i é copiada para uma
strings auxiliar e, a partir de então, todos os caracteres da string serão comparados aos caracteres
"mod i" da substring. Ou seja, para cada posição j na string, a posição j mod i da string deve ser
correpondente, uma vez que a string deve ser uma comcatenação das strings. Sendo assim, caso isso
essa condição seja satisfeita até o final da string, o valor de Q é salvo, sendo que Q será igual
ao tamanho da string, N, dividido pelo tamanho da string, i. Porém, caso a condição falhe em alguma
posição, uma flag, check, é setada em 1 e as comparação terminam para aquela substring candidata.
Ao final de todas as comparações, basta imprimir o valor armazenado em Q. Nesse caso, existem vários 
casos de teste que terminam a string é igual a "*", sendo assim, basta ler a mesma enquanto for 
diferente de "*", efetuar as operações descritas acima e imprimir o resultado.  

Tags = strings, mod, substring, comparação de strings

*/

int main (){
	int N = 0, i = 0, j = 0, check = 0, quantidade = 0;
	char *S = (char*)malloc(100010*sizeof(char));
	char *substring = (char*)malloc(100010*sizeof(char));

	while (1){
		gets(S);

		if (strcmp(S, "*") == 0){
			break;
		}

		N = strlen(S);

		for (i=N; i>=1; i--){
			if (N%i == 0){
				check = 0;

				strncpy(substring, S, i);
				substring[i] = '\0';

				for (j=0; j<N; j++){
					if (S[j] != substring[j%i]){
						check = 1;
						break;
					}
				}

				if (check == 0){
					quantidade = N/i;
				}
			}
		}

		printf("%d\n", quantidade);
	}

	return 0;
}
