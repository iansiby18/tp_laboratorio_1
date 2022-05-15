/*
 * ArrayPassenger.h
 *
 *  Created on: 12 may. 2022
 *      Author: iansi
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
int statusFlight;
int isEmpty;
}typedef Passenger;

int initPassengers(Passenger* list, int len);
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);
int findPassengerById(Passenger* list, int len,int id);
int removePassenger(Passenger* list, int len, int id);
int sortPassengers(Passenger* list, int len, int order);
int sortAndPrintFlycode(Passenger* list,int lenght);
int printPassengerArray(Passenger* list, int length);
int newPassenger(Passenger* list, int len, int* idPassenger);
int findEmptyPosition(Passenger* list, int len);
int modifyPassenger(Passenger* list, int len, int* idPassenger);
int deletePassenger(Passenger* list, int len, int* idPassenger);
int calculateAveragePrice(Passenger* arrayPassenger, int len, float* averagePrice);
int sortAndPrint(Passenger* list,int lenght);
int printPassengerAverage(Passenger* arrayPassenger, int len, float averagePrice);
int calculateAverageAndPrint(Passenger* arrayPassenger, int len);
int sortPassengersFlycodeAndStatusflight(Passenger* list, int len, int order);
int cargaForzada(Passenger* list, int len, int* idPassenger);
int printPassengerArrayStatusFlight(Passenger* list, int length);

#endif /* ARRAYPASSENGER_H_ */
