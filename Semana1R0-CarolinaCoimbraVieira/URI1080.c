#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Maior e Posição (URI1080)

O problema consiste em ler 100 números inteiros e determinar o maior valor lido
dentre eles, bem como sua posição na sequência lida. Para resolvê-lo, basta verificar,
a cada novo valor lido se o mesmo é maior do que o maior valor até então encontrado. 
O maior valor encontrado inicia com 0 e é atualizado sempre que um valor maior é lido.
Quando o maior valor é atualizado, atualiza-se também a posição desse valor na entrada
lida. A estratégia utilizada é comparar (usando um if) o valor lido com o valor máximo 
no momento da leitura (usando um for). Nesse caso, como o número de valores a serem 
lidos foi especificado (100 valores), basta fazer um for para ler os 100 valores da 
entrada.

Tags: comparação de valores, atualização do maior valor

*/
 
void main() {
	int i = 0, max = 0, maxId = 0, valor = 0;
	for (i=1; i<=100; i++){
		fscanf(stdin, "%d", &valor);
		if (valor > max){
			max = valor;
			maxId = i;
		}
	}

    printf("%d\n", max);
    printf("%d\n", maxId);
}