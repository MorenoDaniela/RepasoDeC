#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autores.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"
#include "utn.h"
#define AUTOR 31 ///TAMAÑO DE NOMBRE Y APELLIDO DE AUTOR
#define LIBRO 51 ///TAMAÑO DEL TITULO DEL LIBRO
#define SOCIO 51 ///TAMAÑO DEL
#define PRESTAMO 51 ///TAMAÑO DEL

int main()
{
    char buffer[30];
    char seguir='s';
    int bufferId;
    int contadorIdfantasma=0;
    int contadorIdautor=0;

    Autores list[AUTOR];
    aut_inicializar(list,AUTOR);
    aut_mock(list,AUTOR,&bufferId);

    Libros list2[LIBRO];
    lib_inicializar(list2,LIBRO);

    Socios list3[SOCIO];
    soc_inicializar(list3,SOCIO);

    Prestamos list4[PRESTAMO];
    pre_inicializar(list4,PRESTAMO);

    while(seguir=='s')
    {
        switch(utn_getInSimple("Ingrese una opcion, Socio\n1- Alta: \n2- Modificar: \n3- Baja \n4- Socio Ordenado \n5- Libro Ordenado \n6- Autor Ordenado \n7- Alta Prestamo \n8- Salir\n"))
        {
            case 1:
                if(!soc_alta(list3,"Error",SOCIO,bufferId))
                {
                    printf("Alta Correcta\n\n");
                    soc_mostrar(list3,SOCIO);
                }
                break;

            case 2:
                if(!soc_modificar(list3,SOCIO,&bufferId))
                {
                    printf("Modificado Correcta\n\n");
                }
                break;

            case 3:
                if(!soc_baja(list3,SOCIO))
                {
                    printf("Baja Correcta\n\n");
                }
                break;

            case 4:
                if(!soc_ordenar(list3,SOCIO))
                {
                     soc_mostrar(list3,SOCIO);
                }
                break;

                case 5:
                    if(!lib_ordenar(list2,LIBRO))
                    {
                        lib_mostrar(list2,LIBRO);
                    }
                    break;

                 case 6:
                    if(!aut_mostrar(list,AUTOR))
                    {
                        aut_ordenar(list,AUTOR);

                    }
                    break;

                case 7:
                    if(!lib_empty(list2,LIBRO,&bufferId))
                    {
                        if(!pre_alta(list2,list3,list4,"Error",LIBRO,SOCIO,PRESTAMO,bufferId))
                        {
                            printf("alta exitosa");
                        }
                    }
                    break;

                case 8:
                seguir= 'n';
                break;
        }
    }

    return 0;
}
