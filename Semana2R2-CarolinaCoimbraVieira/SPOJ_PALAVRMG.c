#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Palavras Ordenadas (SPOJ_PALAVRMG)

O problema consiste em ler strings (palavras) e determinar se as mesmas possuem seus 
caracteres ordenados ou não. Por exemplo: "abcdz" é ordenada enquanto "aab" não.
Para solucionar o problema, após a leitura da string, um for percorre a mesma e tranforma
todos os caracteres em letra minúscula para facilitar a comparação entre eles. Para isso, 
a função tolower da biblioteca ctype.h é utilizada. Após isso, cada caractere da palavra 
é comparado com o caractere seguinte e, caso o valor do caractere seja maior ou igual ao
valor do próximo, significa que a palavra não está ordenada, sendo assim, uma "flag" é 
setada como sendo igual a zero (ordenada = 0). Por fim, ao final, caso a "flag" seja 
igual a 0, imprime-se "N" e, caso seja 1, imprime-se "O", indicando que a palavra possui 
seus caracteres ordenados. Além disso, devido ao fato da primeira linha da entrada indicar 
o número de casos de teste (P), basta fazer um for para que esse processo seja repetido esse
número de vezes.

Tags: comparação de caracteres, string, tolower()

*/

int palavraOrdenada (char entrada[45]){
    int i = 0, j = 0, ordenada = 1;
    int palavra[45];
    
    for (i=0; i<strlen(entrada)-1; i++){
        j = i+1;
        palavra[i] = tolower(entrada[i]);
        palavra[j] = tolower(entrada[j]);
        if(palavra[i] >= palavra[j]){
            ordenada = 0;
        }
    }
    return ordenada;
}

int main() {
    int p = 0, P = 0, ordenada = 0;
    char entrada[45];

    fscanf(stdin, "%d", &P);
    for (p=0; p<P; p++){
        ordenada = 1;
        fscanf(stdin, "%s", entrada);
    
        ordenada = palavraOrdenada(entrada);
        if (ordenada == 0){
            printf("%s: N\n", entrada);
        }
        else {
            printf("%s: O\n", entrada);
        }
    }
    return 0;
}