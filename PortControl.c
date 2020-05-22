/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>



typedef union
{
    uint16_t D;
    struct
    {
        uint8_t B;
        uint8_t A;
    };
    
    
}puerto_t;

static puerto_t port;


void bitSet (int bit,char puerto)
{
    if (((puerto== 'd')||(puerto=='D')) && (bit>=0) && (bit<=15))
    {
        uint16_t mask= 0x0001; 
        mask <<= bit;
        port.D |= mask;
    }
    else if ((bit>=0) && (bit<=7) && ((puerto=='b')||(puerto=='B')))
    {
        uint8_t mask= 0x01;
        mask<<= bit;
        port.B |= mask;
        
    }
    else if((bit>=0) && (bit<=7) && ((puerto=='a')||(puerto=='A')))
    {
        uint8_t mask= 0x01;
        mask<<= bit;
        port.A |= mask;
    }
    else
    {
        printf("Datos mal ingresados\n");
    }
}

void bitClr (int bit, char puerto)
{
    if (((puerto== 'd')||(puerto=='D')) && (bit>=0) && (bit<=15))
    {
        uint16_t mask= 0x0001; 
        mask <<= bit;
        port.D &= ~mask;
    }
    else if ((bit>=0) && (bit<=7) && ((puerto=='b')||(puerto=='B')))
    {
        uint8_t mask= 0x01;
        mask<<= bit;
        port.B &= ~mask;
        
    }
    else if((bit>=0) && (bit<=7) && ((puerto=='a')||(puerto=='A')))
    {
        uint8_t mask= 0x01;
        mask<<= bit;
        port.A &= ~mask;
    }
    else
    {
        printf("Datos mal ingresados\n");
    }
}

int bitGet (int bit, char puerto)
{
    int estado=-1;
    
    if (((puerto== 'd')||(puerto=='D')) && (bit>=0) && (bit<=15))
    {
        uint16_t mask= 0x0001; 
        mask <<= bit;
        if ((port.D) &= mask)
        {
            estado=1;
        }
        else 
        {
            estado=0;
        }
    }
    else if ((bit>=0) && (bit<=7) && ((puerto=='b')||(puerto=='B')))
    {
        uint8_t mask= 0x01;
        mask<<= bit;
        if((port.B) &= mask)
        {
            estado=1;
        }
        else
        {
            estado=0;
        }
        
    }
    else if((bit>=0) && (bit<=7) && ((puerto=='a')||(puerto=='A')))
    {
        uint8_t mask= 0x01;
        mask<<= bit;
        if(port.A &= mask)
        {
            estado=1;
        }
        else
        {
            estado=0;
        }  
    }
    else
    {
        printf("Datos mal ingresados\n");
    }
    return estado;
}

void bitToggle (int bit, char puerto)
{
    if (((puerto== 'd')||(puerto=='D')) && (bit>=0) && (bit<=15))
    {
        uint16_t mask= 0x0001; 
        mask <<= bit;
        port.D ^= mask;
    }
    else if ((bit>=0) && (bit<=7) && ((puerto=='b')||(puerto=='B')))
    {
        uint8_t mask= 0x01;
        mask<<= bit;
        port.B ^= mask;
        
    }
    else if((bit>=0) && (bit<=7) && ((puerto=='a')||(puerto=='A')))
    {
        uint8_t mask= 0x01;
        mask<<= bit;
        port.A ^= mask;
    }
    else
    {
        printf("Datos mal ingresados\n");
    }
}
void maskOn (int mask, char puerto)
{
    if((puerto=='d')||(puerto == 'D'))
    {
        port.D |= (uint16_t)mask; 
    }
    else if((puerto=='a')||(puerto=='A'))
    {
        port.A |= (uint8_t) mask;
    }
    else if ((puerto=='b')||(puerto=='B'))
    {
        port.B |= (uint8_t) mask;
    }
    else 
    {
        printf("Datos mal ingresados\n");
    } 
}
void maskOff (int mask, char puerto)
{
    if((puerto=='d')||(puerto == 'D'))
    {
        port.D &=(uint16_t) mask; 
    }
    else if((puerto=='a')||(puerto=='A'))
    {
        port.A &=(uint8_t) mask;
    }
    else if ((puerto=='b')||(puerto=='B'))
    {
        port.B &= (uint8_t) mask;
    }
    else 
    {
        printf("Datos mal ingresados\n");
    } 
}
void maskToggle (int mask, char puerto)
{
    if((puerto=='d')||(puerto == 'D'))
    {
        port.D ^= (uint16_t)mask; 
    }
    else if((puerto=='a')||(puerto=='A'))
    {
        port.A ^=(uint8_t) mask;
    }
    else if ((puerto=='b')||(puerto=='B'))
    {
        port.B ^=(uint8_t) mask;
    }
    else 
    {
        printf("Datos mal ingresados\n");
    } 
}