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
#include "hojaServicio.h"
/// @brief showOneType3Doors		Funcion muestra vehículos de tipo SEDAN DE 3 PUERTAS al ser seleccionada.
///
/// @param arrayVehicle				Array de vehiculos dados de alta.
/// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
/// @param len						Tamanio de ARRAY de vehiculos.
/// @return	           				Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int showOneType3Doors(sVehicle arrayVehicle[], sType arrayType[], int len) ;
/// @brief showOneType5Doors		Funcion muestra vehículos de tipo SEDAN DE 5 PUERTAS al ser seleccionada.
///
/// @param arrayVehicle				Array de vehiculos dados de alta.
/// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
/// @param len						Tamanio de ARRAY de vehiculos.
/// @return							Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int showOneType5Doors(sVehicle arrayVehicle[], sType arrayType[], int len);
/// @brief showOneTypeTruck			Funcion muestra vehículos de tipo CAMIONETA al ser seleccionada.
///
/// @param arrayVehicle				Array de vehiculos dados de alta.
/// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
/// @param len						Tamanio de ARRAY de vehiculos.
/// @return							Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int showOneTypeTruck(sVehicle arrayVehicle[], sType arrayType[], int len) ;
/// @brief showTypes				Funcion para mostrar los tipos de vehiculos por vehiculos dados de alta seleccionados.
///
/// @param arrayVehicle				Array de vehiculos dados de alta.
/// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
/// @param len						Tamanio de ARRAY de vehiculos.
void showTypes(sVehicle arrayVehicle[], sType arrayType[], int len);
/// @brief askDate					Funcion de tipo sDate(estructura de fecha) para realizar la carga de fecha elegida por usuario.
///
/// @return							Retorno auxiliar de sDate(estructura de fecha) con los datos de fecha cargados por el usuario.
sDate askDate();
/// @brief showSheetPerDate			Funcion muestra todas las hojas de servicio efectuadas en una fecha seleccionada por el usuario.
///
/// @param arraySheet				Array de hojas de servicio dada de alta.
/// @param lenSheet					Tamanio de ARRAY de hojas de servicio.
/// @param arrayVehicle				Array de vehiculos dados de alta.
/// @param len						Tamanio de ARRAY de vehiculos.
/// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
/// @param lenType					Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return							Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int showSheetPerDate(sSheet arraySheet[], int lenSheet, sVehicle arrayVehicle[], int len, sType arrayType[], int lenType);
/// @brief loadDataSheetIdReports	Funcion para preguntar por ID de vehiculo a ingresar por usuario
///
/// @return							Retorno auxiliar de sDate(estructura de fecha) con los datos de fecha cargados por el usuario.
int loadDataSheetIdReports();
/// @brief acumulatorPerVehicle		Funcion informa importe total de las hojas de servicio realizadas en un vehículo seleccionado por el usuario.
///
/// @param arraySheet				Array de hojas de servicio dada de alta.
/// @param arrayVehicle				Array de vehiculos dados de alta.
/// @param lenSheet					Tamanio de ARRAY de hojas de servicio.
/// @param len						Tamanio de ARRAY de vehiculos.
/// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
/// @param lenType					Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return							Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int acumulatorPerVehicle(sSheet arraySheet[], sVehicle arrayVehicle[],
		int lenSheet, int len, sType arrayType[], int lenType );
/// @brief askType					Funcion para obtener el ID de tipo de vehiculo elegido por usuario.
///
/// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
/// @return						    Retorno ID de tipo de vehiculo elegido por usuario a traves de auxiliar sVehicle.
int askType(sType arrayType[]);
/// @brief pricePerDateOneType		importe total de todas las hojas de servicio de un tipo en una fecha seleccionada por el usuario.
///
///
/// @param arraySheet				Array de hojas de servicio dada de alta.
/// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
/// @param arrayVehicle				Array de vehiculos dados de alta.
/// @param lenSheet					Tamanio de ARRAY de hojas de servicio.
/// @param lenType					Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @param len						Tamanio de ARRAY de vehiculos.
/// @return							Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int pricePerDateOneType(sSheet arraySheet[], sType arrayType[], sVehicle arrayVehicle[], int lenSheet,
		int lenType, int len);
/// @brief reportsMenu				Funcion para mostrar opciones de menu de informar e informar las mismas elegidas por el usuario.
///
/// @param arraySheet				Array de hojas de servicio dada de alta.
/// @param arrayVehicle				Array de vehiculos dados de alta.
/// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
/// @param len						Tamanio de ARRAY de vehiculos.
/// @param lenSheet					Tamanio de ARRAY de hojas de servicio.
/// @param lenType					Tamanio de ARRAY de tipos de vehiculo harcodeado.
void reportsMenu(sSheet arraySheet[], sVehicle arrayVehicle[], sType arrayType[],
		int len, int lenSheet, int lenType);
#endif /* INFORMES_H_ */
