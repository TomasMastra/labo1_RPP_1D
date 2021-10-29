/*
 * Duenio.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef DUENIO_C_
#define DUENIO_C_


#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "duenio.h"
#include "Nexo.h"


#define D 15
#define EMPTY -1
#define OCCUPED 1


void duenio_inicializar(eDuenio duenio[], int lenDuenio)
{

	int i;

	for(i=0;i<lenDuenio;i++)
	{

		duenio[i].isEmpty = -1;

	}


}

void duenio_harcodear(eDuenio duenio[], int lenDuenio)
{
		int i;
		int ids[] = {30000, 30001, 30002, 30003, 30004};
		char nombres[][21] = {"Martina", "Alan", "Javier", "Tomas", "Lucia"};
		int telefonos[] = {1201001221, 1109785409, 1567983200, 1309786567, 1311784378};
		int isEmpty[] = {1,1,1,1,1};

		for(i=0; i<lenDuenio; i++)
		{
			duenio[i].id = ids[i];
			strcpy(duenio[i].nombre, nombres[i]);
			duenio[i].telefono = telefonos[i];
			duenio[i].isEmpty = isEmpty[i];

		}




}



int duenio_buscarId(eDuenio duenio[], int lenDuenio, int id)
	{

		int i = -1;
		int index = -1;

		lenDuenio = D;


		for(i=0;i<lenDuenio;i++)
			{
				if(duenio[i].id == id)
				{


					index = i;
					break;



				}



		    }

		return index;
	}


void duenio_ordenarPorNombre(eDuenio duenio[], int lenDuenio)
{

	int i;
	int j;
	eDuenio auxDuenio;

	for (i = 0; i < lenDuenio - 1; i++)
		    	{
		    		for (j = i + 1; j < lenDuenio; j++)
		    		{
		    			if(duenio[i].isEmpty != EMPTY && duenio[j].isEmpty !=EMPTY)
		    			{
		    				if (strcmp(duenio[i].nombre, duenio[j].nombre)==1)
		    						  {
		    						    auxDuenio = duenio[i];
		    						    duenio[i] = duenio[j];
		    						    duenio[j] = auxDuenio;
		    						   }

		    			}

		    		}
		    	}



}


void duenio_listarUno(eDuenio duenio)
{

	printf("%-5d %-20s %-20d\n", duenio.id, duenio.nombre, duenio.telefono);


}
void duenio_listar(eDuenio duenio[], int lenDuenio)
{

	int i;


		printf("Listado de duenios:\n\n"
					   "%-5s %-20s %-20s\n", "ID", "Nombre", "telefono");

		for(i=0;i<lenDuenio;i++)
		{
			if(duenio[i].isEmpty  == 1)
			{

			 duenio_listarUno(duenio[i]);
			}


		}



	}

int validarDuenioExiste(eDuenio duenio[], int lenDuenio, int idDuenio)
{
	int ret = -1;

	int i;
		for(i=0;i<lenDuenio;i++)
		{

			if(idDuenio == duenio[i].id)
			{
				ret = 1;
			}
		}


	return ret;
}

void duenio_modificar(eDuenio duenio[], int lenDuenio, int i)
{


	//int index = EMPTY;

	//index =  duenio_buscarId( duenio,  lenDuenio,  idDuenio);


	//i = 0;

	if(i != EMPTY)
	{
		 getValidInt(&duenio[i].telefono, "Ingrese el telefono a modificar", "ERROR, ingrese el telefono a modificar", 1000000000, 1500000000);

		 printf("Se modifico correctamente\n");


	}

}







#endif /* DUENIO_C_ */

