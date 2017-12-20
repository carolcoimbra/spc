#include <stdio.h>
#include <stdlib.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Dentista (SPOJ_JDENTIST)

O problema consiste em determinar a quantidade máxima de consultas que podem ser atenditas 
sem sobreposição dado uma lista com os horários de início e término de consultadas agendadas.
O problema consiste de casos de teste individuais compostos por uma linha, que contém um 
número inteiro positivo N, que indica a quantidade de consultas agendadas, seguido de N 
linhas com dois inteiros que indicam o início e término de cada uma das N consultas. Após
ler o valor N, um for percorre todas as N linhas, salvando em um vetor o tempo de início e
fim de cada uma das consultas, para isso, foi criada uma estrutura chamada "consulta" que
armazena esses dois inteiros. Após preenchido todo o vetor com essas consultas, o mesmo é
ordenado de acordo com o tempo de témino das consultas. Isso permite que as consultas sejam
alocadas de forma contígua ao longo do dia. Entretanto, como não deve haver sobreposição, 
escolhe-se a primeira consulta desse vetor ordenado e, a partir de então, o restante do
vetor é percorrido de modo que se a próxima consulta inicia no mesmo horário de término da
última consulta escolhida, ou depois dela, a mesma é contabilizada como mais uma consulta
a ser adicionada ao dia sem sobreposição. Dessa forma, a cada nova consulta escolhida, o
contador é incrementado e, ao final, seu valor é impresso, representando a quantidade máxima
de consultas que poderão ser feitas sem sobreposição.

Tags: algoritmo guloso, struct, vetor, qsort

*/

typedef struct {
	int inicio;
	int fim;
} consulta;

int compara (const void * a, const void * b){
	consulta *primeiro = (consulta *)a;
	consulta *segundo = (consulta *)b;
   	return (primeiro->fim - segundo->fim);
}

int main (){
	int N = 0, i = 0, count = 0;
	consulta ultimo;
	consulta consultas[10000];

	fscanf(stdin, "%d", &N);


	for (i=0; i<N; i++){
		fscanf(stdin, "%d %d", &consultas[i].inicio, &consultas[i].fim);
	}

	qsort(consultas, N, sizeof(consulta), compara);

	ultimo = consultas[0];
	count = 1;
	for (i=1; i<N; i++){
		if (consultas[i].inicio >= ultimo.fim){
			ultimo = consultas[i];
			count ++;
		}
	}
	printf("%d\n", count);
	
	return 0;
}
