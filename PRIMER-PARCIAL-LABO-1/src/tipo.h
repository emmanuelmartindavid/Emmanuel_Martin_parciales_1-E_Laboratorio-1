/*
 * tipo.h
 *
 *  Created on: 6 oct. 2022
 *      Author: cuerpos
 */

#ifndef TIPO_H_
#define TIPO_H_



#define MAX_DESCRIPTION_TYPE 31
#include "vehiculo.h"

typedef struct{

	int idtype;
	char description[MAX_DESCRIPTION_TYPE];

}type;

int types(type description[], int lenType);

int getDescriptionType(type types[], int lenType, int idType, char *pDescription);


//int listTypes(vehicle vehicles[], type description[], int len);

void hardCode(type oneType[], int lenType);

#endif /* TIPO_H_ */
