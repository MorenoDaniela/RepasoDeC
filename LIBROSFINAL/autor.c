#ifndef AUTOR_C_INCLUDED
#define AUTOR_C_INCLUDED
#include "autor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>//para linux
#include "funciones.h"
#define TRIES 3

int uno_initStruct(Autor* arrayA, int limite)
{
    int retorno = -1;
    int i;
    if (arrayA!=NULL && limite>0)
    {
        for (i = 0; i < limite; i++)
        {
            arrayA[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}

int uno_findEmpty (Autor* arrayA,int limite, int* resultado)
{
    int retorno=-1;
    int i;

    if (arrayA!=NULL && limite>=0 && resultado!=NULL)
    {
        for (i=0;i<=limite;i++)
        {
            if (arrayA[i].isEmpty==1)
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

int uno_alta(Autor* arrayA,int *id, int limite)
{
    int retorno=-1;
    int lugarVacio;
    //__fpurge(stdin);
    fflush(stdin);

    if (limite>0 && id!=NULL )
    {
        if(uno_findEmpty(arrayA,limite,&lugarVacio)!=-1)
        {
            if (getName("\nIngrese nombre: \n","Error, nombre no valido.\n",3,30,TRIES,arrayA[lugarVacio].nombre)==0 &&
                getApellido("\nIngrese apellido: \n","Error, apellido no valido.\n",3,30,TRIES,arrayA[lugarVacio].apellido)==0)
            {
               arrayA[lugarVacio].idAutor=*id;
                (*id)++;
               arrayA[lugarVacio].isEmpty=0;
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

void uno_print(Autor* arrayA, int limite)
{
    int i;

    printf ("\n*** Lista ***\n");

    for (i=0;i<=limite;i++)
    {
        if (arrayA[i].isEmpty==0)
        {
            printf ("\n********************************************");
            printf ("\nNombre del autor: %s ",arrayA[i].nombre);
            printf ("\nApellido del autor: %s ",arrayA[i].apellido);
            printf ("\nId del autor: %d ",arrayA[i].idAutor);
            printf ("\nPosicion: %d ",i);
            printf ("\nEstado : %d \n",arrayA[i].isEmpty);
        }
    }
}

int uno_baja(Autor* arrayA,int limite)
{
    int posicion;
    int retorno=-1;
    if (arrayA!=NULL && limite>0)
    {
        uno_print(arrayA,limite);
        switch (uno_findById("\nIngrese el id del autor a dar de baja: \n",arrayA,&posicion,limite))
        {
            case 0:
            if (arrayA[posicion].isEmpty==0)
            {
                arrayA[posicion].isEmpty=1;
                printf ("\nSe borro el id: %d \n",arrayA[posicion].idAutor);
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
int uno_getId(char*msj,Autor* arrayA,int limite)
{
    int i;
    int retorno=-1;
    Autor auxAutor;

    if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxAutor.idAutor)==0)
    {
        for (i=0;i<=limite;i++)
        {
            if (arrayA[i].idAutor == auxAutor.idAutor)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int uno_findById(char* msj,Autor* arrayA,int* idEncontrado, int limite)
{
    int i;
    int retorno=1;
    int auxAutor;
    //revisar limite aca abajo
    if (msj!=NULL && arrayA !=NULL && idEncontrado!=NULL && limite>0)
    {
        if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxAutor)==0)
        {
            for (i=0;i<=limite;i++)
            {
                if (arrayA[i].isEmpty==0)
                {
                    if (arrayA[i].idAutor == auxAutor)
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

int uno_modificar(Autor* arrayA,int limite)
{
    int retorno=-1;
    int posicion;
    int opcion;
    /*char auxNombre;
    char auxApellido;
    char auxDni;
    int auxEdad;*/

    if (arrayA!=NULL && limite>0)
    {
        uno_print(arrayA,limite);
        //uno_findById("Ingrese el id del autor a modificar",arrayA,&posicion,limite);
        //posicion=uno_getId(msj,arrayA,limite);
        if (uno_findById("Ingrese el id del autor a modificar: \n",arrayA,&posicion,limite)==0)
        {
            while (opcion!=3)
            {
                getInt("\n1-Modificar nombre. \n2-Modificar apellido.\n3-Salir de modificacion.\n","Opcion no valida\n",1,3,TRIES,&opcion);
                system("cls");//
                //system("clear");
                fflush(stdin);
                //__fpurge(stdin);
                switch(opcion)
                {
                    case 1:
                    if (getName("Ingrese nuevo nombre: \n","Nombre no valido.\n",3,31,TRIES,arrayA[posicion].nombre)==0)
                    {
                        //strncpy(arrayA[posicion].nombre,&auxNombre,sizeof(arrayA[posicion].nombre));
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                    break;

                    case 2:
                    if (getApellido("Ingrese nuevo apellido: \n","Error, apellido no valido.\n",2,31,TRIES,arrayA[posicion].apellido)==0)
                    {
                        //strncpy(arrayA[posicion].apellido,&auxApellido,sizeof(auxApellido));
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

int uno_ordenarDobleCadena(Autor* arrayA,int limite)
{
    int i;
    Autor buffer;
    int retorno=-1;

    if (arrayA!=NULL && limite>0)
    {
        for (i=0;i<=limite-1;i++)
        {
            if (arrayA[i].isEmpty==1 || arrayA[i+1].isEmpty==1)
            {
                continue;
            }
                if (strncmp(arrayA[i].nombre,arrayA[i+1].nombre,31)>0)
                {
                    buffer = arrayA[i];
                    arrayA[i]= arrayA[i+1];
                    arrayA[i+1]=buffer;
                }
                    else if(strncmp(arrayA[i].nombre,arrayA[i+1].nombre,31)==0)
                    {
                        if (strncmp(arrayA[i].apellido, arrayA[i+1].apellido,31)>0)
                        {
                            buffer= arrayA[i];
                            arrayA[i]=arrayA[i+1];
                            arrayA[i+1]=buffer;
                        }
                    }
        }
        retorno=0;
    }
    return retorno;
}

void harcodearAutores(Autor* arrayA, int limite)
{
    strcpy(arrayA[0].nombre,"BBB");
    strcpy(arrayA[0].apellido,"DDD");
    arrayA[0].isEmpty=0;
    arrayA[0].idAutor=1;

    strcpy(arrayA[1].nombre,"BBB");
    strcpy(arrayA[1].apellido,"CCC");
    arrayA[1].isEmpty=0;
    arrayA[1].idAutor=3;

    strcpy(arrayA[2].nombre,"CCC");
    strcpy(arrayA[2].apellido,"BBB");
    arrayA[2].isEmpty=0;
    arrayA[2].idAutor=5;

    strcpy(arrayA[3].nombre,"CCC");
    strcpy(arrayA[3].apellido,"AAA");
    arrayA[3].isEmpty=0;
    arrayA[3].idAutor=2;
}

#endif // AUTOR_C_INCLUDED
