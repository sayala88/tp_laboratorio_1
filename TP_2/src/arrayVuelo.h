/*
 * arrayVuelo.h
 *
 *  Created on: 7 may. 2022
 *      Author: Ayala Sebastian F.
 */
//Ayala Sebastian Fernando 1ro H

#ifndef ARRAYVUELO_H_
#define ARRAYVUELO_H_
//Estados de Vuelo
#define ACTIVO 1
#define DEMORADO 0
#define CANCELADO -1

typedef struct{
	char flyCode[10];
	int statusFlight;
}eVuelo;

#endif /* ARRAYVUELO_H_ */
