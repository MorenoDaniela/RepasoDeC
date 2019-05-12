#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autor.h"
#include "libros.h"
#include "socios.h"
#include "prestamo.h"
#include "funciones.h"
#define TRIES 3
#define MAX_AUTOR 10
#define MAX_LIBRO 10
#define MAX_SOCIO 10
#define MAX_PRESTAMO 10

int main()
{
    Autor autores [MAX_AUTOR];
    Libro libros [MAX_LIBRO];
    Socio socios[MAX_SOCIO];
    Prestamo prestamos[MAX_PRESTAMO];
    int opcion;
    int flag=0;
    int flagLibros=0;
    int flagSocios=0;
    int flagPrestamo=0;
    int opcionAutores;
    int opcionLibros;
    int opcionSocios;
    int opcionPrestamos;
    int idAutor=0;
    int idLibro=0;
    int idSocio=0;
    int idPrestamo=0;

    uno_initStruct(autores,MAX_AUTOR);
    dos_initStruct(libros,MAX_LIBRO);
    tres_initStruct(socios,MAX_SOCIO);
    cuatro_initStruct(prestamos,MAX_PRESTAMO);

    harcodearAutores(autores,MAX_AUTOR);
    harcodearLibros(libros,MAX_LIBRO);
    harcodearSocios(socios,MAX_SOCIO);
    //harcodearPrestamos(prestamos,MAX_PRESTAMOS);

    flag=1;
    flagLibros=1;
    flagSocios=1;
    //flagPrestamo=1;

    while(opcion!=5)
    {
        getInt("\n**MENU**\n1-Autores.\n2-Libros.\n3-Socios.\n4-Prestamos.\n5-Salir.\n","\nError, opcion invalida.\n",1,5,TRIES,&opcion);
        system("cls");//system("clear");
        switch(opcion)
        {
        case 1:
            while (opcionAutores!=5)
            {
                getInt("\n AUTORES.\n1-Alta.\n2-Modificar.\n3-Baja.\n4-Listar.\n5-Salir.\n","Error, opcion incorrecta.\n",1,5,TRIES,&opcionAutores);
                system("cls");
                fflush(stdin);
                switch (opcionAutores)
                {
                case 1:
                    if (uno_alta(autores,&idAutor,MAX_AUTOR)==0)
                    {
                        flag=1;
                    }
                    break;
                case 2:
                    if (flag==1)
                    {
                        uno_modificar(autores,MAX_AUTOR);
                    }
                    break;
                case 3:
                    if(flag==1)
                    {
                        uno_baja(autores,MAX_AUTOR);
                    }
                    break;
                case 4:
                    if (flag==1)
                    {
                        uno_ordenarDobleCadena(autores,MAX_AUTOR);
                        uno_print(autores,MAX_AUTOR);
                    }
                    break;
                case 5:
                    break;
                }
            }
            break;
        case 2:
            while (opcionLibros!=5)
            {
                getInt("\n LIBROS.\n1-Alta.\n2-Modificar.\n3-Baja.\n4-Listar.\n5-Salir.\n","Error, opcion incorrecta.\n",1,5,TRIES,&opcionLibros);
                system("cls");
                switch (opcionLibros)
                {
                case 1:
                    if(dos_alta(libros,autores,&idLibro,MAX_AUTOR,MAX_SOCIO)==0)
                    {
                        flagLibros=1;
                    }
                    break;
                case 2:
                    if (flagLibros==1)
                    {
                        dos_print(libros,MAX_LIBRO);
                        dos_modificar(libros,autores,MAX_AUTOR,MAX_LIBRO);
                    }
                    break;
                case 3:
                    if (flagLibros==1)
                    {
                        dos_baja(libros,MAX_LIBRO);
                    }
                    break;
                case 4:
                    if (flagLibros==1)
                    {
                        dos_ordenarTitulo(libros,MAX_LIBRO);
                        dos_print(libros,MAX_LIBRO);
                    }
                    break;
                case 5:
                    break;
                }
            }
            break;
        case 3:
            while (opcionSocios!=5)
            {
                getInt("\n SOCIOS.\n1-Alta.\n2-Modificar.\n3-Baja.\n4-Listar.\n5-Salir.\n","Error, opcion incorrecta.\n",1,5,TRIES,&opcionSocios);
                system("cls");
                switch (opcionSocios)
                {
                case 1:
                    if(tres_alta(socios,&idSocio,MAX_SOCIO)==0)
                    {
                        flagSocios=1;
                    }
                    break;
                case 2:
                    if (flagSocios==1)
                    {
                        tres_print(socios,MAX_SOCIO);
                        tres_modificar(socios,MAX_SOCIO);
                    }
                    break;
                case 3:
                    if (flagSocios==1)
                    {
                        tres_baja(socios,MAX_SOCIO);
                    }
                    break;
                case 4:
                    if (flagSocios==1)
                    {
                        tres_ordenarDobleCadena(socios,MAX_SOCIO);
                        tres_print(socios,MAX_SOCIO);
                    }
                    break;
                case 5:
                    break;
                }
            }
            break;
        case 4:
            while (opcionPrestamos!=3)
            {
                getInt("\n PRESTAMOS.\n1-Alta.\n2-Listar.\n3-Salir.\n","Error, opcion incorrecta.\n",1,3,TRIES,&opcionPrestamos);
                system("cls");
                fflush(stdin);
                switch (opcionPrestamos)
                {
                case 1:
                    if (cuatro_alta(prestamos,libros,socios,&idPrestamo,MAX_PRESTAMO,MAX_LIBRO,MAX_SOCIO)==0)
                    {
                        flagPrestamo=1;
                    }
                    break;
                case 2:
                    if (flagPrestamo==1)
                    {
                        //cuatro_ordenarDobleCadena(prestamos,MAX_PRESTAMO);
                        cuatro_print(prestamos,MAX_PRESTAMO);
                    }
                    break;
                case 3:
                    break;
                }
            }
            break;
            break;
        case 5:
            break;
        }
    }
    return 0;
}
