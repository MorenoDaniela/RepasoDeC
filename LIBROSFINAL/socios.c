#ifndef SOCIOS_C_INCLUDED
#define SOCIOS_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socios.h"
//#include <stdio_ext.h>//para linux
#include "funciones.h"
#define TRIES 3

int tres_initStruct(Socio* arrayS, int limite)
{
    int retorno = -1;
    int i;
    if (arrayS!=NULL && limite>0)
    {
        for (i = 0; i < limite; i++)
        {
            arrayS[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}

int tres_findEmpty (Socio* arrayS,int limite, int* resultado)
{
    int retorno=-1;
    int i;

    if (arrayS!=NULL && limite>=0 && resultado!=NULL)
    {
        for (i=0;i<=limite;i++)
        {
            if (arrayS[i].isEmpty==1)
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

int tres_alta(Socio* arrayS,int *id, int limite)
{
    int retorno=-1;
    int lugarVacio;
    char auxSexo;
    //char letra;
    //__fpurge(stdin);
    fflush(stdin);

    if (limite>0 && id!=NULL )
    {
        if(tres_findEmpty(arrayS,limite,&lugarVacio)!=-1)
        {
            if (getName("\nIngrese nombre del socio: \n","Error, nombre no valido.\n",3,32,TRIES,arrayS[lugarVacio].nombre)==0 &&
                getApellido("\nIngrese apellido del socio: \n","Error, apellido no valido.\n",3,32,TRIES,arrayS[lugarVacio].apellido)==0 &&
                getSex("\nIngrese sexo (M=masculino F=femenino) : \n","Error, sexo no valido.\n",'f','m',TRIES,&auxSexo)==0 &&
                getTelefono("\nIngrese telefono: \n","Error, telefono no valido\n",8,11,TRIES,arrayS[lugarVacio].telefono)==0 &&
                getEmail("\nIngrese mail: ","Error, mail no valido.\n",10,32,TRIES,arrayS[lugarVacio].email)==0)
            {

                arrayS[lugarVacio].sexo=auxSexo;
                arrayS[lugarVacio].idSocio=*id;
                (*id)++;
                arrayS[lugarVacio].isEmpty=0;
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

void tres_print(Socio* arrayS, int limite)
{
    int i;

    for (i=0;i<=limite;i++)
    {
        if (arrayS[i].isEmpty==0)
        {
            printf ("\n*** Lista ***\n");
            printf ("\n********************************************");
            printf ("\nNombre del socio: %s ",arrayS[i].nombre);
            printf ("\nApellido del socio: %s ",arrayS[i].apellido);
            printf ("\nSexo: %c",arrayS[i].sexo);
            printf ("\nId del socio: %d ",arrayS[i].idSocio);
            //printf ("\nPosicion: %d ",i);
            printf ("\nTelefono: %s",arrayS[i].telefono);
            printf ("\nEmail: %s",arrayS[i].email);
            //printf ("\nEstado : %d \n",arrayS[i].isEmpty);
        }
    }
}

int tres_baja(Socio* arrayS,int limite)
{
    int posicion;
    int retorno=-1;
    if (arrayS!=NULL && limite>0)
    {
        tres_print(arrayS,limite);
        switch (tres_findById("\nIngrese el id del socio a dar de baja: \n",arrayS,&posicion,limite))
        {
            case 0:
            if (arrayS[posicion].isEmpty==0)
            {
                arrayS[posicion].isEmpty=1;
                printf ("\nSe borro el id: %d \n",arrayS[posicion].idSocio);
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
int tres_getId(char*msj,Socio* arrayS,int limite)
{
    int i;
    int retorno=-1;
    Socio auxSocio;

    if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxSocio.idSocio)==0)
    {
        for (i=0;i<=limite;i++)
        {
            if (arrayS[i].idSocio == auxSocio.idSocio)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int tres_findById(char* msj,Socio* arrayS,int* idEncontrado, int limite)
{
    int i;
    int retorno=1;
    int auxSocio;
    //revisar limite aca abajo
    if (msj!=NULL && arrayS !=NULL && idEncontrado!=NULL && limite>0)
    {
        if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxSocio)==0)
        {
            for (i=0;i<=limite;i++)
            {
                if (arrayS[i].isEmpty==0)
                {
                    if (arrayS[i].idSocio == auxSocio)
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

int tres_modificar(Socio* arrayS,int limite)
{
    int retorno=-1;
    int posicion;
    int opcion;
    char auxSexo;
    /*char auxNombre;
    char auxApellido;
    char auxDni;
    int auxEdad;*/

    if (arrayS!=NULL && limite>0)
    {
        tres_print(arrayS,limite);
        //tres_findById("Ingrese el id del autor a modificar",arrayS,&posicion,limite);
        //posicion=tres_getId(msj,arrayS,limite);
        if (tres_findById("Ingrese el id del socio a modificar: \n",arrayS,&posicion,limite)==0)
        {
            do
            {
                getInt("\n1-Modificar nombre. \n2-Modificar apellido.\n3-Modificar sexo.\n4-Modificar mail.\n"
                       "5-Modificar telefono.\n6-Salir de modificacion.\n","Opcion no valida\n",1,6,TRIES,&opcion);
                system("cls");//
                //system("clear");
                fflush(stdin);
                //__fpurge(stdin);
                switch(opcion)
                {
                    case 1:
                    if (getName("Ingrese nuevo nombre: \n","Nombre no valido.\n",3,31,TRIES,arrayS[posicion].nombre)==0)
                    {
                        //strncpy(arrayS[posicion].nombre,&auxNombre,sizeof(arrayS[posicion].nombre));
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                    break;

                    case 2:
                    if (getApellido("Ingrese nuevo apellido: \n","Error, apellido no valido.\n",2,31,TRIES,arrayS[posicion].apellido)==0)
                    {
                        //strncpy(arrayS[posicion].apellido,&auxApellido,sizeof(auxApellido));
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                        break;
                    case 3:
                    if (getSex("Ingrese nuevo sexo (1-masculino, 2=femenino : \n","Error, sexo no valido.\n",1,2,TRIES,&auxSexo)==0)
                    {
                        arrayS[posicion].sexo=auxSexo;
                        //strncpy(arrayS[posicion].apellido,&auxApellido,sizeof(auxApellido));
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                        break;
                    case 4:
                    if (getEmail("Ingrese nuevo email: \n","Error, email no valido.\n",2,31,TRIES,arrayS[posicion].email)==0)
                    {
                    //strncpy(arrayS[posicion].apellido,&auxApellido,sizeof(auxApellido));
                    printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                        break;
                    case 5:
                    if (getTelefono("Ingrese nuevo telefono: \n","Error, telefono no valido.\n",8,12,TRIES,arrayS[posicion].telefono)==0)
                    {
                    //strncpy(arrayS[posicion].apellido,&auxApellido,sizeof(auxApellido));
                    printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                        break;
                    case 6:
                        break;
                }//fin switch
            }while (opcion!=6);
            retorno=0;//fin while
        }else
            printf("\nNo se encontro el id.\n");
    }
    return retorno;
}

int tres_ordenarDobleCadena(Socio* arrayS,int limite)
{
    int i;
    Socio buffer;
    int retorno=-1;

    if (arrayS!=NULL && limite>0)
    {
        for (i=0;i<=limite-1;i++)
        {
            if (arrayS[i].isEmpty==1 || arrayS[i+1].isEmpty==1)
            {
                continue;
            }
                if (strncmp(arrayS[i].apellido,arrayS[i+1].apellido,31)>0)
                {
                    buffer = arrayS[i];
                    arrayS[i]= arrayS[i+1];
                    arrayS[i+1]=buffer;
                }
                    else if(strncmp(arrayS[i].apellido,arrayS[i+1].apellido,31)==0)
                    {
                        if (strncmp(arrayS[i].nombre, arrayS[i+1].nombre,31)>0)
                        {
                            buffer= arrayS[i];
                            arrayS[i]=arrayS[i+1];
                            arrayS[i+1]=buffer;
                        }
                    }
        }
        retorno=0;
    }
    return retorno;
}

void harcodearSocios(Socio* arrayS, int limite)
{
    strcpy(arrayS[0].nombre,"BBB");
    strcpy(arrayS[0].apellido,"DDD");
    arrayS[0].sexo='f';
    //strcpy(arrayS[0].sexo,"f");
    strcpy(arrayS[0].email,"pepe_pepe@hotmail.com");
    strcpy(arrayS[0].telefono,"11-45213652");
    arrayS[0].isEmpty=0;
    arrayS[0].idSocio=1;

    strcpy(arrayS[1].nombre,"AAA");
    strcpy(arrayS[1].apellido,"MMM");
    arrayS[0].sexo='m';
    //strcpy(arrayS[1].sexo,"m");
    strcpy(arrayS[1].email,"ariel_pepe@gmail.com");
    strcpy(arrayS[1].telefono,"4293-7778");
    arrayS[1].isEmpty=0;
    arrayS[1].idSocio=3;

    strcpy(arrayS[2].nombre,"BBB");
    strcpy(arrayS[2].apellido,"FFFF");
    arrayS[0].sexo='f';
    //strcpy(arrayS[2].sexo,"f");
    strcpy(arrayS[2].email,"julian_pepe@hotmail.com");
    strcpy(arrayS[2].telefono,"42-25411778");
    arrayS[2].isEmpty=0;
    arrayS[2].idSocio=0;

    strcpy(arrayS[3].nombre,"BBB");
    strcpy(arrayS[3].apellido,"AAA");
    arrayS[0].sexo='m';
    //strcpy(arrayS[3].sexo,"m");
    strcpy(arrayS[3].email,"marina_pepe@hotmail.com");
    strcpy(arrayS[3].telefono,"41-11452778");
    arrayS[3].isEmpty=0;
    arrayS[3].idSocio=2;


}

#endif // SOCIOS_C_INCLUDED
