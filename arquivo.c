#include "arquivo.h"

#define LOG_OPERACOES_PATH "log/log-operacoes.txt"
#define LOG_DADOS_PATH "log/log-conteudo-lista.txt"
#define OPERACOES_PATH "operacoes.txt"

int escrever_arquivo_log(char *operacao, int qnt_nodos)
{
    FILE *arq;
    arq = fopen(LOG_OPERACOES_PATH, "a");
    if (arq != NULL)
    {
        fprintf(arq, "LSE,%s,%i\n", operacao, qnt_nodos);
    }

    fclose(arq);
    return 0;
}

int escrever_arquivo_log_erro(char *mensagem_erro, char *operacao)
{
    FILE *arq;
    arq = fopen(LOG_OPERACOES_PATH, "a");
    if (arq != NULL)
    {
        fprintf(arq, "ERRO,LSE,%s,%s\n", operacao, mensagem_erro);
    }

    fclose(arq);
    return 0;
}

int escrever_arquivo_log_dados(LSE *lista)
{
    printf("[*] Salvando arquivo de dados\n");
    FILE *arq;
    arq = fopen(LOG_DADOS_PATH, "a");

    if (arq == NULL)
    {
        return 1;
    }

    No *p = lista->inicio;
    while (p != NULL)
    {
        No *t = p->proximo;
        fprintf(arq, "LSE,%s,CPF:%d\n", p->cliente.nome, p->cliente.cpf);
        p = t;
    }

    fclose(arq);
    return 0;
}

void comparar_funcoes(LSE *lista, char *operacao, Cliente c)
{
    if (strcmp(operacao, "inserir_inicio") == 0)
    {
        printf("Inserindo no Inicio...\n");
        inserirInicioLSE(lista, c);
        escrever_arquivo_log(operacao, 1);
    }
    else
    {
        if (strcmp(operacao, "inserir_final") == 0)
        {
            printf("Inserindo no Final...\n");
            int qnt_nodos = inserirFinalLSE(lista, c);
            if (qnt_nodos == 1)
            {
                escrever_arquivo_log_erro("Erro ao inserir no final!", operacao);
            }
            else
            {
                escrever_arquivo_log(operacao, qnt_nodos);
            }
        }
        else
        {
            if (strcmp(operacao, "remover") == 0)
            {
                printf("[*] Removendo Cliente pelo CPF:\n");

                int result = 1;

                // int result = removerClienteLSE(lista, c.id);

                if (result == 1)
                {
                    escrever_arquivo_log_erro("Nao foi possivel remover o cliente!", operacao);
                }
            }
            else
            {
                if (strcmp(operacao, "buscar") == 0)
                {
                    printf("[*] Buscando Cliente pelo CPF\n");

                    int result = buscarClienteLSE(lista, c.id);

                    if (result == 1)
                    {
                        escrever_arquivo_log_erro("Usuario nao encontrado!", operacao);
                    }
                }
                else
                {
                    if (strcmp(operacao, "obter_tamanho_lista") == 0)
                    {
                        printf("[*] Obtendo tamanho da Lista\n");

                        int tamanho = obterTamanhoListaLSE(lista);
                        printf("O tamanho atual da lista e: %d\n", tamanho);
                    }
                    else
                    {
                        escrever_arquivo_log_erro("Operacao nao cadastrada", operacao);
                    }
                }
            }
        }
    }
}

void ler_arquivo(LSE *lista)
{
    printf("[*] Carregando arquivo de operacoes\n");

    FILE *arq;
    const char *OPERACOES_FORMAT = "%[a-zA-Z _],%d ,%[a-zA-Z ],%d";
    char linha[100];
    char *result;
    int i;

    char operacao[100];
    Cliente c;

    arq = fopen(OPERACOES_PATH, "rt");

    if (arq == NULL)
    {
        printf("Problemas para abrir o arquivo!\n");
        return;
    }

    i = 1;
    while (!feof(arq))
    {
        result = fgets(linha, 100, arq);

        sscanf(linha, OPERACOES_FORMAT, operacao, &c.id, c.nome, &c.cpf);

        comparar_funcoes(lista, operacao, c);
    }

    printf("---------- Fim da Leitura ----------\n\n");
}
