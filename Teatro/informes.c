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

int cantidad_tipos_orquesta (Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int contadorSinfonica=0;
    int contadorFilarmonica=0;
    int contadorCamara=0;

    if (arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        for (i=0;i<=limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==0)
            {
                switch (arrayOrquesta[i].tipo)
                {
                case 1:
                    contadorSinfonica++;
                    break;
                case 2:
                    contadorFilarmonica++;
                    break;
                case 3:
                    contadorCamara++;
                    break;
                }
            }
        }
        printf ("\nCantidad de orquestas sinfonicas: %d",contadorSinfonica);
        printf ("\nCantidad de orquestas filarmonicas: %d",contadorFilarmonica);
        printf ("\nCantidad de orquestas camara: %d",contadorCamara);
        retorno=0;
    }
    return retorno;
}

int cantidad_tipos_orquesta_y_nombres (Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int contadorSinfonica=0;
    int contadorFilarmonica=0;
    int contadorCamara=0;

    if (arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        for (i=0;i<=limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==0)
            {
                switch (arrayOrquesta[i].tipo)
                {
                case 1:
                    contadorSinfonica++;
                    printf ("\nSINFONICA : Nombre de orquesta: %s",arrayOrquesta[i].nombre);
                    break;
                case 2:
                    contadorFilarmonica++;
                    printf ("\nFILARMONICA : Nombre de orquesta: %s",arrayOrquesta[i].nombre);
                    break;
                case 3:
                    printf ("\nCAMARA : Nombre de orquesta: %s",arrayOrquesta[i].nombre);
                    contadorCamara++;
                    break;
                }
            }
        }
        printf ("\nCantidad de orquestas sinfonicas: %d",contadorSinfonica);
        printf ("\nCantidad de orquestas filarmonicas: %d",contadorFilarmonica);
        printf ("\nCantidad de orquestas camara: %d",contadorCamara);
        retorno=0;
    }
    return retorno;
}

int cantidad_tipos_instrumento (Instrumento* arrayInstrumento, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int contadorCuerdas=0;
    int contadorVientoMadera=0;
    int contadorVientoMetal=0;
    int contadorPercusion=0;

    if (arrayInstrumento!=NULL && limiteInstrumento>0)
    {
        for (i=0;i<=limiteInstrumento;i++)
        {
            if (arrayInstrumento[i].isEmpty==0)
            {
                switch (arrayInstrumento[i].tipo)
                {
                case 1:
                    contadorCuerdas++;
                    break;
                case 2:
                    contadorVientoMadera++;
                    break;
                case 3:
                    contadorVientoMetal++;
                    break;
                case 4:
                    contadorPercusion++;
                    break;
                }
            }
        }
        printf ("\nCantidad de instrumentos de cuerdas: %d",contadorCuerdas);
        printf ("\nCantidad de instrumentos de viento-madera: %d",contadorVientoMadera);
        printf ("\nCantidad de instrumentos de viento-metal: %d",contadorVientoMetal);
        printf ("\nCantidad de instrumentos de percusion: %d",contadorPercusion);
        retorno=0;
    }
    return retorno;
}

int cantidad_tipos_instrumento_y_nombres (Instrumento* arrayInstrumento, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int contadorCuerdas=0;
    int contadorVientoMadera=0;
    int contadorVientoMetal=0;
    int contadorPercusion=0;

    if (arrayInstrumento!=NULL && limiteInstrumento>0)
    {
        for (i=0;i<=limiteInstrumento;i++)
        {
            if (arrayInstrumento[i].isEmpty==0)
            {
                switch (arrayInstrumento[i].tipo)
                {
                case 1:
                    contadorCuerdas++;
                    printf ("\nCUERDA- Nombre de instrumento: %s",arrayInstrumento[i].nombre);
                    break;
                case 2:
                    contadorVientoMadera++;
                    printf ("\nVIENTO-MADERA- Nombre de instrumento: %s",arrayInstrumento[i].nombre);
                    break;
                case 3:
                    contadorVientoMetal++;
                    printf ("\nVIENTO-METAL- Nombre de instrumento: %s",arrayInstrumento[i].nombre);
                    break;
                case 4:
                    contadorPercusion++;
                    printf ("\nPERCUSION- Nombre de instrumento: %s",arrayInstrumento[i].nombre);
                    break;
                }
            }
        }
        printf ("\nCantidad de instrumentos de cuerdas: %d",contadorCuerdas);
        printf ("\nCantidad de instrumentos de viento-madera: %d",contadorVientoMadera);
        printf ("\nCantidad de instrumentos de viento-metal: %d",contadorVientoMetal);
        printf ("\nCantidad de instrumentos de percusion: %d",contadorPercusion);
        retorno=0;
    }
    return retorno;
}

int cantidadOrquestas(Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int contadorOrquesta=0;
    if (arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        for (i=0;i<=limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
                continue;
            if (arrayOrquesta[i].isEmpty==0)
            {
                contadorOrquesta++;
            }
        }
        printf ("\nLa cantidad de orquestas en total es: %d \n",contadorOrquesta);
        retorno=0;
    }
    return retorno;
}

int cantidadInstrumentos(Instrumento* arrayInstrumento, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int contadorInstrumento=0;
    if (arrayInstrumento!=NULL && limiteInstrumento>0)
    {
        for (i=0;i<=limiteInstrumento;i++)
        {
            if (arrayInstrumento[i].isEmpty==1)
                continue;
            if (arrayInstrumento[i].isEmpty==0)
            {
                contadorInstrumento++;
            }
        }
        printf ("\nLa cantidad de instrumentos en total es: %d \n",contadorInstrumento);
        retorno=0;
    }
    return retorno;
}

int cantidadMusicos(Musico* arrayMusico, int limiteMusico)
{
    int retorno=-1;
    int i;
    int contadorMusico=0;
    if (arrayMusico!=NULL && limiteMusico>0)
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
        printf ("\nLa cantidad de musicos en total es: %d \n",contadorMusico);
        retorno=0;
    }
    return retorno;
}

int promedio_edad_musicos(Musico* arrayMusicos,int limiteMusicos)
{
    int retorno=-1;
    int i;
    float contador=0;
    float acumulador=0;
    float promedio=0;

    if (arrayMusicos!=NULL && limiteMusicos>0)
    {
        for (i=0;i<=limiteMusicos;i++)
        {
            if (arrayMusicos[i].isEmpty==1)
                continue;
            if (arrayMusicos[i].isEmpty==0)
            {
                acumulador=arrayMusicos[i].edad+acumulador;
                contador++;
            }
        }
        promedio=acumulador/contador;
        printf ("\nEl promedio de la edad de los musicos en todas las orquestas es: %2.f",promedio);
        retorno=0;
    }
    return retorno;
}

int musicosQueSuperanEdadPromedio(Musico* arrayMusicos,int limiteMusicos)
{
    int retorno=-1;
    int i;
    float contador=0;
    float acumulador=0;
    float promedio=0;
    float musicosQueSuperan=0;

    if (arrayMusicos!=NULL && limiteMusicos>0)
    {
        for (i=0;i<=limiteMusicos;i++)
        {
            if (arrayMusicos[i].isEmpty==1)
                continue;
            if (arrayMusicos[i].isEmpty==0)
            {
                acumulador=arrayMusicos[i].edad+acumulador;
                contador++;
            }
        }
        promedio=acumulador/contador;

        for (i=0;i<=limiteMusicos;i++)
        {
            if (arrayMusicos[i].isEmpty==1)
                continue;
            if (arrayMusicos[i].isEmpty==0)
            {
                if (arrayMusicos[i].edad>promedio)
                {
                    printf ("%s \n",arrayMusicos[i].nombre);
                    musicosQueSuperan++;
                }
            }
        }

        printf ("\nLa cantidad de musicos que superan la edad promedio es: %2.f",musicosQueSuperan);
        printf ("\nEl promedio de la edad de los musicos en todas las orquestas es: %2.f",promedio);
        retorno=0;
    }
    return retorno;
}

int promedio_cantidad_musicos_por_orquesta(Musico* arrayMusico, Orquesta* arrayOrquesta, int limiteMusico, int limiteOrquesta)
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
        promedio=contadorMusico/contadorOrquesta;
        printf("\nEl promedio de musicos por orquesta es: %2.f",promedio);
        retorno=0;
    }
    return retorno;
}

int musicos_segun_instrumento (Musico* arrayMusicos, Instrumento* arrayInstrumento, int limiteMusico, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int auxId;
    int posicion;

    if (arrayInstrumento!=NULL && arrayMusicos!= NULL && limiteInstrumento>0 && limiteMusico>0)
    {
        instrumento_print(arrayInstrumento,limiteInstrumento);
        getInt("\nIngrese el id del instrumento para saber que musicos lo utilizan: \n","\nError, id no valido.\n",1,limiteInstrumento,3,&auxId);
        if (instrumento_buscarID(arrayInstrumento,limiteInstrumento,auxId,&posicion)==0)
        {
            for (i=0;i<=limiteMusico;i++)
            {
                if (arrayMusicos[i].isEmpty==1)
                continue;

                if (arrayMusicos[i].isEmpty==0)
                {
                    if (arrayMusicos[i].idInstrumento==auxId)
                    {
                        printf ("\nNombre: %s. Id de musico: %d. ",arrayMusicos[i].nombre,arrayMusicos[i].idMusico);
                    }
                }
            }
            retorno=0;
        }else
            printf ("\nNo se encontro este id.\n");
    }
    return retorno;
}

int musicos_segun_orquesta (Musico* arrayMusicos, Orquesta* arrayOrquesta, int limiteMusico, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int auxId;
    int posicion;

    if (arrayOrquesta!=NULL && arrayMusicos!= NULL && limiteOrquesta>0 && limiteMusico>0)
    {
        orquesta_print(arrayOrquesta,limiteOrquesta);
        getInt("\nIngrese el id de la orquesta para saber que musicos estan en ella: \n","\nError, id no valido.\n",1,limiteOrquesta,3,&auxId);
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
                        printf ("\nNombre: %s. ",arrayMusicos[i].nombre);
                    }
                }
            }
            retorno=0;
        }else
            printf ("\nNo se encontro este id.\n");
    }
    return retorno;
}

int musicos_ordenarDobleCriterio (Musico* arrayMusico, int limite, int orderFirst, int orderSecond)                              //cambiar fantasma
{
    int retorno=-1;
    int i;
    Musico buffer;
    int flagSwap;

    if(arrayMusico!=NULL && limite>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 0; i<limite-1; i++)
            {
                if (arrayMusico[i].isEmpty==1)
                    continue;
                if (arrayMusico[i].isEmpty==0)
                {
                    if( ((strcmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre) < 0) && orderFirst) ||
                        ((strcmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre)>0) && !orderFirst) )
                    {

                        buffer = arrayMusico[i];
                        arrayMusico[i] = arrayMusico[i+1];
                        arrayMusico[i+1] = buffer;
                        flagSwap=1;
                    }
                    else if(strcmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre) == 0)
                    {
                        if( ((arrayMusico[i].edad < arrayMusico[i+1].edad) && orderSecond) ||
                           ((arrayMusico[i].edad > arrayMusico[i+1].edad) && !orderSecond) )
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

//listar todas las orquestas que solicitaron un instrumento determinado
int orquestasQueSolicitaronInstrumento (Musico* arrayMusicos, Instrumento* arrayInstrumento, int limiteMusico, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int auxId;
    int posicion;

    if (arrayInstrumento!=NULL && arrayMusicos!= NULL && limiteInstrumento>0 && limiteMusico>0)
    {
        instrumento_print(arrayInstrumento,limiteInstrumento);
        getInt("\nIngrese el id del instrumento para saber que orquestas lo solicitaron: \n","\nError, id no valido.\n",1,limiteInstrumento,3,&auxId);
        if (instrumento_buscarID(arrayInstrumento,limiteInstrumento,auxId,&posicion)==0)
        {
            for (i=0;i<=limiteMusico;i++)
            {
                if (arrayMusicos[i].isEmpty==1)
                continue;

                if (arrayMusicos[i].isEmpty==0)
                {
                    if (arrayMusicos[i].idInstrumento==auxId)
                    {
                        printf ("\nId de orquesta que solicito el instrumento: %d. \n",arrayMusicos[i].idOrquesta);
                    }
                }
            }
            retorno=0;
        }else
            printf ("\nNo se encontro este id.\n");
    }
    return retorno;
}

int instrumentosQueFueronSolicitadosPorOrquestaDeterminada(Musico* arrayMusicos, Orquesta* arrayOrquesta,Instrumento* arrayInstrumento, int limiteMusico, int limiteOrquesta, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int auxId;
    int posicion;
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
                        printf ("Id de instrumento que solito: %d. \n",arrayMusicos[i].idInstrumento);
                        contador++;
                    }
                }
            }
            printf ("\nLa cantidad de instrumentos que solicito esta orquesta es: %d",contador);
            retorno=0;
        }else
            printf ("\nNo se encontro este id.\n");
    }
    return retorno;
}

int informes_ordenarInstrumentos(InstrumentoAuxiliar array[],int size)                              //cambiar musico
{
    int retorno=-1;
    int i;
    InstrumentoAuxiliar buffer;
    int flagSwap;
    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for(i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0)))
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

int informes_initInstrmentoAuxiliar(InstrumentoAuxiliar arrayAux[], int sizeArray)
{
    int retorno=-1;
    int i;
    for(i=0;i<sizeArray;i++)
    {
        arrayAux[i].isEmpty = 1;
        strcpy(arrayAux[i].nombre, " ");
    }
    retorno =0;
    return retorno;
}

int informes_instrumentoMasUsado(Musico* arrayMusicos, InstrumentoAuxiliar arrayAux[], Instrumento* arrayInstrumento, int sizeArray)
{
    int retorno=-1;
    int i,j;
    int posicionAuxiliar = 0;
    if(arrayMusicos!= NULL && sizeArray>=0 && arrayAux != NULL && arrayInstrumento != NULL)
    {
        informes_initInstrmentoAuxiliar(arrayAux, sizeArray);
        for(i=0;i<sizeArray;i++)
        {
            if(arrayMusicos[i].isEmpty==1)
                continue;
            else
            {
                arrayAux[posicionAuxiliar].idInstrumento = arrayMusicos[i].idInstrumento;
                arrayAux[posicionAuxiliar].isEmpty = 0;
                for(j=0;j<20;j++)
                {
                    if(arrayAux[posicionAuxiliar].idInstrumento == arrayInstrumento[j].idInstrumento)
                    {
                        strcpy (arrayAux[posicionAuxiliar].nombre, arrayInstrumento[j].nombre);
                        arrayAux[posicionAuxiliar].tipo = arrayInstrumento[j].tipo;
                        break;
                    }
                }
                posicionAuxiliar++;
            }
        }
        retorno =0;
    }
    informes_ordenarInstrumentos(arrayAux, sizeArray);
    int contadorSeguidos = 0;
    int contadorAuxiliar = 0;
    char nombreRepetido[20];
    char nombreSeguido[20];
    int tipoSeguido;
    for(i=0;i<sizeArray;i++)
    {
        if(i==0)
        {
            strncpy(nombreRepetido, arrayAux[i].nombre, 20);
            contadorAuxiliar = 1;
            continue;
        }
        if(!strncmp(nombreRepetido, arrayAux[i].nombre, 20))
        {
            contadorAuxiliar++;
        }else{
            if(contadorAuxiliar>contadorSeguidos)
            {
                contadorSeguidos = contadorAuxiliar;
                strncpy(nombreSeguido, arrayAux[i-1].nombre, 20);
                tipoSeguido = arrayAux[i-1].tipo;
            }
            contadorAuxiliar = 0;
            strncpy(nombreRepetido, arrayAux[i].nombre, 20);
        }
        if(arrayAux[i].isEmpty == 1)
        {
            break; //Se hace break porque se sabe que todos estarán llenos hasta llegar a un isEmpty.
        }
    }
    printf("El instrumento mas usado es %s, y es de tipo %d, encontrandose en %d musicos.", nombreSeguido, tipoSeguido, contadorSeguidos);
    return retorno;
}

#endif // INFORMES_C_INCLUDED
