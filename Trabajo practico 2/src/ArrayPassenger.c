/*
 * ArrayPassenger.c
 *
 *  Created on: 12 may. 2022
 *      Author: iansi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Utn.h"

/*
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger * \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int initPassengers(Passenger* list, int len)  {

	int retorno = -1;

		if(list != NULL && len > 0)
		{
			for(int i=0;i<len;i++)
			{
				list[i].isEmpty = 0;
			}
		}

return retorno;
}

/** \brief add in a existing list of passengers the values received as parameters* in the first empty position * \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \param statusFlight int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok

*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight)  {
	int retorno = -1;
	int auxPosition;

	if(list != NULL && len > 0 && id >= 0 && name != NULL && lastName != NULL && price > 0 && typePassenger >= 0 && flycode != NULL && statusFlight > 0)
	{
		auxPosition = findEmptyPosition(list, len);
		if(auxPosition >= 0)
		{
			retorno = 0;
			list[auxPosition].id = auxPosition;
			strncpy(list[auxPosition].name,name,sizeof(list[auxPosition].name));
			strncpy(list[auxPosition].lastName,lastName,sizeof(list[auxPosition].lastName));
			list[auxPosition].price = price;
			list[auxPosition].typePassenger = typePassenger;
			strncpy(list[auxPosition].flycode,flycode,sizeof(list[auxPosition].flycode));
			list[auxPosition].statusFlight = statusFlight;
			list[auxPosition].isEmpty = 1;

		}
	}
	return retorno;
}


/** \brief find a Passenger by Id en returns the index position in array.*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found] *
*/
int findPassengerById(Passenger* list, int len,int id)  {

	int retorno = -1;
	if(list != NULL && len > 0 && id >= 0)
		{
			for(int i=0;i<len;i++)
			{
				if(list[i].id == id)
				{
					retorno = i;
					break;
				}
			}
		}
		return retorno;
	}


/** \brief Remove a Passenger by Id (put isEmpty Flag in 1) *
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id)  {
	int retorno = -1;

	if(list != NULL && len > 0 && id >= 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				list[i].isEmpty = 0;
				break;
			}
		}
	}
	return retorno;
}


/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int sortPassengersNameAndType(Passenger* list, int len, int order)  {
	int retorno = -1;
		int flagSwap;
		int i;
		Passenger bufferPassenger;
		int auxiliarCmp;

		if(list != NULL && len >0 && (order == 1 || order == 0))
		{
			retorno=0;
			switch (order) {
				case 1:
					do
					{
						flagSwap = 0;
						for(i=0;i<sizeof(list);i++)
						{
							auxiliarCmp = strncmp(list[i].lastName,list[i+1].lastName,sizeof(list[i].lastName));
							if(auxiliarCmp > 0 ||
								(auxiliarCmp == 0 && list[i].typePassenger > list[i+1].typePassenger))
							{
								flagSwap = 1;
								bufferPassenger = list[i];
								list[i] = list[i+1];
								list[i+1] = bufferPassenger;
							}
						}

					}while(flagSwap);
					break;
				case 0:
					do
					{
						flagSwap = 0;
						for(i=0;i<sizeof(list);i++)
						{
							auxiliarCmp = strncmp(list[i].lastName,list[i+1].lastName,sizeof(list[i].lastName));
							if(auxiliarCmp < 0 ||
								(auxiliarCmp == 0 && list[i].typePassenger < list[i+1].typePassenger))
							{
								flagSwap = 1;
								bufferPassenger = list[i];
								list[i] = list[i+1];
								list[i+1] = bufferPassenger;
							}
						}

					}while(flagSwap);
					break;
			}
		}
		return retorno;
	}


/** \brief print the content of an passenger
 *
 * \param list passenger*
 * \return (0) if ok or (-1)ERROR
 *
 */

int printPassenger(Passenger* passenger)
{
	int retorno = -1;

	if(passenger!=NULL)
	{
		retorno = 0;
		if(passenger->isEmpty==1)
		printf("ID: %d ||\tNombre: %-15s ||\tApellido: %-15s ||\tPrecio: %-5.2f ||\tCodigo de vuelo: %-15s ||\tTipo de pasajero: %-5d ||\tEstado del vuelo: %-5d \n",passenger->id,passenger->name,passenger->lastName,passenger->price,passenger->flycode, passenger->typePassenger, passenger->statusFlight);
	}

	return retorno;
}
/** \brief print the content of passengers array *
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassengerArray(Passenger* list, int length)  {
	int retorno =-1;

	if(list!=NULL && length>=0){
		for(int i=0; i<length;i++){
			printPassenger(&list[i]);
		}
	}
return retorno;
}


int newPassenger(Passenger* list, int len, int* idPassenger)
{
	int retorno = -1;
	Passenger bufferPassenger;

	if(list != NULL && len > 0 && idPassenger != NULL)
	{
		if (utn_getName(bufferPassenger.name,sizeof(bufferPassenger.name),"Ingrese el nombre:\n","[ERROR]Ingrese nombre valido.\n",3)==0 &&
			utn_getName(bufferPassenger.lastName,sizeof(bufferPassenger.lastName),"Ingrese el apellido:\n","[ERROR]Iangrese apellido valido.\n",3)==0 &&
			utn_getNumeroFloat(&bufferPassenger.price,"Ingrese el Precio:\n","[ERROR]Ingrese un precio valido.\n",0,99999999,3)==0 &&
			utn_getNumero(&bufferPassenger.typePassenger,"Ingrese 1 para clase Ejecutiva, 2 para clase Turista, 3 para clase Premium\n", "[ERROR]Ingrese una clase valida.\n",1,3,3)==0 &&
			utn_getString(bufferPassenger.flycode,sizeof(bufferPassenger.flycode), "Ingrese el codigo de vuelo:\n")==0 &&
			utn_getNumero(&bufferPassenger.statusFlight,"Ingrese 1 para el estado de vuelo Activo o 2 para estado de vuelo Inactivo\n", "[ERROR]Ingrese un estado valido.\n",1,2,3)==0)

		{

			(*idPassenger)++;
			if(addPassenger(list, len, *idPassenger, bufferPassenger.name,bufferPassenger.lastName,bufferPassenger.price,bufferPassenger.typePassenger,bufferPassenger.flycode,bufferPassenger.statusFlight)==0)
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}

/** \brief Find an empty position in the array
 * \param list passenger* Pointer to array of passengers
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (position) if Ok
 *
 */
int findEmptyPosition(Passenger* list, int len)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Modify an passenger
 *
 * \param list passenger*
 * \param len array lenght
 * \param idpassenger pointer to id
 * \return (0) if ok or (-1)ERROR
 *
 */
int modifyPassenger(Passenger* list, int len, int* idPassenger)
{
	int retorno=-1;
	int option;
	int index;
	int id;
		if(list != NULL && len > 0 && idPassenger!= NULL)
		{
			printPassengerArray(list,len);
			utn_getNumero(&id, "Ingrese ID del pasajero a modificar:\n", "[ERROR]ID Invalido.\n", 0,*idPassenger, 3);
			index = findPassengerById(list, len, id);
			if(list[index].isEmpty==1)
			{
				printf("Que desea modificar?\n");
				printf("1)Nombre\n2)Apellido\n3)Precio\n4)Tipo de pasajero\n5)Codigo de vuelo\n");
				utn_getNumero(&option, "Ingrese opcion:\n", "[ERROR]Opcion Invalida.\n", 1, 5, 3);

				switch (option)
				{
					case 1:
						if(utn_getName(list[index].name,sizeof(list[index].name), "Ingrese Nuevo Nombre:\n", "[ERROR]Nombre invalido.\n",3)==0)
						{
							retorno = 0;
						}
						break;
					case 2:
						if(utn_getName(list[index].lastName,sizeof(list[index].lastName), "Ingrese Nuevo Apellido:\n", "[ERROR]Apellido invalido.\n",3)==0)
						{
							retorno = 0;
						}
						break;
					case 3:
						if(utn_getNumeroFloat(&list[index].price,"Ingrese Nuevo Precio:\n","[ERROR]Precio invalido.\n",0,9999999,3)==0)
						{
							retorno = 0;
						}
						break;
					case 4:
						if(utn_getNumero(&list[index].typePassenger,"Ingrese Nuevo Tipo De Pasajero (1 Ejecutiva, 2 Turista, 3 Premium):\n","[ERROR]Sector invalido.\n",1,3,3)==0)
						{
							retorno = 0;
						}
						break;
					case 5:
						if(utn_getCode(list[index].flycode,sizeof(list[index].flycode), "Ingrese Nuevo Codigo de vuelo:\n", "[ERROR]Codigo invalido.\n",3)==0)
						{
							retorno=0;
						}
						break;
				}
			}

		}
	return retorno;
}


/** \brief Delete an passenger
 *
 * \param list passenger*
 * \param len array lenght
 * \param idpassenger pointer to id
 * \return (0) if ok or (-1)ERROR
 *
 */
int deletePassenger(Passenger* list, int len, int* idPassenger)
{
	int retorno = -1;
	int index;

	if(list != NULL && len > 0 && idPassenger != NULL)
	{
		printPassengerArray(list,len);

		if(utn_getNumero(&index, "Ingrese ID del Pasajero a eliminar.\n", "[ERROR]ID Invalido.\n", 0,*idPassenger, 3)==0)
		{

			if(list[index].isEmpty == 1)
			{
				retorno = 0;
				removePassenger(list, len,index);
			}
		}
	}
	return retorno;
}


/** \brief Find the average price
 *
 * \param list passenger*
 * \param len array lenght
 * \param averagePrice Avarega price calculated
 * \return (0) if ok or (-1)ERROR
 *
 */
int calculateAveragePrice(Passenger* arrayPassenger, int len, float* averagePrice)
{
	int retorno = -1;
	int qtyPassenger = 0;
	float acumPrice = 0;

	if(arrayPassenger != NULL && len > 0 && averagePrice != NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(arrayPassenger[i].isEmpty==1)
			{
				qtyPassenger=qtyPassenger+1;
				acumPrice = acumPrice + arrayPassenger[i].price;
			}
		}
		retorno = 0;
		*averagePrice = acumPrice/qtyPassenger;
	}
	return retorno;
}

/** \brief Sort the array by name and type and print
 *
 * \param list Passenger*
 * \param len array lenght
 * \param idPassenger pointer to id
 * \return (0) if ok or (-1)ERROR
 *
 */
int sortAndPrint(Passenger* list,int lenght)
{
	int retorno = -1;
	if(list!=NULL && lenght>=0)
	{
		sortPassengersNameAndType(list, lenght, 1);

		printPassengerArray(list, lenght);
		retorno=0;
	}

	return retorno;
}

/** \brief Sort the array by flycode and statusFlight and print
 *
 * \param list Passenger*
 * \param len array lenght
 * \param idPassenger pointer to id
 * \return (0) if ok or (-1)ERROR
 *
 */
int sortAndPrintFlycode(Passenger* list,int lenght)
{
	int retorno = -1;
	if(list!=NULL && lenght>=0)
	{
		sortPassengersFlycodeAndStatusflight(list, lenght, 1);
		printPassengerArrayStatusFlight(list, lenght);
	}

	return retorno;
}


/** \brief Print passenger with over avarage price
 *
 * \param list passenger*
 * \param len array lenght
 * \param averagePrice Avarega price calculated
 * \return (0) if ok or (-1)ERROR
 *
 */
int printPassengerAverage(Passenger* arrayPassenger, int len, float averagePrice)
{
	int retorno = -1;

	if(arrayPassenger != NULL && len > 0 && averagePrice > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(arrayPassenger[i].isEmpty==1 && arrayPassenger[i].price >= averagePrice)
			{
				retorno = 0;
				printPassenger(&arrayPassenger[i]);
			}
		}
	}
	return retorno;
}

/** \brief Calculate price average and print the passenger that exceed the avarage price
 *
 * \param list passenger*
 * \param len array lenght
 * \return (0) if ok or (-1)ERROR
 *
 */

int calculateAverageAndPrint(Passenger* arrayPassenger, int len)
{
	int retorno = -1;
	float averagePrice;

	if(arrayPassenger != NULL && len > 0)
	{
		if(calculateAveragePrice(arrayPassenger, len, &averagePrice)==0)
		{
			retorno = 0;
			printf("El promedio de los precio es: %.2f y los superan: \n",averagePrice);
			printPassengerAverage(arrayPassenger, len, averagePrice);
		}
	}
	return retorno;
}


/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/


int sortPassengersFlycodeAndStatusflight(Passenger* list, int len, int order)  {
	int retorno = -1;
		int flagSwap;
		int i;
		Passenger bufferPassenger;
		int auxiliarCmp;

		if(list != NULL && len >0 && (order == 1 || order == 0))
		{
			retorno=0;
			switch (order) {
				case 1:
					do
					{
						flagSwap = 0;
						for(i=0;i<sizeof(list);i++)
						{
							auxiliarCmp = strncmp(list[i].flycode,list[i+1].flycode,sizeof(list[i].flycode));
							if(auxiliarCmp > 0 ||
								(auxiliarCmp == 0 && list[i].statusFlight > list[i+1].statusFlight))
							{
								flagSwap = 1;
								bufferPassenger = list[i];
								list[i] = list[i+1];
								list[i+1] = bufferPassenger;
							}
						}

					}while(flagSwap);
					break;
				case 0:
					do
					{
						flagSwap = 0;
						for(i=0;i<sizeof(list);i++)
						{
							auxiliarCmp = strncmp(list[i].flycode,list[i+1].flycode,sizeof(list[i].flycode));
							if(auxiliarCmp < 0 ||
								(auxiliarCmp == 0 && list[i].statusFlight < list[i+1].statusFlight))
							{
								flagSwap = 1;
								bufferPassenger = list[i];
								list[i] = list[i+1];
								list[i+1] = bufferPassenger;
							}
						}

					}while(flagSwap);
					break;
			}
		}
		return retorno;
	}

int cargaForzada(Passenger* list, int len, int* idPassenger)
{
	int retorno = -1;
	Passenger pasajeros[5];


	if(list != NULL && len > 0 && idPassenger != NULL)
	{


			(*idPassenger)++;
						strncpy(pasajeros[0].name,"Pedro",sizeof(pasajeros[0].name));
						strncpy(pasajeros[0].lastName,"Castro",sizeof(pasajeros[0].lastName));
						pasajeros[0].price = 25450;
						strncpy(pasajeros[0].flycode,"HDSZ24",sizeof(pasajeros[0].flycode));
						pasajeros[0].typePassenger = 1;
						pasajeros[0].statusFlight = 1;
						pasajeros[0].isEmpty = 1;
						if(addPassenger(list, len, *idPassenger, pasajeros[0].name,pasajeros[0].lastName,pasajeros[0].price,pasajeros[0].typePassenger,pasajeros[0].flycode,pasajeros[0].statusFlight)==0)
						{
							retorno = 0;
						}

						(*idPassenger)++;
						strncpy(pasajeros[1].name,"Martin",sizeof(pasajeros[1].name));
						strncpy(pasajeros[1].lastName,"Perez",sizeof(pasajeros[1].lastName));
						pasajeros[1].price = 27840;
						strncpy(pasajeros[1].flycode,"HZXWZ4",sizeof(pasajeros[1].flycode));
						pasajeros[1].typePassenger = 3;
						pasajeros[1].statusFlight = 1;
						pasajeros[1].isEmpty = 1;
						if(addPassenger(list, len, *idPassenger, pasajeros[1].name,pasajeros[1].lastName,pasajeros[1].price,pasajeros[1].typePassenger,pasajeros[1].flycode,pasajeros[1].statusFlight)==0)
						{
							retorno = 0;
						}

							(*idPassenger)++;
						strncpy(pasajeros[2].name,"Camila",sizeof(pasajeros[2].name));
						strncpy(pasajeros[2].lastName,"Formoso",sizeof(pasajeros[2].lastName));
						pasajeros[2].price = 65823;
						strncpy(pasajeros[2].flycode,"JK24GD",sizeof(pasajeros[2].flycode));
						pasajeros[2].typePassenger = 2;
						pasajeros[2].statusFlight = 2;
						pasajeros[2].isEmpty = 1;
						if(addPassenger(list, len, *idPassenger, pasajeros[2].name,pasajeros[2].lastName,pasajeros[2].price,pasajeros[2].typePassenger,pasajeros[2].flycode,pasajeros[2].statusFlight)==0)
						{
							retorno = 0;
						}

						(*idPassenger)++;
						strncpy(pasajeros[3].name,"Hernesto",sizeof(pasajeros[3].name));
						strncpy(pasajeros[3].lastName,"Gutierres",sizeof(pasajeros[3].lastName));
						pasajeros[3].price = 46680;
						strncpy(pasajeros[3].flycode,"Z22HJ4",sizeof(pasajeros[3].flycode));
						pasajeros[3].typePassenger = 1;
						pasajeros[3].statusFlight = 2;
						pasajeros[3].isEmpty = 1;
						if(addPassenger(list, len, *idPassenger, pasajeros[3].name,pasajeros[3].lastName,pasajeros[3].price,pasajeros[3].typePassenger,pasajeros[3].flycode,pasajeros[3].statusFlight)==0)
						{
							retorno = 0;
						}

							(*idPassenger)++;
						strncpy(pasajeros[4].name,"Agustina",sizeof(pasajeros[4].name));
						strncpy(pasajeros[4].lastName,"Formoso",sizeof(pasajeros[4].lastName));
						pasajeros[4].price = 85260;
						strncpy(pasajeros[4].flycode,"3TT6HJ",sizeof(pasajeros[4].flycode));
						pasajeros[4].typePassenger = 3;
						pasajeros[4].statusFlight = 1;
						pasajeros[4].isEmpty = 1;
						if(addPassenger(list, len, *idPassenger, pasajeros[4].name,pasajeros[4].lastName,pasajeros[4].price,pasajeros[4].typePassenger,pasajeros[4].flycode,pasajeros[4].statusFlight)==0)
						{
							retorno = 0;
						}


	}

	return retorno;
}


int printPassengerArrayStatusFlight(Passenger* list, int length)  {
	int retorno =-1;

	if(list!=NULL && length>=0){
		for(int i=0; i<length;i++){
			if(list[i].statusFlight == 1)
			{
				printPassenger(&list[i]);
			}
		}
	}
return retorno;
}
