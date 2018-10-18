#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "afiche.h"
#include "informe.h"
#include "validaciones.h"

int Afiche_init(Afiche* arrayAfiches, int tamanioVentas)
{
    int i;
    int flag=1;
    if(arrayAfiches != NULL && tamanioVentas > 0)
    {
        for(i=0; i<tamanioVentas; i++)
        {
            arrayAfiches[i].isEmpty=COBRADO;
        }
        int idCliente[5]= {1,2,3,4,5};
        int idVenta[5]= {1,2,3,4,5};
        int isEmpty[5]= {0,0,0,0,0};
        char nombreDeAfiche[5][100]= {"a.jpg","b.jpg","c.jpg","d.jpg","e.jpg"};
        int cantidadAfiches[5]= {140,250,560,780,120};
        char zona[5][51]= {"CABA","ZONA SUR","ZONA SUR","ZONA OESTE","CABA"};
        for(i=0; i<5; i++)
        {
            arrayAfiches[i].idCliente=idCliente[i];
            arrayAfiches[i].idVenta=idVenta[i];
            strncpy(arrayAfiches[i].nombreDeAfiche,nombreDeAfiche[i],sizeof(arrayAfiches[i].nombreDeAfiche));
            strncpy(arrayAfiches[i].zona,zona[i],sizeof(arrayAfiches[i].zona));
            arrayAfiches[i].cantidadAfiches=cantidadAfiches[i];
            arrayAfiches[i].isEmpty=isEmpty[i];
        }
    }
    return flag;
}

int afiche_isEmpty(Afiche* arrayAfiches, int tamanioVentas)
{
    int notEmpty=0;
    int i;
    if(arrayAfiches != NULL && tamanioVentas>0)
    {
        for(i=0; i<tamanioVentas; i++)
        {
            if(arrayAfiches[i].isEmpty==0)
            {
                notEmpty++;
            }
        }
    }
    return notEmpty;
}

int afiche_emptySpace(Afiche* arrayAfiches, int tamanioVentas)
{
    int index=0;
    int i;
    if(arrayAfiches != NULL && tamanioVentas>0)
    {
        for(i=0; i<tamanioVentas; i++)
        {
            if((arrayAfiches[i].isEmpty)==1)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}

int afiche_setIdVenta(Afiche* arrayAfiches, int tamanioVentas)
{
    static int id=0;
    static int flag=0;
    int i;
    if(arrayAfiches != NULL && tamanioVentas>0)
    {
        for(i=0; i<tamanioVentas; i++)
        {
            if(arrayAfiches[i].isEmpty==0 && arrayAfiches[i].idVenta > id && flag==0)
            {
                id= arrayAfiches[i].idVenta;
            }
        }
        id=id+1;
        flag=1;
    }
    return id;
}

int afiche_findById(Afiche* arrayAfiches, int tamanioVentas, int id)
{
    int i;
    int index=-1;
    if(arrayAfiches!= NULL && tamanioVentas>0 && id< tamanioVentas && id > 0)
    {
        for(i=0; i<tamanioVentas; i++)
        {
            if(arrayAfiches[i].idCliente==id && arrayAfiches[i].isEmpty==0)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}

int afiche_add(Afiche* arrayAfiches, void* arrayClientes, int id, int tamanioClientes, int tamanioVentas)
{
    Cliente* auxArrayclientes=arrayClientes;
    int flag=0;
    int idCliente=0;
    int idVenta=0;
    int option=0;
    int index=-1;
    int indice=-1;
    char nombreDeAfiche[100];
    int aCobrar=0;
    int cantidadAfiches=0;
    if(arrayAfiches != NULL &&  auxArrayclientes != NULL && tamanioVentas > 0 && tamanioClientes>0 && id>0)
    {
        index=cliente_findById(auxArrayclientes,LIMITE_CLIENTE,id);

        if(index> -1)
        {
            indice=afiche_emptySpace(arrayAfiches,tamanioVentas);
            idCliente=id;
            idVenta=afiche_setIdVenta(arrayAfiches,tamanioVentas);
            set_nombre(" escribe el nombre del Afiche: ",nombreDeAfiche,sizeof(nombreDeAfiche));
            cantidadAfiches=set_margenEntero(" escribe la cantidad de afiches que va a vender: ",cantidadAfiches,1,tamanioVentas);
            option=set_margenEntero(" a que zona se va a enviar?\n CABA(1) ZONA SUR(2) ZONA OSTE(3)\n opcion: ",option,1,3);
            switch(option)
            {
            case 1:
                strncpy(arrayAfiches[indice].zona,"CABA",sizeof(arrayAfiches[indice].zona));
                break;
            case 2:
                strncpy(arrayAfiches[indice].zona,"ZONA SUR",sizeof(arrayAfiches[indice].zona));
                break;
            case 3:
                strncpy(arrayAfiches[indice].zona,"ZONA OESTE",sizeof(arrayAfiches[indice].zona));
                break;
            default :
                printf(" This option doesn't exist.\n");
                break;
            }
            strncpy(arrayAfiches[indice].nombreDeAfiche,nombreDeAfiche,sizeof(arrayAfiches[indice].nombreDeAfiche));
            arrayAfiches[indice].cantidadAfiches=cantidadAfiches;
            arrayAfiches[indice].idCliente=idCliente;
            arrayAfiches[indice].idVenta=idVenta;
            arrayAfiches[indice].isEmpty=aCobrar;
            auxArrayclientes[index].ventasACobrar++;
            informe_mostrarUno(auxArrayclientes,arrayAfiches,tamanioClientes,tamanioVentas,index);
            flag=1;
        }
    }
    return flag;
}


int afiche_modify(Afiche* arrayAfiches, void* arrayClientes, int id, int tamanioClientes, int tamanioVentas)
{
    Cliente* auxArrayClientes=arrayClientes;
    int flag=0;
    int option;
    int zona=0;
    char stay;
    int indiceDeVenta=-1;
    int indiceDeCliente=-1;
    int cantidadAfiches=0;
    if(arrayAfiches != NULL && auxArrayClientes!= NULL && tamanioVentas>0 && tamanioClientes>0 && id>0)
    {
        indiceDeVenta=afiche_findById(arrayAfiches,tamanioVentas,id);
        indiceDeCliente=cliente_findById(auxArrayClientes,tamanioClientes,arrayAfiches[indiceDeVenta].idCliente);
        if(indiceDeVenta > -1 && indiceDeCliente > -1)
        {
            do
            {
                option=set_margenEntero(" que quieres cambiar?\n cantidad De afiches(1)  zona(2) \n opcion: ",option,1,2);
                switch(option)
                {
                case 1:
                    cantidadAfiches=set_margenEntero(" ingresa la nueva cantidad ",cantidadAfiches,1,tamanioVentas);
                    arrayAfiches[indiceDeVenta].cantidadAfiches=cantidadAfiches;
                    break;
                case 2:
                    zona=set_margenEntero(" a que zona se va a enviar?\n CABA(1) ZONA SUR(2) ZONA OSTE(3)\n opcion: ",option,1,3);
                    if(zona == 1)
                    {
                        strncpy(arrayAfiches[indiceDeVenta].zona,"CABA",sizeof(arrayAfiches[indiceDeVenta].zona));
                    }
                    else if(zona == 2)
                    {
                        strncpy(arrayAfiches[indiceDeVenta].zona,"ZONA SUR",sizeof(arrayAfiches[indiceDeVenta].zona));
                    }
                    else if (zona ==3)
                    {
                        strncpy(arrayAfiches[indiceDeVenta].zona,"ZONA OESTE",sizeof(arrayAfiches[indiceDeVenta].zona));
                    }
                    break;
                default :
                    printf(" esta opcion no existe.\n");
                    break;
                }
                informe_mostrarUno(auxArrayClientes,arrayAfiches,tamanioClientes,tamanioVentas,indiceDeCliente);
                printf("\n quieres hacer mas cambios en esta venta?('s' para quedarte): ");
                stay=getc(stdin);
            }
            while(stay == 's');
            flag=1;
        }
    }
    return flag;
}


int afiche_remove(Afiche* arrayAfiches, void* arrayClientes, int id, int tamanioClientes, int tamanioVentas)
{
    Cliente* auxArrayClientes=arrayClientes;
    int flag=0;
    int indiceDeVenta=-1;
    int indiceDeCliente=-1;
    int isEmpty=1;
    if(arrayAfiches != NULL && auxArrayClientes!= NULL && tamanioVentas>0 && tamanioClientes >0 && id>0)
    {
        indiceDeVenta=afiche_findById(arrayAfiches,tamanioVentas,id);
        indiceDeCliente=cliente_findById(auxArrayClientes,tamanioClientes,arrayAfiches[indiceDeVenta].idCliente);
        if(indiceDeVenta > -1 && indiceDeCliente > -1)
        {
            arrayAfiches[indiceDeVenta].cantidadAfichesCobrados=arrayAfiches[indiceDeVenta].cantidadAfichesCobrados+arrayAfiches[indiceDeVenta].cantidadAfiches;
            arrayAfiches[indiceDeVenta].isEmpty=isEmpty;
            flag=1;
            auxArrayClientes[indiceDeCliente].ventasACobrar--;
            auxArrayClientes[indiceDeCliente].ventasCobradas++;
        }
    }
    return flag;
}
