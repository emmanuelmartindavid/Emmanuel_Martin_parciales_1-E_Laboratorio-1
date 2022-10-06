/*
 * vehiculo.c
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

#define OK 1
#define ERROR -1
#define OCCUPIED 1
#define FREE 0
#define DOWN -1

void initializeVehicles(vehicle vehicles[], int len) {

	int i;
	if (vehicles != NULL) {
		for (i = 0; i < len; i++) {

			vehicles[i].isEmpty = FREE;

		}
	}

}

int getFreeId(vehicle vehicles[], int len) {

	int i;
	int ret = ERROR;

	if (vehicles != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (vehicles[i].isEmpty == FREE) {
				ret = i;
				break;
			}
		}
	}
	return ret;
}

void listOneVehicle(vehicle vehicles, type *description, int lenType) {
	char descriptiones[31];

	getDescriptionType(description, lenType, vehicles.typeId, descriptiones);

	printf("%5d  %10s  %10d  %10s %20s\n", vehicles.idVehicle,
			vehicles.description, vehicles.model, vehicles.color,
			descriptiones);

}

int listVehicles(vehicle vehicles[], int len, type description[], int lenType) {

	int i = 0;
	int ammount = 0;
	int ret = ERROR;
	printf(
			"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
	printf("\n%5s  %10s  %10s  %10s %15s\n", "ID ", "DESCRIPCION", "MODELO",
			"COLOR", "TIPO");

	if (vehicles != NULL && len > 0) {

		for (i = 0; i < len; i++) {

			if (vehicles[i].isEmpty == OCCUPIED) {

				listOneVehicle(vehicles[i], description, lenType);

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

static int getId(void) {

	static int getIdIncremental = 100;

	return getIdIncremental++;
}

vehicle loadData(void) {

	vehicle aux;

	utn_getAlfaNumeric(aux.description, "Ingrese descripcion alfanumerica\n",
			"Ingrese caracteres validos\n");
	utn_getNumber(&aux.model, "Ingrese modelo (anio de fabricacion)\n",
			"Solo entre 1960 - 2022\n", 1959, 2023);
	utn_getDescription(aux.color, "Ingrese color: \n", "Solo 10 letras");

	return aux;
}

int addVehicle(vehicle vehicles[], int len, type description[], int lenType) {

	int ret = ERROR;
	int index;
	vehicle auxvehicle;

	if (vehicles != NULL && len > 0) {

		index = getFreeId(vehicles, len);

		if (index != -1) {

			auxvehicle = loadData();

			auxvehicle.idVehicle = getId();

			auxvehicle.typeId = types(description, lenType);

			auxvehicle.isEmpty = OCCUPIED;

			vehicles[index] = auxvehicle;

			printf("El alta de su vehiculo con id %d fue correcta.\n",
					vehicles[index].idVehicle);

			ret = OK;

		}
	}

	return ret;
}

int downVehicle(vehicle vehicles[], int len, type description[], int lenType) {
	int ret = ERROR;
	char buffer;
	int idVehicleAux;
	int index;
	int retList;

	if (vehicles != NULL && len > 0) {

		retList = listVehicles(vehicles, len, description, lenType);

		if (retList == ERROR) {

			printf("\t\tNo hay vehiculos ingresados\n");
		} else {

			utn_getNumber(&idVehicleAux, "Ingrese el ID del vehiculo\n",
					"Ingreso numero invalido.\n", -1, 10000);

			while (findById(vehicles, idVehicleAux, len) == -1) {

				printf("NO EXISTE ID.");

				utn_getNumber(&idVehicleAux, "Ingrese el ID del producto",
						"Ingreso numero invalido.", -1, 10000);
			}

			index = findById(vehicles, idVehicleAux, len);
			printf("SU ID de vehiculo %d", idVehicleAux);
			fflush(stdin);
			printf("\nSe dara de baja, continuar? s/n: ");
			scanf("%c", &buffer);

			if (buffer == 's') {
				vehicles[index].isEmpty = DOWN;
				printf("La baja del vehiculo con id %d fue correcta.\n",
						vehicles[index].idVehicle);
			} else if (buffer == 'n') {

				printf("No se dio de baja nada");
			}
			ret = OK;
		}

	}
	return ret;
}

int findById(vehicle vehicles[], int idVehicle, int len) {
	int ret = -1;
	int i;

	if (vehicles != NULL && idVehicle > -1 && len > 0) {

		for (i = 0; i < len; i++) {

			if (vehicles[i].idVehicle
					== idVehicle&& vehicles[i].isEmpty == OCCUPIED) {
				ret = i;

				break;

			}
		}
	}

	return ret;
}

vehicle modifyOneVehicle(vehicle vehicles) {

	vehicle auxModify = vehicles;
	int auxOptionModify;

	do {

		printf("\t\t****MODIFICACAR****\n");
		utn_getNumber(&auxOptionModify, "1- DESCRIPCION.\n"
				"2- MODELO.\n"
				"3- COLOR.\n"
				"4- SALIR", "\nOpcion incorrecta\n", 0, 5);

		switch (auxOptionModify) {

		case 1:
			utn_getAlfaNumeric(auxModify.description,
					"Ingrese descripcion alfanumerica\n",
					"Ingrese caracteres validos\n");
			break;
		case 2:
			utn_getNumber(&auxModify.model,
					"Ingrese modelo (anio de fabricacion)\n",
					"Solo entre 1960 - 2022\n", 1959, 2023);
			break;
		case 3:
			utn_getDescription(auxModify.color, "Ingrese color: \n",
					"Solo 10 letras");
			break;

		}
	} while (auxOptionModify != 4);

	return auxModify;
}

int modifyVehicles(vehicle vehicles[], int len, type description[], int lenType) {

	int ret = ERROR;
	int idVehicle;
	int index;
	int retListVehicle;
	vehicle auxVehicle;

	if (vehicles != NULL && len > 0) {

		retListVehicle = listVehicles(vehicles, len, description, lenType);

		if (retListVehicle == ERROR) {

			printf("\t\tNo hay vehiculos ingresados\n");
		} else {
			utn_getNumber(&idVehicle,
					"Ingrese el ID del vehiculo a modificar\n",
					"Ingreso numero invalido.\n", -1, 10000);

			while (findById(vehicles, idVehicle, len) == -1) {

				printf("NO EXISTE ID.");

				utn_getNumber(&idVehicle,
						"Ingrese el ID del vehiculo a modificar\n",
						"Ingreso numero invalido.", -1, 10000);
			}

			index = findById(vehicles, idVehicle, len);

			auxVehicle = modifyOneVehicle(vehicles[index]);
			vehicles[index] = auxVehicle;
			printf("La modificacion de vehiculo con id %d fue correcta.\n",
					vehicles[index].idVehicle);

			ret = OK;

		}
	}

	return ret;
}

int sortTypeVehicle(vehicle vehicles[], type description[], int len) {

	int ret = ERROR;
	vehicle auxVehicle;

	if (vehicles != NULL) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				ret = OK;

				if (vehicles[i].isEmpty == OCCUPIED
						&& vehicles[j].isEmpty == OCCUPIED) {

					if (vehicles[i].typeId > vehicles[j].typeId
							|| (vehicles[i].typeId == vehicles[j].typeId
									&& (strcmp(vehicles[i].description,
											vehicles[j].description)) > 0)) {
						auxVehicle = vehicles[i];
						vehicles[i] = vehicles[j];
						vehicles[j] = auxVehicle;
					}

				}
			}
		}

	}

	return ret;
}




//void recorrerArray(vehicle vehicles[], int len) {
//
//	for (int i = 0; i < len; i++) {
//		printf("\n IS EMPTY: %d", vehicles[i].isEmpty);
//
//	}
//
//}

//void Vehicles(vehicle vehicles[], int len) {
//
//
//
//	vehicle aux[25] = { {5, "alpha", 1970, "negro", 1 }, {2, "beta", 1974,
//			"blanco",2 }, { 3, "gamma", 1976, "verde",2}, {4, "delta",
//			1961, "gris",3 }, {5, "epsilon", 1984, "plateado",1 }, {6,
//			"dseta", 1987, "dorado", 1 }, { 7, "eta", 1998, "azul", 2 }, {8,
//			 "zeta", 2000, "amarillo",3 }, {9, "iota", 1964, "rojo",
//			2 }, {10, "kappa", 1980, "marron",1 }, { 11, "mu", 1990,
//			"gris", 2 }, {12, "nu", 1986, "negro",3 }, {13, "xi", 2010,
//			"violeta",1 }, {14, "omicron", 2019, "negro",1}, {
//			15, "pi", 2020, "cosmos", 3}, {16, "ro", 2015, "panton", 1},
//			{17, "sigma", 2013, "blanco",2}, {18, "tau", 1994, "negro",
//			1 }, { 19, "tau", 2004, "rojo",2 }, {20, "ipsilon", 2010,
//			"negro", 1 }, {21, "fi", 2011, "verde",3}, {22, "ji",
//			2013, "azul", 3 }, { 23, "psi", 2020, "amarillo", 2}, {24,
//			"omega", 2022, "negro",3 } };
//
//	for (int i; i < len; i++) {
//
//		vehicles[i]=aux[i];
//	}
//
//
//}

//type TypesHard() {
//
//	type aux;
//
//	[24] = { 1, 2, 3, 2, 3, 2, 1, 2, 3, 2, 1, 2, 3, 2, 1, 2, 3, 2,
//			2, 3, 3, 2, 1, 2 };
//
//	for (int i; i < 24; i++) {
//
//		auxType[i];
//	}
//
//	return auxType;
//
//}


//
//int listDownvehicles(vehicle vehicles[], int len, type description[],
//		int lenType) {
//
//	int i = 0;
//	int ammount = 0;
//	int ret = -1;
//
//	if (vehicles != NULL && len > 0) {
//
//		for (i = 0; i < len; i++) {
//
//			if (vehicles[i].isEmpty == DOWN) {
//
//				listOneVehicle(vehicles[i], description, lenType);
//				ammount++;
//			}
//
//		}
//
//		if (ammount > 0) {
//			ret = 0;
//
//		}
//
//	}
//
//	return ret;
//}



