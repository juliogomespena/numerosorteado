#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//Variáveis globais
int numero01, numero02, numeroSorteado, limiteTentativas;
int acertou = 0;

void OpcoesDoJogo()
{
	//Loop para verificação das opcoes do jogo
	while (1)
	{
		printf_s("Qual sera o intervalo de numeros para sorteio?\n");
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
			Sleep(500);
			system("cls");

			//Define o número de tentativas
			while (1)
			{
				//Solicita e armazena o número de tentativas
				printf_s("Quantas tentativas deseja ter?\n");
				scanf_s("%d", &limiteTentativas);

				//Verifica se o número de tentativas é maior que 0
				if (limiteTentativas <= 0)
				{
					printf_s("O numero de tentativas deve ser maior que 0!\n");
					Sleep(2500);
					system("cls");
				}
				else
				{
					break;
				}
			}
			break;
		}
	}

	// Inicializa o gerador de numeros aleatórios
	srand((unsigned int)time(NULL));

	//Gerar numero aleatorio entre numero01 e numero02
	numeroSorteado = rand() % (numero02 + 1 - numero01) + numero01;

	Sleep(500);
	system("cls");

	return;
}

void ChutarNumero(int numeroSorteado)
{
	//Declaração de variáveis
	int numeroDigitado;
	int tentativa = 1;

	//Loop para permitir tentativas infinitas de chute" até acertar
	while(tentativa <= limiteTentativas)
	{
		printf_s("Tentativa %d de %d\n", tentativa, limiteTentativas);
		//Lê o número digitado
		scanf_s("%d", &numeroDigitado);

		if (numeroDigitado < numero01 || numeroDigitado > numero02)
		{
			printf_s("O numero digitado deve estar entre %d e %d.\nVou te dar uma tentativa extra!\n\n", numero01, numero02);
			continue;
		}

		//Verifica se o número digitado é igual ao número sorteado
		if (numeroDigitado == numeroSorteado)
		{
			acertou = 1;
			tentativa++;
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

		tentativa++;
	}

	return;
}

int main()
{
	//Exibindo título do jogo
	printf_s("*********************************************\n");
	printf_s("*** Bem vindo ao jogo do numero sorteado! ***\n");
	printf_s("*********************************************\n");
	printf_s("\n\n");

	Sleep(1500);

	printf_s("Vamos primeiro escolher as opcoes do nosso jogo!\n");

	Sleep(4000);

	system("cls");

	//Chama a função que define as opcoes do jogo
	OpcoesDoJogo();

	//Mensagem para chutar número
	printf_s("**********************************************\n");
	printf_s("******Tente acertar o numero entre %d e %d******\n", numero01, numero02);
	printf_s("**********************************************\n\n");

	//Chama a função que permite o jogador chutar o número
	ChutarNumero(numeroSorteado);

	//Verifica se o jogador acertou o número sorteado
	if (acertou)
	{
		//Mensagem de parabéns
		printf_s("\n\n***************************************************\n");
		printf_s("*****Parabens! Voce acertou o numero sorteado!*****\n");
		printf_s("***************************************************\n");
	}
	else
	{
		//Mensagem de que o jogador não acertou
		printf_s("Voce nao acertou o numero sorteado!\n");
		printf_s("O numero sorteado era: %d\n", numeroSorteado);
	}

	return 0;
}