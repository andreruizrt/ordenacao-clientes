#include <stdlib.h>
#include <stdio.h>

#include "cliente.h"
#include "LSE.h"

// • Criação da estrutura de dados
LSE *criarLSE()
{
    LSE *li;
    li = (LSE *)malloc(sizeof(LSE));
    if (li != NULL)
    {
        li->inicio = NULL;
    }
    return li;
}

// • Destruição e desalocação de memória utilizada pela estrutura
int desalocarListaLSE(LSE *lista)
{
    printf("[*] Desalocando lista\n");

    No *atual = lista->inicio;
    while (atual != NULL)
    {
        No *t = atual->proximo;
        free(atual);
        atual = t;
    }
    return 0;
}

// • Obtenção do tamanho da lista
int obterTamanhoListaLSE(LSE *lista)
{
    int contador = 0;

    No *aux = lista->inicio;
    while (aux != NULL)
    {
        contador++;
        aux = aux->proximo;
    }
    return contador;
}

// • Obtenção da posição da lista em que um cliente encontra-se cadastrado
int obterPosicaoListaClienteCadastradoLSE(LSE *lista, int id)
{
    int posicao = 0;

    LSE *atual = lista;
    while (lista != NULL && lista->inicio->cliente.id == id)
    {
        LSE *t = atual->inicio->proximo;
        posicao++;
        atual = t;
    }

    return posicao;
}

// • Inserção de clientes no início da lista
int inserirInicioLSE(LSE *lista, Cliente c)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->cliente = c;
        novo->proximo = lista->inicio;
        lista->inicio = novo;

        return 0;
    }
    else
    {
        printf("Error!\n");
        return 1;
    }
}

// • Inserção de clientes no final da lista
int inserirFinalLSE(LSE *lista, Cliente c)
{
    No *novo = (No *)malloc(sizeof(No));
    int counter = 0;

    if (novo == NULL)
    {
        return 1;
    }

    novo->cliente = c;
    novo->proximo = NULL;

    No *aux = lista->inicio;
    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
        counter++;
    }

    aux->proximo = novo;

    printf("[*] Cliente inserido no final da lista!\n\n");
    return counter;
}

// • Inserção de clientes em uma determinada posição
int inserirDeterminadaPosicaoLSE(LSE *lista, Cliente c, int posicao)
{
    int contador = 0;
    No *ponteiro_anterior;

    No *ponteiro_atual = lista->inicio;
    while (ponteiro_atual != NULL)
    {
        No *ponteiro_futuro;
        ponteiro_futuro = ponteiro_atual->proximo;
        if (contador == posicao)
        {
            No *novo = (No *)malloc(sizeof(No));
            novo->cliente = c;
            novo->proximo = ponteiro_atual;
            ponteiro_anterior->proximo = novo;
            return 0;
        }
        ponteiro_anterior = ponteiro_atual;
        ponteiro_atual = ponteiro_futuro;
        contador++;
    }
    return 1;
}

// • Busca de cliente através do CPF
// • Impressão dos dados de um determinado cliente através do CPF
int buscarClienteLSE(LSE *lista, int cpf)
{
    No *aux = lista->inicio;

    if (aux == NULL)
    {
        return 1;
    }

    while (aux != NULL)
    {
        if (aux->cliente.cpf == cpf)
        {
            imprimirDadosCliente(&aux->cliente);
            return 0;
        }
        aux = aux->proximo;
    }
    return 1;
}

int removerClienteLSE(LSE *lista, int cpf)
{

    if (lista->inicio == NULL)
    {
        printf("Nenhum cliente cadastrado!\n");
        return 1;
    }

    if (obterTamanhoListaLSE(lista) == 1)
    {
        lista->inicio = NULL;
        return 0;
    }

    No *atual, *anterior;
    atual = lista->inicio;
    anterior = lista->inicio;

    while (atual != NULL)
    {
        if (atual->cliente.cpf == cpf)
        {
            printf("[*] Removendo cliente: %s\n", atual->cliente.nome);

            if (atual == lista->inicio)
            {
                lista->inicio = lista->inicio->proximo;
                free(atual);
                return 0;
            }
            else
            {
                if (atual->proximo == NULL)
                {
                    atual = anterior;
                }

                anterior->proximo = atual->proximo;
                free(atual);
                return 0;
            }
        }
        else
        {
            anterior = atual;
            atual = atual->proximo;
        }
    }
    return 1;
}

// • Substituição dos valores de um cliente em determinada posição da lista
int substituirValoresClienteLSE(LSE *lista, int cpf)
{

    No *aux = lista->inicio;
    while (aux != NULL)
    {
        if (aux->cliente.cpf == cpf)
        {
            Cliente c;
            c = criarCliente();
            aux->cliente = c;
            return 0;
        }
        aux = aux->proximo;
    }
    return 1;
}

// • Impressão dos dados de todos os clientes cadastrados na lista
int imprimirDadosDaListaLSE(LSE *lista)
{
    No *aux = lista->inicio;
    while (aux != NULL)
    {
        imprimirDadosCliente(&aux->cliente);
        // printf("Proximo = %d\n", aux->proximo);
        aux = aux->proximo;
    }
    printf("\n\n");
    return 0;
}
