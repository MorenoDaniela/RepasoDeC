#ifndef LLAMADA_C_INCLUDED
#define LLAMADA_C_INCLUDED
#include "llamada.h"
#include "asociado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define REINTENTOS 3

int dos_initStruct(Llamada* call, int limite)
{
    int retorno = -1;
    int i;
    if (call!=NULL && limite>0)
    {
        for (i=0; i<limite; i++)
        {
            call[i].estado = 0;
            retorno=0;
        }
    }
    return retorno;
}

int dos_findEmpty (Llamada* call,int limite, int* resultado)
{
    int retorno=-1;
    int i;

    for (i=0;i<limite;i++)
    {
        if (call[i].estado==0)
        {
            *resultado=i;
            retorno=0;
            break;
        }
        //retorno = 1;
    }
    return retorno;
}

int dos_alta(Asociado* socios, Llamada* call,int lugarVacio,int id, int limiteCall, int limiteSocios)
{
    int retorno=-1;
    int posAsociado;
    fflush(stdin);
    posAsociado= uno_getId("Ingrese el id del asociado que hace la llamada.\n",socios,limiteSocios);
    if (posAsociado!=-1)
    {
        if (getFloat("Ingrese registro de la hora. Ejemplo: 12.30 (Minimo 00.00 maximo 23.59)\n","Error, hora no valida.\n",00.00,23.59,REINTENTOS,&call[lugarVacio].tiempo)==0 &&
            getInt("Ingrese el motivo de la llamada: \n0-INFARTO.\n1-ACV.\n2-GRIPE.\n","Error, motivo no valido.\n",0,2,REINTENTOS,&call[lugarVacio].motivo)==0)
        {
            call[posAsociado].idAsociado=posAsociado;
            call[lugarVacio].idAmbulancia=id;
            call[lugarVacio].estado=1;
            retorno=0;
        }else
            {
                retorno=1;
            }
    }else
        {
            printf("Error, el id ingresado no corresponde a un asociado.\n");
        }
    return retorno;
}


int dos_getId(char*msj,Llamada* call,int limite)
{
    int i;
    int retorno=-1;
    Llamada auxCall;

    if (getInt(msj,"\nOpcion no valida.\n",0,limite,REINTENTOS,&auxCall.idLlamada)==0)
    {
        for (i=0;i<limite;i++)
        {
            if (call[i].idLlamada == auxCall.idLlamada)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void dos_print(Llamada* call, int limite)
{
    int i;

    printf ("\n*** Lista de llamadas en curso. ***\n");

    for (i=0;i<limite;i++)
    {
        if (call[i].estado==1)
        {
            printf ("\n********************************************");
            printf ("\nId de la llamada del asociado: %d \n",call[i].idLlamada);
            //printf ("\nApellido del asociado: %s \n",socios[i].apellido);
            //printf ("\nDni del asociado: %s \n",socios[i].dni);
            //printf ("\nEdad del asociado: %d \n",socios[i].edad);
            printf ("\nMotivo de la llamada: %d \n",call[i].motivo);
            //printf ("\nPosicion: %d \n",i);
            printf ("\nEstado : %d \n",call[i].estado);
        }
    }
}
#endif // LLAMADA_C_INCLUDED
