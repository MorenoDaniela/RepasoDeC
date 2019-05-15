#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED
#include "autores.h"

typedef struct
{
    int codigoLibro;
    int codigoAutor;
    char titulo[51];
    int isEmpty;

} Libros;


///int informar (Libros* list2,int length);


int lib_promedio (Libros* list2, int length);


int lib_empty (Libros *list2, int length,int *id);


int lib_inicializar(Libros* list2, int length);


int lib_alta(Autores* list,Libros* list2, char *msgError,int length1,int length2, int posLibre);


int lib_lugarLibre (Libros* list2, int length, int *posLibre);


int lib_modificar (Autores* list, Libros* list2, int length, int length2, int*id);


int lib_buscarPorId (Libros* list2,char *msg,char *msgError, int length, int *id);


int lib_baja (Libros* list2, int length);


int lib_mostrar(Libros* list2, int length);


int lib_ordenar (Libros* list2,int length);
void lib_mock(Libros* list2, int length,int *contadorId);



#endif // LIBROS_H_INCLUDED
