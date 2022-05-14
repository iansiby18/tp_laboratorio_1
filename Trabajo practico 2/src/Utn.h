/*
 * Utn.h
 *
 *  Created on: 12 may. 2022
 *      Author: iansi
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Utn.h"


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int
maximo, int reintentos);
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int
maximo, int reintentos);
int utn_getString(char* pArray,int limite,char* mensaje);
int utn_getName(char* nombre,int limite,char* mensaje,char* mensajeError,int reintentos);
int utn_pedirUnCaracter(char* pCaracter, char* pTexto, char* pTextoError,
char minimo, char maximo, int reintentos);
int utn_myGets(char *buffer, int size);
int isTipo(char* tipo);
int utn_getSexo(char* sexo,char* pMensaje, char* pMensajeError,int reintentos);
int utn_getTipo(char* pTipo, int limite, char* pMensaje, char* pMensajeError,int reintentos);
void utn_hacerMinuscula(char* string, int limite);
int isTamanio(char* tamanio);
int utn_getTamanio(char* pTamanio, int limite, char* pMensaje, char* pMensajeError,int reintentos);
int utn_mayusPrimerLetra(char* string);
int utn_getDNI(char* pDNI, int limite, char* pMensaje, char* pMensajeError,int reintentos);
int isName(char* nombre);
int esNumerica(char* cadena);
int utn_isCuit(char *pCuit);
int utn_getDireccion(char* direccion,int limite,char* mensaje,char* mensajeError, int reintentos);
int utn_getCuit(char* nombre,int limite,char* mensaje,char* mensajeError, int reintentos);
int utn_getCode(char* code,int limite,char* mensaje,char* mensajeError, int reintentos);

#endif /* UTN_H_ */
