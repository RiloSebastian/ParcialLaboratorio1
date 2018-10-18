#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED
#include "cliente.h"
#include "afiche.h"

/** \brief imprime una lista de clientes y sus ventas
 * \param cliente Clientes cliente
 * \param Afiches Clientes afiche
 * \param len int cliente length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int informe_mostrar(Cliente* arrayClientes, Afiche* arrayAfiches,int tamanioCliente, int tamanioVenta);


/** \brief imprime un cliente y la venta por id
 * \param cliente Clientes cliente
 * \param Afiches Clientes afiche
 * \param len int cliente length
 * \param id int Clientes id
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int informe_mostrarUno(Cliente* arrayClientes, Afiche* arrayAfiches,int tamanioCliente, int tamanioVenta, int indice);

int informe_clienteMenosVentasACobrar(Cliente* arrayClientes, Afiche* arrayAfiches, int tamanioCliente, int tamanioVenta);

int informe_clienteMenosVentasCobradas(Cliente* arrayClientes, Afiche* arrayAfiches, int tamanioCliente, int tamanioVenta);

int informe_clienteMenosVentas(Cliente* arrayClientes, Afiche* arrayAfiches, int tamanioCliente, int tamanioVenta);

int informe_zonaConMasAfiches(Cliente* arrayClientes, Afiche* arrayAfiches, int tamanioCliente, int tamanioVenta);

int informe_clienteMenosAfiches(Cliente* arrayClientes, Afiche* arrayAfiches, int tamanioCliente, int tamanioVenta);

#endif // INFORME_H_INCLUDED
