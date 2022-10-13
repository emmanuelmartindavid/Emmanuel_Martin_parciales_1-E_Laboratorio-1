/*
 * hojaServicio.c
 *
 *  Created on: 6 oct. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
#include "hojaServicio.h"
#include "validaciones.h"

/// @brief initializeSheet 		Funcion inicializa en 0 el array de hojas de servicio.
///
/// @param arraySheet	   		Array de hojas de servicio a dar de alta.
/// @param lenSheet		  	    Tamanio de ARRAY de hojas de servicio.
void initializeSheet(sSheet arraySheet[], int lenSheet) {

	int i;
	if (arraySheet != NULL && lenSheet > 0) {
		for (i = 0; i < lenSheet; i++) {

			arraySheet[i].isEmpty = FREE;

		}
	}

}
/// @brief getFreeIndexSheet	Funcion obtiene posicion de ARRAY de hojas de servicio libre a dar de alta.
///
/// @param arraySheet			Array de hojas de servicio a dar de alta.
/// @param lenSheet				Tamanio de ARRAY de hojas de servicio.
/// @return						Retorna la posicion del ARRAY de hojas de servicio libre a dar de alta.
int getFreeIndexSheet(sSheet arraySheet[], int lenSheet) {

	int i;
	int rtn = ERROR;

	if (arraySheet != NULL && lenSheet > 0) {
		for (i = 0; i < lenSheet; i++) {
			if (arraySheet[i].isEmpty == FREE) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}
/// @brief getId Funcion STATIC para autoincrementar ID de cada hoja de servicio.
///
/// @return Retorno ID autoincrementada para cada hoja de servicio dada de alta.
static int getIdSheet(void) {

	static int getIdSheetIncremental = 20000;

	return getIdSheetIncremental++;
}
/// @brief listOneSheet			Funcion para listar una hoja de servicio dada de alta.
///
/// @param sheet				Una hoja de servicio de estructura sSheet, dada de alta.
/// @param vehicle				Un vehiculo de estructura sVehicle, dado de alta.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
void listOneSheet(sSheet sheet, sVehicle vehicle, sType arrayType[],
		int lenType) {

	char descriptionType[31];

	if (arrayType != NULL && lenType > 0) {

		getDescriptionType(arrayType, lenType, vehicle.typeId, descriptionType);

		printf("\t\t\t\t\t\t%5d  %20s  %20.2f %10d-%d-%d %20s\n",
				sheet.vehicleId, sheet.description, sheet.servicePrice,
				sheet.date.day, sheet.date.month, sheet.date.year,
				descriptionType);
	}

}
/// @brief listSheets			Funcion lista ARRAY de hojas de servicio dadas de alta.
///
/// @param arraySheet			Array de hojas de servicio dada de alta.
/// @param lenSheet				Tamanio de ARRAY de hojas de servicio.
/// @param arrayVehicle			Array de vehiculos dados de alta.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int listSheets(sSheet arraySheet[], int lenSheet, sVehicle arrayVehicle[],
		int len, sType arrayType[], int lenType) {

	int i;
	int j;
	int ammount = 0;
	int rtn = ERROR;
	printf(
			"\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*--*-*-*-\n");
	printf("%5s  %10s  %10s  %10s %15s\n", "\t\t\t\t\t\tID VEHICULO",
			"DESCRIPCION DE SERVICIO", "PRECIO DE SERVICIO",
			"FECHA DE SERVICIO", "TIPO VEHICULO");

	if (arraySheet != NULL && lenSheet > 0 && arrayVehicle != NULL && len > 0
			&& arrayType != NULL && lenType > 0) {

		for (i = 0; i < lenSheet; i++) {

			if (arraySheet[i].isEmpty == OCCUPIED) {

				for (j = 0; j < len; j++) {

					if (arrayVehicle[j].idVehicle == arraySheet[i].vehicleId) {

						listOneSheet(arraySheet[i], arrayVehicle[j], arrayType,
								lenType);

						ammount++;
					}

				}

			}

		}
		if (ammount > 0) {
			rtn = OK;
			printf(
					"\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*--*-*-*-\n");
		}

	}

	return rtn;
}
/// @brief loadDataSheetId		Funcion para obtener ID de vehiculo ingresado por usuario a dar de alta en hoja de servicio.
///
/// @return						Retorno auxiliar de ID de sSheet(estructura hoja de servicio) ingresado por usuario.
int loadDataSheetId() {

	sSheet auxSheetId;

	utn_getNumber(&auxSheetId.vehicleId,
			"Ingrese Id de vehiculo SOLO dado de alta.\n", "ERROR. REINTENTE\n",
			-1, 1000);

	return auxSheetId.vehicleId;
}
/// @brief loadDataSheet 		Funcion de tipo sSheet(estructura hoja de servicio) para realizar la carga de datos de hoja de servicio.
///
/// @return						Retorno auxiliar de sSheet(estructura hoja de servicio) con los datos cargados por el usuario.
sSheet loadDataSheet(void) {

	sSheet auxSheet;

	utn_getAlfaNumeric(auxSheet.description,
			"Ingrese descripcion de servicio.\n",
			"Ingrese caracteres validos.\n");

	utn_getNumberFloat(&auxSheet.servicePrice,
			"Ingrese precio de servicio(desde $ 1000).\n", "Precio invalido.\n",
			999, 9999999);

	utn_getNumber(&auxSheet.date.day, "Ingrese dia.\n", "Dia Invalido.\n", 0, 32);

	utn_getNumber(&auxSheet.date.month, "Ingrese mes.\n", "Mes invalido.\n", 0,
			13);

	utn_getNumber(&auxSheet.date.year, "Ingrese anio (1960-2023).\n",
			"Anio invalido.\n", 1959, 2023);

	return auxSheet;
}
/// @brief registerSheet		Funcion para dar de alta una hoja de servicio.
///
/// @param arraySheet			Array de hojas de servicio a dar de alta.
/// @param arrayVehicle			Array de vehiculos dados de alta.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param lenSheet				Tamanio de ARRAY de hojas de servicio.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int registerSheet(sSheet arraySheet[], sVehicle arrayVehicle[], sType arrayType[],
		int len, int lenSheet, int lenType) {

	int rtn = ERROR;
	int indexID;
	int index;
	sSheet auxSheet[lenSheet];

	if (arraySheet != NULL && lenSheet > 0 && arrayVehicle != NULL && len > 0
			&& arrayType != NULL && lenType > 0) {

		listVehicles(arrayVehicle, len, arrayType, lenType);

		indexID = getFreeIndexSheet(arraySheet, lenSheet);

		if (indexID != -1) {

			do {

				auxSheet[indexID].vehicleId = loadDataSheetId();
				index = findById(arrayVehicle, auxSheet[indexID].vehicleId,
						len);

			} while (auxSheet[indexID].vehicleId
					!= arrayVehicle[index].idVehicle);

			auxSheet[indexID] = loadDataSheet();

			auxSheet[indexID].vehicleId = arrayVehicle[index].idVehicle;

			auxSheet[indexID].idSheet = getIdSheet();

			auxSheet[indexID].isEmpty = OCCUPIED;

			arraySheet[indexID] = auxSheet[indexID];

			rtn = OK;

		}
	}

	return rtn;
}
/// @brief hardCodeSheets		Funcion para harcodear hojas de servicio de prueba de programa.
///
/// @param arraySheet			Array de hojas de servicio a dar de alta.
/// @param lenSheet				Tamanio de ARRAY de hojas de servicio.
/// @param pNextId			    Puntero a entero autoincremental a traves de contador.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int hardCodeSheets(sSheet arraySheet[], int lenSheet, int *pNextId) {

	int rtn = ERROR;

	sSheet aux[21] =

	{

	{ 0, 80, "Motor", 5000, { 2, 2, 2020 }, 1 }, { 0, 92, "Frenos", 2274, { 2,
			2, 2020 }, 1 },
			{ 0, 93, "Tren delantero", 10076, { 4, 5, 2005 }, 1 }, { 0, 91,
					"Parabrisas", 1261, { 4, 5, 2005 }, 1 }, { 0, 92,
					"Cambio bujias", 12034, { 3, 4, 2002 }, 1 }, { 0, 99,
					"Cambio llantas", 19827, { 4, 5, 2020 }, 1 }, { 0, 95,
					"Ruedas", 1002, { 2, 2, 2020 }, 1 }, { 0, 95,
					"Chapa-pintura", 2300, { 2, 2, 2020 }, 1 }, { 0, 92,
					"Llantas", 4064, { 2, 2, 2020 }, 1 }, { 0, 90, "Puertas",
					12080, { 2, 2, 2020 }, 1 },
					{ 0, 82, "Motores", 5000, { 2, 2, 2020 }, 1 }, { 0, 93, "Frenos", 2274, { 2,
							2, 2020 }, 1 },
							{ 0, 94, "delantero", 10076, { 4, 5, 2005 }, 1 }, { 0, 95,
									"Parabrisas roto", 1261, { 4, 5, 2005 }, 1 }, { 0, 94,
									"Cambio bujias", 12034, { 3, 4, 2002 }, 1 }, { 0, 98,
									"Cambio aceite", 19827, { 4, 5, 2020 }, 1 }, { 0, 99,
									"Rueda pinchada", 1002, { 2, 2, 2020 }, 1 }, { 0, 96,
									"Chapa-pintura-tapisado", 2300, { 2, 2, 2020 }, 1 }, { 0, 93,
									"Llantas", 4064, { 2, 2, 2020 }, 1 }, { 0, 90, "Puertas",
									12080, { 2, 2, 2020 }, 1 }

	};

	if (arraySheet != NULL && pNextId != NULL && lenSheet > 0) {
		for (int i = 0; i < lenSheet; i++) {
			arraySheet[i] = aux[i];
			arraySheet[i].idSheet = *pNextId;

			(*pNextId)++;

		}
		rtn = OK;
	}
	return rtn;

}
