#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Meteoros (SPOJ_METEORO)

O problema consiste em determinar a quantidade de meteoros que caíram dentro de uma fazenda 
delimitada por um retângulo. A primeira linha de cada caso de teste contém quatro inteiros
X1, Y1, X2, Y2 que indicam as coordenadas x e y do ponto superior esquerdo e inferior direito
do retângulo da fazenda. A segunda linha contém a quantidade de meteoros que caíram, N. Cada 
uma das N linhas seguintes contém dois inteiros x e y representando as coordenadas de onde
caiu cada um dos meteoros. Para cada coordenada (x, y) lida, deve-se determinar se a mesma 
está dentro do retângulo para que, em caso afirmativo, o número de meteoros que caíram dentro
da propriedade seja incrementado. Para isso, basta fazer a seguinte verificação:
x >= X1 && x <= X2 && y <= Y1 && y >= Y2
ou seja, a coordenada de cada meteoro deve estar dentro dos limites do retângulo, ou seja, 
a coordenada x deve estar entre a coordenada x da esquerda do retângulo (X1) e a coordenada
x da direita (X2), assim como a coordenada y deve estar entre as coordenadas y do retângulo
(Y1 e Y2). Dessa forma, como os casos de teste se encerram quando as coordenadas do retângulo 
são iguais a 0, basta ler e verificar se as mesmas são diferentes de 0. Caso o caso de teste 
seja válido, a entrada descrita acima é lida. Após a leitura da entrada, basta incrementar a
quantidade de meteoros que caíram dentro da fazenda utilizando a condição descrita acima. Após
isso, basta imprimir a quantidade contabilizada. Vale ressaltar que antes de cada resultado é
necessário imprimir o número do caso de teste que foi processado. Para isso, basta criar uma 
variável que é incrementada a cada caso de teste processado e imprimí-la antes de cada resultado.

Tags = coordenadas, pontos, retas

*/

int main (){
   int N = 0, X1 = 0, Y1 = 0, X2 = 0, Y2 = 0, x = 0, y = 0, i = 0, count = 0, t = 0;
   
   while (1){
      t++;
      count = 0;
      fscanf (stdin, "%d %d %d %d", &X1, &Y1, &X2, &Y2);

      if (X1 == 0 && X2 == 0 && Y1 == 0 && Y2 == 0){
         break;
      }

      fscanf (stdin, "%d", &N);

      for (i=0; i<N; i++){

         fscanf (stdin, "%d %d", &x, &y);

         if (x >= X1 && x <= X2 && y <= Y1 && y >= Y2){
         	count ++;
         }
      }

      printf("Teste %d\n", t);
      printf("%d\n", count);
   }

   return 0;    
}