/*
 * biblioPropia.h
 *
 *  Created on: 23 abr. 2022
 *      Author: Ayala Sebastian F.
 */
//Ayala Sebastian Fernando 1ro H

#ifndef BIBLIOPROPIA_H_
#define BIBLIOPROPIA_H_
//FUNCIONES MATEMATICAS BASICAS
int sumar(int n1, int n2);
float restar(float n1, float n2);
float multiplicar(float n1, float n2);
float dividirInt(int n1, int n2);
float dividirFloat(float n1, float n2);
//FUNCIONES MATEMATICAS COMPLEMENTARIAS
float InforDifAbsoluta(float num1, float num2);
int informarValor(int nro);
float hacerPromedio(int n1, int n2);
//FUNCIONES DE INPUT
int utn_getNumInt(int *pOpcion, char msje[], char msjeError[], int min, int max, int reintentos);
int utn_getNumFloat(float *pNumIngresado, char msje[], char msjeError[], float min, float max,  int reintentos);
int utn_getChar(char *pOpcion, char msje[], char msjeError[], char min, char max, int reintentos);
int utn_getStringSinNros(char *cadena, int longCadena, char msje[], char msjeError[],int reintentos);
int utn_getStringAlfaNum(char *cadena, int longCadena, char msje[], char msjeError[],int reintentos);

#endif /* BIBLIOPROPIA_H_ */
