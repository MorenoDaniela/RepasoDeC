#ifndef ORQUESTA_C_INCLUDED
#define ORQUESTA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orquesta.h"
//#include <stdio_ext.h>//para linux
#include "funciones.h"
#define TRIES 3

int orquesta_initStruct(Orquesta* arrayOrquesta, int limite)
{
    int retorno = -1;
    int i;
    if (arrayOrquesta!=NULL && limite>0)
    {
        for (i = 0; i <=limite; i++)
        {
            arrayOrquesta[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}

int orquesta_findEmpty (Orquesta* arrayOrquesta,int limite, int* resultado)
{
    int retorno=-1;
    int i;
    if (arrayOrquesta!=NULL && limite>=0 && resultado!=NULL)
    {
        for (i=0;i<=limite;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
            {
                *resultado=i;
                retorno=0;
                break;
            }
            //retorno = 1;
        }
    }
    return retorno;
}

int orquesta_alta(Orquesta* arrayOrquesta,int *id, int limite)
{
    int auxTipo;
    int retorno=-1;
    int lugarVacio;
    //__fpurge(stdin);
    fflush(stdin);
    if (limite>0 && id!=NULL )
    {
        if(orquesta_findEmpty(arrayOrquesta,limite,&lugarVacio)!=-1)
        {
            if (
                getName("\nIngrese nombre de la orquesta: \n","Error, nombre no valido.\n",3,30,TRIES,arrayOrquesta[lugarVacio].nombre)==0 &&
                getString("\nIngrese lugar: \n","Error, lugar no valido.\n",3,30,TRIES,arrayOrquesta[lugarVacio].lugar)==0 &&
                getInt("Ingrese tipo de orquesta: \n1-Sinfonica. \n2-Filarmonica. \n3-Camara\n","Error, tipo de orquesta no valido\n",1,3,TRIES,&auxTipo)==0 )
            {
               arrayOrquesta[lugarVacio].idOrquesta=*id;
                (*id)++;
                arrayOrquesta[lugarVacio].tipo=auxTipo;
               arrayOrquesta[lugarVacio].isEmpty=0;
               printf("\nSe cargaron con exito los datos.\n");
               retorno=0;
            }else
                {
                    printf("\nNo se pudo cargar con exito.\n");
                }
        }else
        {
            printf("No hay espacio vacio.\n");
        }
    }
    return retorno;
}

void orquesta_print(Orquesta* arrayOrquesta, int limite)
{
    int i;
    for (i=0;i<=limite;i++)
    {
        if (arrayOrquesta[i].isEmpty==0)
        {
            printf ("\n********************************************");
            printf ("\nNombre de la orquesta: %s ",arrayOrquesta[i].nombre);
            printf ("\nLugar de la orquesta: %s ",arrayOrquesta[i].lugar);
            printf ("\nTipo de orquesta: %d",arrayOrquesta[i].tipo);
            printf ("\nId de la orquesta: %d ",arrayOrquesta[i].idOrquesta);
            //printf ("\nPosicion: %d ",i);
            //printf ("\nEstado : %d \n",arrayOrquesta[i].isEmpty);
        }
    }
}

int orquesta_findById(char* msj,Orquesta* arrayOrquesta,int* idEncontrado, int limite)
{
    int i;
    int retorno=1;
    int auxOrquesta;
    //revisar limite aca abajo
    if (msj!=NULL && arrayOrquesta !=NULL && idEncontrado!=NULL && limite>0)
    {
        if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxOrquesta)==0)
        {
            for (i=0;i<=limite;i++)
            {
                if (arrayOrquesta[i].isEmpty==0)
                {
                    if (arrayOrquesta[i].idOrquesta == auxOrquesta)
                    {
                        retorno=0;
                        *idEncontrado=i;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}

int orquesta_baja(Orquesta* arrayOrquesta,int limite, int* idBajada)
{
    int posicion;
    int retorno=-1;
    int id;
    if (arrayOrquesta!=NULL && limite>0)
    {
        orquesta_print(arrayOrquesta,limite);
        if (getInt("\nID a cancelar: ","Error.\n",0,limite,TRIES,&id)==0)
        {
           if (orquesta_buscarID(arrayOrquesta,limite,id,&posicion)==0)
            {
                if (arrayOrquesta[posicion].isEmpty==0)
                {
                    *idBajada=id;
                    arrayOrquesta[posicion].isEmpty=1;
                    printf ("\nSe borro el id: %d \n",arrayOrquesta[posicion].idOrquesta);
                    retorno=0;
                }
            }else
                printf ("\nNo se encontro el id.\n");
        }
    }
    return retorno;
}

int orquesta_buscarID(Orquesta* arrayOrquesta, int limite, int valorBuscado, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(arrayOrquesta!= NULL && limite>=0)
    {
        for(i=0;i<=limite;i++)
        {
            if(arrayOrquesta[i].isEmpty==1)
                continue;
            else if(arrayOrquesta[i].idOrquesta==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

void harcodearOrquestas(Orquesta* arrayOrquesta, int limite)
{
    strcpy(arrayOrquesta[0].nombre,"Orquesta1");
    strcpy(arrayOrquesta[0].lugar,"Lugar 1");
    arrayOrquesta[0].isEmpty=0;
    arrayOrquesta[0].idOrquesta=1;
    arrayOrquesta[0].tipo=1;

    strcpy(arrayOrquesta[1].nombre,"Orquesta2");
    strcpy(arrayOrquesta[1].lugar,"Lugar 1");
    arrayOrquesta[1].isEmpty=0;
    arrayOrquesta[1].idOrquesta=2;
    arrayOrquesta[1].tipo=2;

    strcpy(arrayOrquesta[2].nombre,"Orquesta3");
    strcpy(arrayOrquesta[2].lugar,"Lugar 2");
    arrayOrquesta[2].isEmpty=0;
    arrayOrquesta[2].idOrquesta=3;
    arrayOrquesta[2].tipo=3;

    strcpy(arrayOrquesta[3].nombre,"Orquesta4");
    strcpy(arrayOrquesta[3].lugar,"Lugar 3");
    arrayOrquesta[3].isEmpty=0;
    arrayOrquesta[3].idOrquesta=4;
    arrayOrquesta[3].tipo=2;
}


#endif // ORQUESTA_C_INCLUDED
