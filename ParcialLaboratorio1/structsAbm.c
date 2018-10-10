#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structsAbm.h"
#include "validations.h"
#include "informes.h"

int structure_init(Clientes clientes[], Afiches afiche[],int len)
{
    int i;
    int flag=1;
    if(clientes != NULL)
    {
        for(i=0; i<len; i++)
        {
            clientes[i].isEmpty=1;
            afiche[i].aCobrar=1;
        }

        int id[5]= {1,2,3,4,5};
        char nombre[5][51]= {"Juan","Luis","Maria","Jose","emiliano"};
        char apellido[5][51]= {"juanes","alvarez","balbin","iglesias","johnson"};
        char cuit[5][15]= {"1234-5678","0147-8523","8520-1479","9865-3214","7530-1598"};
        int isEmpty[5]= {0,0,0,0,0};
        char nombreDeAfiche[5][100]= {"a","b","c","d","e"};
        int cantidadAfiches[5]= {140,250,560,780,120};
        char zona[5][51]= {"CABA","ZONA SUR","ZONA SUR","ZONA OESTE","CABA"};

        for(i=0; i<5; i++)
        {
            strncpy(clientes[i].nombre,nombre[i],sizeof(clientes[i].nombre));
            strncpy(clientes[i].apellido,apellido[i],sizeof(clientes[i].apellido));
            strncpy(clientes[i].cuit,cuit[i],sizeof(clientes[i].cuit));
            strncpy(afiche[i].nombreDeAfiche,nombreDeAfiche[i],sizeof(afiche[i].nombreDeAfiche));
            strncpy(afiche[i].zona,zona[i],sizeof(afiche[i].zona));
            afiche[i].cantidadAfiches=cantidadAfiches[i];
            afiche[i].aCobrar=isEmpty[i];
            clientes[i].id=id[i];
            clientes[i].isEmpty=isEmpty[i];
        }

    }
    return flag;
}

int structure_isEmpty(Clientes cliente[], int len)
{
    int notEmpty=0;
    int i;

    if(cliente != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(cliente[i].isEmpty==0)
            {
                notEmpty++;
            }
        }
    }
    return notEmpty;
}

int search_closestEmptySpace(Clientes cliente[], int len)
{
    int index=0;
    int i;

    if(cliente != NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if((cliente[i].isEmpty)==1)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}

int structure_setId(Clientes cliente[], int len)
{
    static int id=0;
    static int flag=0;
    int i;
    if(cliente != NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(cliente[i].isEmpty==0 && cliente[i].id > id && flag==0)
            {
                id= cliente[i].id;
            }
        }
        id=id+1;
        flag=1;
    }

    return id;
}

int structure_findById(Clientes cliente[], int len, int id)
{
    int i;
    int index=-1;
    if(cliente!= NULL && len>0 && id< len && id > 0)
    {
        for(i=0; i<len; i++)
        {
            if(cliente[i].id==id && cliente[i].isEmpty==0)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}


int structure_add(Clientes cliente[],Afiches afiche[],int len)
{
    int flag=0;
    int index;
    int id;
    char nombre[51];
    char apellido[51];
    char cuit[15];
    int isEmpty=0;

    if(cliente != NULL && len >0)
    {
        index=search_closestEmptySpace(cliente,len);
        printf(" escribe el nombre: ");
        set_name(nombre,sizeof(nombre));
        printf(" escribe el apellido: ");
        set_name(apellido,sizeof(apellido));
        printf(" escribe el numero de cuit: ");
        set_string(cuit,sizeof(cuit));
        id=structure_setId(cliente,len);
        isEmpty=0;

        strncpy(cliente[index].nombre,nombre,sizeof(cliente[index].nombre));
        strncpy(cliente[index].apellido,apellido,sizeof(cliente[index].apellido));
        strncpy(cliente[index].cuit,cuit,sizeof(cliente[index].cuit));
        cliente[index].id=id;
        cliente[index].isEmpty=isEmpty;
        structure_printOne(cliente,afiche,len,index);
        flag=1;
    }

    return flag;
}

int structure_modify(Clientes cliente[], Afiches afiche[],int len)
{
    int flag=0;
    int option;
    char stay;
    int index;
    int id=0;
    char nombre[50];
    char apellido[50];
    char cuit[15];

    if(cliente != NULL && len >0)
    {
        printf(" elige un cliente por id para modificar: ");
        id=set_marginInt(id,1,len);
        index=structure_findById(cliente,len,id);
        if(index> -1)
        {
            do
            {
                printf(" que quieres cambiar?\n nombre(1)  apellido(2)  cuit(3)\n option: ");
                option=set_marginInt(option,1,3);
                switch(option)
                {
                case 1:

                    printf(" ingresa el nuevo nombre: ");
                    set_name(nombre,sizeof(nombre));
                    strncpy(cliente[index].nombre,nombre,sizeof(cliente[index].nombre));
                    break;
                case 2:
                    printf(" ingresa el nuevo apellido: ");
                    set_name(apellido,sizeof(apellido));
                    strncpy(cliente[index].apellido,apellido,sizeof(cliente[index].apellido));
                    break;
                case 3:
                    printf(" ingresa el nuevo cuit: ");
                    set_string(cuit,sizeof(cuit));
                    strncpy(cliente[index].cuit,cuit,sizeof(cliente[index].cuit));
                    break;
                default :
                    printf(" This option doesn't exist.\n");
                    break;
                }
                structure_printOne(cliente,afiche,len,index);
                printf("\n Do you want to make more changes?(s to stay): ");
                stay=getc(stdin);
            }
            while(stay == 's');
            flag=1;

        }
    }

    return flag;
}

int structure_remove(Clientes cliente[], int len)
{
    int flag=0;
    int id=0;
    int index=0;
    int isEmpty=1;
    printf(" elige un cliente por id para dar de baja: ");
    id=set_marginInt(id,1,len);
    index=structure_findById(cliente,len,id);
    if(index> -1)
    {
        cliente[index].isEmpty=isEmpty;
        flag=1;
    }

    return flag;
}


int structure_sell(Clientes cliente[], Afiches afiche[], int len)
{
    int flag=0;
    int id=0;
    int index=0;
    int option=0;
    char nombreDeAfiche[100];
    int aCobrar=0;
    int cantidadAfiches=0;

    if(cliente != NULL && afiche != NULL)
    {
        printf(" elige un cliente por id para que venda afiches: ");
        id=set_marginInt(id,1,len);
        index=structure_findById(cliente,len,id);
        if(index> -1)
        {
            printf(" escribe el nombre del afiche: ");
            set_name(nombreDeAfiche,sizeof(nombreDeAfiche));
            printf(" escribe la cantidad de afiches que va a vender: ");
            cantidadAfiches=set_marginInt(cantidadAfiches,1,1000);
            printf(" a que zona se va a enviar?\n CABA(1) ZONA SUR(2) ZONA OSTE(3)");
            option=set_marginInt(option,1,3);
            switch(option)
            {
            case 1:
                strncpy(afiche[index].zona,"CABA",sizeof(afiche[index].zona));
                break;
            case 2:
                strncpy(afiche[index].zona,"ZONA SUR",sizeof(afiche[index].zona));
                break;
            case 3:
                strncpy(afiche[index].zona,"ZONA OESTE",sizeof(afiche[index].zona));
                break;
            default :
                printf(" This option doesn't exist.\n");
                break;
            }

            strncpy(afiche[index].nombreDeAfiche,nombreDeAfiche,sizeof(afiche[index].nombreDeAfiche));
            afiche[index].cantidadAfiches=cantidadAfiches;
            afiche[index].id=id;
            afiche[index].aCobrar=aCobrar;
            structure_printOne(cliente,afiche,len,index);
            flag=1;

        }
    }
    return flag;
}


int structure_modifyAfiche(Clientes cliente[], Afiches afiche[],int len)
{
    int flag=0;
    int option;
    int zona=0;
    char stay;
    int index;
    int id=0;
    int cantidadAfiches=0;

    if(cliente != NULL && len >0)
    {
        printf(" elige un cliente por id para modificar su venta: ");
        id=set_marginInt(id,1,len);
        index=structure_findById(cliente,len,id);
        if(index> -1)
        {
            do
            {
                printf(" que quieres cambiar?\n cantidad De afiches(1)  zona(2) \n option: ");
                option=set_marginInt(option,1,2);
                switch(option)
                {
                case 1:
                    printf(" ingresa la nueva cantidad ");
                    cantidadAfiches=set_marginInt(cantidadAfiches,1,1000);
                    afiche[index].cantidadAfiches=cantidadAfiches;
                    break;
                case 2:
                    printf(" a que zona se va a enviar?\n CABA(1) ZONA SUR(2) ZONA OSTE(3)");
                    zona=set_marginInt(option,1,3);
                    if(zona == 1)
                    {
                        strncpy(afiche[index].zona,"CABA",sizeof(afiche[index].zona));
                    }
                    else if(zona == 2)
                    {
                        strncpy(afiche[index].zona,"ZONA SUR",sizeof(afiche[index].zona));
                    }
                    else if (zona ==3)
                    {
                        strncpy(afiche[index].zona,"ZONA OESTE",sizeof(afiche[index].zona));
                    }
                    break;
                default :
                    printf(" This option doesn't exist.\n");
                    break;
                }
                structure_printOne(cliente,afiche,len,index);
                printf("\n Do you want to make more changes?(s to stay): ");
                stay=getc(stdin);
            }
            while(stay == 's');
            flag=1;

        }
    }

    return flag;
}


int structure_CobrarAfiche(Clientes cliente[], Afiches afiche[], int len)
{
    int flag=0;
    int id=0;
    int index=0;
    int isEmpty=1;
    if(afiche != NULL)
    {
        printf(" elige un cliente por id para cobrar venta: ");
        id=set_marginInt(id,1,len);
        index=structure_findById(cliente,len,id);
        if(index> -1)
        {
            afiche[index].cantidadAfichesCobrados=afiche[index].cantidadAfichesCobrados+afiche[index].cantidadAfiches;
            afiche[index].aCobrar=isEmpty;
            flag=1;
        }
    }

    return flag;
}
