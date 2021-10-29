/*
 * Nexo.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */


#ifndef NEXO_H_
#define NEXO_H_



void validarIdPerro(eEstadia estadia[], ePerro perro[], int len, int index,int id, int lenPerro);//Valida que el perro exista y no ingrese cualquier numero
void validarIdDuenio(eEstadia estadia[], eDuenio duenio[], int lenDuenio, int index);//Valida que el duenio exista
int voidValidarPerroTieneEstadia(eEstadia estadia[], ePerro perro[], int len);//NO LA USO
int inicializar(eEstadia estadia[], ePerro perro[],eDuenio duenio[],  int len, int flag, int id, int lenDuenio, int idDuenio, int lenPerro);//Inicializa todas las estadias y los perros si el flag es 0, si el flag es 1 solo pide los datos


void modificarEstadia(eEstadia estadia[], ePerro perro[], eDuenio duenio[],  int len,  int lenPerro, int lenDuenio);//Pide la ID para pasarsela a la funcion de buscarID, luego le pasa el index al sub menu
void modificarSubMenu(eEstadia estadia[], ePerro perro[], eDuenio duenio[], int len, int option, int lenPerro, int lenDuenio, int id);//El sub menu de la funcion de modificar con un switch que valida que queres modificar

void modificarIdPerro(eEstadia estadia[], ePerro perro[], int lenPerro, int index, int id);//Modifica el id del perro


int buscarMasEstadias(eEstadia estadia[], ePerro perro[], int lenPerro, int len);//Esta funcion busca el perro con mas estadias
void mostrarMasEstadias(ePerro perro[], int lenPerro, int masEstadias);//Esta funcion muestra el perro con mas estadias, compara si cantidadEstadias es igual a masEstadias y ahi muestra


void Perro_ListarConSusEstadias(eEstadia estadia[], ePerro perro[], int len, int lenPerro);
/*
 * muestra los perros con las ids de las estadias que tiene cada uno
 */

void mostrarEstadiasConPerroDuenio(eEstadia estadia[], ePerro perro[], eDuenio duenio[], int len, int lenPerro, int lenDuenio);
/*
 * llama a la funcion de mostrar uno y le paso cada posicion del array
 *
 */
void mostrarUnaEstadiaConDuenioPerro(eEstadia estadia, ePerro perro, eDuenio duenio);
/*
 *
 *
 */

void estadia_ordenarPorFecha(eEstadia estadia[],  int len);
/*
 * Ordena las estadias por fecha
 *
 */

void buscarIDduenio(eEstadia estadia[], eDuenio duenio[], int len, int lenDuenio, int id);
/*
 * Busca el id del duenio, anteriormente ingreso el id de la estadia y busco que el id duenio de la estadia sea igual al id del duenio
 *
 */


void buscarDuenioAlan(eDuenio duenio[], eEstadia estadia[], ePerro perro[],  int len, int lenDuenio, int lenPerro);
/*
 * Busca un duenio que se llame Alan con una estadia reservada
 */

void buscarDueniaLucia(eDuenio duenio[], eEstadia estadia[], ePerro perro[],  int len, int lenDuenio, int lenPerro);
/*
 * Busca un duenio que se llama Lucia y y cuya fecha de reserva es durante la segunda quincena de noviembre 2021
 */


//void estadia_pedirFecha(eEstadia estadia[], int i);//Esta funcion pide las fechas, dia, mes y año



#endif /* NEXO_H_ */
