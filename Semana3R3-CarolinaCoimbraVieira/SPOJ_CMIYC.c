#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Catch Me If You Can (SPOJ_CMIYC)

O problema consiste em determinar a distância do ponto inicial ao ponto de encontro de dois 
colegas que saem do mesmo ponto, mas correm para direções opostas e com velocidades diferentes.
A área da brincadeira pode ser entendida como um retângulo dividido em sub áreas. Por exemplo, 
supondo que a área da brincadeira é um retângulo com 2 subáreas, os amigos saem da subárea 1, 
um deles dá um passo e vai para a subárea 2, enquanto o outro vai para a direção oposta, passa
pela subárea 2 e em seguida vai para a 1 (o segundo amigo anda 2x mais que o primeiro). Após
inúmeros testes, fazendo simulações no papel com vários tamanhos para o retângulo, observou-se 
que, quando o tamanho do retângulo não é divisível por 3, os amigos chegam juntos no mesmo ponto
de onde saíram (1), dessa forma, a distância do ponto inicial para esse ponto de encontro é 0.
Porém, quando o tamanho do retângulo é divisível por 3, a distância é igual ao tamanho do retângulo
dividido por 3. Nesse problema, cada caso de teste consiste de um valor que determina a quantidade de
"jogos", T, que devem ser calculados, dessa forma, basta ler esse valor e fazer um for para ler os T
valor inteiros referentes ao tamanho do retângulo do "jogo" e imprimir o resultado que será igual a
zero se o tamanho do retângulo não for divisível por 3 e tamanho do retângulo dividido por 3 caso
contrário.

Tags: encontrar um padrão, divisão, mod

*/

int main() {
    int i = 0, T = 0;
    long int N = 0;

    fscanf(stdin, "%d", &T);

    for (i=0; i<T; i++){
        fscanf(stdin, "%ld", &N);
        if(N%3 == 0){
            printf("%ld\n", N/3);
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
