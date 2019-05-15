#ifndef PRESTAMOS_C_INCLUDED
#define PRESTAMOS_C_INCLUDED
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
int informar (Prestamos* list4,int length)
{
   int retorno=-1;
   char seguir='s';


    while(seguir=='s')
    {
        switch(utn_getInSimple("Ingrese una opcion a Informar\n1- Listado Ordenado por Apellido y Sector: \n2- Salario Total y Promedio: \n3- Salir\n"))
        {
            case 1:
                sortPrestamos(list4, length);
                printPrestamos(list4,length);
            break;

            case 2:
                emp_promedio(list4, length);
            break;

            case 3:
                retorno=0;
                seguir= 'n';
            break;
        }
    }

    return retorno;
}

int pre_promedio (Prestamos* list4, int length)
{
    int i;
    int retorno = -1;
    float acumuladorSalary=0;
    int contadorEmpleados=-1;
    int contadorEmpleadosQueSuperan=0;
    float promedio;

    if(list4 != NULL && length > 0)
    {
        for(i=0; i<=length; i++)
        {
            if(list4[i].isEmpty == 0)
            {
                acumuladorSalary += list4[i].salary;
                contadorEmpleados++;
            }
        }
        promedio = acumuladorSalary / contadorEmpleados;
        for(i=0; i<=length; i++)
        {
            if(list4[i].salary >promedio)
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
int pre_empty (Prestamos *list4, int length,int *id)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        if(list4[i].isEmpty==0)
        {
             retorno=0;
            break;
        }
        else
        {
            printf("No hay Prestamos cargados\n");
            break;
        }
    }
    return retorno;
}

int pre_inicializar(Prestamos* list4, int length)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        list4[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

int pre_alta(Libros* list2, Socios* list3, Prestamos* list4, char *msgError,int length, int length2, int length3, int posLibre)
{
    int retorno=-1;
    int bufferLibro;
    int bufferSocio;
    char auxFecha[20];

    if(!pre_lugarLibre(list4,length,&posLibre))
    {
        if(!lib_buscarPorId(list2,"Ingrese codigo de libro","Error",length,&bufferLibro))
        {
            if(!soc_buscarPorId(list3,"Ingrese codigo de Socio","Error",length2,&bufferSocio))
            {
                if(!utn_fechaNacimiento("Ingrese fecha:","Error",4,7,2,auxFecha))
                {
                    list4[posLibre].codigoLibro=bufferLibro;
                    list4[posLibre].codigoSocio=bufferSocio;
                    strncpy(list4[posLibre].fechaPrestamo,auxFecha,sizeof(auxFecha));
                    list4[posLibre].codigoPrestamo=generarId();
                    list4[posLibre].isEmpty=0;
                    retorno=0;
                }
            }
        }
    }
    else
    {
        printf("\nNo hay lugar para nuevo Prestamo.\n\n");
    }
    return retorno;
}

int pre_lugarLibre (Prestamos* list4, int length, int *posLibre)
{
    int retorno=-1;
    int i;
    for(i=0; i<length;i++)
    {
        if(list4[i].isEmpty==1)
        {
            *posLibre=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

int pre_modificar (Libros* list2, Socios* list3, Prestamos* list4, char *msgError,int length, int length2, int length3,int*id)
{
    int retorno=-1;
    int bufferLibro;
    int bufferSocio;
    int bufferId;
    char auxFecha[20];

    char seguir='s';
    while(seguir=='s')
    {
        if(pre_buscarPorId(list4,"\nIngrese Id de prestamos a modificar\n", "Error id invalido\n",length,&bufferId)==0)
        {
            switch(utn_getInSimple("\nMENU DE MODIFICACION\nIngrese opcion a modificar \n1- Id Socio - \n2- Id Libro - \n3- Fecha - \n4- Salir \n"))
            {
                case 1:
                    if(!soc_buscarPorId(list3,"Ingrese id a modificar"," reingrese:\n",length2,&bufferSocio))
                    {
                        list4[bufferId].codigoSocio=bufferSocio;
                        printf("Id Socio modificado correctamente.\n");
                    }
                break;

                case 2:
                    if(!lib_buscarPorId(list2,"Ingrese Id libro:\n","Invalido, reingrese:\n",length,&bufferLibro))
                        {
                            list4[bufferId].codigoLibro=bufferLibro;
                            printf("Id Libro modificado correctamente.\n");
                        }
                break;

                case 3:
                    if(!utn_fechaNacimiento("Ingrese Fecha:\n","Invalido, reingrese:\n",4,7,2,auxFecha))
                        {
                            strncpy(list4[bufferId].fechaPrestamo,auxFecha,sizeof(auxFecha));
                            printf("Fecha modificada correctamente.\n");
                        }
                break;

                case 4:
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

int pre_buscarPorId (Prestamos* list4,char *msg,char *msgError, int length, int *id)
{
    int retorno=-1;
    int i;
    utn_getInt(msg,msgError,1,3,2,id);
    for(i=0; i<length; i++)
    {
        if (list4[i].codigoPrestamo==*id)
        {
            retorno=0;
            *id=i;
             break;
        }
    }

    return retorno;
}

int pre_baja (Prestamos* list4, int length)
{
    int buffer;
    int retorno=-1;

    pre_mostrar(list4,length);

    if(pre_buscarPorId(list4,"\nIngrese Id a dar de baja\n","\nId incorrecto\n",length,&buffer)==0)
    {
        list4[buffer].isEmpty=2;
        retorno=0;
    }
    else
    {
        printf("\nId no encontrado\n");
    }
    return retorno;
}

int pre_mostrar(Prestamos* list4, int length)
{
    int i;
    int retorno=-1;
    for (i=0; i<length; i++)
    {
        if(list4[i].isEmpty==0)
        {
            printf("\nCodigo Prestamo : %d", list4[i].codigoPrestamo);
            printf("\nCodigo Socio: %d", list4[i].codigoSocio);
            printf("\nCodigo Libro: %d", list4[i].codigoLibro);
            printf("\nFecha de Prestamo: %s", list4[i].fechaPrestamo);
            retorno=0;
        }
    }
    return retorno;
}
/*
int pre_ordenar (Prestamos* list4,int length)
{
    int j;
    int flag;
    Prestamos buffer;
    int retorno=-1;
    int A;

    do
    {
        flag=0;
        for(j=0;j<length-1;j++)
        {
            A = strncmp(list4[j].codigoPrestamo,list4[j+1].codigoPrestamo,length);
            if(A>0)
            {
                buffer=list4[j];
                list4[j]=list4[j+1];
                list4[j+1]=buffer;
                flag=1;
                break;

                for(j=0;j<length-1;j++)
                {

                    if(list4[j].fechaPrestamo>list4[j+1].fechaPrestamo)
                    {
                    buffer=list4[j];
                    list4[j]=list4[j+1];
                    list4[j+1]=buffer;
                    flag=1;
                    break;
                    }
                }

            }
        }
    }while(flag);
    return retorno;
}
*/
/** \brief La funcion muestra los datos hardcodeados.
 *
 * \param la estructura
 * \param el tamaño y el id para contar.
 * \return no retorna nada.
 *
 */


void pre_mock(Prestamos* list4, int length,int *contadorId)
{

    list4[0].codigoPrestamo =0;
    list4[0].isEmpty=0;
    list4[0].codigoSocio=2;
    list4[0].codigoLibro=3;
    list4[0].codigoLibro=3;
    strcpy(list4[3].fechaPrestamo,"25011990");
    *contadorId++;

    list4[1].codigoPrestamo=1;
    list4[1].isEmpty=0;
    list4[1].codigoSocio=3;
    list4[1].codigoLibro=3;
    strcpy(list4[3].fechaPrestamo,"25031990");
    *contadorId++;

    list4[2].codigoPrestamo=2;
    list4[2].isEmpty=0;
    list4[2].codigoSocio=4;
    list4[2].codigoLibro=5;
    strcpy(list4[3].fechaPrestamo,"25021990");
    *contadorId++;

    list4[3].codigoPrestamo=3;
    list4[3].isEmpty=0;
    list4[3].codigoSocio=3;
    list4[3].codigoLibro=4;
    strcpy(list4[3].fechaPrestamo,"22021990");
    *contadorId++;

}


#endif // PRESTAMOS_C_INCLUDED
