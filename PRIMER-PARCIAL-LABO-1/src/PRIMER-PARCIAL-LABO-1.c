/*
 ============================================================================
 Name        : PRIMER-PARCIAL-LABO-1.c
 Author      :  EMMANUEL  DAVID MARTIN
 Version     :  PRIMERO E
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "vehiculo.h"
#include "tipo.h"
#include "hojaServicio.h"
#include "informes.h"

#define OK 1
#define ERROR -1
#define OCCUPIED 1
#define FREE 0
#define DOWN -1
#define TAM 100
#define TAMSHEET 100
#define TAM_TYPE 3

int main(void) {

	setbuf(stdout, NULL);
	type description[TAM_TYPE];
	vehicle vehicles[TAM];
	sheet oneSheet[TAMSHEET];


	hardCode(description, TAM_TYPE);

	int option = 0;
	int retorno;

	initializeVehicles(vehicles, TAM);

	do {

		utn_getNumber(&option, "\t\t-*-*-*-*-*-*-*-*-*-*-*-*-MENU TALLER MECANICO-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"
				"\n\t\t*\t\t\t\t\t\t\t\t\t*"
				"\n\t\t*\t\t\t 1-ALTA VEHICULO:\t\t\t\t*"
				"\n\t\t*\t\t\t 2-MODIFICAR VEHICULO:\t\t\t\t*"
				"\n\t\t*\t\t\t 3-BAJA VEHICULO\t\t\t\t*"
				"\n\t\t*\t\t\t 4-LISTAR VEHICULOS:\t\t\t\t*"
				"\n\t\t*\t\t\t 5-LISTAR TIPOS\t\t\t\t\t*"
				"\n\t\t*\t\t\t 6-ALTA HOJA DE SERVICIO\t\t\t*"
				"\n\t\t*\t\t\t 7-LISTAR HOJA DE SERVICIO\t\t\t*"
				"\n\t\t*\t\t\t 8-INFORMES\t\t\t\t\t*"
				"\n\t\t*\t\t\t 9-SALIR\t\t\t\t\t*"
				"\n\t\t*\t\t\t\t\t\t\t\t\t*\n"
				"\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n", "Ingrese opcion valida\n", 0, 10);

		switch (option) {
		case 1:
			printf("\n Selecciono ALTA VEHICULO: \n \n");

			if (addVehicle(vehicles, TAM, description, TAM_TYPE) == OK) {


			} else {
				printf("\t\tNo hay espacio para dar altas\n");
			}
			break;
		case 2:
			printf("\n \n Selecciono MODIFICAR VEHICULO: \n \n");

			modifyVehicles(vehicles, TAM, description, TAM_TYPE);
			break;
		case 3:
			printf("\n \n Selecciono BAJA PRODUCTO:  \n \n");

			downVehicle(vehicles, TAM, description, TAM_TYPE);
			break;
		case 4:
			printf("\n \n Selecciono LISTAR VEHICULOS. \n \n");

			sortTypeVehicle(vehicles, description, TAM);
			retorno = listVehicles(vehicles, TAM, description, TAM_TYPE);

			if (retorno == ERROR) {
				printf("\t\tNada para mostrar\n");
			}
			break;
		case 5:

			listTypes(vehicles, description, TAM);

			break;
		case 6:


			addSheet(oneSheet, vehicles, description,TAM, TAMSHEET, TAM_TYPE);
			break;
		case 7:

			totalPricePerVehicle(oneSheet, vehicles, description, TAMSHEET, TAM, TAM_TYPE);
			//listSheets(oneSheet, TAMSHEET);

			break;
		case 8:

			reportsMenu(oneSheet, vehicles, description, TAM, TAMSHEET);
//			showTypes(vehicles, description, TAM);
//
//			showSheetPerDate(oneSheet, TAMSHEET);
			break;
		}
	} while (option != 9);

	return EXIT_SUCCESS;
}
