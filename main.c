#include <stdio.h>

#include "cliente.h"
#include "LSE.h"

// Show the menu option to the user.
int print_menu()
{
	printf("1 - Cadastrar cliente\n2 - Ordenar Lista pelo CPF\n");
	printf("3 - Imprimir lista toda\n4 - Desalocar Lista\n");
	printf("5 - Sair\nEscolha a opcao: ");
}

// Compare the input with the functions.
int menu(LSE *lista)
{
	int option = 1;

	while (option != 0)
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
			//Imprimir lista toda
			printf("[*] Imprimindo lista");
			imprimirDadosDaListaLSE(lista);
		case 4:
			//Desalocar lista
			printf("[*] Desalocando lista\n");
			// desalocarListaLSE(lista);
			break;
		case 5:
			//opcao de sair
			printf("[*] Saindo...\n");
			option = 0;
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

	ler_arquivo(lista);

	menu(lista);

	escrever_arquivo_log_dados(lista);
	
	desalocarListaLSE(lista);

	return 0;
}
