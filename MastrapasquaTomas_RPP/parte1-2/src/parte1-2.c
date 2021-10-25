/*
 ============================================================================
 Name        : MastrapasquaTomas_PP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "duenio.h"
#include "Nexo.h"




#define X 15
#define P 10
#define D 15

int main(void) {

	setbuf(stdout, NULL);


	 int flag = 0;
	// int flagPerro = 0;
	 int option;
	 int len = X;
	 int lenPerro = P;
	 int lenDuenio = D;

	 eEstadia estadia[X];
	 ePerro perro[P];
	 eDuenio duenio[D];

	 int id = 100000;
	 //int idPerro = 7002;
	 int idDuenio = 30000;




	 perro_inicializar(perro, lenPerro);
	 harcodearPerros(perro, lenPerro);

	 duenio_inicializar(duenio,  lenDuenio);
	 duenio_harcodear(duenio,  lenDuenio);

	estadia_inicializar(estadia, len);

	/*
	 * 1.terminado
	 * 2.terminado
	 * 3.terminado
	 *
	 *
	 */




		 do{
			 getInt(&option, "-----------------------------------------------------------------------------------\n"
		 							 "1. ALTA estadia\n"
		 							 "2. BAJA estadia\n"
		 							 "3. MODIFICACION estadia\n"
		 							 "4. LISTADO ordenado por fecha\n"
		 							 "5. LISTADO perros\n"
		 							 "6. PROMEDIO edad perros\n"
					 	 	 	 	 "7. El perro que tiene mas estadias reservadas\n"
					                 "8. Listado de perros con sus estadias reservadas\n "
		 							 "10.SALIR\n"
		 							 "----------------------------------------------------------------------------------\n",
		 							 "Ingrese una opcion: "
		 							 "-----------------------------------------------------------------------------------\n"
		 							 "1. ALTA estadia\n"
		 							 "2. BAJA estadia\n"
		 							 "3. MODIFICACION estadia\n"
		 							 "4. LISTADO ordenado por fecha\n"
		 							 "5. LISTADO perros\n"
		 							 "6. PROMEDIO edad perros\n"/////////////////////////////// VER Y AGREGAR LAS QUE FALTAN
									 "7. El perro que tiene mas estadias reservadas\n"
									 "8. Listado de perros con sus estadias reservadas\n"
		 							 "10.SALIR\n"
		 							 "-----------------------------------------------------------------------------------\n"
		 							 "Opcion invalida, reingrese: ", 1, 10);

		 		switch(option)
		 		{
		 			case 1:





	 				    systemPause("\nToque cualquier tecla para continuar...");

		 					 flag = inicializar(estadia, perro, duenio,len, flag, id, lenDuenio,idDuenio, lenPerro);


		 					 id++;
		 					 idDuenio++;




		 				break;



		 			case 2:

		 				if(flag ==1)
		 				{


		 				    systemPause("\nToque cualquier tecla para continuar...");

		 				 estadia_cancelar(estadia, len);

		 				}else
		 				{

				 			printf("Ingrese una estadia\n");

		 				}








					break;

		 			case 3:


		 				if(flag == 1)
		 				{

		 				    systemPause("\nToque cualquier tecla para continuar...");

		 					 modificarEstadia(estadia, perro, duenio, len,   lenPerro,  lenDuenio);

		 				}else
		 				{

				 			printf("Ingrese una estadia\n");


		 				}





		 				break;


		 			case 4:

		 					if(flag == 1)
		 					{
		 					//estadia_ordenar(estadia,  lenPerro);


			 				    systemPause("\nToque cualquier tecla para continuar...");

		 					 estadia_ordenarPorFecha(estadia,  len);


		 					 duenio_ordenarPorNombre(duenio, lenDuenio);





		 					 duenio_listar(duenio, lenDuenio);

		 					// estadia_listarTodos(estadia, len);


		 					 mostrarEstadiasConPerroDuenio( estadia,  perro,  duenio,  len,  lenPerro,  lenDuenio);




		 					}else
		 					{

					 			printf("Ingrese una estadia\n");


		 					}



		 				break;


		 		case 5:


 				    systemPause("\nToque cualquier tecla para continuar...");

		 			 perro_listar(perro, lenPerro);













		 			break;


		 		case 6:


 				    systemPause("\nToque cualquier tecla para continuar...");

		 				perro_calcularPromedioEdad(perro, lenPerro);




		 			break;

		 		case 7:

 				    systemPause("\nToque cualquier tecla para continuar...");


		 			 buscarMasEstadias(estadia, perro,  lenPerro, len);


		 			break;

		 		case 8:

 				    systemPause("\nToque cualquier tecla para continuar...");


		 			 Perro_ListarConSusEstadias(estadia, perro,  len, lenPerro);


		 			break;

		 		case 10:

		 			printf("Saliendo...\n\n");

		 			break;




		 		}






		 	}while(option !=10);

	return EXIT_SUCCESS;
}
