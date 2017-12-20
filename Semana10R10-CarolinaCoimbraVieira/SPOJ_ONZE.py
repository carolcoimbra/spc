'''
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Você pode dizer 11 (SPOJ_ONZE)

O problema consiste em ler um inteiro N e determinar se o mesmo é divisível ou não por 11.
Para solucionar o problema, basta ler o valor de N como uma string para que essa variável
seja utilizada no final para imprimir o resultado. Sendo assim, enquanto que uma variável 
armazena o valor lido como uma string, outra armazena esse mesmo valor como um inteiro, 
sendo assim, caso o resto da divisão desse inteiro por 11 seja igual a zero, significa que 
o mesmo é divisível por 11 e a string que representa esse valor é impressa seguida de
" is a multiple of 11.". Caso contrário, a string que representa o inteiro é impressa 
seguida de " is not a multiple of 11.". Vale lembrar que os casos de teste terminam quando
o inteiro é igual a 0, sendo assim, quando isso ocorre, a leitura dos casos de teste se
encerram.

Tags = divisibilidade, mod, strings

'''

def main():

	while (1):
	    numeroString = str(input())
	    numero = int(numeroString)

	    if (numero == 0):
	    	break

	    if (numero%11 == 0):
	    	print (numeroString + " is a multiple of 11.")
	    else:
	    	print (numeroString + " is not a multiple of 11.")

main()