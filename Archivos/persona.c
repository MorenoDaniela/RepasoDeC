#ifndef PERSONA_C_INCLUDED
#define PERSONA_C_INCLUDED
#include "persona.h"
#include "validaciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


Persona* Pers_new(void)
{
    return (Persona*) malloc(sizeof(Persona));
}

Persona* Pers_newStr(char* id, char* nombre, char* apellido, char* estado)
{
    Persona* retorno=NULL;
    Persona* pAuxPersona;
    if (id!=NULL && nombre !=NULL && apellido!=NULL && estado!=NULL)
    {
        pAuxPersona = Pers_new();
        if (pAuxPersona!=NULL)
        {
            if (!Pers_setNombre(pAuxPersona,nombre) &&
                !Pers_setApellido(pAuxPersona,apellido) &&
                !Pers_setIdString(pAuxPersona,id) &&
                !Pers_setEstadoString(pAuxPersona,estado))
                {
                    retorno= pAuxPersona;
                }else
                    {
                        Pers_delete(pAuxPersona);
                    }
        }
    }
    return retorno;
}

int Pers_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Pers_setId(Persona* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Pers_setIdString(Persona* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id!=NULL)
    {
        if (isNumber(id)==1)
        {
            retorno = Pers_setId(this,atoi(id));
        }
    }
    return retorno;
}

int Pers_getIdString(Persona* this, char* id)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && id != NULL)
    {
        Pers_getId(this,&buffer);
        sprintf(id,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}

int Pers_getId(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

int Pers_setNombre(Persona* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre >= 0)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}


int Pers_getNombre(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->nombre);
        retorno = 0;
    }
    return retorno;
}


int Pers_setApellido(Persona* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido >= 0)
    {
        strcpy(this->apellido,apellido);
        retorno = 0;
    }
    return retorno;
}


int Pers_getApellido(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->apellido);
        retorno = 0;
    }
    return retorno;
}

int Pers_setEstado(Persona* this, int estado)
{
    int retorno = -1;
    if(this != NULL && estado >= 0)
    {
        this->estado=estado;
        retorno = 0;
    }
    return retorno;
}

int Pers_setEstadoString(Persona* this, char* estado)
{
    int retorno = -1;
    if(this != NULL && estado!=NULL)
    {
        if(strcmp(estado,"FALSE")==0)
        {
            Pers_setEstado(this,0);
            retorno = 0;
        }else if (strcmp(estado,"TRUE")==0)
            {
                Pers_setEstado(this,1);
            }
    }
    return retorno;
}

int Pers_getEstadoString(Persona* this, char* estado)
{
    int retorno = -1;
    int buffer;
    if(this != NULL && estado != NULL)
    {
        Pers_getEstado(this,&buffer);
        if (buffer==0)
        {
            sprintf(estado,"FALSE");
        }else
            sprintf(estado,"TRUE");

        retorno = 0;
    }
    return retorno;
}

int Pers_getEstado(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->estado;
        retorno = 0;
    }
    return retorno;
}


Persona* Pers_alta(char* nombre, char* apellido, int estado, int id)
{
    Persona *retorno= NULL;
    Persona* persona = Pers_new();
    if(persona != NULL && !Pers_setNombre(persona,nombre) && !Pers_setApellido(persona,apellido)
        && !Pers_setEstado(persona,estado) && !Pers_setId(persona, id))
    {
        retorno=persona;
    }else
        {
            Pers_delete(persona);
        }
    return retorno;
}

int parserPersona (char* nombreFile,Persona* persona, int limite)
{
    char aux[512];
    char auxId[512];
    char auxNombre[512];
    char auxApellido[512];
    char auxEdad[512];
    int r;
    int retorno=-1;

    FILE* fp = fopen(nombreF,"r");
    if (fp!=NULL)
    {
        retorno=0;
        //scanf(fp,"%[[^]")
        fgets(aux,512,fp);//saltea primera linea

        do
        {
            r = fscanf(fp,"%[^;];%[^;];%[^;];%[^;];[^\n]\n",auxId,auxNombre,auxApellido,auxEdad);
            if(r==4)
            {
                printf ("%s %s %s %s ",auxId,auxNombre,auxApellido,auxEdad);
                retorno++;
            }
        }while(!feof(fp));

        fclose(fp);
    }
    return retorno;
}
#endif // PERSONA_C_INCLUDED
