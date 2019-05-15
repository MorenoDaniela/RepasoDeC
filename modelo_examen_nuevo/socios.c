#ifndef SOCIOS_C_INCLUDED
#define SOCIOS_C_INCLUDED
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

/** \brief  Genera Id.
 *
 * \param   No recibe nada
 * \param
 * \return  int, creciente.
 *
 */
static int generarId(void)
{
    static int id=1;
    return id++;
}

/*
int informar (Socios* list3,int length)
{
   int retorno=-1;
   char seguir='s';


    while(seguir=='s')
    {
        switch(utn_getInSimple("Ingrese una opcion a Informar\n1- Listado Ordenado por Apellido y Sector: \n2- Salario Total y Promedio: \n3- Salir\n"))
        {
            case 1:
                sortSocios(list3, length);
                printSocios(list3,length);
            break;

            case 2:
                emp_promedio(list3, length);
            break;

            case 3:
                retorno=0;
                seguir= 'n';
            break;
        }
    }

    return retorno;
}

int soc_promedio (Socios* list3, int length)
{
    int i;
    int retorno = -1;
    float acumuladorSalary=0;
    int contadorEmpleados=-1;
    int contadorEmpleadosQueSuperan=0;
    float promedio;

    if(list3 != NULL && length > 0)
    {
        for(i=0; i<=length; i++)
        {
            if(list3[i].isEmpty == 0)
            {
                acumuladorSalary += list3[i].salary;
                contadorEmpleados++;
            }
        }
        promedio = acumuladorSalary / contadorEmpleados;
        for(i=0; i<=length; i++)
        {
            if(list3[i].salary >promedio)
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

/** \brief  Busca si una estructura esta vacia o no.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si pudo dar de baja, -1 si no pudo.
 *
 */
int soc_empty (Socios *list3, int length,int *id)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        if(list3[i].isEmpty==0)
        {
             retorno=0;
            break;
        }
        else
        {
            printf("No hay Socios cargados\n");
            break;
        }
    }
    return retorno;
}

/** \brief  Inicializa todos los campos en 1.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si pudo. -1 si no pudo.
 *
 */
int soc_inicializar(Socios* list3, int length)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        list3[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

/** \brief  Da de Alta.
 *
 * \param   Recibe la Estructura
 * \param   Mensaje de Error
 * \param   Tamaño de la misma
 * \param   Posicion donde va a guardar.
 * \return  0 si pudo dar de alta, -1 si no pudo.
 *
 */
int soc_alta(Socios* list3, char *msgError,int length, int posLibre)
{
    char bufferName [51];
    char bufferLastName [51];
    char bufferSexo;
    char bufferTel [20];
    char bufferMail [30];
    char bufferFecha [30];
    int retorno=-1;

    if(!soc_lugarLibre(list3,length,&posLibre))
    {
        if(!utn_getName("Nombre:\n","Invalido, reingrese:\n",2,20,2,bufferName))
        {
            if(!utn_getName("Apellido:\n","Invalido, reingrese:\n",2,20,2,bufferLastName))
            {
                if(!utn_getSex("Sexo:\n","Invalido, reingrese:\n",1,1,2,&bufferSexo))
                {
                    if(!utn_getTelefono("Telefono:\n","Invalido, reingrese:\n",8,20,2,bufferTel))
                    {
                       if(!utn_getMail("Mail:\n","Invalido, reingrese:\n",8,30,2,bufferMail))
                       {
                            if(!utn_fechaNacimiento("Fecha de Nacimiento dd-mm-aaaa sin guiones por favor:\n","Invalido, reingrese:\n",8,15,2,bufferFecha))
                            {
                                strncpy(list3[posLibre].nombre,bufferName,sizeof(bufferName));
                                strncpy(list3[posLibre].apellido,bufferLastName,sizeof(bufferLastName));
                                list3[posLibre].sexo=bufferSexo;
                                strncpy(list3[posLibre].telefono,bufferTel,sizeof(bufferTel));
                                strncpy(list3[posLibre].mail,bufferMail,sizeof(bufferMail));
                                strncpy(list3[posLibre].fechaAsociado,bufferFecha,sizeof(bufferFecha));
                                list3[posLibre].codigoSocio=generarId();
                                list3[posLibre].isEmpty=0;
                                retorno=0;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        printf("\nNo hay lugar para realizar una nueva Alta.\n\n");
    }
    return retorno;
}

/** \brief  Buscar lugar libre.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \param   int donde guarda el indice de la posicion libre
 * \return  0 encontro lugar libre, -1 si no.
 *
 */
int soc_lugarLibre (Socios* list3, int length, int *posLibre)
{
    int retorno=-1;
    int i;
    for(i=0; i<length;i++)
    {
        if(list3[i].isEmpty==1)
        {
            *posLibre=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

/** \brief  Modifica el campo solicitado.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \param   El id a buscar
 * \return  0 si pudo modificar, -1 si no pudo.
 *
 */
int soc_modificar (Socios* list3, int length,int*id)
{
    int retorno=-1;
    char bufferName [51];
    char bufferLastName [51];
    int bufferId;

    char seguir='s';
    while(seguir=='s')
    {
        if(soc_buscarPorId(list3,"\nIngrese Id a modificar\n", "Error id invalido\n",length,&bufferId)==0)
        {
            switch(utn_getInSimple("\nMENU DE MODIFICACION\nIngrese opcion a modificar \n1- Nombre - \n2- Apellido - \n3- Salir \n"))
            {
                case 1:
                    if(!utn_getName("Ingrese nombre:\n","Invalido, reingrese:\n",2,20,2,bufferName))
                    {
                        strncpy(list3[bufferId].nombre,bufferName,sizeof(bufferName));
                        printf("Nombre modificado correctamente.\n");
                    }
                break;

                case 2:
                    if(!utn_getName("Ingrese Apellido:\n","Invalido, reingrese:\n",2,20,2,bufferLastName))
                        {
                        strncpy(list3[bufferId].apellido,bufferLastName,sizeof(bufferLastName));
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

/** \brief  Busca por Id el campo solicitado.
 *
 * \param   Recibe la Estructura
 * \param   Mensaje
 * \param   Mensaje de Error
 * \param   Tamaño de la misma
 * \param   Id a buscar
 * \return  0 si lo encontro, -1 si no.
 *
 */
int soc_buscarPorId (Socios* list3,char *msg,char *msgError, int length, int *id)
{
    int retorno=-1;
    int i;
    utn_getInt(msg,msgError,1,3,2,id);
    for(i=0; i<length; i++)
    {
        if (list3[i].codigoSocio==*id)
        {
            retorno=0;
            *id=i;
             break;
        }
    }

    return retorno;
}

/** \brief  Da de baja el campo solicitado.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si pudo dar de baja, -1 si no pudo.
 *
 */
int soc_baja (Socios* list3, int length)
{
    int buffer;
    int retorno=-1;

    soc_mostrar(list3,length);

    if(soc_buscarPorId(list3,"\nIngrese Id a dar de baja\n","\nId incorrecto\n",length,&buffer)==0)
    {
        list3[buffer].isEmpty=2;
        retorno=0;
    }
    else
    {
        printf("\nId no encontrado\n");
    }
    return retorno;
}

/** \brief Muestra todos los campos indicados
 *
 * \param list3 Socios* Recibe la Estructura
 * \param length Tamaño de la misma
 * \return int 0 si pudo mostrar, -1 si no pudo.
 *
 */
int soc_mostrar(Socios* list3, int length)
{
    int i;
    int retorno=-1;
    for (i=0; i<length; i++)
    {
        if(list3[i].isEmpty==0)
        {
            printf("\n Codigo de socio %d",list3[i].codigoSocio);
            printf("\n Nombre %s",list3[i].nombre);
            printf("\n Apellido %s",list3[i].apellido);
            printf("\n Sexo %c",list3[i].sexo);
            printf("\ntelefono: %s", list3[i].telefono);
            printf("\n Mail %s",list3[i].mail);
            printf("\n Fecha asociado %s",list3[i].fechaAsociado);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Ordena por 2 criterios
 *
 * \param  Recibe la Estructura
 * \param El tamaño de la misma
 * \return  -1 si no pudo Ordenar, 0 Si pudo.
 *
 */
int soc_ordenar (Socios* list3,int length)
{
    int j;
    int flag;
    Socios buffer;
    int retorno=-1;
    int A;

    do
    {
        flag=0;
        for(j=0;j<length-1;j++)
        {
            A = strncmp(list3[j].apellido,list3[j+1].apellido,length);
            if(A>0)
            {
                buffer=list3[j];
                list3[j]=list3[j+1];
                list3[j+1]=buffer;
                flag=1;
                retorno=0;
                break;

                for(j=0;j<length-1;j++)
                {

                    if(list3[j].nombre>list3[j+1].nombre)
                    {
                    buffer=list3[j];
                    list3[j]=list3[j+1];
                    list3[j+1]=buffer;
                    flag=1;
                    retorno=0;
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

void soc_mock(Socios* list3, int length,int *contadorId)
{

    list3[0].codigoSocio =0;
    list3[0].isEmpty=0;
    strcpy(list3[0].apellido,"CCCCC");
    strcpy(list3[0].nombre,"CCCCC");
    list3[0].sexo='f';
    //strcpy(list3[0].sexo,"F");
    strcpy(list3[0].telefono,"CCCCC");
    strcpy(list3[0].mail,"CCCCC");
    strcpy(list3[0].fechaAsociado,"CCCCC");
    *contadorId++;

     list3[1].codigoSocio =1;
    list3[1].isEmpty=0;
    strcpy(list3[1].apellido,"CCCCC");
    strcpy(list3[1].nombre,"CCCCC");
    list3[1].sexo='f';
    // strcpy(list3[1].sexo,"M");//
    strcpy(list3[1].telefono,"CCCCC");
    strcpy(list3[1].mail,"CCCCC");
    strcpy(list3[1].fechaAsociado,"CCCCC");
    *contadorId++;

     list3[2].codigoSocio =2;
    list3[2].isEmpty=0;
    strcpy(list3[2].apellido,"CCCCC");
    strcpy(list3[2].nombre,"CCCCC");
    list3[2].sexo='m';
    //strcpy(list3[2].sexo,"M");
    strcpy(list3[2].telefono,"CCCCC");
    strcpy(list3[2].mail,"CCCCC");
    strcpy(list3[2].fechaAsociado,"CCCCC");
    *contadorId++;

    list3[3].codigoSocio =3;
    list3[3].isEmpty=0;
    strcpy(list3[3].apellido,"CCCCC");
    strcpy(list3[3].nombre,"CCCCC");
    list3[3].sexo='m';
    //strcpy(list3[3].sexo,"CCCCC");
    strcpy(list3[3].telefono,"CCCCC");
    strcpy(list3[3].mail,"CCCCC");
    strcpy(list3[3].fechaAsociado,"CCCCC");
    *contadorId++;


}




#endif // SOCIOS_C_INCLUDED
