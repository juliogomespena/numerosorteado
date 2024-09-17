#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	//Declara��o de vari�veis
	int numero01, numero02;
	int numeroDigitado;
	int numeroSorteado;

	//Exibindo t�tulo do jogo
	printf_s("*********************************************\n");
	printf_s("*** Bem vindo ao jogo do numero sorteado! ***\n");
	printf_s("*********************************************\n");
	printf_s("\n\n");

	Sleep(1500);

	printf_s("Vamos primeiro escolher o intervalo de nosso numero sorteado!\n");

	Sleep(4000);

	system("cls");

	//Loop para verifica��o do intervalo de n�meros
	while (1)
	{
		//Solicita e armazena numero01
		printf_s("Digite o primeiro numero\n");
		scanf_s("%d", &numero01);

		//Solicita e armazena numero02
		printf_s("Digite o segundo numero\n");
		scanf_s("%d", &numero02);

		//Verifica se numero01 � menor que numero02
		if (numero01 > numero02)
		{
			printf_s("O primeiro numero deve ser menor que o segundo numero!\n");
			Sleep(2500);
			system("cls");
		}
		//Verifica se numero01 � igual a numero02
		else if (numero01 == numero02)
		{
			printf_s("Os numeros devem ser diferentes!\n");
			Sleep(2500);
			system("cls");
		}
		//Se os n�meros forem v�lidos, sai do loop
		else
		{
			system("cls");
			break;
		}
	}

	// Inicializa o gerador de numeros aleat�rios
	srand((unsigned int)time(NULL));

	//Gerar numero aleatorio entre numero01 e numero02
	numeroSorteado = rand() % (numero02 + 1 - numero01) + numero01;

	//Mensagem para chutar n�mero
	printf_s("Tente acertar o numero entre %d e %d.\n", numero01, numero02);

	//Loop para permitir tentativas infinitas de chute at� acertar
	while (1)
	{
		//L� o n�mero digitado
		scanf_s("%d", &numeroDigitado);

		//Verifica se o n�mero digitado � igual ao n�mero sorteado
		if (numeroDigitado == numeroSorteado)
		{
			printf_s("Parabens! Voce acertou o numero sorteado!\n\n");
			break;
		}
		//Verifica se o n�mero digitado � maior que numero sorteado
		else if (numeroDigitado > numeroSorteado)
		{
			printf_s("O numero sorteado e menor que o numero digitado!\n\n");
		}
		//Verifica se o n�mero digitado � menor que o numero sorteado
		else
		{
			printf_s("O numero sorteado e maior que o numero digitado!\n\n");
		}
	}

	return 0;
}
