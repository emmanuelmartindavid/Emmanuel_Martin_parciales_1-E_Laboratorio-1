/*
 ============================================================================
 Name        : segundo-parcial-labo-1-1E.c
 Author      : 
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
	LinkedList *otra = ll_newLinkedList();

	int optionMainMenu;
	int flagExit = 2;
	int returnRemoveSale;
	int returnEditSale;
	int idSale;
	char exit[3];

	do
	{
		showMainMenu();
		if (utn_getNumber(&optionMainMenu, "\nINGRESE OPCION.\n", "ERROR. REINTENTE.\n", 1, 8, 3) == 0)
		{
			switch (optionMainMenu)
			{
			case 1:
				if (ll_isEmpty(listSale) == 1)
				{
					if (controllerLoadSaleFromText("Autos-3.csv", listSale) == SUCCESS && controllerLoadIdSaleFromText("idAutoincremental.txt", &idSale) == SUCCESS && controllerListSales(listSale) == SUCCESS)
					{
						printf("\n\t\t\t\t\t\t\tSE HA CARGADO EXITOSAMENTE SU ARCHIVO DE TEXTO. EL CUAL CONTIENE LOS ELEMENTOS LISTADOS.\n");
					}
					else
					{
						printf("\n\t\t\t\t\t\t\tERROR AL CARGAR EL ARCHIVO.\n");
					}
				}
				else
				{
					printf("\n\t\t\t\t\t\t\tYA REALIZO LA CARGA DE ARCHIVOS.\n");
				}
				break;
			case 2:
				if (ll_isEmpty(listSale) == 0)
				{
					if (controllerAddSale(listSale, &idSale) == SUCCESS)
					{
						printf("\n\t\t\t\t\t\t\t\t\t\t\tALTA DE VENTA EXITOSA.\n");
					}
					else
					{
						printf("\n\t\t\t\t\t\t\t\t\t\t\tDATOS INVALIDOS. REINTENTE.\n");
					}
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\tPRIMERO DEBE CARGAR EL ARCHIVO DE TEXTO.\n");
				}
				break;
			case 3:
				if (ll_isEmpty(listSale) == 0)
				{
					returnEditSale = controllerEditSale(listSale);
					if (returnEditSale == SUCCESS)
					{
						printf("\n\t\t\t\t\t\t\t\t\t\tVENTA MODIFICADA EXITOSAMENTE.\n");
					}
					else if (returnEditSale == ERROR)
					{
						printf("\n\t\t\t\t\t\t\t\t\t\tERROR. REINTENTE\n");
					}
					else if (returnEditSale == NOEDIT)
					{
						printf("\n\t\t\t\t\t\t\t\t\t\t\tNO REALIZO MODIFICACIONES.\n");
					}
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\tPRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				break;
			case 4:
				if (ll_isEmpty(listSale) == 0)
				{
					returnRemoveSale = controllerRemoveSale(listSale);
					if (returnRemoveSale == SUCCESS)
					{
						printf("\n\t\t\t\t\t\t\t\t\tVENTA DADA DE BAJA EXITOSAMENTE.\n");

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
					printf("\n\t\t\t\t\t\t\t\t\tPRIMERO DEBE CARGAR EL ARCHIVO DE TEXTO.\n");
				}
				break;
			case 5:
				if (ll_isEmpty(listSale) == 0)
				{
					if (controllerListSales(listSale) == SUCCESS)
					{
						printf("\n\t\t\t\t\t\t\t\t\t\t\tLISTADO VEHICULOS.\n");
					}
					else
					{
						printf("\n\t\t\t\t\t\t\t\t\t\t\tNADA PARA MOSTRAR.\n");
					}
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\tPRIMERO DEBE CARGAR EL ARCHIVO DE TEXTO.\n");
				}
				break;
			case 6:
//				controllerGetTotalAmountSale(listSale, &cantidad);
//				printf("CANTIDAD EN MAIN %d\n", cantidad);
//				retcount = ll_count(listSale, getAmountSalesFirstCriteria);
//				printf("CANTIDAD EN MAIN LL_COUNT %d\n", retcount);
				controllerReportSale("Informes.txt", listSale);
//				otra = ll_filter(listSale, getAmountSalesFirstCriteria);
//				controllerListSales(otra);
//				otra = ll_filter(listSale, getAmountSalesSecondCriteria);
//				controllerListSales(otra);
//				otra = ll_filter(listSale, getModelCarCriteria);
//				controllerListSales(otra);

				break;
			case 7:
				controllerSaveSalesTextMode("Autos-3.csv", listSale);
				controllerSaveIdSaleTextMode("idAutoincremental.txt", &idSale);

				break;
			case 8:
				if (flagExit != 2)
				{
					if (utn_getDescriptionExit(exit, "VA A SALIR SIN GUARDAR CAMBIOS.\n"
							"\t\t\t\t\t\t\tTENGA EN CUENTA. SI GENERO ARCHIVOS BINARIOS, LOS MISMOS SERAN ELIMINADOS AL CERRAR EL PROGRAMA.\n"
							"INGRESE SI PARA SALIR SIN GUARDAR.\n"
							"INGRESE NO PARA SEGUIR EN EL MENU.\n", "Error. Solo si o no.\n", 3) == 0)
					{
						if ((stricmp(exit, "si") == 0))
						{

						}
					}
					else
					{
						printf("\n\t\t\t\t ERROR. REINTENTE.\n");
					}
				}
				else if (flagExit == 2)
				{
					utn_getDescriptionExit(exit, "INGRESE SI PARA SALIR.\n"
							"INGRESE NO PARA SEGUIR EN EL MENU.\n", "Error. Solo si o no.\n", 3);
				}
				break;

			}
		}
		else
		{
			printf("\t\t\t\t\t\t\t\t\t\tALGO SALIO MAL.\n");
			break;
		}
	} while (stricmp(exit, "si") != 0);

	return EXIT_SUCCESS;
}
