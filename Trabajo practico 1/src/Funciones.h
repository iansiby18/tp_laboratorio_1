/*
 * Funciones.h
 *
 *  Created on: 8 abr. 2022
 *      Author: iansi
 */
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

float CalcularDescuento(float precio, float descuento);
float CalcularPrecioTotal(float precio, float km);
float CalcularInteres(float precio, float interes);
float CalcularEnBitcoin(float precio, float bitcoin);
float MostrarDifPrecio(float precio, float precio2);
#endif /* FUNCIONES_H_ */
