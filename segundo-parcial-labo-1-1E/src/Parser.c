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
		fscanf(pFile, "%[^\n]\n", auxHeader);
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
/// @brief parserSaleFromBinary	PARSEA DATOS DE VENTAS DESDE ARCHIVO MODO BINARIO.
///
/// @param pFile				PUNTERO A FILE.
/// @param pArrayListPlayer		LINKEDLIST VENTAS.
/// @return						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int parserSaleFromBinary(FILE *pFile, LinkedList *pListSale)
{
	int returnParserSaleFromBinary = ERROR;
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
	int returnFread;
	if (pFile != NULL && pListSale != NULL)
	{
		ll_clear(pListSale);
		do
		{
			pSale = newSale();
			if (pSale != NULL)
			{
				returnFread = fread(pSale, sizeof(sSale), 1, pFile);
				if (returnFread == 1)
				{
					if (ll_add(pListSale, pSale) == 0)
					{
						returnParserSaleFromBinary = SUCCESS;
					}
				}
				else
				{
					returnParserSaleFromBinary = ERROR;
					break;
				}
			}
		} while (!feof(pFile));
	}
	return returnParserSaleFromBinary;
}

/// @brief parserIdSaleFromText 	PARSEA DATO DE ID VENTA A DAR DE ALTA DESDE ARCHIVO CSV EN MODO TEXTO.
///
/// @param pFile					PUNTERO A FILE.
/// @param pIdSale				PUNTERO ENTERO.
/// @return							RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int parserIdSaleFromText(FILE *pFile, int *pIdSale)
{
	int returnparserIdSaleFromText = ERROR;
	int returnFscanf;
	char auxId[1000];

	if (pFile != NULL && pIdSale != NULL)
	{
		returnFscanf = fscanf(pFile, "%[^\n]\n", auxId);
		if (returnFscanf == 1)
		{
			*pIdSale = atoi(auxId);
			returnparserIdSaleFromText = SUCCESS;
		}
	}
	return returnparserIdSaleFromText;
}

