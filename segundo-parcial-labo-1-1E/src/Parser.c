/*
 * Parser.c
 *
 *  Created on: 16 nov. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "venta.h"

/// @brief parserSaleFromText	PARSEA DATOS DE VENTAS DESDE ARCHIVO CSV EN MODO TEXTO.
///
/// @param pFile				PUNTERO A FILE.
/// @param pArrayListPlayer		LINKEDLIST VENTAS.
/// @return						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int parserSaleFromText(FILE *pFile, LinkedList *pListSale)
{
	int returnParserSaleFromText = ERROR;
	char auxId[2000];
	char auxDay[2000];
	char auxMonth[2000];
	char auxYear[2000];
	char auxModel[2000];
	char auxAmmount[2000];
	char auxUnitPrice[2000];
	char auxCreditCardNumber[2000];
	char auxHeader[2000];
	sSale *pSale;
	int returnFscanf;

	if (pFile != NULL && pListSale != NULL)
	{
		fscanf(pFile,"%[^\n]\n", auxHeader);
		do
		{
			returnFscanf = fscanf(pFile, "%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],$%[^,],%[^\n]\n", auxId, auxDay, auxMonth, auxYear, auxModel, auxAmmount, auxUnitPrice, auxCreditCardNumber);
			if (returnFscanf == 8)
			{
				pSale = newSaleParameters(auxId, auxDay, auxMonth, auxYear, auxModel, auxAmmount, auxUnitPrice, auxCreditCardNumber);
				if (pSale != NULL)
				{
					if (ll_add(pListSale, pSale) == 0)
					{
						returnParserSaleFromText = SUCCESS;
					}
				}
			}
			else
			{
				returnParserSaleFromText = ERROR;
				break;
			}
		} while (!feof(pFile));
	}
	return returnParserSaleFromText;
}
