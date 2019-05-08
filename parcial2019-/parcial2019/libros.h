#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idAutor;
    int idLibro;
    char titulo;
    int isEmpty;
}Libros;

int dos_initStruct(Libros* books, int limite);
int dos_findEmpty (Libros* books,int limite, int* resultado);

#endif // LIBROS_H_INCLUDED
