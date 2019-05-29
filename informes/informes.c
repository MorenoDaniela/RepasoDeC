#ifndef INFORMES_C_INCLUDED
#define INFORMES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>//para linux
#include "informes.h"
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"
#include "funciones.h"


int instrumentosQueFueronSolicitadosPorOrquestaDeterminada(Musico* arrayMusicos, Orquesta* arrayOrquesta,Instrumento* arrayInstrumento, int limiteMusico, int limiteOrquesta, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int auxId;
    int posicion;
    int posInstrumento;
    int contador=0;

    if (arrayOrquesta!=NULL && arrayMusicos!= NULL && arrayInstrumento!=NULL && limiteOrquesta>0 && limiteMusico>0 && limiteInstrumento>0)
    {
        orquesta_print(arrayOrquesta,limiteOrquesta);
        getInt("\nIngrese el id de la orquesta para saber que instrumentos solicito: \n","\nError, id no valido.\n",1,limiteOrquesta,3,&auxId);
        if (orquesta_buscarID(arrayOrquesta,limiteOrquesta,auxId,&posicion)==0)
        {
            for (i=0;i<=limiteMusico;i++)
            {
                if (arrayMusicos[i].isEmpty==1)
                continue;

                if (arrayMusicos[i].isEmpty==0)
                {
                    if (arrayMusicos[i].idOrquesta==auxId)
                    {
                        printf ("\nId de instrumento que solicito: %d. \n",arrayMusicos[i].idInstrumento);
                        printf ("Musico que lo toca: %s \n",arrayMusicos[i].nombre);
                        instrumento_buscarID(arrayInstrumento,limiteInstrumento,arrayMusicos[i].idInstrumento,&posInstrumento);
                        printf ("Nombre de instrumento: %s. \n",arrayInstrumento[posInstrumento].nombre);
                        switch (arrayInstrumento[posInstrumento].tipo)
                        {
                            case 1:
                                printf ("Tipo de instrumento: Cuerdas.\n");
                                break;
                            case 2:
                                printf ("Tipo de instrumento: Viento-Madera.\n");
                                break;
                            case 3:
                                printf ("Tipo de instrumento: Viento-Metal.\n");
                                break;
                            case 4:
                                printf ("Tipo de instrumento: Percusion.\n");

                        }
                        printf ("**********************************\n");
                        contador++;
                    }
                }
            }
            printf ("\nLa cantidad de instrumentos que solicito esta orquesta es: %d.\n",contador);
            retorno=0;
        }else
            printf ("\nNo se encontro este id.\n");
    }
    return retorno;
}

int orquestasSegunLugar (Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    char auxLugar[50];

    if (arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        getString("\nIngrese el nombre del lugar para saber si alguna orquesta se encuentra ahi: \n","\nError, lugar no valido.\n",5,50,3,auxLugar);
            for (i=0;i<=limiteOrquesta;i++)
            {
                if (arrayOrquesta[i].isEmpty==1)
                continue;

                if (arrayOrquesta[i].isEmpty==0)
                {
                    if (strcmp(arrayOrquesta[i].lugar,auxLugar)==0)
                    {
                        printf ("\nId de orquesta: %d. \n",arrayOrquesta[i].idOrquesta);
                        printf ("Nombre de orquesta: %s .\n",arrayOrquesta[i].nombre);
                        printf ("Lugar de orquesta: %s \n",arrayOrquesta[i].lugar);
                        switch (arrayOrquesta[i].tipo)
                        {
                        case 1:
                            printf ("Tipo de orquesta : Sinfonica.\n");
                            break;
                        case 2:
                            printf ("Tipo de orquesta: Filarmonica.\n");
                            break;
                        case 3:
                            printf ("Tipo de orquesta: Camara.\n");
                            break;
                        }
                    }
                }
            }
        retorno=0;
    }
    return retorno;
}


int musicosQueNoSuperan25(Musico* arrayMusicos,int limiteMusicos,Instrumento* arrayInstrumento, int limiteInstrumento, Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    //int j;
    //int k;
    int posicionInstrumento;
    int posicionOrquesta;
    int edad=25;
    int musicosQueNoSuperan=0;

    if (arrayMusicos!=NULL && limiteMusicos>0)
    {
        for (i=0;i<=limiteMusicos;i++)
        {
            if (arrayMusicos[i].isEmpty==1)
                continue;
            if (arrayMusicos[i].isEmpty==0)
            {
                if (arrayMusicos[i].edad<edad)
                {
                    printf ("\nNombre del musico: %s \n",arrayMusicos[i].nombre);
                    printf ("Apellido del musico: %s\n",arrayMusicos[i].apellido);
                    printf ("Edad del musico: %d. \n",arrayMusicos[i].edad);
                    printf ("Id musico: %d \n",arrayMusicos[i].idMusico);
                    printf ("Id instrumento %d \n",arrayMusicos[i].idInstrumento);
                    musicosQueNoSuperan++;
                    instrumento_buscarID(arrayInstrumento,limiteInstrumento,arrayMusicos[i].idInstrumento,&posicionInstrumento);
                    orquesta_buscarID(arrayOrquesta,limiteOrquesta,arrayMusicos[i].idOrquesta,&posicionOrquesta);
                    printf ("Nombre del instrumento: %s \n",arrayInstrumento[posicionInstrumento].nombre);
                    printf ("Nombre de orquesta: %s \n",arrayOrquesta[posicionOrquesta].nombre);
                }
            }
        }
        printf ("\nLa cantidad de musicos que no superan la edad 25 es: %d ",musicosQueNoSuperan);
        retorno=0;
    }
    return retorno;
}

int inf_instrumentoPorOrquesta(Musico* arrayMusico, Orquesta* arrayOrquesta, int limiteMusico, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int contadorMusico=0;
    int contadorOrquesta=0;
    float promedio=0;

    if (arrayMusico!=NULL && arrayOrquesta!=NULL && limiteMusico>0 && limiteOrquesta>0)
    {
        for (i=0;i<=limiteMusico;i++)
        {
            if (arrayMusico[i].isEmpty==1)
                continue;
            if (arrayMusico[i].isEmpty==0)
            {
                contadorMusico++;
            }
        }

        for (i=0;i<=limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
                continue;
            if (arrayOrquesta[i].isEmpty==0)
            {
                contadorOrquesta++;
            }
        }
        promedio=contadorMusico/(float)contadorOrquesta;
        printf("\nEl promedio de instrumentos por orquesta es: %.2f",promedio);
        retorno=0;
    }
    return retorno;
}

int inf_musicosNoViento(Musico* arrayMusico,Instrumento* arrayInstrumento, int limiteMusico, int limiteInstrumento)
{
    int i;
    int j;
    int retorno=-1;

    if (arrayMusico!= NULL && arrayInstrumento!= NULL && limiteMusico >0 && limiteInstrumento>0)
    {
        for (i=0;i<limiteMusico;i++)
        {
            if (arrayMusico[i].isEmpty==1)
                continue;
            if (arrayMusico[i].isEmpty==0)
            {
                for (j=0;j<limiteInstrumento;j++)
                {
                    if (arrayInstrumento[j].isEmpty==1)
                        continue;
                    if (arrayInstrumento[j].isEmpty==0)
                    {
                        if (arrayInstrumento[j].idInstrumento==arrayMusico[i].idInstrumento)
                        {
                            if (arrayInstrumento[j].tipo!=2 && arrayInstrumento[j].tipo!=3)
                            {
                                printf ("\nNombre del musico: %s.\n",arrayMusico[i].nombre);
                                printf ("Apellido del musico: %s.\n",arrayMusico[i].apellido);
                                printf ("Edad: %d.\n",arrayMusico[i].edad);
                                printf ("Nombre del instrumento: %s.\n",arrayInstrumento[j].nombre);
                                printf ("Tipo de instrumento: %d.\n",arrayInstrumento[j].tipo);
                                switch (arrayInstrumento[j].tipo)
                                {
                                case 1:
                                    printf ("Tipo de instrumento: cuerdas.\n");
                                    break;
                                case 4:
                                    printf ("Tipo de instrumento: percusion.\n");
                                    break;
                                }
                            }
                        }
                    }
                }
            }

        }
        retorno=0;
    }
    return retorno;
}

int inf_musicosPorApellido (Musico* arrayMusico, int limiteMusico, int orderFirst, int orderSecond)
{
    int retorno=-1;
    int i;
    Musico buffer;
    int flagSwap;

    if(arrayMusico!=NULL && limiteMusico>0)
    {
        do
        {
            flagSwap=0;
            for (i=0; i<limiteMusico-1; i++)
            {
                if (arrayMusico[i].isEmpty==1)
                    continue;
                if (arrayMusico[i].isEmpty==0)
                {
                    if( ((strncmp(arrayMusico[i].apellido,arrayMusico[i+1].apellido,31) < 0) && orderFirst) ||
                        ((strncmp(arrayMusico[i].apellido,arrayMusico[i+1].apellido,31) >0) && !orderFirst) )
                    {

                        buffer = arrayMusico[i];
                        arrayMusico[i] = arrayMusico[i+1];
                        arrayMusico[i+1] = buffer;
                        flagSwap=1;
                    }
                    else if(strncmp(arrayMusico[i].apellido,arrayMusico[i+1].apellido,31) == 0)
                    {
                        if( ((strncmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre,31) <0) && orderSecond) ||
                           ((strncmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre,31) >0) && !orderSecond) )
                        {

                            buffer = arrayMusico[i];
                            arrayMusico[i] = arrayMusico[i+1];
                            arrayMusico[i+1] = buffer;
                            flagSwap=1;
                        }
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

int inf_orquestaCompleta(Musico* arrayMusico, Orquesta* arrayOrquesta, Instrumento* arrayInstrumento,int limiteMusico, int limiteOrquesta, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int posOrquesta;
    int posInstrumento;
    int contadorCuerda=0;
    int contadorViento=0;
    int contadorPercusion=0;

    if (arrayMusico!=NULL && arrayOrquesta!=NULL && arrayInstrumento!=NULL && limiteMusico>0 && limiteOrquesta>0 && limiteInstrumento>0)
    {
        for (i=0;i<limiteMusico;i++)
        {
            if (arrayMusico[i].isEmpty==1)
                continue;
            if (arrayMusico[i].isEmpty==0)
            {
                if (orquesta_buscarID(arrayOrquesta,limiteOrquesta,arrayMusico[i].idOrquesta,&posOrquesta)==0 &&
                    instrumento_buscarID(arrayInstrumento,limiteInstrumento,arrayMusico[i].idInstrumento,&posInstrumento)==0)
                {
                    switch (arrayInstrumento[posInstrumento].tipo)
                    {
                        case 1:
                            contadorCuerda++;
                            break;
                        case 2:
                            contadorViento++;
                            break;
                        case 3:
                            contadorViento++;
                            break;
                        case 4:
                            contadorPercusion++;
                            break;
                    }
                }
            }
        }

        if (contadorCuerda>=4 && contadorViento>=4 && contadorPercusion>=4)
        {
            printf ("\nOrquesta completa id: %d.\n",arrayOrquesta[posOrquesta].idOrquesta);
            printf ("Orquesta completa nombre: %s.\n",arrayOrquesta[posOrquesta].nombre);
            printf ("Orquesta completa lugar: %s.\n",arrayOrquesta[posOrquesta].lugar);
        }else
            printf ("\nNinguna orquesta esta completa.\n");
        retorno=0;
    }
    return retorno;
}

int inf_ordenarMusicosPorIdOrquesta(Musico* arrayMusico, int limite)
{
    int retorno=-1;
    int i;
    int j;
    Musico buffer;

    if (arrayMusico!=NULL && limite>0)
    {
        for (i=0;i<limite;i++)
        {
            for (j=i+1;j<limite;j++)
            {
                if (arrayMusico[i].isEmpty==0)
                {
                    if (arrayMusico[i].idOrquesta > arrayMusico[j].idOrquesta)
                    {
                        buffer=arrayMusico[i];
                        arrayMusico[i]=arrayMusico[j];
                        arrayMusico[j]=buffer;
                    }
                }
            }
        }
        retorno=0;
    }
  return retorno;
}

int inf_orquestasMenosDeSeisMusicos(Musico* arrayMusico,int limiteMusico, Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int i;
    int j;
    int retorno=-1;
    int contador=0;

    if (arrayMusico!=NULL && arrayOrquesta!=NULL && limiteMusico>0 && limiteOrquesta>0)
    {
        for (i=0;i<limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
                continue;
            if (arrayOrquesta[i].isEmpty==0)
            {
                for(j=0;j<limiteMusico;j++)
                {
                    if (arrayMusico[j].isEmpty==1)
                        continue;
                    if (arrayMusico[j].isEmpty==0)
                    {
                        if(arrayOrquesta[i].idOrquesta==arrayMusico[j].idOrquesta)
                        {
                            contador++;
                        }
                    }
                }
                if (contador<6)
                {
                    printf ("\nId de orquesta: %d. \n",arrayOrquesta[i].idOrquesta);
                    printf ("Nombre de orquesta: %s. \n",arrayOrquesta[i].nombre);
                    printf ("Lugar de orquesta: %s.\n",arrayOrquesta[i].lugar);
                    switch (arrayOrquesta[i].tipo)
                    {
                        case 1:
                            printf ("Tipo de orquesta : Sinfonica.\n");
                        break;
                        case 2:
                            printf ("Tipo de orquesta: Filarmonica.\n");
                        break;
                        case 3:
                            printf ("Tipo de orquesta: Camara.\n");
                        break;
                    }
                }
                contador=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

int inf_orquestaConMenosMusicos(Orquesta* arrayOrquesta, int limiteOrquesta, Musico* arrayMusico, int limiteMusico)
{
    int retorno=-1;
    int i;
    int j;
    int contador=0;
    int indiceMaximo=0;
    int indiceMinimo=1000;

    if (arrayMusico!=NULL && arrayOrquesta!=NULL && limiteMusico>0 && limiteOrquesta>0)
    {
        for (i=0;i<limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
                continue;
            if (arrayOrquesta[i].isEmpty==0)
            {
                for (j=0;j<limiteMusico;j++)
                {
                    if (arrayMusico[j].isEmpty==1)
                        continue;
                    if (arrayMusico[j].isEmpty==0)
                    {
                        if (arrayOrquesta[i].idOrquesta==arrayMusico[j].idOrquesta)
                        {
                            contador++;
                        }
                    }
                }

                if (contador>indiceMaximo)
                {
                    indiceMaximo=contador;
                }else if (contador<=indiceMinimo)
                    {
                        indiceMinimo=contador;
                        printf ("\nId de orquesta: %d. \n",arrayOrquesta[i].idOrquesta);
                        printf ("Nombre de orquesta: %s. \n",arrayOrquesta[i].nombre);
                        printf ("Lugar de orquesta: %s.\n",arrayOrquesta[i].lugar);
                        printf ("Cantidad de musicos: %d\n",contador);
                        printf ("indice maximo %d\n",indiceMaximo);
                        printf ("indice minimo %d\n",indiceMinimo);
                        switch (arrayOrquesta[i].tipo)
                        {
                            case 1:
                                printf ("Tipo de orquesta : Sinfonica.\n");
                            break;
                            case 2:
                                printf ("Tipo de orquesta: Filarmonica.\n");
                            break;
                            case 3:
                                printf ("Tipo de orquesta: Camara.\n");
                            break;
                        }
                    }

                contador=0;
            }
        }

        retorno=0;
    }
    return retorno;
}

#endif // INFORMES_C_INCLUDED
