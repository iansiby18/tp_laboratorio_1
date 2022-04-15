/*
 ============================================================================
 Name        : Trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(void) {
int menu;
float btc = 4606954.55;
float km=0;
float preciolatam=0;
float precioaero=0;
float preciototallatam=0;
float preciototalaero=0;
float preciodeblatam=0;
float preciodebaero=0;
float preciocrelatam=0;
float preciocreaero=0;
float precioenbitcoinaero=0;
float precioenbitcoinlatam=0;
float difDePrecio;
int flagCalculos=0;
setbuf(stdout,NULL);


do{

printf("\n1- Ingresar Kilometros: (KM=%.f)\n"
	   "2- Ingresar Precios de Vuelos (Aerolineas=%.f Latam=%.f)\n"
	   "3- Calcular todos los costos\n"
	   "   a- Tarjeta de débito (descuento 10 Porciento)\n"
	   "   b- Tarjeta de crédito (interes 25 Porciento)\n"
	   "   c- Bitcoin (1BTC = 4606954,55 Pesos Argentinos)\n"
	   "   d- Mostrar precio por km (Precio Unitario)\n"
	   "   e- Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n"
	   "4- Informar resultados\n"
	   "5- Carga forzada\n"
	   "6- Salir\n",km,precioaero,preciolatam);

printf("Ingrese una opcion: ");
scanf("%d",&menu);

switch(menu){
	case 1:
		printf("Ingrese la cantidad de km: \n");
		scanf("%f",&km);
		break;
	case 2:
		printf("Ingresar precio de vuelo para Aerolineas Argentinas: \n");
		scanf("%f",&precioaero);
		printf("Ingresar precio de vuelo para Latam: \n");
		scanf("%f",&preciolatam);
		break;
	case 3:
		if (km>0 && precioaero > 0 && preciolatam>0){
		preciototallatam= CalcularPrecioTotal(preciolatam,km);
		preciototalaero= CalcularPrecioTotal(precioaero,km);
		preciodeblatam = CalcularDescuento(preciototallatam,10);
		preciodebaero= CalcularDescuento(preciototalaero,10);
		preciocrelatam= CalcularInteres(preciototallatam,25);
		preciocreaero= CalcularInteres(preciototalaero,25);
		precioenbitcoinaero= CalcularEnBitcoin(preciototalaero,btc);
		precioenbitcoinlatam= CalcularEnBitcoin(preciototallatam,btc);
		difDePrecio= MostrarDifPrecio(preciototallatam,preciototalaero);
		flagCalculos=1;
		}else{
			printf("\n Para realizar los calculos ingrese todos los datos \n");
		}

	break;
	case 4:
		if(flagCalculos==1){
		printf("Latam:\n"
			"a- Precio con tarjeta de débito: %.2f \n"
			"b- Precio con tarjeta de crédito: %.2f  \n"
			"c- Precio pagando con bitcoin : %f  \n"
			"d- Precio unitario: %.2f \n "
			"Aerolineas: \n"
			"a- Precio con tarjeta de débito: %.2f \n "
			"b- Precio con tarjeta de crédito: %.2f \n "
			"c- Precio pagando con bitcoin : %f \n"
			"d- Precio unitario: %.2f  \n"
			"\nLa diferencia de precio es : %.2f \n", preciodeblatam, preciocrelatam,precioenbitcoinlatam,preciototallatam,preciodebaero,preciocreaero,precioenbitcoinaero,preciototalaero,difDePrecio);
		}else{
			printf("Debes realizar los calculos para mostrar el resultado");
		}

	break;

	case 5:
		km=7090;
		preciolatam=159339;
		precioaero=162965;
		preciototallatam= CalcularPrecioTotal(preciolatam,km);
				preciototalaero= CalcularPrecioTotal(precioaero,km);
				preciodeblatam = CalcularDescuento(preciototallatam,10);
				preciodebaero= CalcularDescuento(preciototalaero,10);
				preciocrelatam= CalcularInteres(preciototallatam,25);
				preciocreaero= CalcularInteres(preciototalaero,25);
				precioenbitcoinaero= CalcularEnBitcoin(preciototalaero,btc);
				precioenbitcoinlatam= CalcularEnBitcoin(preciototallatam,btc);
				difDePrecio= MostrarDifPrecio(preciototallatam,preciototalaero);
				printf("Latam:\n"
							"a- Precio con tarjeta de débito: %.2f \n"
							"b- Precio con tarjeta de crédito: %.2f  \n"
							"c- Precio pagando con bitcoin : %f  \n"
							"d- Precio unitario: %.2f \n "
							"Aerolineas: \n"
							"a- Precio con tarjeta de débito: %.2f \n "
							"b- Precio con tarjeta de crédito: %.2f \n "
							"c- Precio pagando con bitcoin : %f \n"
							"d- Precio unitario: %.2f  \n"
							"\nLa diferencia de precio es : %.2f \n", preciodeblatam, preciocrelatam,precioenbitcoinlatam,preciototallatam,preciodebaero,preciocreaero,precioenbitcoinaero,preciototalaero,difDePrecio);
};
}while(menu !=5);
return EXIT_SUCCESS;
}
