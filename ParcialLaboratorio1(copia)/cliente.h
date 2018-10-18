#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#define LIMITE_CLIENTE 100

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char cuit[15];
    int ventasACobrar;
    int ventasCobradas;
    int isEmpty;

}Cliente;

int cliente_init(Cliente* arrayClientes, int tamanioClientes);

int cliente_isEmpty(Cliente* arrayClientes,int tamanioClientes);

int cliente_emptySpace(Cliente* arrayClientes, int tamanioClientes);

int cliente_setId(Cliente* arrayClientes, int tamanioClientes);

int cliente_findById(Cliente* arrayClientes, int tamanioClientes, int id);

int cliente_verificarCuit(Cliente* arrayClientes, void* arrayAfiches, char nombre[], char apellido[] , char cuit[], int tamanioClientes, int tamanioVentas);

int cliente_add(Cliente* arrayClientes, void* arrayAfiche, int tamanioClientes, int tamanioVentas);

int cliente_modify(Cliente* arrayClientes, void* arrayAfiche, int id, int tamanioClientes, int tamanioVentas);

int cliente_remove(Cliente* arrayClientes, void* arrayAfiches, int id, int tamanioClientes, int tamanioVentas);

#endif // CLIENTE_H_INCLUDED
