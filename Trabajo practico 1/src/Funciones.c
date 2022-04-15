#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"

float CalcularDescuento(float precio, float descuento){
	float resultado;
float resultadofinal;
	resultado= precio * (descuento/100);
	resultadofinal= precio - resultado;
return resultadofinal;
}

float CalcularPrecioTotal(float precio, float km){
	float resultado;
	resultado= precio*km;
	return resultado;
}

float CalcularInteres(float precio, float interes){
	float resultado;
float resultadofinal;
	resultado= precio * (interes/100);
	resultadofinal= precio + resultado;
return resultadofinal;
}

float CalcularEnBitcoin(float precio,float bitcoin){

	float resultado;
	resultado= precio / bitcoin;
	return resultado;
}

float MostrarDifPrecio(float precio, float precio2){
	float resultado;
	if(precio>precio2){
	resultado= precio - precio2;
	}else{
		resultado= precio2 - precio;
	}
	return resultado;
}
