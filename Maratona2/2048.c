#include <stdio.h>
#include <stdlib.h>

int verificaValorMaximo (int matriz[5][5]){
    int i = 0, j = 0;

    for (i=0; i<4; i++){
        for (j=0; j<4; j++){
            if (matriz[i][j] == 2048){
                return 1;
            }
        }
    }
    return 0;
}

void buscaSolucao (int matriz[5][5], int resposta[4]){
    int i = 0, j = 0, contador = 0;

    for (i=0; i<3; i++){
        for (j=0; j<4; j++){
            if ((matriz[i][j] == matriz[i+1][j] && matriz[i][j] != 0) || matriz[i+1][j] == 0 && matriz[i][j] != 0){
                resposta[contador] = 1;
                break;
            }
        }

        if (resposta[contador] == 1){
            contador ++;
            break;
        }
    }

    for (i=0; i<4; i++){
        for (j=3; j>0; j--){
            if ((matriz[i][j] == matriz[i][j-1] && matriz[i][j] != 0) || matriz[i][j-1] == 0 && matriz[i][j] != 0){
                resposta[contador] = 2;
                break;
            }
        }

        if (resposta[contador] == 2){
            contador ++;
            break;
        }
    }

    for (i=0; i<4; i++){
        for (j=0; j<3; j++){
            if ((matriz[i][j] == matriz[i][j+1] && matriz[i][j] != 0) || matriz[i][j+1] == 0 && matriz[i][j] != 0){
                resposta[contador] = 3;
                break;
            }
        }

        if (resposta[contador] == 3){
            contador ++;
            break;
        }
    }

    for (i=0; i<3; i++){
        for (j=0; j<4; j++){
            if ((matriz[i+1][j] == matriz[i][j] && matriz[i][j] != 0) || matriz[i][j] == 0 && matriz[i+1][j] != 0){
                resposta[contador] = 4;
                break;
            }
        }

        if (resposta[contador] == 4){
            contador ++;
            break;
        }
    }

}

int main () {
    int T = 0, i = 0, j = 0, t = 0, espaco = 0;
    int matriz[5][5];
    int resposta[4];
  
    fscanf(stdin, "%d", &T);

    for (t=0; t<T; t++){

        for (i=0; i<4; i++){
            for (j=0; j<4; j++){ 
                fscanf(stdin, "%d", &matriz[i][j]);
            }
        }

        if (verificaValorMaximo(matriz) == 1){
            printf("NONE");
        }

        else {
            espaco = 0;

            for (i=0; i<4; i++){
                resposta[i] = 0;
            }

            buscaSolucao(matriz, resposta);

            if (resposta[0] == 0){
                printf("NONE");
            }

            else {
                for (i=0; i<4; i++){
                    if (resposta[i] == 1){
                        printf("DOWN");
                        espaco = 1;
                    }

                    else if (resposta[i] == 2){
                        if (espaco == 1){
                            printf(" LEFT");
                        }

                        else {
                            printf("LEFT");
                            espaco = 1;
                        }
                    }

                    else if (resposta[i] == 3){
                        if (espaco == 1){
                            printf(" RIGHT");
                        }

                        else {
                            printf("RIGHT");
                            espaco = 1;
                        }
                    }

                    else if (resposta[i] == 4){
                        if (espaco == 1){
                            printf(" UP");
                        }

                        else {
                            printf("UP");
                            espaco = 1;
                        }   
                    }
                }
            }
        }

        printf("\n");
    }

    return 0;
}