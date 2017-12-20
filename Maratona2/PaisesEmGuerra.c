#include <stdio.h>    // fopen, fclose, fgets, feof
#include <stdlib.h>   // malloc, free, exit, qsort
#include <string.h>   // strtok, strcmp, strcpy
#include <math.h> //pow, sqrt
 
#define MAX 500
#define INFINITO 100000
 
void ZeraMatriz(int Matriz[MAX][MAX], int n){
    int i=0; int j=0;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            Matriz[i][j]=INFINITO;
        }
    }
}
 
int BuscaMenor(int Vetor[MAX], int Visitados[MAX], int n, int c1){
    int i=0;
    int menor = INFINITO;
    int aux;

    for (i=0; i<n; i++){
        if (Vetor[i]<menor && Visitados[i] == -1){
            menor = Vetor[i];
            aux = i;
        }
    }

    if(menor == INFINITO){
        return INFINITO;
    }

    return aux;
}

 
int BuscaCaminho(int Matriz[MAX][MAX], int n, int c1, int c2){
    int Visitados[n];
    int Cidades[n];
    int menor=0, aux=0, menor_indice=0;
    int i=0, j=0;
    int horas=0;
    int origem=0;
 
    for (i=0; i<n; i++){
        Cidades[i] = INFINITO;
        Visitados[i] = -1;
    }

    Cidades[c1] = 0;
    Visitados[c1] = c1;
    origem = c1;

    while (Visitados[c2] == -1){
        for (i=0; i<n; i++){
            if (Matriz[origem][i] != INFINITO && Matriz[i][origem] != INFINITO){
                Cidades[i] = Cidades[origem];
            }
            else if (Matriz[origem][i] + Cidades[origem] < Cidades[i]){
                Cidades[i] = Cidades[origem] + Matriz[origem][i];
            }
        }

        menor_indice = BuscaMenor(Cidades, Visitados, n, origem);
        if (menor_indice == INFINITO){
            return INFINITO;
        }

        else {
            origem = menor_indice;
            Visitados[menor_indice] = menor_indice;
        }
    }
    
    if (Cidades[c2] != INFINITO) {
        return Cidades[c2];
    }
}
 
void main () {
    int Matriz[MAX][MAX];
    int num_cidades=0, num_acordos=0, num_consultas=0;
    int cidade1=0, cidade2=0;
    int x=0, y=0, h=0;
    int horas=0;
    int i=0;
 
 
    scanf ("%d %d", &num_cidades, &num_acordos);
    while (num_cidades != 0 || num_acordos != 0){
        ZeraMatriz(Matriz, num_cidades);
        for (i=0; i<num_acordos; i++){
            scanf("%d %d %d", &x, &y, &h);
            x--;
            y--;
            Matriz[x][y]=h;
        }
 
        scanf ("%d", &num_consultas);
        for(i=0; i<num_consultas; i++){
            scanf ("%d %d", &cidade1, &cidade2);
            cidade1--;
            cidade2--;
            if (Matriz[cidade1][cidade2] != INFINITO && Matriz[cidade2][cidade1] != INFINITO || cidade1 == cidade2){
                horas = 0;
                printf("%d\n", horas);
            }
 
            else{
                horas = BuscaCaminho(Matriz, num_cidades, cidade1, cidade2);
 
                if (horas>=INFINITO){
                    printf("Nao e possivel entregar a carta\n");
                }
                else{
                    printf("%d\n", horas);
                }
            }
        }
 
        printf("\n");
 
 
        scanf ("%d %d", &num_cidades, &num_acordos);
    }
}