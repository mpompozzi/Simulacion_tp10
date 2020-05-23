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
void printPort(char puerto);
/*
 * 
 */
int main(void) 
{
    char puerto='a';
    int mask= 0xFF;
    int var= -3;
    
    maskOff(mask, puerto);
    
    printPort(puerto);
    
    while (var != QUIT)
    {
        var= input();
                
        if ((var>=0) && (var<=7))
        {
            bitToggle(var, puerto);
        }
        else if((var=='s')||(var=='S'))
        {
            maskOn(mask,puerto);
        }
        else if ((var=='c')||(var=='C'))
        {
            maskOff(mask,puerto);
        }
        else if ((var=='t')||(var=='T'))
        {
            maskToggle (mask,puerto);
        }
        else if (var == QUIT)
        {
            printf("BAIII\n");
        }
        else
        {
            printf("Estaria bueno aprender a programar\n");
        }
        printPort(puerto);
        
    }
    printf("Termino el programa\n");
    
    return 0;
}

int input (void)   
{
    int c=0;
    int conta=0;
    int letter=0;
    int res=0;
    
    
    while ((c=getchar())!='\n')
    {
        if ((c >= '0') && (c <= '7')) 
	{
            res *=10;
            res = (c-'0');
            conta++;
        }
        else if ( c == 't' || c == 'T' || c == 'c' || c == 'C' || c == 's' || c == 'S'|| c == 'i' || c == 'I')
        {
            letter++;
            conta++;
            res=c;
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
        res=ERROR;
        printf("Lo ingresado no es valido\n");
    }
    if (letter==-10)
    {
        res=QUIT;
    }
    
	
	
	return res;
}	

void printPort (char puerto)
{
    int i=0;
    int bit=0;
    
    printf("|");
    
    for(i=0; i<=7;i++)
    {
        bit= bitGet(i, puerto);
        if(bit==0)
        {
            printf(" ");
        }
        else
        {
            printf("*");
        }
        printf("|");
    }
    
    printf("\n");
}
