/*
 * vehiculo.h
 *
 *  Created on: 6 oct. 2022
 *      Author: cuerpos
 */

#ifndef VEHICULO_H_
#define VEHICULO_H_

#define MAX_DESCRIPTION 4096
#define MAX_DESCRIPTION_COLOR 11
#include "tipo.h"

typedef struct {
	int idVehicle;
	char description[MAX_DESCRIPTION];
	int model;
	char color[MAX_DESCRIPTION_COLOR];
	int typeId;
	int isEmpty;

}vehicle;

void initializeVehicles(vehicle vehicles[], int len);
int getFreeId(vehicle vehicles[], int len);
int findById(vehicle vehicles[], int idProduct, int len);

void listOneVehicle(vehicle vehicles, type *description, int lenType);
int listVehicles(vehicle vehicles[], int len, type description[], int lenType);
//int listDownvehicles(vehicle vehicles[], int len, type description[], int lenType);


int listTypes(vehicle vehicles[], type description[], int len);


vehicle loadData(void);


int addVehicle(vehicle vehicles[], int len, type description[], int lenType);
int downVehicle(vehicle vehicles[], int len, type description[], int lenType);
vehicle modifyOneVehicle(vehicle vehicles);
int modifyVehicles(vehicle vehicles[], int len, type description[], int lenType);


int sortTypeVehicle(vehicle vehicles[], type description[], int len);




//vehicle Vehicles();
//type TypesHard();

//void recorrerArray(vehicle vehicles[], int len);


#endif /* VEHICULO_H_ */
