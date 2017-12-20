#include <stdio.h>
#include <string.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Candy I (SPOJ_CANDY)

O problema consiste em determinar a quantidade de doces que devem ser movidos de um pacote para 
outro para que todos tenham a mesma quantidade. Ou seja, se existem dois pacotes, um com 1 doce 
e outro com 3 doces, basta mover 1 doce do segundo pacote para o primeiro para que os dois fiquem
com 2 doces. Porém, se o segundo pacote tivesse apenas 2 doces, seria impossível ter dois pacotes
com a mesma quantidade porque a soma dos doces nos dois pacotes não é divisível pelo número de 
pacotes ((1+2=3) não é dividível por 2). Sendo assim, a solução do problema envolve armazenar a 
quantidade de doces que cada pacote possui em um vetor e, a cada nova quantidade lida, somar à 
variável responsável por armazenar a soma de todos os doces. Após isso, basta verificar se a soma
calculada é divisível pelo número de pacotes, N, fornecido como entrada. Caso não seja, basta imprimir
-1, já que não é possível dividir os doces igualmente nos pacotes. Caso seja divisível, basta percorrer
o vetor e incrementar a variavél movimentos com a quantidade que o pacote possui a mais. Ou seja, a 
quantidade que cada pacote deve ter é dada pela divisão da soma pelo número de pacotes, sendo assim, 
todos os pacotes que possuem uma quantidade maior do que essa, devem tirar o excedente e é esse valor
que será incrementado à variável movimentos (quantidade do pacote - quantidade media dos pacotes).
Nesse caso, como o fim da entrada é marcado pelo valor de N, quantidade de pacotes de doces igual a -1, 
basta ler esse valor N e, quando o mesmo for igual a -1, o programa é finalizado. Mas, enquanto for 
diferentes de -1, as N linhas com as quantidade de doces em cada pacote são lidas em um for que armazena
essas quantidades em um vetor e atualiza o valor da soma dos doces. E, por fim, outro for percorre o vetor 
somando todas as quantidades de doces excedentes nos pacotes caso a soma seja dividível pelo número de 
pacotes e o resultado é impresso. Mas, caso o valor não seja divisível, basta fazer essa verificação e 
imprimir -1.

Tags: vetor, comparação de valores, atualização de valor

*/

int main() {
    int i = 0, n = 0, N = 0, soma = 0, q = 0, movimentos = 0;

    while (1){
    	fscanf(stdin, "%d", &N);
    	if (N == -1){
    		break;
    	}

        int quantidades[N];
        soma = 0;
        movimentos = 0;
        for (n=0; n<N; n++){
            fscanf(stdin, "%d", &quantidades[n]);
            soma += quantidades[n];
        }

        if (soma%N != 0){
            printf("-1\n");
        }
        else {
            q = soma/N;
            for (i=0; i<N; i++){
                if (quantidades[i] > q){
                    movimentos += (quantidades[i] - q);
                }
            }
            printf("%d\n", movimentos);
        }
    }
    return 0;
}
