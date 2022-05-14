/*
 * ArrayPassenger.c
 *
 *  Created on: 3 may. 2022
 *      Author: Ayala Sebastian F.
 */
//Ayala Sebastian Fernando 1ro H

#include "arrayVuelo.h"
#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menusTPN2.h"
#include "biblioPropia.h"

//Estado de Pasajero .isEmpty
#define TRUE 1 // Vacio
#define FALSE 0 // Cargado
#define BAJA -1 // Dado de Baja
//Tipo de Pasajero
#define VIP 1
#define TURISTA 0

/*Funcion estatica que genera los ID's
 * Devuelve un int con el nro de ID nuevo
 */
static int obtenerID(void);
static int obtenerID(void) {

	static int PasajeroID = 100;
	return PasajeroID++;
}

/*Funcion estatica que busca la Primer posicion libre de la estructura
 * y devuelve un int con ese indice
 * en caso de no encontrar ninguna posicion libre devuelve -1
 */
static int buscarIndiceLibre(Passenger* list, int len);
static int buscarIndiceLibre(Passenger* list, int len){
	int indiceLibre= -1;
	int i;
	if(list != NULL && len > 0)
	{
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == TRUE)
			{
				indiceLibre = i;
				break;
			}
		}
	}
	return indiceLibre;
}

/**
 * Funcion estatica que busca el primer Indice del array ocupado
 * @param list Array de tipo Passenger
 * @param len int con el largo del array
 * @return devuelve un int con la primer posicion ocupada
 */
static int buscarIndiceOcupado(Passenger* list, int len);
static int buscarIndiceOcupado(Passenger* list, int len){
	int indiceOcupado= -1;
	int i;
	if(list != NULL && len > 0)
	{
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE)
			{
				indiceOcupado = i;
				break;
			}
		}
	}
	return indiceOcupado;
}

/*Funcion que inicializa todos los campos del array isEmpty en TRUE de la estructura Passenger
 * Devuelve -1 si algo salio MAL
 * Devuelve 0 si salio BIEN.
 * Passenger* puntero a la estructura de ese tipo
 * len longitud o cantidad de Passanger de tipo entero
 */
int initPassengers(Passenger* list, int len)
{
	int retorno = -1;
	int i;
	if (list != NULL && len > 0 )
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/* \brief add in a existing list of passengers the values received as parameters
 * in the first empty position
 * \param list passenger*
 * \param lenAux int RECIBE EL INDICE DEL ARRAY DE ESTRUCTURA EN DONDE TENGO QUE CARGAR LOS DEMAS DATOS
 * \param idAux int
 * \param nameAux[] char
 * \param lastNameAux[] char
 * \param priceAux float
 * \param typePassengerAux int
 * \param flycodeAux[] char
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addPassenger(Passenger* list, int lenAux, int idAux, char nameAux[],char
		lastNameAux[],float priceAux,int typePassengerAux, char flycodeAux[], int statusFlightAux)
{
	int rtn = -1;

	if(list != NULL && lenAux >= 0 && nameAux != NULL && lastNameAux != NULL && priceAux >0 &&
			typePassengerAux <=1 && flycodeAux != NULL && statusFlightAux <= 1)
	{
		if (list[lenAux].isEmpty == TRUE) {
			list[lenAux].id = idAux;
			strcpy(list[lenAux].name, nameAux);
			strcpy(list[lenAux].lastName , lastNameAux);
			list[lenAux].price = priceAux;
			list[lenAux].typePassenger = typePassengerAux;
			strcpy(list[lenAux].infoVuelo.flyCode, flycodeAux);
			list[lenAux].infoVuelo.statusFlight = statusFlightAux;

			list[lenAux].isEmpty = FALSE;

			rtn = 0; // VERDADERO
		}
		else {
			printf("\nNo quedan lugares disponible para agregar pasajeros.");
			rtn = -1;
		}
	}
	return rtn;
}

/* \brief find a Passenger by Id en returns the index position in array.
 * \param list Passenger*
 * \param len int
 * \param id int
 * \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
 */
int findPassengerById(Passenger* list, int len, int id) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE) {
				if (list[i].id == id) {
					retorno = i; //retorno index del ID que estoy buscando
					break;
				}
			}
		}
	}
	return retorno;
}

/* Funcion que llama a mostrarPasajerosCargados
 * para que el usuario vea el ID del pasajero que desea modificar
 * verifica que el ID este correcto Y llama a findPassengerByID
 * para encontrar el index del Pasajero y luego muestra el subMenu
 * para que el usuario modifique de a 1 solo dato a la vez
 */
int modificarCampos(Passenger* list, int len ) // FALTA PASAR A ALGO O ALGUIEN LOS VALORES QUE CARGO EN LA ESTRUCTURA AUXILIAR
{
	int retorno = -1;
	Passenger eAux;
	int buscarID, indice;
	int opcion, guardarCambios;
	int modificaciones=0;

	if(list != NULL && len > 0){
		if(buscarIndiceOcupado(list, len) == -1){
			printf("\n\n\t\t PRIMERO DEBE DAR DE ALTA AL MENOS 1 PASAJERO PARA ELEGIR ESTA OPCION\n");
		}else{
			printPassenger(list, len);
			if(utn_getNumInt(&buscarID, "\nIngrese ID del Pasajero que desea Modificar: ", "\nID no Valido", 1, 9999, 2)==0){
				indice = findPassengerById(list, len, buscarID);
				if(indice < 0){
					printf("\nEl numero de ID: %d no corresponde a ningun Pasajero",buscarID);
					return retorno;
				}
			}else{
				printf("\nError al tomar el ID");
			}

			eAux = list[indice]; // COPIO EN LA ESTRUCTURA AUXILIAR TODOS LOS DATOS DEL INDEX A MODIFICAR
			do{
				menuModificadorDatos();

				fflush(stdin);
				utn_getNumInt(&opcion,"\nSeleccione una opcion a Cargar/Modificar", "\nOpcion No Valida.", 1, 7, 2);

				switch (opcion) {
				case 1: // PIDO EL NOMBRE
					if((utn_getStringSinNros(eAux.name, sizeof(eAux.name), "\nIngrese el Nombre: ", "\n Dato no valido", 2)) ==0){
						modificaciones ++;
					}
					break;
				case 2:// PIDO EL APELLIDO
					if((utn_getStringSinNros(eAux.lastName, sizeof(eAux.lastName), "\nIngrese el Apellido: ", "\n Dato no valido", 2))==0){
						modificaciones ++;
					}
					break;
				case 3: // PIDO EL PRECIO
					if((utn_getNumFloat(&eAux.price,"\nIngrese el Precio: ", "\nIngrese el Precio: ", 0, 9999999, 2))==0){
						modificaciones ++;
					}
					break;
				case 4: // PIDO EL CODIGO DE VUELO
					if((utn_getStringAlfaNum(eAux.infoVuelo.flyCode, sizeof(eAux.infoVuelo.flyCode),"\nIngrese el Codigo de Vuelo:","\nNo Valido.",2))==0){
						modificaciones ++;
					}
					break;
				case 5 : // PIDO EL TIPO DE PASAJERO
					if((utn_getNumInt(&eAux.typePassenger, "\n\t*Tipo de Pasajero*\nIngrese '0' Clase TURISTA o '1' VIP: ", "\n Dato no valido", 0, 1, 2))==0){
						modificaciones ++;
					}
					break;
				case 6 : // PIDO EL ESTADO DEL VUELO
					if(utn_getNumInt(&eAux.infoVuelo.statusFlight,"\n*Estado de Vuelo*\nIngrese:\t'1' ACTIVO;\t'0'DEMORADO;\t'-1' CANCELADO.\t","\n Dato no valido", -1, 1, 2)==0){
						modificaciones ++;
					}
					break;
				case 7 : // SALIR PERO ANTES PREGUNTA SI DESEA CONFIRMAR LAS MODIFICACIONES
					if(modificaciones > 0 ){
						printf("\n\tUSTED HA REALIZADO %d MODIFICACIONES.",modificaciones);
						utn_getNumInt(&guardarCambios,"\tPresione '1' para CONFIRMAR y GUARDAR o '0' para CANCELAR(se perderan las modificaciones) :", "\nError Reingrese", 0, 1, 3);
						if(guardarCambios == 1){
							list[indice] = eAux;
							printf("\n\nCAMBIOS REALIZADOS");
						}
						else{
							printf("\n\nCAMBIOS DESCARTADOS");
						}
					}else{
						printf("\n\nNO SE REALIZARON MODIFICACIONES");
					}
					break;
				}

			}while (opcion != 7);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * Funcion que pide los datos en una estructura auxiliar tipo Passenger
 * Los Valida y si estan correctos los llama a addPassenger pasandole estos valores para que los guarde
 * @param list /estructura de tipo Passenger
 * @param len de tipo int / Cantidad de Pasajeros
 * @return Devuelve -1 en caso de Erro en los parametros recibidos
 * Devuelve 0 si salio bien
 */
int altaPassenger(Passenger* list, int len){

	int retorno = -1;
	int lenAux;
	Passenger eAux;

	if(list != NULL && len > 0 ){

		fflush(stdin);
		if(utn_getStringSinNros(eAux.name, sizeof(eAux.name), "\nIngrese el Nombre: ", "\n Dato no valido", 2) == 0){
			if(utn_getStringSinNros(eAux.lastName, sizeof(eAux.lastName), "\nIngrese el Apellido: ", "\n Dato no valido", 2)==0){
				if(utn_getNumFloat(&eAux.price,"\nIngrese el Precio: ", "\nIngrese el Precio: ", 0, 9999999, 2)==0){
					if(utn_getStringAlfaNum(eAux.infoVuelo.flyCode, sizeof(eAux.infoVuelo.flyCode),"\nIngrese el Codigo de Vuelo:","\nNo Valido.",2)==0){
						if(utn_getNumInt(&eAux.typePassenger,"\n*Tipo de Pasajero*\nIngrese '0' Clase TURISTA o '1' VIP: ", "\n Dato no valido", 0, 1, 2)==0){
							if(utn_getNumInt(&eAux.infoVuelo.statusFlight,"\n*Estado de Vuelo*\nIngrese:\t'1' ACTIVO;\t'0'DEMORADO;\t'-1' CANCELADO.\t","\n Dato no valido", -1, 1, 2)==0)
							{
								eAux.id = obtenerID(); //Llamo a la funcion que me genera un nuevo ID
								lenAux = buscarIndiceLibre(list, len);// traigo la primer posicion libre de pasajeros y luego se la paso a la funcion addPassanger

								if(eAux.name != NULL && eAux.lastName != NULL && eAux.price >0 &&
										eAux.infoVuelo.flyCode != NULL && eAux.typePassenger >= 0 && eAux.typePassenger <= 1 && eAux.infoVuelo.statusFlight <=1)
								{
									if(addPassenger(list,lenAux, eAux.id, eAux.name,eAux.lastName,eAux.price,eAux.typePassenger, eAux.infoVuelo.flyCode,eAux.infoVuelo.statusFlight) == 0){

										printf("\nCARGA EXITOSA\n");
									}
								}
							}
						}
					}
				}
			}
		}
	}return retorno;
}

/* Funcion para forzar carga de Pasajeros
 * SE PUEDE USAR EN CUALQUIER DEL MOMENTO DEL PROGRAMA QUE NO BORRARA A OTRO PASAJERO
 * eList Recibe una estructura tipo Passenger
 * devuelve 0 si se cargo correctamente
 * devuelve -1 si no se cargo
 */
int forzarCarga(Passenger* eList)
{
	int retorno = -1;
	int i=0;

	if(eList != NULL){

		i= buscarIndiceLibre(eList,2000);
		if(i!= -1){
			strcpy(eList[i].name,"Sebastian");
			strcpy(eList[i].lastName,"Ayala");
			eList[i].price = 18999.99;
			eList[i].typePassenger = VIP;
			strcpy(eList[i].infoVuelo.flyCode,"ABCD12345");
			eList[i].isEmpty = FALSE;
			eList[i].id = obtenerID();
			eList[i].infoVuelo.statusFlight = ACTIVO;
		}

		i= buscarIndiceLibre(eList,2000);
		if(i!= -1){
			strcpy(eList[i].name,"Fabiana");
			strcpy(eList[i].lastName,"Guzman");
			eList[i].price = 2599.89;
			eList[i].typePassenger = TURISTA;
			strcpy(eList[i].infoVuelo.flyCode,"ABCD12345");
			eList[i].isEmpty = FALSE;
			eList[i].id = obtenerID();
			eList[i].infoVuelo.statusFlight = DEMORADO;
		}

		i= buscarIndiceLibre(eList,2000);
		if(i!= -1){
			strcpy(eList[i].name,"Roberto");
			strcpy(eList[i].lastName,"Garcia");
			eList[i].price = 3209.25;
			eList[i].typePassenger = VIP;
			strcpy(eList[i].infoVuelo.flyCode,"AA0919");
			eList[i].isEmpty = FALSE;
			eList[i].id = obtenerID();
			eList[i].infoVuelo.statusFlight = ACTIVO;
		}

		i= buscarIndiceLibre(eList,2000);
		if(i!= -1){
			strcpy(eList[i].name,"Veronica");
			strcpy(eList[i].lastName,"Fernandez");
			eList[i].price = 5323.50;
			eList[i].typePassenger = TURISTA;
			strcpy(eList[i].infoVuelo.flyCode,"AA0919");
			eList[i].isEmpty = FALSE;
			eList[i].id = obtenerID();
			eList[i].infoVuelo.statusFlight = CANCELADO;
		}

		i= buscarIndiceLibre(eList,2000);
		if(i!= -1){
			strcpy(eList[i].name,"Hector");
			strcpy(eList[i].lastName,"Lopez");
			eList[i].price = 8999.50;
			eList[i].typePassenger = TURISTA;
			strcpy(eList[i].infoVuelo.flyCode,"CA1888");
			eList[i].isEmpty = FALSE;
			eList[i].id = obtenerID();
			eList[i].infoVuelo.statusFlight = CANCELADO;
		}

		i= buscarIndiceLibre(eList,2000);
		if(i!= -1){
			strcpy(eList[i].name,"Maria");
			strcpy(eList[i].lastName,"Lopez");
			eList[i].price = 18999.50;
			eList[i].typePassenger = VIP;
			strcpy(eList[i].infoVuelo.flyCode,"CA1888");
			eList[i].isEmpty = FALSE;
			eList[i].id = obtenerID();
			eList[i].infoVuelo.statusFlight = DEMORADO;
		}

		i= buscarIndiceLibre(eList,2000);
		if(i!= -1){
			strcpy(eList[i].name,"Esteban");
			strcpy(eList[i].lastName,"Zanetti");
			eList[i].price = 18999.50;
			eList[i].typePassenger = VIP;
			strcpy(eList[i].infoVuelo.flyCode,"PR2812");
			eList[i].isEmpty = FALSE;
			eList[i].id = obtenerID();
			eList[i].infoVuelo.statusFlight = ACTIVO;
		}
		retorno = 0;
	}
	return retorno;
}

/* \brief Remove a Passenger by Id (put isEmpty Flag in 1)
 *
 * \param list Passenger*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
 *
 */
int removePassenger(Passenger* list, int len, int id){

	int retorno = -1;
	int indice;
	int confirmaBaja;

	if(list != NULL && len > 0 && id > 0){

		indice = findPassengerById(list, len, id);

		if(indice < 0 || list[indice].isEmpty == TRUE){
			printf("\nEl numero de ID: %d no corresponde a ningun Pasajero dado de ALTA",id);
			return retorno;
		}else{
			printf("\nATENCION ESTA POR DAR DE BAJA UN PASAJERO:");
			fflush(stdin);
			utn_getNumInt(&confirmaBaja,"\tPresione '1' para CONFIRMAR o '0' para CANCELAR:", "\nError Reingrese", 0, 1, 3);
			if(confirmaBaja == 1){
				list[indice].isEmpty = BAJA;//Al Setearlo en BAJA es decir "-1" dejo sin poder utlizarse este indice, pero me sirve por si en algun futuro necesito ver los dados de BAJA
				retorno = 0;
			}
			else{
				printf("\n CAMBIOS DESCARTADOS");
			}
		}
	}
	return retorno;
}

/*
 * Funcion que sera llamada en el MAIN
 * Muestra los Pasajeros dados de ALTA para que el usuario vea los ID
 * pide el ID y llama removePassenger(); que validara si es un ID correcto
 * antes de darlo de BAJA
 * retorna un int: 0 si se realizo una BAJA y -1 si no se ralizo la BAJA
 */
int bajaPassenger(Passenger* list, int len){

	int retorno = -1;
	int auxID;

	if(list != NULL && len > 0 ){

		if(buscarIndiceOcupado(list, len) == -1){
			printf("\n\n\t\t PRIMERO DEBE DAR DE ALTA AL MENOS 1 PASAJERO PARA ELEGIR ESTA OPCION\n");
		}
		else{
			utn_getNumInt(&auxID,"\nIngrese ID del Pasajero que desea dar de BAJA: ", "\nID no Valido", 1, 9999, 2);

			if(removePassenger(list,len,auxID) == 0 ){
				printf("PASAJERO ID: %d - DADO DE BAJA",auxID);
				retorno = 0;
			}
			else{
				printf("\n NO SE REALIZO NINGUNA BAJA");
			}
		}
	}
	return retorno;
}

/* \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
 *
 * \param list Passenger*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortPassengers(Passenger* list, int len, int order)
{
	int retorno = -1 ;
	int i,j;
	int comparoArray;
	Passenger eAux;
	if (list != NULL && len > 0){
		if(order == 1){//ORDENO DE MENOR A MAYOR (ASCENDENTE)
			for (i = 0; i < len - 1; i++){
				for (j = i + 1; j < len; j++) {
					if (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE){//VALIDO QUE ESTEN DADOS DE ALTA
						comparoArray = strcmpi(list[i].lastName,list[j].lastName);
						if (comparoArray > 0) { //INTERCAMBIO POSICIONES EN ARRAY SEGUN APELLIDOS
							eAux = list[i];
							list[i] = list[j];
							list[j] = eAux;
						}//EN CASO DE REPETIRSE LOS APELLIDOS INTERCAMBIO POSICIONES EN ARRAY SEGUN TIPO DE PASAJERO Y
						if(comparoArray == 0){
							if(list[i].typePassenger > list[j].typePassenger){
								eAux = list[i];
								list[i] = list[j];
								list[j] = eAux;

							}
						}
					}
				}
			}
			retorno = 0;//ARRAY ORDENADO DE MENOR A MAYOR
		}

		if(order == 0){//ORDENO DE MAYOR A MENOR(DESCENDENTE)
			for (i = 0; i < len - 1; i++){
				for (j = i + 1; j < len; j++) {
					if (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE){//VALIDO QUE ESTEN DADOS DE ALTA
						comparoArray = strcmpi(list[i].lastName,list[j].lastName);
						if (comparoArray < 0) { //INTERCAMBIO POSICIONES EN ARRAY SEGUN APELLIDOS
							eAux = list[i];
							list[i] = list[j];
							list[j] = eAux;
						}
					}//EN CASO DE REPETIRSE LOS APELLIDOS COMPARO E INTERCAMBIO POSICIONES EN ARRAY SEGUN TIPO DE PASAJERO Y
					if(comparoArray == 0){
						if(list[i].typePassenger < list[j].typePassenger){
							eAux = list[i];
							list[i] = list[j];
							list[j] = eAux;

						}
					}
				}
			}
			retorno = 0;// ARRAY ORDENADO DE MAYOR A MENOR
		}

	}return retorno;
}

int printPassenger(Passenger* list, int length){
	int retorno = -1;
	int i;
	if (list != NULL && length > 0){

		printf("\n\nLISTADO DE PASAJEROS");
		printf("\n=======================================================================================================");
		printf("\n|%5s|%15s|%15s|%15s|%15s|%15s|%15s|","ID","NOMBRE","APELLIDO","PRECIO VUELO","COD. VUELO","T. PASAJERO.","STATUS VUELO.");
		printf("\n=======================================================================================================");
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty == FALSE){

				mostrarUnPasajero(list, i);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * Funcion llamada en el main para la Generar informes y luego Mostrarlos
 * @param list de tipo Passenger
 * @param len de tipo int Cantidad de pasajeros
 * @return
 * Devuelve -1 si hay algun Error en los parametros recibidos
 * Devuelve 0 si salio todo bien
 */
int generarInformes(Passenger* list, int len){
	int retorno = -1, opcion, ordenInforme;
	int i;

	if (list != NULL && len > 0){
		if(buscarIndiceOcupado(list, len) == -1){
			printf("\n\n\t\t PRIMERO DEBE DAR DE ALTA AL MENOS 1 PASAJERO PARA ELEGIR ESTA OPCION\n");
		}
		else{
			do{
				menuInformes();
				utn_getNumInt(&opcion,"\n\nIngrese la Opcion deseada:", "Dato no Valido, Reintente", 1, 4, 2);

				switch (opcion){
				case 1://Listo por Apellido y Tipo de pasajero. segun criterio
					if(utn_getNumInt(&ordenInforme,
							"\n\n'0'- PARA LISTAR DE MANERA DESCENDENTE POR APELLIDO Y T. DE PASAJERO."
							"\n'1'- PARA LISTAR DE MANERA ASCENDENTE POR APELLIDO Y T. DE PASAJERO\t", "DATO NO VALIDO", 0, 1, 2) == 0){
						if(sortPassengers(list, len, ordenInforme)==0){
							printPassenger(list, len);
						}else {
							printf("\nERROR.");
						}
					}
					break;
				case 2:// Total y promedio de $ pasajes, y cuántos pasajeros superan el precio promedio.
					if(calcPreciosProm(list, len)==-1){
						printf("\nERROR NO SE PUEDE LISTAR.");
					}
					break;
				case 3:// Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
					if(utn_getNumInt(&ordenInforme,
							"\n\n'0'- PARA LISTAR DE MANERA DESCENDENTE."
							"\n'1'- PARA LISTAR DE MANERA ASCENDENTE\t", "DATO NO VALIDO", 0, 1, 2) == 0){

						if(sortPassengersByCode(list, len, ordenInforme)==0){
							printf("\n\nLISTADO DE PASAJEROS");
							printf("\n=======================================================================================================");
							printf("\n|%5s|%15s|%15s|%15s|%15s|%15s|%15s|","ID","NOMBRE","APELLIDO","PRECIO VUELO","COD. VUELO","T. PASAJERO.","STATUS VUELO.");
							printf("\n=======================================================================================================");

							for(i=0;i<len;i++){
								if(list[i].isEmpty == FALSE && list[i].infoVuelo.statusFlight == 1){
									mostrarUnPasajero(list, i);
								}
							}
						}else {
							printf("\nERROR NO SE PUDO ORDENAR.");
						}

					}
					break;
				case 4://VOLVER AL MENU PRINCIPAL
					break;
				}
			}while (opcion != 4);
		}
	}return retorno;
}

/**
 * Calcula y Muestra Precio Total de Pasajes, Precio Promedio y Cantidad de Pasajeros que Superan el Precio Promedio
 * @param list recibe la estructura de tipo Passenger
 * @param len recibe int con largo de estructura
 * @return Devuelve -1 en caso de Erro en el pasaje de parametros;
 * Devuelve 0 en caso de haber podido calcular y mostrar los promedios
 */
int calcPreciosProm(Passenger* list, int len){
	int retorno= -1;
	int i,cantPasajSupProm = 0;
	float totalPrice = 0, cantPasajeros = 0, promedyPrice;

	if(list != NULL && len > 0)
	{
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE)
			{
				totalPrice += list[i].price;
				cantPasajeros ++;
				retorno = 0;
			}
		}
		promedyPrice = dividirFloat(totalPrice, cantPasajeros);

		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE)
			{
				if(promedyPrice < list[i].price){
					cantPasajSupProm++;
				}
			}
		}
		printf("\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
		printf("\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ P R O M E D I O S  S E G U N  $  P A S A J E S $$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
		printf("\n\n\tEl precio TOTAL de Pasajes es de: %.2f",totalPrice);
		printf("\n\n\tEl precio Promedio de Pasajes es de: %.2f",promedyPrice);
		printf("\n\n\tCantidad de Pasajeros que superan el Precio Promedio: %d",cantPasajSupProm);
		printf("\n\n\n=================================================================================================================");
	}
	return retorno;
}

/**Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o descendente.
 * @param list de tipo Passenger
 * @param len de tipo int Cantidada de pasajeros
 * @param order de tipo int Es el Criterio elegido para ordenar
 * @return
 * Devuelve -1 si hubo algun Error al recibir los parametros
 * Devuelve 0 si salio todo bien
 */
int sortPassengersByCode(Passenger* list, int len, int order){
	int retorno = -1 ;
	int i,j;
	int comparoArray=0;
	Passenger eAux;
	if (list != NULL && len > 0){
		if(order == 1){//ORDENO DE MENOR A MAYOR (ASCENDENTE)
			for (i = 0; i < len - 1; i++){
				for (j = i + 1; j < len; j++) {
					if (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE){//VALIDO QUE ESTEN DADOS DE ALTA
						comparoArray = strcmpi(list[i].infoVuelo.flyCode,list[j].infoVuelo.flyCode);
						if (comparoArray > 0) { //INTERCAMBIO POSICIONES EN ARRAY SEGUN CODIGO DE VUELOS
							eAux = list[i];
							list[i] = list[j];
							list[j] = eAux;
						}
					}
				}
			}
			retorno = 0;//ARRAY ORDENADO DE MENOR A MAYOR
		}
		if(order == 0){//ORDENO DE MAYOR A MENOR(DESCENDENTE)
			for (i = 0; i < len - 1; i++){
				for (j = i + 1; j < len; j++) {
					if (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE){//VALIDO QUE ESTEN DADOS DE ALTA
						comparoArray = strcmpi(list[i].infoVuelo.flyCode,list[j].infoVuelo.flyCode);
						if (comparoArray < 0) { //INTERCAMBIO POSICIONES EN ARRAY SEGUN CODIGO DE VUELOS
							eAux = list[i];
							list[i] = list[j];
							list[j] = eAux;
						}
					}
				}
			}
			retorno = 0;// ARRAY ORDENADO DE MAYOR A MENOR
		}

	}return retorno;
}

/**
 * Funcion que Muestra un pasajero recibiendo el indicie del que se desea mostrar
 * @param list estructura de tipo Passenger
 * @param indice de tipo int
 * @return
 * Devuelve -1 en caso de Error al recibir parametros
 * Devuelve 0 si salio todo bien
 *  */
int mostrarUnPasajero(Passenger* list, int indice){
	int retorno = -1;

	if (list != NULL){
		if(indice >= 0){

			printf("\n|%5d|%15s|%15s|%15.2f|%15s|",list[indice].id,list[indice].name,list[indice].lastName,list[indice].price,
					list[indice].infoVuelo.flyCode);

			if(list[indice].typePassenger==1){
				printf("%15s|","VIP");
			}else{
				printf("%15s|","TURISTA");
			}

			if(list[indice].infoVuelo.statusFlight==ACTIVO){
				printf("%15s|","ACTIVO");
			}else if(list[indice].infoVuelo.statusFlight==DEMORADO){
				printf("%15s|","DEMORADO");
			}else if(list[indice].infoVuelo.statusFlight==CANCELADO){
				printf("%15s|","CANCELADO");
			}
			retorno = 0;

		}else{printf("Error con el Indice que se pasa a Mostrar un Pasajero Indice nro: %d",indice);}
	}else{printf("Error con la Lista en Mostrar un Pasajero");}
	return retorno;
}


