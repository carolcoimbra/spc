import math

'''
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Poodle (SPOJ_POODLEMG)

O problema consiste em ler dois inteiros que representam a quantidade de documentos encontrados
em uma busca, N, e a quantidade de resultados que podem ser exibidos por página, P, e, após
isso, imprimir a palavra Poodle com a quantidade de caracteres igual ao números de páginas 
que são necessárias para exibir todos os resultados. Entretanto, uma informação importante é
que existem limites inferior e superior para o tamanho da palavra que são, respectivamente, 
6 e 20. Sendo assim, caso o número de páginas seja maior do que 6, é impresso Poodle e caso o
número de páginas seja maior ou igual a 20 é impresso essa mesma palavra com 16 'o's. A solução 
desse problema envolve encontrar um arredondamento superior da divisão entre o número de documentos
N pelo número de resultados por página P. Após isso, basta ajustar esse valor levando em conta os
limites especificados anteriormente (6 e 20) e, por fim, imprimir "P" concatenado com a quantidade
de 'o' e concatenado com o restante da palavra "dle". A quantidade de 'o' será, portanto, igual
ao valor encontrado no teto da divisão N/P menos 4 referentes aos 4 caracteres fixos da palavra.
Nesse caso, existem vários casos de teste que terminam quando o valor N e P são iguais a 0, sendo
assim, basta ler esses valores enquanto os mesmos forem diferentes de 0, efetuar as operações
descritas acima e imprimir o resultado.  

Tags = strings, imprimir strings, repetição de caracteres, arredondamento, teto

'''

def main ():
	while (1):
		N, P = raw_input().split(" ")
		N = float(N) 
		P = float(P)

		if (N == 0.0 and P == 0.0):
			break

		paginas = int(math.ceil(N/P))

		if (paginas <= 6):
			paginas = 6

		elif (paginas >= 20):
			paginas = 20

		paginas = paginas - 4

		print ("P" + paginas*'o' + "dle")

main ()