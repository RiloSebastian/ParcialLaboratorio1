#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structsAbm.h"
#include "validations.h"
#include "informes.h"

int structure_print(Clientes cliente[], Afiches afiche[],int len)
{
    int flag=0;
    int i;

    if(cliente != NULL && len >0)
    {

        for(i=0; i<len; i++)
        {
            structure_printOne(cliente,afiche,len,i);
            flag=1;
        }

    }
    return flag;
}

int structure_printOne(Clientes cliente[],Afiches afiche[],int len,int id)
{
    int flag=0;
    if(cliente != NULL && len>0 && id < len && id >= 0 && cliente[id].isEmpty==0)
    {
        printf("\n************************************************************************");
        printf("\n  id           nombre                apellido                 cuit        \n");
        printf("---------------------------------------------------------------------\n");
        printf(" %5d       %10s            %10s            %10s \n\n",cliente[id].id,cliente[id].nombre,cliente[id].apellido,
                cliente[id].cuit);

        if(afiche[id].aCobrar==0)
        {
            printf(" nombre de afiche         afiches vendidos              zona   \n");
            printf("---------------------------------------------------------------------\n");
            printf(" %10s                 %5d                   %10s\n", afiche[id].nombreDeAfiche, afiche[id].cantidadAfiches,
                    afiche[id].zona);
        }
        printf("************************************************************************\n\n\n");
            flag=1;
    }

    return flag;
}

