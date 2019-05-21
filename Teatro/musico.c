#ifndef MUSICO_C_INCLUDED
#define MUSICO_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"
//#include <stdio_ext.h>//para linux
#include "funciones.h"
#define TRIES 3

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param limite int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musicos_initStruct(Musico* arrayMusico, int limite)
{
    int retorno = -1;
    int i;
    if (arrayMusico!=NULL && limite>0)
    {
        for (i = 0; i<=limite; i++)
        {
            arrayMusico[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}
/** \brief Busca el primer lugar vacio en un array
* \param array musico Array de musico
* \param limite int Tamaño del array
* \param resultado int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musicos_findEmpty (Musico* arrayMusico,int limite, int* resultado)
{
    int retorno=-1;
    int i;
    if (arrayMusico!=NULL && limite>=0 && resultado!=NULL)
    {
        for (i=0;i<=limite;i++)
        {
            if (arrayMusico[i].isEmpty==1)
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
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array musico Array de musico
* \param limite int Tamaño del array
* \param ID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musicos_alta(Musico* arrayMusico, Orquesta* arrayOrquesta,Instrumento* arrayInstrumento,int *id,int limiteMusico,int limiteOrquesta, int limiteInstrumento)
{
    int retorno=-1;
    int lugarVacio;
    int idOrquesta;
    int idInstrumento;
    int auxEdad;
    int posicion;
    //__fpurge(stdin);
    fflush(stdin);

    if (limiteOrquesta>0 && id!=NULL && limiteMusico>0 && limiteInstrumento>0)
    {
        orquesta_print(arrayOrquesta,limiteOrquesta);
        if (getInt("\nIngrese id de la orquesta: \n","\nError, id no valido.\n",1,limiteOrquesta,TRIES,&idOrquesta)==0)
        {
            if (orquesta_buscarID(arrayOrquesta,limiteOrquesta,idOrquesta,&posicion)==0)
            {
                instrumento_print(arrayInstrumento,limiteInstrumento);
                if (getInt("\nIngrese id de instrumento: \n","\nError, id no valido.\n",1,limiteInstrumento,TRIES,&idInstrumento)==0)
                {
                    if (instrumento_buscarID(arrayInstrumento,limiteInstrumento,idInstrumento,&posicion)==0)
                    {
                        if(musicos_findEmpty(arrayMusico,limiteMusico,&lugarVacio)!=-1)
                        {
                            if(getName("\nIngrese nombre del musico: \n","Error, nombre no valido.\n",1,31,TRIES,arrayMusico[lugarVacio].nombre)==0 &&
                                getApellido("\nIngrese apellido: \n","Error, apellido no valido.\n",1,12,TRIES,arrayMusico[lugarVacio].apellido)==0 &&
                                getInt("\nIngrese edad: \n","Error, edad no valido.\n",18,200,TRIES,&auxEdad)==0)
                            {
                               arrayMusico[lugarVacio].idMusico=*id;
                               arrayMusico[lugarVacio].idOrquesta=idOrquesta;
                               arrayMusico[lugarVacio].idInstrumento=idInstrumento;
                               arrayMusico[lugarVacio].edad=auxEdad;
                                (*id)++;
                               arrayMusico[lugarVacio].isEmpty=0;
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
                    }else
                        {
                            printf ("\nId del instrumento no encontrado.\n");
                        }
                }
            }else
            {
                printf ("\nId de orquesta no encontrado.\n");
            }
        }
    }
    return retorno;
}
/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param limite int Tamaño del array
* \return void
*
*/
void musico_print(Musico* arrayMusico, int limiteMusico, Instrumento* arrayInstrumento, int limiteInstrumento)
{
    int i;
    char buffer[20];
    int auxPos;
    for (i=0;i<=limiteMusico;i++)
    {
        if (arrayMusico[i].isEmpty==0)
        {
            instrumento_buscarID(arrayInstrumento,limiteInstrumento,arrayInstrumento[i].idInstrumento,&auxPos);
            switch (arrayInstrumento[auxPos].tipo)
            {
            case 1:
                strncpy(buffer,"Cuerdas.",sizeof(buffer));
                break;
            case 2:
                strncpy(buffer,"Viento-Madera.",sizeof(buffer));
                break;
            case 3:
                strncpy(buffer,"Viento-Metal.",sizeof(buffer));
                break;
            case 4:
                strncpy(buffer,"Percusion.",sizeof(buffer));
                break;
            }
            printf ("\n********************************************");
            printf ("\nNombre del musico: %s ",arrayMusico[i].nombre);
            printf ("\nApellido del musico: %s ",arrayMusico[i].apellido);
            printf ("\nTipo de instrumento : %s",buffer);
            printf ("\nId de orquesta : %d",arrayMusico[i].idOrquesta);
            printf ("\nNombre de instrumento: %s",arrayInstrumento[auxPos].nombre);
            printf ("\nId de instrumento : %d",arrayMusico[i].idInstrumento);
            printf ("\nId del musico: %d ",arrayMusico[i].idMusico);
            //printf ("\nPosicion: %d ",i);
            //printf ("\nEstado : %d \n",arrayMusico[i].isEmpty);
        }
    }
}

void musicos_print(Musico* arrayMusico, int limite)
{
    int i;
    for (i=0;i<=limite;i++)
    {
        if (arrayMusico[i].isEmpty==0)
        {
            printf ("\n********************************************");
            printf ("\nNombre del musico: %s ",arrayMusico[i].nombre);
            printf ("\nApellido del musico: %s ",arrayMusico[i].apellido);
            printf ("\nEdad del musico: %d ",arrayMusico[i].edad);
            printf ("\nId de instrumento : %d",arrayMusico[i].idInstrumento);
            printf ("\nId del musico: %d ",arrayMusico[i].idMusico);
            //printf ("\nPosicion: %d ",i);
            //printf ("\nEstado : %d \n",arrayMusico[i].isEmpty);
        }
    }
}
/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musicos_baja(Musico* arrayMusico,int limiteMusico)
{
    int posicion;
    int idMusico;
    int retorno=-1;
    if (arrayMusico!=NULL && limiteMusico>0)
    {
        musicos_print(arrayMusico,limiteMusico);
        if (getInt("\nIngrese el id del musico a dar de baja: \n","Error, id no valido.",1,limiteMusico,TRIES,&idMusico)==0)
        {
            if (musico_buscarID(arrayMusico,limiteMusico,idMusico,&posicion)==0)
            {
                if (arrayMusico[posicion].isEmpty==0)
                {
                    arrayMusico[posicion].isEmpty=1;
                    printf ("\nSe borro el id: %d \n",arrayMusico[posicion].idMusico);
                    retorno=0;
                }
            }else
                printf ("\nNo se encontro el id del musico.\n");
        }
    }
    return retorno;
}


int musicos_modificar(Musico* arrayMusico,Orquesta* arrayOrquesta,int limiteOrquesta, int limiteMusico)
{
    int retorno=-1;
    int posicion;
    int opcion;
    int idOrquesta;
    int idMusico;
    int auxEdad;//
    if (arrayMusico!=NULL && limiteMusico>0 && limiteOrquesta>0 && arrayOrquesta!=NULL)
    {
        musicos_print(arrayMusico,limiteMusico);
        if (getInt("\nIngrese id del musico a modificar: \n","\nError, id no valida.\n",1,limiteMusico,TRIES,&idMusico)==0)
        {
            if (musico_buscarID(arrayMusico,limiteMusico,idMusico,&posicion)==0)
            {
                while (opcion!=3)
                {
                    getInt("\n1-Modificar edad.\n2-Modificar id de orquesta.\n3-Salir de modificacion.\n","Opcion no valida\n",1,3,TRIES,&opcion);
                    //system("cls");//
                    system("clear");
                    fflush(stdin);
                    //__fpurge(stdin);
                    switch(opcion)
                    {
                        case 1:
                            if (getInt("\nIngrese nueva edad: \n","Edad no valido.\n",18,200,TRIES,&auxEdad)==0)
                            {
                                arrayMusico[posicion].edad=auxEdad;
                                printf ("Modificacion con exito.\n");
                            }else
                                {
                                    printf ("\nModificacion sin exito.\n");
                                }
                            break;
                        case 2:
                            if (getInt("\nIngrese nuevo id de la orquesta: \n","\nError, id no valido",1,limiteOrquesta,TRIES,&idOrquesta)==0)
                            {
                                if (orquesta_buscarID(arrayOrquesta,limiteOrquesta,idOrquesta,&posicion)==0)
                                {
                                    arrayMusico[posicion].idOrquesta=idOrquesta;
                                    printf ("Modificacion con exito.\n");
                                }else
                                    {
                                        printf ("\nNo se encontro el id.\n");
                                    }
                            }
                            break;
                        default:
                            printf("\nOpcion no valida.\n");
                            break;
                    }//fin switch
                }//fin while
                retorno=0;
            }else
                printf("\nNo se encontro el id.\n");
        }
    }
    return retorno;
}

int musicos_findById(char* msj,Musico* arrayMusico,int* idEncontrado, int limite)
{
    int i;
    int retorno=1;
    int auxMusico;
    //revisar limite aca abajo
    if (msj!=NULL && arrayMusico !=NULL && idEncontrado!=NULL && limite>0)
    {
        if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxMusico)==0)
        {
            for (i=0;i<=limite;i++)
            {
                if (arrayMusico[i].isEmpty==0)
                {
                    if (arrayMusico[i].idMusico == auxMusico)
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

int musico_buscarID(Musico* arrayMusico, int limite, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(arrayMusico!= NULL && limite>=0)
    {
        for(i=0;i<=limite;i++)
        {
            if(arrayMusico[i].isEmpty==1)
                continue;
            else if(arrayMusico[i].idMusico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int musicos_bajaOrquesta(Musico* arrayMusico,int limiteMusico, Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int j;
    if (arrayMusico!=NULL && arrayOrquesta!=NULL && limiteMusico>0 && limiteOrquesta>0)
    {
        for (i=0;i<=limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
            {
                for (j=0;j<limiteMusico;j++)
                {
                    arrayMusico[j].isEmpty=1;
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

int musicos_bajaPorOrquesta(Musico* arrayMusico, int limite, int idAEliminar)                                      //cambiar musico
{
    int retorno=-1;
    int i;
    if(arrayMusico!=NULL && limite>0)
    {
        for(i=0;i<=limite;i++)
        {
            if(arrayMusico[i].idOrquesta == idAEliminar)
            {
                arrayMusico[i].isEmpty=1;
                arrayMusico[i].idMusico=0;                                                                   //cambiar campo id
                arrayMusico[i].edad=0;                                                               //cambiar campo edad                                                            //cambiar campo varFloat
                strcpy(arrayMusico[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(arrayMusico[i].apellido,"");
                arrayMusico[i].idOrquesta = 0;
                arrayMusico[i].idInstrumento = 0;                                               //cambiar campo apellido
                retorno=0;
            }
        }
    }
    return retorno;
}
void harcodearMusicos(Musico* arrayMusico, int limite)
{
    strcpy(arrayMusico[0].nombre,"Avril");
    strcpy(arrayMusico[0].apellido,"Lavigne");
    arrayMusico[0].edad=34;
    arrayMusico[0].idInstrumento=9;
    arrayMusico[0].idOrquesta=1;
    arrayMusico[0].isEmpty=0;
    arrayMusico[0].idMusico=1;

    strcpy(arrayMusico[1].nombre,"Shawn");
    strcpy(arrayMusico[1].apellido,"Mendes");
    arrayMusico[1].edad=20;
    arrayMusico[1].idInstrumento=1;
    arrayMusico[1].idOrquesta=1;
    arrayMusico[1].isEmpty=0;
    arrayMusico[1].idMusico=3;

    strcpy(arrayMusico[2].nombre,"Camila");
    strcpy(arrayMusico[2].apellido,"Cabello");
    arrayMusico[2].edad=22;
    arrayMusico[2].idInstrumento=2;
    arrayMusico[2].idOrquesta=6;
    arrayMusico[2].isEmpty=0;
    arrayMusico[2].idMusico=2;

    strcpy(arrayMusico[3].nombre,"Avril");
    strcpy(arrayMusico[3].apellido,"Frangipane");
    arrayMusico[3].edad=24;
    arrayMusico[3].idInstrumento=4;
    arrayMusico[3].idOrquesta=5;
    arrayMusico[3].isEmpty=0;
    arrayMusico[3].idMusico=4;

    strcpy(arrayMusico[4].nombre,"Madonna");
    strcpy(arrayMusico[4].apellido,"Ciccone");
    arrayMusico[4].edad=60;
    arrayMusico[4].idInstrumento=4;
    arrayMusico[4].idOrquesta=3;
    arrayMusico[4].isEmpty=0;
    arrayMusico[4].idMusico=5;

    strcpy(arrayMusico[5].nombre,"Tyler");
    strcpy(arrayMusico[5].apellido,"Joseph");
    arrayMusico[5].edad=30;
    arrayMusico[5].idInstrumento=6;
    arrayMusico[5].idOrquesta=5;
    arrayMusico[5].isEmpty=0;
    arrayMusico[5].idMusico=6;

    strcpy(arrayMusico[6].nombre,"Elvis");
    strcpy(arrayMusico[6].apellido,"Presley");
    arrayMusico[6].edad=42;
    arrayMusico[6].idInstrumento=7;
    arrayMusico[6].idOrquesta=1;
    arrayMusico[6].isEmpty=0;
    arrayMusico[6].idMusico=8;

    strcpy(arrayMusico[7].nombre,"Elvis");
    strcpy(arrayMusico[7].apellido,"Gaga");
    arrayMusico[7].edad=33;
    arrayMusico[7].idInstrumento=8;
    arrayMusico[7].idOrquesta=5;
    arrayMusico[7].isEmpty=0;
    arrayMusico[7].idMusico=7;

    strcpy(arrayMusico[8].nombre,"Travis");
    strcpy(arrayMusico[8].apellido,"Barker");
    arrayMusico[8].edad=43;
    arrayMusico[8].idInstrumento=4;
    arrayMusico[8].idOrquesta=3;
    arrayMusico[8].isEmpty=0;
    arrayMusico[8].idMusico=9;
}

void harcodearTODO(Musico* arrayMusico,int limiteMusico, Instrumento* arrayInstrumento, int limiteInstrumento, Orquesta* arrayOrquesta, int limiteOrquesta)
{
    harcodearOrquestas(arrayOrquesta,limiteOrquesta);
    harcodearInstrumento(arrayInstrumento,limiteInstrumento);
    harcodearMusicos(arrayMusico,limiteMusico);
}
#endif // MUSICO_C_INCLUDED
