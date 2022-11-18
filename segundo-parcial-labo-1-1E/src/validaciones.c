/*
 * validaciones.c
 *
 *  Created on: 18 nov. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "menus.h"


/// @brief get String      Funcion para pedir dato por consola, a traves de cadena de caracteres.
///
/// @param pString         Puntero de cadena de caracteres.
/// @param len	           Limite de cadena de caracteres.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getString(char *pString, int len)
{
	int returnGetString = -1;
	char bufferString[4096];

	if (pString != NULL && len > 0)
	{
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= len)
			{
				strncpy(pString, bufferString, len);
				returnGetString = 0;
			}
		}
	}
	return returnGetString;
}
/// @brief  getAlfaNumeric  Funcion verifica la cadena de caracteres ingresada, devolviendola asi por puntero cadena si es correcta.
///
/// @param pResult   	    Puntero a cadena de caracteres.
/// @param len				Largo de cadena maximo.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getalphabetic(char *pString, int len)
{
	int returnGetalphabetic = -1;
	char option[len];
	if (pString != NULL && getString(option, sizeof(option)) == 0 && isAlphabetic(option, sizeof(option)) == 0 && isSpace(option) == 0 && normalizerString(option) == 0 && strnlen(option, sizeof(option)) <= len)
	{

		strncpy(pString, option, len);

		returnGetalphabetic = 0;

	}
	return returnGetalphabetic;
}
/// @brief  islfaNumeric  	Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de una cadena caracteres alfanumerica.
///
/// @param pResult   	    Puntero de cadena de caracteres.
/// @param len				Largo de cadena maximo.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isAlphabetic(char *pString, int len)
{

	int returnIsAlphabetic = 0;
	int lenght;
	if (pString != NULL)
	{
		lenght = strlen(pString);
		for (int i = 0; i < lenght; i++)
		{
			if ((pString[i] < 97 || pString[i] > 122) && (pString[i] < 65 || pString[i] > 90) && (pString[i] != 32))
			{
				returnIsAlphabetic = -1;
				break;
			}
		}

	}
	return returnIsAlphabetic;
}

int isSpace(char *pString)
{
	int returnIsSpace;

	if (pString != NULL)
	{
		if (pString[0] == 32)
		{
			returnIsSpace = -1;
		}
		else
		{
			returnIsSpace = 0;
		}
	}
	return returnIsSpace;
}

int normalizerString(char *pString)
{
	int returnNormalizerString = -1;
	int lenght;
	if (pString != NULL)
	{
		strlwr(pString);
		pString[0] = toupper(pString[0]);
		lenght = strlen(pString);
		for (int i = 0; i < lenght; i++)
		{
			if ((pString[i] == 32))
			{
				pString[i + 1] = toupper(pString[i + 1]);

			}
		}
		returnNormalizerString = 0;
	}
	return returnNormalizerString;
}
/// @brief utn_getAlfaNumeric    Función para pedir una descripcion alfanumerica por consola.
///
/// @param pResult          Puntero a direccion de la cadena de  caracteres ingresada en el caso de ser correcta.
/// @param message		    Puntero a cadena de caracteres con mensaje a imprimir para usuario.
/// @param errorMessage     Puntero a cadena de caracteres con mensaje de error.
/// @param retry				entero, cantidad de reintentos.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getAlphabeticDescription(char *pResult, char *message, char *ErrorMessage, int retry, int len, int min)
{
	int returnUtn_getAlphabeticDescription;
	char bufferString[len];
	while (retry > 0)
	{
		printf(message);
		if (getalphabetic(bufferString, sizeof(bufferString)) == 0 && strlen(bufferString) >= min && strnlen(bufferString, sizeof(bufferString)) < len)
		{
			strncpy(pResult, bufferString, len);
			returnUtn_getAlphabeticDescription = 0;
			break;
		}
		fflush(stdin);
		retry--;
		printf(ErrorMessage);
	}
	if (retry == 0)
	{
		returnUtn_getAlphabeticDescription = -1;
	}
	else
	{
		returnUtn_getAlphabeticDescription = 0;

	}
	return returnUtn_getAlphabeticDescription;
}

/// @brief getInt           Funcion verifica la cadena de caracteres ingresada, convirtiendola, si es valida, a numero entero.
///
/// @param pResult          Puntero numero entero de la conversion realizada con ATOI.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getInt(int *pResult)
{
	int returnGetInt = -1;
	char option[4096];

	if (pResult != NULL && getString(option, sizeof(option)) == 0 && isInt(option, sizeof(option)) == 0)
	{
		*pResult = atoi(option);

		returnGetInt = 0;
	}

	return returnGetInt;
}
/// @brief isInt        Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de un numero entero.
///
/// @param pString          Puntero de cadena de caracteres a verificar en funcion.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isInt(char *pString, int len)
{
	int i = 0;
	int returnIsInt = 0;
	if (pString != NULL && len > 0)
	{
		while (i < len && pString[i] != '\0')
		{
			if (pString[i] < '0' || pString[i] > '9')
			{
				returnIsInt = -1;
				break;
			}
			i++;
		}
	}
	return returnIsInt;
}
/// @brief utn_getNumber    Función para pedir un número entero por consola.
///
/// @param pResult          Puntero a direccion de la variable ingresada en el caso de ser correcta.
/// @param message		    Puntero a cadena de caracteres con mensaje a imprimir para pedirle al usuario ingresar un numero.
/// @param errorMessage     Puntero a cadena de caracteres con mensaje de error mientras el dato no sea un numero.
/// @param minimus		    Valor mínimo valido.
/// @param maximus          Valor máximo valido.
/// @param retry			entero, cantidad de reintentos.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getNumber(int *pResult, char *message, char *errorMessage, int minimus, int maximus, int retry)
{
	int returnUtn_getNumber;
	int num = 0;
	if (pResult != NULL && message != NULL && errorMessage != NULL)
	{
		while (retry > 0)
		{
			printf(message);
			if (getInt(&num) == 0)
			{
				if (num <= maximus && num >= minimus)
					break;
			}
			fflush(stdin);
			retry--;
			printf(errorMessage);
		}
		if (retry == 0)
		{
			returnUtn_getNumber = -1;
		}
		else
		{
			returnUtn_getNumber = 0;
			*pResult = num;
		}
	}
	return returnUtn_getNumber;

}
/// @brief getFloat		    Funcion verifica la cadena de caracteres ingresada, convirtiendola, si es valida, a numero flotante.
///
/// @param pResult          Puntero numero entero de la conversion realizada con ATOF.
/// @return				    Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getFloat(float *pResult)
{
	int returnGetFloat = -1;
	char option[4096];
	if (pResult != NULL)
	{
		if (getString(option, sizeof(option)) == 0 && isFloat(option) == 0)
		{
			*pResult = atof(option);
			returnGetFloat = 0;
		}
	}
	return returnGetFloat;
}
/// @brief isFloat          Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de un numero flotante.
///
/// @param pString          Puntero a cadena de caracteres.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isFloat(char *pString)
{
	int i = 0;
	int returnIsFloat = 0;
	int pointCounter = 0;

	if (pString != NULL && strlen(pString) > 0)
	{
		for (i = 0; pString[i] != '\0'; i++)
		{
			if (pString[i] < '0' || pString[i] > '9')
			{
				if (pString[i] == '.' && pointCounter == 0)
				{
					pointCounter++;
				}
				else
				{
					returnIsFloat = -1;
					break;
				}
			}
		}
	}
	return returnIsFloat;
}
/// @brief utn_getNumberFloat   Función para pedir un número flotante  por consola
///
/// @param pResult        	    Puntero a direccion de la variable ingresada en el caso de ser correcta.
/// @param message              Puntero a cadena de caracteres con mensaje a imprimir para pedirle al usuario ingresar un numero.
/// @param errorMessage         Puntero a cadena de caracteres con mensaje de error mientras el dato no sea un numero.
/// @param minimus 	            Valor mínimo valido.
/// @param maximus              Valor máximo valido.
/// @param retry				entero, cantidad de reintentos.
/// @return                     Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getNumberFloat(float *pResult, char *message, char *errorMessage, float minimus, float maximus, int retry)
{
	int returnUtn_getNumberFloat;
	float num = 0;
	if (pResult != NULL && message != NULL && errorMessage != NULL)
	{
		while (retry > 0)
		{
			printf(message);
			if (getFloat(&num) == 0)
			{
				if (num <= maximus && num >= minimus)
					break;
			}
			fflush(stdin);
			retry--;
			printf(errorMessage);
		}
		if (retry == 0)
		{
			returnUtn_getNumberFloat = -1;
		}
		else
		{
			returnUtn_getNumberFloat = 0;
			*pResult = num;
		}
	}
	return returnUtn_getNumberFloat;
}
/// @brief 						Funcion para validar las salidas de menus. SOLO siendo validos si(SI) o no(NO)
///
/// @param pString				Puntero a direccion de la cadena de  caracteres ingresada en el caso de ser correcta.
/// @param message				Puntero a cadena de caracteres con mensaje a imprimir para usuario.
/// @param errorMessage			Puntero a cadena de caracteres con mensaje de error.
/// @param retry				entero, cantidad de reintentos.
/// @return						 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getDescriptionExit(char *pResult, char *message, char *ErrorMessage, int retry)
{
	int returnUtn_getDescriptionExit;
	char bufferString[3];
	while (retry > 0)
	{
		printf(message);
		if (getalphabetic(bufferString, sizeof(bufferString)) == 0 && (strnlen(bufferString, sizeof(bufferString)) < 3 && (stricmp(bufferString, "si") == 0 || stricmp(bufferString, "no") == 0)))
		{

			returnUtn_getDescriptionExit = 0;
			break;
		}
		fflush(stdin);
		retry--;
		printf(ErrorMessage);
	}
	if (retry == 0)
	{
		returnUtn_getDescriptionExit = -1;
	}
	else
	{
		returnUtn_getDescriptionExit = 0;
		strcpy(pResult, bufferString);

	}
	return returnUtn_getDescriptionExit;
}
/// @brief getshort           Funcion verifica la cadena de caracteres ingresada, convirtiendola, si es valida, a numero short.
///
/// @param pResult          Puntero numero entero de la conversion realizada con ATOI.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getshort(short *pResult)
{
	int returnGetshort = -1;
	char option[4096];

	if (pResult != NULL && getString(option, sizeof(option)) == 0 && isInt(option, sizeof(option)) == 0)
	{

		*pResult = atoi(option);

		returnGetshort = 0;
	}

	return returnGetshort;
}
/// @brief utn_getNumberShort    Función para pedir un número entero por consola.
///
/// @param pResult          Puntero a direccion de la variable ingresada en el caso de ser correcta.
/// @param message		    Puntero a cadena de caracteres con mensaje a imprimir para pedirle al usuario ingresar un numero.
/// @param errorMessage     Puntero a cadena de caracteres con mensaje de error mientras el dato no sea un numero.
/// @param minimus		    Valor mínimo valido.
/// @param maximus          Valor máximo valido.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getNumberShort(short *pResult, char *message, char *errorMessage, int minimus, int maximus, int retry)
{
	int returnUtn_getNumberShort;
	short num = 0;
	if (pResult != NULL && message != NULL && errorMessage != NULL)
	{
		while (retry > 0)
		{
			printf(message);
			if (getshort(&num) == 0)
			{
				if (num <= maximus && num >= minimus)
					break;
			}
			fflush(stdin);
			retry--;
			printf(errorMessage);
		}
		if (retry == 0)
		{
			returnUtn_getNumberShort = -1;
		}
		else
		{
			returnUtn_getNumberShort = 0;
			*pResult = num;
		}
	}
	return returnUtn_getNumberShort;

}
int isValidCreditCardNumber(char *pString)
{
	int returnIsSpace;

	if (pString != NULL)
	{
		if (pString[0] != '4')
		{
			returnIsSpace = -1;
		}
		else
		{
			returnIsSpace = 0;
		}
	}
	return returnIsSpace;
}
/// @brief utn_getValidCreditCardNumber    Función para pedir numero tarjeta de credito por consola.
///
/// @param pResult          Puntero a direccion de la cadena de  caracteres ingresada en el caso de ser correcta.
/// @param message		    Puntero a cadena de caracteres con mensaje a imprimir para usuario.
/// @param errorMessage     Puntero a cadena de caracteres con mensaje de error.
/// @param retry				entero, cantidad de reintentos.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getValidCreditCardNumber(char *pResult, char *message, char *ErrorMessage, int retry, int len, int min)
{
	int returnUtn_getAlphabeticDescription;
	char bufferString[len];
	while (retry > 0)
	{
		printf(message);
		fflush(stdin);
		if (getString(bufferString, sizeof(bufferString))==0 && isValidCreditCardNumber(bufferString)==0 &&  isInt(bufferString, sizeof(bufferString)) == 0 && strlen(bufferString) == min && strnlen(bufferString, sizeof(bufferString)) <= len)
		{
			strncpy(pResult, bufferString, len);
			returnUtn_getAlphabeticDescription = 0;
			break;
		}
		fflush(stdin);
		retry--;
		printf(ErrorMessage);
	}
	if (retry == 0)
	{
		returnUtn_getAlphabeticDescription = -1;
	}
	else
	{
		returnUtn_getAlphabeticDescription = 0;

	}
	return returnUtn_getAlphabeticDescription;
}
/// @brief utn_getModelCar 						OBTIENE MODELO DE AUTO ELEGIDO.
///
/// @param pPosition							PUNTERO STRING.
/// @return										RETORNO 0 EN CASO CORRECTO. -1 EN CASO CONTRARIO.
int utn_getModelCar(char *pModel)
{
	int returnUtn_getModelCar;
	int option;
	char auxModel[19][20] =
	{ " ", "Odyssey", "Mustang", "Monte Carlo", "Continental", "Durango", "Grand Prix", "F-Series", "Frontier", "Pagani", "Savana 3500", "Corvette","Galant", "Mountaineer", "Discovery", "Neon", "Leaf", "Matrix", "Electra"};

	if (pModel != NULL)
	{
		showModelsMenu();
		if (utn_getNumber(&option, "\n\t\t\t\t\t\t\t\t\t\tINGRESE MODELO DE VEHICULO.\n", "\n\t\t\t\t\t\t\t\t\t\t\tERROR. REINTENTE.\n", 1, 18, 3) == 0)
		{
			for (int i = 0; i < 19; i++)
			{
				if (i == option)
				{
					strcpy(pModel, auxModel[i]);
					returnUtn_getModelCar = 0;
				}
			}
		}
		else
		{
			returnUtn_getModelCar = -1;
		}
	}
	return returnUtn_getModelCar;
}



