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
/// @brief	controllerSaveSalesTextMode		GUARDA DATOS DE VENTE EN ARCHIVO CSV EN MODO TEXTO.
///
/// @param path								PUNTERO STRING
/// @param LinkedList						LINKEDLIST VENTAS.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerSaveSalesTextMode(char *path, LinkedList *pListSale)
{
	int returnControllerSaveSalesTextMode = ERROR;
	FILE *pFile = NULL;
	int lenListSale;
	sSale *pSale = NULL;
	int auxId;
	short auxDay;
	short auxMonth;
	short auxYear;
	char auxModel[50];
	short auxAmount;
	float auxUnitPrice;
	char auxCreditCardNumber[17];
	if (path != NULL && pListSale != NULL)
	{
		pFile = fopen(path, "w");
		if (pFile != NULL)
		{
			lenListSale = ll_len(pListSale);
			if (lenListSale > 0)
			{
				fprintf(pFile, "ID_Venta ,Fecha_Venta,Modelo_Auto,Cantidad,Precio_Unitario,Tarjeta_De_Credito\n");
				for (int i = 0; i < lenListSale; i++)
				{
					pSale = (sSale*) ll_get(pListSale, i);
					if (pSale != NULL)
					{
						if (getIdSale(pSale, &auxId) == SUCCESS && getDaySale(pSale, &auxDay) == SUCCESS && getMonthSale(pSale, &auxMonth) == SUCCESS && getYearSale(pSale, &auxYear) == SUCCESS && getModelSale(pSale, auxModel) == SUCCESS && getAmountSale(pSale, &auxAmount) == SUCCESS
								&& getUnitPriceSale(pSale, &auxUnitPrice) == SUCCESS && getCreditCardNumber(pSale, auxCreditCardNumber) == SUCCESS)
						{
							if (fprintf(pFile, "%d,%.2hd/%.2hd/%hd,%s,%hd,$%.2f,%s\n", auxId, auxDay, auxMonth, auxYear, auxModel, auxAmount, auxUnitPrice, auxCreditCardNumber) > 0)
							{
								returnControllerSaveSalesTextMode = SUCCESS;
							}
						}
					}
				}
				fclose(pFile);
			}
		}

	}
	return returnControllerSaveSalesTextMode;
}
/// @brief controllerLoadIdSaleFromText	  	CARGA ID DE VENTA A DAR DE ALTA DESDE ARCHIVO CSV EN MODO TEXTO.
///
/// @param path								PUNTERO STRING
/// @param pListSale						LINKEDLIST VENTAS
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerLoadIdSaleFromText(char *path, int *pIdSale)
{
	int returncontrollerLoadPlayerFromText = ERROR;
	FILE *pFile = NULL;
	if (path != NULL && pIdSale != NULL)
	{
		pFile = fopen(path, "r");
		if (pFile != NULL)
		{
			if (parserIdSaleFromText(pFile, pIdSale) == SUCCESS)
			{
				returncontrollerLoadPlayerFromText = SUCCESS;
			}
			fclose(pFile);
		}
	}
	return returncontrollerLoadPlayerFromText;
}
/// @brief controllerSaveIdSaleTextMode      GAURDA ID DE VENTA EN MODO TEXTO A ARCHIVO CSV.
///
/// @param path								 PUNTERO STRING.
/// @param pIdSale							 PUNTERO ENTERO.
/// @return									 RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerSaveIdSaleTextMode(char *path, int *pIdSale)
{
	int returnControllerSaveIdSaleTextMode = ERROR;
	FILE *pFile = NULL;
	if (path != NULL && pIdSale != NULL)
	{
		pFile = fopen(path, "w");
		if (pFile != NULL)
		{
			if (fprintf(pFile, "%d\n", *pIdSale) > 0)
			{
				returnControllerSaveIdSaleTextMode = SUCCESS;
			}
		}
		fclose(pFile);
	}
	return returnControllerSaveIdSaleTextMode;
}
/// @brief controllerLoadSalesFromBinary  			CARGA DATOS DE VENTAS DESDE ARCHIVO BIN EN MODO BINARIO.
///
/// @param path												PUNTERO STRING
/// @param pListSale										 LINKEDLIST VENTAS.
/// @return 												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerLoadSalesFromBinary(char *path, LinkedList *pListSale)
{
	int returncontrollerLoadSaleFromBinary = ERROR;
	FILE *pFile = NULL;

	if (path != NULL && pListSale != NULL)
	{
		pFile = fopen(path, "rb");
		if (pFile != NULL)
		{
			if (parserSaleFromBinary(pFile, pListSale) == SUCCESS)
			{
				returncontrollerLoadSaleFromBinary = SUCCESS;
			}
			fclose(pFile);
		}
	}
	return returncontrollerLoadSaleFromBinary;
}
/// @brief controllerSaveSalesBinarytMode   			   	 GUARDA DATOS DE JUGADORES DESDE ARCHIVO CSV EN MODO BINARIO.
///
/// @param path								 			 	 PUNTERO STRING
/// @param pListSale										 LINKEDLIST VENTAS.
/// @return									 				 RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerSaveSalesBinarytMode(char *path, LinkedList *pListSale)
{
	int returnControllerSaveSalesBinarytMode = ERROR;
	FILE *pFile = NULL;
	int lenListSale;
	sSale *pSale = NULL;
	int returnFwrite;

	if (path != NULL && pListSale != NULL)
	{
		pFile = fopen(path, "wb");
		if (pFile != NULL)
		{
			lenListSale = ll_len(pListSale);
			if (lenListSale > 0)
			{
				for (int i = 0; i < lenListSale; i++)
				{
					pSale = (sSale*) ll_get(pListSale, i);
					if (pSale != NULL)
					{
						returnFwrite = fwrite(pSale, sizeof(sSale), 1, pFile);
						if (returnFwrite == 1)
						{
							returnControllerSaveSalesBinarytMode = SUCCESS;
						}
					}
				}
				fclose(pFile);
			}
		}
	}
	return returnControllerSaveSalesBinarytMode;
}
/// @brief controllerAddSale		ALTA DE VENTA.
///
/// @param pListSale				LINKEDLIST VENTAS.
/// @param pListSale				ENTERO.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerAddSale(LinkedList *pListSale, int *pIdSale)
{
	int returnControllerAddSale = ERROR;
	sSale *pSale = NULL;

	if (pListSale != NULL && pIdSale != NULL)
	{
		//&& editCreditCardNumber(pSale) == SUCCESS AGREGAR
		pSale = newSale();
		if (pSale != NULL && editCreditCardNumber(pSale) == SUCCESS && editDaySale(pSale) == SUCCESS && editMonthSale(pSale) == SUCCESS && editYearSale(pSale) == SUCCESS && editModel(pSale) == SUCCESS && editAmountSale(pSale) == SUCCESS && editUnitPriceSale(pSale) == SUCCESS && setIdSale(pSale, *pIdSale) == SUCCESS)
		{
			if (ll_add(pListSale, pSale) == 0)
			{
				(*pIdSale)++;
				returnControllerAddSale = SUCCESS;
			}
		}
	}
	return returnControllerAddSale;
}
/// @brief controllerRemoveSale		EDICION DE VENTA.
///
/// @param pListSale				LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO(MODIFICACION HECHA). ERROR(-1) EN CASO CONTRARIO. RETORNA NOEDIT(3) EN CASO DE NO HABER HECHO NINGUNA MODIFIACION.
int controllerEditSale(LinkedList *pListSale)
{
	int returnControllerEditSale = ERROR;
	int auxId;
	int indexListPlayer;
	sSale *pSale = NULL;

	if (pListSale != NULL)
	{
		if (ll_isEmpty(pListSale) == 0 && controllerListSales(pListSale) == SUCCESS && utn_getNumber(&auxId, "INGRESE ID DE VENTA A MODIFICAR.\n", "ERROR. REINTENTE.\n", 1, 500, 3) == 0)
		{
			indexListPlayer = controllerFindSaleById(pListSale, auxId);
			if (indexListPlayer != ERROR)
			{
				pSale = (sSale*) ll_get(pListSale, indexListPlayer);
				if (pSale != NULL)
				{
					returnControllerEditSale = editOneSale(pSale);
					if (returnControllerEditSale == SUCCESS)
					{
						returnControllerEditSale = SUCCESS;
					}
					else if (returnControllerEditSale == ERROR)
					{
						returnControllerEditSale = ERROR;
					}
					else
					{
						returnControllerEditSale = NOEDIT;
					}
				}
			}
			else
			{
				returnControllerEditSale = NOSALE;
			}
		}
	}
	return returnControllerEditSale;
}
/// @brief controllerRemoveSale		BAJA DE VENTA.
///
/// @param pListSale				LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
/// 								RETORNA REMOVECANCEL(-2) EN CASO DE CANCELAR BAJA.
/// 								RETORNA NOSALE(-2) EN CASO DE QUE NO EXISTA LA VENTA.
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
/// @brief controllerSortPerIdSale			ORDENA VENTAS POR ID.
///
/// @param pListSale						LINKEDLIST VENTAS.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerSortPerIdSale(LinkedList *pListSale)
{
	int returnControllerSortPerIdSale=ERROR;

	if(ll_sort(pListSale, compareSaleById, 1)==0)
	{
		returnControllerSortPerIdSale=SUCCESS;
	}
	return returnControllerSortPerIdSale;
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
				if (pSale != NULL && listOneSale(pSale) == SUCCESS)
				{
					returncontrollerListPlayer = SUCCESS;
				}
			}
			//printf("\t\t\t\t\t\t==================================================================================================================\n");
			showLine();
		}
	}
	return returncontrollerListPlayer;
}
/// @brief controllerListReportFirstCriteria		LISTA CANTIDAD TOTAL DE VENTAS Y SUS VENTAS.
///
/// @param pListSale								LINKEDLIST VENTAS.
/// @return 										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerListReportFirstCriteria(LinkedList *pListSale)
{
	int returnControllerListReportFirstCriteria = ERROR;
	int firstCriteriaCounter;
	if (pListSale != NULL)
	{
		firstCriteriaCounter = ll_count(pListSale, getTotalAmountSaleCriteria);
		printf("\n\t\t\t\t\t\t\t\t\t\t-----------------------------------------"
				"\n\t\t\t\t\t\t\t\t\t\t|CUENTA CON %d UNIDADES TOTALES VENDIDAS|\n"
				"\t\t\t\t\t\t\t\t\t\t-----------------------------------------\n", firstCriteriaCounter);
		if (controllerListSales(pListSale) == SUCCESS)
		{
			returnControllerListReportFirstCriteria = SUCCESS;
		}
	}
	return returnControllerListReportFirstCriteria;
}
/// @brief controllerListReportSecondtCriteria			LISTA CANTIDAD Y VENTAS MAYORES A $10000.
///
/// @param pListSale									LINKEDLIST VENTAS.
/// @return 											RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerListReportSecondtCriteria(LinkedList *pListSale)
{
	int returnControllerListReportSecondCriteria = ERROR;
	int secondCriteriaCounter;
	LinkedList *pAuxLinkedList = NULL;
	if (pListSale != NULL)
	{
		pAuxLinkedList = ll_newLinkedList();
		if (pAuxLinkedList != NULL)
		{
			secondCriteriaCounter = ll_count(pListSale, getAmountSalesFirstCriteria);
			pAuxLinkedList = ll_filter(pListSale, getAmountSalesFirstCriteria);
			if (secondCriteriaCounter > 0 && pAuxLinkedList != NULL)
			{
				printf("\n\t\t\t\t\t\t\t\t\t\t---------------------------------------"
						"\n\t\t\t\t\t\t\t\t\t\t|CUENTA CON %d VENTAS MAYORES A $10000|\n"
						"\t\t\t\t\t\t\t\t\t\t---------------------------------------\n", secondCriteriaCounter);
				if (controllerListSales(pAuxLinkedList) == SUCCESS)
				{
					returnControllerListReportSecondCriteria = SUCCESS;
				}
			}
		}
	}
	ll_deleteLinkedList(pAuxLinkedList);
	return returnControllerListReportSecondCriteria;
}
/// @brief	controllerListReportthirdCriteria				LISTA CANTIDAD Y VENTAS MAYORES A $20000.
///
/// @param pListSale										LINKEDLIST VENTAS.
/// @return 												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerListReporthirdCriteria(LinkedList *pListSale)
{
	int returnControllerListReportThirdCriteria = ERROR;
	int thirdCriteriaCounter;
	LinkedList *pAuxLinkedList = NULL;
	if (pListSale != NULL)
	{
		pAuxLinkedList = ll_newLinkedList();
		if (pAuxLinkedList != NULL)
		{
			thirdCriteriaCounter = ll_count(pListSale, getAmountSalesSecondCriteria);
			pAuxLinkedList = ll_filter(pListSale, getAmountSalesSecondCriteria);
			if (thirdCriteriaCounter > 0 && pAuxLinkedList != NULL)
			{
				printf("\n\t\t\t\t\t\t\t\t\t\t--------------------------------------"
						"\n\t\t\t\t\t\t\t\t\t\t|CUENTA CON %d VENTAS MAYORES A $20000|\n"
						"\t\t\t\t\t\t\t\t\t\t--------------------------------------\n", thirdCriteriaCounter);
				if (controllerListSales(pAuxLinkedList) == SUCCESS)
				{
					returnControllerListReportThirdCriteria = SUCCESS;
				}
			}
		}
	}
	ll_deleteLinkedList(pAuxLinkedList);
	return returnControllerListReportThirdCriteria;
}
/// @brief controllerListModelCarCriteria						LISTA CANTIDAD Y VENTAS DE MODELO MATRIX.
///
/// @param pListSale											LINKEDLIST VENTAS.
/// @return 													RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerListModelCarCriteria(LinkedList *pListSale)
{
	int returnControllerListReportModelCarCriteria = ERROR;
	int modelCarCriteria;
	LinkedList *pAuxLinkedList = NULL;
	if (pListSale != NULL)
	{
		pAuxLinkedList = ll_newLinkedList();

		if (pAuxLinkedList != NULL)
		{
			modelCarCriteria = ll_count(pListSale, getModelCarCriteria);
			pAuxLinkedList = ll_filter(pListSale, getModelCarCriteriaMatrix);
			if (modelCarCriteria > 0 && pAuxLinkedList != NULL)
			{
				printf("\n\t\t\t\t\t\t\t\t\t\t---------------------------------------"
						"\n\t\t\t\t\t\t\t\t\t\t|CUENTA CON %d MODELOS MATRIX VENDIDOS|\n"
						"\t\t\t\t\t\t\t\t\t\t---------------------------------------\n", modelCarCriteria);
				if (controllerListSales(pAuxLinkedList) == SUCCESS)
				{
					returnControllerListReportModelCarCriteria = SUCCESS;
				}
			}
		}
	}
	ll_deleteLinkedList(pAuxLinkedList);
	return returnControllerListReportModelCarCriteria;
}
/// @brief controllerGeneratesReportSale			FILTRA Y GENERA INFORME DE VENTA.
///
/// @param path										PUNTERO STRING
/// @param LinkedList								LINKEDLIST VENTAS.
/// @return											RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerGeneratesReportSale(char *path, LinkedList *pListSale)
{
	int returnControllerGenerateReportSale = ERROR;
	int firstCriteriaCounter;
	int secondCriteriaCounter;
	int thirdCriteriaCounter;
	int modelCarCriteria;
	LinkedList *pAuxLinkedList = NULL;

	if (path != NULL && pListSale != NULL)
	{
		pAuxLinkedList = ll_newLinkedList();

		if (pAuxLinkedList != NULL)
		{
			firstCriteriaCounter = ll_count(pListSale, getTotalAmountSaleCriteria);
			secondCriteriaCounter = ll_count(pListSale, getAmountSalesFirstCriteria);
			thirdCriteriaCounter = ll_count(pListSale, getAmountSalesSecondCriteria);
			modelCarCriteria = ll_count(pListSale, getModelCarCriteria);
			pAuxLinkedList = ll_filter(pListSale, getModelCarCriteriaMatrix);

			if (controllerSaveReportTxt(path, pAuxLinkedList, firstCriteriaCounter, secondCriteriaCounter, thirdCriteriaCounter, modelCarCriteria) == SUCCESS)
			{
				returnControllerGenerateReportSale = SUCCESS;
			}
		}
	}
	ll_deleteLinkedList(pAuxLinkedList);
	return returnControllerGenerateReportSale;
}
/// @brief	controllerSaveReportTxt						GUARDA DATOS DE VENTA EN ARCHIVO TXT EN MODO TEXTO.
///
/// @param path											PUNTERO STRING
/// @param LinkedList									LINKEDLIST VENTAS.
/// @param firstCriteriaCounter							ENTERO.
/// @param secondCriteriaCounter						ENTERO.
/// @param thirdCriteriaCounter							ENTERO.
/// @param modelCarCriteria								ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerSaveReportTxt(char *path, LinkedList *pListSale, int firstCriteriaCounter, int secondCriteriaCounter, int thirdCriteriaCounter, int modelCarCriteria)
{
	int returnControllerSaveSalesTextMode = ERROR;
	FILE *pFile = NULL;
	int lenListSale;
	sSale *pSale = NULL;
	int auxId;
	short auxDay;
	short auxMonth;
	short auxYear;
	char auxModel[50];
	short auxAmount;
	float auxUnitPrice;
	char auxCreditCardNumber[17];
	if (path != NULL)
	{
		pFile = fopen(path, "w");
		if (pFile != NULL)
		{
			fprintf(pFile, "============================INFORME-DE-VENTAS============================\n"
					"|\t- Cantidad de unidades vendidas totales: %d\t\t\t|\n"
					"|\t- Cantidad de ventas por un monto mayor a $10000: %d\t\t|\n"
					"|\t- Cantidad de ventas por un monto mayor a $20000: %d\t\t|\n"
					"|\t- Cantidad de modelos Matrix vendidos: %d\t\t\t|\n"
					"=========================================================================\n", firstCriteriaCounter, secondCriteriaCounter, thirdCriteriaCounter, modelCarCriteria);
			lenListSale = ll_len(pListSale);
			if (lenListSale > 0)
			{
				fprintf(pFile, "=======================================LISTADO-MODELOS-MATRIX-VENDIDOS============================================\n"
						"| ID  |  FECHA VENTA   |     MODELO DE AUTO      | CANTIDAD |   PRECIO UNITARIO   |      TARJETA DE CREDITO      |\n"
						"==================================================================================================================\n");
				for (int i = 0; i < lenListSale; i++)
				{
					pSale = (sSale*) ll_get(pListSale, i);
					if (pSale != NULL)
					{
						if (getIdSale(pSale, &auxId) == SUCCESS && getDaySale(pSale, &auxDay) == SUCCESS && getMonthSale(pSale, &auxMonth) == SUCCESS && getYearSale(pSale, &auxYear) == SUCCESS && getModelSale(pSale, auxModel) == SUCCESS && getAmountSale(pSale, &auxAmount) == SUCCESS
								&& getUnitPriceSale(pSale, &auxUnitPrice) == SUCCESS && getCreditCardNumber(pSale, auxCreditCardNumber) == SUCCESS)
						{
							if (fprintf(pFile, "|%-5d| %-.2hd / %-.2hd / %-2hd | %-24s|%-10hd|$%-20.2f|%-30s|\n", auxId, auxDay, auxMonth, auxYear, auxModel, auxAmount, auxUnitPrice, auxCreditCardNumber) > 0)
							{
								returnControllerSaveSalesTextMode = SUCCESS;
							}
						}
					}
				}
				fprintf(pFile, "==================================================================================================================\n");
			}
			fclose(pFile);
		}
	}
	return returnControllerSaveSalesTextMode;
}

