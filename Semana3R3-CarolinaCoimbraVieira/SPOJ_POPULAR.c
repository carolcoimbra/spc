#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Popularidade (SPOJ_POPULAR)

O problema consiste em determinar a quantidade de votos recebida pelo aluno vencedor de uma 
eleição escolar. Para esse problema, um vetor foi criado para armazenar a contagem dos votos 
de cada um dos alunos, ou seja, cada posição do vetor recebe o número de votos recebidos pelo
aluno cujo número é indicado pelo índice do vetor. Dessa forma, a cada linha de votos lida, caso
o valor seja igual a 1, a posição do vetor correspondente à posição na qual o número foi lida é 
incrementada em 1. Nesse caso, como o fim da entrada é marcado pelo valor de N, quantidade de alunos 
igual a 0, basta ler esse valor N e, quando o mesmo for igual a 0, o programa é finalizado. Mas, 
enquanto for diferentes de 0, as N linhas com os votos são lidas em um for que atualiza a quantidade
de votos em cada posição, conforme descrito anteriormente. E, por fim, outro for percorre o vetor 
buscando o maior valor armazenado no mesmo, ou seja, a maior quantidade de votos recebida na eleição, 
que é impresso na tela.

Tags: vetor, comparação de valores, atualização do maior valor

*/

int main() {
    int i = 0, n = 0, N = 0, max = 0, voto = 0;
    int alunos[102];
    
    while (1){
    	fscanf(stdin, "%d", &N);
    	if (N == 0){
    		break;
    	}

        for (i=0; i<N; i++){
            alunos[i] = 0;
        }

        for (n=0; n<N; n++){
            for (i=0; i<N; i++){
                fscanf(stdin, "%d", &voto);
                if(voto == 1){
                    alunos[i] += 1;
                }
            }
        }

        max = 0;
        for (i=0; i<N; i++){
            if(alunos[i] >= max){
                max = alunos[i];
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
