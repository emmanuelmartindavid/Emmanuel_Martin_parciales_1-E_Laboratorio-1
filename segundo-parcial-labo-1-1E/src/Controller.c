/*
 * Controller.c
 *
 *  Created on: 16 nov. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "venta.h"

/// @brief controllerLoadSaleFromText	  	CARGA DATOS DE VENTAS DESDE ARCHIVO CSV EN MODO TEXTO.
///
/// @param path								PUNTERO STRING
/// @param pArrayListPlayer					LINKEDLIST VENTAS
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

/// @brief  controllerListSales   	LISTADO VENTAS.
///
/// @param pArrayListPlayer			LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerListSales(LinkedList *pListSale)
{
	int returncontrollerListPlayer = ERROR;
	int lenListPlayers;
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
					if (listOneSale(pSale) == SUCCESS)
					{
						returncontrollerListPlayer = SUCCESS;
					}
				}
			}
		}
	}
	return returncontrollerListPlayer;
}
