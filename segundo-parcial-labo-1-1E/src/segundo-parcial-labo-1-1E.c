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
	int optionMainMenu;
	int flagExit = 0;
	int returnRemoveSale;
	int returnEditSale;
	int idSale;
	char exit[3];
	int returnExit=0;

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
					if (controllerLoadSaleFromText("data.csv", listSale) == SUCCESS && controllerLoadIdSaleFromText("idAutoincremental.txt", &idSale) == SUCCESS && controllerListSales(listSale) == SUCCESS)
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

					if (controllerListReportFirstCriteria(listSale) == SUCCESS && controllerListReportSecondtCriteria(listSale) == SUCCESS && controllerListReporthirdCriteria(listSale) == SUCCESS && controllerListModelCarCriteria(listSale) == SUCCESS)
					{
						printf("\n\t\t\t\t\t\t\t\t\t\t\tINFORMES.\n");
					}
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\tPRIMERO DEBE CARGAR EL ARCHIVO DE TEXTO.\n");
				}
				break;
			case 6:
				if (controllerGeneratesReportSale("Informes.txt", listSale) == SUCCESS)
				{
					printf("\n\t\t\t\t\t\t\t\t\t\tINFORME TXT GENERADO EXITOSAMENTE.\n");
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\t\tHA OCURRIDO UN PROBLEMA AL GENERAR EL INFORME TXT.\n");
				}
				break;
			case 7:
				if (controllerSaveSalesTextMode("data.csv", listSale) == SUCCESS && controllerSaveIdSaleTextMode("idAutoincremental.txt", &idSale) == SUCCESS && controllerSaveSalesBinarytMode("data-binario.bin", listSale) == SUCCESS)
				{
					flagExit=2;
					printf("\n\t\t\t\t\t\t\t\t\t\tARCHIVO .CSV Y .BIN GUARDADOS CORRECTAMENTE.\n");
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t\t\tHA OCURRIDO UN PROBLEMA AL GUARDAR LOS ARCHIVOS.\n");
				}
				break;
			case 8:
				if (flagExit != 2)
				{
					returnExit=utn_getDescriptionExit(exit, "\t\t\t\t\t\t\tVA A SALIR SIN GUARDAR CAMBIOS.\n"
							"\t\t\t\t\t\t\tINGRESE SI PARA SALIR SIN GUARDAR.\n"
							"\t\t\t\t\t\t\tINGRESE NO PARA SEGUIR EN EL MENU.\n", "\t\t\t\t\t\t\tERROR. REINTENTE. SOLO SI O NO\n", 3);

				}
				else if (flagExit == 2)
				{
					returnExit=utn_getDescriptionExit(exit, "\t\t\t\t\t\t\tINGRESE SI PARA SALIR.\n"
							"\t\t\t\t\t\t\tINGRESE NO PARA SEGUIR EN EL MENU.\n", "\t\t\t\t\t\t\tERROR. REINTENTE. SOLO SI O NO\n", 3);
				}
				break;
			}
		}
		else
		{
			printf("\t\t\t\t\t\t\t\t\t\tALGO SALIO MAL.\n");
			break;
		}
	} while (stricmp(exit, "si") != 0 && returnExit==0);

	printf("\n\n\t\t\t\t\t\t\t\t\t\tALGO SALIO MAL. INGRESE BIEN LOS DATOS LA PROXIMA. \n");
	return EXIT_SUCCESS;
}
