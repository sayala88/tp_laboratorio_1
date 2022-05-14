/*
 ============================================================================
 Name        : TP_2.c
 Author      : Ayala Sebastian F.
 Version     :	1° H
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menusTPN2.h"
#include "biblioPropia.h"
#include "ArrayPassenger.h"

#define MAXPASSENGERS 2000

int main(void) {
	setbuf(stdout,NULL);
	int continua, cargaForzadaOK;
	Passenger ePasajeros[MAXPASSENGERS];
	initPassengers(ePasajeros, MAXPASSENGERS);

	do
	{
	menuPrincipal();
	utn_getNumInt(&continua,"\n\tIngrese la opcion deseada", "\nOpcion no valida", 1, 6, 2);
	switch(continua)
		{
			case 1: // ALTA
				altaPassenger(ePasajeros, MAXPASSENGERS);
				break;
			case 2: // MODIFICAR
				modificarCampos(ePasajeros, MAXPASSENGERS);
				break;
			case 3: // BAJA
				bajaPassenger(ePasajeros, MAXPASSENGERS);
				break;
			case 4: // INFORMAR
				generarInformes(ePasajeros, MAXPASSENGERS);
				break;
			case 5:// CARGA FORZADA
				if((cargaForzadaOK = forzarCarga(ePasajeros)) == 0){
					printf("\nCarga Forzada realizada!");
				}
				break;
			case 6: // SALIR
				break;
		}
	}while (continua != 6);
	return EXIT_SUCCESS;
}


