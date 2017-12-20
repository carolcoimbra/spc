#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Bits Trocados (SPOJ_BIT)

O problema consiste em, dado o valor de Bits desejado pelo cliente, determinar o número de 
cada uma das notas necessário para totalizar esse valor, de modo a minimizar a quantidade de 
cédulas entregues. O problema consiste de vários casos de teste, cada conjunto de teste é 
composto por uma única linha, que contém um número inteiro positivo V, que indica o valor 
solicitado pelo cliente. O final da entrada é indicado por V = 0, dessa forma, enquanto V
for diferente de 0, um caso de teste é processado. Antes mesmo de se ler o valor desejado 
pelo cliente, um vetor é construído de forma que, em cada posição seja armazenado um valor
de uma das notas existentes, nesse caso, apenas 50, 10, 5 e 1. O valor V é lido e, para 
cada valor de nota, iniciando pelas maiores, a quantidade de notas daquela quantia será
igual ao resultado da divisão de V por aquele valor, e, após isso, V é atualizado para o
resultado da divisão de V por esse mesmo valor. Isso faz com que a maior quantidade de 
notas maiores seja dada primeiro, e o que sobrar será distribuído pelas demais notas de
acordo com sua ordem decrescente de valor. Dessa forma, a cada interação, a quantidade de
notas de daterminado valor é armazenada em um outro vetor que será impresso ao final, 
contendo todas as quantidades de notas entregues de acordo com a ordem decrescente do valor
das notas, ou seja, o resultado 1 2 0 2 indica que foram entregues 1 nota de 50, 2 de 10, 
0 de 5 e 2 de 1. Além disso, para cada caso de teste deve ser impresso o número do teste
correspondente antes do resultado. Para isso, basta criar uma variável que é incrementada 
a cada caso de teste e imprimí-la antes de percorrer e imprimir o vetor com o resultado.
Por fim, após cada caso de teste, uma linha em branco adicional é impressa.

Tags: algoritmo guloso, vetor, divisão, módulo

*/
     
int main (){
 	int V = 0, i = 0, teste = 0;
   	int vetor[4] = {50, 10, 5, 1};
   	int resultado[4];
   	
   	fscanf (stdin, "%d", &V);
   	while (V != 0){
   		teste++;
   		for (i=0; i<4; i++){
   			resultado[i] = V/vetor[i];
   			V = V%vetor[i];
   		}
     
   		printf("Teste %d\n", teste);
   		for (i=0; i<4; i++){
   			printf("%d ", resultado[i]);
   		}
   		printf("\n");
   		fscanf (stdin, "%d", &V);
   	}
   	return 0;
} 