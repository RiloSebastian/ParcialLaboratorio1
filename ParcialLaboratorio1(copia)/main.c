#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "informe.h"
#include "afiche.h"
#include "validaciones.h"

int main()
{
    Cliente arrayClientes[LIMITE_CLIENTE];
    Afiche arrayAfiches[LIIMITE_VENTAS];
    int option;
    char opcionInforme;
    int flag=0;
    static int flagVentas=0;
    int id=-1;
    if((cliente_init(arrayClientes,LIMITE_CLIENTE)) && (Afiche_init(arrayAfiches,LIIMITE_VENTAS)))
    {

        do
        {
            if(cliente_isEmpty(arrayClientes,LIMITE_CLIENTE)>0 && cliente_isEmpty(arrayClientes,LIMITE_CLIENTE)<100)
            {
                flag=1;
                if(afiche_isEmpty(arrayAfiches,LIIMITE_VENTAS)>0 && afiche_isEmpty(arrayAfiches,LIIMITE_VENTAS)<1000)
                {
                    flagVentas=1;
                }
            }
            else
            {
                flagVentas=0;
            }


            printf("\n 1. alta de cliente\n"
                   " 2. modificacion de cliente\n"
                   " 3. baja de cliente\n"
                   " 4. alta de ventas\n"
                   " 5. modificacion de ventas\n"
                   " 6. baja de ventas\n"
                   " 7. informar\n"
                   " 8. salir\n");
            option=set_margenEntero("\n elige una opcion: ",option,1,8);
            switch(option)
            {
            case 1:
                if(cliente_isEmpty(arrayClientes,LIMITE_CLIENTE)!=100)
                {
                    if(cliente_add(arrayClientes,arrayAfiches,LIMITE_CLIENTE,LIIMITE_VENTAS))
                    {
                        printf("\n cliente agregado con exito");
                        flag=1;

                    }
                    else
                    {
                        printf(" Error. no se pudo agregar");
                    }
                }
                else
                {
                    printf(" No se pueden agregar mas clientes");
                }
                getc(stdin);
                break;
            case 2:
                if(flag==1)
                {
                    informe_mostrar(arrayClientes,arrayAfiches,LIMITE_CLIENTE,LIIMITE_VENTAS);
                    id=set_margenEntero(" elige un cliente por id para modificar: ",id,1,LIMITE_CLIENTE);
                    if(cliente_modify(arrayClientes,arrayAfiches,id,LIMITE_CLIENTE,LIIMITE_VENTAS))
                    {
                        printf("\n cliente modificado con exito");
                    }
                    else
                    {
                        printf(" el cliente que quieres modificar no existe");
                    }
                }
                else
                {
                    printf(" No puedes modificar si no hay clientes");
                }
                getc(stdin);
                break;
            case 3:
                if(flag==1)
                {
                    informe_mostrar(arrayClientes,arrayAfiches,LIMITE_CLIENTE,LIIMITE_VENTAS);
                    id=set_margenEntero(" elige un cliente por id para dar de baja: ",id,1,LIMITE_CLIENTE);
                    if(cliente_remove(arrayClientes,arrayAfiches,id,LIMITE_CLIENTE,LIIMITE_VENTAS))
                    {
                        printf("\n Cliente dado de baja con exito");
                    }
                    else
                    {
                        printf(" El cliente que quieres dar de baja no existe");
                    }
                }
                else
                {
                    printf(" No puedes dar de baja si no hay clientes");
                }
                getc(stdin);
                break;
            case 4:
                if(cliente_isEmpty(arrayClientes,LIMITE_CLIENTE)!=100)
                {
                    if(flag==1)
                    {
                        informe_mostrar(arrayClientes,arrayAfiches,LIMITE_CLIENTE,LIIMITE_VENTAS);
                        id=set_margenEntero(" elige un cliente por id para vender: ",id,1,LIMITE_CLIENTE);
                        if(afiche_add(arrayAfiches,arrayClientes,id,LIMITE_CLIENTE,LIIMITE_VENTAS))
                        {
                            printf("\n venta realizada con exito");
                        }
                        else
                        {
                            printf(" El cliente a quien se le va a vender no existe");
                        }
                    }
                    else
                    {
                        printf(" no puedes vender si no hay clientes");
                    }
                }
                else
                {
                    printf("no se pueden hacer mas ventas. \n");
                }
                getc(stdin);
                break;
            case 5:
                if(flag==1)
                {
                    informe_mostrar(arrayClientes,arrayAfiches,LIMITE_CLIENTE,LIIMITE_VENTAS);
                    id=set_margenEntero(" elige una venta por id para modificar: ",id,1,LIIMITE_VENTAS);
                    if(afiche_modify(arrayAfiches,arrayClientes,id,LIMITE_CLIENTE,LIIMITE_VENTAS))
                    {
                        printf("\n venta modificada con exito");
                    }
                    else
                    {
                        printf(" error en la venta");
                    }
                }
                else
                {
                    printf(" no podes modificar una venta si no hay clientes");
                }
                getc(stdin);
                break;
            case 6:
                if(flag==1)
                {
                    informe_mostrar(arrayClientes,arrayAfiches,LIMITE_CLIENTE,LIIMITE_VENTAS);
                    id=set_margenEntero(" elige una venta opr id para cobrar : ",id,1,LIIMITE_VENTAS);
                    if(afiche_remove(arrayAfiches,arrayClientes,id,LIMITE_CLIENTE,LIIMITE_VENTAS))
                    {
                        printf("\n Venta cobrada con exito");
                    }
                    else
                    {
                        printf(" La venta que quisiste cobrar no existe");
                    }
                }
                else
                {
                    printf(" No puedes cobrar una venta si no hay clientes");
                }
                getc(stdin);
                break;
            case 7:
                if(flag==1)
                {

                    printf(" a. cliente con menos ventas a cobrar\n"
                           " b. cliente con menos ventas cobradas\n"
                           " c. cliente con menos ventas\n"
                           " d. zona con mas afiches vendidos\n"
                           " e. cliente que compro menos afiches\n"
                           " f. cliente con mas afiches a cobrar\n"
                           " g. cantidad de clientes que compraron mas de 500 afiches\n"
                           " h. cantidad de afiches vendidos por cada una de las 3 zonas\n"
                           " i. cantidad de afiches vendidos promedio por cliente(suma de afiches/ suma de clientes)\n"
                           " j. listar ventas ordenadas por zonas\n"
                           " opcion: ");
                    opcionInforme=getc(stdin);
                    switch(opcionInforme)
                    {
                    case 'a':
                        if(flagVentas==1)
                        {
                            if(informe_clienteMenosVentasACobrar(arrayClientes,arrayAfiches,LIMITE_CLIENTE,LIIMITE_VENTAS))
                            {
                                printf("informe realizado con exito.");
                            }
                            else
                            {
                                printf("no hubo ventas a cobrar echas en ningun momento.");
                            }
                        }
                        else
                        {
                            printf("no podes listar si nunca hubo una venta");
                        }
                        getc(stdin);
                        break;
                    case 'b':
                        if(flagVentas==1)
                        {
                            if(informe_clienteMenosVentasCobradas(arrayClientes,arrayAfiches,LIMITE_CLIENTE,LIIMITE_VENTAS))
                            {
                                printf("informe realizado con exito.");
                            }
                            else
                            {
                                printf("no hubo ventas cobradas en ningun momento.");
                            }
                        }
                        else
                        {
                            printf("no podes listar si nunca hubo una venta");
                        }
                        getc(stdin);
                        break;
                    case 'c':
                        if(flagVentas==1)
                        {
                            if(informe_clienteMenosVentas(arrayClientes,arrayAfiches,LIMITE_CLIENTE,LIIMITE_VENTAS))
                            {
                                printf("informe realizado con exito.");
                            }
                            else
                            {
                                printf("no hubo ventas en ningun momento.");
                            }
                        }
                        else
                        {
                            printf("no podes listar si nunca hubo una venta");
                        }
                        getc(stdin);
                        break;
                    case 'd':
                        if(flagVentas==1)
                        {
                            if(informe_zonaConMasAfiches(arrayClientes,arrayAfiches,LIMITE_CLIENTE,LIIMITE_VENTAS))
                            {
                                printf("informe realizado con exito.");
                            }
                            else
                            {
                                printf("no hubo ventas en ningun momento.");
                            }
                        }
                        else
                        {
                            printf("no podes listar si nunca hubo una venta");
                        }
                        getc(stdin);
                        break;
                    case 'e':
                        if(flagVentas==1)
                        {
                            if(informe_clienteMenosAfiches(arrayClientes,arrayAfiches,LIMITE_CLIENTE,LIIMITE_VENTAS))
                            {
                                printf("informe realizado con exito.");
                            }
                            else
                            {
                                printf("no hubo ventas en ningun momento.");
                            }
                        }
                        else
                        {
                            printf("no podes listar si nunca hubo una venta");
                        }
                        getc(stdin);
                        break;
                    case 'f':
                        getc(stdin);
                        break;
                    case 'g':
                        getc(stdin);
                        break;
                    case 'h':
                        getc(stdin);
                        break;
                    case 'i':
                        getc(stdin);
                        break;
                    case 'j':
                        getc(stdin);
                        break;
                    default :
                        printf("no existe esta opcion");
                        getc(stdin);
                        break;
                    }
                }
                else
                {
                    printf(" no podes listar nada si no hay clientes");
                }
                getc(stdin);
                break;
            case 8:
                //salir
                break;
            default :
                printf("\n esta opcion no existe");
                getc(stdin);
                break;
            }
            system("clear");
        }
        while(option != 8);
    }
    return 0;
}
