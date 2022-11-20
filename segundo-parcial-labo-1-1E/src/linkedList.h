/*
 * LinkedList.h
 *
 *  Created on: 16 nov. 2022
 *      Author: cuerpos
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
/// @brief ll_newLinkedList													CREA UNA NUEVA LINKEDLIST UTILIZANDO LA FUNCION MALLOC PARA PEDIR ESPACIO EN MEMORIA DINAMICA (HEAP).
///
/// @return																	RETORNA PUNTERO TIPO LINKEDLIST SI PUDO RESERVA ESPACIO EN MEMORIA PARA ESTE. RETORNA NULL EN CASO CONTRARIO.
LinkedList* ll_newLinkedList(void);
/// @brief ll_len															OBTIENE LA CANTIDAD DE ELEMENTOS QUE EXISTEN EN LA LINKEDLIST.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @return																	RETORNO EL SIZE DE LINKEDLIST. RETORNA -1 EN CASO CONTRARIO.
int ll_len(LinkedList* this);
/// @brief ll_add															AGREGA UN ELEMENTO A LINKEDLIST.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @param pElement															PUNTERO VOID AL ELEMENTO A SER AGREGADO.
/// @return																	RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL. RETORNA 0 SI FUNCIONA CORRECTAMENTE.
int ll_add(LinkedList* this, void* pElement);
/// @brief ll_get															OBTIENE UN ELEMENTO DE LA LISTA SEGUN EL INDICE ESPECIFICADO.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @param index															ENTERO. INDICE DE UBICACION DE ELEMENTO A OBTENER.
/// @return 																RETORNA NULL SINO FUNCIONA CORRECTAMENTE. RETORNA EL ELEMENTO EN CASO CORRECTO.
void* ll_get(LinkedList* this, int index);
/// @brief ll_set															ESTABLECE UNA MODIFICACION EN UN ELEMENTO DE LA LINKEDLIST.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @param index															ENTERO. UBICACION DE ELEMENTO A SER MODIFICACIÓN.
/// @param pElement															PUNTERO VOID DE ELEMENTO A MODIFICAR.
/// @return																	RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL O SI EL INDICE ES MENOR A 0 O MAYOR AL SIZE DE LINKEDLIST.
/// 																		RETORNA 0 SI FUNCIONA CORRECTAMENTE.
int ll_set(LinkedList* this, int index,void* pElement);
/// @brief 	ll_remove														ELIMINA UN ELEMENTO DE LA LINKEDLIST.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @param index															ENTERO. INDICE DE ELEMENTO A SER ELIMINAR.
/// @return																	RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL O SI EL INDICE ES MENOR A 0 O MAYOR AL SIZE DE LINKEDLIST.
/// 																		RETORNA 0 SI FUNCIONA CORRECTAMENTE.
int ll_remove(LinkedList *this, int index);
/// @brief ll_clear															ELEMIMINA TODOS LOS ELEMENTOS DE LA LINKEDLIST.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @return																	RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL. RETORNA 0 SI FUNCIONA CORRECTAMENTE.
int ll_clear(LinkedList* this);
/// @brief ll_deleteLinkedList												ELIMINA TODOS LOS ELEMENTOS DE LA LINKEDLIST Y LA LINKEDLIST.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @return																	RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL. RETORNA 0 SI FUNCIONA CORRECTAMENTE.
int ll_deleteLinkedList(LinkedList* this);
/// @brief ll_indexOf														OBTIENE INDICE DE ELEMENTO DE ELEMENTO DE LA LINKEDLIST.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @param pElement															PUNTERO VOID DE ELEMENTO A MODIFICAR.
/// @return																	RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL. RETORNA POSICION BUSCADO EN CASO DE HABER FUNCIONADO CORRECTAMENTE.
int ll_indexOf(LinkedList* this, void* pElement);
/// @brief ll_isEmpty														VERIFICA SI HAY ELEMENTOS EN LA LINKEDLIST.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @return																	RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL. RETORNA 0 LA LINKEDLIST NO ESTA VACIO.
/// 																		RETORNA 1 SI LA LINKEDLIST ESTA VACIA.
int ll_isEmpty(LinkedList* this);
/// @brief ll_push															AGREGA UN NUEVO ELEMENTO A LA LINKEDLIST EN UNA POSICION ESPECIFICADA.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @param index															ENTERO. POSICION DONDE SE AGREGARA EL NUEVO ELEMENTO.
/// @param pElement															PUNTERO VOID DE NUEVO ELEMENTO.
/// @return																	RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL. RETORNA 0 SI FUNCIONA CORRECTAMENTE.
int ll_push(LinkedList* this, int index, void* pElement);
/// @brief ll_pop															ELIMINA ELEMENTO Y DE POSICION ESPECIFICADA Y RETORNA SU PUNTERO.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @param index															ENTERO. POSICION DE ELEMENTO A ELIMINAR.
/// @return 																RETORNA NULL SI EL PUNTERO ES NULL O SI EL INDICE ES MENOR A 0 O MAYOR AL SIZE DE LINKEDLIST.
/// 																		RETORNA EL PUNTERO ELEMENTO ELIMINADO SI FUNCIONO CORRECTAMENTE.
void* ll_pop(LinkedList* this,int index);
/// @brief ll_contains														VERIFICA SI LA LINKEDLIST CONTIENE O NO UN ELEMENTO RECIBIDO POR PARAMETRO.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @param pElement															PUNTERO VOID DE ELEMENTO VERIFICAR.
/// @return																	RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL  RETORNA 1 SI CONTIENE EL ELEMENTO. RETORNA 0 SI NO LO CONTIENE.
int ll_contains(LinkedList* this, void* pElement);
/// @brief ll_containsAll													VERIFICA SI TODOS ELELEMENTOS DE LINKEDLIST THIS 2 ESTAN CONTENIDO EN LA LINKEDLIST THIS.
///
/// @param this																PUNTERO TIPO LINKEDLIST THIS.
/// @param this2															PUNTERO TIPO LINKEDLIST THIS 2.
/// @return																	RETORNA -1 SI ALGUNO DE LOS ELEMENTOS DE LA LISTA SON NULL.
/// 																		RETORNA 1 SI LOS ELEMENTOS DE THIS 2 ESTAN CONTENIDOS EN THIS.
/// 																		RETORNA 0 SI LOS ELEMENTOS DE THIS 2 NO ESTAN CONTENDIDOS EN THIS.
int ll_containsAll(LinkedList* this,LinkedList* this2);
/// @brief ll_subList														CREA Y RETORNA UNA NUEVA LINKEDLIST CON LOS ELEMENETOS INDICADOS.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @param from																ENTERO. INDICE DESDE EL CUAL SE COPIAN LOS ELELEMENTOS A LA NUEVA LISTA.
/// @param to																ENTERO. INDICE HASTA EL CUAL SE COPIAN LOS ELEMENTOS A LA NUEVA LISTA (INDICE NO INCLUIDO).
/// @return																	RETORNA NULL SI EL PUNTERO A LA LISTA ES NULL O
/// 																		SI EL INDICE FROM ES MENOR A 0 O MAYOR AL LEN DE LA LINKEDLIST 0
/// 																		SI EL INDICE TO ES MENOR O IGUAL A FROM O MAYOR AL LEN DE LA LISTA.
/// 																		RETORNA PUNTERO A NUEVA LISTA SI SALIO DE FORMA CORRECTA.
LinkedList* ll_subList(LinkedList* this,int from,int to);
/// @brief ll_clone															CREA Y RETORNA UNA NUEVA LINKEDLIST CON TODOS LOS ELEMENTOS DE LA LINKEDLIST RECIBIDA POR PARAMETRO.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @return																	RETORNA NULL SI EL PUNTERO A LINKEDLIST ES NULL.
/// 																		RETORNA EL PUNTERO DE NUEVA LINKEDLIST EN CASO CORRECTO.
LinkedList* ll_clone(LinkedList* this);
/// @brief ll_sort															ORDENA LOS ELEMENTOS DE LA LINKEDLIST SEGUN FUNCION CRITERIO RECIBIDA POR PARAMETRO.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @param pFunc															PUNTERO FUNCION CRITERIO.
/// @param order															ENTERO.
/// 																	    1 INDICA ORDEN ASCENDENTE.
/// 																		0 INDICA ORDEN DESCENDENTE.
/// @return																	RETORNA -1 SI EL PUNTERO A LINKEDLIST ES NULL.
/// 																	    RETORNA 0 SI FUNCIONO CORRECTAMENTE.
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
/// @brief ll_filter														FILTRA SEGUN FUNCION CRITERIO Y DEVUELVE UNA NUEVA LINKEDLIST CON LOS ELELEMENTOS CARGADOS.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @param pFunc															PUNTERO FUNCION CRITERIO.
/// @return																	RETORNA NULL SI EL PUNTERO A LINKEDLIST ES NULL EN CASO ERROR.
/// 																		RETORNA PUNTERO LINKEDLIST CON LA NUEVA LISTA EN CASO CORRECTO.
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*));
/// @brief ll_map															PERMITE A FUNCION CRITERIO MODIFICAR ALGUNO DE LOS CAMPOS DE ELEMENTO EN CASO DE SER NECESARIO.
/// 																		QUEDANDO ASI AL FINAL DE LA ITERACION TODOS LOS ELEMENTOS MODIFICADOS SEGUN EL CRITERIO.
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @param pFunc															PUNTERO FUNCION CRITERIO.
/// @return																	RETORNA NULL SI EL PUNTERO A LINKEDLIST ES NULL EN CASO ERROR.
/// 																		RETORNA PUNTERO LINKEDLIST CON LA NUEVA LISTA EN CASO CORRECTO.
LinkedList* ll_map(LinkedList *this, void (*pFunc)(void*));
/// @brief ll_count															CUENTA ELEMENTOS DE LA LISTA SEGUN FUNCION CRITERIO.
///
/// @param this																PUNTERO TIPO LINKEDLIST.
/// @param pFunc															PUNTERO FUNCION CRITERIO.
/// @return																	RETORNA 0 SINO CONTO NADA.
/// 																		RETORNA CONTADOR/ACUMULADOR DE ELEMENTOS CONTADOS.
int ll_count(LinkedList *this, int (*pFunc)(void*));

#endif /* LINKEDLIST_H_ */
