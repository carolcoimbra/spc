#include <stdio.h>
#include <stdlib.h>
 
#define MAX 42195 

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Maratona (SPOJ_MARAT09)

O problema consiste em determinar se um atleta consegue completar uma prova de corrida dada
a posição dos postos de água ao longo do percurso, e a distância intermediária máxima de um 
atleta. Os casos de teste são individuais, dessa forma a cada execução do programa, o mesmo
recebe como entrada os valores N e M, que indicam respectivamente o número de postos de água
e a distância intermediária máxima de um atleta. Após isso, seguem N números inteiros Pi, 
representando a posição dos postos de água ao longo do trajeto da maratona. Devido a posição
de um posto de água é dada pela distância, em metros, do início do percurso até o posto de
água, as mesmas são armazenadas em um vetor de forma, que ao ser percorrido, a diferença entre
a localização de dois pontos adjacentes no vetor, incluindo a última distância para o final
da prova, seja menor ou igual à distância intermediária máxima do atleta. Caso a distância 
entre dois pontos de água seja maior do que a distância intermediária, significa que não será
possível completar a prova e é impresso 'N'. No contrário, é impresso 'S'.

Tags: vetor, comparação de valores

*/

char encontraResultado (int *postos, int N, int M){
    int i = 0;
    for (i=1; i<N; i++){
        if (postos[i]-postos[i-1] > M)
            return 'N';
    }
    if (MAX-postos[N-1] > M)
        return 'N';
    return 'S';
}

int main() {
    int i = 0, N = 0, M = 0;
    char resultado;
    
    fscanf(stdin, "%d %d", &N, &M);
    int *postos = (int*)malloc((N+2)*sizeof(int));   
    for (i=0; i<N; i++){
        fscanf(stdin, "%d", &postos[i]);
    }

    resultado = encontraResultado(postos, N, M);
    printf("%c\n", resultado);
    return 0;
}
