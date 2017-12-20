'''
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Eleições (SPOJ_ELEICOES)

O problema consiste em ler vários inteiros que representam o número de um candidato à 
prefeito e determinar qual é o candidato vencedor. A solução desse problema envolve uma
estrutura muito útil em Python, o dicionário. Nesse caso, cada candidato possui um número 
identificador que será a chave do dicionário e, para cada voto que o mesmo recebe, o valor
atrelado a essa chave é incrementado. Ao final, basta ordenar o dicionário em ordem decrescente
de acordo com o valor e imprimir a chave do candidato que obteve o maior número de votos, ou 
seja, o primeiro candidato nesse dicionário ordenado de forma decrescente. Nesse caso, como cada
caso de teste consiste de um conjunto de N votos, basta ler esse valor e fazer um for para que
cada um dos N valores sejam lidos. Se o candidato já possuía votos, ou seja, seu número já é uma
chave no dicionário (candidato in dict), basta incrementar o valor (dict[candidato] += 1). Caso 
contrário, basta adicionar a chave do novo candidato no dicionário com o valor igual a 1 
(dict[candidato] = 1). Ao final das leituras e contabilização ds votos, é feita a ordenação 
decrescente (reverse=True) de acordo com o valor atribuído a cada uma das chaves (value[1]). 
Por fim, a chave do primeiro elemento do dicionário ordenado será o próprio identificador do 
candidato vencedor (dictSort[0][0]).

Tags = dicionário, atualização de valores em dicionário, ordenação de dicionário, ordenação de 
dicionário pelo valor

'''

def main ():
	N = int(input()) 
	dict = {}

	for i in range (N):
		candidato = int(input())
		if (candidato in dict):
			dict[candidato] += 1
		else:
			dict[candidato] = 1

	dictSort = sorted(dict.items(), key=lambda value: value[1], reverse=True)
	print (dictSort[0][0])

main ()