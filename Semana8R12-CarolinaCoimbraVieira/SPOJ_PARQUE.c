#include <stdio.h>
#include <string.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Parque Jurássico (SPOJ_PARQUE)

O problema consiste em determinar a maior sequência de caracteres que contenha duas substrings
dadas como entrada do problema. Os casos de teste consistem de apenas duas strings S1 e S2 e 
terminam com o caractere '#', ou seja, enquanto a leitura de S1 for diferente de "#", o caso de 
teste é processado. A solução do problema consiste em encontrar a menor substring que está presente
nas duas strings dadas e, após isso formar uma string que, possui todo os caracteres das duas strings 
antes daqueles que formam a substring comum. Para isso, foi implementado o algoritmo "Longest Common 
Subsequence" através do qual uma matriz é construída e armazena os valores correspondentes à maior
substring existente entre duas strings. A matriz é montadad da seguinte forma, a primeira linha e 
a primeira coluna são preenchidas com 0, após isso, as strings são percorridas de forma que, caso
o caractere em ambas seja igual, basta somar 1 ao valor já encontrado na linha e coluna anterior, 
uma vez que isso a maior substring encontrada antes de se adicionar o caractere avaliado. Mas, caso
o caractes seja diferente, a matriz é preenchida com o valor máximo entre o valor da coluna anterior
na mesma linha e da linha anterior na mesma coluna. Após preenchida, basta percorrer a matriz de trás
para frente de forma que a maior string que contenha as duas strings como substring seja recuperada.
Nesse caso, quando os caracteres armazenados nas strings na posição indicada pelo índice da matriz são 
iguais, ele é adicionado à string que será o resultado e os indíces para ambas as sequências é decrementado, 
isso porque, o caractere que foi inserido na string é comum em ambas as strings que foram comparadas.
Outros quatro casos devem ser avaliados, dois deles para tratar de quando uma das strings já foi 
completamente percorrida, nesse caso, basta completar a string do resultado com todos os caracteres que
faltam percorrer na outra string. Além disso, quando os caracteres das strings não coincidem, deve-se
adicionar um deles à string e decrementar o índice referente à string do qual o caractere foi removido.
Essa decisão é tomada tendo como base os valores anteriores na matriz, ou seja, se o valor que está armazenado 
na mesma linha e na coluna anterior é maior do que o valor armazenado na linha anterior e na mesma coluna,
significa que o caractere sairá da string cujo identificado é igual ao identificador da coluna da matriz. 
Caso contrário, o caractere sairá da outra string e seu índice será decrementado, conforme dito anteriormente.
Ao final de todos esses passos, a string que armazenará o resultado estará pronta, no entanto, invertida,
sendo assim, basta inverter a string e imprimí-la. Vale ressaltar que antes de cada resultado deve ser 
impresso o número do caso de teste, para isso basta fazer um contador que, a cada caso de teste é incrementado 
em 1 e imprimir seu valor antes da string resultado. E, após isso deve-se deixar uma linha em branco ("\n").

Tags: substrings, strings, longest common subsequence, LCS

*/

int maximo (int a, int b){
	if (a > b){
		return a;
	}

	return b;
}

void inverte (char *S){
    int i = strlen(S)-1, j=0;
    char c;

    while(i > j){
        c = S[i];
        S[i]= S[j];
        S[j] = c;
        i--;
        j++;
    }
}

void lcsString (int matriz[110][110], char S1[110], char S2[110], int t1, int t2, char S[220], int t){
	int k = 0, count = 0;
	if (t1 == 0){
		for (k=t2-1; k>=0; k--){
			S[t+count] = S2[k];
			count ++;
		}
		S[t+count] = '\0';
	}
	else if (t2 == 0){
		for (k=t1-1; k>=0; k--){
			S[t+count] = S1[k];
			count ++;
		}
		S[t+count] = '\0';
	} 
	else if (S1[t1-1] == S2[t2-1]){
		S[t] = S1[t1-1];
		lcsString (matriz, S1, S2, t1-1, t2-1, S, t+1);
	}
	else {
		if (matriz[t1][t2-1] > matriz[t1-1][t2]){
			S[t] = S2[t2-1];
	        lcsString(matriz, S1, S2, t1, t2-1, S, t+1);
	    }
	    else {
	    	S[t] = S1[t1-1];
	        lcsString(matriz, S1, S2, t1-1, t2, S, t+1);
	    }
	}
}

void lcs (int matriz[110][110], char* S1, char* S2, char* S){
	int i = 0, j = 0, t1 = 0, t2 = 0;

	t1 = strlen(S1);
 	t2 = strlen(S2);

 	for (i=0; i<=t1; i++){
		for (j=0; j<=t2; j++){
			if (i == 0 || j == 0){
				matriz[i][j] = 0;
			}
			else if (S1[i-1] == S2[j-1]){
				matriz[i][j] = matriz[i-1][j-1] + 1;
			}
			else {
				matriz[i][j] = maximo (matriz[i-1][j], matriz[i][j-1]);
			}
		}
	}

	lcsString (matriz, S1, S2, t1, t2, S, 0);
}

void maxString (int matriz[110][110], char* S1, char *S2){
	int i = 0, j = 0, k = 0, tam = 0;
	char maxS[220];
	char S[220] = "";

	lcs (matriz, S1, S2, S);
	inverte(S);

	printf("%s\n", S);
}

int main (){
	int t = 0;
 	char S1[110], S2[110];
 	int matriz[110][110];

 	while (1){
 		t++;
 		fscanf(stdin, "%s", S1);

 		if (strcmp(S1, "#") == 0){
 			break;
 		}

 		fscanf(stdin, "%s", S2);

 		printf("Teste %d\n", t);
 		maxString (matriz, S1, S2);
 		printf("\n");
	}

	return 0;
}