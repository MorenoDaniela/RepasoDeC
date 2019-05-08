#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validaciones.h"
#include "autores.h"
#include "libros.h"
#include "socios.h"
#include <stdio_ext.h>//para linux
#define MAX_AUTORES 10
#define MAX_LIBROS 10
#define MAX_SOCIOS 10
#define REINTENTOS 3
int main()
{
    int opcion=0;
    int idAutores=0;
    int idBook=0;
    int lugarVacioAutor;
    int lugarVacioLibro;
    int lugarVacioSocio;
    int flag=0;

    Autor autores [MAX_AUTORES];
    Libros books [MAX_LIBROS];

    uno_initStruct(autores,MAX_AUTORES);
    dos_initStruct(books,MAX_LIBROS);

    while(opcion!=14)
    {
        getInt("\nMENU\n1-Alta de un autor.\n2-Modificar datos de autor.\n"
        "3-Baja de autor.\n4-Listar autores.\n5-Alta de un libro.\n"
        "6-Modificar datos de un libro.\n6-Baja de un libro.\n"
        "7-Listar libros.\n8-Alta de un socio.\n9-Modificar datos de un socio.\n"
        "10-Baja de un socio.\n11-Listar socios.\n12-Alta prestamo.\n13Informes.\n14-Salir\n",
        "Error, opcion no valida.\n",1,14,REINTENTOS,&opcion);
         system("clear");

        switch (opcion)
        {
            case 1:
                if (uno_findEmpty(autores,MAX_AUTORES,&lugarVacioAutor)!=0)
                {
                    printf ("No hay espacio para dar de alta un autor.\n");
                }else
                    {
                        switch (uno_alta(autores,lugarVacioAutor,idAutores,MAX_AUTORES))
                        {
                            case 0:
                            printf ("\n****Ingreso correcto.****\n");
                            idAutores++;
                            flag=1;
                            break;
                            case 1:
                            printf("\n*****Ingreso incorrecto.*****\n");
                            break;
                        }
                    }
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
                uno_print(autores,MAX_AUTORES);
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:
            break;
            case 9:
            break;
            case 10:
            break;
            case 11:
            break;
            case 12:
            break;
            case 13:
            break;
            case 14:
            break;
        }
    }
    return 0;
}
