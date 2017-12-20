'''
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Choosing Symbol Pairs (Codeforces_CF50B)

O problema consiste em ler uma string S de tamanho N e determinar a quantidade de pares (i,j) 
que podem ser formados de forma que 1 <= i, j <= N e S[i] = S[j]. Como os casos de teste são 
individuais, a cada chamada do main, um dicionário é criado e a string S é lida. Após isso, 
todos os caracteres da string são percorrido de forma que, caso algum deles esteja no dicionário, 
basta incrementar o valor em 1 e, caso contrário, basta criar essa chave e inicializar seu valor 
em 1. Após percorrer toda a string e completado o dicionário conforme descrito acima, basta 
elevar todos os valores do dicionário à potência de 2 e somar todos eles. Isso significa que, 
ao elevar a potência de 2, são gerados todos os pares com aquele caractere específico representado
pela chave do dicionário, uma vez que os pares devem ser formados pelo mesmo caractere, já que
uma das restrições do problema é que S[i] deve ser igual à S[j]. Uma informação importante é que 
como foi descrito na especificação, os pares (1,2) e (2,1) são diferentes, ou seja, a ordem importa, 
sendo assim, elevando à potência de 2, todos os pares são considerados. E, ao somar todos os valores 
resultantes significa que todos os pares formados por todos os caracteres serão considerados. 
Por fim, basta imprimir essa soma. 

Tags = dicionário, atualização de valores em dicionário, soma de valores do dicionário, strings

'''

def main ():
	dict = {}

	S = input();

	for i in range (len(S)):
		if (S[i] in dict):
			dict[S[i]] += 1
		else:
			dict[S[i]] = 1

	for key in dict:
		dict[key] *= dict[key]

	print (sum(dict.values()))

main ()
