/*
 * tipo.h
 *
 *  Created on: 6 oct. 2022
 *      Author: cuerpos
 */

#ifndef TIPO_H_
#define TIPO_H_
#include "vehiculo.h"
#define MAX_DESCRIPTION_TYPE 31


typedef struct{

	int idtype;
	char description[MAX_DESCRIPTION_TYPE];

}sType;
/// @brief getIdtype		   Funcion para obtener el ID de tipo de vehiculo elegido por usuario.
///
/// @param arrayType		   ARRAY de tipos de vehiculo harcodeado.
/// @return					   Retorno ID de tipo de vehiculo elegido por usuario a traves de auxiliar sType.
int getIdtype(sType arrayType[]);
/// @brief getDescriptionType  Funcion para obtener la descripcion de tipo de vehiculo, segun ID tipo elegido por usuario.
///
/// @param arrayType           ARRAY de tipos de vehiculo harcodeado.
/// @param lenType			   Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @param idType			   ID tipo de vehiculo elegido por usuario a comparar.
/// @param pDescription		   Puntero a cadena de texto, con descripcion de tipo de vehiculo, dependiendo del ID de tipo de vehiculo elegido por usuario.
/// @return					   Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int getDescriptionType(sType arrayType[], int lenType, int idType, char *pDescription);
/// @brief hardCode			   Funcion de harcodeo de ID tipo de vehiculo, descripcion tipo de vehiculo.
///
/// @param arrayType		   ARRAY de tipos de vehiculo a harcodear.
void hardCode(sType arrayType[]);


#endif /* TIPO_H_ */
