/*
 * Funciones.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>

/*
 *
 * Estas funciones se usan para pedir un dato, cada una pide un tipo de dato diferente
 *
 *
 */
int getInt(int* integer, char* message, char* messageError, int min, int max);
int getFloat(float* floating, char* message, char* messageError, float min, float max);
int getString(char* string, char* message, char* messageError, int max);
int getChar(char* character, char* message);

int systemPause(char* message);


int validateLetters(char* string);//Esta funcion valida que solo se ingresen letras, no se pueden ingresar numeros, simbolos.
int PonerMayusculas(char* string);//Esta fucion pone la primer letra en mayuscula y las demas en minuscula


int getValidInt(int* number, char* message, char* errorMessage, int lowLimit, int hiLimit);//llama a getStringNumbers y valida si es menor o mayor al limite
int itsNumber(char* str);//valida que sea un numero
int getStrings(char* message, char* str);//pide el numero
int getStringNumbers(char* message, char* input);//llama al getString y al itsNumber, si se cumplen las condiciones de cada funcion.








#endif /* FUNCIONES_H_ */
