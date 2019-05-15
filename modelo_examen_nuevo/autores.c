#ifndef AUTORES_C_INCLUDED
#define AUTORES_C_INCLUDED
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
int informar (Autores* list,int length)
{
   int retorno=-1;
   char seguir='s';


    while(seguir=='s')
    {
        switch(utn_getInSimple("Ingrese una opcion a Informar\n1- Listado Ordenado por Apellido y Sector: \n2- Salario Total y Promedio: \n3- Salir\n"))
        {
            case 1:
                sortAutores(list, length);
                printAutores(list,length);
            break;

            case 2:
                emp_promedio(list, length);
            break;

            case 3:
                retorno=0;
                seguir= 'n';
            break;
        }
    }

    return retorno;
}

int aut_promedio (Autores* list, int length)
{
    int i;
    int retorno = -1;
    float acumuladorSalary=0;
    int contadorEmpleados=-1;
    int contadorEmpleadosQueSuperan=0;
    float promedio;

    if(list != NULL && length > 0)
    {
        for(i=0; i<=length; i++)
        {
            if(list[i].isEmpty == 0)
            {
                acumuladorSalary += list[i].salary;
                contadorEmpleados++;
            }
        }
        promedio = acumuladorSalary / contadorEmpleados;
        for(i=0; i<=length; i++)
        {
            if(list[i].salary >promedio)
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
int aut_empty (Autores *list, int length,int *id)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        if(list[i].isEmpty==0)
        {
             retorno=0;
            break;
        }
        else
        {
            printf("No hay Autores cargados\n");
            break;
        }
    }
    return retorno;
}

int aut_inicializar(Autores* list, int length)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        list[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

int aut_alta(Autores* list, char *msgError,int length, int posLibre)
{
    char bufferName [51];
    char bufferLastName [51];
    int retorno=-1;

    if(!aut_lugarLibre(list,length,&posLibre))
    {
        if(!utn_getName("Nombre:\n","Invalido, reingrese:\n",2,20,2,bufferName))
        {
            if(!utn_getName("Apellido:\n","Invalido, reingrese:\n",2,20,2,bufferLastName))
            {
                strncpy( list[posLibre].apellido,bufferLastName,sizeof(bufferLastName));
                strncpy( list[posLibre].nombre,bufferName,sizeof(bufferName));
                list[posLibre].codigoAutor=generarId();
                list[posLibre].isEmpty=0;
                retorno=0;
            }
        }
    }
    else
    {
        printf("\nNo hay lugar para realizar una nueva Alta.\n\n");
    }
    return retorno;
}

int aut_lugarLibre (Autores* list, int length, int *posLibre)
{
    int retorno=-1;
    int i;
    for(i=0; i<length;i++)
    {
        if(list[i].isEmpty==1)
        {
            *posLibre=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

int aut_modificar (Autores* list, int length,int*id)
{
    int retorno=-1;
    char bufferName [51];
    char bufferLastName [51];
    int bufferId;

    char seguir='s';
    while(seguir=='s')
    {
        if(aut_buscarPorId(list,"\nIngrese Id a modificar\n", "Error id invalido\n",length,&bufferId)==0)
        {
            switch(utn_getInSimple("\nMENU DE MODIFICACION\nIngrese opcion a modificar \n1- Nombre - \n2- Apellido - \n3- Salir \n"))
            {
                case 1:
                    if(!utn_getName("Ingrese nombre:\n","Invalido, reingrese:\n",2,20,2,bufferName))
                    {
                        strncpy(list[bufferId].nombre,bufferName,sizeof(bufferName));
                        printf("Nombre modificado correctamente.\n");
                    }
                break;

                case 2:
                    if(!utn_getName("Ingrese Apellido:\n","Invalido, reingrese:\n",2,20,2,bufferLastName))
                        {
                        strncpy(list[bufferId].apellido,bufferLastName,sizeof(bufferLastName));
                        printf("Apellido modificado correctamente.\n");
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

int aut_buscarPorId (Autores* list,char *msg,char *msgError, int length, int *id)
{
    int retorno=-1;
    int i;
    utn_getInt(msg,msgError,1,3,2,id);
    for(i=0; i<length; i++)
    {
        if (list[i].codigoAutor==*id)
        {
            retorno=0;
            *id=i;
             break;
        }
    }

    return retorno;
}

int aut_baja (Autores* list, int length)
{
    int buffer;
    int retorno=-1;

    aut_mostrar(list,length);

    if(aut_buscarPorId(list,"\nIngrese Id a dar de baja\n","\nId incorrecto\n",length,&buffer)==0)
    {
        list[buffer].isEmpty=2;
        retorno=0;
    }
    else
    {
        printf("\nId no encontrado\n");
    }
    return retorno;
}

int aut_mostrar(Autores* list, int length)
{
    int i;
    int retorno=-1;
    for (i=0; i<length; i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("\nId: %d", list[i].codigoAutor);
            printf("\nNombre: %s", list[i].nombre);
            printf("\nApellido: %s", list[i].apellido);
            retorno=0;
        }
    }
    return retorno;
}

int aut_ordenar (Autores* list,int length)
{
    int j;
    int flag;
    Autores buffer;
    int retorno=-1;
    int A;

    do
    {
        flag=0;
        for(j=0;j<length-1;j++)
        {
            A = strncmp(list[j].apellido,list[j+1].apellido,length);
            if(A>0)
            {
                buffer=list[j];
                list[j]=list[j+1];
                list[j+1]=buffer;
                flag=1;
                break;

                for(j=0;j<length-1;j++)
                {

                    if(list[j].nombre>list[j+1].nombre)
                    {
                    buffer=list[j];
                    list[j]=list[j+1];
                    list[j+1]=buffer;
                    flag=1;
                    break;
                    }
                }

            }
        }
    }while(flag);
    return retorno;
}

/** \brief La funcion muestra los datos hardcodeados.
 *
 * \param la estructura
 * \param el tamaño y el id para contar.
 * \return no retorna nada.
 *
 */

void aut_mock(Autores* list, int length,int *contadorId)
{

    list[0].codigoAutor =0;
    list[0].isEmpty=0;
    strcpy(list[0].apellido,"CCCCC");
    strcpy(list[0].nombre,"CCCCC");
    *contadorId++;

    list[1].codigoAutor=1;
    list[1].isEmpty=0;
    strcpy(list[1].apellido,"AAAAA");
    strcpy(list[1].nombre,"AAAAA");
    *contadorId++;

    list[2].codigoAutor=2;
    list[2].isEmpty=0;
    strcpy(list[2].apellido,"BBBBB");
    strcpy(list[2].nombre,"BBBBBB");
    *contadorId++;

    list[3].codigoAutor=3;
    list[3].isEmpty=0;
    strcpy(list[3].apellido,"BBBBB");
    strcpy(list[3].nombre,"BBBBBB");
    *contadorId++;


}



#endif // AUTORES_C_INCLUDED
