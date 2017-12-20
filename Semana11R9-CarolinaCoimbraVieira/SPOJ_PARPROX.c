#include <stdio.h>
#include <math.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Pontos (SPOJ_PARPROX)

O problema consiste em determinar a menor distância entre dois pontos dado um conjunto de N
pontos. As entradas para o problema são individuais, dessa forma, cada entrada consiste de 
um único caso de teste. A primeira linha contém um número inteiro positivo N, que indica o 
número de pontos a serem considerados. As N linhas seguintes contêm dois números inteiros cada, 
representando as coordenadas X e Y de cada ponto. A solução para o problema consiste em ler e 
armazenar as coordenadas de todos os pontos fornecidos em um vetor. Após isso, basta percorrer
todo o vetor e calculando a distância euclidiana entre todos os pares de pontos no mesmo de 
forma que, a menor distância sempre seja atualizada. No final, basta imprimir a menor distância 
encontrada.

Tags = vetor, struct, distância euclidiana

*/

typedef struct {
   int x;
   int y;
} par;

double distancia (int x1, int y1, int x2, int y2){
   double d = 0.0;
   d = sqrt((pow((double)x1-x2, 2.0)) + (pow((double)y1-y2, 2.0)));

   return d;
}

int main (){
   int N = 0, x = 0, y = 0, i = 0, j = 0;
   double d = 0, minimo = 10000000.0;
   par pares[1000];

   fscanf (stdin, "%d", &N);

   for (i=0; i<N; i++){
      fscanf (stdin, "%d %d", &x, &y);
      pares[i].x = x;
      pares[i].y = y;
   }

   for (i=0; i<N; i++){
      for (j=i+1; j<N; j++){
         d = distancia(pares[i].x, pares[i].y, pares[j].x, pares[j].y);
         if (d < minimo){
            minimo = d;
         }
      }
   }

   printf("%.3lf\n", minimo);

   return 0;
}
     