#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED
#define TEXT_SIZE 20

typedef struct
{
    int codigoLibro;
    int isEmpty;
    int idUnico;
    //-----------------
    char titulo[TEXT_SIZE];
    //int varInt;
    //float varFloat;
    //char varChar;
    //char varLongString[TEXT_SIZE];

}Libros;


//#endif // FANTASMA_H_INCLUDED

int libro_Inicializar(Libros array[], int size);                                    //cambiar libro
int libro_buscarEmpty(Libros array[], int size, int* posicion);                    //cambiar libro
int libro_buscarID(Libros array[], int size, int valorBuscado, int* posicion);                    //cambiar libro
int libro_buscarInt(Libros array[], int size, int valorBuscado, int* posicion);                    //cambiar libro
int libro_buscarString(Libros array[], int size, char* valorBuscado, int* indice);                    //cambiar libro
//int libro_alta(Libros array[], int size, int* contadorID);                          //cambiar libro
int libro_baja(Libros array[], int sizeArray);                                      //cambiar libro
int libro_bajaValorRepetidoInt(Libros array[], int sizeArray, int valorBuscado);
int libro_modificar(Libros array[], int sizeArray);                                //cambiar libro
int libro_ordenarPorDobleCriterio(Libros array[],int size, int orderFirst, int orderSecond);                                  //cambiar libro
int libro_listar(Libros array[], int size);                      //cambiar libro
void libro_mock(Libros arrayLibros[], int size,int *contadorId);                      //cambiar libro
int libro_alta(Libros arrayAut,int limAutor, Libros array[], int size, int* contadorID)

#endif // LIBROS_H_INCLUDED
