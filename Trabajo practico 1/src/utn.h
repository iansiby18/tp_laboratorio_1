/*
 * utn.h
 *
 *  Created on: 8 abr. 2022
 *      Author: iansi
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int
maximo, int reintentos);
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int
maximo, int reintentos);
int utn_getString(char* pArray,int limite,char* mensaje);
int utn_getName(char* nombre,int limite,char* mensaje,char* mensajeError);
int utn_pedirUnCaracter(char* pCaracter, char* pTexto, char* pTextoError,
char minimo, char maximo, int reintentos);




#endif /* UTN_H_ */
