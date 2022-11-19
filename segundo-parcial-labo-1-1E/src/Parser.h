/*
 * Parser.h
 *
 *  Created on: 16 nov. 2022
 *      Author: cuerpos
 */

#ifndef PARSER_H_
#define PARSER_H_


/// @brief parserSaleFromText	PARSEA DATOS DE VENTAS DESDE ARCHIVO CSV EN MODO TEXTO.
///
/// @param pFile				PUNTERO A FILE.
/// @param pArrayListPlayer		LINKEDLIST VENTAS.
/// @return						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int parserSaleFromText(FILE *pFile, LinkedList *pListSale);
/// @brief parserSaleFromBinary PARSEA DATOS DE VENTAS DESDE ARCHIVO BIN EN BINARIO.
///
/// @param pFile				PUNTERO A FILE.
/// @param pArrayListPlayer		LINKEDLIST VENTAS.
/// @return						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int parserSaleFromBinary(FILE *pFile, LinkedList *pListSale);
/// @brief parserIdSaleFromText 	PARSEA DATO DE ID VENTA A DAR DE ALTA DESDE ARCHIVO CSV EN MODO TEXTO.
///
/// @param pFile					PUNTERO A FILE.
/// @param pIdSale				PUNTERO ENTERO.
/// @return							RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int parserIdSaleFromText(FILE *pFile, int *pIdSale);

#endif /* PARSER_H_ */
