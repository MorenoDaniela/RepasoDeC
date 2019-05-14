#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>
#include "funciones.h"

int main()
{
    char cuit[20];
    int dia;
    int mes;
    int anio;

    utn_getCUIT("Ingrese CUIT: ","Error.",3,cuit);
    getFecha("Ingrese fecha: ","error.",1,2019,3,&mes,&dia,&anio);
    printf ("El cuit ingresado es: %s",cuit);
    printf ("La fecha ingresado es: %d/%d/%d",dia,mes,anio);
    return 0;
}
