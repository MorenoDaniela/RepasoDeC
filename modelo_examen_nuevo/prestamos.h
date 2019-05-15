#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED
#include "libros.h"
#include "socios.h"

typedef struct
{
    int codigoPrestamo; ///Id
    int codigoLibro;
    int codigoSocio;
    char fechaPrestamo[20];
    int isEmpty;

} Prestamos;

///int informar (Prestamos* list4,int length);
int pre_promedio (Prestamos* list4, int length);
int pre_empty (Prestamos *list4, int length,int *id);
int pre_inicializar(Prestamos* list4, int length);

int pre_alta(Libros* list2, Socios* list3, Prestamos* list4, char *msgError, int length, int length2, int length3, int posLibre);

int pre_lugarLibre (Prestamos* list4, int length, int *posLibre);

int pre_modificar (Libros* list2, Socios* list3, Prestamos* list4, char *msgError, int length, int length2, int length3,int*id);

int pre_buscarPorId (Prestamos* list4,char *msg,char *msgError, int length, int *id);
int pre_baja (Prestamos* list4, int length);
int pre_mostrar(Prestamos* list4, int length);
/// int pre_ordenar (Prestamos* list4,int length); no esta en uso
void pre_mock(Prestamos* list4, int length,int *contadorId);



#endif // PRESTAMOS_H_INCLUDED
