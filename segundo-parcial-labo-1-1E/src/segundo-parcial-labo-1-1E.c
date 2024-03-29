/*
 ============================================================================
 Name        : segundo-parcial-labo-1-1E.c
 Author      : EMMANUEL MARTIN 1.E
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "venta.h"
#include "menus.h"
#include "validaciones.h"

int main(void)
{
	setbuf(stdout, NULL);
	LinkedList *listSale = ll_newLinkedList();
	LinkedList *ListFromBinary = ll_newLinkedList();
	int optionMainMenu;
	int flagLoad = 0;
	int flagExit = 2;
	int flagAdd = 0;
	int flagBinary = 0;
	int returnRemoveSale;
	int returnEditSale;
	int idSale;
	char exit[3];
	int returnExit = 0;
	controllerLoadIdSaleFromText("idAutoincremental.txt", &idSale);
	do
	{
		showMainMenu();
		if (utn_getNumber(&optionMainMenu, "\n\n\t\t\t\t\t\t\t\t\t\t\tINGRESE OPCION.\n", "\n\t\t\t\t\t\t\t\t\t\t\tERROR. REINTENTE.\n", 1, 10, 3) == 0)
		{
			switch (optionMainMenu)
			{
			case 1:
				if (flagLoad == 0)
				{
					if (controllerLoadSaleFromText("data.csv", listSale) == SUCCESS && controllerSortPerIdSale(listSale) == SUCCESS)
					{
						printf("\n\t\t\t\t\t\t\t\t\tSE HA CARGADO EXITOSAMENTE SU ARCHIVO DE TEXTO.\n");
						flagLoad = 1;
					}
					else
					{
						printf("\n\t\t\t\t\t\t\tERROR AL CARGAR EL ARCHIVO.\n");
					}
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\t\tYA REALIZO LA CARGA DE ARCHIVOS.\n");
				}
				break;
			case 2:
				if (flagAdd == 0)
				{
					if (controllerAddSale(listSale, &idSale) == SUCCESS)
					{
						printf("\n\t\t\t\t\t\t\t\t\t\t\tALTA DE VENTA EXITOSA.\n");
						flagExit = 1;
					}
					else
					{
						printf("\n\t\t\t\t\t\t\t\t\t\t\tDATOS INVALIDOS. REINTENTE.\n");
					}
				}
				break;
			case 3:
				if (ll_isEmpty(listSale) == 0)
				{
					returnEditSale = controllerEditSale(listSale);
					if (returnEditSale == SUCCESS)
					{
						printf("\n\t\t\t\t\t\t\t\t\t\tVENTA MODIFICADA EXITOSAMENTE.\n");
						flagExit = 1;
					}
					else if (returnEditSale == ERROR)
					{
						printf("\n\t\t\t\t\t\t\t\t\t\tERROR. REINTENTE\n");
					}
					else if (returnEditSale == NOEDIT)
					{
						printf("\n\t\t\t\t\t\t\t\t\t\t\tNO REALIZO MODIFICACIONES.\n");
					}
					else
					{
						printf("\n\t\t\t\t\t\t\t\t\tNO EXISTE ID DE VENTA. REINTENTE.\n");
					}
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\tPRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO. O DAR AL MENOS UNA VENTA DE ALTA.\n");
				}
				break;
			case 4:
				if (ll_isEmpty(listSale) == 0)
				{
					returnRemoveSale = controllerRemoveSale(listSale);
					if (returnRemoveSale == SUCCESS)
					{
						printf("\n\t\t\t\t\t\t\t\t\tVENTA DADA DE BAJA EXITOSAMENTE.\n");
						flagExit = 1;

					}
					else if (returnRemoveSale == ERROR)
					{
						printf("\n\t\t\t\t\t\t\t\t\tERROR. REINTENTE\n");
					}
					else if (returnRemoveSale == REMOVECANCEL)
					{
						printf("\n\t\t\t\t\t\t\t\t\tBAJA CANCELADA.\n");
					}
					else
					{
						printf("\n\t\t\t\t\t\t\t\t\tNO EXISTE ID DE VENTA. REINTENTE.\n");
					}
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\tPRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO. O DAR AL MENOS UNA VENTA DE ALTA.\n");
				}
				break;
			case 5:
				if (ll_isEmpty(listSale) == 0)
				{
					if (controllerListReportFirstCriteria(listSale) == SUCCESS)
					{
						if (controllerListReportSecondtCriteria(listSale) != SUCCESS)
						{
							printf("\n\t\t\t\t\t\t\t\t\t\tNO CUENTA CON  VENTAS MAYORES A $10000\n");
						}
						if (controllerListReporthirdCriteria(listSale) != SUCCESS)
						{
							printf("\n\t\t\t\t\t\t\t\t\t\tNO CUENTA CON  VENTAS MAYORES A $20000\n");
						}
						if (controllerListModelCarCriteria(listSale) != SUCCESS)
						{
							printf("\n\t\t\t\t\t\t\t\t\t\tSIN ELEMENTOS COINCIDENTES A MODELO MATRIX.\n");
						}
						flagExit = 1;
					}
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\tPRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO. O DAR AL MENOS UNA VENTA DE ALTA.\n");
				}
				break;
			case 6:
				if (ll_isEmpty(listSale) == 0)
				{
					if (controllerGeneratesReportSale("informe.txt", listSale) == SUCCESS)
					{
						printf("\n\t\t\t\t\t\t\t\t\t\tINFORME TXT GENERADO EXITOSAMENTE.\n");
						flagExit = 1;
					}
					else
					{
						printf("\n\t\t\t\t\t\t\t\t\tINFORME TXT GENERADO. NO HAY MODELOS MATRIX EN SU TXT.\n");
					}
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\tPRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO. O DAR AL MENOS UNA VENTA DE ALTA.\n");
				}
				break;
			case 7:
				if (ll_isEmpty(listSale) == 0)
				{
					if (controllerSaveSalesBinarytMode("data-binario.bin", listSale) == SUCCESS)
					{
						flagBinary = 1;
						printf("\n\t\t\t\t\t\t\t\t\t\tARCHIVO .BIN GENERADO CORRECTAMENTE.\n");
					}
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\tPRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO. O DAR AL MENOS UNA VENTA DE ALTA.\n");
				}
				break;
			case 8:
				if (ll_isEmpty(listSale) == 0 && flagBinary == 1)
				{

					if (controllerLoadSalesFromBinary("data-binario.bin", ListFromBinary) == SUCCESS && controllerSortPerIdSale(ListFromBinary) == SUCCESS && controllerListSales(ListFromBinary) == SUCCESS)
					{
						printf("\n\t\t\t\t\t\t\t\t\tLISTADO ARCHIVO DESDE BINARIO.\n");
						flagExit = 1;
					}
					else
					{
						printf("\n\t\t\t\t\t\t\t\tERROR AL CARGAR EL ARCHIVO .BIN. PRIMERO DEBE GENERARO EL MISMO.\n");
					}
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\tPRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO. O DAR AL MENOS UNA VENTA DE ALTA.\n");
				}
				break;
			case 9:

				if (ll_isEmpty(listSale) == 0)
				{
					if (controllerSaveSalesTextMode("data.csv", listSale) == SUCCESS && controllerSaveIdSaleTextMode("idAutoincremental.txt", &idSale) == SUCCESS)
					{
						flagExit = 2;
						printf("\n\t\t\t\t\t\t\t\t\t\tARCHIVO .CSV GUARDADO CORRECTAMENTE.\n");
					}
					else
					{
						printf("\n\t\t\t\t\t\t\t\t\t\tHA OCURRIDO UN PROBLEMA AL GUARDAR LOS ARCHIVOS.\n");
					}
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\tPRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO. O DAR AL MENOS UNA VENTA DE ALTA.\n");
				}
				break;
			case 10:
				if (flagExit != 2)
				{
					returnExit = utn_getDescriptionExit(exit, "\t\t\t\t\t\t\t\t\tVA A SALIR SIN GUARDAR CAMBIOS.\n"
							"\t\t\t\t\t\t\t\t\tINGRESE SI PARA SALIR SIN GUARDAR.\n"
							"\t\t\t\t\t\t\t\t\tINGRESE NO PARA SEGUIR EN EL MENU.\n", "\t\t\t\t\t\t\t\t\tERROR. REINTENTE. SOLO SI O NO\n", 3);

				}
				else if (flagExit == 2)
				{
					returnExit = utn_getDescriptionExit(exit, "\t\t\t\t\t\t\t\t\tINGRESE SI PARA SALIR.\n"
							"\t\t\t\t\t\t\t\t\tINGRESE NO PARA SEGUIR EN EL MENU.\n", "\t\t\t\t\t\t\t\t\tERROR. REINTENTE. SOLO SI O NO\n", 3);
				}
				break;
			}
		}
		else
		{
			printf("\t\t\t\t\t\t\t\t\t\tALGO SALIO MAL.\n");
			break;
		}
	} while (stricmp(exit, "si") != 0 && returnExit == 0);
	if (returnExit != 0)
	{
		printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\tALGO SALIO MAL. INGRESE BIEN LOS DATOS LA PROXIMA. \n");
	}
	else
	{
		printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\tADIOS C. QUE LE VAYA BIEN. GRACIAS. \n");
	}
	return EXIT_SUCCESS;
}
