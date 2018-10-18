#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "afiche.h"
#include "informe.h"

int informe_mostrar(Cliente* arrayClientes, Afiche* arrayAfiches,int tamanioCliente, int tamanioVenta)
{
    int flag=0;
    int i;

    if(arrayClientes != NULL && arrayAfiches!= NULL && tamanioCliente >0 && tamanioVenta >0)
    {

        for(i=0; i<tamanioCliente; i++)
        {
            informe_mostrarUno(arrayClientes,arrayAfiches,tamanioCliente,tamanioVenta,i);
            flag=1;
        }

    }
    return flag;
}

int informe_mostrarUno(Cliente* arrayClientes, Afiche* arrayAfiches,int tamanioCliente, int tamanioVenta, int indice)
{
    int flag=0;
    int i;
    if(arrayClientes != NULL && tamanioCliente >0 && indice < tamanioCliente && tamanioVenta >0 && indice < tamanioVenta && indice >= 0)
    {
        if(arrayClientes[indice].isEmpty==0)
        {
            printf("\n ************************************************************************"
                   "\n *   id           nombre                apellido              cuit      *"
                   "\n *----------------------------------------------------------------------*"
                   "\n *%5d       %10s             %10s            %10s   *",arrayClientes[indice].id,
                   arrayClientes[indice].nombre,arrayClientes[indice].apellido,arrayClientes[indice].cuit);
            printf("\n ************************************************************************"
                   "\n *  id de venta    nombre de imagen      afiches vendidos      zona     *"
                   "\n *----------------------------------------------------------------------*");
            for(i=0; i<tamanioVenta; i++)
            {
                if(arrayClientes[indice].id==arrayAfiches[i].idCliente && arrayAfiches[i].isEmpty==0)
                {
                    printf("\n *%5d             %10s                %5d       %10s    *",arrayAfiches[i].idVenta,arrayAfiches[i].nombreDeAfiche,
                           arrayAfiches[i].cantidadAfiches,arrayAfiches[i].zona);
                }
            }
            printf("\n ************************************************************************\n\n\n");
        }

        flag=1;
    }

    return flag;
}

int informe_clienteMenosVentasACobrar(Cliente* arrayClientes, Afiche* arrayAfiches, int tamanioCliente, int tamanioVenta)
{
    int flag=0;
    int i;
    int j=0;
    int minimo=0;
    int indiceCliente[tamanioCliente];
    int contadorDeIndice=0;
    if(arrayClientes != NULL && arrayAfiches!= NULL && tamanioCliente >0 && tamanioVenta >0)
    {
        for(i=0; i<tamanioCliente; i++)
        {
            if((flag==0 || arrayClientes[i].ventasACobrar<minimo) && arrayClientes[i].ventasACobrar!=0 && arrayClientes[i].isEmpty==0)
            {
                minimo=arrayClientes[i].ventasACobrar;
                flag=1;
            }
        }
        if(minimo != 0 )
        {
            for(i=0; i<tamanioCliente; i++)
            {
                if(arrayClientes[i].ventasACobrar==minimo && arrayClientes[i].isEmpty==0)
                {
                    indiceCliente[j]=i;
                    contadorDeIndice++;
                    j++;
                }
            }
            printf("el minimo de ventas a cobrar es: %d\n esta cantidad de ventas a cobrar esta en: \n", minimo);
            for(i=0; i<contadorDeIndice; i++)
            {
                informe_mostrarUno(arrayClientes,arrayAfiches,tamanioCliente,tamanioVenta,indiceCliente[i]);
            }
        }
    }
    return flag;
}


int informe_clienteMenosVentasCobradas(Cliente* arrayClientes, Afiche* arrayAfiches, int tamanioCliente, int tamanioVenta)
{
    int flag=0;
    int i;
    int j=0;
    int minimo=0;
    int indiceCliente[tamanioCliente];
    int contadorDeIndice=0;
    if(arrayClientes != NULL && arrayAfiches!= NULL && tamanioCliente >0 && tamanioVenta >0)
    {
        for(i=0; i<tamanioCliente; i++)
        {
            if((flag==0 || arrayClientes[i].ventasCobradas<minimo) && arrayClientes[i].ventasCobradas!=0 && arrayClientes[i].isEmpty==0)
            {
                minimo=arrayClientes[i].ventasCobradas;
                flag=1;
            }
        }
        if(minimo != 0 )
        {
            for(i=0; i<tamanioCliente; i++)
            {
                if(arrayClientes[i].ventasCobradas==minimo && arrayClientes[i].isEmpty==0)
                {
                    indiceCliente[j]=i;
                    contadorDeIndice++;
                    j++;
                }
            }
            printf("el minimo de ventas cobradas es: %d\n esta cantidad de ventas cobradas esta en: \n", minimo);
            for(i=0; i<contadorDeIndice; i++)
            {
                informe_mostrarUno(arrayClientes,arrayAfiches,tamanioCliente,tamanioVenta,indiceCliente[i]);
            }
        }
    }
    return flag;
}

int informe_clienteMenosVentas(Cliente* arrayClientes, Afiche* arrayAfiches, int tamanioCliente, int tamanioVenta)
{
    int flag=0;
    int i;
    int j=0;
    int minimo=0;
    int indiceCliente[tamanioCliente];
    int contadorDeIndice=0;
    int totalDeVentasCliente;
    if(arrayClientes != NULL && arrayAfiches!= NULL && tamanioCliente >0 && tamanioVenta >0)
    {
        for(i=0; i<tamanioCliente; i++)
        {
            totalDeVentasCliente=arrayClientes[i].ventasCobradas+arrayClientes[i].ventasACobrar;
            if((flag==0 || totalDeVentasCliente<minimo) && totalDeVentasCliente!=0 && arrayClientes[i].isEmpty==0)
            {
                minimo=totalDeVentasCliente;
                flag=1;
            }
        }
        if(minimo != 0 )
        {
            for(i=0; i<tamanioCliente; i++)
            {
                totalDeVentasCliente=arrayClientes[i].ventasCobradas+arrayClientes[i].ventasACobrar;
                if(totalDeVentasCliente==minimo && arrayClientes[i].isEmpty==0)
                {
                    indiceCliente[j]=i;
                    contadorDeIndice++;
                    j++;
                }
            }
            printf("el minimo de ventas es: %d\n esta cantidad de ventas esta en: \n", minimo);
            for(i=0; i<contadorDeIndice; i++)
            {
                informe_mostrarUno(arrayClientes,arrayAfiches,tamanioCliente,tamanioVenta,indiceCliente[i]);
            }
        }
    }
    return flag;
}

int informe_zonaConMasAfiches(Cliente* arrayClientes, Afiche* arrayAfiches, int tamanioCliente, int tamanioVenta)
{
    int flag=0;
    int i;
    int cantidadAfichesCABA=0;
    int cantidadAfichesZonaSur=0;
    int cantidadAfichesZonaOeste=0;
    if(arrayClientes != NULL && arrayAfiches!= NULL && tamanioCliente >0 && tamanioVenta >0)
    {
        for(i=0; i<tamanioVenta; i++)
        {
            if(strcmp(arrayAfiches[i].zona,"CABA")==0 && arrayAfiches[i].isEmpty==0)
            {
                cantidadAfichesCABA=cantidadAfichesCABA+arrayAfiches[i].cantidadAfiches;
            }
            else if(strcmp(arrayAfiches[i].zona,"ZONA SUR")==0 && arrayAfiches[i].isEmpty==0)
            {
                cantidadAfichesZonaSur=cantidadAfichesZonaSur+arrayAfiches[i].cantidadAfiches;
            }
            else if(strcmp(arrayAfiches[i].zona,"ZONA OESTE")==0 && arrayAfiches[i].isEmpty==0)
            {
                cantidadAfichesZonaOeste=cantidadAfichesZonaOeste+arrayAfiches[i].cantidadAfiches;
            }
        }
        if(cantidadAfichesCABA>= cantidadAfichesZonaSur && cantidadAfichesCABA >= cantidadAfichesZonaOeste)
        {
            if(cantidadAfichesCABA == cantidadAfichesZonaSur)
            {
                printf("CABA y ZONA SUR tienen la misma cantidad de afiches vendidos\n");
            }
            else if(cantidadAfichesCABA == cantidadAfichesZonaOeste)
            {
                printf("CABA y ZONA OESTE tienen la misma cantidad de afiches vendidos\n");
            }
            else
            {
                printf(" CABA es la zona con mas afiches vendidos\n");
            }
        }
        else if(cantidadAfichesZonaSur> cantidadAfichesCABA && cantidadAfichesZonaSur >= cantidadAfichesZonaOeste)
        {
            if(cantidadAfichesCABA == cantidadAfichesZonaSur)
            {
                printf("ZONA SUR y ZONA OESTE tienen la misma cantidad de afiches vendidos\n");
            }
            else
            {
                printf(" ZONA SUR es la zona con mas afiches vendidos\n");
            }
        }
        else if(cantidadAfichesZonaOeste> cantidadAfichesCABA && cantidadAfichesZonaOeste > cantidadAfichesZonaSur)
        {
            printf("ZONA OESTE es la zona con mas afiches vendidos\n");
        }
        else
        {
            printf("las 3 zonas tienen la misma cantidad de afiches vendidos\n");
        }
        flag=1;
    }
    return flag;
}

int informe_clienteMenosAfiches(Cliente* arrayClientes, Afiche* arrayAfiches, int tamanioCliente, int tamanioVenta)
{
    int flag=0;
    int i;
    int j;
    int minimo=0;
    int indiceCliente[tamanioCliente];
    int cantidadDeAfiches[tamanioCliente];
    int contadorDeIndice=0;
    if(arrayClientes != NULL && arrayAfiches!= NULL && tamanioCliente >0 && tamanioVenta >0)
    {
        for(i=0; i<tamanioCliente; i++)
        {
            if(arrayClientes[i].isEmpty==0)
            {
                for(j=0; j<tamanioVenta; j++)
                {
                    if(arrayAfiches[j].idCliente== arrayClientes[j].id && arrayAfiches[j].isEmpty==0)
                    {
                        cantidadDeAfiches[i]=cantidadDeAfiches[i]+arrayAfiches[j].cantidadAfiches;
                    }
                }
                indiceCliente[i]=i;
            }
        }
        for(i=0; i<tamanioCliente; i++)
        {
            if((flag==0 || cantidadDeAfiches[i]<minimo) && cantidadDeAfiches[i]!= 0 && arrayClientes[i].isEmpty==0)
            {
                minimo=cantidadDeAfiches[i];
                flag=1;
            }
        }
        if(minimo != 0 )
        {
            for(i=0; i<tamanioCliente; i++)
            {
                if(cantidadDeAfiches[i]==minimo && arrayClientes[i].isEmpty==0)
                {
                    contadorDeIndice++;
                    j++;
                }
            }
            printf("el minimo de afiches vendidos es: %d\n esta cantidad de afiches esta en: \n", minimo);
            for(i=0; i<contadorDeIndice; i++)
            {
                informe_mostrarUno(arrayClientes,arrayAfiches,tamanioCliente,tamanioVenta,indiceCliente[i]);
            }
        }
    }
    return flag;
}
