/*
 * Controller.h
 *
 *  Created on: 16 nov. 2022
 *      Author: cuerpos
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#define REMOVECANCEL -2
#define NOSALE -3
#define NOEDIT 3
/// @brief  controllerFindSaleById		FUNCION PARA BUSCAR INDICE DE ELEMENTO
///
/// @param pArrayListPlayer				LINKEDLIST VENTAS.
/// @param idPlayer						ENTERO
/// @return								RETORNO  POSICION DE VENTA EN CASO CORRECTO. RETORNO ERROR(-1) EN CASO CONTRARIO.
int controllerFindSaleById(LinkedList *pListSale, int idSale);
/// @brief controllerLoadSaleFromText	  	CARGA DATOS DE VENTAS DESDE ARCHIVO CSV EN MODO TEXTO.
///
/// @param path								PUNTERO STRING
/// @param pArrayListPlayer					LINKEDLIST VENTAS
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerLoadSaleFromText(char *path, LinkedList *pListSale);
/// @brief	controllerSaveSalesTextMode		GUARDA DATOS DE VENTE EN ARCHIVO CSV EN MODO TEXTO.
///
/// @param path								PUNTERO STRING
/// @param LinkedList						LINKEDLIST VENTAS.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerSaveSalesTextMode(char *path, LinkedList *pListSale);
/// @brief controllerLoadIdSaleFromText	  	CARGA ID DE VENTA A DAR DE ALTA DESDE ARCHIVO CSV EN MODO TEXTO.
///
/// @param path								PUNTERO STRING
/// @param pListSale						LINKEDLIST VENTAS
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerLoadIdSaleFromText(char *path, int *pIdSale);
/// @brief controllerSaveIdSaleTextMode      GAURDA ID DE VENTA EN MODO TEXTO A ARCHIVO CSV.
///
/// @param path								 PUNTERO STRING.
/// @param pIdSale							 PUNTERO ENTERO.
/// @return									 RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerSaveIdSaleTextMode(char *path, int *pIdSale);

/// @brief controllerAddSale		ALTA DE VENTA.
///
/// @param pListSale				LINKEDLIST VENTAS.
/// @param pListSale				ENTERO.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerAddSale(LinkedList *pListSale, int *idSale);
/// @brief controllerRemoveSale		EDITAR DE VENTA.
///
/// @param pListSale				LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerEditSale(LinkedList *pListSale);
/// @brief controllerRemoveSale		BAJA DE VENTA.
///
/// @param pArrayListPlayer			LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerRemoveSale(LinkedList *pListSale);
/// @brief controllerGetTotalAmountSale				OBTIENE TOTAL UNIDADES DE VENTA.
///
/// @param pListSale								LINKEDLIST VENTAS.
/// @param pTotalAmount								PUNTERO ENTERO
/// @return 										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerGetTotalAmountSale(LinkedList *pListSale, int *pTotalAmount);
int controllerReportSale(char *path, LinkedList *pListSale);
int controllerGenerateReportTxt(char *path, LinkedList *pListSale, int firstCriteriaCounter, int secondCriteriaCounter, int thirdCriteriaCounter, int modelCarCriteria);
/// @brief  controllerListSales   	LISTADO VENTAS.
///
/// @param pArrayListPlayer			LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerListSales(LinkedList *pListSale);

#endif /* CONTROLLER_H_ */
