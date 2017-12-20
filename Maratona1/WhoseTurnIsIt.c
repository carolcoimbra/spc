#include <stdio.h>
#include <string.h>

int main() {
    int n = 0, N = 0, valor1 = 0, valor2 = 0, soma = 0;
    char jogador1[110], jogador2[110];
    char escolha1[10], escolha2[10];
    
    fscanf(stdin, "%d", &N);
    for (n=0; n<N; n++){
        fscanf(stdin, "%s %s %s %s", jogador1, escolha1, jogador2, escolha2);  
        fscanf(stdin, "%d %d", &valor1, &valor2);

        soma = valor1 + valor2;

        if (soma%2 == 0){
        	if (strcmp(escolha1, "PAR") == 0){
        		printf("%s\n", jogador1);
        	}
        	else {
        		printf("%s\n", jogador2);
        	}
        } 
        else{
        	if (strcmp(escolha1, "IMPAR") == 0){
        		printf("%s\n", jogador1);
        	}
        	else {
        		printf("%s\n", jogador2);
        	}
    	}
    }
}
