#ifndef AUTORES_C_INCLUDED
#define AUTORES_C_INCLUDED
#include "funciones.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>//para linux
#include "autores.h"
#define REINTENTOS 3

int uno_initStruct(Autor* autores, int limite)
{
    int retorno = -1;
    int i;
    if (autores!=NULL && limite>0)
    {
        for (i = 0; i < limite; i++)
        {
            autores[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}

int uno_findEmpty (Autor* autores,int limite, int* resultado)
{
    int retorno=-1;
    int i;

    for (i=0;i<limite;i++)
    {
        if (autores[i].isEmpty==1)
        {
            *resultado=i;
            retorno=0;
            break;
        }
        //retorno = 1;
    }
    return retorno;
}

int uno_alta(Autor* autores,int lugarVacio,int id, int limite)
{
    int retorno=-1;
    __fpurge(stdin);//fflush(stdin);

    if (getName("\nIngrese nombre: \n","Error, nombre no valido.\n",3,31,REINTENTOS,autores[lugarVacio].nombre)==0 &&
        getApellido("\nIngrese apellido: \n","Error, apellido no valido.\n",3,31,REINTENTOS,autores[lugarVacio].apellido)==0)
    {
       autores[lugarVacio].idAutor=id;
       autores[lugarVacio].isEmpty=0;
       retorno=0;
    }
    else
        {
            retorno=1;
        }
    return retorno;
}

void uno_print(Autor* autores, int limite)
{
    int i;

    printf ("\n*** Lista ***\n");

    for (i=0;i<limite;i++)
    {
        if (autores[i].isEmpty==0)
        {
            printf ("\n********************************************");
            printf ("\nNombre del autor: %s \n",autores[i].nombre);
            printf ("\nApellido del asociado: %s \n",autores[i].apellido);
            printf ("\nId del autor: %d \n",autores[i].idAutor);
            printf ("\nPosicion: %d \n",i);
            printf ("\nEstado : %d \n",autores[i].isEmpty);
        }
    }
}

#endif // AUTORES_C_INCLUDED
