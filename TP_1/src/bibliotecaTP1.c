/*
 * bibliotecaTP1.c
 *
 *  Created on: 15 abr. 2022
 *      Author: sfa_y
 */

#include <stdio.h>
#include <stdlib.h>

int getInt(int* pOpcion, char msje[], char msjeError[], int min, int max, int reintentos) // Pido y valido los KM
{
	int validador = -1; // Me aseguro de que el retorno de la funcion este mal a menos que entre en todas las validaciones correctamente
	if (pOpcion != NULL && msje != NULL && min < max && msjeError != NULL && reintentos > 0)
	{
		do{
			int auxiliar;
			printf("\n%s", msje);
			fflush(stdin);
			if (scanf("%d", &auxiliar)==1)
			{

				if(auxiliar > min && auxiliar < max)
					{
					*pOpcion = auxiliar;
					validador = 0;
					return validador;
					}
				else{
					reintentos--;
					printf("\n%s",msjeError);
					printf("\nLe quedan %d reintentos.",reintentos);
					}
			}
			else{
				reintentos--;
				printf("\nEsta ingresando un dato NO numerico");
				printf("\nLe quedan %d reintentos.",reintentos);
				}
		}while (reintentos > 0);
	}
	else{
		printf("\nAlgo salio mal");
		system("pause");
		}

return validador;
}

float getFloat(char msje[], float min, float max, char msjeError[], int reintentos) // Pido y valido los KM
{
	if (msje != NULL && min < max && msjeError != NULL && reintentos > 0)
	{
		do{
			float auxiliar = 0;
			printf("\n%s", msje);
			fflush(stdin);
			if (scanf("%f", &auxiliar)==1)
			{
				if(auxiliar > min && auxiliar < max)
					{
					return auxiliar;
					}
				else{
					reintentos--;
					printf("\n%s",msjeError);
					printf("\nLe quedan %d reintentos.",reintentos);
					}
			}
			else{
				reintentos--;
				printf("\nEsta ingresando un dato NO numerico");
				printf("\nLe quedan %d reintentos.",reintentos);
				}
		}while (reintentos > 0);
	}
	else{
		printf("\nAlgo salio mal");
		system("pause");
		}


return 0;
}

float debitar(float costo, float descuento)
{
	float auxiliar = 0;
	auxiliar = costo * descuento;
	return auxiliar;
}

float tarjetear(float monto, float interes)
{
	float auxiliar = 0;
	auxiliar = monto * interes;
	return auxiliar;
}

float cambCriptoM(float precio, float btc)
{
	float auxiliar = 0;
		auxiliar = precio / btc;
		return auxiliar;
}

float precioPorKm(float costoViaje, float kmViaje)
{
	float auxiliar = 0;
			auxiliar = costoViaje / kmViaje;
			return auxiliar;
}

float CalcDifPrecios(float precioLatam, float precioAA)
{
	float auxiliar = 0;
	auxiliar = precioLatam - precioAA;
	if (auxiliar < 0)
		{
			auxiliar *= -1;
		}
	return auxiliar;
}

int calcularTodo(float Km,float precio1,float precio2,float* tarjDebit1, float* tarjDebit2,float descuentoDebito,float* tarjCred1,float* tarjCred2,float interesCredito, float* bitCoin1, float* bitCoin2,float valorBitCoin,float* pUnitario1,float* pUnitario2,float* difPrecios)
{
	int habilitadorAMostrar = -1;
	if(Km != 0 && precio1 != 0 && precio2 != 0)
	{
		*tarjDebit1 = debitar(precio1,descuentoDebito);
		*tarjDebit2 = debitar(precio2,descuentoDebito);
		*tarjCred1 = tarjetear(precio1,interesCredito);
		*tarjCred2 = tarjetear(precio2,interesCredito);
		*bitCoin1 = cambCriptoM(precio1,valorBitCoin);
		*bitCoin2 = cambCriptoM(precio2,valorBitCoin);
		*pUnitario1 = precioPorKm(precio1,Km);
		*pUnitario2 = precioPorKm(precio2,Km);
		*difPrecios = CalcDifPrecios(precio2,precio1);
		printf("\nLos costos se calcularon correctamente\n");
		habilitadorAMostrar = 0;
		return habilitadorAMostrar;
	}
	else
		{
		 printf("\nNo se puede calcualar los costos si no ingresa los kilometros y/o precios");
		}
	return habilitadorAMostrar;
}

void mostrarResultados(float tarjDebit2,float tarjCred2,float bitCoin2,float pUnitario2,float tarjDebit1,float tarjCred1,float bitCoin1,float pUnitario1,float difTotal)
{
	system("cls");
	printf("Latam:\na) Precio con tarjeta de débito: %.2f\n",tarjDebit2);
	printf("b) Precio con tarjeta de crédito: %.2f\n",tarjCred2);
	printf("c) Precio pagando con bitcoin : %.8f\n",bitCoin2);
	printf("d) Precio unitario: %.2f\n",pUnitario2);
	printf("Aerolíneas:\na) Precio con tarjeta de débito: %.2f\n",tarjDebit1);
	printf("b) Precio con tarjeta de crédito: %.2f\n",tarjCred1);
	printf("c) Precio pagando con bitcoin : %.8f\n",bitCoin1);
	printf("d) Precio unitario: %.2f\n",pUnitario1);
	printf("La diferencia de precio es : %.2f\n",difTotal);
}
