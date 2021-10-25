/*
 * Nexo.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef NEXO_C_
#define NEXO_C_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "duenio.h"
#include "Nexo.h"
#include "Fecha.h"

#include "Nexo.h"

#define EMPTY -1
#define X 15
#define P 10


int inicializar(eEstadia estadia[], ePerro perro[], eDuenio duenio[], int len, int flag, int id, int lenDuenio, int idDuenio, int lenPerro)
{


	int index;











		index = estadia_buscarLibre(estadia, len);

		if(index != -1)
		{






				printf("Cargo correctamente el programa..\n\n");

				flag = 1;


				validarIdPerro(estadia, perro,  lenPerro,  index, id, lenPerro);

				 validarIdDuenio(estadia, duenio, lenDuenio, index);

				//estadia_pedirDatos(estadia,  index,  id);

				 estadia_pedirFecha(estadia,  index);

				  estadia_confirmar(estadia,  index);

					estadia[index].id = id;



				//id++;




		}else
		{


			printf("No hay espacio, elimine una estadia\n");
		}











	return flag;
}

void Perro_ListarConSusEstadias(eEstadia estadia[], ePerro perro[], int len, int lenPerro)
{


	int i;
	int j;

	printf("Perros con sus estadias: \n");
	for(i=0;i<lenPerro;i++)
	{

		if(perro[i].isEmpty != EMPTY)
		{

			printf("------------\n");
			printf("%d -- %s\n", perro[i].id, perro[i].nombre);
					for(j=0;j<len;j++)
					{



						if(estadia[j].isEmpty != -1 && perro[i].id == estadia[j].idPerro)
						{

								printf("%d\n", estadia[j].id);



						}
					}

		}


	}


}





void mostrarEstadiaConDuenio(eEstadia estadia[], eDuenio duenio[], int len, int lenDuenio)
{

	int i;
	int j;



	printf("Listado de estadias\n\n\n"
						   "%-10s %-20s %s %-50s %s\n\n", "ID",  "ID perro", "Fecha", "ID duenio", "Nombre Duenio");

	for(i=0;i<len;i++)
	{

		for(j=0;j<lenDuenio;j++)
		{
			if(estadia[i].isEmpty != -1 && duenio[j].isEmpty != -1)


			{


				if(estadia[i].idDuenio == duenio[j].id)// 100000   30002 JAVIER     J     100001  30001 ANTONELLA A
				{

					{
						printf("%-10d %-20d %d/%d/%d %-50d %s\n", estadia[i].id,  estadia[i].idPerro, estadia[i].fecha.dia, estadia[i].fecha.mes, estadia[i].fecha.anio, estadia[i].idDuenio, duenio[j].nombre);


					}
				}



					//mostrarUnaEstadiaConDuenio(estadia[i], duenio[j]);






			}
		}

	}


}






void validarIdPerro(eEstadia estadia[], ePerro perro[], int len, int index, int id, int lenPerro)
{

	int number;
	int i = 0;
	len = X;



	 perro_listar(perro, P);




	if(index!=EMPTY)
		{
	getInt(&number, "Ingrese una ID de perro: ", "Error, ingrese una ID de perro correcta: ", 7000, 7100);



	for(i=0;i<len;i++)
	{


			while( (validarPerroExiste( perro,  len,  number) == -1))
			{


					//printf("%d\n", perro[i].estadia);
					getInt(&number, "ERROR, Ingrese una ID de perro: ", "Error, ingrese una ID de perro correcta: ", 7000, 7100);



				break;
			}



		}
		}




	estadia[index].idPerro = number;
		//perro[i].estadia = id;





}






void modificarEstadia(eEstadia estadia[], ePerro perro[], eDuenio duenio[], int len, int lenPerro, int lenDuenio)
{

	/*int idIngresado;
	int index = EMPTY;*/
	int option = 0;







			if(validarIsEmpty(estadia, len) == 1)
			  {


						modificarSubMenu(estadia, perro, duenio, len, option, lenPerro, lenDuenio, P);


			}else
			{

				printf("No cargo ninguna estadia\n\n ");
			}


}


void modificarSubMenu(eEstadia estadia[], ePerro perro[], eDuenio duenio[],  int len, int option, int lenPerro, int lenDuenio, int id)
{

	/////////

	int i = 0;


	getInt(&option, "Ingrese la opcion a modificar (1.duenio 2.perro): ", "ERROR, Ingrese la opcion para modificar (1.duenio 2.perro): ", 1, 2);


		switch(option)
		{

		case 1:

			mostrarEstadiasConPerroDuenio( estadia,  perro,  duenio,  len,  lenPerro,  lenDuenio);


			 getInt(&id, "Ingrese el id de la estadia para modificar el telefono :\n","Error, ingrese el id de la estadia para modificar el telefono:\n", 100000, 200000);


			  buscarIDduenio( estadia,  duenio,  len,  lenDuenio,  id);


			 // duenio_modificar( duenio,  lenDuenio,  id);








			break;



		case 2:

			 mostrarEstadiasConPerroDuenio( estadia,  perro,  duenio,  len,  lenPerro,  lenDuenio);


			 getInt(&id, "Ingrese el id de la estadia para modificar el perro asociado:\n","Error, ingrese el id de la estadia para modificar el perro asociado:\n", 100000, 110000);


			modificarIdPerro(estadia,  perro, lenPerro,  i, id);



			break;


		}


}

 void buscarIDduenio(eEstadia estadia[], eDuenio duenio[], int len, int lenDuenio, int id)
{
	int i;
	int j;
	int index;
	int idDuenio;


	for(i=0;i<len;i++)
	{


		if(id == estadia[i].id)
		{
			index = i;



			idDuenio = estadia[index].idDuenio;


			for(j=0;j<lenDuenio;j++)
			{
				if(idDuenio == duenio[j].id)
				{




					duenio_modificar(duenio,  lenDuenio,  j);
					break;


				}
			}

			break;

		}



	}


}




void modificarIdPerro(eEstadia estadia[], ePerro perro[], int lenPerro, int index, int id)
{



	index = estadia_buscarID( estadia,  lenPerro,  id);//Esta funcion busca un ID

	//index =  perro_buscarID(perro, lenPerro, id);



	printf("%d\n", index);




		if(index >-1)
		{




			 validarIdPerro( estadia,  perro,  X, index, id, lenPerro);//Valida que el perro exista y no ingrese cualquier numero




		}


}

int buscarMasEstadias(eEstadia estadia[], ePerro perro[], int lenPerro, int len)
{

	int i;
	int j;
	//int cantidadEstadias[P];
	int masEstadias = 0;
	int flagEstadias = 0;
	//int perroMasEstadias = 0;


	for(i=0;i<lenPerro;i++)
	{
		perro[i].cantidadEstadias = 0;


	}




	masEstadias = 0;
	for(i=0;i<lenPerro;i++)
	{
		for(j=0;j<len;j++)
		{

			if(perro[i].isEmpty != EMPTY && estadia[j].isEmpty != EMPTY)
			{
			if(perro[i].id == estadia[j].idPerro)
			{
				perro[i].cantidadEstadias++;
				printf("%d\n", perro[i].cantidadEstadias);
			}

			}
		}

	}


	if(flagEstadias ==0 )
	{


		flagEstadias = 1;

	}else
	{


	}








	 //mostrarMasEstadias(perro, lenPerro, masEstadias);

	perro_buscarMasEstadias( perro,  masEstadias,  lenPerro);


	return masEstadias;


}



void validarIdDuenio(eEstadia estadia[], eDuenio duenio[], int lenDuenio, int index)
{


	int number;
		int i;
		lenDuenio = 15;



		 //perro_listar(perro, P);



		 duenio_listar(duenio, lenDuenio);


		if(index!=EMPTY)
			{
		getInt(&number, "Ingrese una ID de duenio: ", "ERROR, ingrese una ID de perro correcta: ", 30000, 31000);



		for(i=0;i<lenDuenio;i++)
		{


				while((validarDuenioExiste( duenio,  lenDuenio,  number) == -1))
				{


					getInt(&number, "ERROR, Ingrese una ID de duenio: ", "ERROR, ingrese una ID de perro correcta: ", 30000, 31000);




					break;
				}

		}
			}





		estadia[index].idDuenio = number;


}

void mostrarEstadiasConPerroDuenio(eEstadia estadia[], ePerro perro[], eDuenio duenio[], int len, int lenPerro, int lenDuenio)
{

	int i;
	int j;
	int k;
	int index;

	 index = validarIsEmpty( estadia,  len);

	 printf("\n\n");


if(index != EMPTY)
{
	printf("------------------------------------------------------------------------------------\n");
	printf("Listado de estadias\n\n"
						   "%-10s %-20s %-25s %-20s %-20s\n", "ID",  "ID perro", "Fecha", "Perro", "Duenio");


	for(i=0;i<len;i++)
	{
		for(j=0;j<lenPerro;j++)
		{

			for(k=0;k<lenDuenio;k++)
			{
				if(estadia[i].isEmpty != EMPTY && perro[j].isEmpty != EMPTY && duenio[k].isEmpty != EMPTY)
				{
					if(estadia[i].idPerro == perro[j].id && estadia[i].idDuenio == duenio[k].id)
					{

						printf("%-10d %-20d %-d/%-d/%-20d %-20s %-20s\n", estadia[i].id,  estadia[i].idPerro, estadia[i].fecha.dia, estadia[i].fecha.mes, estadia[i].fecha.anio, perro[j].nombre, duenio[k].nombre);

					}
				}
			}

		}



	}
}else
{
	printf("No hay estadias\n\n");

}




}

void estadia_ordenarPorFecha(eEstadia estadia[], int len)
{


	int i;
		int j;

		eEstadia auxEstadia;

		printf("Funciona...\n");

		for(i=0; i<len-1; i++)
				{
					for(j=i+1; j<len; j++)
					{
						if(estadia[i].isEmpty != EMPTY && estadia[j].isEmpty != EMPTY)
						{
							if(estadia[i].fecha.anio < estadia[j].fecha.anio)//BIEN
							{
								auxEstadia = estadia[i];
								estadia[i] = estadia[j];
								estadia[j] = auxEstadia;
							}else
							{

								if(estadia[i].fecha.anio == estadia[j].fecha.anio)
								{
									if(estadia[i].fecha.mes < estadia[j].fecha.mes)
									{
										auxEstadia = estadia[i];
										estadia[i] = estadia[j];
										estadia[j] = auxEstadia;

									}else
									{

										if(estadia[i].fecha.mes == estadia[j].fecha.mes)
										{

											if(estadia[i].fecha.dia < estadia[j].fecha.dia)
											{

												auxEstadia = estadia[i];
												estadia[i] = estadia[j];
												estadia[j] = auxEstadia;



											}else
											{
												if(estadia[i].fecha.dia == estadia[j].fecha.dia)
												{
													if(estadia[i].idDuenio > estadia[j].idDuenio)
													{

														auxEstadia = estadia[i];
														estadia[i] = estadia[j];
														estadia[j] = auxEstadia;
													}

												}

											}


										}


									}


								}
							}
						}
					}
				}




}








#endif /* NEXO_C_ */
