#ifndef LIBROS_C_INCLUDED
#define LIBROS_C_INCLUDED
#include "autor.h"
#include "libros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
//#include <stdio_ext.h>//para linux
#define TRIES 3

int dos_initStruct(Libro* arrayL, int limite)
{
    int retorno = -1;
    int i;
    if (arrayL!=NULL && limite>0)
    {
        for (i=0; i<= limite; i++)
        {
            arrayL[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}

int dos_findEmpty (Libro* arrayL,int limite, int* resultado)
{
    int retorno=-1;
    int i;

    if (arrayL!=NULL && limite>=0 && resultado!=NULL)
    {
        for (i=0;i<=limite;i++)
        {
            if (arrayL[i].isEmpty==1)
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

int dos_alta(Libro* arrayL, Autor* arrayA,int *id, int limiteAutor,int limiteLibro)
{
    int retorno=-1;
    int lugarVacio;
    int idAutor;
    //__fpurge(stdin);
    fflush(stdin);

    if (limiteAutor>0 && id!=NULL && limiteLibro>0)
    {
        uno_print(arrayA,limiteAutor);
        if (uno_findById("\nIngrese id del autor al que se le va a asignar un libro: \n",arrayA,&idAutor,limiteAutor)==0)
        {
            if(dos_findEmpty(arrayL,limiteLibro,&lugarVacio)!=-1)
            {
                if(getString("\nIngrese titulo: \n","\nError, nombre no valido.\n",3,51,TRIES,arrayL[lugarVacio].titulo)==0)
                {
                   arrayL[lugarVacio].idLibro=*id;
                   arrayL[lugarVacio].idAutor=idAutor;
                    (*id)++;
                   arrayL[lugarVacio].isEmpty=0;
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
        }else
        {
            printf("\nError, id de autor no encontrado.\n");
        }
    }
    return retorno;
}

void dos_print(Libro* arrayL, int limite)
{
    int i;

    printf ("\n*** Lista ***\n");

    for (i=0;i<=limite;i++)
    {
        if (arrayL[i].isEmpty==0)
        {
            printf ("\n********************************************");
            printf ("\nTitulo del libro: %s ",arrayL[i].titulo);
            printf ("\nId del autor: %d ",arrayL[i].idAutor);
            printf ("\nId del libro: %d ",arrayL[i].idLibro);
            printf ("\nPosicion: %d ",i);
            printf ("\nEstado : %d \n",arrayL[i].isEmpty);
        }
    }
}

int dos_baja(Libro* arrayL,int limite)
{
    int posicion;
    int retorno=-1;
    if (arrayL!=NULL && limite>0)
    {
        dos_print(arrayL,limite);
        switch (dos_findById("\nIngrese el id del libro a dar de baja: \n",arrayL,&posicion,limite))
        {
            case 0:
            if (arrayL[posicion].isEmpty==0)
            {
                arrayL[posicion].isEmpty=1;
                printf ("\nSe borro el id: %d \n",arrayL[posicion].idLibro);
                retorno=0;
            }
            break;
            case 1:
                printf ("\nNo se encontro el id.\n");
                break;
            default:
                printf ("\nNo encontro el id.\n");
                break;
        }
    }
    return retorno;
}
int dos_getId(char*msj,Libro* arrayL,int limite)
{
    int i;
    int retorno=-1;
    Libro auxLibro;

    if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxLibro.idLibro)==0)
    {
        for (i=0;i<limite;i++)
        {
            if (arrayL[i].idLibro == auxLibro.idLibro)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int dos_findById(char* msj,Libro* arrayL,int* idEncontrado, int limite)
{
    int i;
    int retorno=1;
    int auxLibro;
    //revisar limite aca abajo
    if (msj!=NULL && arrayL !=NULL && idEncontrado!=NULL && limite>0)
    {
        if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxLibro)==0)
        {
            for (i=0;i<=limite;i++)
            {
                if (arrayL[i].isEmpty==0)
                {
                    if (arrayL[i].idLibro == auxLibro)
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

int dos_modificar(Libro* arrayL,Autor* arrayA,int limiteAutor, int limiteLibro)
{
    int retorno=-1;
    int posicion;
    int opcion;
    int idAutor;
    //char auxTitulo;
    /*char auxNombre;
    char auxApellido;
    char auxDni;
    int auxEdad;*/

    if (arrayL!=NULL && limiteLibro>0 && limiteAutor>0 && arrayA!=NULL)
    {
        dos_print(arrayL,limiteLibro);
        //dos_findById("Ingrese el id del autor a modificar",arrayL,&posicion,limite);
        //posicion=dos_getId(msj,arrayL,limite);
        if (dos_findById("Ingrese el id del libro a modificar: \n",arrayL,&posicion,limiteLibro)==0)
        {
            while (opcion!=3)
            {
                getInt("\n1-Modificar titulo. \n2-Modificar id de autor.\n3-Salir de modificacion.\n","Opcion no valida\n",1,3,TRIES,&opcion);
                system("cls");//
                //system("clear");
                fflush(stdin);
                //__fpurge(stdin);
                switch(opcion)
                {
                    case 1:
                    if (getString("Ingrese nuevo titulo: \n","Nombre no valido.\n",3,51,TRIES,arrayL[posicion].titulo)==0)
                    {
                        //strncpy(arrayL[posicion].titulo,auxTitulo,51);
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                    break;

                    case 2:
                    if (uno_findById("\nIngrese nuevo id del autor:\n",arrayA,&idAutor,limiteAutor)==0)
                    {
                        arrayL[posicion].idAutor=idAutor;
                        //strncpy(arrayL[posicion].apellido,&auxApellido,sizeof(auxApellido));
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                        break;
                    case 3:
                        break;
                }//fin switch
            }
            retorno=0;//fin while
        }else
            printf("\nNo se encontro el id.\n");
    }
    return retorno;
}

int dos_ordenarTitulo(Libro* arrayL,int limite)
{
    int i;
    Libro buffer;
    int retorno=-1;

    if (arrayL!=NULL && limite>0)
    {
        for (i=0;i<=limite-1;i++)
        {
            if (arrayL[i].isEmpty==1 || arrayL[i+1].isEmpty==1)
            {
                continue;
            }
                if (strncmp(arrayL[i].titulo,arrayL[i+1].titulo,51)>0)
                {
                    buffer = arrayL[i];
                    arrayL[i]= arrayL[i+1];
                    arrayL[i+1]=buffer;
                }
        }
        retorno=0;
    }
    return retorno;
}

void harcodearLibros(Libro* arrayL, int limite)
{
    strcpy(arrayL[0].titulo,"Los montes de Oca");
    arrayL[0].isEmpty=0;
    arrayL[0].idAutor=2;
    arrayL[0].idLibro=1;

    strcpy(arrayL[1].titulo,"Caperucita Roja");
    arrayL[1].isEmpty=0;
    arrayL[1].idAutor=3;
    arrayL[1].idLibro=0;

    strcpy(arrayL[2].titulo,"Arca de Noe");
    arrayL[2].isEmpty=0;
    arrayL[2].idAutor=3;
    arrayL[2].idLibro=3;

    strcpy(arrayL[3].titulo,"Zorro loco");
    arrayL[3].isEmpty=0;
    arrayL[3].idAutor=1;
    arrayL[3].idLibro=2;

}

#endif // LIBROS_C_INCLUDED
