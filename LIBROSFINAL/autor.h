#ifndef AUTOR_H_INCLUDED
#define AUTOR_H_INCLUDED

typedef struct
{
    int idAutor;
    char nombre[31];
    char apellido[31];
    int isEmpty;//estado habilitado 0 no habilitado 1
}Autor;

int uno_initStruct(Autor* arrayAutor, int limite);
int uno_findEmpty (Autor* arrayAutor,int limite, int* resultado);
int uno_alta(Autor* arrayAutor,int* id, int limite);
void uno_print(Autor* arrayAutor, int limite);
int uno_findById(char* msj,Autor* arrayAutor,int* idEncontrado, int limite);
int uno_getId(char*msj,Autor* arrayAutor,int limite);
int uno_baja(Autor* arrayAutor,int limite);
int uno_modificar(Autor* arrayAutor,int limite);
int uno_ordenarDobleCadena(Autor* arrayA,int limite);
void harcodearAutores(Autor* arrayA, int limite);

#endif // AUTOR_H_INCLUDED
