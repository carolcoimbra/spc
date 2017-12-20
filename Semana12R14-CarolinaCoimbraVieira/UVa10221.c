#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Satellites (UVa_10221)

O problema consiste em determinar o tamanho da distância e da corda, dado a distância do
satélite à superfície terrestre e o ângulo feito entre os mesmos. A primeira linha de cada
caso de teste contém dois valores, S e A, e uma string, representando respectivamente, a
distância entre o satélite e a superfície terrestre, o ângulo formado e o tipo do ângulo
formado, minutos ou graus. Para cada caso de teste, o valor da distância e da corda devem
ser calculados. Para isso, basta assumirmos que:
O raio total do centro da Terra até o satélite será: R = s + 6440km (dado no enunciado);
O ângulo A em radianos será igual a:
   A = a* π/180 se a foi dado em graus
   A = (a * π/180)/60 se foi dado em minutos
Além disso, para garantir que A será menor do que pi, basta pegar o menor valor de A ou 2π-A.
Após calcular todos esses dados, basta substituir nas respectivas fórmulas para encontrar
o arco e a corda e imprimí-los.
Arco = A*R
Corda = 2*R*sin(A/2). Uma vez que o valor da mesma é correspondente a duas vezes a base do
triângulo retângulo formado pela divisão ao meio do triângulo isósceles de "lados" iguais a R.
Dessa forma, o cateto oposto ao ângulo A/2 corresponde ao tamanho da corda/2. Ou seja,
corda/2 = R*sin(A/2), sendo assim, corda = 2*R*sin(A/2).
Dessa forma, como os casos de teste se encerram com o fim do arquivo, basta ler os casos de
teste enquanto não ocorrer o fim do arquivo, computando os valores conforme descrito acima.

Tags = geometria, raio, pi, seno

*/

double minimo (double a, double b){
    if (a < b){
        return a;
    }

    return b;
}

int main (){
       double s = 0.0, a = 0.0, R = 0.0, A = 0.0, pi=3.14159265358979323846, arco = 0.0, corda = 0.0;
       char tipo[10];

       while (fscanf(stdin, "%lf %lf %s", &s, &a, tipo) != EOF){

           R = s + 6440.00;

           if (strcmp(tipo, "deg") == 0){
               A = a*(pi/180.00);
           }

           else{
               A = a*(pi/180.00)/60.00;
           }        

           A = minimo (A, 2*pi-A);
           arco = A*R;
           corda = 2.00*R*(sin(A/2.00));
           printf("%.6lf %.6lf\n", arco, corda);
       }

    return 0;
}