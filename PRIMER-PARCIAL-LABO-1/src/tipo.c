/*
 * tipo.c
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

#define MAX_DESCRIPTION_TYPE 31
#define OCCUPIED 1



#define MAX_DESCRIPTION_TYPE 31
#define OCCUPIED 1



int types(type oneType[], int lenType) {

	int option;
	type auxVehicleTypeId;

	utn_getNumber(&option, "Ingrese tipo.\n"
			"1-SEDAN 3 PUERTAS\n"
			"2-SEDAN 5 PUERTAS\n"
			"3-CAMIONETA\n", "Solo entre 1-3\n", 0, 4);
	switch (option) {

	case 1:
		auxVehicleTypeId.idtype= oneType[0].idtype;

		break;
	case 2:
		auxVehicleTypeId.idtype=oneType[1].idtype;

		break;
	case 3:
		auxVehicleTypeId.idtype=oneType[2].idtype;

		break;
	}
	return auxVehicleTypeId.idtype;
}

int getDescriptionType(type oneType[], int lenType, int idType,
		char *pDescription) {
	int ret = -1;
	int i;

	if (oneType != NULL && idType > -1) {

		for (i = 0; i < lenType; i++) {

			if (oneType[i].idtype == idType) {

				strncpy(pDescription, oneType[i].description, 31);
				ret = 0;

				break;

			}
		}
	}

	return ret;
}

int listTypes(vehicle vehicles[], type description[], int len) {

	int ret = -1;
	int ammount = 0;
	char auxDescription[31];
	type auxDescriptions[31];
	int i;

	for (i = 0; i < len; i++) {
		if (vehicles[i].isEmpty == OCCUPIED) {
			getDescriptionType(description, len, vehicles[i].typeId,
					auxDescription);

			strncpy(auxDescriptions[i].description, auxDescription, 31);

			printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
			printf("%10s" "%10s", "LISTADO DE TIPOS", "ID\n\n");
			printf("%10s %10d", auxDescriptions[i].description,
					vehicles[i].typeId);
			printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
			ammount++;

		}

	}
	if (ammount > 0) {
		ret = 1;

	}

	return ret;
}

void hardCode(type oneType[], int lenType) {



	oneType[0].idtype=1000;
	strncpy(oneType[0].description,"SEDAN 3 PUERTAS", 31);
	oneType[1].idtype=1001;
	strncpy(oneType[1].description,"SEDAN 5 PUERTAS", 31);
	oneType[2].idtype=1002;
	strncpy(oneType[2].description,"CAMIONETA", 31);

}

