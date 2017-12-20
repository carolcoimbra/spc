#include <stdio.h>
#include <string.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Encontre o telefone (SPOJ_ENCOTEL)

O problema consiste em ler uma string formada pelos caracteres de A-Z, '-' e números 1 e 0, 
e transformá-la em um número de telefone de acordo com o mapeamento dado entre as letras de
A-Z e os números de 2 a 9. Sendo assim, foi criado um vetor de caracteres com 26 posições de 
forma que, cada posição representa uma letra do alfabeto e contém o dígito correspondente à
mesma de acordo com o problema. Após isso, cada string pé lida de modo que, caso o código 
ascii esteja ante 65 e 90, ou seja, trata-se de uma letra do alfabeto, o dígito correspondente
à mesma no vetor é armazenado no vetor com os dígitos da resposta. Entretanto, caso o caractere
lido não seja uma letra do alfabeto, significa que ele pode ser o dígito 0, 1 ou o caractere '-',
sendo assim, ele será somente copiado para o vetor resposta. Por fim, quando todo o vetor com a 
string de entrada tiver sido percorrido, basta inserir o caractere '\0' no vetor resposta para
finalizá-lo e, posteriormente imprimí-lo como uma string. Nesse caso, existem vários casos de 
teste que terminam com final de arquivo (EOF), sendo assim, basta ler a string enquanto não for
fim de arquivo, percorrê-la e salvar os caracteres modificados em um vetor que será impresso em
seguida. .  

Tags = strings, imprimir strings, comparação de strings, ascii

*/

int main (){
	int i = 0, valor = 0;
	char C[40], R[40];
	char vetor[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'};
   	
   	while (fscanf (stdin, "%s", C) != EOF){
   		for (i=0; i<strlen(C); i++){
   			valor = C[i];
   			if (valor >= 65 && valor <= 90){
   				R[i] = vetor[valor - 65];
   			}
   			else {
   				R[i] = C[i];
   			}
   		}

   		R[i] = '\0';
   		printf("%s\n", R);
   	}

   	return 0;
}