/*
 ============================================================================
 Name        : TP_1.c
 Author      : Ayala Sebastian Fernando
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaTP1.h"
#define TRUE 1
#define FALSE 0
#define DEBITDESC 0.9
#define CREDINTERES 1.25
#define BITCOIN 4463952.30
#define FORZARKM 7090
#define FORZARPRECIOAA 162965
#define FORZARPRECIOLA 159339

int main(void) {

	setbuf(stdout,NULL);
	float kmTotales, precioAA, precioLA, tarjDebitAA, tarjDebitLa, tarjCredAA, tarjCredLa, bitCoinAA, bitCoinLa, pUnitarioAA, pUnitarioLa, difPrecTotal;
	int opc1Menu, Mostrar;
	char repetir = TRUE;
	do{
		system("cls");
		printf("\n1. Ingresar Kilómetros:(km = %.2f)\n2. Ingresar Precio de Vuelos:(Aerolíneas = %.2f , Latam = %.2f)\n3. Calcular todos los costos:\n4. Informar Resultados\n5. Carga forzada de datos\n6. Salir\n",kmTotales,precioAA,precioLA);
		getInt(&opc1Menu,"\nIngrese el numero de la opcion que quiere realizar:","\nEl numero ingresado no es valido.",0,7,3);
		switch (opc1Menu)
		{
		case 1: //Pido los Km
			printf("\nHa seleccionado la opcion 1");
			kmTotales = getFloat("\nIngrese los Km del vuelo por favor: ",0,99999999,"\tEl numero Ingresado no es valido.",3); // con la funcion pido y valido los km y los almaceno en kmTotales
			break;
		case 2: // Pido Precios
			precioAA = getFloat("\nIngrese el precio de Aerolineas Argentinas:",0,99999999,"\tEl precio Ingresado no es valido.",3); // con esta funcion pido y valido el precio de AA y lo guardo en precioAA
			precioLA = getFloat("\nIngrese el precio de Latan:",0,99999999,"\tEl precio Ingresado no es valido.",3); // con esta funcion pido y valido el precio de AA y lo guardo en precioAA
			break;
		case 3: //Calcular costos
			Mostrar = calcularTodo(kmTotales, precioAA, precioLA, &tarjDebitAA, &tarjDebitLa, DEBITDESC, &tarjCredAA, &tarjCredLa, CREDINTERES, &bitCoinAA, &bitCoinLa, BITCOIN, &pUnitarioAA, &pUnitarioLa, &difPrecTotal);
			break;
		case 4: // Informar/Mostrar Resultados
			if(Mostrar == 0)
			{
				mostrarResultados(tarjDebitLa,tarjCredLa,bitCoinLa,pUnitarioLa,tarjDebitAA,tarjCredAA,bitCoinAA,pUnitarioAA,difPrecTotal);
			}
			else
				{
				printf("\nPara Mostrar los costos primero debe calcularlos con la opcion 3\n ");
				}
			system("pause");
			break;
		case 5: // carga Forzada de datos
			kmTotales = FORZARKM;
			precioAA = FORZARPRECIOAA;
			precioLA = FORZARPRECIOLA;
			calcularTodo(kmTotales, precioAA, precioLA, &tarjDebitAA, &tarjDebitLa, DEBITDESC, &tarjCredAA, &tarjCredLa, CREDINTERES, &bitCoinAA, &bitCoinLa, BITCOIN, &pUnitarioAA, &pUnitarioLa, &difPrecTotal);
			mostrarResultados(tarjDebitLa,tarjCredLa,bitCoinLa,pUnitarioLa,tarjDebitAA,tarjCredAA,bitCoinAA,pUnitarioAA,difPrecTotal);
			system("pause");
			break;
		case 6:
			repetir = FALSE;
			break;
		default:
			printf("\nOpcion NO valida\n");
			break;
		}
	}while(repetir);
return EXIT_SUCCESS;
}




