#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

//#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"

typedef struct
{
    int idMusico;
    int idOrquesta;
    int idInstrumento;
    char nombre[31];
    char apellido[31];
    int edad;
    int isEmpty;//estado habilitado 0 no habilitado 1
}Musico;

//int musicos_baja(Musico* arrayMusico,int limiteMusico, Instrumento* arrayInstrumento, int limiteInstrumento);
int musicos_baja(Musico* arrayMusico,int limite);
int musicos_bajaOrquesta(Musico* arrayMusico,int limiteMusico, Orquesta* arrayOrquesta, int limiteOrquesta);
int musicos_bajaPorOrquesta(Musico* arrayMusico, int limite, int idAEliminar);
int musicos_initStruct(Musico* arrayMusico, int limite);
int musicos_findEmpty (Musico* arrayMusico,int limite, int* resultado);
void musicos_print(Musico* arrayMusico, int limite);
int musicos_alta(Musico* arrayMusico, Orquesta* arrayOrquesta,Instrumento* arrayInstrumento,int *id,int limiteMusico,int limiteOrquesta, int limiteInstrumento);
//int musico_alta(Musico* arrayMusico, Orquesta* arrayOrquesta, int* id, int limite);
void musicos_print(Musico* arrayMusico, int limite);
void musico_print(Musico* arrayMusico, int limiteMusico, Instrumento* arrayInstrumento, int limiteInstrumento);
void harcodearMusicos(Musico* arrayA, int limite);
int musicos_modificar(Musico* arrayMusico,Orquesta* arrayOrquesta,int limiteOrquesta, int limiteMusico);
int musicos_findById(char* msj,Musico* arrayMusico,int* idEncontrado, int limite);
int musico_buscarID(Musico* arrayMusico, int limite, int valorBuscado, int* posicion) ;
void harcodearTODO(Musico* arrayMusico,int limiteMusico, Instrumento* arrayInstrumento, int limiteInstrumento, Orquesta* arrayOrquesta, int limiteOrquesta);

#endif // MUSICO_H_INCLUDED
