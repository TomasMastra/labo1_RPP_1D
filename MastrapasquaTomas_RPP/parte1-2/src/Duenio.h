/*
 * Duenio.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef DUENIO_H_
#define DUENIO_H_

typedef struct
{

	int id;
	char nombre[41];
	int telefono;

	int isEmpty;


}eDuenio;

void duenio_inicializar(eDuenio duenio[], int lenDuenio);
/*
 *
 * Inicializa el array de isEmpty en EMPTY -1
 *
 */
void duenio_harcodear(eDuenio duenio[], int lenDuenio);
/*
 * Harcodea 5 duenios
 */

int duenio_buscarId(eDuenio duenio[], int lenDuenio,int  id);
/*
 * Le paso el id del duenio y ahi busca la posicion del array
 *
 */


void duenio_listarUno(eDuenio duenio);
void duenio_listar(eDuenio duenio[], int lenDuenio);
/*
 *
 * For que llama a la funcion de mostrar un duenio de la posicion de i
 */

void duenio_ordenarPorNombre(eDuenio duenio[], int lenDuenio);
/*
 *
 * Ordena a los duenios por nombre
 */

int validarDuenioExiste(eDuenio duenio[], int lenDuenio, int idDuenio);
/*
 * Valida que el duenio ingresado si exista
 *
 */

void duenio_modificar(eDuenio duenio[], int lenDuenio, int i);
/*
 * Modifica el telefono del duenio, anteriormente se le pide la id de la estadia y busca la id del duenio
 *
 *
 */




#endif /* DUENIO_H_ */
