#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//Variáveis globais
#define NUMERO_DE_TENTATIVAS 5
int numero01, numero02;

int GerarNumeroSorteado()
{
	//Declaração de variáveis
	int numeroSorteado;

	//Loop para verificação do intervalo de números
	while (1)
	{
		//Solicita e armazena numero01
		printf_s("Digite o primeiro numero\n");
		scanf_s("%d", &numero01);

		//Solicita e armazena numero02
		printf_s("Digite o segundo numero\n");
		scanf_s("%d", &numero02);

		//Verifica se numero01 é menor que numero02
		if (numero01 > numero02)
		{
			printf_s("O primeiro numero deve ser menor que o segundo numero!\n");
			Sleep(2500);
			system("cls");
		}
		//Verifica se numero01 é igual a numero02
		else if (numero01 == numero02)
		{
			printf_s("Os numeros devem ser diferentes!\n");
			Sleep(2500);
			system("cls");
		}
		//Se os números forem válidos, sai do loop
		else
		{
			system("cls");
			break;
		}
	}

	// Inicializa o gerador de numeros aleatórios
	srand((unsigned int)time(NULL));

	//Gerar numero aleatorio entre numero01 e numero02
	numeroSorteado = rand() % (numero02 + 1 - numero01) + numero01;
	return numeroSorteado;
}

void ChutarNumero(int numeroSorteado)
{
	//Declaração de variáveis
	int numeroDigitado;

	//Loop para permitir tentativas infinitas de chute" até acertar
	for (int i = 1; i <= NUMERO_DE_TENTATIVAS; i++)
	{

		printf_s("Tentativa %d de %d\n", i, NUMERO_DE_TENTATIVAS);
		//Lê o número digitado
		scanf_s("%d", &numeroDigitado);

		//Verifica se o número digitado é igual ao número sorteado
		if (numeroDigitado == numeroSorteado)
		{
			printf_s("Parabens! Voce acertou o numero sorteado!\n\n");
			break;
		}
		//Verifica se o número digitado é maior que numero sorteado
		else if (numeroDigitado > numeroSorteado)
		{
			printf_s("O numero sorteado e menor que o numero digitado!\n\n");
		}
		//Verifica se o número digitado é menor que o numero sorteado
		else
		{
			printf_s("O numero sorteado e maior que o numero digitado!\n\n");
		}
	}
	return;
}

int main()
{
	int numeroSorteado;

	//Exibindo título do jogo
	printf_s("*********************************************\n");
	printf_s("*** Bem vindo ao jogo do numero sorteado! ***\n");
	printf_s("*********************************************\n");
	printf_s("\n\n");

	Sleep(1500);

	printf_s("Vamos primeiro escolher o intervalo de nosso numero sorteado!\n");

	Sleep(4000);

	system("cls");

	numeroSorteado = GerarNumeroSorteado();

	//Mensagem para chutar número
	printf_s("**********************************************\n");
	printf_s("*****Tente acertar o numero entre %d e %d*****\n", numero01, numero02);
	printf_s("**********************************************\n\n");

	ChutarNumero(numeroSorteado);

	return 0;
}