#include <stdio.h>
#include <stdlib.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Caça ao tesouro (SPOJ_TESOUR11)

O problema consiste em determinar, caso exista apenas uma, a coordenada onde está o tesouro. Para 
isso, o problema fornece algumas pistas que nada mais são que a distância de um determinado ponto 
à coordenada onde encontra-se o tesouro. Para cada caso de teste, após ler o valor que representa 
a quantidade de quadriculados, N, e a quantidade de pistas, K, basta inicializar a matriz com as 
posições iguais a zero e, em seguida, para cada pista lida, a posição da matriz nas coordenadas 
correspondentes à pista recebe o valor referente à distância do tesouro àquela posição. Um fato 
muito importante é que as coordenadas são diferentes dos índices habituais de matriz, dessa forma, 
o índice i corresponde a N-1-coordenadaY enquanto que o índice j corresponde à coordenadaX. Após
preencher a matriz com as distâncias das pistas, basta fazer um for por cada uma das pistas e
calcular a distância entre cada célula da matriz para a célula onde consta a pista. Caso a distância
encontrada seja igual à distância armazenada na célula da pista, uma matriz auxiliar incrementa seu 
valor na posição onde foi feita a comparação. Dessa forma, nessa matriz auxiliar, cada célula
representa o número de vezes que determinada posição foi considerada a posição onde está o tesouro.
Por fim, basta percorrer essa matriz e buscar a posição cujo valor armazenado é o maior. Porém, caso
esse valor esteja presente em mais de uma célula dessa matriz, significa que o local onde está o
tesouro não pode ser determinado e "-1 -1" é impresso na tela. Caso contrário, as coordenadas dessa
célula da matriz são impressas, lembrando que a coordenadaX é igual a j e a coordenadaY é N-1-i.

Tags: matriz, distância entre coordenadas, caminhamento em matriz

*/

int main() {
    int i = 0, j = 0, i_aux = 0, j_aux = 0, k = 0, N = 0, K = 0, X = 0, Y = 0, D = 0;
    int count = 0, maior = 0, maiorX = 0, maiorY = 0;
    int matriz[101][101], matriz_aux[101][101];
    int K_x[101], K_y[101];

    fscanf(stdin, "%d %d", &N, &K);
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            matriz[i][j] = 0;
            matriz_aux[i][j] = 0;
        }
    }

    for (i=0; i<K; i++){
        fscanf(stdin, "%d %d %d", &X, &Y, &D);
        // X representa a coluna e Y representa a linha de baixo para cima
        matriz[N-1-Y][X] = D;
        K_x[i] = X;
        K_y[i] = Y;
    }

    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            for (k=0; k<K; k++){
                i_aux = N-1-K_y[k];
                j_aux = K_x[k];
                if(abs(i_aux-i)+abs(j_aux-j) == matriz[i_aux][j_aux]){
                    matriz_aux[i][j] += 1;
                }

            } 
        }
    }

    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            if(matriz_aux[i][j] >= maior){
                if(matriz_aux[i][j] > maior){
                    count = 0;
                }
                maior = matriz_aux[i][j];
                maiorX = j;
                maiorY = N-1-i;
                count ++;
            }
        }
    }

    if(count > 1){
        printf("-1 -1\n");
    }
    else{
        printf("%d %d\n", maiorX, maiorY);
    }
    return 0;
}
