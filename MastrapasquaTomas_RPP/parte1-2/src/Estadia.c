/*
 * Estadia.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef ESTADIA_C_
#define ESTADIA_C_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "duenio.h"
#include "Nexo.h"



#define EMPTY -1
#define X 15

void estadia_inicializar(eEstadia estadia[], int len)
{
	int i;

	for(i=0;i<len;i++)
	{
		estadia[i].isEmpty = EMPTY;


	}


}







int estadia_buscarLibre(eEstadia estadia[], int len)
{
		int i;
		int index = EMPTY;


			for(i=0;i<len;i++)
			{




				if(estadia[i].isEmpty == EMPTY)
				{

					//estadia[i].isEmpty = 1;



					index = i;

					break;

					//list[i].isEmpty = 1;


				}



			}

			return index;
}

void estadia_confirmar(eEstadia estadia[], int i)
{
		char confirm;


		getChar(&confirm, "Ingrese S para cargar la estadia\n\n");

					 if(confirm == 's' || confirm == 'S')
						 {
								estadia[i].isEmpty = 1;

								printf("\n\nSe cargo correctamente\n\n");

						}



}

void confirmarEliminar(eEstadia estadia[], int i)
{
	char confirm;


			getChar(&confirm, "Ingrese S para cargar la estadia");

						 if(confirm == 's' || confirm == 'S')
							 {
									estadia[i].isEmpty = EMPTY;

									printf("Se elimino correctamente\n");

							}

}


void estadia_cancelar(eEstadia estadia[], int len)
{//0

		int idIngresado;
		int index = EMPTY;

		int ret = -1;





		printf("Bucando estadia...\n");

	  if(validarIsEmpty(estadia, len) == 1)
	  {
		   estadia_listarTodos(estadia,  len);//Esta funcion muestra todas las estadias, llama a la de listarUno

		  // printf(" \n  ");

			getInt(&idIngresado, "Ingrese el ID de la estadia para que sea eliminada (100000-200000): ", "ERROR, Ingrese el ID de la estadia para que sea eliminada (100000-200000): ", 100000, 200000);
			index =  estadia_buscarID(estadia, len, idIngresado);


			if(index>-1)
			{


				 confirmarEliminar( estadia,  index);





					ret = 0;

			}else
				if(index == EMPTY)

			{
				printf("No se encontro el ID\n");
			}
	  }else
		  if(ret == -1)
	  {



		  printf("No cargo ninguna estadia\n");

	  }




}

	int estadia_buscarID(eEstadia estadia[], int len, int id)
	{

		int i = -1;
		int index = -1;


		for(i=0;i<len;i++)
			{
				if(estadia[i].id == id)
				{


					index = i;
					break;



				}



		    }

		return index;


	}

	int validarIsEmpty(eEstadia estadia[], int len)
	{
		int ret = -1;

		int i;


		for(i=0;i<len;i++)
			if(estadia[i].isEmpty != EMPTY)
			{


				ret=1;
				break;
			}





		return ret;
	}////////////


	void estadia_listarUno(eEstadia estadia)
	{

		printf("%-10d %-20d %d/%d/%d %-50d\n", estadia.id,  estadia.idPerro, estadia.fecha.dia, estadia.fecha.mes, estadia.fecha.anio, estadia.idDuenio);


	}



	void estadia_listarTodos(eEstadia estadia[], int len)
	{

		int i;


			printf("Listado de estadias\n\n\n"
					   "%-10s %-20s %s %-50s\n\n", "ID",  "ID perro", "Fecha", "ID duenio");



				for(i=0; i<len; i++)
				{
					if(estadia[i].isEmpty != EMPTY)
					{
						estadia_listarUno(estadia[i]);
					}
				}


	}









#endif /* ESTADIA_C_ */
