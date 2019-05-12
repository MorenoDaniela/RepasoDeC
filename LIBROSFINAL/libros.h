#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct
{
    int idLibro;
    int idAutor;
    int isEmpty;
    char titulo[51];
}Libro;

int dos_initStruct(Libro* arrayLibro, int limite);
int dos_findEmpty (Libro* arrayLibro,int limite, int* resultado);
//int dos_alta(Libro* arrayLibro,int* id, int limite);
int dos_alta(Libro* arrayL,Autor* arrayA,int *id, int limiteAutor,int limiteLibro);
void dos_print(Libro* arrayLibro, int limite);
int dos_findById(char* msj,Libro* arrayLibro,int* idEncontrado, int limite);
int dos_getId(char*msj,Libro* arrayLibro,int limite);
int dos_baja(Libro* arrayLibro,int limite);
int dos_modificar(Libro* arrayL,Autor* arrayA,int limiteAutor, int limiteLibro);
int dos_ordenarTitulo(Libro* arrayL,int limite);
void harcodearLibros(Libro* arrayL, int limite);

#endif // LIBROS_H_INCLUDED
