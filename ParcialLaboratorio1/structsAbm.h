#ifndef STRUCTSABM_H_INCLUDED
#define STRUCTSABM_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char cuit[15];
    int isEmpty;

}Clientes;

typedef struct
{
    int id;
    int cantidadAfiches;
    char nombreDeAfiche[100];
    int cantidadAfichesCobrados;
    char zona[51];
    int aCobrar;
}Afiches;



/** \brief To indicate that all position in the cliente are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the cliente
 * \param cliente estructura cliente of
 * \param Afiches structura de afiche
 * \param len int cliente length
 * \return int Return (0) si hay error [tamanio no valido o puntero nulo] - (1) si OK
 *
 */
int structure_init(Clientes clientes[], Afiches afiche[],int len);



/** \brief sees if there are clientes in the array
 * \param cliente estructura cliente
 * \param len int cliente length
 * \return int Return (0) si hay error [tamanio no valido o puntero nulo] - (1) si OK
 *
 */
int structure_isEmpty(Clientes clientes[], int len);


/** \brief sets the next id for the cliente
 * \param cliente estructura cliente
 * \param len int cliente length
 * \return int Return (0) si hay error [tamanio no valido o puntero nulo] - (1) si OK
 *
 */
int structure_setId(Clientes cliente[], int len);


/** \brief sets a new cliente
 * \param cliente estructura cliente
 * \param Afiches structura de afiche
 * \param len int cliente length
 * \return int Return (0) si hay error [tamanio no valido o puntero nulo] - (1) si OK
 *
 */
int structure_add(Clientes cliente[],Afiches afiche[] ,int len);

/** \brief finds an Clientes by id
 * \param cliente estructura cliente
 * \param len int cliente length
 * \param id int Clientes id
 * \return int Return (0) si hay error [tamanio no valido o puntero nulo] - (1) si OK
 *
 */
int structure_findById(Clientes cliente[] , int len, int id);


/** \brief busca el espacio mas cercano
 * \param cliente estructura cliente
 * \param len int cliente length
 * \return int Return (0) si hay error [tamanio no valido o puntero nulo] - (1) si OK
 *
 */
int search_closestEmptySpace(Clientes cliente[] ,int len);

/** \brief changes the cliente
 * \param cliente estructura cliente
 * \param Afiches structura de afiche
 * \return int Return (0) si hay error [tamanio no valido o puntero nulo] - (1) si OK
 *
 */
int structure_modify(Clientes cliente[], Afiches afiche[],int len);

/** \brief removes an Clientes by id
 * \param cliente estructura cliente
 * \param len int cliente length
 * \return int Return (0) si hay error [tamanio no valido o puntero nulo] - (1) si OK
 *
 */
int structure_remove(Clientes cliente[], int len);


/** \brief crea una venta de afiches
 * \param cliente estructura cliente
 * \param Afiches structura de afiche
 * \param len int tamanio de cliente
 * \return int Return (0) si hay error [tamanio no valido o puntero nulo] - (1) si OK
 *
 */
int structure_sell(Clientes cliente[], Afiches afiche[], int len);


/** \brief modifica una venta de afiches
 * \param cliente estructura cliente
 * \param Afiches structura de afiche
 * \param len int tamanio de cliente
 * \return int Return (0) si hay error [tamanio no valido o puntero nulo] - (1) si OK
 *
 */
int structure_modifyAfiche(Clientes cliente[], Afiches afiche[],int len);


/** \brief cobra los afiches
 * \param cliente estructura cliente
 * \param Afiches structura de afiche
 * \param len int tamanio de cliente
 * \return int Return (0) si hay error [tamanio no valido o puntero nulo] - (1) si OK
 *
 */
int structure_CobrarAfiche(Clientes cliente[], Afiches afiche[], int len);


#endif // STRUCTSABM_H_INCLUDED
