#include <stdio.h>
#include <math.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Elevador (SPOJ_ELEVADOR)

O problema consiste em determinar se dado o tamanho do elevador (um retângulo) e o raio de dois
círculos, os mesmo cabem dentro do elevador. A primeira linha de cada caso de teste contém quatro
números inteiros L, C, R1 e R2, indicando respectivamente a largura do elevador, o comprimento
do elevador, e os raios dos cilindros. Para cada valor caso de teste, deve-se determinar se os
círculos cabem ou não dentro do elevador. A solução do problema envolve comparar a distância entre
os centros dos círculos quando os mesmos estão o mais juntos possível e o mais separado possível
dentro do elevador. Ou seja, quando os círculos estão o mais junto possível, sem interseção, a
distância entre os centros é igual a R1+R2, onde R1 e R2 representam os raios dos círculos 1 e 2,
respectivamente. Já quando os círculos estão o mais distante possível dentro do elevador, ou seja,
um círculo está em uma extremidade da diagonal e o outro está em outra, temos que essa distância
entre os centros chamada de R' deve ser maior ou igual à R1+R2. Isso porque, caso R' seja menor do
que R1+R2, significa que os círculos não cabem no elevador sem interseção. Para simplificar, um
caso trivial de se pensar é que, caso o diâmetro do maior círculo seja maior do que o menor lado
do elevador, significa que a resposta já é imediata, "N". Porém, caso essa condição não seja
satisfeita, verifica-se se a distância R' é menor do que R1+R2, o que também tem como resultado "N".
E, por fim, caso essa distância seja maior, é porque os círculos cabem no elevador, "S". Vale
ressaltar que tais comparações envolvendo distância forem realizadas sem tirar a raiz quadrada,
dessa forma, o valor de R' é comparado com (R1+R2)^2. Dessa forma, como os casos de teste se
encerram quando os valores de L, C, R1 e R2 são iguais a 0, basta ler e verificar se os mesmos são
diferentes de 0. Caso o caso de teste seja válido, a entrada descrita acima é lida. Após a leitura
da entrada, basta realizar as operações descritas anteriormente e imprimir "S" caso tenha espaço
para os círculos e "N" caso contrário.

Tags = geometria, distância euclidiana, raio

*/

int distancia (int x1, int y1, int x2, int y2){
   int d = 0;
   d = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));

   return d;
}

int maximo (int a, int b){
   if (a > b){
      return a;
   }
   
   return b;
}

int minimo (int a, int b){
   if (a < b){
      return a;
   }

   return b;
}

int main (){
   int L = 0, C = 0, R1 = 0, R2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0;

   while (1){
      fscanf (stdin, "%d %d %d %d", &L, &C, &R1, &R2);

      if (L == 0 && C == 0 && R1 == 0 && R2 == 0){
         break;
      }
     
      x1 = R1;
      y1 = R1;
      x2 = L-R2;
      y2 = C-R2;

      if (x2 >= R2 && y2 >= R2 && 2*maximo(R1,R2) <= minimo(C,L)){

         if (distancia(x1, y1, x2, y2) < ((R1+R2)*(R1+R2))){
            printf("N\n");
         }

         else {
            printf("S\n");
         }
      }

      else {
         printf("N\n");
      }
   }

   return 0;    
}