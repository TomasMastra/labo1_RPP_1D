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
#include "Fechas.h"
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

				  pedirFecha(estadia,  index);


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















void validarIdPerro(eEstadia estadia[], ePerro perro[], int len, int index, int id, int lenPerro)
{

	int number;
	int i = 0;
	len = X;



	 perro_listar(perro, lenPerro);




	if(index!=EMPTY)
		{


	  getValidInt(&number, "Ingrese el ID del perro: ", "ERROR, ingrese el ID del perro: ", 7000, 7100);


	for(i=0;i<len;i++)
	{


			while( (validarPerroExiste( perro,  len,  number) == -1))
			{


					//printf("%d\n", perro[i].estadia);
				  getValidInt(&number, "ERROR, Ingrese el ID del perro: ", "ERROR, ingrese el ID del perro: ", 7000, 7100);



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


	  getValidInt(&option, "Ingrese la opcion a modificar (1.duenio 2.perro): ", "ERROR, Ingrese la opcion para modificar (1.duenio 2.perro): ", 1, 2);



		switch(option)
		{

		case 1:

			mostrarEstadiasConPerroDuenio( estadia,  perro,  duenio,  len,  lenPerro,  lenDuenio);



			  getValidInt(&id, "Ingrese el id de la estadia para modificar el telefono :\n","Error, ingrese el id de la estadia para modificar el telefono:\n", 100000, 200000);



			  buscarIDduenio( estadia,  duenio,  len,  lenDuenio,  id);










			break;



		case 2:

			 mostrarEstadiasConPerroDuenio( estadia,  perro,  duenio,  len,  lenPerro,  lenDuenio);



			 getValidInt(&id, "Ingrese el ID de la estadia :\n","Error, ingrese el id de la estadia:\n", 100000, 200000);


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







		if(index >-1)
		{

			 perro_listar(perro, P);




			 getValidInt(&estadia[index].idPerro, "Ingrese el ID del perro :\n","Error, ingrese el id del perro:\n", 7000, 7100);






		}else
		{
			printf("No se encontro el ID :(\n");
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


	 vaciarMasEstadias(perro,  lenPerro);





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
		getValidInt(&number, "Ingrese una ID de duenio: ", "ERROR, ingrese una ID de duenio correcta: ", 30000, 31000);



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

void mostrarUnaEstadiaConDuenioPerro(eEstadia estadia, ePerro perro, eDuenio duenio)
{

	printf("%-10d %-20d %-d/%-d/%-20d %-20s %-20s\n", estadia.id,  estadia.idPerro, estadia.fecha.dia, estadia.fecha.mes, estadia.fecha.anio, perro.nombre, duenio.nombre);


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

						 mostrarUnaEstadiaConDuenioPerro( estadia[i],  perro[j],  duenio[k]);

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

void estadia_ordenarPorFecha(eEstadia estadia[],  int len)
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





void buscarDuenioAlan(eDuenio duenio[], eEstadia estadia[], ePerro perro[], int len, int lenDuenio, int lenPerro)
{


	int i;
	int j;
	int k;

	int index;

	index =  validarIsEmpty(estadia,  len);




	if(index != EMPTY)
	{

		printf("Listado de duenios que se llaman Alan con una estadia reservada\n\n"
								   "%-10s %-20s %-25s %-20s %-20s\n", "ID",  "ID perro", "Fecha", "Perro", "Duenio");
	for(i=0;i<len;i++)
	{

		for(j=0;j<lenDuenio;j++)
		{
			for(k=0;k<lenPerro;k++)
			{
				if(estadia[i].idDuenio == duenio[j].id && estadia[i].idPerro == perro[k].id)
				{
					if(duenio[j].id == 30001)
					{

					 mostrarUnaEstadiaConDuenioPerro( estadia[i],  perro[k],  duenio[j]);


					}
				}

			}
		}


		}

	}


}

void buscarDueniaLucia(eDuenio duenio[], eEstadia estadia[], ePerro perro[],  int len, int lenDuenio, int lenPerro)
{

	int i;
	int j;
	int k;

	int index;

		index =  validarIsEmpty(estadia,  len);

		if(index != -1)
		{

			printf("Listado de duenias que se llaman Lucia con una estadia reservada durante de la segunda quincena de noviembre 2021\n\n"
											   "%-10s %-20s %-25s %-20s %-20s\n", "ID",  "ID perro", "Fecha", "Perro", "Duenio");

	for(i=0;i<len;i++)
		{

			for(j=0;j<lenDuenio;j++)
			{
				for(k=0;k<lenPerro;k++)
				{

					if(estadia[i].fecha.mes == 11 && estadia[i].fecha.anio == 2021 && estadia[i].fecha.dia >15 && estadia[i].fecha.dia<30)
					{


						if(estadia[i].idDuenio == duenio[j].id && estadia[i].idPerro == perro[k].id)
							{
								if(duenio[j].id == 30004)
								{
									mostrarUnaEstadiaConDuenioPerro( estadia[i],  perro[k],  duenio[j]);


								}
							}

						}

					}

				}
			}
		}


}








#endif /* NEXO_C_ */
