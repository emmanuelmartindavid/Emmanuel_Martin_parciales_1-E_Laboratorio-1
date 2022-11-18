/*
 * Controller.c
 *
 *  Created on: 16 nov. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "parser.h"
#include "venta.h"
#include "validaciones.h"
/// @brief  controllerFindSaleById		FUNCION PARA BUSCAR INDICE DE ELEMENTO
///
/// @param pListSale					LINKEDLIST VENTAS.
/// @param idPlayer						ENTERO
/// @return								RETORNO  POSICION DE VENTA EN CASO CORRECTO. RETORNO ERROR(-1) EN CASO CONTRARIO.
int controllerFindSaleById(LinkedList *pListSale, int idSale)
{
	int returnControllerFindSaleById = ERROR;
	int lenListPlayers;
	int auxId;
	sSale *pSale = NULL;

	if (pListSale != NULL && ll_isEmpty(pListSale) == 0)
	{
		lenListPlayers = ll_len(pListSale);
		if (lenListPlayers > 0)
		{
			for (int i = 0; i < lenListPlayers; i++)
			{
				pSale = (sSale*) ll_get(pListSale, i);
				if (pSale != NULL)
				{
					if (getIdSale(pSale, &auxId) == SUCCESS && auxId == idSale)
					{
						returnControllerFindSaleById = ll_indexOf(pListSale, pSale);
					}
				}
			}
		}
	}
	return returnControllerFindSaleById;
}
/// @brief controllerLoadSaleFromText	  	CARGA DATOS DE VENTAS DESDE ARCHIVO CSV EN MODO TEXTO.
///
/// @param path								PUNTERO STRING
/// @param pListSale						LINKEDLIST VENTAS
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerLoadSaleFromText(char *path, LinkedList *pListSale)
{
	int returncontrollerLoadPlayerFromText = ERROR;
	FILE *pFile = NULL;
	if (path != NULL && pListSale != NULL)
	{
		pFile = fopen(path, "r");
		if (pFile != NULL)
		{
			if (parserSaleFromText(pFile, pListSale) == SUCCESS)
			{
				returncontrollerLoadPlayerFromText = SUCCESS;
			}
			fclose(pFile);
		}
	}
	return returncontrollerLoadPlayerFromText;
}
/// @brief controllerAddSale		ALTA DE VENTA.
///
/// @param pListSale				LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerAddSale(LinkedList *pListSale)
{
	int returnControllerAddSale = ERROR;
	sSale *pSale = NULL;
	if (pListSale != NULL)
	{
		//&& editCreditCardNumber(pSale) == SUCCESS AGREGAR
		pSale = newSale();
		if (pSale != NULL && editDaySale(pSale) == SUCCESS && editMonthSale(pSale) == SUCCESS && editYearSale(pSale) == SUCCESS && editModel(pSale) == SUCCESS && editAmountSale(pSale) == SUCCESS && editUnitPriceSale(pSale) == SUCCESS)
		{
			if (ll_add(pListSale, pSale) == 0)
			{
				returnControllerAddSale = SUCCESS;
			}
		}
	}
	return returnControllerAddSale;
}


int controllerEditSale(LinkedList *pListSale)
{
	int returnControllerEditSale=ERROR;

	if(pListSale != NULL)
	{








	}
	return returnControllerEditSale;
}


/// @brief controllerRemoveSale		BAJA DE VENTA.
///
/// @param pListSale				LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerRemoveSale(LinkedList *pListSale)
{
	int returnControllerRemoveSale = ERROR;
	int auxId;
	int indexListSales;
	char confirmation[3];
	sSale *pSale = NULL;

	if (pListSale != NULL && ll_isEmpty(pListSale) == 0 && controllerListSales(pListSale) == SUCCESS)
	{
		if (utn_getNumber(&auxId, "\n\t\t\t\t\t\t\t\tINGRESE ID DE VENTA A DAR DE BAJA.\n", "\n\t\t\t\t\t\t\t\tERROR. REINTENTE.\n", 1, 500, 3) == 0)
		{
			indexListSales = controllerFindSaleById(pListSale, auxId);
			if (indexListSales != ERROR)
			{
				pSale = (sSale*) ll_get(pListSale, indexListSales);
				if (pSale != NULL)
				{
					showSaleData();
					listOneSale(pSale);
					showLine();
					if (utn_getDescriptionExit(confirmation, "\n\t\t\t\t\t\t\t\tSE DARA DE BAJA.\n"
							"\n\t\t\t\t\t\t\t\tINGRESE SI PARA CONTINUAR.\n"
							"\n\t\t\t\t\t\t\t\tINGRESE NO PARA CANCELAR BAJA.\n", "\n\t\t\t\t\t\t\t\tERROR. REINTENTE.\n", 3) == 0)
					{
						if (stricmp(confirmation, "si") == 0)
						{
							if (ll_remove(pListSale, indexListSales) == 0)
							{
								deleteSale(pSale);
								returnControllerRemoveSale = SUCCESS;
							}
						}
						else
						{
							returnControllerRemoveSale = REMOVECANCEL;
						}
					}
				}
			}
			else
			{
				returnControllerRemoveSale = NOSALE;
			}
		}
	}

	return returnControllerRemoveSale;
}

/// @brief  controllerListSales   	LISTADO VENTAS.
///
/// @param pListSale				LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerListSales(LinkedList *pListSale)
{
	int returncontrollerListPlayer = ERROR;
	int lenListPlayers;
	sSale *pSale = NULL;
	if (pListSale != NULL)
	{
		lenListPlayers = ll_len(pListSale);
		if (lenListPlayers > 0 && ll_isEmpty(pListSale) == 0)
		{
			showSaleData();
			for (int i = 0; i < lenListPlayers; i++)
			{
				pSale = (sSale*) ll_get(pListSale, i);
				if (pSale != NULL)
				{
					if (listOneSale(pSale) == SUCCESS)
					{
						returncontrollerListPlayer = SUCCESS;
					}
				}
			}
			printf("\t\t\t\t\t\t==================================================================================================================\n");
		}
	}
	return returncontrollerListPlayer;
}
