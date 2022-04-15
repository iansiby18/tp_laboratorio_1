/*
 * utn.c
 *
 *  Created on: 8 abr. 2022
 *      Author: iansi
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);
static int getFloat(float* pResultado);
/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
static int myGets(char* cadena, int longitud)
{
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}
/**
 * \brief Agarra y Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}
/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y -1 (falso) si no lo es
*/
static int esNumerica(char* cadena)
{
	int i=0;
	int retorno = -1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] == '-' || cadena[i] == '.' || cadena[i] > '0' || cadena[i] < '9')
			{
				retorno = 1;
				i++;
			}
			else
			{
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \param reintentos ES la cantidad de reintentos, no puede ser 0 o menor
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int
maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;
	while(reintentos>0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getInt(&bufferInt) == 0)
		{
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Agarra y Verifica si la cadena ingresada es numerica flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero Float al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \param reintentos ES la cantidad de reintentos, no puede ser 0 o menor
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int
maximo, int reintentos)
{
	float bufferInt;
	int retorno = -1;
	while(reintentos>0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferInt) == 0)
		{
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Solicita al usuario un string
 * \param pArray Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param limite El tamaño del Array
 * \param mensaje El mensaje por consola
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getString(char* pArray,int limite,char* mensaje)
{
	int retorno = -1;
	char buffer[800];
	if(pArray != NULL && limite > 0 && mensaje != NULL)
	{
		printf("%s",mensaje);
		if(myGets(buffer,sizeof(buffer))==0)
		{
			strncpy(pArray,buffer,limite);
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Recibe un string y valida que sea un nombre
 * \param char Puntero al string
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
static int isName(char* nombre)
{
	int retorno = -1;
	int i=0;

	if(nombre != NULL)
	{
		while(nombre[i] != '\0')
		{
			if((nombre[i] > 'A' && nombre[i] > 'Z') || (nombre[i] > 'a' && nombre[i] < 'z'))
			{
				retorno = 0;
				i++;
			}
			else
			{
				break;
			}

		}
	}

	return retorno;
}

/**
 * \brief Pide al usuario un string y valida si es un nombre
 * \param char Puntero al string
 * \param limite El tamaño del string
 * \param mensaje Puntero al mensaje que muestra por pantalla
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getName(char* nombre,int limite,char* mensaje,char* mensajeError)
{
	int retorno = -1;
	char bufferChar[limite];

	if(nombre != NULL && limite > 0 && mensaje != NULL)
	{
		printf("%s",mensaje);
		if(myGets(bufferChar,limite)==0 && isName(bufferChar)==0)
		{
			strncpy(nombre,bufferChar,limite);
			retorno = 0;
		}
		else
		{
			printf("%s",mensajeError);
		}
	}
	return retorno;
}

/**
 * \brief Pide al usuario un caracter y valida si esta entre el minimo y maximo ingresado, tiene reintentos;
 * \param char Puntero al string
 * \param limite El tamaño del string
 * \param mensaje Puntero al mensaje que muestra por pantalla
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_pedirUnCaracter(char* pCaracter, char* pTexto, char* pTextoError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;

		if (pCaracter !=NULL && pTexto !=NULL && pTextoError !=NULL && minimo <= maximo && reintentos >=0)
		{
			retorno = -2;

			do
			{
				printf("%s",pTexto);
				fflush(stdin);
				bufferChar = getchar();
				bufferChar = tolower(bufferChar);
				if(bufferChar >= minimo && bufferChar <= maximo)
				{
					retorno = 0;
					*pCaracter = bufferChar;
					break;
				}
				printf("%s",pTextoError);
				reintentos--;
			}while(reintentos >= 0);
		}
		return retorno;
}
