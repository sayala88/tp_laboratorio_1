/*
 * menusTPN2.c
 *
 *  Created on: 3 may. 2022
 *      Author: Ayala Sebastian F.
 */
//Ayala Sebastian Fernando 1ro H
#include <stdio.h>
#include "menusTPN2.h"

void menuPrincipal(void){
	printf("\n\n\t\t\t************************************************");
	printf("\n\t\t\t*                MENU PRINCIPAL                *");
	printf("\n\t\t\t*     ADMINITRACION DE PASAJEROS DE VUELOS     *");
	printf("\n\t\t\t*          ®By Sebastián F. Ayala 1°H          *");
	printf("\n\t\t\t************************************************");
	printf("\n\n");
	printf("\n\t1. ALTAS.\n");
	printf("\n\t2. MODIFICAR.\n");
	printf("\n\t3. BAJA.\n");
	printf("\n\t4. INFORMAR.\n");
	printf("\n\t5. CARGA FORZADA.\n");
	printf("\n\t6. SALIR.\n");
	return;
}

void menuModificadorDatos(void){
	printf("\n\n\t*****************************************");
	printf("\n\t*****           SUB-MENU            *****");
	printf("\n\t*****    DE MODIFICACION DE DATOS   *****");
	printf("\n\t*****************************************");
	printf("\n\n");
	printf("\n\t1. NOMBRE.\n");
	printf("\n\t2. APELLIDO.\n");
	printf("\n\t3. PRECIO.\n");
	printf("\n\t4. CODIGO DE VUELO.\n");
	printf("\n\t5. TIPO DE PASAJERO.\n");
	printf("\n\t6. ESTADO DE VUELO.\n");
	printf("\n\t7. VOLVER AL MENU PRINCIPAL.\n");
	return;
}

void menuInformes(void){
	printf("\n\n\t   ##############################");
	printf("\n\t######        SUB-MENU        ######");
	printf("\n\t######  DE INFORMES DE DATOS  ######");
	printf("\n\t   ##############################");
	printf("\n\n");
	printf("\n\t1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n");
	printf("\n\t2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n");
	printf("\n\t3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");
	printf("\n\t4. VOLVER AL MENU PRINCIPAL.\n");
	return;
}
