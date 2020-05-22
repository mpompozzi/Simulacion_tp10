/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: maga
 *
 * Created on May 22, 2020, 6:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "PortControl.h"
#include "const.h"

/*
 * 
 */
int main(void) 
{
    char puerto='a';
    int mask= 0xFF;
    
    
    
    return 0;
}

int getVar (void)   
{
	int var = getchar();
	int proximo = getchar();
	
	
	if (proximo == '\n') //si lo ingresado es un numero o una letra, seguido de '\n':
	{
	
		if ((var >= '0' && var <= '7') || var == 't' || var == 'T' || var == 'c' || var == 'C' || var == 's' || var == 'S'|| var == 'i' || var == 'I') //si lo que se ingreso es valido(y no es una 'Q'), devuelve lo que se ha ingresado y continua el programa
		{
			next = true;
		}
		else if (var == 'q' || var == 'Q') //si se ingreso una 'Q', cambia el valor de next para que termine el programa
		{
			next = false;
		}
		else //si lo que se ingreso no es valido, devuelve un error y el usuario puede volver a ingresar lo que quiera
		{
			var = -1;
			printf ("Error. Lo que se ha ingresado no es valido. \n");
		}
	}
	else //si luego del primero numero o letra no hay '\n', lo que se ha ingresado no es valido
	{
		var = -1;
		printf ("Error. Lo que se ha ingresado no es valido. \n");
	}
	
	return var;
}	 
