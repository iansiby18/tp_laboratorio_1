/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Ian Sibikousky
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Utn.h"
#define QTY_PASSENGER 1000

int main(void) {
	setbuf(stdout, NULL);
	Passenger arrayPassenger[QTY_PASSENGER];
	int idPassenger = -1;
	int opcion;
	int choice;
	int flagPassenger =0;
	int flagCargaForzada=0;
	initPassengers(arrayPassenger,QTY_PASSENGER);
	do{
		printf("Ingrese una opcion: \n");
		utn_getNumero(&opcion, "1)ALTAS.\n2)MODIFICAR.\n3)BAJA.\n4)INFORMES.\n5)CARGA FORZADA.\n6)SALIR.\n", "[ERROR]Opcion invalida.\n", 1, 6, 3);
		switch(opcion){
		case 1:
				if(newPassenger(arrayPassenger, QTY_PASSENGER, &idPassenger)== 0){
					flagPassenger = flagPassenger + 1 ;
						printf("\nEl Pasajero fue creado con exito! \n");
				}

				break;
		case 2:
			if(flagPassenger > 0){
				if(modifyPassenger(arrayPassenger, QTY_PASSENGER, &idPassenger)==0){
				printf("Pasajero modificado con exito\n");

				}
			}else{
				printf("[ERROR] No hay pasajeros cargados!\n");
			}
			break;
		case 3:

			if(flagPassenger > 0){
				if(deletePassenger(arrayPassenger,QTY_PASSENGER, &idPassenger)==0){
					flagPassenger = flagPassenger-1;
					printf("Pasajero eliminado con exito!\n");

				}
			}else{
				printf("[ERROR] No hay pasajeros cargados!\n");
			}
			break;
		case 4:

			if(utn_getNumero(&choice,  " 1). Listado de los pasajeros ordenados alfabéticamente por Apellido y tipo de pasajero.\n"
								       " 2). Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
									   " 3). Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n"	, "[ERROR]Opcion Invalida.\n", 1, 3, 3)==0)
			{

				switch(choice){
				 case 1:
					 if(sortAndPrint(arrayPassenger, QTY_PASSENGER)==0)

					 break;
				 case 2:
					 if(calculateAverageAndPrint(arrayPassenger,QTY_PASSENGER)==0)

					 break;
				 case 3:
					 if(sortAndPrintFlycode(arrayPassenger, QTY_PASSENGER)==0)
					 break;
				}
			}
			break;
		case 5:
			if(flagCargaForzada==0){
			cargaForzada(arrayPassenger, QTY_PASSENGER, &idPassenger);
			flagPassenger= flagPassenger + 5;
			flagCargaForzada=1;
			printf("Carga Forzada realizada con exito!\n");
			}else{
				printf("Ya realizaste la carga forzada!\n");
			}


		}
	} while(opcion != 6);


	return EXIT_SUCCESS;
}
