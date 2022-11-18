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
		newSale->day = 0;
		newSale->month = 0;
		newSale->year = 0;
		strcpy(newSale->model, " ");
		newSale->ammount = 0;
		newSale->unitPrice = 0;
		newSale->creditCardNumber = 0;
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
/// @param pAmmountStr									PUNTERO STRING.
/// @param pUnitPriceStr								PUNTERO STRING.
/// @param pCreditCardNumberStr							PUNTERO STRING.
/// @return												RETORNA PUNTERO DE ENTIDAD CREADO CON SUS PARAMETROS SETEADOS EN CASO CORRECTO. RETORNA NULL EN CASO CONTRARIO.
sSale* newSaleParameters(char *pIdStr, char *pDayStr, char *pMonthStr, char *pYearStr, char *pModelStr, char *pAmmountStr, char *pUnitPriceStr, char *pCreditCardNumberStr)
{
	sSale *auxNewSale = NULL;
	if (pIdStr != NULL && pDayStr != NULL && pDayStr != NULL && pMonthStr != NULL && pYearStr != NULL && pModelStr != NULL && pAmmountStr != NULL && pUnitPriceStr != NULL && pCreditCardNumberStr != NULL)
	{
		auxNewSale = newSale();
		if (auxNewSale != NULL)
		{
			if (!(setIdSale(auxNewSale, atoi(pIdStr)) && setDaySale(auxNewSale, atoi(pDayStr)) && setMonthSale(auxNewSale, atoi(pMonthStr)) && setYearSale(auxNewSale, atoi(pYearStr)) && setModelSale(auxNewSale, pModelStr) && setAmmountSale(auxNewSale, atoi(pAmmountStr))
					&& setUnitPriceSale(auxNewSale, atof(pUnitPriceStr)) && setCreditCardNumber(auxNewSale, atol(pCreditCardNumberStr))))
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
/// @param 	day											PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setDaySale(sSale *this, short day)
{
	int returnSetDaySale = ERROR;
	if (this != NULL && day > 0 && day <= 31)
	{
		this->day = day;
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
		*pDay = this->day;
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
		this->month = month;
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
		*pMonth = this->month;
		returnGetMonthSale = SUCCESS;
	}
	return returnGetMonthSale;
}
/// @brief setYearSale 									SETEA POSICION DE JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pYear										ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setYearSale(sSale *this, short year)
{
	int returnGetYearSale = ERROR;
	if (this != NULL && year > 2017 && year <= 2022)
	{
		this->year = year;
		returnGetYearSale = SUCCESS;
	}
	return returnGetYearSale;
}
/// @brief getYearSale									OBTIENE POSICION DE JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param position										PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getYearSale(sSale *this, short *pYear)
{
	int returnGetYearSale = ERROR;
	if (this != NULL && pYear != NULL)
	{
		*pYear = this->year;
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
int setAmmountSale(sSale *this, short ammount)
{
	int returnSetAmmountSale = ERROR;
	if (this != NULL && ammount > 0)
	{
		this->ammount = ammount;
		returnSetAmmountSale = SUCCESS;
	}
	return returnSetAmmountSale;
}
/// @brief getIdNationalTeamPLayer						OBTIENE CANTIDAD DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pAmmount										PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getAmmountSale(sSale *this, short *pAmmount)
{
	int returnGetAmmountSale = ERROR;
	if (this != NULL && pAmmount != NULL)
	{
		*pAmmount = this->ammount;
		returnGetAmmountSale = SUCCESS;
	}
	return returnGetAmmountSale;
}
/// @brief	setUnitPriceSale							SETEA PRECIO UNITARIO DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param idNationalTeam								FLOTANTE
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
/// @brief getIdNationalTeamPLayer						OBTIENE PRECIO UNITARIO DE VENTA.
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
/// @brief	setIdNationalTeamPlayer						SETEA NUMERO DE TARJETA DE CREDITO DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param creditCardNumber								ENTERO
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setCreditCardNumber(sSale *this, long int creditCardNumber)
{
	int returnSetCreditCardNumber = ERROR;
	if (this != NULL && creditCardNumber > 0)
	{
		this->creditCardNumber = creditCardNumber;
		returnSetCreditCardNumber = SUCCESS;
	}
	return returnSetCreditCardNumber;
}
/// @brief getIdNationalTeamPLayer						OBTIENE NUMERO DE TARJETA DE CREDITO DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pCreditCardNumber							PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getCreditCardNumber(sSale *this, long int *pCreditCardNumber)
{
	int returnGetCreditCard = ERROR;
	if (this != NULL && pCreditCardNumber != NULL)
	{
		*pCreditCardNumber = this->creditCardNumber;
	}
	return returnGetCreditCard;
}
/// @brief	listOnePlayer								LISTA UN JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA JUGADOR.
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
	long int auxCreditCardNumber;

	if (this != NULL)
	{
		if (getIdSale(this, &auxId) == SUCCESS && getDaySale(this, &auxDay) == SUCCESS && getMonthSale(this, &auxMonth) == SUCCESS && getYearSale(this, &auxYear) == SUCCESS && getModelSale(this, auxModel) == SUCCESS && getAmmountSale(this, &auxAmmount) == SUCCESS && getUnitPriceSale(this, &auxUnitPrice) == SUCCESS
				&& getCreditCardNumber(this, &auxCreditCardNumber) == SUCCESS)
		{
			printf("\t\t|%-5d| %-5hd| %-5hd| %-5hd| %-24s|%-5hd|%.2f|%ld|\n", auxId, auxDay, auxMonth, auxYear, auxModel, auxAmmount, auxUnitPrice, auxCreditCardNumber);
			returnListOneSale = SUCCESS;
		}
	}
	return returnListOneSale;
}
