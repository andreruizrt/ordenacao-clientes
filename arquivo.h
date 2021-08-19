#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "LSE.h"

int escreve_arquivo_log(char *operacao, int qnt_nodos);
int escrever_arquivo_log_erro(char *mensagem_erro, char *operacao);
int escrever_arquivo_log_dados(LSE *lista);
void comparar_funcoes(LSE *lista, char *operacao, Cliente c);
void ler_arquivo(LSE *lista);