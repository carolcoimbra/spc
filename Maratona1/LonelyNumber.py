while (1):
	N = int(input()) 
	dict = {}

	if (N == 0):
		break

	numeros = map(int, input().split())
	for numero in numeros:
		if (numero in dict):
			dict[numero] += 1
		else:
			dict[numero] = 1

	for i in dict:
		if (dict[i]%2 == 1):
			print (i)
