#include <stdio.h>

typedef struct {
	int i;
	int j;
} posicao;


int encontraVencedor (int matriz[5][5]){
	int i = 0, j = 0, novoi = 0, novoj = 0, inicio = 0, fim = 0;
	int visitados[5][5];
	posicao fila[25], direcao[4];

	for (i=0; i<5; i++){
		for (j=0; j<5; j++){
			visitados[i][j] = 0;
		}
	}

	for (i=0; i<25; i++){
		fila[i].i = -1;
		fila[i].j = -1;
	}

	direcao[0].i = 0;
	direcao[0].j = 1;
	direcao[1].i = 1;
	direcao[1].j = 0;
	direcao[2].i = 0;
	direcao[2].j = -1;
	direcao[3].i = -1;
	direcao[3].j = 0;


	visitados[0][0] = 1;
	fila[fim].i = 0;
	fila[fim].j = 0;
	fim ++;

	while (inicio < 25 && fila[inicio].i != -1){
		for (i=0; i<4; i++){
			novoi = fila[inicio].i + direcao[i].i;
			novoj = fila[inicio].j + direcao[i].j;
			if(novoi >= 0 && novoi < 5 && novoj >= 0 && novoj < 5){
				if (matriz[novoi][novoj] == 0 && visitados[novoi][novoj] == 0){
					visitados[novoi][novoj] = 1;
					if (novoi == 4 && novoj == 4){
						return 1;
					}
					fila[fim].i = novoi;
					fila[fim].j = novoj;
					fim ++;
				}
			}
		}
		inicio ++;
	}
	return 0;
}

int main (){
	int T = 0, t = 0, i = 0, j = 0, vencedor = 0;
	int matriz[5][5];
	int visitados[25];
	posicao fila[25];

	fscanf(stdin, "%d", &T);
	
	for (t=0; t<T; t++){
		for (i=0; i<5; i++){
			for (j=0; j<5; j++){
				matriz[i][j] = 0;
			}
		}

		for (i=0; i<5; i++){
			for (j=0; j<5; j++){
				fscanf(stdin, "%d", &matriz[i][j]);
			}
		}

		vencedor = encontraVencedor (matriz);
		if (vencedor == 1){
			printf("COPS\n");
		}
		else{
			printf("ROBBERS\n");
		}
	}
}
	