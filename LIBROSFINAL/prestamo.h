#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
#include "libros.h"
#include "socios.h"
typedef struct
{
    int idLibro;
    int idSocio;
    int idPrestamo;
    int dia;
    int mes;
    int anio;
    int isEmpty;//estado habilitado 0 no habilitado 1
}Prestamo;

int cuatro_initStruct(Prestamo* arrayP, int limite);
int cuatro_findEmpty (Prestamo* arrayP,int limite, int* resultado);
//int cuatro_alta(Prestamo* arrayP,int* id, int limite);
int cuatro_alta(Prestamo* arrayP, Libro* arrayL,Socio* arrayS,int *id,int limitePrestamo,int limiteLibro, int limiteSocio);
//int cuatro_alta(Prestamo* arrayP, Libro* arrayL, Socio* arrayS, int *id, int limitePrestamo, int limiteLibro, int limiteSocio);
void cuatro_print(Prestamo* arrayP, int limite);
int cuatro_findById(char* msj,Prestamo* arrayP,int* idEncontrado, int limite);
int cuatro_getId(char*msj,Prestamo* arrayP,int limite);
int cuatro_baja(Prestamo* arrayP,int limite);
//int cuatro_modificar(Prestamo* arrayP,Autor* arrayA,int limiteAutor, int limitePrestamo);
int cuatro_ordenarTitulo(Prestamo* arrayP,int limite);
//void harcodearPrestamos(Prestamo* arrayP, int limite);

#endif // PRESTAMO_H_INCLUDED
