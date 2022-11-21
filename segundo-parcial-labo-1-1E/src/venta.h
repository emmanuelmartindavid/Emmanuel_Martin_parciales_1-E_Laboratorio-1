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
#define NOEDIT 3

typedef struct
{
	short day;
	short month;
	short year;
} sDate;

typedef struct
{
	int id;
	char model[50];
	short amount;
	float unitPrice;
	char creditCardNumber[17];
	sDate date;
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
/// @param pAmountStr									PUNTERO STRING.
/// @param pUnitPriceStr								PUNTERO STRING.
/// @param pCreditCardNumberStr							PUNTERO STRING.
/// @return												RETORNA PUNTERO DE ENTIDAD CREADO CON SUS PARAMETROS SETEADOS EN CASO CORRECTO. RETORNA NULL EN CASO CONTRARIO.
sSale* newSaleParameters(char *pIdStr, char *pDayStr, char *pMonthStr, char *pYearStr, char *pModelStr, char *pAmountStr, char *pUnitPriceStr, char *pCreditCardNumberStr);
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
/// @param 	day										    ENTERO.
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
/// @param year											ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setYearSale(sSale *this, short year);
/// @brief getYearSale									OBTIENE POSICION DE JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pYear										PUNTERO ENTERO.
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
/// @param amount										ENTERO
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setAmountSale(sSale *this, short amount);
/// @brief getAmountSale								OBTIENE CANTIDAD DE VENTA.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pAmount										PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getAmountSale(sSale *this, short *pAmount);
/// @brief	setUnitPriceSale										SETEA PRECIO UNITARIO DE VENTA.
///
/// @param this														PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param unitPrice												FLOTANTE
/// @return															RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setUnitPriceSale(sSale *this, float unitPrice);
/// @brief getUnitPriceSale											OBTIENE PRECIO UNITARIO DE VENTA.
///
/// @param this														PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pUnitPrice												PUNTERO FLOTANTE.
/// @return															RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getUnitPriceSale(sSale *this, float *pUnitPrice);
/// @brief	setCreditCardNumber										SETEA NUMERO DE TARJETA DE CREDITO DE VENTA.
///
/// @param this														PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param creditCardNumber											ENTERO
/// @return															RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setCreditCardNumber(sSale *this, char *pCreditCardNumber);
/// @brief getCreditCardNumber										OBTIENE NUMERO DE TARJETA DE CREDITO DE VENTA.
///
/// @param this														PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @param pCreditCardNumber										PUNTERO ENTERO.
/// @return															RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getCreditCardNumber(sSale *this, char *pCreditCardNumber);
/// @brief editDaySale											EDICION DE CANTIDAD DE VENTA.
///
/// @param this													PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return														RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editDaySale(sSale *this);
/// @brief editMonthSale										EDICION DE MES DE VENTA.
///
/// @param this													PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return														RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editMonthSale(sSale *this);
/// @brief editYearSale											EDICION DE ANIO DE VENTA.
///
/// @param this													PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return														RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editYearSale(sSale *this);
/// @brief editModel											EDICION DE MODELO DE VEHICULO.
///
/// @param this													PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return														RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editModel(sSale *this);
/// @brief editAmountSale										EDICION DE CANTIDAD DE VENTA.
///
/// @param this													PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return														RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editAmountSale(sSale *this);
/// @brief editUnitPriceSale									EDICION DE PRECIO UNITARIO DE VENTA.
///
/// @param this													PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return														RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editUnitPriceSale(sSale *this);
/// @brief editCreditCardNumber									EDICION DE NUMERO DE TARJETA DE CREDITO.
///
/// @param this													PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return														RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editCreditCardNumber(sSale *this);
/// @brief editOneSale											EDICION DE UNA VENTA.
///
/// @param this													PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return														RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO. RETORNO 3 EN CASO DE NO HABER REALIZADO MODIFICACIONES EN LA VENTA.
int editOneSale(sSale *this);
/// @brief gtTotalAmountSaleCriteria							OBTIENE CRITERIO PARA OBTENER TOTAL DE  UNIDADES DE VENTA.
///
/// @param pListSale											LINKEDLIST VENTAS.
/// @param pTotalAmount											PUNTERO ENTERO
/// @return 													RETORNA ACUMULADOR DE CANITDAD DE ELEMENTO VENTA A PASAR POR LL_COUNT.
int getTotalAmountSaleCriteria(void *this);
/// @brief getAmountSalesFirstCriteria							OBTIENE CRITERIO DE PRECIOS POR VENTA MAYORES $10000
///
/// @param this													PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return														RETORNA ACUMULADOR DE CANITDAD DE ELEMENTO VENTA A PASAR POR LL_COUNT.
int getAmountSalesFirstCriteria(void *this);
/// @brief getGetAmountSalesSecondtCriteria						OBTIENE CRITERIO DE PRECIOS POR VENTA MAYORES $20000
///
/// @param this													PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return														RETORNA ACUMULADOR DE CANITDAD DE ELEMENTO VENTA A PASAR POR LL_COUNT.
int getAmountSalesSecondCriteria(void *this);
/// @brief getModelCarCriteria									OBTIENE CRITERIO DE MODELO DE AUTO TIPO MATRIX.
///
/// @param this													PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return														RETORNA ACUMULADOR DE CANITDAD DE ELEMENTO VENTA A PASAR POR LL_COUNT.
int getModelCarCriteria(void *this);
/// @brief getModelCarCriteriaMatrix							OBTIENE CRITERIO PARA OBTENER VENTAS DE TIPO DE MODELO MATRIX.
///
/// @param this													PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return														RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getModelCarCriteriaMatrix(void *this);
/// @brief compareSaleById						COMPARA VENTAS POR ID.
///
/// @param pPlayerOne							PUNTERO TIPO VOID.
/// @param pPlayerTwo							PUNTERO TIPO VOID.
/// @return										RETORNA COMPARACION DE ID.
int compareSaleById(void *thisOne, void *thisTwo);
/// @brief	listOneSale											LISTA UNA VENTA.
///
/// @param this													PUNTERO DE TIPO ESTRUCTURA VENTA.
/// @return														RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int listOneSale(sSale *this);
/// @brief
///
void showSaleData();
/// @brief
///
void showLine();
#endif /* VENTA_H_ */
