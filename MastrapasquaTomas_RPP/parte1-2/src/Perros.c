/*
 * Perros.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef PERROS_C_
#define PERROS_C_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "duenio.h"
#include "Nexo.h"

#define P 10
#define EMPTY -1

void perro_inicializar(ePerro perro[], int lenPerro)
{
	int i;

	for(i=0;i<lenPerro;i++)
	{


		perro[i].isEmpty = EMPTY;


	}

}






void harcodearPerros(ePerro perro[], int lenPerro)
{
	lenPerro =P;
		int i;
		int ids[] = {7000, 7001, 7002};
		char nombres[][21] = {"Lobo", "Shelia", "Reina"};
		char razas[][21] = {"Sharpei", "Golden", "Galgo"};
		int edad[] = {2, 12, 13};
		int isEmpty[] = {1,1,1};
		int estadias[] = {0,0,0};

		for(i=0; i<3; i++)
		{
			perro[i].id = ids[i];
			strcpy(perro[i].nombre, nombres[i]);
			strcpy(perro[i].raza, razas[i]);
			perro[i].edad = edad[i];
			perro[i].isEmpty = isEmpty[i];
			perro[i].cantidadEstadias = estadias[i];

		}




}



void perro_listar(ePerro perro[], int lenPerro)
{

	int i;

	lenPerro = P;

	printf("Listado de perros:\n\n"
				   "%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Raza", "Edad");

	for(i=0;i<lenPerro;i++)
	{
		if(perro[i].isEmpty  != EMPTY)
		{

		 perro_listarUno(perro[i]);
		}


	}



}

void perro_listarUno(ePerro perro)
{

	printf("%-5d %-20s %-20s %-20d\n", perro.id, perro.nombre, perro.raza, perro.edad);

}

int perro_buscarID(ePerro perro[], int len, int id)
	{

		int i = -1;
		int index = -1;


		for(i=0;i<len;i++)
			{
				if(perro[i].id == id)
				{


					index = i;
					break;



				}



		    }

		return index;
	}

void perro_calcularPromedioEdad(ePerro perro[], int lenPerro)
{

	float promedio;
	int i;
	float sumaEdades;

	int cantidadPerros = 0;

	sumaEdades = 0;
	promedio = 0;


	for(i=0;i<lenPerro;i++)
	{
		if(perro[i].isEmpty != EMPTY)
		{

		sumaEdades = sumaEdades + perro[i].edad;
		cantidadPerros++;

		}

	}


	promedio = sumaEdades/cantidadPerros;

	printf("Promedio de edades de los perros: %f\n", promedio);

}

void mostrarMasEstadias(ePerro perro[], int lenPerro, int masEstadias)
{



	int i;




	if(masEstadias > 0)
	{

		printf("Listado de perros con mas estadias:\n\n"

					"%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Raza", "Edad");

		for(i=0;i<lenPerro;i++)
		{




			if(perro[i].cantidadEstadias == masEstadias && perro[i].isEmpty != -1)
			{


				perro_listarUno(perro[i]);




			}
		}

	}else
	{
		printf("Ningun perro tiene estadia\n\n");
	}











}

void perro_buscarMasEstadias(ePerro perro[], int masEstadias, int lenPerro)
{

	int flag = 0;
	int i;

for(i=0;i<lenPerro;i++)
{
	if(flag == 0)
	{

		masEstadias = perro[i].cantidadEstadias;
		flag = 1;
	}else
		if(perro[i].cantidadEstadias > masEstadias)
		{

			masEstadias = perro[i].cantidadEstadias;

		}
}


	mostrarMasEstadias( perro,  lenPerro,  masEstadias);


}

int validarPerroExiste(ePerro perro[], int lenPerro, int idPerro)
{

	int ret=-1;

	int i;
	for(i=0;i<lenPerro;i++)
	{

		if(idPerro == perro[i].id)
		{
			ret = 1;
			perro[i].cantidadEstadias++;
			break;
		}
	}


	return ret;
}





#endif /* PERROS_C_ */
