#include <stdio.h>

#include "cliente.h"
#include "LSE.h"

// Show the menu option to the user.
int print_menu()
{
	printf("1 - Cadastrar cliente\n2 - Ordenar Lista pelo CPF\n");
	printf("3 - Desalocar Lista\n4 - Sair\n");
	printf("Escolha a opcao: ");
}

// Compare the input with the functions.
int menu(LSE *lista)
{
	int option;

	while (1)
	{
		print_menu();
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			// cadastro de clientes(final e inicio da lista);
			printf("[*] Cadastrar cliente\n");

			if (lista == NULL)
			{
				lista = criarLSE();
			}

			Cliente c = criarCliente();
			inserirFinalLSE(lista, c);

			break;
		case 2:
			//Ordenar lista
			printf("[*] Ordenando Lista de Cliente pelo CPF\n");

			break;
		case 3:
			//Desalocar lista
			printf("[*] Desalocando lista\n");

			break;
		case 4:
			//opcao de sair
			printf("[*] Saindo...\n");
			exit(0);
			break;

		default:
			printf("Opcao Invalida!\n");
			break;
		}
	}
}

int main()
{
	LSE *lista;
	lista = criarLSE();

	menu(lista);

	ler_arquivo(lista);

	desalocarListaLSE(lista);

	return 0;
}
