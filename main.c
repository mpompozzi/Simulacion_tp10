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

int input (void);

/*
 * 
 */
int main(void) 
{
    char puerto='a';
    int mask= 0xFF;
    int var= -3;
    
    while (var != QUIT)
    {
        var= input();
        if ((var>=0) && (var<=7))
        {
            
        }
        
    }
    
    
    return 0;
}

int input (void)   
{
    int c=0;
    int conta=0;
    int letter=0;
    
    
    while ((c=getchar())!='\n')
    {
        if ((c >= '0') && (c <= '7')) 
	{
            conta++;
        }
        else if ( c == 't' || c == 'T' || c == 'c' || c == 'C' || c == 's' || c == 'S'|| c == 'i' || c == 'I')
        {
            letter++;
            conta++;
        }
        else if ((c=='Q')||(c=='q'))
        {
            letter= -10;
            conta++;
        }
        else
        {
            conta=-10;
        }
    }
    
    if (conta<=0 || conta>1 || ((letter>-10)&&(letter<0)))
    {
        c=ERROR;
        printf("Lon ingresado no es valido\n");
    }
    if (letter==-10)
    {
        c=QUIT;
    }
    
	
	
	return c;
}	 
