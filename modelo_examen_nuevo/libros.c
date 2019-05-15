#ifndef LIBROS_C_INCLUDED
#define LIBROS_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prestamos.h"
#include "autores.h"
#include "libros.h"
#include "socios.h"
#include "utn.h"
#define TRUE 1
#define FALSE 0

static int generarId(void);


static int generarId(void)
{
    static int id=1;
    return id++;
}

/*
int informar (Libros* list2,int length)
{
   int retorno=-1;
   char seguir='s';


    while(seguir=='s')
    {
        switch(utn_getInSimple("Ingrese una opcion a Informar\n1- Listado Ordenado por Apellido y Sector: \n2- Salario Total y Promedio: \n3- Salir\n"))
        {
            case 1:
                sortLibros(list2, length);
                printLibros(list2,length);
            break;

            case 2:
                emp_promedio(list2, length);
            break;

            case 3:
                retorno=0;
                seguir= 'n';
            break;
        }
    }

    return retorno;
}

int lib_promedio (Libros* list2, int length)
{
    int i;
    int retorno = -1;
    float acumuladorSalary=0;
    int contadorEmpleados=-1;
    int contadorEmpleadosQueSuperan=0;
    float promedio;

    if(list2 != NULL && length > 0)
    {
        for(i=0; i<=length; i++)
        {
            if(list2[i].isEmpty == 0)
            {
                acumuladorSalary += list2[i].salary;
                contadorEmpleados++;
            }
        }
        promedio = acumuladorSalary / contadorEmpleados;
        for(i=0; i<=length; i++)
        {
            if(list2[i].salary >promedio)
            {

                contadorEmpleadosQueSuperan++;
            }
        }
        printf("El total de los salarios es: %.2f \n",acumuladorSalary);
        printf("El promedio de los Salarios es: %.2f \n",promedio);
        printf("Los empleados que superan el salario Promedio Son: %d \n",contadorEmpleadosQueSuperan);
        retorno = 0;
    }
    return retorno;
}
*/
int lib_empty (Libros *list2, int length,int *id)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        if(list2[i].isEmpty==0)
        {
             retorno=0;
            break;
        }
        else
        {
            printf("No hay libros cargados\n");
            break;
        }
    }
    return retorno;
}

int lib_inicializar(Libros* list2, int length)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        list2[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

int lib_alta(Autores* list,Libros* list2, char *msgError,int length2,int length, int posLibre)
{
    char bufferName [51];
    int bufferAutor;
    int buffer;
    int retorno=-1;

    if(aut_empty(list,length2,&buffer)==0)
    {
        if(aut_buscarPorId(list,"Ingrese codigo Autor","Error",length2,&bufferAutor)==0)
        {
            if(!lib_lugarLibre(list2,length,&posLibre))
            {
                if(!utn_getName("TiTulo:\n","Invalido, reingrese:\n",2,20,2,bufferName))
                {
                        strncpy(list2[posLibre].titulo,bufferName,sizeof(bufferName));
                        list2[posLibre].codigoLibro=generarId();
                        list2[posLibre].isEmpty=0;
                        list2[posLibre].codigoAutor=list[bufferAutor].codigoAutor;
                        retorno=0;
                }
                }
            else
            {
                printf("\nNo hay lugar para realizar una nueva Alta.\n\n");

            }
        }
        else
        {
            printf("Id no encontrado");
        }

    }
    return retorno;
}

int lib_lugarLibre (Libros* list2, int length, int *posLibre)
{
    int retorno=-1;
    int i;
    for(i=0; i<length;i++)
    {
        if(list2[i].isEmpty==1)
        {
            *posLibre=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

int lib_modificar (Autores* list, Libros* list2, int length, int length2, int*id)
{
    int retorno=-1;
    char bufferName [51];
    int bufferId;

    char seguir='s';
    while(seguir=='s')
    {
        if(lib_buscarPorId(list2,"\nIngrese Id a modificar\n", "Error id invalido\n",length2,&bufferId)==0)
        {
            switch(utn_getInSimple("\nMENU DE MODIFICACION\nIngrese opcion a modificar \n1- Titulo - \n2- Codigo De Autor - \n3- Salir \n"))
            {
                case 1:
                    if(!utn_getName("Ingrese Titulo:\n","Invalido, reingrese:\n",2,20,2,bufferName))
                    {
                        strncpy(list2[bufferId].titulo,bufferName,sizeof(bufferName));
                        printf("Titulo modificado correctamente.\n");
                    }
                break;

                case 2:
                    if(!aut_buscarPorId(list,"Ingrese Id:\n","Invalido, reingrese:\n",length,&bufferId))
                        {
                            list2[bufferId].codigoAutor=bufferId;
                            printf("Autor modificado correctamente.\n");
                        }
                break;

                case 3:
                    retorno=0;
                    seguir= 'n';
                    break;

                default:
                    printf("Opcion invalida");
                    break;
            }
        }
        else
        {
        printf("\nId no encontrado.\n\n");
        }

    }


    return retorno;
}

int lib_buscarPorId (Libros* list2,char *msg,char *msgError, int length, int *id)
{
    int retorno=-1;
    int i;
    utn_getInt(msg,msgError,1,3,2,id);
    for(i=0; i<length; i++)
    {
        if (list2[i].codigoAutor==*id)
        {
            retorno=0;
            *id=i;
             break;
        }
    }

    return retorno;
}

int lib_baja (Libros* list2, int length)
{
    int buffer;
    int retorno=-1;

    lib_mostrar(list2,length);

    if(lib_buscarPorId(list2,"\nIngrese Id a dar de baja\n","\nId incorrecto\n",length,&buffer)==0)
    {
        list2[buffer].isEmpty=2;
        retorno=0;
    }
    else
    {
        printf("\nId no encontrado\n");
    }
    return retorno;
}

int lib_mostrar(Libros* list2, int length)
{
    int i;
    int retorno=-1;
    for (i=0; i<length; i++)
    {
        if(list2[i].isEmpty==0)
        {
            printf("\nCodigo Libro: %d", list2[i].codigoLibro);
            printf("\nTitulo: %s", list2[i].titulo);
            printf("\n Codigo de Autor: %d", list2[i].codigoAutor);
            retorno=0;
        }
    }
    return retorno;
}

int lib_ordenar (Libros* list2,int length)
{
    int j;
    int flag;
    Libros buffer;
    int retorno=-1;
    int A;

    do
    {
        flag=0;
        for(j=0;j<length-1;j++)
        {
            A = strncmp(list2[j].titulo,list2[j+1].titulo,length);
            if(A>0)
            {
                buffer=list2[j];
                list2[j]=list2[j+1];
                list2[j+1]=buffer;
                flag=1;
                break;
                /*
                for(j=0;j<length-1;j++)
                {

                    if(list2[j].nombre>list2[j+1].nombre)
                    {
                    buffer=list2[j];
                    list2[j]=list2[j+1];
                    list2[j+1]=buffer;
                    flag=1;
                    break;
                    }
                }*/

            }
        }
    }while(flag);
    return retorno;
}

void lib_mock(Libros* list2, int length,int *contadorId)
{
    list2[0].codigoLibro=2;
    list2[0].isEmpty=0;
    list2[0].codigoAutor=2;
    strcpy(list2[0].titulo,"CCCCC");
    *contadorId++;

    list2[1].codigoLibro=3;
    list2[1].isEmpty=0;
    list2[1].codigoAutor=4;
    strcpy(list2[1].titulo,"AAAAA");
    *contadorId++;

    list2[2].codigoLibro=4;
    list2[2].isEmpty=0;
    list2[2].codigoAutor=2;
    strcpy(list2[2].titulo,"BBBB");
    *contadorId++;

    list2[3].codigoLibro=1;
    list2[3].isEmpty=0;
    list2[3].codigoAutor=4;
    strcpy(list2[3].titulo,"BBBBB");
    *contadorId++;

}




#endif // LIBROS_C_INCLUDED
