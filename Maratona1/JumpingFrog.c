#include <stdio.h>
#include <stdlib.h>

int main (){
	int i = 0, P = 0, N = 0;
	int canos[110];

	fscanf(stdin, "%d %d", &P, &N);
	for (i=0; i<N; i++){
		fscanf(stdin, "%d", &canos[i]);
	}

	for (i=0; i<N-1; i++){
		if (abs(canos[i]-canos[i+1]) > P){
			printf("GAME OVER\n");
			return 0;
		}
	}
	printf("YOU WIN\n");
	return 0;
}