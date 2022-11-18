/*
 * venta.h
 *
 *  Created on: 16 nov. 2022
 *      Author: cuerpos
 */

#ifndef VENTA_H_
#define VENTA_H_
#define ERROR -1
#define SUCCESS 1

typedef struct
{
	int id;
	short day;
	short month;
	short year;
	char model[50];
	short ammount;
	float unitPrice;
	long int creditCardNumber;
} sSale;
/// @brief	newSale 						    		CONTRSTRUCTOR DE ENTIDAD VENTA EN MEMORIA DINAMICA.
///
/// @return			 						 			RETORNA PUNTERO DE ENTIDAD CREADO EN MEMORIA DINAMICA EN CASO CORRECTO. RETORNA NULL EN CASO CONTRARIO.
sSale* newSale();
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
sSale* newSaleParameters(char *pIdStr, char *pDayStr, char *pMonthStr, char *pYearStr, char *pModelStr, char *pAmmountStr, char *pUnitPriceStr, char *pCreditCardNumberStr);
/// @brief	deleteSale									LIBERA ESPACIO EN MEMORIA DINAMICA DEL TIPO PUNTERO POR PARAMETRO EN CASO DE SER NECESARIO.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
void deleteSale(sSale *this);
/// @brief setIdSale									SETEA ID DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param id											ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setIdSale(sSale *this, int id);
/// @brief	getIdSale									OBTIENE ID DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pId											PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getIdSale(sSale *this, int *pId);
/// @brief setDaySale									SETEA DIA DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param 	day											PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setDaySale(sSale *this, short day);
/// @brief getDaySale									OBTIENE DIA DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pDay											PUNTERO ENTERO
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getDaySale(sSale *this, short *pDay);
/// @brief setMonthSale									SETEA MES DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param month										ENTERO
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setMonthSale(sSale *this, short month);
/// @brief getMonthSale									OBTIENE MES DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pMonth										PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getMonthSale(sSale *this, short *pMonth);
/// @brief setYearSale 									SETEA POSICION DE JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pYear										ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setYearSale(sSale *this, short year);
/// @brief getYearSale									OBTIENE POSICION DE JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param position										PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getYearSale(sSale *this, short *pYear);
/// @brief setModelSale									SETEA NACIONALIDAD DE JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param pModel										PUNTERO STRING.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setModelSale(sSale *this, char *pModel);
/// @brief	getModelSale								OBTIENE MODELO DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pModel										PUNTERO STRING.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getModelSale(sSale *this, char *pModel);
/// @brief	setAmmountSale								SETEA CANTIDAD DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param ammount										ENTERO
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setAmmountSale(sSale *this, short ammount);
/// @brief getIdNationalTeamPLayer						OBTIENE CANTIDAD DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pAmmount										PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getAmmountSale(sSale *this, short *pAmmount);
/// @brief	setUnitPriceSale							SETEA PRECIO UNITARIO DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param idNationalTeam								FLOTANTE
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setUnitPriceSale(sSale *this, float unitPrice);
/// @brief getIdNationalTeamPLayer						OBTIENE PRECIO UNITARIO DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pUnitPrice									PUNTERO FLOTANTE.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getUnitPriceSale(sSale *this, float *pUnitPrice);
/// @brief	setIdNationalTeamPlayer						SETEA NUMERO DE TARJETA DE CREDITO DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param creditCardNumber								ENTERO
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setCreditCardNumber(sSale *this, long int creditCardNumber);
/// @brief getIdNationalTeamPLayer						OBTIENE NUMERO DE TARJETA DE CREDITO DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pCreditCardNumber							PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getCreditCardNumber(sSale *this, long int *pCreditCardNumber);

/// @brief	listOnePlayer								LISTA UN JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int listOneSale(sSale *this);
/// @brief editFullNamePlayer						EDICION DE NOMBRE DE JUGADOR.
///
/// @param this										PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @return											RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.

#endif /* VENTA_H_ */
