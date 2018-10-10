#include <stdio.h>
#include <stdlib.h>
#include "structsAbm.h"
#include "validations.h"
#include "informes.h"
#define TAMANIOESTRUCTURA 100

int main()
{
    Clientes cliente[TAMANIOESTRUCTURA];
    Afiches afiche[TAMANIOESTRUCTURA];
    int option;
    int flag=0;

    if(structure_init(cliente,afiche,TAMANIOESTRUCTURA))
    {
        if(structure_isEmpty(cliente,TAMANIOESTRUCTURA)>0)
        {
            flag=1;
        }
        do
        {
            printf("\n 1. alta de cliente\n");
            printf(" 2. modificar cliente\n");
            printf(" 3. baja de cliente\n");
            printf(" 4. vender afiches\n");
            printf(" 5. editar venta\n");
            printf(" 6. cobrar venta\n");
            printf(" 7. imprimir\n");
            printf(" 8. salir\n");
            printf("\n elige una opcion: ");
            option=set_marginInt(option,1,8);
            switch(option)
            {
            case 1:
                if(structure_add(cliente,afiche,TAMANIOESTRUCTURA))
                {
                    printf("\n  cliente agregado con exito.\n");
                    flag=1;
                }
                else
                {
                    printf(" Error. no se pudo agregar \n");
                }
                break;
            case 2:
                if(flag==1)
                {
                    structure_print(cliente,afiche,TAMANIOESTRUCTURA);
                    if(structure_modify(cliente,afiche,TAMANIOESTRUCTURA))
                    {
                        printf("\n  cliente succesfully modified.\n");
                    }
                    else
                    {
                        printf(" the cliente you tried to modify doesn't exist.\n");
                    }
                }
                else
                {
                    printf(" You can't modify an cliente if you haven't added any yet.\n");
                }
                break;
            case 3:
                if(flag==1)
                {
                    structure_print(cliente,afiche,TAMANIOESTRUCTURA);
                    if(structure_remove(cliente,TAMANIOESTRUCTURA))
                    {
                        printf("\n  cliente succesfully removed.\n");
                    }
                    else
                    {
                        printf(" the cliente you tried to remove doesn't exist.\n");
                    }
                }
                else
                {
                    printf(" You can't remove an cliente if you haven't added any yet.\n");
                }
                break;
            case 4:
                if(flag==1)
                {
                    structure_print(cliente,afiche,TAMANIOESTRUCTURA);
                    if(structure_sell(cliente,afiche,TAMANIOESTRUCTURA))
                    {
                        printf("\n  afiche vendido.\n");
                    }
                    else
                    {
                        printf(" el cliente que va a vender no existe.\n");
                    }
                }
                else
                {
                    printf(" no podes vender arfiches si no hay clientes.\n");
                }
                break;
                case 5:
                if(flag==1)
                {
                    structure_print(cliente,afiche,TAMANIOESTRUCTURA);
                    if(structure_modifyAfiche(cliente,afiche,TAMANIOESTRUCTURA))
                    {
                        printf("\n  venta modificada con exito.\n");
                    }
                    else
                    {
                        printf(" error en la venta.\n");
                    }
                }
                else
                {
                    printf(" no podes modificar una venta si no hay clientes.\n");
                }
                break;
             case 6:
                 if(flag==1)
                {
                    structure_print(cliente,afiche,TAMANIOESTRUCTURA);
                    if(structure_CobrarAfiche(cliente,afiche,TAMANIOESTRUCTURA))
                    {
                        printf("\n  cliente succesfully removed.\n");
                    }
                    else
                    {
                        printf(" the cliente you tried to remove doesn't exist.\n");
                    }
                }
                else
                {
                    printf(" You can't remove an cliente if you haven't added any yet.\n");
                }
                break;
                break;
             case 7:
                 if(flag==1)
                 {
                     if(structure_print(cliente,afiche,TAMANIOESTRUCTURA))
                     {
                         printf("\n lista de clientes y ventas impresa cco exito.\n");
                     }
                     else
                     {
                         printf("\n ocurrio un error.\n");
                     }
                 }
                 else
                 {
                     printf(" no podes listar nada si no hay clientes.\n");
                 }
                 break;
            case 8:
                //salir
                break;
            default :
                printf("\n esta opcion no existe.\n");
                break;
            }
        }
        while(option!=8);
    }
    return 0;
}

