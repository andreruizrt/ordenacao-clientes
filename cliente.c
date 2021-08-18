#include "cliente.h"
#include <stdio.h>

Cliente criarCliente()
{
	Cliente c;

	printf("Digite o id: ");
	scanf("%d", &c.id);

	printf("Digite o nome: ");
	scanf("%s", c.nome);

	printf("Digite o Cpf: ");
	scanf("%d", &c.cpf);

	return c;
}

void imprimirDadosCliente(Cliente *c)
{
	printf("Nome: %s\n", c->nome);
	printf("ID: %d\n", c->id);
	printf("CPF: %d\n\n", c->cpf);
}
