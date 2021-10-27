/*
 * Funciones.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OCCUPED 1
#define EMPTY -1

#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "duenio.h"
#include "Fechas.h"
#include "Nexo.h"







int validateLetters(char *string)
{

	//int i;
	int ret = -1;
	int len;
	char validateCaps[256];

	len = strlen(string);

	//tolower(string);


	for(int i=0;i<len;i++)
	{

		validateCaps[i] = tolower(string[i]);

		if(validateCaps[i] < 97 || validateCaps[i] > 122)
		{
			ret = 0;

		}

	}





	return ret;

}


int getInt(int* integer, char* message, char* messageError, int min, int max)
{
	int ret = -1;
	int number;

	if(integer != NULL && message != NULL && messageError != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &number);

		while(number < min || number > max)
		{
			printf("%s", messageError);
			fflush(stdin);
			scanf("%d", &number);
		}

		*integer = number;
		ret = 0;
	}

	return ret;
}

int getFloat(float* floating, char* message, char* messageError, float min, float max)
{

	int ret = -1;
	float number;

		if(floating != NULL && message != NULL && messageError != NULL && min < max)
		{
			printf("%s", message);
			fflush(stdin);
			scanf("%f", &number);

			while(number < min || number > max)
			{
				printf("%s", messageError);
				fflush(stdin);
				scanf("%f", &number);
			}

			*floating = number;
			ret = 0;
		}

		return ret;

}

int getString(char* string, char* message, char* messageError, int max)
{
	int ret = -1;
	char buffer[256];
	int len;

	int i;

	if(string != NULL && message != NULL && messageError != NULL && max > 0)
	{
		printf("%s\n\n", message);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		len = strlen(buffer);



		for(i=0;i<len;i++)
		{



			while(len>max || validateLetters(buffer)==0)
			{



						{
							printf("%s\n\n", messageError);
							fflush(stdin);
							scanf("%[^\n]", buffer);
							len = strlen(buffer);

						}

			}
		}

		 PonerMayusculas(buffer);

		strcpy(string, buffer);



		ret = 0;
	}

	while(len>max)
	{

	}

	return ret;
}

int getChar(char* character, char* message)
{
	int ret = -1;

	if(character != NULL && message != NULL)
	{
		printf("%s", message);
		fflush(stdin);
		//__fpurge(stdin);

		*character = getchar();
		ret = 0;
	}

	return ret;
}

int PonerMayusculas(char* string)
{

	int ret = -1;
	int i;
	char buffer[21];

	strcpy(buffer, string);


	for(i=0; buffer[i]!='\0' ; i++)
{

        buffer[i] = tolower(buffer[i]);

}
	buffer[0] = toupper(buffer[0]);

	strcpy(string, buffer);






	return ret;
}

int systemPause(char* message)
{
	int ret=-1;
	if(message!=NULL)
	{
		fflush(stdin);
		printf("\n%s\n\n",message);
		getchar();
		ret=0;
	}
	return ret;
}


//llama a getStringNumbers y valida los limites
int getValidInt(int* number, char* message, char* errorMessage, int lowLimit, int hiLimit)
{
	int rt = 1;
	char auxStrNumber[200];
	int auxNumber;
	int flag;

	if(number != NULL && message != NULL && lowLimit < hiLimit)
	{
		flag = getStringNumbers(message, auxStrNumber);
		auxNumber = atoi(auxStrNumber);



		while(flag != 0 || auxNumber < lowLimit || auxNumber > hiLimit)
		{
			flag = getStringNumbers(errorMessage, auxStrNumber);
			auxNumber = atoi(auxStrNumber);
		}

		*number = auxNumber;

		rt = 0;
	}

	return rt;
}

//verifica que el caracter ingresado sea solo numero
int itsNumber(char* str)
{
	int rt = 0;
	int i;
	int len;

	if(str != NULL)
	{
		len = strlen(str);
		for(i=0; i<len; i++)
		{
			if(str[i]<48 || str[i]>57)
			{
				rt = 1;
				break;
			}
		}
	}

	return rt;
}

//pedir cadena comun
int getStrings(char* message, char* str)
{
	int rt = -1;
	char auxStr[200];

	if(message != NULL && str != NULL)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%[^\n]", auxStr);

		strcpy(str, auxStr);
		rt = 0;
	}

	return rt;
}

//llama al getString y al itsNumber
int getStringNumbers(char* message, char* input)
{
	int rt = -1;
	char auxInput[200];

	if(message != NULL && input != NULL)
	{
		if(getStrings(message, auxInput) == 0 && itsNumber(auxInput) == 0)
		{
			strcpy(input, auxInput);
			rt = 0;
		}
	}

	return rt;
}

