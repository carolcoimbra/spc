#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Divisão da Nlogônia (SPOJ_NLOGONIA)

O problema consiste em determinar a posição de determinados pontos em um plano. A entrada do 
problema contém vários casos de teste. A primeira linha de um caso de teste contém um inteiro
K indicando o número de consultas que serão realizadas. A segunda linha de um caso de teste 
contém dois números inteiros N e M representando as coordenadas do ponto divisor do plano. 
Cada uma das K linhas seguintes contém dois inteiros X e Y representando as coordenadas de uma
residência. Para cada coordenada (X, Y) lida, deve-se determinar a região na qual o ponto se 
encontra de forma que:
se X == N ou Y == M, significa que o ponto está na divisa;
se X > N ou Y > M, significa que o ponto está na região NE;
se X < N ou Y < M, significa que o ponto está na região SO;
se X > N ou Y < M, significa que o ponto está na região SE;
se X < N ou Y > M, significa que o ponto está na região NO;
Dessa forma, como os casos de teste se encerram quando N é igual a 0, basta ler e verificar se
o mesmo é diferentes de 0. Caso o caso de teste seja válido, a entrada descrita acima é lida. 
Após a leitura da entrada, basta calcular o resultado utilizando ifs sequenciais que verificam 
cada uma das condições apresentadas acima na ordem em que aparecem. O resultado é impresso na 
primeira condição satisfeita e os próximos casos de teste são processados.

Tags = coordenadas, pontos, retas, rosa dos ventos

*/

int main (){
   int N = 0, X = 0, Y = 0, x = 0, y = 0, i = 0;
   
   while (1){
      fscanf (stdin, "%d", &N);

      if (N == 0){
         break;
      }

      fscanf (stdin, "%d %d", &X, &Y);

      for (i=0; i<N; i++){

         fscanf (stdin, "%d %d", &x, &y);

         if (x == X || y == Y){
         	printf("divisa\n");
         }

         else if (x > X && y > Y){
         	printf("NE\n");
         }

         else if (x < X && y < Y){
         	printf("SO\n");
         }

         else if (x > X && y < Y){
         	printf("SE\n");
         }

         else if (x < X && y > Y){
         	printf("NO\n");
         }
      }
   }

   return 0;    
}