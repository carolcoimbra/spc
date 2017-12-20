'''
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: What's Cryptanalysis? (UVa_10008)

O problema consiste em ler um inteiro N que reprsenta o número de frases que devem ser lidas
na sequência e determinar em ordem decrescente as letras que aparecem com mais frequência no
texto. E, caso alguma letra aparece a mesma quantidade de vezes do que outra, ordenar de acordo
com a ordem lexicográfica. Para solucionar esse problema, foi criado um vetor para representar 
todas as letras do alfabeto. Como os casos de teste são individuais, a cada chamada do main, o 
vetor alfabet é criado, o valor de N é lido e, em seguida, um for permite que as N frases sejam
lidas. Para cada frase lida, a mesma tem todos os seus caracteres alterados para maiúsculo. 
Após isso, todos os caracteres da frase são percorrido de forma que, caso algum deles seja igual
a algum caractere do vetor alfabeto, basta verificar se o a chave desse caractere já está no 
dicionário, nesse caso basta incrementar o valor em 1 e, caso contrário, basta criar essa chave 
e inicializar seu valor em 1. Por fim, quando todas as frases já tiverem sido lidas, basta ordenar
o dicionário da seguinte forma, em ordem decrescente ordena-se os valores do dicionário e, em caso
de empate, ordena-se em ordem crescente de acoro com a chave, que nada mais é do que o próprio 
caractere. Para fazer isso, basta uma linha: sorted(dict.items(), key=lambda v:(-v[1], v[0]))
E, por fim, com o dicionário ordenado, basta fazer um for para percorrê-lo e imprimir a chave do 
mesmo secguido de seu valor.

Tags = dicionário, atualização de valores em dicionário, ordenação de dicionário, ordenação de 
dicionário por valor e chave, string, upper

'''

def main ():
	alfabeto = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

	N = int(input())

	dict = {}

	for i in range (N):
		frase = input()
		frase = frase.upper()

		for j in range (len(frase)):
			if (frase[j] in alfabeto):
				if (frase[j] in dict):
					dict[frase[j]] += 1
				else:
					dict[frase[j]] = 1

	dictSort = sorted(dict.items(), key=lambda value:(-value[1], value[0]))

	for d in dictSort:
		print (d[0] + " " + str(d[1]))

main ()