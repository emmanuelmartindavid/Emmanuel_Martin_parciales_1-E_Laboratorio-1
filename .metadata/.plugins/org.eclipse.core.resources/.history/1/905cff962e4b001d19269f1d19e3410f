/*
 ============================================================================
 Name        : PRIMER-PARCIAL-LABO-1.c
 Author      :  EMMANUEL  DAVID MARTIN
 Version     :  PRIMERO E
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "informes.h"

#define LEN_VEHICLES 100
#define LEN_SHEET 200
#define LEN_TYPE 3

int main(void) {

	setbuf(stdout, NULL);
	sType arrayType[LEN_TYPE];
	sVehicle arrayVehicle[LEN_VEHICLES];
	sSheet arraySheet[LEN_SHEET];

	int pNextId = 76;
	int pNextIdSheet = 20000;
	int option = 0;
	char exit[3];
	int flagRegisterVehicle = 0;
	int flagSheet = 0;

	hardCode(arrayType);

	initializeVehicles(arrayVehicle, LEN_VEHICLES);

	initializeSheet(arraySheet, LEN_SHEET);

	if (hardCodeVehicles(arrayVehicle, LEN_VEHICLES, &pNextId) == OK
			&& hardCodeSheets(arraySheet, LEN_SHEET, &pNextIdSheet) == OK) {
		flagRegisterVehicle = 1;
		flagSheet = 1;
	}

	do {
		utn_getNumber(&option,
				"\t\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-MENU TALLER MECANICO-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"
						"\n\t\t\t\t\t\t\t*\t\t\t\t\t\t\t\t\t*"
						"\n\t\t\t\t\t\t\t*\t\t\t 1-ALTA VEHICULO:\t\t\t\t*"
						"\n\t\t\t\t\t\t\t*\t\t\t 2-MODIFICAR VEHICULO:\t\t\t\t*"
						"\n\t\t\t\t\t\t\t*\t\t\t 3-BAJA VEHICULO\t\t\t\t*"
						"\n\t\t\t\t\t\t\t*\t\t\t 4-LISTAR VEHICULOS:\t\t\t\t*"
						"\n\t\t\t\t\t\t\t*\t\t\t 5-LISTAR TIPOS\t\t\t\t\t*"
						"\n\t\t\t\t\t\t\t*\t\t\t 6-ALTA HOJA DE SERVICIO\t\t\t*"
						"\n\t\t\t\t\t\t\t*\t\t\t 7-LISTAR HOJA DE SERVICIO\t\t\t*"
						"\n\t\t\t\t\t\t\t*\t\t\t 8-INFORMES\t\t\t\t\t*"
						"\n\t\t\t\t\t\t\t*\t\t\t 9-SALIR\t\t\t\t\t*"
						"\n\t\t\t\t\t\t\t*\t\t\t\t\t\t\t\t\t*\n"
						"\t\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n",
				"Ingrese opcion valida\n", 0, 10);

		cls();
		switch (option) {
		case 1:
			cls();
			printf("\t\t\t\t\t\t\t\t\t\t\tALTA VEHICULO\n\n");

			if (registerVehicle(arrayVehicle, LEN_VEHICLES, arrayType) == OK) {
				cls();
				printf(
						"\t\t\t\t\t\t\t\t\tSu vehiculo fue dado de alta correctamente\n\n");
				flagRegisterVehicle = 1;

			} else {
				printf("\t\t\t\t\t\t\t\tNo hay espacio para dar altas\n\n");
			}
			break;
		case 2:
			cls();
			printf("\t\t\t\t\t\t\t\t\t\tMODIFICAR VEHICULO\n\n");

			if (flagRegisterVehicle == 0) {
				printf(
						"\t\t\t\t\t\t\t\tNADA PARA MODIFICAR. PRIMERO DEBE DAR DE ALTA UN VEHICULO\n\n");
			} else if (modifyVehicles(arrayVehicle, LEN_VEHICLES, arrayType,
			LEN_TYPE) == OK) {
				cls();
				printf("\t\t\t\t\t\t\t\t\t\tModificacion exitosa\n");
			} else {

				printf("\t\t\t\t\t\t\t\tNada para modificar\n");
			}
			break;
		case 3:
			cls();
			printf("\t\t\t\t\t\t\t\t\t\tBAJA PRODUCTO\n\n");
			if (flagRegisterVehicle == 0) {
				printf(
						"\t\t\t\t\t\t\t\tNADA PARA DAR DE BAJA. PRIMERO DEBE DAR DE ALTA UN VEHICULO\n\n");
			} else if (downVehicle(arrayVehicle, LEN_VEHICLES, arrayType,
			LEN_TYPE) == OK) {
				cls();
				printf(
						"\t\t\t\t\t\t\t\tSu vehiculo fue dado de baja correctamente\n");

			} else {
				printf("\t\t\t\t\t\t\t\tBaja de vehiculo cancelada\n");

			}
			break;
		case 4:
			cls();
			if (flagRegisterVehicle == 0) {
				printf(
						"\t\t\t\t\t\t\t\tNADA PARA LISTAR. PRIMERO DEBE DAR DE ALTA UN VEHICULO\n\n");
			} else {
				sortPerTypeAndDescriptionVehicle(arrayVehicle, LEN_VEHICLES);
				listVehicles(arrayVehicle, LEN_VEHICLES, arrayType,
				LEN_TYPE);
				printf("\t\t\t\t\t\t\t\t\t\tLISTADO VEHICULOS.\n\n");

			}
			break;
		case 5:
			cls();
			if (flagRegisterVehicle == 0) {
				printf(
						"\t\t\t\t\t\t\t\tNADA PARA LISTAR. PRIMERO DEBE DAR DE ALTA UN VEHICULO\n\n");
			} else if (listTypes(arrayVehicle, arrayType, LEN_VEHICLES) == OK) {

				printf("\t\t\t\t\t\t\t\t\t\tLISTADO TIPOS. \n \n");
			}

			break;
		case 6:
			cls();
			if (flagRegisterVehicle == 0) {
				printf(
						"\t\t\t\t\t\t\t\tNADA PARA DAR DE ALTA. PRIMERO DEBE DAR DE ALTA UN VEHICULO\n\n");
			} else if (registerSheet(arraySheet, arrayVehicle, arrayType,
			LEN_VEHICLES, LEN_SHEET, LEN_TYPE) == OK) {

				printf(
						"\t\t\t\t\t\t\t\tSu hoja de servicio fue dada de alta correctamente\n");
				flagSheet = 1;

			} else {
				printf("\t\t\t\t\t\t\t\tNo hay espacio para dar altas\n");

			}
			break;
		case 7:
			cls();
			if (flagRegisterVehicle == 0 || flagSheet == 0) {
				printf(
						"\t\t\t\t\t\t\tNADA PARA LISTAR. PRIMERO DEBE DAR DE ALTA UN VEHICULO Y UNA HOJA DE SERVICIO\n\n");
			} else if (listSheets(arraySheet, LEN_SHEET, arrayVehicle,
			LEN_VEHICLES, arrayType, LEN_TYPE) == OK) {

				printf("\t\t\t\t\t\t\t\t\t\tLISTADO HOJAS DE SERVICIO. \n \n");
			}

			break;
		case 8:
			cls();
			if (flagRegisterVehicle == 0) {
				printf(
						"\t\t\t\t\t\t\t\tNADA PARA INFORMAR. PRIMERO DEBE DAR DE ALTA AL MENOS UN VEHICULO\n\n");
			} else {
				reportsMenu(arraySheet, arrayVehicle, arrayType, LEN_VEHICLES,
				LEN_SHEET, LEN_TYPE);
			}
			break;
		case 9:
			cls();
			utn_getDescriptionExit(exit,
					"\t\t\t\t\t\t\tPresione si para salir. Presione no para continuar en el menu.\n",
					"\t\t\t\t\t\t\tError. Solo si o no.\n");
			break;
		}

	} while (stricmp(exit,"si") !=0);

	printf("\n\t\t\t\t\t\t\t\t\t\t¡¡HASTA LUEGO!!\n");
	return EXIT_SUCCESS;
}
