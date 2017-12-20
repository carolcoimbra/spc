#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERRO 1e-9

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Points in Figures: Rectangles, Circles, Triangles (UVa_478)

O problema consiste em determinar em quais figuras um determinado ponto está. A primeiras
N linhas de cada caso de teste contém um a caractere indicando o tipo da figura seguido
dos valores necessários em cada um desses casos, ou seja:
Para um retângulo, 'r', seguem quatro valores reais representando as coordenadas x e y do
ponto mais a esquerda acima e do ponto mais a direita abaixo.
Para um círculo, 'c', seguem três valores reais representando a coordenada x e y do ponto
central e o raio do mesmo.
Para um triângulo, 't', seguem seis valores reais representando as coordenadas x e y dos
três pontos extremos do mesmo.
O final da leitura das figuras é marcado por um asterisco, sendo assim, enquanto o mesmo
não é lido, todas as figuras são lidas e armazenadas em um vetor de figuras. Após isso,
vários pontos são lidos para que sejam verificados se estão em alguma figura. Ou seja,
segue uma lista de coordenadas x e y dos pontos de forma que, a entrada só termina quando
ambos os valores são iguais a 9999.9. Sendo assim, a cada coordenada lida, deve-se percorrer
o vetor onde estão armazenadas as informações osbre as figuras para saber se o ponto pertence
a alguma delas ou não. A função verificaDentro é responsável por verificar se o ponto está
dentro de alguma figura dado sua coordenada. Dessa forma, para cada figura, essa checagem é
feita de forma diferente. Sendo elas:
Retângulo: basta comparar os valores x e y do ponto com o maior e o menor valor que eles
podem assumir para que eles pertençam ao retângulo.
Círculo: basta calcular a distancia euclidiana do ponto ao centro e comparar esse valor com
o raio, ou seja, se for menor que o raio, significa que está dentro do círculo.
Triângulo: basta calcular a área dos três triangulos que o ponto forma com os pontos P1, P2 e P3
do triangulo principal e comparar se a soma delas é a mesma que a do tringulo principal.
Dessa forma, dado um ponto, é verificado se o mesmo está dentro de cada uma das figuras, em
caso afirmativo, um flag é setada em 1 e o número do ponto e da figura são impressos. Mas, caso
o ponto esteja fora de todas as figuras, ou seja, a flag está setada em 0, basta imprimir:
"Point p is not contained in any figure", onde p é o número correpondente à ordem na qual o
ponto foi lido do arquivo de entrada.

Tags = geometria, ponto, figuras geométricas, área de triângulos, raio

*/

typedef struct {
    char f;
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    double r;
} figura;

int igual (double a, double b){
    if (fabs(a-b) < ERRO){
        return 1;
    }

    return 0;
}

double distancia (double x1, double y1, double x2, double y2){
   double d = 0.0;
   d = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));

   return d;
}

double area (double x1, double y1, double x2, double y2, double x3, double y3){
    double a = 0.0;
    a = fabs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);

    return a;
}

int noRetangulo (figura f, double x, double y){
    if (x > f.x1 && x < f.x2 && y < f.y1 && y > f.y2){
        return 1;
    }

    return 0;
}

int noCirculo (figura f, double x, double y){
    if (distancia(f.x1, f.y1, x, y) < (f.r*f.r)){
        return 1;
    }

    return 0;
}

int noTriangulo (figura f, double x, double y){
    double A1 = 0.0, A2 = 0.0, A3 = 0.0, A = 0.0;

    A = area (f.x1, f.y1, f.x2, f.y2, f.x3, f.y3);
    A1 = area (x, y, f.x2, f.y2, f.x3, f.y3);
    A2 = area (f.x1, f.y1, x, y, f.x3, f.y3);
    A3 = area (f.x1, f.y1, f.x2, f.y2, x, y);
    
    if (igual(A1+A2+A3, A) == 1 && igual(A1, 0.0) == 0 && igual(A2, 0.0) == 0 && igual (A3, 0.0) == 0){
        return 1;
    }

    return 0;
}

int verificaDentro (figura *vetor, int i, double x, double y){
    if (vetor[i].f == 'r'){
        if (noRetangulo(vetor[i], x, y)){
            return 1;
        }
    }
    else if (vetor[i].f == 'c'){
        if (noCirculo(vetor[i], x, y)){
            return 1;
        }

    }
    else if (vetor[i].f == 't'){
        if (noTriangulo(vetor[i], x, y)){
            return 1;
        }
    }

    return 0;
}

int main (){
       int i = 0, ponto = 0, c = 0, count = 0, N = 0;
       double x = 0.0, y = 0.0;
       char tipo;
       figura vetor[10];

       N = 0;
       while (1){
        fscanf (stdin, "%c", &tipo);

        if (tipo == '*'){
            break;
        }
        vetor[i].f = tipo;

        if (tipo == 'r'){
            fscanf(stdin, "%lf %lf %lf %lf", &vetor[i].x1, &vetor[i].y1, &vetor[i].x2, &vetor[i].y2);
        }

        else if (tipo == 'c'){
            fscanf(stdin, "%lf %lf %lf", &vetor[i].x1, &vetor[i].y1, &vetor[i].r);
        }

        else if (tipo == 't'){
            fscanf(stdin, "%lf %lf %lf %lf %lf %lf", &vetor[i].x1, &vetor[i].y1, &vetor[i].x2, &vetor[i].y2, &vetor[i].x3, &vetor[i].y3);
        }

        N++;
        i++;
        fscanf (stdin, "%c", &tipo);
    }

    ponto = 1;
    while (1){
        fscanf(stdin, "%lf %lf", &x, &y);

        if (igual(x, 9999.9) == 1 && igual(y, 9999.9) == 1){
            break;
        }

        count = 0;
        for (i=0; i<N; i++){
            c = verificaDentro (vetor, i, x, y);
            
            if (c == 1){
                printf("Point %d is contained in figure %d\n", ponto, i+1);
            }
            count += c;
        }

        if (count == 0){
            printf("Point %d is not contained in any figure\n", ponto);
        }

        ponto ++;
    }

    return 0;
}