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
/// @brief controllerLoadSalesFromBinary  			CARGA DATOS DE VENTAS DESDE ARCHIVO BIN EN MODO BINARIO.
///
/// @param path												PUNTERO STRING
/// @param pListSale										 LINKEDLIST VENTAS.
/// @return 												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerLoadSalesFromBinary(char *path, LinkedList *pListSale);
/// @brief controllerSaveSalesBinarytMode   			   	 GUARDA DATOS DE JUGADORES DESDE ARCHIVO CSV EN MODO BINARIO.
///
/// @param path								 			 	 PUNTERO STRING
/// @param pListSale										 LINKEDLIST VENTAS.
/// @return									 				 RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerSaveSalesBinarytMode(char *path, LinkedList *pListSale);
/// @brief controllerAddSale		ALTA DE VENTA.
///
/// @param pListSale				LINKEDLIST VENTAS.
/// @param pListSale				ENTERO.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerAddSale(LinkedList *pListSale, int *idSale);
/// @brief controllerRemoveSale		EDITAR DE VENTA.
///
/// @param pListSale				LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO(MODIFICACION HECHA). ERROR(-1) EN CASO CONTRARIO. RETORNA NOEDIT(3) EN CASO DE NO HABER HECHO NINGUNA MODIFIACION.
int controllerEditSale(LinkedList *pListSale);
/// @brief controllerRemoveSale		BAJA DE VENTA.
///
/// @param pArrayListPlayer			LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO. RETORNA REMOVECANCEL(-2) EN CASO DE CANCELAR BAJA. RETORNA NOSALE(-2) EN CASO DE QUE NO EXISTA LA VENTA.
int controllerRemoveSale(LinkedList *pListSale);
/// @brief  controllerListSales   	LISTADO VENTAS.
///
/// @param pArrayListPlayer			LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerListSales(LinkedList *pListSale);
/// @brief controllerListReportFirstCriteria		LISTA CANTIDAD TOTAL DE VENTAS Y SUS VENTAS.
///
/// @param pListSale								LINKEDLIST VENTAS.
/// @return 										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerListReportFirstCriteria(LinkedList *pListSale);
/// @brief controllerListReportSecondtCriteria			LISTA CANTIDAD Y VENTAS MAYORES A $10000.
///
/// @param pListSale								LINKEDLIST VENTAS.
/// @return 										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerListReportSecondtCriteria(LinkedList *pListSale);
/// @brief	controllerListReportthirdCriteria			LISTA CANTIDAD Y VENTAS MAYORES A $20000.
///
/// @param pListSale								LINKEDLIST VENTAS.
/// @return 										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerListReporthirdCriteria(LinkedList *pListSale);
/// @brief controllerListModelCarCriteria			LISTA CANTIDAD Y VENTAS DE MODELO MATRIX.
///
/// @param pListSale								LINKEDLIST VENTAS.
/// @return 										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerListModelCarCriteria(LinkedList *pListSale);
/// @brief 	controllerGeneratesReportSale			FILTRA Y GENERA INFORME DE VENTA.
///
/// @param path								PUNTERO STRING
/// @param LinkedList						LINKEDLIST VENTAS.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerGeneratesReportSale(char *path, LinkedList *pListSale);
/// @brief	controllerSaveReportTxt						GUARDA DATOS DE VENTA EN ARCHIVO TXT EN MODO TEXTO.
///
/// @param path											PUNTERO STRING
/// @param LinkedList									LINKEDLIST VENTAS.
/// @param firstCriteriaCounter							ENTERO.
/// @param secondCriteriaCounter						ENTERO.
/// @param thirdCriteriaCounter							ENTERO.
/// @param modelCarCriteria								ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerSaveReportTxt(char *path, LinkedList *pListSale, int firstCriteriaCounter, int secondCriteriaCounter, int thirdCriteriaCounter, int modelCarCriteria);

#endif /* CONTROLLER_H_ */
