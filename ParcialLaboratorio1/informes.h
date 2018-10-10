#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/** \brief imprime una lista de clientes y sus ventas
 * \param cliente Clientes cliente
 * \param Afiches Clientes afiche
 * \param len int cliente length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int structure_print(Clientes cliente[],Afiches afiche[] , int len);


/** \brief imprime un cliente y la venta por id
 * \param cliente Clientes cliente
 * \param Afiches Clientes afiche
 * \param len int cliente length
 * \param id int Clientes id
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int structure_printOne(Clientes cliente[],Afiches afiche[],int len, int id);


#endif // INFORMES_H_INCLUDED
