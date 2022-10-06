/*
 * hojaServicio.c
 *
 *  Created on: 6 oct. 2022
 *      Author: cuerpos
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hojaServicio.h"
#include "validaciones.h"
#include "vehiculo.h"
#include "tipo.h"

#define OK 1
#define ERROR -1
#define OCCUPIED 1
#define FREE 0

void initializeSheet(sheet oneSheet[], int len) {

	int i;
	if (oneSheet != NULL) {
		for (i = 0; i < len; i++) {

			oneSheet[i].isEmpty = FREE;

		}
	}

}

int getFreeIdSheet(sheet oneSheet[], int len) {

	int i;
	int ret = ERROR;

	if (oneSheet != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (oneSheet[i].isEmpty == FREE) {
				ret = i;
				break;
			}
		}
	}
	return ret;
}

static int getIdSheet(void) {

	static int getIdSheetIncremental = 2000;

	return getIdSheetIncremental++;
}

int findByIdSheet(sheet oneSheet[], int idSheet, int len) {
	int ret = -1;
	int i;

	if (oneSheet != NULL && idSheet > -1 && len > 0) {

		for (i = 0; i < len; i++) {

			if (oneSheet[i].idSheet
					== idSheet&& oneSheet[i].isEmpty == OCCUPIED) {
				ret = i;

				break;

			}
		}
	}

	return ret;
}

void listOneSheet(sheet oneSheet, int len) {

	printf("%5d  %10d  %10s  %10.2f %10d-%d-%d\n", oneSheet.idSheet,
			oneSheet.vehicleId, oneSheet.description, oneSheet.servicePrice,
			oneSheet.oneDate.day, oneSheet.oneDate.month,
			oneSheet.oneDate.year);

}

int listSheets(sheet oneSheet[], int len) {

	int i = 0;
	int ammount = 0;
	int ret = ERROR;
	printf(
			"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
	printf("\n%5s  %10s  %10s  %10s %15s\n", "ID SERVICIO", "ID VEHICULO",
			"DESCRIPCION DE SERVICIO", "PRECIO DE SERVICIO",
			"FECHA DE SERVICIO");

	if (oneSheet != NULL && len > 0) {

		for (i = 0; i < len; i++) {

			if (oneSheet[i].isEmpty == OCCUPIED) {

				listOneSheet(oneSheet[i], len);

				ammount++;

			}

		}
		if (ammount > 0) {
			ret = OK;
			printf(
					"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
		}

	}

	return ret;
}

int loadDataSheetId(sheet oneSheet[], int lenSheet) {

	sheet auxSheetId;

	utn_getNumber(&auxSheetId.vehicleId, "Ingrese Id de vehiculo\n",
			"\n", 99, 400);

	return auxSheetId.vehicleId;
}

sheet loadDataSheet(void) {

	sheet auxSheet;

	utn_getAlfaNumeric(auxSheet.description,
			"Ingrese descripcion de servicio\n",
			"Ingrese caracteres validos\n");

	utn_getNumberFloat(&auxSheet.servicePrice,
			"Ingrese precio de servicio(desde $ 1000)\n", "Precio invalido\n",
			1000, 100000);

	utn_getNumber(&auxSheet.oneDate.day, "Ingrese dia", "Dia Invalido", 0, 32);

	utn_getNumber(&auxSheet.oneDate.month, "Ingrese mes", "Mes invalido", 0,
			13);

	utn_getNumber(&auxSheet.oneDate.year, "Ingrese anio", "Anio invalido", 2000,
			2023);

	return auxSheet;
}

int addSheet(sheet oneSheet[], vehicle vehicles[], type description[], int len,
		int lenSheet, int lenType) {

	int ret = ERROR;
	int indexID;
	int index;
	sheet auxSheet[lenSheet];

	if (oneSheet != NULL && vehicles != NULL && lenSheet > 0 && len > 0) {

		listVehicles(vehicles, len, description, lenType);

		indexID = getFreeIdSheet(oneSheet, lenSheet);

		if (indexID != -1) {

			do{

				auxSheet[indexID].vehicleId = loadDataSheetId(oneSheet,
						lenSheet);
				index = findById(vehicles, auxSheet[indexID].vehicleId, len);

			}while(auxSheet[indexID].vehicleId != vehicles[index].idVehicle);

			auxSheet[indexID] = loadDataSheet();

			auxSheet[indexID].vehicleId = vehicles[index].idVehicle;

			auxSheet[indexID].idSheet = getIdSheet();

			auxSheet[indexID].isEmpty = OCCUPIED;

			oneSheet[indexID] = auxSheet[indexID];

			printf(
					"El alta de su hoja de servicio con ID %d y vehiculo con ID %d fue correcta.\n",
					oneSheet[indexID].idSheet, oneSheet[indexID].vehicleId);

//			printf("PRUEBA %d %d %s %.2f %d-%d-%d\n", oneSheet[index].idSheet,
//					oneSheet[index].vehicleId, oneSheet[index].description,
//					oneSheet[index].servicePrice, oneSheet[index].oneDate.day,
//					oneSheet[index].oneDate.month,
//					oneSheet[index].oneDate.year);

			ret = OK;

		}
	}

	return ret;
}



