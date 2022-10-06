/*
 * informes.c
 *
 *  Created on: 6 oct. 2022
 *      Author: cuerpos
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "vehiculo.h"
#include "validaciones.h"
#include "tipo.h"
#include "hojaServicio.h"

#define OK 1
#define ERROR -1
#define OCCUPIED 1
#define FREE 0
#define DOWN -1

int showOneType3Doors(vehicle vehicles[], type description[], int len) {

	int ret = -1;
	int ammount = 0;
	char descriptiones[31];

	getDescriptionType(description, len, vehicles->typeId, descriptiones);

	if (vehicles != NULL && len > 0) {

		for (int i = 0; i < len; i++) {

			if (vehicles[i].isEmpty == OCCUPIED) {

				if (vehicles[i].typeId == description[0].idtype) {

					listOneVehicle(vehicles[i], description, len);
					ammount++;

				}

			}
			if (ammount > 0) {
				ret = OK;

			}

		}
	}
	return ret;
}

int showOneType5Doors(vehicle vehicles[], type description[], int len) {

	int ret = -1;
	int ammount = 0;
	char descriptiones[31];

	getDescriptionType(description, len, vehicles->typeId, descriptiones);

	if (vehicles != NULL && len > 0) {

		for (int i = 0; i < len; i++) {

			if (vehicles[i].isEmpty == OCCUPIED) {

				if (vehicles[i].typeId == description[1].idtype) {

					listOneVehicle(vehicles[i], description, len);
					ammount++;

				}

			}
			if (ammount > 0) {
				ret = OK;

			}

		}
	}
	return ret;
}

int showOneTypeTruck(vehicle vehicles[], type description[], int len) {

	int ret = -1;
	int ammount = 0;
	char descriptiones[31];

	getDescriptionType(description, len, vehicles->typeId, descriptiones);

	if (vehicles != NULL && len > 0) {

		for (int i = 0; i < len; i++) {

			if (vehicles[i].isEmpty == OCCUPIED) {

				if (vehicles[i].typeId == description[2].idtype) {

					listOneVehicle(vehicles[i], description, len);
					ammount++;

				}

			}
			if (ammount > 0) {
				ret = OK;

			}

		}
	}
	return ret;
}

void showTypes(vehicle vehicles[], type description[], int len) {

	int auxShowType;

	utn_getNumber(&auxShowType, "Ingrese tipo de vehiculos a listar\n"
			"1- SEDAN 3 PUERTAS\n"
			"2- SEDAN 5 PUERTAS\n"
			"3- CAMIONETA\n", "Opcion invalida\n", 0, 4);

	switch (auxShowType) {

	case 1:

		showOneType3Doors(vehicles, description, len);
		break;
	case 2:

		showOneType5Doors(vehicles, description, len);
		break;
	case 3:

		showOneTypeTruck(vehicles, description, len);

		break;

	}

}

date askDate() {

	date auxDate;

	utn_getNumber(&auxDate.day, "Ingrese dia", "Dia Invalido", 0, 32);

	utn_getNumber(&auxDate.month, "Ingrese mes", "Mes invalido", 0, 13);

	utn_getNumber(&auxDate.year, "Ingrese anio", "Anio invalido", 2000, 2023);

	return auxDate;
}

int showSheetPerDate(sheet oneSheet[], int lenSheet) {

	int ret = -1;
	int ammount = 0;
	date auxDatePerDate;

	if (oneSheet != NULL && lenSheet > 0) {

		auxDatePerDate = askDate();
		for (int i = 0; i < lenSheet; i++) {

			if (oneSheet[i].isEmpty == OCCUPIED) {

				if (oneSheet[i].oneDate.day == auxDatePerDate.day
						&& oneSheet[i].oneDate.month == auxDatePerDate.month
						&& oneSheet[i].oneDate.year == auxDatePerDate.year) {

					listOneSheet(oneSheet[i], lenSheet);
					ammount++;

				}

			}
			if (ammount > 0) {
				ret = OK;

			}

		}
	}
	return ret;

}

//3- Informar importe total de las hojas de servicio realizadas en un vehículo seleccionado

int loadDataSheetIdReports(sheet oneSheet[], int lenSheet) {

	sheet auxSheetIdReport;

	utn_getNumber(&auxSheetIdReport.vehicleId, "Ingrese Id de vehiculo\n", "\n",
			99, 400);

	return auxSheetIdReport.vehicleId;
}

int totalPricePerVehicle(sheet oneSheet[], vehicle vehicles[],
		type description[], int lenSheet, int len, int lenType) {

	int ret = ERROR;
	int indexID;
	int index;
	sheet auxSheet[lenSheet];
	float acumulator = 0;

	if (oneSheet != NULL && vehicles != NULL && lenSheet > 0 && len > 0) {

		listVehicles(vehicles, len, description, lenType);

		//indexID = getFreeIdSheet(oneSheet, lenSheet);

		for(int i=0;i<lenSheet;i++){

					acumulator += oneSheet[i].servicePrice;
						printf("PRECIO $%.2f. SERVICIO %.2f \n", acumulator, oneSheet[i].servicePrice);
						break;

					}

		do {

			auxSheet[indexID].vehicleId = loadDataSheetId(oneSheet, lenSheet);

			indexID = findByIdSheet(oneSheet, auxSheet[indexID].vehicleId, len);

			index = findById(vehicles, auxSheet[indexID].vehicleId, len);

		} while (auxSheet[indexID].vehicleId != vehicles[index].idVehicle);


		for(int i=0;i<lenSheet;i++){

			acumulator += oneSheet[i].servicePrice;
				printf("PRECIO $%.2f. SERVICIO %.2f \n", acumulator, oneSheet[i].servicePrice);
				break;

			}


//		auxSheet[indexID] = loadDataSheet();
//
//		auxSheet[indexID].vehicleId = vehicles[index].idVehicle;
//
//		auxSheet[indexID].isEmpty = OCCUPIED;
//
//		oneSheet[indexID] = auxSheet[indexID];

		printf("PRECIO $%.2f. SERVICIO %.2f \n", acumulator, oneSheet[indexID].servicePrice);

//			printf("PRUEBA %d %d %s %.2f %d-%d-%d\n", oneSheet[index].idSheet,
//					oneSheet[index].vehicleId, oneSheet[index].description,
//					oneSheet[index].servicePrice, oneSheet[index].oneDate.day,
//					oneSheet[index].oneDate.month,
//					oneSheet[index].oneDate.year);

		ret = OK;

	}

	return ret;

}

void reportsMenu(sheet oneSheet[], vehicle vehicles[], type description[],
		int len, int lenSheet) {

	int optionReports;

	do {
		utn_getNumber(&optionReports,
				"\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-INFORMES-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
						"\n\t\t*\t\t\t\t\t\t\t\t\t\t\t\t*"
						"\n\t\t*\t 1-MOSTRAR VEHICULOS DE UN TIPO:\t\t\t\t\t\t\t*"
						"\n\t\t*\t 2-MOSTRAR HOJAS DE SERVICIO EFECTUADAS EN FECHA SELECCIONADA:\t\t\t\t*"
						"\n\t\t*\t 3-IMPORTE TOTAL DE LAS HOJAS DE SERVICIO REALIZADAS EN UN VEHICULO:\t\t\t*"
						"\n\t\t*\t 4-IMPORTE TOTAL DE TODAS LAS HOJAS DE SERVICIO DE UN TIPO EN UNA FECHA SELECCIONADA\t*"
						"\n\t\t*\t\t\t\t\t\t\t\t\t\t\t\t*\n"
						"\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n",
				"Opcion invalida", 0, 6);

		switch (optionReports) {

		case 1:

			showTypes(vehicles, description, len);
			break;
		case 2:

			showSheetPerDate(oneSheet, lenSheet);
			break;
		case 3:

			break;
		case 4:

			break;

		}

	} while (optionReports != 5);

}
