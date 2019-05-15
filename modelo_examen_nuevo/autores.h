#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct
{
    int codigoAutor;
    char apellido[20];
    char nombre[20];
    int isEmpty;

} Autores;


int informar (Autores* list,int length);
int aut_promedio (Autores* list, int length);
int aut_empty (Autores *list, int length,int *id);
int aut_inicializar(Autores* list, int length);
int aut_alta(Autores* list, char *msgError,int length, int posLibre);
int aut_lugarLibre (Autores* list, int length, int *posLibre);
int aut_modificar (Autores* list, int length,int*id);
int aut_buscarPorId (Autores* list,char *msg,char *msgError, int length, int *id);
int aut_baja (Autores* list, int length);
int aut_mostrar(Autores* list, int length);
int aut_ordenar (Autores* list,int length);
void aut_mock(Autores* list, int length,int *contadorId);


#endif // AUTORES_H_INCLUDED
