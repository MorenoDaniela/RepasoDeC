#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include <string.h>

Empleado* Emp_new(void)
{
    return (Empleado*) malloc(sizeof(Empleado));
}

int Emp_delete(Empleado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Emp_setId(Empleado* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Emp_getId(Empleado* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}



int Emp_setPeso(Empleado* this, float peso)
{
    int retorno = -1;
    if(this != NULL && peso >= 0)
    {
        this->peso= peso;
        retorno = 0;
    }
    return retorno;
}

int Emp_getPeso(Empleado* this, float* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->peso;
        retorno = 0;
    }
    return retorno;
}

int Emp_setNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre >= 0)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}


int Emp_getNombre(Empleado* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->nombre);//revisar aca
        retorno = 0;
    }
    return retorno;
}

int Emp_setEstado(Empleado* this, int estado)
{
    int retorno = -1;
    if(this != NULL && estado >= 0)
    {
        this->estado=estado;
        retorno = 0;
    }
    return retorno;
}

int Emp_getEstado(Empleado* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->estado;
        retorno = 0;
    }
    return retorno;
}

int Emp_compararNombre(Empleado* this, Empleado* thisUno)
{
    int retorno = -2;
    if(this != NULL && thisUno != NULL)
    {
        retorno = strncmp(this->nombre,thisUno->nombre,sizeof(this->nombre));
    }
    return retorno;
}

int Emp_alta(char* nombre, float peso, int estado, int id)
{
    Empleado* emp = Emp_new();
    if(emp != NULL && !Emp_setNombre(emp,nombre) && !Emp_setPeso(emp,peso)
        && !Emp_setEstado(emp,estado) && !Emp_setId(emp, id))
    {

    }else
        {
            free(emp);
        }
    return emp;
}



