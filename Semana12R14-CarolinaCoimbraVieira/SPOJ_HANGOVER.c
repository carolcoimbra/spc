#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Hangover (SPOJ_HANGOVER)

O problema consiste em determinar a quantidade de cartões que devem ser empilhados conforme
mostrado na imagem do problema para que se tenha um comprimento de pelo menos o valor N dado.
A primeira linha de cada caso de teste contém um valor ponto flutuante N que indica o tamanho
da sequência de cartões empilhados que se desja obter. Para cada valor N, deve-se determinar
a quantidade de cartões que são necessários para se obter, pelo menos, um comprimento igual
a N. O problema fornece uma sequência que deve ser utilizada nesse cálculo. Essa sequência
calcula o comprimento das cartas empilhadas da seguinte forma: 1/2 + 1/3 + 1/4 +...+ 1/(n+1)
para n cartas empilhadas. Sendo assim, basta criar um vetor onde em cada posição o valor
para a quantidade de cartas determinada pelo índice do vetor é pré-computada. Sendo assim,
o vetor possui 0 na posição 0, 1/2 na posição 1, 1/2 + 1/3 na posição 2 e assim sucessivamente.
Dado que o vetor já está pré-computado, basta imprimir o índice do vetor onde o valor armazenado
é igual ou maior que o valor de N dado. Dessa forma, como os casos de teste se encerram quando
o valor de N é igual a 0, basta ler e verificar se o mesmo é diferente de 0. Caso o caso de teste
seja válido, a entrada descrita acima é lida. Após a leitura da entrada, basta fazer um for para
percorrer todo o vetor pré-computado e imprimir o inteiro que representa o índice da primeira
posição do vetor na qual o valor contido é maior ou igual ao valor N.

Tags = sequência, vetor, comparação de valores

*/

int main (){
   int i = 0, resposta = 0;
   double N = 0.0;
   double sequencia[300];

   sequencia[0] = 0.00;
   for (i=1; i<300; i++){
      sequencia[i] = sequencia[i-1] + 1.00/(double)(i+1);
   }
   
   while (1){
      fscanf (stdin, "%lf", &N);

      if (N == 0.00){
         break;
      }

      for (i=1; i<300; i++){
         if (N <= sequencia[i]){
            resposta = i;
            break;
         }
      }

      printf("%d card(s)\n", resposta);
   }

   return 0;    
}