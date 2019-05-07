#ifndef ASOCIADO_C_INCLUDED
#define ASOCIADO_C_INCLUDED
#include "asociado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>//para linux
#include "funciones.h"
#define REINTENTOS 3
int uno_initStruct(Asociado* socios, int limite)
{
    int retorno = -1;
    int i;
    if (socios!=NULL && limite>0)
    {
        for (i = 0; i < limite; i++)
        {
            socios[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}

int uno_findEmpty (Asociado* socios,int limite, int* resultado)
{
    int retorno=-1;
    int i;

    for (i=0;i<limite;i++)
    {
        if (socios[i].isEmpty==1)
        {
            *resultado=i;
            retorno=0;
            break;
        }
        //retorno = 1;
    }
    return retorno;
}

int uno_alta(Asociado* socios,int lugarVacio,int id, int limite)
{
    int retorno=-1;
    __fpurge(stdin);//fflush(stdin);
    if (getName("\nIngrese nombre: \n","Error, nombre no valido.\n",3,30,REINTENTOS,socios[lugarVacio].nombre)==0 &&
        getApellido("\nIngrese apellido: \n","Error, apellido no valido.\n",3,30,REINTENTOS,socios[lugarVacio].apellido)==0 &&
        getDni("\nIngrese dni: \n","Error, dni no valido.\n",7,9,REINTENTOS,socios[lugarVacio].dni)==0&&
        getInt("\nIngrese edad: \n","Error, edad no valida.-Mayor de 18-\n",18,150,REINTENTOS,&socios[lugarVacio].edad)==0)
    {
       socios[lugarVacio].idAsociado=id;
       socios[lugarVacio].isEmpty=0;
       retorno=0;
    }
    else
        {
            retorno=1;
        }
    return retorno;
}

void uno_print(Asociado* socios, int limite)
{
    int i;

    printf ("\n*** Lista ***\n");

    for (i=0;i<limite;i++)
    {
        if (socios[i].isEmpty==0)
        {
            printf ("\n********************************************");
            printf ("\nNombre del asociado: %s \n",socios[i].nombre);
            printf ("\nApellido del asociado: %s \n",socios[i].apellido);
            printf ("\nDni del asociado: %s \n",socios[i].dni);
            printf ("\nEdad del asociado: %d \n",socios[i].edad);
            printf ("\nId del asociado: %d \n",socios[i].idAsociado);
            printf ("\nPosicion: %d \n",i);
            printf ("\nEstado : %d \n",socios[i].isEmpty);
        }
    }
}

int uno_baja(Asociado* socios,int limite)
{
    int posicion;
    int retorno=-1;

    switch (uno_findById("\nIngrese el id del asociado a dar de baja: \n",socios,&posicion,limite))
    {
        case 0:
        if (socios[posicion].isEmpty==0)
        {
            socios[posicion].isEmpty=2;
            printf ("Se borro: %d \n",socios[posicion].idAsociado);
            retorno=0;
        }
        break;
        case 1:
            printf ("No se encontro el id y no entro al if.\n");
            break;
        default:
            printf ("Ingreso al if pero no encontro el id.\n");
            break;
    }
    return retorno;
}
int uno_getId(char*msj,Asociado* socios,int limite)
{
    int i;
    int retorno=-1;
    Asociado auxSocio;

    if (getInt(msj,"\nOpcion no valida.\n",0,limite,REINTENTOS,&auxSocio.idAsociado)==0)
    {
        for (i=0;i<limite;i++)
        {
            if (socios[i].idAsociado == auxSocio.idAsociado)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int uno_findById(char* msj,Asociado* socios,int* idEncontrado, int limite)
{
    int i;
    int retorno=1;
    Asociado auxSocio;
    //revisar limite aca abajo
    if (getInt(msj,"\nOpcion no valida.\n",0,limite,REINTENTOS,&auxSocio.idAsociado)==0)
    {
        for (i=0;i<limite;i++)
        {
            if (socios[i].idAsociado == auxSocio.idAsociado)
            {
                retorno=0;
                *idEncontrado=i;
                break;
            }
        }
    }
    return retorno;
}

int uno_modificar(char* msj,Asociado* socios,int limite)
{
    int retorno=-1;
    int posicion;
    int opcion;
    /*char auxNombre;
    char auxApellido;
    char auxDni;*/
    int auxEdad;

    if (msj!=NULL && socios!=NULL && limite>0)
    {
        posicion=uno_getId(msj,socios,limite);
        if (posicion!=-1)
        {
            while (opcion!=5)
            {
                getInt("1-Modificar nombre. \n2-Modificar apellido.\n3-Modificar dni.\n4-Modificar edad.\n"
                "5-Salir de modificacion.\n","Opcion no valida\n",1,5,REINTENTOS,&opcion);
                //system("cls");//
                system("clear");
                //fflush(stdin);//
                __fpurge(stdin);
                switch(opcion)
                {
                    case 1:
                    if (getName("Ingrese nuevo nombre: \n","Nombre no valido.\n",3,25,REINTENTOS,socios[posicion].nombre)==0)
                    {
                        //strncpy(socios[posicion].nombre,&auxNombre,sizeof(socios[posicion].nombre));
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                    break;

                    case 2:
                    if (getApellido("Ingrese nuevo apellido: \n","Error, apellido no valido.\n",2,25,REINTENTOS,socios[posicion].apellido)==0)
                    {
                        //strncpy(socios[posicion].apellido,&auxApellido,sizeof(auxApellido));
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                        break;

                    case 3:
                    if (getDni("Ingrese nuevo dni: \n","Error, dni no valido.\n",7,9,REINTENTOS,socios[posicion].dni)==0)
                    {
                        //strncpy(socios[posicion].dni,&auxDni,sizeof(auxDni));
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                    break;

                    case 4:
                    if(getInt("Ingrese nueva edad: \n","Error, edad no valida.\n",18,150,REINTENTOS,&auxEdad)==0)
                    {
                        socios[posicion].edad=auxEdad;
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                    break;

                    case 5:
                    break;
                }//fin switch
            }
            retorno=0;//fin while
        }else{
                printf("No se encontro el id.\n");
            }
    }
    return retorno;
}
#endif // ASOCIADO_C_INCLUDED
