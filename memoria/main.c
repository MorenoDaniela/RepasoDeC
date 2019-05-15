#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#define MAX_EMPLEADO 10

int main()
{
    Empleado *pArrayEmpleado[MAX_EMPLEADO];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    int auxInt;
    float auxPeso;
    char auxNombre[50];
    int auxEstado;

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Emp_new();


    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if(!Emp_setId(pArrayEmpleado[indiceActual],14))
        {
            Emp_getId(pArrayEmpleado[indiceActual], &auxInt);
            printf("\n El id es %d",auxInt);

            if (!Emp_setPeso(pArrayEmpleado[indiceActual],55.25))
            {
                Emp_getPeso(pArrayEmpleado[indiceActual],&auxPeso);
                printf("\nEl peso es: %.2f ",auxPeso);

                if (!Emp_setNombre(pArrayEmpleado[indiceActual],"Daniel"))
                {
                    Emp_getNombre(pArrayEmpleado[indiceActual],auxNombre);
                    printf ("\nEl nombre es: %s",auxNombre);

                    if (!Emp_setEstado(pArrayEmpleado[indiceActual],0))
                    {
                        Emp_getEstado(pArrayEmpleado[indiceActual],&auxEstado);
                        printf ("\nEl estado es: %d\n",auxEstado);
                    }
                }
            }

        }

    }
////////////////////////////////////////////////////////////////
    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if(!Emp_setId(pArrayEmpleado[indiceActual],12))
        {
            Emp_getId(pArrayEmpleado[indiceActual], &auxInt);
            printf("\n El id es %d",auxInt);

            if (!Emp_setPeso(pArrayEmpleado[indiceActual],20.25))
            {
                Emp_getPeso(pArrayEmpleado[indiceActual],&auxPeso);
                printf("\nEl peso es: %.2f ",auxPeso);

                if (!Emp_setNombre(pArrayEmpleado[indiceActual],"Enrique"))
                {
                    Emp_getNombre(pArrayEmpleado[indiceActual],auxNombre);
                    printf ("\nEl nombre es: %s",auxNombre);

                    if (!Emp_setEstado(pArrayEmpleado[indiceActual],0))
                    {
                        Emp_getEstado(pArrayEmpleado[indiceActual],&auxEstado);
                        printf ("\nEl estado es: %d\n",auxEstado);
                    }
                }
            }

        }

    }
    /////////////////////////////////////////////
        if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if(!Emp_setId(pArrayEmpleado[indiceActual],10))
        {
            Emp_getId(pArrayEmpleado[indiceActual], &auxInt);
            printf("\n El id es %d",auxInt);

            if (!Emp_setPeso(pArrayEmpleado[indiceActual],10.30))
            {
                Emp_getPeso(pArrayEmpleado[indiceActual],&auxPeso);
                printf("\nEl peso es: %.2f ",auxPeso);

                if (!Emp_setNombre(pArrayEmpleado[indiceActual],"Soledad"))
                {
                    Emp_getNombre(pArrayEmpleado[indiceActual],auxNombre);
                    printf ("\nEl nombre es: %s",auxNombre);

                    if (!Emp_setEstado(pArrayEmpleado[indiceActual],0))
                    {
                        Emp_getEstado(pArrayEmpleado[indiceActual],&auxEstado);
                        printf ("\nEl estado es: %d\n",auxEstado);
                    }
                }
            }

        }

    }


    return 0;
}
