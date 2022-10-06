/*
 * validaciones.h
 *
 *  Created on: 6 oct. 2022
 *      Author: cuerpos
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_


int getString(char *string, int len);
int isAlfaNumeric(char *string, int len);
int getAlfaNumeric(char *pResult, int len);
int utn_getAlfaNumeric(char *pResult, char *message, char *ErrorMessage);

int getInt(int *pResult);
int isNumeric(char *string);
int utn_getNumber(int *pResult, char *message, char *errorMessage, int minimus,
		int maximus);

int getFloat(float *pResult);
int isFloat(char *string);
int utn_getNumberFloat(float *pResult, char *message, char *errorMessage,
		float minimus, float maximus);

int getDescription(char *pResult, int len);
int isDescription(char *string, int len);
int utn_getDescription(char *pResult, char *message, char *ErrorMessage);

#endif /* VALIDACIONES_H_ */
