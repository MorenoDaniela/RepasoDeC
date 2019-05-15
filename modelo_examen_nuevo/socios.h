#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

typedef struct
{
    int codigoSocio;
    char nombre[31];
    char apellido[31];
    char sexo;
    char telefono[16];
    char mail[31];
    char fechaAsociado[20];
    int isEmpty;

} Socios;

///int informar (Socios* list3,int length);
int soc_promedio (Socios* list3, int length);
int soc_empty (Socios *list3, int length,int *id);
int soc_inicializar(Socios* list3, int length);
int soc_alta(Socios* list3, char *msgError,int length, int posLibre);
int soc_lugarLibre (Socios* list3, int length, int *posLibre);
int soc_modificar (Socios* list3, int length,int*id);
int soc_buscarPorId (Socios* list3,char *msg,char *msgError, int length, int *id);
int soc_baja (Socios* list3, int length);
int soc_mostrar(Socios* list3, int length);
int soc_ordenar (Socios* list3,int length);
void soc_mock(Socios* list3, int length,int *contadorId);



#endif // SOCIOS_H_INCLUDED
