#ifndef LIBROS_C_INCLUDED
#define LIBROS_C_INCLUDED
#include "libros.h"

int dos_initStruct(Libros* books, int limite)
{
    int retorno = -1;
    int i;
    if (books!=NULL && limite>0)
    {
        for (i=0; i<limite; i++)
        {
            books[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}

int dos_findEmpty (Libros* books,int limite, int* resultado)
{
    int retorno=-1;
    int i;

    for (i=0;i<limite;i++)
    {
        if (books[i].isEmpty==0)
        {
            *resultado=i;
            retorno=0;
            break;
        }
        //retorno = 1;
    }
    return retorno;
}

#endif // LIBROS_C_INCLUDED
