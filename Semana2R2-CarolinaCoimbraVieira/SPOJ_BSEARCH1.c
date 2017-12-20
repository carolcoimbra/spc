#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Binary Search (SPOJ_BSEARCH1)

O problema consiste em determinar se um determinado inteiro está presente em um vetor ordenado
de inteiros e, caso esteja, imprimir a posição da sua primeira ocorrência. Para esse problema, 
foi implementado o algoritmo de busca binária que consiste em "particionar" o vetor ordenado e
"caminhar" nas metades de acordo o valor que se deseja encontrar. Por exemplo, uma vez que o 
vetor está ordenado, os menores valores estão do meio para a esquerda enquanto os maiores valores
encontram-se do meio para a direita (fim do vetor). Dessa forma, basta iniciar a busca pelo elemento
do meio do vetor e, enquanto o vetor não estiver sido totalmente "varrido", ou seja, enquanto os 
limites do vetor não se cruzarem, esses limites são atualizados de acordo com o valor que está
sendo buscado. Se o valor buscado é menor do que o valor atual, significa que o subvetor da esquerda
será utilizado, dessa forma, o indicador da direita ("fim do vetor") assume o valor do indicador da 
posição atual -1, ou seja, o vetor a ser considerado é limitado a esse valor. De forma semelhante 
ocorre quando o valor buscado é maior do que o valor atual, porém, nesse caso o limite à esquerda é
atualizado com o valor atual +1, ou seja, o subvetor à direita é considerado. Nesse problema, existe 
um detalhe a mais, pois se o valor buscado existe no vetor, a posição onde aparece pela primeira vez
deve ser retornada, ou seja, quando o valor é menor ou igual, o subvetor da esquerda é considerado e 
verifica-se ainda se o valor é igual e, em caso positivo, a posição é armazenada em uma variável 
("existe"). Dessa forma, caso o valor apareça, antes, os subvetores vão sendo divididos, até que a
variável armazene a menor posição na qual o valor aparece. Nesse caso, como os valores iniciais 
indicam o tamanho do vetor e o número de "queries" ou buscas que serão feitas, basta armazenar esses
valores para que um for seja feito em seguida para ler e armazenar os valores no vetor. Após isso, 
o outro for encarrega-se de ler o valor que será buscado no vetor e fazer a busca binária, retornando
a posição onde o valor se encontra no vetor ou -1 caso contrário. 

Tags: busca binária

*/

int buscaBinaria (int vetor[100001], int N, int valor){
	int esquerda = 0, direita = N-1, atual = 0, existe = -1;

	while (esquerda <= direita){
		atual = (esquerda + direita)/2;
		if (valor <= vetor[atual]){
			direita = atual - 1;
			if (valor == vetor[atual]){
				existe = atual;
			}
		}               
    else {
     	esquerda = atual + 1;
    }
	}
	return existe;
}

int main() {
  int i = 0, N = 0, Q = 0, valor = 0, existe = 0;
  int vetor[100001];
    
  fscanf(stdin, "%d %d", &N, &Q);
    
  for (i=0; i<N; i++){
   	fscanf(stdin, "%d", &vetor[i]);
  }

  for (i=0; i<Q; i++){
  	fscanf(stdin, "%d", &valor);
   	existe = buscaBinaria(vetor, N, valor);
   	printf("%d\n", existe);
  }
}