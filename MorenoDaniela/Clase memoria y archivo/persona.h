#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    char nombre [50];
    char apellido [50];
    int id;
    int estado;
}Persona;

Persona* Pers_new(void);
Persona* Pers_newStr(char* id, char* nombre, char* apellido, char* estado);

int Pers_delete(Persona* this);
Persona* Pers_alta(char* nombre, char* apellido, int estado, int id);
//Persona* Pers_newStr(char* id, char* nombre, char* apellido, char* estado);

int Pers_setIdString(Persona* this, char* id);
int Pers_getIdString(Persona* this, char* resultado);

int Pers_setEstadoString(Persona* this, char* estado);
int Pers_getEstadoString(Persona* this, char* estado);

int Pers_setId(Persona* this, int id);
int Pers_setNombre(Persona* this, char* nombre);
int Pers_setApellido(Persona* this, char* apellido);
int Pers_setEstado(Persona* this, int estado);

int Pers_getId(Persona* this, int* resultado);
int Pers_getNombre(Persona* this, char* resultado);
int Pers_getApellido(Persona* this, char* resultado);
int Pers_getEstado(Persona* this, int* resultado);

#endif // PERSONA_H_INCLUDED
