/*
 * validaciones.h
 *
 *  Created on: 6 oct. 2022
 *      Author: cuerpos
 */
#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
/// @brief get String      Funcion para pedir dato por consola, a traves de cadena de caracteres.
///
/// @param pString         Puntero de cadena de caracteres.
/// @param len	           Limite de cadena de caracteres.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getString(char *pString, int len);
/// @brief  getAlfaNumeric  Funcion verifica la cadena de caracteres ingresada, devolviendola asi por puntero cadena si es correcta.
///
/// @param pResult   	    Puntero a cadena de caracteres.
/// @param len				Largo de cadena maximo.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getAlfaNumeric(char *pResult, int len);
/// @brief  islfaNumeric  	Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de una cadena caracteres alfanumerica.
///
/// @param pString   	    Puntero de cadena de caracteres.
/// @param len				Largo de cadena maximo.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isAlfaNumeric(char *pString, int len);
/// @brief utn_getAlfaNumeric    Función para pedir una descripcion alfanumerica por consola.
///
/// @param pString          Puntero a direccion de la cadena de  caracteres ingresada en el caso de ser correcta.
/// @param message		    Puntero a cadena de caracteres con mensaje a imprimir para usuario.
/// @param errorMessage     Puntero a cadena de caracteres con mensaje de error.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getAlfaNumeric(char *pString, char *message, char *errorMessage);
/// @brief getInt           Funcion verifica la cadena de caracteres ingresada, convirtiendola, si es valida, a numero entero.
///
/// @param pResult          Puntero numero entero de la conversion realizada con ATOI.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getInt(int *pResult);
/// @brief isInt        	Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de un numero entero.
///
/// @param pString          Puntero de cadena de caracteres a verificar en funcion.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isInt(char *pString);
/// @brief utn_getNumber    Función para pedir un número entero por consola.
///
/// @param pResult          Puntero a direccion de la variable ingresada en el caso de ser correcta.
/// @param message		    Puntero a cadena de caracteres con mensaje a imprimir para pedirle al usuario ingresar un numero.
/// @param errorMessage     Puntero a cadena de caracteres con mensaje de error mientras el dato no sea un numero.
/// @param minimus		    Valor mínimo valido.
/// @param maximus          Valor máximo valido.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getNumber(int *pResult, char *message, char *errorMessage, int minimus,
		int maximus);
/// @brief getFloat		    Funcion verifica la cadena de caracteres ingresada, convirtiendola, si es valida, a numero flotante.
///
/// @param pResult          Puntero numero entero de la conversion realizada con ATOF.
/// @return				    Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getFloat(float *pResult);
/// @brief isFloat          Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de un numero flotante.
///
/// @param pString          Puntero a cadena de caracteres.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isFloat(char *pString);
/// @brief utn_getNumberFloat   Función para pedir un número flotante  por consola
///
/// @param pResult        	    Puntero a direccion de la variable ingresada en el caso de ser correcta.
/// @param message              Puntero a cadena de caracteres con mensaje a imprimir para pedirle al usuario ingresar un numero.
/// @param errorMessage         Puntero a cadena de caracteres con mensaje de error mientras el dato no sea un numero.
/// @param minimus 	            Valor mínimo valido.
/// @param maximus              Valor máximo valido.
/// @return                     Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getNumberFloat(float *pResult, char *message, char *errorMessage,
		float minimus, float maximus);
/// @brief getDescription       Funcion verifica la cadena de caracteres ingresada, devolviendola asi por puntero cadena si es correcta.
///
/// @param pString				Puntero a cadena de caracteres.
/// @param len					Largo de cadena maximo.
/// @return					    Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getDescription(char *pString, int len) ;
/// @brief isDescription 		Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de una cadena alfabetica.
///
/// @param pString				Puntero a cadena de caracteres.
/// @param len					Largo de cadena maximo.
/// @return					    Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isDescription(char *pString, int len);
/// @brief utn_getDescription   Función para pedir una descripcion alfabetica por consola.
///
/// @param pString				Puntero a direccion de la cadena de  caracteres ingresada en el caso de ser correcta.
/// @param message				Puntero a cadena de caracteres con mensaje a imprimir para usuario.
/// @param errorMessage			Puntero a cadena de caracteres con mensaje de error.
/// @return					    Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getDescription(char *pString, char *message, char *errorMessage);
/// @brief 						Funcion para validar las salidas de menus. SOLO siendo validos si(SI) o no(NO)
///
/// @param pString				Puntero a direccion de la cadena de  caracteres ingresada en el caso de ser correcta.
/// @param message				Puntero a cadena de caracteres con mensaje a imprimir para usuario.
/// @param errorMessage			Puntero a cadena de caracteres con mensaje de error.
/// @return						 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getDescriptionExit(char *pString, char *message, char *errorMessage);

#endif /* VALIDACIONES_H_ */
