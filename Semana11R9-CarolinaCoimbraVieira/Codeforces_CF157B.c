#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Trace (Codeforces_CF157B)

O problema consiste em determinar a área total de uma parede que possui círculos circunscritos
que está pintada com a cor vermelha. A primeira linha de cada caso de teste contém um inteiro
N indica a quantidade de círculos circunscritos que existem. A segunda linha contém a N inteiros
que representam o raio de cada um dos N círculos. Para cada caso de teste, deve-se determinar a
área total de círculos vermelhos, sabendo que os círculos são pintados de forma alternada nas 
cores vermelho e azul. E, como a área externa aos círculos é pintada de azul, o círculo mais
externo deverá ser da cor vermelha. Sendo assim, para solucionar o problema, basta ler e 
armazenar em um vetor os valores dos raios dos círculos, após isso, é necessário ordená-los 
para encontrar a sequência de de cores corretas, uma vez que o cículo de maior raio deverá ser 
pintado de vermelho. Após ordenado, basta percorrer o vetor de trás para frente e pulando de
duas em duas posições, isso porque, a área do círculo vermelho será sempre sua área subtraída
da área do círculo seguinte, que por sua vez, será pintado de azul. Sendo assim, a cada posição,
a área será igual à área considerando o raio da posição atual menos a área considerando o raio 
da posição anterior. Para o caso do tamanho do vetor ser ímpar e a área do menor círculo ser 
considerada, uma posição adicional foi criada com o valor do raio igual a zero, para que o 
caso onde toda a área do menor círculo é pintada de vermelho seja contemplada, uma vez que a 
área do mesmo será igual a (1^2 - 0^2) * pi, que nada mais é do que 1^2 * pi.
Dessa forma, como os casos de teste são individuais, basta ler o valor de N e criar um vetor com
N+1 posições, preenchendo a posição 0 com o valor 0 e, da posição 1 até a N fazer um for para
ler os N valores dos raios e incluí-los ao vetor. Após a leitura da entrada, basta ordenar o vetor
de forma que os raios fiquem em ordem crescente. Após isso, basta percorrer o vetor conforme 
descrito acima, incrementando a área para que, ao final, a mesma seja impressa. Uma informação
importante é que, a área só foi calculada, de fato, no final do programa quando o valor encontrado
foi multiplicado pelo valor de pi.

Tags = área do círculo, círculos circunscritos, raio, pi

*/

int compara (const void *a, const void *b){
   return (*(int*)a - *(int*)b);
}

int main (){
   int N = 0, i = 0;
   double pi = 3.1415926535897932384;
   double area = 0.0;
   int raios[110];
   
   fscanf (stdin, "%d", &N);

   raios[0] = 0;
   for (i=1; i<=N; i++){
      fscanf (stdin, "%d", &raios[i]);      
   }

   qsort (raios, N+1, sizeof(int), compara);

   for (i=N; i>0; i-=2){
      area += (raios[i]*raios[i] - raios[i-1]*raios[i-1]);
   }

   printf("%.10lf\n", area*pi);

   return 0;    
}