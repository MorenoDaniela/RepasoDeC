#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED
#include "asociado.h"
typedef struct
{
    int idAsociado;
    int idAmbulancia;
    float tiempo;
    int motivo;//infarto 0 acv 1 gripe 2
    int estado;//estado pendiente 1 cumplido 0
    int idLlamada;
}Llamada;

int dos_alta(Asociado* socios, Llamada* call,int lugarVacio,int id, int limiteCall, int limiteSocios);
int dos_findEmpty (Llamada* call,int limite, int* resultado);
int dos_initStruct(Llamada* call, int limite);
int dos_getId(char*msj,Llamada* call,int limite);
void dos_print(Llamada* call, int limite);
int motivoMasRecurrente(Llamada* call,int limite);
int socioConMasLlamadas(Llamada* call,Asociado* socios,int limiteSocios, int limiteCall);

#endif // LLAMADA_H_INCLUDED
