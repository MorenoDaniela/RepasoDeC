#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

typedef struct
{
    int idSocio;
    char nombre[31];
    char apellido[31];
    int sexo;
    char telefono[10];
    char email[50];
    int isEmpty;//estado habilitado 0 no habilitado 1
}Socio;

int tres_initStruct(Socio* arraySocio, int limite);
int tres_findEmpty (Socio* arraySocio,int limite, int* resultado);
int tres_alta(Socio* arraySocio,int* id, int limite);
void tres_print(Socio* arraySocio, int limite);
int tres_findById(char* msj,Socio* arraySocio,int* idEncontrado, int limite);
int tres_getId(char*msj,Socio* arraySocio,int limite);
int tres_baja(Socio* arraySocio,int limite);
int tres_modificar(Socio* arraySocio,int limite);
int tres_ordenarDobleCadena(Socio* arraySocio,int limite);
void harcodearSocios(Socio* arraySocio, int limite);

#endif // SOCIOS_H_INCLUDED
