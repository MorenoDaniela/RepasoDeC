#ifndef PRESTAMO_C_INCLUDED
#define PRESTAMO_C_INCLUDED
#include "autor.h"
#include "prestamo.h"
#include "libros.h"
#include "socios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
//#include <stdio_ext.h>//para linux
#define TRIES 3

int cuatro_initStruct(Prestamo* arrayP, int limite)
{
    int retorno = -1;
    int i;
    if (arrayP!=NULL && limite>0)
    {
        for (i=0; i<= limite; i++)
        {
            arrayP[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}

int cuatro_findEmpty (Prestamo* arrayP,int limite, int* resultado)
{
    int retorno=-1;
    int i;

    if (arrayP!=NULL && limite>=0 && resultado!=NULL)
    {
        for (i=0;i<=limite;i++)
        {
            if (arrayP[i].isEmpty==1)
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

int cuatro_alta(Prestamo* arrayP, Libro* arrayL,Socio* arrayS,int *id,int limitePrestamo,int limiteLibro, int limiteSocio)
{
    int retorno=-1;
    int lugarVacio;
    int idLibro;
    int idSocio;
    int auxAnio;
    int auxDia;
    int auxMes;
    //__fpurge(stdin);
    fflush(stdin);

    if (limiteLibro>0 && id!=NULL && limitePrestamo>0 && limiteSocio>0)
    {
        dos_print(arrayL,limiteLibro);
        if (dos_findById("\nIngrese id del libro: \n",arrayL,&idLibro,limiteLibro)==0)
        {
            tres_print(arrayS,limiteSocio);
            if (tres_findById("\nIngrese id del socio: \n",arrayS,&idSocio,limiteSocio)==0)
            {
                if(cuatro_findEmpty(arrayP,limitePrestamo,&lugarVacio)!=-1)
                {
                    if(getInt("\nIngrese dia: \n","Error, dia no valido.\n",1,31,TRIES,&auxDia)==0 &&
                        getInt("\nIngrese mes: \n","Error, mes no valido.\n",1,12,TRIES,&auxMes)==0 &&
                        getInt("\nIngrese anio: \n","Error, anio no valido.\n",2000,2019,TRIES,&auxAnio)==0)
                    {
                       arrayP[lugarVacio].idPrestamo=*id;
                       arrayP[lugarVacio].idLibro=idLibro;
                       arrayP[lugarVacio].idSocio=idSocio;
                       arrayP[lugarVacio].dia=auxDia;
                       arrayP[lugarVacio].anio=auxAnio;
                       arrayP[lugarVacio].mes=auxMes;
                        (*id)++;
                       arrayP[lugarVacio].isEmpty=0;
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
                printf ("\nId del socio no encontrado.\n");
            }
        }else
        {
            printf ("\nId de libro no encontrado.\n");
        }
    }
    return retorno;
}

void cuatro_print(Prestamo* arrayP, int limite)
{
    int i;

    printf ("\n*** Lista ***\n");

    for (i=0;i<=limite;i++)
    {
        if (arrayP[i].isEmpty==0)
        {
            printf ("\n********************************************");
            printf ("\nID del prestamo: %d ",arrayP[i].idPrestamo);
            printf ("\nId del socio: %d ",arrayP[i].idSocio);
            printf ("\nId del libro: %d ",arrayP[i].idPrestamo);
            printf ("\nFecha: %d-%d-%d ",arrayP[i].dia,arrayP[i].mes,arrayP[i].anio);
            printf ("\nPosicion: %d ",i);
            printf ("\nEstado : %d \n",arrayP[i].isEmpty);
        }
    }
}

int cuatro_baja(Prestamo* arrayP,int limite)
{
    int posicion;
    int retorno=-1;
    if (arrayP!=NULL && limite>0)
    {
        cuatro_print(arrayP,limite);
        switch (cuatro_findById("\nIngrese el id del libro a dar de baja: \n",arrayP,&posicion,limite))
        {
            case 0:
            if (arrayP[posicion].isEmpty==0)
            {
                arrayP[posicion].isEmpty=1;
                printf ("\nSe borro el id: %d \n",arrayP[posicion].idPrestamo);
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
int cuatro_getId(char*msj,Prestamo* arrayP,int limite)
{
    int i;
    int retorno=-1;
    Prestamo auxPrestamo;

    if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxPrestamo.idPrestamo)==0)
    {
        for (i=0;i<limite;i++)
        {
            if (arrayP[i].idPrestamo == auxPrestamo.idPrestamo)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int cuatro_findById(char* msj,Prestamo* arrayP,int* idEncontrado, int limite)
{
    int i;
    int retorno=1;
    int auxPrestamo;
    //revisar limite aca abajo
    if (msj!=NULL && arrayP !=NULL && idEncontrado!=NULL && limite>0)
    {
        if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxPrestamo)==0)
        {
            for (i=0;i<=limite;i++)
            {
                if (arrayP[i].isEmpty==0)
                {
                    if (arrayP[i].idPrestamo == auxPrestamo)
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

/*int cuatro_modificar(Prestamo* arrayP,Autor* arrayA,int limiteAutor, int limitePrestamo)
{
    int retorno=-1;
    int posicion;
    int opcion;
    int idAutor;
    //char auxTitulo;
    //char auxNombre;
    char auxApellido;
    char auxDni;
    int auxEdad;//

    if (arrayP!=NULL && limitePrestamo>0 && limiteAutor>0 && arrayA!=NULL)
    {
        cuatro_print(arrayP,limitePrestamo);
        //cuatro_findById("Ingrese el id del autor a modificar",arrayP,&posicion,limite);
        //posicion=cuatro_getId(msj,arrayP,limite);
        if (cuatro_findById("Ingrese el id del libro a modificar: \n",arrayP,&posicion,limitePrestamo)==0)
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
                    if (getString("Ingrese nuevo titulo: \n","Nombre no valido.\n",3,51,TRIES,arrayP[posicion].titulo)==0)
                    {
                        //strncpy(arrayP[posicion].titulo,auxTitulo,51);
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                    break;

                    case 2:
                    if (uno_findById("\nIngrese nuevo id del autor:\n",arrayA,&idAutor,limiteAutor)==0)
                    {
                        arrayP[posicion].idAutor=idAutor;
                        //strncpy(arrayP[posicion].apellido,&auxApellido,sizeof(auxApellido));
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
}*/

/*int cuatro_ordenarTitulo(Prestamo* arrayP,int limite)
{
    int i;
    Prestamo buffer;
    int retorno=-1;

    if (arrayP!=NULL && limite>0)
    {
        for (i=0;i<=limite-1;i++)
        {
            if (arrayP[i].isEmpty==1 || arrayP[i+1].isEmpty==1)
            {
                continue;
            }
                if (strncmp(arrayP[i].titulo,arrayP[i+1].titulo,51)>0)
                {
                    buffer = arrayP[i];
                    arrayP[i]= arrayP[i+1];
                    arrayP[i+1]=buffer;
                }
        }
        retorno=0;
    }
    return retorno;
}*/

void harcodearPrestamos(Prestamo* arrayP, int limite)
{
    arrayP[0].isEmpty=0;
    arrayP[0].idLibro=3;
    arrayP[0].idPrestamo=0;
    arrayP[0].idSocio=1;
    arrayP[0].dia=2;
    arrayP[0].mes=5;
    arrayP[0].anio=2010;

    arrayP[1].isEmpty=0;
    arrayP[1].idLibro=0;
    arrayP[1].idPrestamo=1;
    arrayP[1].idSocio=0;
    arrayP[1].dia=31;
    arrayP[1].mes=10;
    arrayP[1].anio=2015;

    arrayP[2].isEmpty=0;
    arrayP[2].idLibro=1;
    arrayP[2].idPrestamo=2;
    arrayP[2].idSocio=0;
    arrayP[2].dia=15;
    arrayP[2].mes=9;
    arrayP[2].anio=2018;

}



#endif // PRESTAMO_C_INCLUDED
