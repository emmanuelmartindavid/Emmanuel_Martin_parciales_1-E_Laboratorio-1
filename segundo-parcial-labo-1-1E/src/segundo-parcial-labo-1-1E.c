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
#include "LinkedList.h"
#include "Controller.h"
#include "venta.h"

int main(void) {
	setbuf(stdout, NULL);

	LinkedList *listSale = ll_newLinkedList();

	controllerLoadSaleFromText("Autos.csv", listSale);

	controllerListSales(listSale);


	return EXIT_SUCCESS;
}
