#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct
{
    int idAutor;
    char nombre;
    char apellido;
    int isEmpty;
}Autor;

int uno_initStruct(Autor* autores, int limite);
int uno_findEmpty (Autor* autores,int limite, int* resultado);
int uno_alta(Autor* autores,int lugarVacio,int id, int limite);
void uno_print(Autor* autores, int limite);

#endif // AUTORES_H_INCLUDED
