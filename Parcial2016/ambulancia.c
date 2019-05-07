#ifndef AMBULANCIA_C_INCLUDED
#define AMBULANCIA_C_INCLUDED
#include "ambulancia.h"
#include "llamada.h"
#include "asociado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define REINTENTOS 3

int tres_initStruct(Ambulancia* amb, int limite)
{
    int retorno = -1;
    int i;
    if (amb!=NULL && limite>0)
    {
        for (i=0; i<limite; i++)
        {
            amb[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}

int tres_altaAmbulancia(Ambulancia* amb,Llamada* call,int lugarVacio,int id,int limiteCall,int limiteAmbulancia)
{
    int retorno=-1;
    int posLlamada;
    fflush(stdin);
    posLlamada=dos_getId("Ingrese el id de la llamada para poder asignar una ambulancia.\n",call,limiteCall);
    if (posLlamada!=-1)
    {
        if (getFloat("Ingrese registro de la hora en la que se esta asignando la ambulancia."
            "Ejemplo: 12.30(Minimo 00.00 maximo 23.59)\n",
            "Error, hr no valida.\n",00.00,23.59,REINTENTOS,&call[lugarVacio].tiempo)==0)
        {
            call[posLlamada].estado=0;
            retorno=0;
        }else
            {
                retorno=1;
            }
    }else
        {
            printf ("Error, el id de la llamada ingresado no existe.\n");
        }
    return retorno;
}

int tres_findEmpty (Ambulancia* amb,int limite, int* resultado)
{
    int retorno=-1;
    int i;

    for (i=0;i<limite;i++)
    {
        if (amb[i].isEmpty==1)
        {
            *resultado=i;
            retorno=0;
            break;
        }
        //retorno = 1;
    }
    return retorno;
}
#endif // AMBULANCIA_C_INCLUDED
