#include <stdio.h>

#include "cliente.h"
#include "LSE.h"

int ordenar(LSE *lista)
{
	No *pi;
	No *pj;
	No *pfim = NULL;

	if (lista->inicio == NULL)
	{
		return 1;
	}
	for (pi = lista->inicio; pi->proximo != NULL; pi = pi->proximo)
	{
		for (pj = lista->inicio; pj->proximo != pfim; pj = pj->proximo)
		{
			No *aux = pj->proximo;
			if (pj->cliente.cpf > aux->cliente.cpf)
			{
				Cliente c = pj->cliente;
				pj->cliente = aux->cliente;
				aux->cliente = c;
			}
		}
		pfim = pj;
	}

	return 0;
}

// Show the menu option to the user.
int print_menu()
{
	printf("1 - Cadastrar cliente\n2 - Ordenar Lista pelo CPF\n");
	printf("3 - Imprimir lista toda\n4 - Sair\n");
	printf("Escolha a opcao: ");
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
			// cadastro de clientes no final da lista
			printf("[*] Cadastrar cliente\n");

			if(lista == NULL) {
				lista = criarLSE();
			}

			Cliente c = criarCliente();
			inserirFinalLSE(lista, c);

			break;
		case 2:
			//Ordenar lista
			printf("[*] Ordenando Lista de Cliente pelo CPF\n");
			int result = ordenar(lista);
			if (result != 1)
			{
				printf("[*] Lista ordenada com sucesso!\n\n");
			}
			else
			{
				printf("Erro ao ordenar a lista!\n");
			}
			break;
		case 3:
			//Imprimir lista toda
			printf("[*] Imprimindo lista\n");
			imprimirDadosDaListaLSE(lista);
			break;
		case 4:
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

	// ler_arquivo(lista);

	menu(lista);

	escrever_arquivo_log_dados(lista);

	desalocarListaLSE(lista);

	return 0;
}
