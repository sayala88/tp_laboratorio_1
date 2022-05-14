/*
 * ArrayPassenger.h
 *
 *  Created on: 3 may. 2022
 *      Author: Ayala Sebastian F.
 */
//Ayala Sebastian Fernando 1ro H
#include "arrayVuelo.h"
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	//char flyCode[10];
	int typePassenger;
	//int statusFlight;
	eVuelo infoVuelo;
	int isEmpty;
}Passenger;
// Funciones pedidas por el TPN2
int initPassengers(Passenger* list, int len);
int addPassenger(Passenger* list, int lenAux, int idAux, char nameAux[],char
lastNameAux[],float priceAux,int typePassengerAux, char flycodeAux[], int statusFlightAux);
int findPassengerById(Passenger* list, int len, int id);
int removePassenger(Passenger* list, int len, int id);
int printPassenger(Passenger* list, int length);
int sortPassengers(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger* list, int len, int order);

//Mas Funciones complementarias de Passenger
int modificarCampos(Passenger* list, int len ); // FALTA PASAR A ALGO O ALGUIEN LOS VALORES QUE CARGO EN LA ESTRUCTURA AUXILIAR
int altaPassenger(Passenger* list, int len);
int forzarCarga(Passenger* eList);
//int mostrarPasajerosCargados(Passenger* eList, int len);
int bajaPassenger(Passenger* list, int len);
int generarInformes(Passenger* list, int len);
int calcPreciosProm(Passenger* list, int len);
int mostrarUnPasajero(Passenger* list, int indice);

#endif /* ARRAYPASSENGER_H_ */
