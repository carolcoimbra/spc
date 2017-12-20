#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Ele está impedido (SPOJ_IMPEDIDO)

O problema consiste em ler vários valores inteiros que representam as distâncias dos
atacantes de um time e os defensores do time oposto e determinar se existe algum atacante
impedido. Para determinar se um atacante está impedido, basta verificar se existe algum 
atacente cuja distância até a linha do gol é menor do que a distância do penúltimo defensor 
até a linha do gol. Dessa forma, basta ordenar as distâncias dos defensores até a linha do 
gol e verificar se a distância de algum dos atacantes ao gol é menor do que a segunda menor 
distância de um defensor ao gol, ou seja, o vetor de defensores na segunda posição. A segunda 
posição do vetor de defensores indica o segundo defensor mais próximo da linha do gol e, se 
existe um atacente com distância menor do que ele, significa que o mesmo encontra-se posicionado 
antes do denfensor em relação à linha do gol, ou seja, impedimento. Caso isso ocorra, significa 
que houve impedimento,"Y", caso contrário, "N". A ordenação do vetor consiste de um algoritmo 
simples de ordenação, Selection Sort e a verifição de impedimento é feita por meio de um if que 
verifica se a distância dos atacantes cujo vetor está sendo percorrido por um for é menor do que a 
segunda menor distância entre os defensores. Nesse caso, como o fim da entrada é marcado pelos 
valores de número de atacantes e números de defensores igual a 0, basta ler esses valores (A e D) 
e, quando os mesmos forem iguais a 0, o programa é finalizado. Mas, enquanto forem diferentes de 0, 
os valores são lidos, seguido de um for para armazenar em um vetor as distâncias dos atacantes e 
defensores para o gol, ordenação desse vetor, verificação da condição de impedimento e o resultado
é impresso, informando se existe ou não impedimento.

Tags: ordenação, comparação de vetores

*/

void ordenaVetor (int vetor[12], int D){
    int i = 0, j = 0, aux = 0;
    
    for (i=0; i<D; i++){
        for (j=i+1; j<D; j++){
            if(vetor[i] > vetor[j]){
                aux  = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int impedimento(int atacantes[12], int A, int defensores[12], int D){
    int i = 0;

    ordenaVetor(defensores, D);
    for (i=0; i<A; i++){
        if(atacantes[i] < defensores[1]){
            return 1;
        }
    }
    return 0;
}

int main() {
    int i = 0, j = 0, impedido = 0, A = 0, D = 0;
    int atacantes[12], defensores[12];
    
    while (1){
    	fscanf(stdin, "%d %d", &A, &D);
    	if(A == 0 && D==0){
    		break;
    	}
    	for (i=0; i<A; i++){
    		fscanf(stdin, "%d", &atacantes[i]);
    	}
    	for (i=0; i<D; i++){
    		fscanf(stdin, "%d", &defensores[i]);
    	}

	   	impedido = impedimento(atacantes, A, defensores, D);

    	if(impedido == 1){
    		printf("Y\n");
    	}
    	else{
        	printf("N\n");
    	}
    }
    return 0;
}