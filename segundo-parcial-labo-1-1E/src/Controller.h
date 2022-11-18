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
/// @brief controllerAddSale		ALTA DE VENTA.
///
/// @param pArrayListPlayer			LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerAddSale(LinkedList *pListSale);
/// @brief controllerRemoveSale		BAJA DE VENTA.
///
/// @param pArrayListPlayer			LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerRemoveSale(LinkedList *pListSale);
/// @brief  controllerListSales   	LISTADO VENTAS.
///
/// @param pArrayListPlayer			LINKEDLIST VENTAS.
/// @return 						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int controllerListSales(LinkedList *pListSale);

#endif /* CONTROLLER_H_ */
