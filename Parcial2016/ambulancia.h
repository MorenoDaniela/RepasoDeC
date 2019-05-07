#ifndef AMBULANCIA_H_INCLUDED
#define AMBULANCIA_H_INCLUDED
#include "llamada.h"
typedef struct
{
    //int idAsociado;
    int idAmbulancia;
    //float tiempo;
    //int motivo;//infarto 0 acv 1 gripe 2
    int isEmpty;//estado pendiente 1 cumplido 0
    //int idLlamada;
}Ambulancia;

int tres_initStruct(Ambulancia* amb, int limite);
int tres_altaAmbulancia(Ambulancia* amb,Llamada* call,int lugarVacio,int id,int limiteCall,int limiteAmbulancia);
int tres_findEmpty (Ambulancia* amb,int limite, int* resultado);

#endif // AMBULANCIA_H_INCLUDED
