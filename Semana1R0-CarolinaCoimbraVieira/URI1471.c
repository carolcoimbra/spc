#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Dangerous Dive/Mergulho (URI1471)

O problema consiste em ler dois valores inteiros que indicam o número de voluntários 
que mergulharam e o número de voluntários que retornaram, seguido dos indicadores dos
voluntários que retornaram. Para esse problema, um vetor cuja posição representa o id 
dos voluntários que mergulharam é construído, inicialmente com valores iguais a 0. Na 
medida em que os identificadores dos mergulhadores que voltaram é lido, essa posição do  
vetor recebe o valor 1, para que, ao final, sejam impressos somente os ids cuja posição
no vetor é igual a 0, indicando que o mergulhador não voltou. Para facilitar, a posição 0
do vetor foi desconsiderada, uma vez que os ids iniciam do valor 1, dessa forma, a impressão
dos ids cuja posição está preenchida com 0 inicia da posição 1. Nesse caso, como o fim da 
entrada é marcado pelo fim do arquivo "EOF", basta ler os valores enquanto não for o fim do 
arquivo, salvar a quantidade de mergulhadores que mergulharam e a quantidade que retornou. 
Dessa forma, em um primeiro for, o vetor é construído com o número de posições igual ao número 
de mergulhadores que mergulhou +1 (pois a posição 0 é descartada) e um segundo for é usado para 
ler os ids dos mergulhadores que voltaram e preencher a posição do vetor com 1. Após isso, basta 
verificar se o número de mergulhadores que mergulharam é o mesmo da quantidade que retornou, 
caso isso ocorra, basta imprimir "*". Caso contrário, um outro for é necessário para imprimir 
todas as posições que, a partir do id 1 estão preenchidas com 0.

Tags: vetor, vetor binário

*/

void main() {
    int i = 0, valor1 = 0, valor2 = 0, id = 0;

    while (fscanf(stdin, "%d %d", &valor1, &valor2) != EOF){
        int vetor[valor1+1];
        for (i=0; i<=valor1; i++){
            vetor[i] = 0;
        }
        for (i=0; i<valor2; i++){
            fscanf(stdin, "%d", &id);
            vetor[id] = 1;
        }
        
        if (valor1 == valor2){
            printf("*");
        }
        else{
            for (i=1; i<=valor1; i++){
                if (vetor[i] == 0){
                    printf("%d ", i);
                }
            }
        }
        printf("\n");
    }
}