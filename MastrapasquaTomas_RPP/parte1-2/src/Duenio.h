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
void duenio_harcodear(eDuenio duenio[], int lenDuenio);

int duenio_buscarId(eDuenio duenio[], int lenDuenio,int  id);

void duenio_listarUno(eDuenio duenio);
void duenio_listar(eDuenio duenio[], int lenDuenio);

void duenio_ordenarPorNombre(eDuenio duenio[], int lenDuenio);

int validarDuenioExiste(eDuenio duenio[], int lenDuenio, int idDuenio);

void duenio_modificar(eDuenio duenio[], int lenDuenio, int i);




#endif /* DUENIO_H_ */
