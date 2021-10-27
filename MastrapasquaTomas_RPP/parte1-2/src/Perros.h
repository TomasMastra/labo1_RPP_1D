/*
 * Perros.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef PERROS_H_
#define PERROS_H_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define P 10

typedef struct
{

	int id;
	char nombre[21];
	char raza[21];
	int edad;

	int cantidadEstadias;

	int isEmpty;


}ePerro;

void harcodearPerros(ePerro perro[], int lenPerro);//Esta funcion harcodea los perros en la posicion de i
void perro_inicializar(ePerro perro[], int lenPerro);//Inicializa el Isempty en -1



void perro_listar(ePerro perro[], int len);//Esta funcion llama a la funcion de listarUno con un for para que se muestren todos los perros
void perro_listarUno(ePerro perro);//esta funcion muestra un perro, se usa para la funcion de mostar todos



void perro_calcularPromedioEdad(ePerro perro[], int lenPerro);//Esta funcion suma las edades para buscar el promedio de sus edades
int perro_buscarID(ePerro perro[], int lenPerro, int idIngresado);//Busca la posicion de la ID que ingrese el usuario, si ingresa 7000 el index sera 0

void mostrarMasEstadias(ePerro perro[], int lenPerro, int masEstadias);

int validarPerroExiste(ePerro perro[], int lenPerro, int idPerro);//Valida que el perro ingresado exista, si existe devuelve 1

void vaciarMasEstadias(ePerro perro[], int lenPerro);
/*Esta funcion vacia la variable masCantidad de la estructura ePerro para poder volver a calcular cuantas estadias tiene cada perro
 *
 */

void perro_buscarMasEstadias(ePerro perro[], int masEstadias, int lenPerro);
/*
 * busca el perro con mas estadias y se lo pasa a la funcion que lo muestra, esa funcion compara si hay varios perros con la misma cantidad de estadias
 *
 */







#endif /* PERROS_H_ */
