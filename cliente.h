typedef struct
{
    char nome[100];
    int id;
    int cpf;
} Cliente;

Cliente criarCliente();
void imprimirDadosCliente(Cliente *c);
