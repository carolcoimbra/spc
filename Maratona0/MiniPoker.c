#include <stdio.h>
#include <stdlib.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
*/

int encontraResultado (int *cartas){
    //regra 1:
    if (cartas[0] == cartas[1]-1 && cartas[1] == cartas[2]-1 && cartas[2] == cartas[3]-1 && cartas[3] == cartas[4]-1){
        return 200+cartas[0];
    }

    //regra 2:
    else if (cartas[0] == cartas[1] && cartas[1] == cartas[2] && cartas[2] == cartas[3] || (cartas[1] == cartas[2] && cartas[2] == cartas[3] && cartas[3] == cartas[4])){
        return 180+cartas[1];
    }

    //regra 3 4:
    else if ((cartas[0] == cartas[1] && cartas[1] == cartas[2]) || (cartas[1] == cartas[2] && cartas[2] == cartas[3]) || (cartas[2] == cartas[3] && cartas[3] == cartas[4])){ 
        if ((cartas[0] != cartas[2] && cartas[0] == cartas[1]) || (cartas[2] != cartas[4] && cartas[3] == cartas[4])){
            return 160+cartas[2];
        }       
        else {
            return 140+cartas[2];
        }
    }

    //regra 5:
    else if (cartas[0] == cartas[1] || cartas[1] == cartas[2]){
        if (cartas[2] == cartas[3] || cartas[3] == cartas[4]){
            return 3*cartas[3] + 2*cartas[1] + 20;
        }
        //regra 6:
        else{
            return cartas[1];
        }
    }

    //regra 6:
    else if (cartas[2] == cartas[3] || cartas[3] == cartas[4]){
        return cartas[3];
    }

    //regra 7:
    else{
        return 0;
    }

}

int compara (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}


int main() {
    int N = 0, i = 0;
    int cartas[5];

    fscanf(stdin, "%d", &N);

    for (i=0; i<N; i++){
        fscanf(stdin, "%d %d %d %d %d", &cartas[0], &cartas[1], &cartas[2], &cartas[3], &cartas[4]);
        qsort (cartas, 5, sizeof(int), compara);

        printf("Teste %d\n", i+1);
        printf("%d\n", encontraResultado(cartas));
        printf("\n");
    }
    return 0;
}