/*
 * Fechas.c
 *
 *  Created on: 26 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef FECHAS_C_
#define FECHAS_C_
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

void pedirFecha(eEstadia estadia[], int i)
{






	  getValidInt(&estadia[i].fecha.dia, "Ingrese el dia: ", "ERROR, ingrese el dia: ", 1, 31);
	  getValidInt(&estadia[i].fecha.mes, "Ingrese el mes: ", "ERROR, ingrese el mes: ", 1, 12);
	  getValidInt(&estadia[i].fecha.anio, "Ingrese el anio: ", "ERROR, ingrese el anio: ", 2021, 2030);







}




#endif /* FECHAS_C_ */
