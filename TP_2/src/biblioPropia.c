/*
 * biblioPropia.c
 *
 *  Created on: 23 abr. 2022
 *      Author: Ayala Sebastian F.
 */
//Ayala Sebastian Fernando 1ro H

#include "biblioPropia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 								FUNCIONES Estaticas
static int myGets ( char * cadena, int longitud);
static int esNumerica ( char * cadena);
static int esAlfabetica ( char * cadena);
static int getInt ( int * pResultado);
static int esNumericaFloat ( char * cadena);
static int getFloat (float * pResultado);

/*---------------------------------------------------------------------------------------------------*/
//							**FUNCIONES MATEMATICAS BASICAS*

/*
 * Realiza la suma de 2 numeros enteros y devuelve el resultado
 */
int sumar(int n1, int n2)
{
	int resultado;
	resultado = n1 + n2;
	return resultado;
}

/*
 * Realiza la resta de 2 numeros reales y devuelve el resultado
 */
float restar(float n1, float n2)
{
	float resultado;
	resultado = n1 - n2;
	return resultado;
}

/*
 * Realiza la Multiplicacion de 2 numeros reales y devuelve el resultado
 */
float multiplicar(float n1, float n2)
{
	float resultado;
	resultado = n1 * n2;
	return resultado;
}

/*
 * Realiza la Division de 2 numeros enteros (Casteando uno de ellos para no perder decimales)
 *  y devuelve el resultado como flotante.
 *  Devuelve '0' en caso de que se quiera dividir por '0'.
 */
float dividirInt(int n1, int n2)
{
	float resultado;
	if (n2 == 0)
	{
		resultado = 0;
	}
	else
	{
		resultado = (float)n1 / n2; //CASTEO de n1
	}
	return resultado;
}

/*
 * Recibe 2 numeros reales, los divide y devuelve el resultado.
 * En caso de querer dividir por '0' devuelve '0'
 */
float dividirFloat(float n1, float n2)
{
	float resultado;
	if (n2 == 0) { //VALIDO QUE DEVUELVA UN CERO PARA QUE NO ROMPA EL PROGRAMA AL INTENTAR DIVIDIR POR CERO
		resultado = 0;
	} else {
		resultado = n1 / n2;
	}
	return resultado;
}

/*
 * Devuelve la diferencia de 2 reales en valor absoluto
 */
float InforDifAbsoluta(float num1, float num2)
{
	float auxiliar = 0;
	auxiliar = num1 - num2;
	if (auxiliar < 0)
	{
		auxiliar *= -1;
	}
	return auxiliar;
}

/* Recibe un Numero entero para saber su Signo/Valor
 *Devuelve '1' si es positivo,
 *Devuelve '-1' si es negativo
 *Devuelve '0' si es cero.
 */
int informarValor(int nro)
{
	int resultado;
	if (nro > 0)
	{
		resultado = 1;
	}
	if (nro == 0)
	{
		resultado = 0;
	}
	if (nro < 0)
	{
		resultado = -1;
	}
	return resultado;
}

/*Recibe 2 numeros enteros
 *Devuelve el promedio con CASTEO
 * (significa que convierto el resultado de la suma de enteros a un float antes de dividirlo
 * para no perder los decimales)
 */
float hacerPromedio(int n1, int n2)
{
	float auxiliar;
	auxiliar = ((float) n1 + n2) / 2; // Casteo
	return auxiliar;
}

/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/

// 					FUNCIONES DE ENTRADA Y VALIDACION DE DATOS

/*Pide un caracter, lo valida con rangos y reintentos.
 * y lo graba por referencia en *pOpcion
 * Devuelve '0' si lo tomo bien y
 * Devuelve '-1' si algo salio mal
 *
 */
int utn_getChar(char *pOpcion, char msje[], char msjeError[], char min, char max, int reintentos)
{
	int retorno = -1;
	char auxiliar;

	if (pOpcion != NULL && msje != NULL && min <= max && msjeError != NULL && reintentos > 0)
	{
		do{
			printf("\n%s", msje);
			fflush(stdin);

			if (scanf("%c",&auxiliar)==1)
			{
				if(auxiliar >= min && auxiliar <= max)
				{
					*pOpcion = auxiliar;
					retorno = 0;
					return retorno;
				}
				else{
					reintentos--;
					printf("\n%s",msjeError);
					printf("\nLe quedan %d reintentos.",reintentos);
				}
			}
			else{
				reintentos--;
				printf("\nEsta ingresando un dato NO Valido");
				printf("\nLe quedan %d reintentos.",reintentos);
			}
		}while (reintentos > 0);
	}
	else{
		printf("\nAlgo salio mal");
		system("pause");
	}
	return retorno;

}

/*Pide un entero, lo valida con rangos y reintentos.
 * y lo graba por referencia en *pOpcion
 * Devuelve '0' si lo tomo bien y
 * Devuelve '-1' si algo salio mal
 *
 */
int utn_getNumInt(int *pOpcion, char msje[], char msjeError[], int min, int max, int reintentos)
{
	int retorno = -1; // Me aseguro de que el retorno de la funcion este mal a menos que entre en todas las validaciones correctamente
	int auxiliar;

	if (pOpcion != NULL && msje != NULL && min <= max && msjeError != NULL && reintentos > 0)
	{
		do{
			printf("\n%s", msje);
			fflush(stdin);
			if (getInt(&auxiliar)==0)// Utilizo una funcion estatica
			{
				if(auxiliar >= min && auxiliar <= max)
				{
					*pOpcion = auxiliar;
					retorno = 0;
					return retorno;
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
	return retorno;
}

/*Pide un flotante, lo valida con rangos y reintentos.
 * y lo graba por referencia en *pNumIngresado
 * Devuelve '0' si lo tomo bien y
 * Devuelve '-1' si algo salio mal
 * ACEPTA NEGATIVOS Y DECIMALES
 */
int utn_getNumFloat(float *pNumIngresado, char msje[], char msjeError[], float min, float max,  int reintentos)
{
	int retorno = -1;
	if (pNumIngresado != NULL && msje != NULL && min <= max && msjeError != NULL && reintentos > 0)
	{
		do{
			float auxiliar = 0;
			printf("\n%s", msje);
			fflush(stdin);
			if (getFloat(&auxiliar)==0)//Sirve para validar que el dato ingresado sea numerico aceptando negativos y decimales
			{
				if(auxiliar >= min && auxiliar <= max)
				{
					*pNumIngresado = auxiliar;
					retorno = 0;
					break;
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


	return retorno;
}

/*Pide una cadena, lo valida con rangos y reintentos para que NO tenga Numeros, solo letras y/o simbolos.
 * y lo graba por referencia en *cadena
 * Devuelve '0' si lo tomo bien y
 * Devuelve '-1' si algo salio mal
 */
int utn_getStringSinNros(char *cadena, int longCadena, char msje[], char msjeError[],int reintentos)
{
	int retorno = -1;
	char auxiliar[longCadena];
	if (cadena != NULL && longCadena >0 && msje != NULL && msjeError != NULL && reintentos > 0)
	{
		do{
			printf("\n%s", msje);
			fflush(stdin);
			if (myGets(auxiliar,sizeof(auxiliar))==0 && (esAlfabetica(auxiliar) == 0))
			{
				strcpy(cadena,auxiliar);
				retorno = 0;
				break;
			}
			else{
				reintentos--;
				printf("\nEsta ingresando un dato NO Alfabetico");
				printf("\nLe quedan %d reintentos.",reintentos);
			}
		}while (reintentos > 0);
	}
	else{
		printf("\nAlgo salio mal");
		system("pause");
	}


	return retorno;
}

/*Pide una cadena, lo valida con longitud de cadena y reintentos.acepta todos los caracteres.
 * y lo graba por referencia en *cadena
 * Devuelve '0' si lo tomo bien y
 * Devuelve '-1' si algo salio mal
 */
int utn_getStringAlfaNum(char *cadena, int longCadena, char msje[], char msjeError[],int reintentos)
{
	int retorno = -1;
	char auxiliar[longCadena];
	if (cadena != NULL && longCadena >0 && msje != NULL && msjeError != NULL && reintentos > 0)
	{
		do{
			printf("\n%s", msje);
			fflush(stdin);
			if (myGets(auxiliar,sizeof(auxiliar))==0)
				{
					strcpy(cadena,auxiliar);
					retorno = 0;
					break;
				}
			}while (reintentos > 0);
	}
	else{
		printf("\nAlgo salio mal");
		system("pause");
	}
	return retorno;
}


/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/

// 								FUNCIONES Estaticas


/*
* \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
* un máximo de ' longitud - 1' caracteres .
* \ param *cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
* \ param longitud Define el tamaño de cadena
* \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
static int myGets ( char * cadena, int longitud)
{
	fflush (stdin);
	if (cadena != NULL && longitud >0 && fgets (cadena,longitud,stdin)==cadena)
	{

		if (cadena[strlen(cadena)-1] == '\n' )
		{
			cadena[strlen(cadena)-1] = '\0' ;
		}
		return 0;
	}
	return -1;
}

/*
* \brief Verifica si la cadena ingresada es numerica
* \ param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 ( vardadero ) si la cadena es numerica y 0 ( falso ) si no lo es
*/
static int esNumerica ( char * cadena)
{
	int i=0;
	int retorno = 1;
	fflush (stdin);
	if (cadena != NULL && strlen (cadena) > 0)
	{
		if (cadena[0] == '-')//Aca valido que se puedan aceptar numeros negativos
		{
			i=1;
		}
		while (cadena[i] != '\0' )
		{
			if (cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = 0;
				break ;
			}
			i++;
		}
	}
	return retorno;
}

/*
* \brief Verifica si la cadena ingresada es numerica aceptando numeros decimales
* \ param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 ( vardadero ) si la cadena es numerica y 0 ( falso ) si no lo es
*/
static int esNumericaFloat ( char * cadena)
{
	int i=0;
	int retorno = 0;
	int valida1Coma = 0;
	fflush (stdin);
	if (cadena != NULL && strlen (cadena) > 0)
	{
		if (cadena[0] == '-')//Aca valido que se puedan aceptar numeros negativos
		{
			i=1;
		}

		while (cadena[i] != '\0' )
		{
			if (cadena[i] < '0' || cadena[i] > '9' )
				{
					if (cadena[i] == '.' && valida1Coma < 1) //Aca valido que se puedan aceptar 1 solo '.' para separar decimales de enteros
					{
						valida1Coma = 1;
					}
					else
					{
					retorno = 0;
					break;
					}
				}
			i++;
			retorno = 1;
		}

	}

return retorno;
}

/*
* \brief Verifica si la cadena ingresada es Alfabetica y solo acepta letras, no acepta numeros ni signos
* Acepta Mayusculas y minusculas
* \ param cadena Cadena de caracteres a ser analizada
* \return Retorna 0 ( vardadero ) si la cadena es numerica y -1 ( falso ) si no lo es
*/
static int esAlfabetica ( char * cadena)
{
	int i=0;
	int retorno = -1;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		while (cadena[i] != '\0' )
		{
			if (cadena[i] >= '0' && cadena[i] <= '9' ) // o tmb podria ser !(cadena[i] < '0' || cadena[i] > '9' )
				{
					retorno = -1;
					break;
				}
			i++;
			retorno = 0;
		}
	}
return retorno;
}

/*Toma un entero llamando a myGets y lo valida llamando a esNumerica.
 * lo convierte en un int con atoi y lo guarda en el puntero que vino.
 *param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 *return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt ( int * pResultado)
{
	int retorno=-1;
	char auxiliar[64];
	fflush (stdin);

	if (pResultado != NULL)
	{
		if (myGets(auxiliar, sizeof (auxiliar))==0 && esNumerica(auxiliar))
		{
			*pResultado = atoi (auxiliar);
			retorno = 0;
		}
	}
	return retorno;
}

/*Toma un flotante llamando a myGets y lo valida llamando a esNumericaFloat.
 * lo convierte en un float con atof y lo guarda en el puntero que vino.
 *param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 *return Retorna 0 (EXITO) si se obtiene un numero float y -1 (ERROR) si no
 *
 */
static int getFloat (float * pResultado)
{
	int retorno=-1;
	char auxiliar[64];
	fflush (stdin);

	if (pResultado != NULL)
	{
		if (myGets(auxiliar, sizeof (auxiliar))==0 && (esNumericaFloat(auxiliar))==1)
		{
			*pResultado = atof(auxiliar);
			retorno = 0;
		}
	}
	return retorno;
}






