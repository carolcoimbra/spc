#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Intersection (SPOJ_LINESEG)

O problema consiste em determinar se dado quatro pontos que formam respectivamente dois
segmentos se cruzam e, caso isso seja verdadeiro, determinar se a interseção é um ponto ou
outro segmento. A primeira linha de cada caso de teste contém um valor T que indica a quantidade
de casos de teste que deverão ser processados dessa forma, basta fazer um for para ler cada um
dos T casos de teste que seguem. Cada teste consiste de duas linhas, cada uma contendo quatro
inteiros que representam as coordenadas x e y do primeiro e do segundo ponto do segmento (não
necessariamente na ordem). Após ler as entradas basta fazer uma sequência de ifs e else para
determinar se os segmentos se interceptam ou não. Para facilitar, os casos foram tratados
separadamente de forma que foram criadas quatro funções para as quatro possíveis configurações
dos segmentos, ou seja: horizontal-horizontal, vertical-horizontal, horizintal-vertical e
vertical-vertical. As funções hv e vh possuem somente dois resultados possiveis, ou seja, ou
as mesmas se interceptam (em um ponto) ou não. Dessa forma basta verificar se as coordenadas
de um estão entre os limites das coordenadas da outra e, caso isso ocorra significa que elas
se interceptam e, caso contrário, não. Para os casos hh e vv é um pouco mais trabalhoso, uma
vez que deve-se verificar primeiro se um dos dois segmentos é um ponto e se esse ponto está
no outro segmento ou se os segmentos se interceptam nas suas extremidades. Caso uma dessas duas
condições sejam verdadeiras, significa que a interseção se dá em um ponto. Além disso, uma
verificação determina se há formação de outro segmento para isso verifica-se se a coordenada
variável dos segmentos está entre os limite das coordenadas variáveis do outro. E, por fim,
caso o teste não se enquadre em nenhuma dessas condições, significa que não há interseção.
Dessa forma, após a leitura da entrada, basta fazer um for para todos os casos de teste, e a
cada leitura dos segmentos, para facilitar as operações, é necessário ordenar os pontos de forma
que x1 e y1 sejam o primeiro ponto do segmento e x2 e y2 o ponto final. Após isso, basta
verificar se os segmentos são horizontais e verticais para que a função correspondente seja
chamada. Por fim, será impresso "SEGMENT", "POINT" ou "NO" dependendo do resultado dessa função
conforme descrito anteriormente.

Tags = geometria, ponto, segmento, interseção'''''

*/

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} segmento;

int horizontal (segmento p){
    if (p.y1 == p.y2){
        return 1;
    }

    return 0;
}

int ePonto (segmento p){
    if (p.x1 == p.x2 && p.y1 == p.y2){
        return 1;
    }

    return 0;
}

int hh (segmento p1, segmento p2){
    if (ePonto(p1)){
        if (p1.y1 == p2.y1 && p1.x1 >= p2.x1 && p1.x1 <= p2.x2){
            return 1;
        }
    }

    else if (ePonto(p2)){
        if (p2.y1 == p1.y1 && p2.x1 >= p1.x1 && p2.x1 <= p1.x2){
            return 1;
        }
    }

    else if (p1.y1 == p2.y1 && (p1.x1 == p2.x2 || p2.x1 == p1.x2)){
        return 1;
    }

    else if ((p1.y1 == p2.y1) && (p2.x1 >= p1.x1 && p2.x1 <= p1.x2) || (p1.x1 > p2.x1 && p1.x1 < p2.x2)){
        return 2;
    }

    else {
        return 0;
    }
}

int hv (segmento p1, segmento p2){
    if (p2.x1 >= p1.x1 && p2.x1 <= p1.x2 && p1.y1 >= p2.y1 && p1.y1 <= p2.y2){
        return 1;
    }

    return 0;
}

int vh (segmento p1, segmento p2){
    if (p1.x1 >= p2.x1 && p1.x1 <= p2.x2 && p2.y1 >= p1.y1 && p2.y1 <= p1.y2){
        return 1;
    }

    return 0;
}

int vv (segmento p1, segmento p2){
    if (ePonto(p1)){
        if (p1.x1 == p2.x1 && p1.y1 >= p2.y1 && p1.y1 <= p2.y2){
            return 1;
        }
    }

    else if (ePonto(p2)){
        if (p2.x1 == p1.x1 && p2.y1 >= p1.y1 && p2.y1 <= p1.y2){
            return 1;
        }
    }

    else if (p1.x1 == p2.x1 && (p1.y1 == p2.y2 || p2.y1 == p1.y2)){
        return 1;
    }

    else if ((p1.x1 == p2.x1) && (p2.y1 >= p1.y1 && p2.y1 <= p1.y2) || (p1.y1 > p2.y1 && p1.y1 < p2.y2)){
        return 2;
    }

    else {
        return 0;
    }
}

int main (){
       int T = 0, i = 0, linha1 = 0, linha2 = 0, tipo = 0, aux = 0;
       segmento p1, p2;

    fscanf (stdin, "%d", &T);

    for (i=0; i<T; i++){
        fscanf(stdin, "%d %d %d %d", &p1.x1, &p1.y1, &p1.x2, &p1.y2);
        fscanf(stdin, "%d %d %d %d", &p2.x1, &p2.y1, &p2.x2, &p2.y2);

        if (p1.x1 > p1.x2){
            aux = p1.x1;
            p1.x1 = p1.x2;
            p1.x2 = aux;
        }

        if (p2.x1 > p2.x2){
            aux = p2.x1;
            p2.x1 = p2.x2;
            p2.x2 = aux;
        }

        if (p1.y1 > p1.y2){
            aux = p1.y1;
            p1.y1 = p1.y2;
            p1.y2 = aux;
        }

        if (p2.y1 > p2.y2){
            aux = p2.y1;
            p2.y1 = p2.y2;
            p2.y2 = aux;
        }

        linha1 = horizontal (p1);
        linha2 = horizontal (p2);

        //horizontal-horizontal
        if (linha1 == 1 && linha2 == 1){
            tipo = hh(p1, p2);
        }

        //horizontal-vertical
        else if (linha1 == 1 && linha2 == 0){
            tipo = hv(p1, p2);
        }

        //vertical-horizontal
        else if (linha1 == 0 && linha2 == 1){
            tipo = vh(p1, p2);
        }

        //Vertical-vertical
        else {
            tipo = vv(p1, p2);
        }

        if (tipo == 0){
            printf("NO\n");
        }

        else if (tipo == 1){
            printf("POINT\n");
        }

        else {
            printf("SEGMENT\n");
        }
    }

    return 0;
}