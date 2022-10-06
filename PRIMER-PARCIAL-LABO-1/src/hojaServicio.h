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

}date;

typedef struct{

	int idSheet;
	int vehicleId;
	char description[MAX_DESCRIPTIONSHEET];
	float servicePrice;
	date oneDate;
	int isEmpty;

}sheet;

void initializeSheet(sheet oneSheet[], int len);
int getFreeIdSheet(sheet oneSheet[], int len);
int findByIdSheet(sheet oneSheet[], int idSheet, int len);

void listOneSheet(sheet oneSheet, int len);
int listSheets(sheet oneSheet[], int len);

int loadDataSheetId(sheet oneSheet[], int lenSheet);
sheet loadDataSheet(void);

//int addSheet(sheet oneSheet[], vehicle vehicles[], int len, int lenSheet);
int addSheet(sheet oneSheet[], vehicle vehicles[], type description[], int len, int lenSheet, int lenType);



#endif /* HOJASERVICIO_H_ */
