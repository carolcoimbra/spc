N = int(input())

for n in range (N):
	dict = {}

	palavras = list(map(str, input().split()))

	i=0
	for palavra in palavras:
		dict[i] = len(palavra)
		i += 1

	dictSort = sorted(dict.items(), key=lambda value: value[1], reverse=True)
	for i in range (len(dictSort)-1):
		print (palavras[dictSort[i][0]], end=" ")
	print(palavras[dictSort[len(dictSort)-1][0]])

