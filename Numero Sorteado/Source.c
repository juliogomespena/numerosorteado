#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//Vari�veis globais
int numero01, numero02, numeroSorteado, limiteTentativas;
double pontos;
int acertou = 0;

void OpcoesDoJogo()
{
	//Loop para verifica��o das opcoes do jogo
	while (1)
	{
		printf_s("Qual sera o intervalo de numeros para sorteio?\n");
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
			Sleep(500);
			system("cls");

			//Define o n�mero de tentativas
			while (1)
			{
				//Solicita e armazena o n�mero de tentativas
				printf_s("Quantas tentativas deseja ter?\n");
				scanf_s("%d", &limiteTentativas);

				//Verifica se o n�mero de tentativas � maior que 0
				if (limiteTentativas <= 0)
				{
					printf_s("O numero de tentativas deve ser maior que 0!\n");
					Sleep(2500);
					system("cls");
				}
				else
				{
					pontos = (numero02 - numero01) * limiteTentativas * 10;
					break;
				}
			}
			break;
		}
	}

	// Inicializa o gerador de numeros aleat�rios
	srand((unsigned int)time(NULL));

	//Gerar numero aleatorio entre numero01 e numero02
	numeroSorteado = rand() % (numero02 + 1 - numero01) + numero01;

	Sleep(500);
	system("cls");

	return;
}

void ChutarNumero(int numeroSorteado)
{
	//Declara��o de vari�veis
	int numeroDigitado;
	int tentativa = 1;

	//Loop para permitir tentativas definidas de chute
	while(tentativa <= limiteTentativas)
	{
		if (pontos <= 0)
		{
			printf_s("Voce nao tem mais pontos para continuar!\n");
			printf_s("***********************************************************************\n\n\n");
			break;
		}

		//Exibe a pontua��o atual e a tentativa atual
		printf_s("Pontuacao atual: %.2f\n", pontos);
		printf_s("Tentativa %d de %d\n", tentativa, limiteTentativas);

		//L� o n�mero digitado
		printf_s("Chute: ");
		scanf_s("%d", &numeroDigitado);

		//Verifica se o n�mero digitado est� dentro do intervalo
		if (numeroDigitado < numero01 || numeroDigitado > numero02)
		{
			printf_s("O numero digitado deve estar entre %d e %d.\nVou te dar uma tentativa extra!\n", numero01, numero02);
			printf_s("***********************************************************************\n\n\n");
			continue;
		}

		//Verifica se o n�mero digitado � igual ao n�mero sorteado
		if (numeroDigitado == numeroSorteado)
		{
			acertou = 1;
			tentativa++;
			break;
		}
		//Verifica se o n�mero digitado � maior que numero sorteado
		else if (numeroDigitado > numeroSorteado)
		{
			printf_s("O numero sorteado e menor que o numero digitado!\n");
		}
		//Verifica se o n�mero digitado � menor que o numero sorteado
		else
		{
			printf_s("O numero sorteado e maior que o numero digitado!\n");
		}

		//Diminui a pontua��o do jogador
		double pontosPerdidos = abs(numeroSorteado - numeroDigitado) * ((numero02 - numero01) / (double)limiteTentativas);
		pontos = pontos - pontosPerdidos;
		printf_s("Voce perdeu %.2f pontos!\n", pontosPerdidos);

		printf_s("***********************************************************************\n\n\n");

		tentativa++;
	}

	return;
}

int main()
{
	//Exibindo t�tulo do jogo
	printf_s("*********************************************\n");
	printf_s("*** Bem vindo ao jogo do numero sorteado! ***\n");
	printf_s("*********************************************\n");
	printf_s("\n\n");

	Sleep(1500);

	printf_s("Vamos primeiro escolher as opcoes do nosso jogo!\n");

	Sleep(4000);

	system("cls");

	//Chama a fun��o que define as opcoes do jogo
	OpcoesDoJogo();

	//Mensagem para chutar n�mero
	printf_s("**********************************************\n");
	printf_s("******Tente acertar o numero entre %d e %d******\n", numero01, numero02);
	printf_s("**********************************************\n\n");

	//Chama a fun��o que permite o jogador chutar o n�mero
	ChutarNumero(numeroSorteado);

	//Verifica se o jogador acertou o n�mero sorteado
	if (acertou)
	{
		//Mensagem de parab�ns
		printf_s("\n\n***************************************************\n");
		printf_s("*****Parabens! Voce acertou o numero sorteado!*****\n");
		printf_s("***************************************************\n");
	}
	else
	{
		//Mensagem de que o jogador n�o acertou
		printf_s("Voce nao acertou o numero sorteado!\n");
		printf_s("O numero sorteado era: %d\n", numeroSorteado);
	}

	return 0;
}