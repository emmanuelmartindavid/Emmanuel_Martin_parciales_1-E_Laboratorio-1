/*
 * Venta.c
 *
 *  Created on: 16 nov. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "venta.h"
#include "validaciones.h"
#include "menus.h"
/// @brief	newSale 						    		CONTRSTRUCTOR DE ENTIDAD VENTA EN MEMORIA DINAMICA.
///
/// @return			 						 			RETORNA PUNTERO DE ENTIDAD CREADO EN MEMORIA DINAMICA EN CASO CORRECTO. RETORNA NULL EN CASO CONTRARIO.
sSale* newSale()
{
	sSale *newSale = NULL;
	newSale = (sSale*) malloc(sizeof(sSale));
	if (newSale != NULL)
	{
		newSale->id = 0;
		newSale->date.day = 0;
		newSale->date.month = 0;
		newSale->date.year = 0;
		strcpy(newSale->model, " ");
		newSale->amount = 0;
		newSale->unitPrice = 0;
		strcpy(newSale->creditCardNumber, " ");

	}
	return newSale;
}
/// @brief newSaleParameters							CONTRUCTOR DE ENTIDAD VENTA CON SU PARAMETROS A SETEAR.
///
/// @param pIdStr										PUNTERO STRING.
/// @param pDayStr										PUNTERO STRING.
/// @param pMonthStr									PUNTERO STRING.
/// @param pYearStr										PUNTERO STRING.
/// @param pModelStr									PUNTERO STRING.
/// @param pAmountStr									PUNTERO STRING.
/// @param pUnitPriceStr								PUNTERO STRING.
/// @param pCreditCardNumberStr							PUNTERO STRING.
/// @return												RETORNA PUNTERO DE ENTIDAD CREADO CON SUS PARAMETROS SETEADOS EN CASO CORRECTO. RETORNA NULL EN CASO CONTRARIO.
sSale* newSaleParameters(char *pIdStr, char *pDayStr, char *pMonthStr, char *pYearStr, char *pModelStr, char *pAmountStr, char *pUnitPriceStr, char *pCreditCardNumberStr)
{
	sSale *auxNewSale = NULL;
	if (pIdStr != NULL && pDayStr != NULL && pDayStr != NULL && pMonthStr != NULL && pYearStr != NULL && pModelStr != NULL && pAmountStr != NULL && pUnitPriceStr != NULL && pCreditCardNumberStr != NULL)
	{
		auxNewSale = newSale();
		if (auxNewSale != NULL)
		{
			if (!(setIdSale(auxNewSale, atoi(pIdStr)) && setDaySale(auxNewSale, atoi(pDayStr)) && setMonthSale(auxNewSale, atoi(pMonthStr)) && setYearSale(auxNewSale, atoi(pYearStr)) && setModelSale(auxNewSale, pModelStr) && setAmountSale(auxNewSale, atoi(pAmountStr))
					&& setUnitPriceSale(auxNewSale, atof(pUnitPriceStr)) && setCreditCardNumber(auxNewSale, pCreditCardNumberStr)))
			{
				deleteSale(auxNewSale);
			}
		}
	}
	return auxNewSale;
}

/// @brief	deleteSale									LIBERA ESPACIO EN MEMORIA DINAMICA DEL TIPO PUNTERO POR PARAMETRO EN CASO DE SER NECESARIO.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
void deleteSale(sSale *this)
{
	free(this);
}
/// @brief setIdSale									SETEA ID DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param id											ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setIdSale(sSale *this, int id)
{
	int returnSetIdSale = ERROR;
	if (this != NULL && id > 0)
	{
		this->id = id;
		returnSetIdSale = SUCCESS;
	}
	return returnSetIdSale;
}
/// @brief	getIdSale									OBTIENE ID DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pId											PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getIdSale(sSale *this, int *pId)
{
	int returnGetIdsale = ERROR;
	if (this != NULL && pId != NULL)
	{
		*pId = this->id;
		returnGetIdsale = SUCCESS;
	}
	return returnGetIdsale;
}
/// @brief setDaySale									SETEA DIA DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param day											ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setDaySale(sSale *this, short day)
{
	int returnSetDaySale = ERROR;
	if (this != NULL && day > 0 && day <= 31)
	{
		this->date.day = day;
		returnSetDaySale = SUCCESS;
	}

	return returnSetDaySale;
}
/// @brief getDaySale									OBTIENE DIA DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pDay											PUNTERO ENTERO
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getDaySale(sSale *this, short *pDay)
{
	int returnGetDaySale = ERROR;

	if (this != NULL && pDay != NULL)
	{
		*pDay = this->date.day;
		returnGetDaySale = SUCCESS;
	}

	return returnGetDaySale;
}
/// @brief setMonthSale									SETEA MES DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param month										ENTERO
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setMonthSale(sSale *this, short month)
{
	int returnSetMonthSale = ERROR;
	if (this != NULL && month > 0 && month <= 12)
	{
		this->date.month = month;
		returnSetMonthSale = SUCCESS;
	}

	return returnSetMonthSale;
}
/// @brief getMonthSale									OBTIENE MES DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pMonth										PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getMonthSale(sSale *this, short *pMonth)
{
	int returnGetMonthSale = ERROR;
	if (this != NULL && pMonth != NULL)
	{
		*pMonth = this->date.month;
		returnGetMonthSale = SUCCESS;
	}

	return returnGetMonthSale;
}
/// @brief setYearSale 									SETEA POSICION DE JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param year										    ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setYearSale(sSale *this, short year)
{
	int returnSetYearSale = ERROR;
	if (this != NULL && year > 2017 && year <= 2022)
	{
		this->date.year = year;
		returnSetYearSale = SUCCESS;
	}

	return returnSetYearSale;
}
/// @brief getYearSale									OBTIENE POSICION DE JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pYear										PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getYearSale(sSale *this, short *pYear)
{
	int returnGetYearSale = ERROR;
	if (this != NULL && pYear != NULL)
	{
		*pYear = this->date.year;
		returnGetYearSale = SUCCESS;
	}

	return returnGetYearSale;
}
/// @brief setModelSale									SETEA NACIONALIDAD DE JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param pModel										PUNTERO STRING.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setModelSale(sSale *this, char *pModel)
{
	int returnSetModelSale = ERROR;
	if (this != NULL && pModel != NULL)
	{
		strcpy(this->model, pModel);
		returnSetModelSale = SUCCESS;
	}

	return returnSetModelSale;
}
/// @brief	getModelSale								OBTIENE MODELO DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pModel										PUNTERO STRING.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getModelSale(sSale *this, char *pModel)
{
	int returnGetModelSale = ERROR;
	if (this != NULL && pModel != NULL)
	{
		strcpy(pModel, this->model);
		returnGetModelSale = SUCCESS;
	}

	return returnGetModelSale;
}
/// @brief	setAmmountSale								SETEA CANTIDAD DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param ammount										ENTERO
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setAmountSale(sSale *this, short amount)
{
	int returnSetAmmountSale = ERROR;
	if (this != NULL && amount > 0)
	{
		this->amount = amount;
		returnSetAmmountSale = SUCCESS;
	}

	return returnSetAmmountSale;
}
/// @brief getAmmountSale								OBTIENE CANTIDAD DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pAmmount										PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getAmountSale(sSale *this, short *pAmount)
{
	int returnGetAmmountSale = ERROR;
	if (this != NULL && pAmount != NULL)
	{
		*pAmount = this->amount;
		returnGetAmmountSale = SUCCESS;
	}
	return returnGetAmmountSale;
}
/// @brief	setUnitPriceSale							SETEA PRECIO UNITARIO DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param unitPrice								    FLOTANTE
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setUnitPriceSale(sSale *this, float unitPrice)
{
	int returnSerUnitPriceSale = ERROR;
	if (this != NULL && unitPrice > 0)
	{
		this->unitPrice = unitPrice;
		returnSerUnitPriceSale = SUCCESS;
	}

	return returnSerUnitPriceSale;
}
/// @brief getUnitPriceSale								OBTIENE PRECIO UNITARIO DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pUnitPrice									PUNTERO FLOTANTE.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getUnitPriceSale(sSale *this, float *pUnitPrice)
{
	int returnGetUnitPriceSale = ERROR;
	if (this != NULL && pUnitPrice != NULL)
	{
		*pUnitPrice = this->unitPrice;
		returnGetUnitPriceSale = SUCCESS;
	}

	return returnGetUnitPriceSale;
}
/// @brief	setCreditCardNumber							SETEA NUMERO DE TARJETA DE CREDITO DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param creditCardNumber								PUNTERO SRING
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setCreditCardNumber(sSale *this, char *pCreditCardNumber)
{
	int returnSetCreditCardNumber = ERROR;
	if (this != NULL && pCreditCardNumber != NULL)
	{
		strcpy(this->creditCardNumber, pCreditCardNumber);
		returnSetCreditCardNumber = SUCCESS;
	}

	return returnSetCreditCardNumber;
}
/// @brief getCreditCardNumber						OBTIENE NUMERO DE TARJETA DE CREDITO DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pCreditCardNumber							PUNTERO STRING.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getCreditCardNumber(sSale *this, char *pCreditCardNumber)
{
	int returnGetCreditCard = ERROR;
	if (this != NULL && pCreditCardNumber != NULL)
	{
		strcpy(pCreditCardNumber, this->creditCardNumber);
		returnGetCreditCard = SUCCESS;
	}

	return returnGetCreditCard;
}
/// @brief editDaySale							EDICION DE DIA DE VENTA.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editDaySale(sSale *this)
{
	int returnEditDaySale = ERROR;
	short auxDay;
	if (this != NULL)
	{
		if (utn_getNumberShort(&auxDay, "\n\t\t\t\t\t\t\t\t\t\t\tINGRESE DIA DE VENTA.\n", "\n\t\t\t\t\t\t\t\t\t\t\tERROR. REINTENTE.\n", 1, 31, 3) == 0)
		{
			if (setDaySale(this, auxDay) == SUCCESS)
			{
				returnEditDaySale = SUCCESS;
			}
		}
	}
	return returnEditDaySale;
}
/// @brief editMonthSale						EDICION DE MES DE VENTA.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editMonthSale(sSale *this)
{
	int returnEditMonthSale = ERROR;
	short auxMonth;
	if (this != NULL)
	{
		if (utn_getNumberShort(&auxMonth, "\n\t\t\t\t\t\t\t\t\t\t\tINGRESE MES DE VENTA.\n", "\n\t\t\t\t\t\t\t\t\t\t\tERROR. REINTENTE.\n", 1, 12, 3) == 0)
		{
			if (setMonthSale(this, auxMonth) == SUCCESS)
			{
				returnEditMonthSale = SUCCESS;
			}
		}
	}
	return returnEditMonthSale;
}
/// @brief editYearSale							EDICION DE ANIO DE VENTA.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editYearSale(sSale *this)
{
	int returnEditYearSale = ERROR;
	short auxYear;
	if (this != NULL)
	{
		if (utn_getNumberShort(&auxYear, "\n\t\t\t\t\t\t\t\t\tINGRESE ANIO DE VENTA. DESDE 2020 HASTA 2022, INCLUSIVE.\n", "\n\t\t\t\t\t\t\t\t\t\t\tERROR. REINTENTE.\n", 2020, 2022, 3) == 0)
		{
			if (setYearSale(this, auxYear) == SUCCESS)
			{
				returnEditYearSale = SUCCESS;
			}
		}
	}
	return returnEditYearSale;
}
/// @brief editModel								EDICION DE MODELO DE VEHICULO.
///
/// @param this										PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return											RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editModel(sSale *this)
{
	int returnEditModel = ERROR;
	char auxModel[20];
	if (this != NULL)
	{
		if (utn_getModelCar(auxModel) == 0)
		{
			if (setModelSale(this, auxModel) == SUCCESS)
			{
				returnEditModel = SUCCESS;
			}
		}
	}
	return returnEditModel;
}
/// @brief editAmountSale						EDICION DE CANTIDAD DE VENTA.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editAmountSale(sSale *this)
{
	int returnEditAmountSale = ERROR;
	short auxAmmount;
	if (this != NULL)
	{
		if (utn_getNumberShort(&auxAmmount, "\n\t\t\t\t\t\t\t\t\tINGRESE CANTIDAD. RANGO PERMITIDO, 1 A 4 INCLUSIVE.\n", "\n\t\t\t\t\t\t\t\t\t\t\tERROR. REINTENTE.\n", 1, 4, 3) == 0)
		{
			if (setAmountSale(this, auxAmmount) == SUCCESS)
			{
				returnEditAmountSale = SUCCESS;
			}
		}
	}
	return returnEditAmountSale;
}
/// @brief editUnitPriceSale					EDICION DE PRECIO UNITARIO DE VENTA.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editUnitPriceSale(sSale *this)
{
	int returnEditUnitPriceSale = ERROR;
	float auxYear;
	if (this != NULL)
	{
		if (utn_getNumberFloat(&auxYear, "\n\t\t\t\t\t\t\t\tINGRESE PRECIO UNITARIO DE MODELO. DESDE $1000 HASTA $9000 (USD), INCLUSIVE.\n", "\n\t\t\t\t\t\t\t\t\t\t\tERROR. REINTENTE.\n", 1000, 9000, 3) == 0)
		{
			if (setUnitPriceSale(this, auxYear) == SUCCESS)
			{
				returnEditUnitPriceSale = SUCCESS;
			}
		}
	}
	return returnEditUnitPriceSale;
}
/// @brief editCreditCardNumber					EDICION DE NUMERO DE TARJETA DE CREDITO.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editCreditCardNumber(sSale *this)
{
	int returnEditCreditCardNumber = ERROR;
	char auxCreditCardNumber[17];
	if (this != NULL)
	{
		if (utn_getValidCreditCardNumber(auxCreditCardNumber, "\n\t\t\t\t\t\t\t\tINGRESE NUMERO DE TARJETA DE CREDITO. COMIENZA CON 4. LLEVA 16 DIGITOS.\n", "\n\t\t\t\t\t\t\t\t\t\t\tERROR. REINTENTE.\n", 3, 17, 16) == 0)
		{
			if (setCreditCardNumber(this, auxCreditCardNumber) == SUCCESS)
			{
				returnEditCreditCardNumber = SUCCESS;
			}
		}
	}
	return returnEditCreditCardNumber;
}

/// @brief editOneSale				EDICION DE UNA VENTA.
///
/// @param this						PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return							RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO. RETORNO 3 EN CASO DE NO HABER REALIZADO MODIFICACIONES EN LA VENTA.
int editOneSale(sSale *this)
{
	int returnrEditOnePlayer;
	int optionEditMenu;
	int flagEditPlayer = NOEDIT;
	if (this != NULL)
	{
		do
		{
			showEditSaleMenu();
			showSaleData();
			listOneSale(this);
			showLine();
			if (utn_getNumber(&optionEditMenu, "\n\t\t\t\t\t\t\t\t\t\t\tINGRESE OPCION.\n", "\n\t\t\t\t\t\t\t\tERROR. REINTENTE.\n", 1, 6, 3) == 0)
			{
				switch (optionEditMenu)
				{
				case 1:
					if (editDaySale(this) == SUCCESS && editMonthSale(this) == SUCCESS && editYearSale(this) == SUCCESS)
					{
						flagEditPlayer = SUCCESS;

					}
					else
					{
						flagEditPlayer = NOEDIT;
					}
					break;
				case 2:
					if (editModel(this) == SUCCESS)
					{
						flagEditPlayer = SUCCESS;
					}
					else
					{
						flagEditPlayer = NOEDIT;
					}
					break;
				case 3:
					if (editAmountSale(this) == SUCCESS)
					{
						flagEditPlayer = SUCCESS;
					}
					else
					{
						flagEditPlayer = NOEDIT;
					}
					break;
				case 4:
					if (editUnitPriceSale(this) == SUCCESS)
					{
						flagEditPlayer = SUCCESS;
					}
					else
					{
						flagEditPlayer = NOEDIT;
					}
					break;
				case 5:
					if (editCreditCardNumber(this) == SUCCESS)
					{
						flagEditPlayer = SUCCESS;
					}
					else
					{
						flagEditPlayer = NOEDIT;
					}
					break;
				}
			}
			else
			{
				returnrEditOnePlayer = ERROR;
				break;
			}
		} while (optionEditMenu != 6);
		returnrEditOnePlayer = flagEditPlayer;
	}
	return returnrEditOnePlayer;
}
/// @brief gtTotalAmountSaleCriteria				OBTIENE CRITERIO PARA OBTENER TOTAL DE  UNIDADES DE VENTA.
///
/// @param pListSale								LINKEDLIST VENTAS.
/// @param pTotalAmount								PUNTERO ENTERO
/// @return 										RETORNA  CANITDAD DE ELEMENTO VENTA A CONTAR POR LL_COUNT.
int getTotalAmountSaleCriteria(void *this)
{
	int returnControllerGetTotalAmountSale=0;
	sSale *pSale = NULL;
	short auxAmount=0;
	if (this != NULL)
	{
		pSale = (sSale*) this;
		if (pSale != NULL)
		{
				if (getAmountSale(pSale, &auxAmount) == SUCCESS)
				{
					returnControllerGetTotalAmountSale= auxAmount;

				}
		}
	}
	return returnControllerGetTotalAmountSale;
}
/// @brief getAmountSalesFirstCriteria				OBTIENE CRITERIO PARA OBTENER CANTIDAD DE VENTAS MAYORES A $10000
///
/// @param this										PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return											RETORNA SUCCESS(1) EN CASO CORRRECTO. 0 EN CASO CONTRARIO.
int getAmountSalesFirstCriteria(void *this)
{
	int returnGetAmountSalesFirstCriteria = 0;
	sSale *pSale = NULL;
	short auxAmount;
	float auxUnitPrice;
	if (this != NULL)
	{
		pSale = (sSale*) this;
		if (pSale != NULL)
		{
			if (getAmountSale(pSale, &auxAmount) == SUCCESS && getUnitPriceSale(pSale, &auxUnitPrice) == SUCCESS)
			{
				if (auxAmount * auxUnitPrice > 10000)
				{
					returnGetAmountSalesFirstCriteria=SUCCESS;
				}
			}
		}
	}
	return returnGetAmountSalesFirstCriteria;
}
/// @brief getAmountSalesSecondtCriteria			OBTIENE CRITERIO PARA OBTENER CANTIDAD DE VENTAS MAYORES A  $20000
///
/// @param this										PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return											RETORNA SUCCESS(1) EN CASO CORRRECTO. 0 EN CASO CONTRARIO.
int getAmountSalesSecondCriteria(void *this)
{
	int returnGetAmountSalesSecondCriteria = 0;
	sSale *pSale = NULL;
	short auxAmount;
	float auxUnitPrice;
	if (this != NULL)
	{
		pSale = (sSale*) this;
		if (pSale != NULL)
		{
			if (getAmountSale(pSale, &auxAmount) == SUCCESS && getUnitPriceSale(pSale, &auxUnitPrice) == SUCCESS)
			{
				if (auxAmount * auxUnitPrice > 20000)
				{
					returnGetAmountSalesSecondCriteria=SUCCESS;
				}
			}
		}
	}
	return returnGetAmountSalesSecondCriteria;
}

/// @brief getModelCarCriteria						OBTIENE CRITERIO PARA OBTENER CANTIDAD DE AUTO TIPO MATRIX.
///
/// @param this										PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return											RETORNA  CANITDAD DE ELEMENTO VENTA A CONTAR  POR LL_COUNT.
int getModelCarCriteria(void *this)
{
	int returnGetAmountSalesSecondCriteria = 0;
	char auxModel[50];
	short auxAmount;
	sSale *pSale = NULL;
	if (this != NULL)
	{
		pSale = (sSale*) this;
		if (pSale != NULL)
		{
			if (getModelSale(this, auxModel) && getAmountSale(this, &auxAmount)==SUCCESS)
			{
				if (stricmp(auxModel, "Matrix") == 0)
				{
					returnGetAmountSalesSecondCriteria = auxAmount;
				}
			}
		}
	}
	return returnGetAmountSalesSecondCriteria;
}
/// @brief getModelCarCriteriaMatrix				OBTIENE CRITERIO PARA OBTENER VENTAS DE TIPO DE MODELO MATRIX.
///
/// @param this										PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return											RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getModelCarCriteriaMatrix(void *this)
{
	int returnGetAmountSalesSecondCriteria = ERROR;
	char auxModel[50];
	sSale *pSale = NULL;

	if (this != NULL)
	{
		pSale = (sSale*) this;
		if (pSale != NULL)
		{
			if (getModelSale(this, auxModel)==SUCCESS)
			{
				if (stricmp(auxModel, "Matrix") == 0)
				{
					returnGetAmountSalesSecondCriteria=SUCCESS;
				}
			}
		}
	}
	return returnGetAmountSalesSecondCriteria;
}
/// @brief	listOneSale									LISTA UNA VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int listOneSale(sSale *this)
{
	int returnListOneSale = ERROR;
	int auxId;
	short auxDay;
	short auxMonth;
	short auxYear;
	char auxModel[100];
	short auxAmmount;
	float auxUnitPrice;
	char auxCreditCardNumber[17];

	if (this != NULL)
	{
		if (getIdSale(this, &auxId) == SUCCESS && getDaySale(this, &auxDay) == SUCCESS && getMonthSale(this, &auxMonth) == SUCCESS && getYearSale(this, &auxYear) == SUCCESS && getModelSale(this, auxModel) == SUCCESS && getAmountSale(this, &auxAmmount) == SUCCESS && getUnitPriceSale(this, &auxUnitPrice) == SUCCESS
				&& getCreditCardNumber(this, auxCreditCardNumber) == SUCCESS)
		{
			printf("\t\t\t\t\t\t|%-5d| %-.2hd / %-.2hd / %-2hd | %-24s|%-10hd|$%-20.2f|%-30s|\n", auxId, auxDay, auxMonth, auxYear, auxModel, auxAmmount, auxUnitPrice, auxCreditCardNumber);
			returnListOneSale = SUCCESS;
		}
	}
	return returnListOneSale;
}
/// @brief showSaleData
///
void showSaleData()
{
	printf("\t\t\t\t\t\t==================================================================================================================\n");
	printf("\t\t\t\t\t\t| ID  |  FECHA VENTA   |     MODELO DE AUTO      | CANTIDAD |   PRECIO UNITARIO   |      TARJETA DE CREDITO      |\n");
	printf("\t\t\t\t\t\t==================================================================================================================\n");
}
/// @brief
///
void showLine()
{
	printf("\t\t\t\t\t\t==================================================================================================================\n");
}
