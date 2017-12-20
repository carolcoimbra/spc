#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Soma de fatoriais (URI1161)

O problema consiste em ler dois valores inteiros e calcular a soma do fatorial
de ambos. Para esse problema, devido os valores serem no máximo 20, foi construído
um vetor com o cálculo do fatorial dos 21 primeiros números inteiros (incluindo o 0). 
Dessa forma, a cada leitura de pares de valores, basta somar os valores dessas posições 
do vetor, facilitando assim o cálculo do resultado. Ou seja, o vetor com os valores do
fatorial é calculado antes mesmo da primeira leitura ser feita. Nesse caso, como o fim da 
entrada é marcado pelo fim do arquivo "EOF", basta ler os valores enquanto não for o fim 
do arquivo, somar os valores do vetor nas respectivas posições e retornar a soma dos mesmos.

Tags: fatorial, vetor, vetor de fatorial

*/

void main() {
    int i = 0;
    long long int valor1 = 0, valor2 = 0, f1 = 0, f2 = 0;
    long long vetorFatorial[21];

    vetorFatorial[0] = 1;
    for (i=1; i<=20; i++){
        vetorFatorial[i] = vetorFatorial[i-1] * i;
    }

    while (fscanf(stdin, "%lld %lld", &valor1, &valor2) != EOF){
        f1 = vetorFatorial[valor1];
        f2 = vetorFatorial[valor2];
        printf("%lld\n", f1+f2);
    }
}