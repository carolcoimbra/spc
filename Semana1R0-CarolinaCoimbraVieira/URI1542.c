#include <stdio.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Lendo Livros (URI1542)

O problema consiste em ler três valores inteiros e calcular o número de páginas de 
um livro. Para solucionar esse problema, a seguinte equação foi montada: 
                        paginas/Q - paginas/P = D
onde paginas representa o número de páginas que tem o livro (o que se deseja descobrir), 
Q é o número de páginas lidas por dia, D é o número de dias que seriam "economizados" 
caso P páginas estivessem sendo lidas por dia. Ou seja, a equação acima representa 
exatamente isso, a diferença entre a quantidade de dias que se gasta lendo Q páginas 
por dia e lendo P páginas por dia. Tirando o mmc(P, Q), encontraremos a seguinte equação:
                        (P*paginas-Q*paginas)/P*Q = D
multiplicando cruzado, chega-se a:
                        (P*paginas-Q*paginas) = D*P*Q
e, isolando a variável paginas, que deseja-se descobrir, temos:
                        paginas = D*P*Q/(P-Q)
Sendo assim, após definida a equação para encontrar o número de páginas do livro, basta
ler e substiruir os valores de Q, D e P de cada um dos casos de teste do problema.
Nesse caso, como o fim da entrada é marcado pelo valor de Q igual a 0, basta ler os 
valores enquanto Q for diferente de zero, calcular o número de páginas do livro e 
verificar se a palavra "pagina" deverá ser impressa no singular (caso o número de 
páginas seja igual a 1) ou no plural (caso o número de páginas seja igual a 2 ou mais).

Tags: equação, mmc

*/

void main() {
    int i = 0, j = 0;
    int Q = 0, D = 0, P = 0, paginas = 0;

    fscanf(stdin, "%d", &Q);
    while (Q != 0){
        fscanf(stdin, "%d %d", &D, &P);

        paginas = (D*P*Q)/(P-Q);
        
        if (paginas == 1){
            printf("%d pagina\n", paginas);
        }
        else {
            printf("%d paginas\n", paginas);
        }

        fscanf(stdin, "%d", &Q);
    }
}