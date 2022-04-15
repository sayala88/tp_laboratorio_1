/*
 * bibliotecaTP1.h
 *
 *  Created on: 15 abr. 2022
 *      Author: sfa_y
 */

#ifndef BIBLIOTECATP1_H_
#define BIBLIOTECATP1_H_
int getInt(int* pOpcion, char msje[], char msjeError[], int min, int max, int reintentos); //Declaro Funcion que toma y valida un char y lo graba en una variable con puntero
float getFloat(char msje[], float min, float max, char msjeError[], int reintentos);// Declaro Funcion que Toma, valida y devuelve un flotante sin puntero
float debitar(float costo, float descuento);// Funcion que calcula un descuento y devuelve el resultado al pagar con tarjeta de debito
float tarjetear(float monto, float interes);// Funcion que calcula un interes devuelve el resultado al pagar con tarjeta de credito
float cambCriptoM(float precio, float btc); // Funcion que convierte los pesos AR a Bitcoin y devuelve el resultado
float precioPorKm(float costoViaje, float kmViaje); // Funcion que calcula el precio del viaje por km y devuelve el resultado
float CalcDifPrecios(float precioLatam, float precioAA); // Funcion que muestra la diferencia de precios entre 2 aereolineas devuelve el resultado en valor absoluto
int calcularTodo(float Km,float precio1,float precio2,float* tarjDebit1, float* tarjDebit2,float descuentoDebito,float* tarjCred1,float* tarjCred2,float interesCredito, float* bitCoin1, float* bitCoin2,float valorBitCoin,float* pUnitario1,float* pUnitario2,float* difPrecios);
void mostrarResultados(float tarjDebit2,float tarjCred2,float bitCoin2,float pUnitario2,float tarjDebit1,float tarjCred1,float bitCoin1,float pUnitario1,float difTotal);
#endif /* BIBLIOTECATP1_H_ */
