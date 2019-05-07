#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED

typedef struct
{
    int idAsociado;
    char dni[1000];
    char nombre[50];
    char apellido[50];
    int edad;
    int isEmpty;//estado habilitado 0 no habilitado 1
}Asociado;

int uno_initStruct(Asociado* socios, int limite);
int uno_findEmpty (Asociado* socios,int limite, int* resultado);
int uno_alta(Asociado* socios,int lugarVacio,int id, int limite);
void uno_print(Asociado* socios, int limite);
int uno_findById(char* msj,Asociado* socios,int* idEncontrado, int limite);
int uno_getId(char*msj,Asociado* socios,int limite);
int uno_baja(Asociado* socios,int limite);
int uno_modificar(char* msj,Asociado* socios,int limite);

#endif // ASOCIADO_H_INCLUDED
