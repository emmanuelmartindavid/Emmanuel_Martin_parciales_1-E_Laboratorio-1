/*
 * LinkedList.c
 *
 *  Created on: 16 nov. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

static Node* getNode(LinkedList *this, int nodeIndex);
static int addNode(LinkedList *this, int nodeIndex, void *pElement);
/// @brief ll_newLinkedList															CREA UNA NUEVA LINKEDLIST UTILIZANDO LA FUNCION MALLOC PARA PEDIR ESPACIO EN MEMORIA DINAMICA (HEAP).
///
/// @return																			RETORNA PUNTERO TIPO LINKEDLIST SI PUDO RESERVA ESPACIO EN MEMORIA PARA ESTE. RETORNA NULL EN CASO CONTRARIO.
LinkedList* ll_newLinkedList(void)
{
	LinkedList *this = (LinkedList*) malloc(sizeof(LinkedList));
	if (this != NULL)
	{
		this->pFirstNode = NULL;
		this->size = 0;
	}
	return this;
}
/// @brief ll_len																	OBTIENE LA CANTIDAD DE ELEMENTOS QUE EXISTEN EN LA LINKEDLIST.
///
/// @param this																		PUNTERO TIPO LINKEDLIST.
/// @return																			RETORNO EL SIZE DE LINKEDLIST. RETORNA -1 EN CASO CONTRARIO.
int ll_len(LinkedList *this)
{
	int retorno = -1;
	if (this != NULL)
	{
		retorno = this->size;
	}
	return retorno;
}
/// @brief getNode																	OBTIENE UN NODO DE LA LINKEDLIST DEPENDIENDO DEL INDICE RECIBIDO POR PARAMETRO.
///
/// @param this																		PUNTERO TIPO LINKEDLIST.
/// @param nodeIndex																ENTERO(INDICE DE NODO A OBTENER).
/// @return																			RETORNA EL PUNTERO NODO EN CASO DE ENCONTRARSE EN LA LINKEDLIST.
/// 																				RETORNA NULL EN CASO CONTRARIO (SI EL INDICE ES MENOR A 0 O EL MAYOR AL SIZE DE LA LINKEDLIST).
static Node* getNode(LinkedList *this, int nodeIndex)
{

	Node *auxNode = NULL;

	if (this != NULL)
	{

		if (nodeIndex >= 0 && nodeIndex < ll_len(this))
		{
			auxNode = this->pFirstNode;
			if (auxNode != NULL)
			{
				for (int i = 0; i < nodeIndex; i++)
				{

					auxNode = auxNode->pNextNode;
				}
			}

		}

	}

	return auxNode;
}
/// @brief addNode																		AGREGA Y ENLAZA UN NUEVO NODO A LA LINKEDLIST.
///
/// @param this																			PUNTERO TIPO LINKEDLIST.
/// @param nodeIndex																	ENTERO. DONDE SE AGREGARA EL NUEVO NODO.
/// @param pElement																		PUNTERO VOID AL ELEMENTO A SER CONTENIDO POR EL NUEVO NODO.
/// @return																				RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL O SI EL INDICE ES MENOR A 0 O MAYOR AL SIZE DE LINKEDLIST.
/// 																					RETORNA 0 SI FUNCIONA CORRECTAMENTE.
static int addNode(LinkedList *this, int nodeIndex, void *pElement)
{
	int returnAux = -1;
	Node *auxNode = (Node*) malloc(sizeof(Node*));
	Node *auxPrevNode = NULL;
	if (this != NULL)
	{
		if (nodeIndex >= 0 && nodeIndex <= ll_len(this))
		{
			auxNode->pElement = pElement;
			if (nodeIndex == 0)
			{
				auxNode->pNextNode = this->pFirstNode;
				this->pFirstNode = auxNode;
				this->size++;
				returnAux = 0;
			}
			else
			{
				auxPrevNode = getNode(this, nodeIndex - 1);
				if (auxPrevNode != NULL)
				{
					auxNode->pNextNode = auxPrevNode->pNextNode;
					auxPrevNode->pNextNode = auxNode;
					this->size++;
					returnAux = 0;
				}
			}
		}
	}
	return returnAux;
}
/// @brief ll_add																	AGREGA UN ELEMENTO A LINKEDLIST.
///
/// @param this																		PUNTERO TIPO LINKEDLIST.
/// @param pElement																	PUNTERO VOID AL ELEMENTO A SER AGREGADO.
/// @return																			RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL. RETORNA 0 SI FUNCIONA CORRECTAMENTE.
int ll_add(LinkedList *this, void *pElement)
{
	int returnAux = -1;

	if (this != NULL)
	{
		if (addNode(this, ll_len(this), pElement) == 0)
		{
			returnAux = 0;
		}
	}
	return returnAux;
}
/// @brief ll_get																	OBTIENE UN ELEMENTO DE LA LISTA SEGUN EL INDICE ESPECIFICADO.
///
/// @param this																		PUNTERO TIPO LINKEDLIST.
/// @param index																	ENTERO. INDICE DE UBICACION DE ELEMENTO A OBTENER.
/// @return 																		RETORNA NULL SINO FUNCIONA CORRECTAMENTE. RETORNA EL ELEMENTO EN CASO CORRECTO.
void* ll_get(LinkedList *this, int index)
{
	void *returnAux = NULL;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		Node *auxNode = getNode(this, index);
		if (auxNode != NULL)
		{
			returnAux = auxNode->pElement;
		}
	}
	return returnAux;
}
/// @brief ll_set																	ESTABLECE UNA MODIFICACION EN UN ELEMENTO DE LA LINKEDLIST.
///
/// @param this																		PUNTERO TIPO LINKEDLIST.
/// @param index																	ENTERO. UBICACION DE ELEMENTO A SER MODIFICACIÓN.
/// @param pElement																	PUNTERO VOID DE ELEMENTO A MODIFICAR.
/// @return																			RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL O SI EL INDICE ES MENOR A 0 O MAYOR AL SIZE DE LINKEDLIST.
/// 																				RETORNA 0 SI FUNCIONA CORRECTAMENTE.
int ll_set(LinkedList *this, int index, void *pElement)
{
	int returnAux = -1;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		Node *auxNode = getNode(this, index);
		if (auxNode != NULL)
		{
			auxNode->pElement = pElement;
			returnAux = 0;
		}
	}
	return returnAux;
}
/// @brief 	ll_remove																ELIMINA UN ELEMENTO DE LA LINKEDLIST.
///
/// @param this																		PUNTERO TIPO LINKEDLIST.
/// @param index																	ENTERO. INDICE DE ELEMENTO A SER ELIMINAR.
/// @return																			RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL O SI EL INDICE ES MENOR A 0 O MAYOR AL SIZE DE LINKEDLIST.
/// 																				RETORNA 0 SI FUNCIONA CORRECTAMENTE.
int ll_remove(LinkedList *this, int index)
{
	int returnAux = -1;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		Node *auxNode = getNode(this, index);

		if (auxNode != NULL)
		{
			if (index == 0)
			{
				this->pFirstNode = auxNode->pNextNode;
				free(auxNode);
				this->size--;
			}
			else
			{
				Node *auxPrevNode = getNode(this, index - 1);
				if (auxPrevNode != NULL)
				{
					auxPrevNode->pNextNode = auxNode->pNextNode;
					free(auxNode);
					this->size--;
				}
			}
		}
		returnAux = 0;
	}
	return returnAux;
}
/// @brief ll_clear																	ELEMIMINA TODOS LOS ELEMENTOS DE LA LINKEDLIST.
///
/// @param this																		PUNTERO TIPO LINKEDLIST.
/// @return																			RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL. RETORNA 0 SI FUNCIONA CORRECTAMENTE.
int ll_clear(LinkedList *this)
{
	int returnAux = -1;
	int longitudLinkedList = ll_len(this);
	if (this != NULL && longitudLinkedList > 0)
	{
		for (int i = 0; i < longitudLinkedList; i++)
		{
			ll_remove(this, 0);
		}
		returnAux = 0;
	}

	return returnAux;
}
/// @brief ll_deleteLinkedList														ELIMINA TODOS LOS ELEMENTOS DE LA LINKEDLIST Y LA LINKEDLIST.
///
/// @param this																		PUNTERO TIPO LINKEDLIST.
/// @return																			RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL. RETORNA 0 SI FUNCIONA CORRECTAMENTE.
int ll_deleteLinkedList(LinkedList *this)
{
	int returnAux = -1;
	if (this != NULL)
	{
		ll_clear(this);
		free(this);
		returnAux = 0;
	}
	return returnAux;
}
/// @brief ll_indexOf																OBTIENE INDICE DE ELEMENTO DE ELEMENTO DE LA LINKEDLIST.
///
/// @param this																		PUNTERO TIPO LINKEDLIST.
/// @param pElement																	PUNTERO VOID DE ELEMENTO.
/// @return																			RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL. RETORNA POSICION BUSCADO EN CASO DE HABER FUNCIONADO CORRECTAMENTE.
int ll_indexOf(LinkedList *this, void *pElement)
{
	int returnAux = -1;
	int longitudLinkedlist = ll_len(this);
	Node *auxNode;
	if (this != NULL && longitudLinkedlist > 0)
	{
		for (int i = 0; i < longitudLinkedlist; i++)
		{
			auxNode = getNode(this, i);
			if (auxNode != NULL && auxNode->pElement == pElement)
			{
				returnAux = i;
				break;
			}
		}
	}
	return returnAux;
}
/// @brief ll_isEmpty																VERIFICA SI HAY ELEMENTOS EN LA LINKEDLIST.
///
/// @param this																		PUNTERO TIPO LINKEDLIST.
/// @return																			RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL. RETORNA 0 LA LINKEDLIST NO ESTA VACIO.
/// 																				RETORNA 1 SI LA LINKEDLIST ESTA VACIA.
int ll_isEmpty(LinkedList *this)
{
	int returnAux = -1;
	if (this != NULL)
	{
		if (ll_len(this) > 0)
		{
			returnAux = 0;
		}
		else
		{
			returnAux = 1;
		}
	}
	return returnAux;
}
/// @brief ll_push																	AGREGA UN NUEVO ELEMENTO A LA LINKEDLIST EN UNA POSICION ESPECIFICADA.
///
/// @param this																		PUNTERO TIPO LINKEDLIST.
/// @param index																	ENTERO. POSICION DONDE SE AGREGARA EL NUEVO ELEMENTO.
/// @param pElement																	PUNTERO VOID DE NUEVO ELEMENTO.
/// @return																			RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL. RETORNA 0 SI FUNCIONA CORRECTAMENTE.
int ll_push(LinkedList *this, int index, void *pElement)
{
	int returnAux = -1;
	if (this != NULL && index >= 0 && index <= ll_len(this))
	{
		addNode(this, index, pElement);
		returnAux = 0;
	}
	return returnAux;
}
/// @brief ll_pop																	ELIMINA ELEMENTO Y DE POSICION ESPECIFICADA Y RETORNA SU PUNTERO.
///
/// @param this																		PUNTERO TIPO LINKEDLIST.
/// @param index																	ENTERO. POSICION DE ELEMENTO A ELIMINAR.
/// @return 																		RETORNA NULL SI EL PUNTERO ES NULL O SI EL INDICE ES MENOR A 0 O MAYOR AL SIZE DE LINKEDLIST.
/// 																				RETORNA EL PUNTERO ELEMENTO ELIMINADO SI FUNCIONO CORRECTAMENTE.
void* ll_pop(LinkedList *this, int index)
{
	void *returnAux = NULL;
	void *auxPElement;
	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		auxPElement = ll_get(this, index);
		if (auxPElement != NULL)
		{
			returnAux = auxPElement;
			ll_remove(this, index);
		}
	}
	return returnAux;
}
/// @brief ll_contains																VERIFICA SI LA LINKEDLIST CONTIENE O NO UN ELEMENTO RECIBIDO POR PARAMETRO.
///
/// @param this																		PUNTERO TIPO LINKEDLIST.
/// @param pElement																	PUNTERO VOID DE ELEMENTO VERIFICAR.
/// @return																			RETORNA -1, SI EL PUNTERO A LA LISTA ES NULL  RETORNA 1 SI CONTIENE EL ELEMENTO. RETORNA 0 SI NO LO CONTIENE.
int ll_contains(LinkedList *this, void *pElement)
{
	int returnAux = -1;
	if (this != NULL)
	{
		if (ll_indexOf(this, pElement) != -1)
		{
			returnAux = 1;
		}
		else
		{
			returnAux = 0;
		}
	}
	return returnAux;
}
/// @brief ll_containsAll															VERIFICA SI TODOS ELELEMENTOS DE LINKEDLIST THIS 2 ESTAN CONTENIDO EN LA LINKEDLIST THIS.
///
/// @param this																		PUNTERO TIPO LINKEDLIST THIS.
/// @param this2																	PUNTERO TIPO LINKEDLIST THIS 2.
/// @return																			RETORNA -1 SI ALGUNO DE LOS ELEMENTOS DE LA LISTA SON NULL.
/// 																				RETORNA 1 SI LOS ELEMENTOS DE THIS 2 ESTAN CONTENIDOS EN THIS.
/// 																				RETORNA 0 SI LOS ELEMENTOS DE THIS 2 NO ESTAN CONTENDIDOS EN THIS.
int ll_containsAll(LinkedList *this, LinkedList *this2)
{
	int returnAux = -1;
	int len;
	if (this != NULL && this2 != NULL)
	{  //ver si hay que validar que una list2 sea menor que list
		len = ll_len(this2);
		if (len == 0)
		{
			returnAux = 0;
		}
		else
		{
			for (int i = 0; i < len; i++)
			{
				if (ll_contains(this, ll_get(this2, i)) == 0)
				{
					returnAux = 0;  //no contiene
					break;
				}
				else
				{
					returnAux = 1;  //contiene
				}
			}
		}
	}
	return returnAux;
}
/// @brief ll_subList																					CREA Y RETORNA UNA NUEVA LINKEDLIST CON LOS ELEMENETOS INDICADOS.
///
/// @param this																							PUNTERO TIPO LINKEDLIST.
/// @param from																							ENTERO. INDICE DESDE EL CUAL SE COPIAN LOS ELELEMENTOS A LA NUEVA LISTA.
/// @param to																							ENTERO. INDICE HASTA EL CUAL SE COPIAN LOS ELEMENTOS A LA NUEVA LISTA (INDICE NO INCLUIDO).
/// @return																								RETORNA NULL SI EL PUNTERO A LA LISTA ES NULL O
/// 																									SI EL INDICE FROM ES MENOR A 0 O MAYOR AL LEN DE LA LINKEDLIST 0
/// 																									SI EL INDICE TO ES MENOR O IGUAL A FROM O MAYOR AL LEN DE LA LISTA.
/// 																									RETORNA PUNTERO A NUEVA LISTA SI SALIO DE FORMA CORRECTA.
LinkedList* ll_subList(LinkedList *this, int from, int to)
{
	LinkedList *cloneArray = NULL;
	void *auxPElement;
	if (this != NULL && to > from && to <= ll_len(this) && from >= 0 && from < ll_len(this))
	{
		cloneArray = ll_newLinkedList();
		if (cloneArray != NULL)
		{
			for (int i = from; i < to; i++)
			{
				auxPElement = ll_get(this, i);
				if (auxPElement != NULL)
				{
					ll_add(cloneArray, auxPElement);
				}
			}
		}
	}
	return cloneArray;
}
/// @brief ll_clone																			CREA Y RETORNA UNA NUEVA LINKEDLIST CON TODOS LOS ELEMENTOS DE LA LINKEDLIST RECIBIDA POR PARAMETRO.
///
/// @param this																				PUNTERO TIPO LINKEDLIST.
/// @return																					RETORNA NULL SI EL PUNTERO A LINKEDLIST ES NULL.
/// 																						RETORNA EL PUNTERO DE NUEVA LINKEDLIST EN CASO CORRECTO.
LinkedList* ll_clone(LinkedList *this)
{
	LinkedList *cloneArray = NULL;
	if (this != NULL)
	{
		cloneArray = ll_subList(this, 0, ll_len(this));
	}
	return cloneArray;
}
/// @brief ll_sort																			ORDENA LOS ELEMENTOS DE LA LINKEDLIST SEGUN FUNCION CRITERIO RECIBIDA POR PARAMETRO.
///
/// @param this																				PUNTERO TIPO LINKEDLIST.
/// @param pFunc																			PUNTERO FUNCION CRITERIO.
/// @param order																			ENTERO.
/// 																						1 INDICA ORDEN ASCENDENTE.
/// 																						0 INDICA ORDEN DESCENDENTE.
/// @return																					RETORNA -1 SI EL PUNTERO A LINKEDLIST ES NULL.
/// 																						RETORNA 0 SI FUNCIONO CORRECTAMENTE.
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order)
{
	int returnAux = -1;
	int estaOrdenado;
	int len;
	void *auxElement = NULL;
	void *auxElementDos = NULL;
	int retornoPFunc;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
		len = ll_len(this);
		do
		{
			estaOrdenado = 1;
			len--;
			for (int i = 0; i < len; i++)
			{
				auxElement = ll_get(this, i);
				auxElementDos = ll_get(this, i + 1);
				retornoPFunc = pFunc(auxElement, auxElementDos);
				if ((retornoPFunc > 0 && order == 1) || (retornoPFunc < 0 && order == 0))
				{
					ll_set(this, i, auxElementDos);
					ll_set(this, i + 1, auxElement);
					estaOrdenado = 0;
				}
			}

		} while (estaOrdenado == 0);
		returnAux = 0;
	}
	return returnAux;

}
/// @brief ll_filter																				FILTRA SEGUN FUNCION CRITERIO Y DEVUELVE UNA NUEVA LINKEDLIST CON LOS ELELEMENTOS CARGADOS.
///
/// @param this																						PUNTERO TIPO LINKEDLIST.
/// @param pFunc																					PUNTERO FUNCION CRITERIO.
/// @return																							RETORNA NULL SI EL PUNTERO A LINKEDLIST ES NULL EN CASO ERROR.
/// 																								RETORNA PUNTERO LINKEDLIST CON LA NUEVA LISTA EN CASO CORRECTO.
LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void*))
{
	LinkedList *filterList = NULL;
	int lenList;
	void *auxElement;
	if (this != NULL && pFunc != NULL)
	{
		filterList = ll_newLinkedList();

		lenList = ll_len(this);  //INDEX DE ULTIMO ELEMENTO VA A SER MENOR AL TOTAL DE LOS ELEMENTOS.N-1
		if (filterList != NULL && lenList > 0)
		{
			for (int i = 0; i < lenList; i++)
			{
				auxElement = ll_get(this, i);

				if (auxElement != NULL && pFunc(auxElement) == 1)
				{
					ll_add(filterList, auxElement);
				}
			}
		}
	}
	return filterList;
}
/// @brief ll_map																				PERMITE A FUNCION CRITERIO MODIFICAR ALGUNO DE LOS CAMPOS DE ELEMENTO EN CASO DE SER NECESARIO.
/// 																							QUEDANDO ASI AL FINAL DE LA ITERACION TODOS LOS ELEMENTOS MODIFICADOS SEGUN EL CRITERIO.
/// @param this																					PUNTERO TIPO LINKEDLIST.
/// @param pFunc																				PUNTERO FUNCION CRITERIO.
/// @return																						RETORNA NULL SI EL PUNTERO A LINKEDLIST ES NULL EN CASO ERROR.
/// 																							RETORNA PUNTERO LINKEDLIST CON LA NUEVA LISTA EN CASO CORRECTO.
LinkedList* ll_map(LinkedList *this, void (*pFunc)(void*))
{
	int lenList;
	void *auxElement;
	if (this != NULL && pFunc != NULL)
	{
		lenList = ll_len(this);  //INDEX DE ULTIMO ELEMENTO VA A SER MENOR AL TOTAL DE LOS ELEMENTOS.N-1
		if (lenList > 0)
		{
			for (int i = 0; i < lenList; i++)
			{
				auxElement = ll_get(this, i);
				if (auxElement != NULL)
				{
					pFunc(auxElement);
				}
			}
		}
	}
	return this;
}
/// @brief ll_count																				CUENTA ELEMENTOS DE LA LISTA SEGUN FUNCION CRITERIO.
///
/// @param this																					PUNTERO TIPO LINKEDLIST.
/// @param pFunc																				PUNTERO FUNCION CRITERIO.
/// @return																						RETORNA 0 SINO CONTO NADA.
/// 																							RETORNA CONTADOR/ACUMULADOR DE ELEMENTOS CONTADOS.
int ll_count(LinkedList *this, int (*pFunc)(void*))
{
	int returnLl_count = 0;
	int lenList;
	void *auxElement;
	if (this != NULL && pFunc != NULL)
	{
		lenList = ll_len(this);  //INDEX DE ULTIMO ELEMENTO VA A SER MENOR AL TOTAL DE LOS ELEMENTOS.N-1
		if (lenList > 0)
		{
			for (int i = 0; i < lenList; i++)
			{
				auxElement = ll_get(this, i);

				if (auxElement != NULL)
				{
					returnLl_count += pFunc(auxElement);
				}
			}
		}
	}
	return returnLl_count;
}
