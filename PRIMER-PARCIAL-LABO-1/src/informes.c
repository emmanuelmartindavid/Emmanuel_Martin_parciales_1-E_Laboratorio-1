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

