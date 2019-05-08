#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

typedef struct
{
    int idPrestamo;
    int idLibro;
    int idSocio;
    char fechaPrestamo;
    int isEmpty;
}Prestamos;

#endif // PRESTAMOS_H_INCLUDED
