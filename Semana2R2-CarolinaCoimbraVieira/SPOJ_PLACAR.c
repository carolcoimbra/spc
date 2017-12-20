#include <stdio.h>
#include <string.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Quem vai ser reprovado (SPOJ_PLACAR)

O problema consiste em ler vários nomes de alunos com um valor inteiro referente à quantidade
de problemas resolvidos pelos mesmos e, determinar quem será o aluno reprovado. O aluno 
reprovado deverá ser aquele cuja quantidade de problemas resolvidos é a menor e, caso haja
empate, o reprovado será aquele cujo nome vem depois de acordo com a ordem alfabética. A 
solução do problema envolve incialmente ler o primeiro aluno e salvá-lo como sendo o reprovado
e sua quantidade de problemas resolvidos como sendo a menor. A partir de então, a cada novo 
aluno lido, a quantidade de problemas é comparada com a menor até então de forma que, caso seja
menor, a variável menor é atualizada assim como o nome do aluno reprovado. Para isso, a função
strcpy da biblioteca string.h é usada para copiar o nome do aluno para a string que indica o 
nome do aluno reprovado. Outra condição que deve ser verificada é se a quantidade de problemas
resolvidos pelo aluno em questão é igual à menor quantidade até o momento. Nesse caso, se o novo
aluno possui um nome cuja ordem alfabética é maior do que o aluno que seria reprovado até o momento,
os valores são atualizados. Para comparar a ordem dos nomes dos alunos foi utilizada a função
strcmp da biblioteca string.h que retorna > 0 caso a string do primeiro argumento seja maior do
que a do segundo argumento. Nesse caso, como o fim da entrada é marcado pelo fim do arquivo "EOF", 
basta ler o valor N, que representa o número de alunos que segue em cada caso de teste enquanto 
não for o fim do arquivo, determinar o aluno reprovado utilizando um for e imprimir no final.

Tags: comparação de strings, comparação de valores, atualização do menor valor, strcpy(), strcmp()

*/

int main() {
    int n = 0, p_aux = 0, menor = 0, N = 0, instancia = 0;
    char infeliz[25], aluno_aux[25];
    
    while (fscanf(stdin, "%d", &N) != EOF){
        fscanf(stdin, "%s %d", infeliz, &menor);

        for (n=1; n<N; n++){
            fscanf(stdin, "%s %d", aluno_aux, &p_aux);
            if (p_aux < menor){
                strcpy(infeliz, aluno_aux);
                menor = p_aux;
            }
            else if (p_aux == menor){
                if (strcmp(aluno_aux, infeliz) > 0){
                    strcpy(infeliz, aluno_aux);
                }
            }
        }        
        instancia++;
        printf("Instancia %d\n", instancia);
        printf("%s\n", infeliz);
    }
    return 0;
}
