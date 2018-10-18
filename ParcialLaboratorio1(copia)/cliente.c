#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "afiche.h"
#include "informe.h"
#include "validaciones.h"

int cliente_init(Cliente* arrayClientes, int tamanioClientes)
{
    int i;
    int flag=1;

    if(arrayClientes != NULL && tamanioClientes > 0)
    {
        for(i=0; i<tamanioClientes; i++)
        {
            arrayClientes[i].isEmpty=1;
            arrayClientes[i].ventasACobrar=0;
            arrayClientes[i].ventasCobradas=0;
        }
        int id[5]= {1,2,3,4,5};
        char nombre[5][51]= {"Juan","Luis","Maria","Jose","emiliano"};
        char apellido[5][51]= {"juanes","alvarez","balbin","iglesias","johnson"};
        char cuit[5][15]= {"1234-5678","0147-8523","8520-1479","9865-3214","7530-1598"};
        int ventasACobrar[5]= {1,1,1,1,1};
        int isEmpty[5]= {0,0,0,0,0};
        for(i=0; i<5; i++)
        {
            strncpy(arrayClientes[i].nombre,nombre[i],sizeof(arrayClientes[i].nombre));
            strncpy(arrayClientes[i].apellido,apellido[i],sizeof(arrayClientes[i].apellido));
            strncpy(arrayClientes[i].cuit,cuit[i],sizeof(arrayClientes[i].cuit));
            arrayClientes[i].id=id[i];
            arrayClientes[i].ventasACobrar=ventasACobrar[i];
            arrayClientes[i].isEmpty=isEmpty[i];
        }
    }
    return flag;
}

int cliente_isEmpty(Cliente* arrayClientes,int tamanioClientes)
{
    int notEmpty=0;
    int i;
    if(arrayClientes != NULL && tamanioClientes>0)
    {
        for(i=0; i<tamanioClientes; i++)
        {
            if(arrayClientes[i].isEmpty==0)
            {
                notEmpty++;
            }
        }
    }
    return notEmpty;
}

int cliente_emptySpace(Cliente* arrayClientes, int tamanioClientes)
{
    int index=0;
    int i;
    if(arrayClientes != NULL && tamanioClientes>0)
    {
        for(i=0; i<tamanioClientes; i++)
        {
            if((arrayClientes[i].isEmpty)==1)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}

int cliente_setId(Cliente* arrayClientes, int tamanioClientes)
{
    static int id=0;
    static int flag=0;
    int i;
    if(arrayClientes != NULL && tamanioClientes>0)
    {
        for(i=0; i<tamanioClientes; i++)
        {
            if(arrayClientes[i].isEmpty==0 && arrayClientes[i].id > id && flag==0)
            {
                id= arrayClientes[i].id;
            }
        }
        id=id+1;
        flag=1;
    }
    return id;
}

int cliente_findById(Cliente* arrayClientes, int tamanioClientes, int id)
{
    int i;
    int index=-1;
    if(arrayClientes!= NULL && tamanioClientes>0 && id< tamanioClientes && id > 0)
    {
        for(i=0; i<tamanioClientes; i++)
        {
            if(arrayClientes[i].id==id && arrayClientes[i].isEmpty==0)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}

int cliente_verificarCuit(Cliente* arrayClientes, void* arrayAfiches, char nombre[], char apellido[], char cuit[], int tamanioClientes, int tamanioVentas)
{
    Afiche* auxArrayAfiches=arrayAfiches;
    int flag=-1;
    int i;
    if(arrayClientes != NULL && nombre != NULL && apellido != NULL && cuit != NULL && tamanioClientes > 0)
    {
        for(i=0; i<tamanioClientes; i++)
        {
            if(arrayClientes[i].isEmpty==0 &&strcmp(arrayClientes[i].cuit,cuit)==0 && strcmp(arrayClientes[i].nombre,nombre)==0 && strcmp(arrayClientes[i].apellido,apellido)==0)
            {
                printf(" parece que el nuevo cliente es igual a:\n");
                informe_mostrarUno(arrayClientes,auxArrayAfiches,tamanioClientes,tamanioVentas,i);
                flag=set_margenEntero(" puede (1)borrar el primer cliente, (2)borrar el cliente actual o (3)modificar los datos del cliente: ",flag,1,3);
                if(flag==1)
                {
                    arrayClientes[i].isEmpty=1;
                }
                break;
            }
            else if(arrayClientes[i].isEmpty==0 && strcmp(arrayClientes[i].cuit,cuit)==0)
            {
                printf(" parece que este numero de cuit ya fue ingresado. por favor ingrese otro cuit.\n");
                flag=0;
                break;
            }
        }
    }
    return flag;
}

int cliente_add(Cliente* arrayClientes, void* arrayAfiches, int tamanioClientes, int tamanioVentas)
{
    Afiche* auxArrayafiches=arrayAfiches;
    int flag=0;
    int verificacionCuit=-2;
    int index;
    int id;
    char nombre[51];
    char apellido[51];
    char cuit[15];
    int isEmpty=0;
    if(arrayClientes != NULL && tamanioClientes >0)
    {
        do
        {
            index=cliente_emptySpace(arrayClientes,tamanioClientes);
            set_nombre(" escribe el nombre: ",nombre,sizeof(nombre));
            set_nombre(" escribe el apellido: ",apellido,sizeof(apellido));
            do
            {
                set_cuit(" escribe el numero de cuit: ",cuit,sizeof(cuit));
                verificacionCuit=cliente_verificarCuit(arrayClientes,arrayAfiches,nombre,apellido,cuit,tamanioClientes, tamanioVentas);
            }
            while(verificacionCuit==0);
            if(verificacionCuit!=2)
            {
                id=cliente_setId(arrayClientes,tamanioClientes);
                arrayClientes[index].id=id;
                arrayClientes[index].isEmpty=isEmpty;
            }
            printf("verificacionCuit: %d, index: %d\n",verificacionCuit,index);
        }
        while(verificacionCuit==3);
        strncpy(arrayClientes[index].nombre,nombre,sizeof(arrayClientes[index].nombre));
        strncpy(arrayClientes[index].apellido,apellido,sizeof(arrayClientes[index].apellido));
        strncpy(arrayClientes[index].cuit,cuit,sizeof(arrayClientes[index].cuit));
        informe_mostrarUno(arrayClientes, auxArrayafiches, tamanioClientes, tamanioVentas, index);
        flag=1;
    }
    return flag;
}

int cliente_modify(Cliente* arrayClientes, void* arrayAfiches, int id, int tamanioClientes, int tamanioVentas)
{
    Afiche* auxArrayAfiches= arrayAfiches;
    int flag=0;
    int option;
    int verificacionCuit=-2;
    char stay;
    int index;
    char nombre[50];
    char apellido[50];
    char cuit[15];
    if(arrayClientes != NULL && auxArrayAfiches != NULL && tamanioClientes >0 && tamanioVentas>0 && id>0)
    {
        index=cliente_findById(arrayClientes,tamanioClientes,id);
        if(index> -1)
        {
            do
            {
                option=set_margenEntero(" que quieres cambiar?\n nombre(1)  apellido(2)  cuit(3)\n option: ",option,1,3);
                switch(option)
                {
                case 1:
                    set_nombre(" ingresa el nuevo nombre: ",nombre,sizeof(nombre));
                    strncpy(arrayClientes[index].nombre,nombre,sizeof(arrayClientes[index].nombre));
                    break;
                case 2:
                    set_nombre(" ingresa el nuevo apellido: ",apellido,sizeof(apellido));
                    strncpy(arrayClientes[index].apellido,apellido,sizeof(arrayClientes[index].apellido));
                    break;
                case 3:
                    do
                    {
                        set_cuit(" escribe el numero de cuit: ",cuit,sizeof(cuit));
                        verificacionCuit=cliente_verificarCuit(arrayClientes,arrayAfiches,nombre,apellido,cuit,tamanioClientes,tamanioVentas);
                    }
                    while(verificacionCuit==0);
                    strncpy(arrayClientes[index].cuit,cuit,sizeof(arrayClientes[index].cuit));
                    break;
                default :
                    printf(" esta opcion no existe.\n");
                    break;
                }
                if(verificacionCuit==2)
                {
                    arrayClientes[index].isEmpty=1;
                    printf("se ha eliminado este cliente.\n");
                    stay='n';
                }
                else if(verificacionCuit < 2)
                {
                    informe_mostrarUno(arrayClientes,auxArrayAfiches,tamanioClientes,tamanioVentas,index);
                    printf("\n quieres hacer mas cambios en esta venta?('s' para quedarte): ");
                    stay=getc(stdin);
                    flag=1;
                }
            }
            while(stay == 's' || verificacionCuit==3);
        }
    }
    return flag;
}

int cliente_remove(Cliente* arrayClientes, void* arrayAfiches, int id, int tamanioClientes, int tamanioVentas)
{
    Afiche* auxArrayAfiches=arrayAfiches;
    int flag=0;
    int index=0;
    int isEmpty=1;
    int i;
    if(arrayClientes!= NULL && auxArrayAfiches!= NULL && tamanioClientes>0 && tamanioVentas>0 && id>0)
    {
        index=cliente_findById(arrayClientes,tamanioClientes,id);
        if(index> -1 && arrayClientes[index].isEmpty==0)
        {
            for(i=0; i<tamanioVentas; i++)
            {
                if(auxArrayAfiches[i].idCliente==arrayClientes[index].id && auxArrayAfiches[i].isEmpty==0)
                {
                    afiche_remove(auxArrayAfiches,arrayClientes,auxArrayAfiches[i].idVenta,tamanioClientes,tamanioVentas);
                }
            }
            arrayClientes[index].isEmpty=isEmpty;
            flag=1;
        }
    }

    return flag;
}
