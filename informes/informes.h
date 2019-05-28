#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"

int instrumentosQueFueronSolicitadosPorOrquestaDeterminada(Musico* arrayMusicos, Orquesta* arrayOrquesta,Instrumento* arrayInstrumento, int limiteMusico, int limiteOrquesta, int limiteInstrumento);
int orquestasSegunLugar (Orquesta* arrayOrquesta, int limiteOrquesta);
int musicosQueNoSuperan25(Musico* arrayMusicos,int limiteMusicos,Instrumento* arrayInstrumento, int limiteInstrumento, Orquesta* arrayOrquesta, int limiteOrquesta);
int inf_instrumentoPorOrquesta(Musico* arrayMusico, Orquesta* arrayOrquesta, int limiteMusico, int limiteOrquesta);
int inf_orquestasMenosDeSeisMusicos(Musico* arrayMusico,int limiteMusico, Orquesta* arrayOrquesta, int limiteOrquesta);
int inf_musicosNoViento(Musico* arrayMusico,Instrumento* arrayInstrumento, int limiteMusico, int limiteInstrumento);
int inf_musicosPorApellido(Musico* arrayMusico, int limiteMusico, int orderFirst, int orderSecond);
int inf_orquestaCompleta(Musico* arrayMusico,Orquesta* arrayOrquesta, Instrumento* arrayInstrumento, int limiteMusico,int limiteOrquesta, int limiteInstrumento);
int inf_ordenarMusicosPorIdOrquesta(Musico* arrayMusico, int limite);

#endif // INFORMES_H_INCLUDED
