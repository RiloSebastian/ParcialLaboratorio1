#ifndef AFICHE_H_INCLUDED
#define AFICHE_H_INCLUDED
#define LIIMITE_VENTAS 1000
#define ACOBRAR 0
#define COBRADO 1

typedef struct
{
    int idVenta;
    int idCliente;
    int cantidadAfiches;
    char nombreDeAfiche[100];
    int cantidadAfichesCobrados;
    char zona[51];
    int isEmpty;
}Afiche;

int Afiche_init(Afiche* arrayAfiches, int tamanioVentas);

int afiche_isEmpty(Afiche* arrayAfiches, int tamanioVentas);

int afiche_emptySpace(Afiche* arrayAfiches, int tamanioVentas);

int afiche_setIdVenta(Afiche* arrayAfiches, int tamanioVentas);

int afiche_findById(Afiche* arrayAfiches, int tamanioVentas, int id);

int afiche_add(Afiche* arrayAfiches, void* arrayClientes, int id, int tamanioClientes, int tamanioVentas);

int afiche_modify(Afiche* arrayAfiches, void* arrayClientes, int id, int tamanioClientes, int tamanioVentas);

int afiche_remove(Afiche* arrayAfiches, void* arrayClientes, int id, int tamanioClientes, int tamanioVentas);

#endif // AFICHE_H_INCLUDED
