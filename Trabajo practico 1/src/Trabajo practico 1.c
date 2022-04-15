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
	float km = 0;
	float precioLatam = 0;
	float precioAero = 0;
	float precioTotalLatam = 0;
	float precioTotalAero = 0;
	float precioDebLatam = 0;
	float precioDebAero = 0;
	float precioCreLatam = 0;
	float precioCreAero = 0;
	float precioEnBitcoinAero = 0;
	float precioEnBitcoinLatam = 0;
	float difDePrecio;
	int flagCalculos = 0;
	setbuf(stdout, NULL);

	do {

		printf(
				"\n1- Ingresar Kilometros: (KM=%.f)\n"
						"2- Ingresar Precios de Vuelos (Aerolineas=%.f Latam=%.f)\n"
						"3- Calcular todos los costos\n"
						"   a- Tarjeta de débito (descuento 10 Porciento)\n"
						"   b- Tarjeta de crédito (interes 25 Porciento)\n"
						"   c- Bitcoin (1BTC = 4606954,55 Pesos Argentinos)\n"
						"   d- Mostrar precio por km (Precio Unitario)\n"
						"   e- Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n"
						"4- Informar resultados\n"
						"5- Carga forzada\n"
						"6- Salir\n", km, precioAero, precioLatam);

		printf("Ingrese una opcion: ");
		scanf("%d", &menu);

	switch (menu) {
		case 1:
			printf("Ingrese la cantidad de km: \n");
			scanf("%f", &km);
			break;
		case 2:
			printf("Ingresar precio de vuelo para Aerolineas Argentinas: \n");
			scanf("%f", &precioAero);
			printf("Ingresar precio de vuelo para Latam: \n");
			scanf("%f", &precioLatam);
			break;
		case 3:
			if (km > 0 && precioAero > 0 && precioLatam > 0) {
				precioTotalLatam = CalcularPrecioTotal(precioLatam, km);
				precioTotalAero = CalcularPrecioTotal(precioAero, km);
				precioDebLatam = CalcularDescuento(precioTotalLatam, 10);
				precioDebAero = CalcularDescuento(precioTotalAero, 10);
				precioCreLatam = CalcularInteres(precioTotalLatam, 25);
				precioCreAero = CalcularInteres(precioTotalAero, 25);
				precioEnBitcoinAero = CalcularEnBitcoin(precioTotalAero, btc);
				precioEnBitcoinLatam = CalcularEnBitcoin(precioTotalLatam, btc);
				difDePrecio = MostrarDifPrecio(precioTotalLatam,
						precioTotalAero);
				flagCalculos = 1;
				printf("\n Calculos realizados correctamente \n");


			} else {
				printf("\n Para realizar los calculos ingrese todos los datos \n");
			}

			break;
		case 4:
			if (flagCalculos == 1) {
				printf("Latam:\n"
						"\na- Precio con tarjeta de débito: %.2f \n"
						"b- Precio con tarjeta de crédito: %.2f  \n"
						"c- Precio pagando con bitcoin : %f  \n"
						"d- Precio unitario: %.2f \n "
						"\nAerolineas: \n"
						"\na- Precio con tarjeta de débito: %.2f \n "
						"b- Precio con tarjeta de crédito: %.2f \n "
						"c- Precio pagando con bitcoin : %f \n"
						"d- Precio unitario: %.2f  \n"
						"\nLa diferencia de precio es : %.2f \n",
						precioDebLatam, precioCreLatam, precioEnBitcoinLatam,
						precioTotalLatam, precioDebAero, precioCreAero,
						precioEnBitcoinAero, precioTotalAero, difDePrecio);
			} else {
				printf("\nDebes realizar los calculos para mostrar el resultado\n");
			}

			break;

		case 5:
			km = 7090;
			precioLatam = 159339;
			precioAero = 162965;
			precioTotalLatam = CalcularPrecioTotal(precioLatam, km);
			precioTotalAero = CalcularPrecioTotal(precioAero, km);
			precioDebLatam = CalcularDescuento(precioTotalLatam, 10);
			precioDebAero = CalcularDescuento(precioTotalAero, 10);
			precioCreLatam = CalcularInteres(precioTotalLatam, 25);
			precioCreAero = CalcularInteres(precioTotalAero, 25);
			precioEnBitcoinAero = CalcularEnBitcoin(precioTotalAero, btc);
			precioEnBitcoinLatam = CalcularEnBitcoin(precioTotalLatam, btc);
			difDePrecio = MostrarDifPrecio(precioTotalLatam, precioTotalAero);
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
					"\nLa diferencia de precio es : %.2f \n", precioDebLatam,
					precioCreLatam, precioEnBitcoinLatam, precioTotalLatam,
					precioDebAero, precioCreAero, precioEnBitcoinAero,
					precioTotalAero, difDePrecio);
		};
	} while (menu != 5);
	return EXIT_SUCCESS;
}
