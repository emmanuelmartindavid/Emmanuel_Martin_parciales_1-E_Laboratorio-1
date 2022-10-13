/*
 * hojaServicio.h
 *
 *  Created on: 6 oct. 2022
 *      Author: cuerpos
 */
#ifndef HOJASERVICIO_H_
#define HOJASERVICIO_H_
#include "vehiculo.h"
#include "tipo.h"

#define MAX_DESCRIPTIONSHEET 4096

typedef struct{

	int day;
	int month;
	int year;

}sDate;

typedef struct{

	int idSheet;
	int vehicleId;
	char description[MAX_DESCRIPTIONSHEET];
	float servicePrice;
	sDate date;
	int isEmpty;

}sSheet;
/// @brief initializeSheet 		Funcion inicializa en 0 el array de hojas de servicio.
///
/// @param arraySheet	   		Array de hojas de servicio a dar de alta.
/// @param lenSheet		  	    Tamanio de ARRAY de hojas de servicio.
void initializeSheet(sSheet arraySheet[], int lenSheet);
/// @brief getFreeIndexSheet	Funcion obtiene posicion de ARRAY de hojas de servicio libre a dar de alta.
///
/// @param arraySheet			Array de hojas de servicio a dar de alta.
/// @param lenSheet				Tamanio de ARRAY de hojas de servicio.
/// @return						Retorna la posicion del ARRAY de hojas de servicio libre a dar de alta.
int getFreeIndexSheet(sSheet arraySheet[], int lenSheet);
/// @brief listOneSheet			Funcion para listar una hoja de servicio dada de alta.
///
/// @param sheet				Una hoja de servicio de estructura sSheet, dada de alta.
/// @param vehicle				Un vehiculo de estructura sVehicle, dado de alta.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
void listOneSheet(sSheet sheet, sVehicle vehicle, sType arrayType[], int lenType);
/// @brief listSheets			Funcion lista ARRAY de hojas de servicio dadas de alta.
///
/// @param arraySheet			Array de hojas de servicio dada de alta.
/// @param lenSheet				Tamanio de ARRAY de hojas de servicio.
/// @param arrayVehicle			Array de vehiculos dados de alta.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int listSheets(sSheet arraySheet[], int lenSheet, sVehicle arrayVehicle[], int len, sType arrayType[], int lenType);
/// @brief loadDataSheetId		Funcion para obtener ID de vehiculo ingresado por usuario a dar de alta en hoja de servicio.
///
/// @return						Retorno auxiliar de ID de sSheet(estructura hoja de servicio) ingresado por usuario.
int loadDataSheetId();
/// @brief loadDataSheet 		Funcion de tipo sSheet(estructura hoja de servicio) para realizar la carga de datos de hoja de servicio.
///
/// @return						Retorno auxiliar de sSheet(estructura hoja de servicio) con los datos cargados por el usuario.
sSheet loadDataSheet();
/// @brief registerSheet		Funcion para dar de alta una hoja de servicio.
///
/// @param arraySheet			Array de hojas de servicio a dar de alta.
/// @param arrayVehicle			Array de vehiculos dados de alta.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param lenSheet				Tamanio de ARRAY de hojas de servicio.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int registerSheet(sSheet arraySheet[], sVehicle arrayVehicle[], sType arrayType[], int len, int lenSheet, int lenType);
/// @brief hardCodeSheets		Funcion para harcodear hojas de servicio de prueba de programa.
///
/// @param arraySheet			Array de hojas de servicio a dar de alta.
/// @param lenSheet				Tamanio de ARRAY de hojas de servicio.
/// @param pNextId			    Puntero a entero autoincremental a traves de contador.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int hardCodeSheets(sSheet arraySheet[], int lenSheet, int *pNextId);


#endif /* HOJASERVICIO_H_ */
