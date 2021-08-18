typedef struct
{
    Cliente cliente;
    struct No *proximo;
} No;

typedef struct
{
    No *inicio;
} LSE;

LSE *criarLSE();
int inserirFinalLSE(LSE *lista, Cliente c);
int inserirInicioLSE(LSE *lista, Cliente c);
int buscarClienteLSE(LSE *lista, int cpf);
int removerClienteLSE(LSE *lista, int cpf);
int imprimirDadosDaListaLSE(LSE *lista);

int desalocarListaLSE(LSE *lista);
int obterTamanhoListaLSE(LSE *lista);
int obterPosicaoListaClienteCadastradoLSE(LSE *lista, int id);
int inserirDeterminadaPosicaoLSE(LSE *lista, Cliente c, int posicao);
int substituirValoresClienteLSE(LSE *lista, int cpf);
