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



	 getInt(&estadia[i].fecha.dia, "Ingrese el dia (1-31):\n","Error, ingrese el dia (1-31):\n", 1, 31);
	getInt(&estadia[i].fecha.mes, "Ingrese el mes (1-12):\n","Error, ingrese el mes (1-12):\n", 1, 12);
	getInt(&estadia[i].fecha.anio, "Ingrese el año (2021 - 2030):\n","Error, ingrese el año (2021 - 2030):\n", 2021, 2030);

}


#endif /* FECHAS_C_ */
