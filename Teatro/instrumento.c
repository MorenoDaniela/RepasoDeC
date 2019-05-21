#ifndef INSTRUMENTO_C_INCLUDED
#define INSTRUMENTO_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instrumento.h"
//#include <stdio_ext.h>//para linux
#include "funciones.h"
#define TRIES 3
#define CUERDAS 1
#define VIENTO_MADERA 2
#define VIENTO_METAL 3
#define PERCUSION 4

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array instrumento Array of instrumento
* \param limite int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int instrumento_initStruct(Instrumento* arrayInstrumento, int limite)
{
    int retorno = -1;
    int i;
    if (arrayInstrumento!=NULL && limite>0)
    {
        for (i = 0; i<=limite; i++)
        {
            arrayInstrumento[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}
/** \brief Busca el primer lugar vacio en un array
* \param array instrumento Array de instrumento
* \param limite int Tamaño del array
* \param resultado int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumento_findEmpty (Instrumento* arrayInstrumento,int limite, int* resultado)
{
    int retorno=-1;
    int i;
    if (arrayInstrumento!=NULL && limite>=0 && resultado!=NULL)
    {
        for (i=0;i<=limite;i++)
        {
            if (arrayInstrumento[i].isEmpty==1)
            {
                *resultado=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array instrumento Array de instrumento
* \param limite int Tamaño del array
* \param ID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento* arrayInstrumento,int *id, int limite)
{
    int retorno=-1;
    int lugarVacio;
    int auxTipo;
    //__fpurge(stdin);
    fflush(stdin);
    if (limite>0 && id!=NULL )
    {
        if(instrumento_findEmpty(arrayInstrumento,limite,&lugarVacio)!=-1)
        {
            if (getName("\nIngrese nombre del instrumento: \n","Error, nombre no valido.\n",3,30,TRIES,arrayInstrumento[lugarVacio].nombre)==0 &&
                getInt("\nIngrese tipo de instrumento: \n1-Cuerdas.\n"
                "2-Viento-Madera.\n"
                "3-Viento-metal.\n 4-Percusion\n","Error, tipo no valido.\n",1,4,TRIES,&auxTipo)==0)
            {
               arrayInstrumento[lugarVacio].idInstrumento=*id;
               printf ("\nEl id es: %d \n",*id);
                (*id)++;
                arrayInstrumento[lugarVacio].tipo=auxTipo;
               arrayInstrumento[lugarVacio].isEmpty=0;
               printf("\nSe cargaron con exito los datos.\n");

               retorno=0;
            }else
                {
                    printf("\nNo se pudo cargar con exito.\n");
                }
        }else
        {
            printf("\nNo hay espacio vacio.\n");
        }
    }
    return retorno;
}
/** \brief Lista los elementos de un array
* \param array instrumento Array de instrumento
* \param limite int Tamaño del array
* \return void
*
*/
void instrumento_print(Instrumento* arrayInstrumento, int limite)
{
    int i;
    char buffer[20];
    for (i=0;i<limite;i++)
    {
        if (arrayInstrumento[i].isEmpty==0)
        {
            switch (arrayInstrumento[i].tipo)
            {
            case 1:
                strncpy(buffer,"Cuerdas",sizeof(buffer));
                break;
            case 2:
                strncpy(buffer,"Viento-Madera",sizeof(buffer));
                break;
            case 3:
                strncpy(buffer,"Viento-Metal",sizeof(buffer));
                break;
            case 4:
                strncpy(buffer,"Percusion",sizeof(buffer));
                break;
            }
            printf ("\n********************************************");
            printf ("\nNombre del instrumento: %s ",arrayInstrumento[i].nombre);
            printf ("\nTipo del instrumento: %s ",buffer);
            printf ("\nId del instrumento: %d ",arrayInstrumento[i].idInstrumento);
        }
    }
}
/** \brief Borra un elemento del array por ID
* \param array instrumento Array de instrumento
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_baja(Instrumento* arrayInstrumento,int limite)
{
    int posicion;
    int auxId;
    int retorno=-1;
    if (arrayInstrumento!=NULL && limite>0)
    {
        instrumento_print(arrayInstrumento,limite);
        if (getInt("\nIngrese el id del instrumento a dar de baja: \n","Error, id no valido.",1,limite,TRIES,&auxId)==0)
        {
            if (instrumento_buscarID(arrayInstrumento,limite,auxId,&posicion)==0)
            {
                if (arrayInstrumento[posicion].isEmpty==0)
                {
                    arrayInstrumento[posicion].isEmpty=1;
                    printf ("\nSe borro el id: %d \n",arrayInstrumento[posicion].idInstrumento);
                    retorno=0;
                }
            }else
                printf("\nNo se encontro el id.\n");
        }
    }
    return retorno;
}

int instrumento_findById(char* msj,Instrumento* arrayInstrumento,int* idEncontrado, int limite)
{
    int i;
    int retorno=-1;
    int auxInstrumento;

    if (msj!=NULL && arrayInstrumento !=NULL && idEncontrado!=NULL && limite>0)
    {
        if (getInt(msj,"\nOpcion no valida.\n",1,limite,TRIES,&auxInstrumento)==0)
        {
            for (i=0;i<=limite;i++)
            {
                if (arrayInstrumento[i].isEmpty==0)
                {
                    if (arrayInstrumento[i].idInstrumento == auxInstrumento)
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

int instrumento_buscarID(Instrumento* arrayInstrumento, int limite, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(arrayInstrumento!= NULL && limite>=0)
    {
        for(i=0;i<=limite;i++)
        {
            if(arrayInstrumento[i].isEmpty==1)
                continue;
            else if(arrayInstrumento[i].idInstrumento==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

void harcodearInstrumento(Instrumento* arrayInstrumento, int limite)
{
    strcpy(arrayInstrumento[0].nombre,"Guitarra");
    arrayInstrumento[0].tipo=1;
    arrayInstrumento[0].isEmpty=0;
    arrayInstrumento[0].idInstrumento=1;

    strcpy(arrayInstrumento[1].nombre,"Violin");
    arrayInstrumento[1].tipo=2;
    arrayInstrumento[1].isEmpty=0;
    arrayInstrumento[1].idInstrumento=2;

    strcpy(arrayInstrumento[2].nombre,"Bateria");
    arrayInstrumento[2].tipo=4;
    arrayInstrumento[2].isEmpty=0;
    arrayInstrumento[2].idInstrumento=3;

    strcpy(arrayInstrumento[3].nombre,"Piano");
    arrayInstrumento[3].tipo=3;
    arrayInstrumento[3].isEmpty=0;
    arrayInstrumento[3].idInstrumento=4;

    strcpy(arrayInstrumento[4].nombre,"Saxofon");
    arrayInstrumento[4].tipo=1;
    arrayInstrumento[4].isEmpty=0;
    arrayInstrumento[4].idInstrumento=5;

    strcpy(arrayInstrumento[5].nombre,"Armonica");
    arrayInstrumento[5].tipo=1;
    arrayInstrumento[5].isEmpty=0;
    arrayInstrumento[5].idInstrumento=8;

    strcpy(arrayInstrumento[6].nombre,"Acordeon");
    arrayInstrumento[6].tipo=3;
    arrayInstrumento[6].isEmpty=0;
    arrayInstrumento[6].idInstrumento=6;

    strcpy(arrayInstrumento[7].nombre,"Tuba");
    arrayInstrumento[7].tipo=1;
    arrayInstrumento[7].isEmpty=0;
    arrayInstrumento[7].idInstrumento=7;

    strcpy(arrayInstrumento[8].nombre,"Bandoneon");
    arrayInstrumento[8].tipo=2;
    arrayInstrumento[8].isEmpty=0;
    arrayInstrumento[8].idInstrumento=9;

}

#endif // INSTRUMENTO_C_INCLUDED
