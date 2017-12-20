#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
*/

int main() {
    int T = 0, N = 0, i = 0, pontos = 0, count = 0;
    char time [15];

    while (1){
        fscanf(stdin, "%d %d", &T, &N);

        if (T == 0){
            break;
        }
        
        count = 0;

        for (i=0; i<T; i++){
            fscanf(stdin, "%s %d", time, &pontos);

            count = count + pontos;
        }
        printf("%d\n", 3*N - count);
    }
    return 0;
}