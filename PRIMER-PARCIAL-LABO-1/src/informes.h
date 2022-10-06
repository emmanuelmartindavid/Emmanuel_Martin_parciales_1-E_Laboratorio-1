/*
 * informes.h
 *
 *  Created on: 6 oct. 2022
 *      Author: cuerpos
 */

#ifndef INFORMES_H_
#define INFORMES_H_


#include "vehiculo.h"
#include "tipo.h"

int showOneType3Doors(vehicle vehicles[], type description[], int len);

int showOneType5Doors(vehicle vehicles[], type description[], int len);

int showOneTypeTruck(vehicle vehicles[], type description[], int len) ;

void showTypes(vehicle vehicles[], type description[], int len);

//sheet askDate();
date askDate();

int showSheetPerDate(sheet oneSheet[], int lenSheet);

int totalPricePerVehicle(sheet oneSheet[], vehicle vehicles[], type description[], int lenSheet, int len, int lenType);

void reportsMenu(sheet oneSheet[], vehicle vehicles[], type description[], int len,  int lenSheet);

#endif /* INFORMES_H_ */
