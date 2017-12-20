#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Romeo and Juliet (UVa_10210)

O problema consiste em determinar a maior distância entre as casas de Romeu e Julieta de forma
que satisfaça algumas condições descritas pela imagem do problema. A primeira linha de cada caso 
de teste contém seis valores ponto flutuantes, x1, y1, x2, y2, CMD e ENF, onde (x1, y1) 
representam as coordenadas do canhão A, (x2, y2) as coordenadas do canhão B, CMD é o ângulo 
formado entre as direções do canhão para M e ENF representa o mesmo para N. Para cada caso de 
teste, deve-se determinar a maior distância entre M e N. Sendo assim, para solucionar o problema, 
basta ler todos os valores descritos acima enquanto não houver fim de arquivo e, calcular o 
resultado para cada um dos casos de teste. O resultado de cada caso de teste será processado 
conforme descrito a seguir: A distância máxima entre M e N ocorre quando os pontos M, N e A estão 
alinhados. Sendo assim, assumindo que isso deve ocorrer temos que, a distância entre M e N pode 
ser dividida em dois segmentos, o primeiro que vai de N a A e o segundo que vai do ponto A à M. 
As distâncias desses segmentos serão, respectivamente, d1 e d2. Cada uma desses distâncias será 
vista como sendo o cateto adjacente dos triângulos formados por (NAB) e (MAB), ou seja, a distância 
total será a soma das distâncias dos catetos adjacentes desses triângulos. Devido ao fato do 
problema fornecer os ângulos formados por CMD e ENF e as coordenadas dos pontos A e B, cuja 
distância determina o cateto oposto dos triângulos, é possível encontrar o valor dos catetos 
adjacentes da seguinte forma: Sabendo que a fórmula da tangente é dada por: tg = co/ca, onde 
co é a medida do cateto oposto e ca é o cateto adjacente ao ângulo, temos que encontrar o valor 
do cateto adjacente, uma vez que o cateto adjacente à M é igual a distância de M ao ponto A e o 
cateto adjacente à N é a distância de N ao ponto A que, somados é igual à máxima distância entre 
as casas. Aplicando a fórmula da tangente para o encontrar a primeira distância, do segmento NA, 
temos que: tg = co/ca => tg ENF = d(AB) / d1 => d1 = d(AB) / tg ENF. Da mesma forma, aplicando 
para o segundo segmento, AM, temos que: tg = co/ca => tg CMD = d(AB) / d2 => d2 = d(AB) / tg CMD
Após isso, basta somar d1 e d2. Vale ressaltar que a função para calcular a tangente recebe um ângulo
expresso em radianos, dessa forma, vale lembrar que um radiano equivale a 180/pi graus. Sendo assim, 
após calcular a distância máximo, basta imprimí-la com 3 casas decimais.

Tags = trigonometria, tangente, distância euclidiana, 

*/

double distancia (double x1, double y1, double x2, double y2){
   double d = 0.0;
   d = sqrt((pow((double)x1-x2, 2.0)) + (pow((double)y1-y2, 2.0)));

   return d;
}

int main (){
   int N = 0, i = 0;
   double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, a1 = 0.0, a2 = 0.0;
   double pi = 3.1415926535897932384;
   double F = 0.0, d1 = 0.0, d2 = 0.0, r1 = 0.0, r2 = 0.0, ab = 0.0;
   int raios[110];
   
   while (fscanf (stdin, "%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &a1, &a2) != EOF){

      r1 = tan (a1 * pi / 180.00);
      r2 = tan (a2 * pi / 180.00);

      ab = distancia (x1, y1, x2, y2);
      d1 = ab / r1;
      d2 = ab / r2;
      F = d1 + d2;

      printf("%.3lf\n", F);
   }

   return 0;    
}