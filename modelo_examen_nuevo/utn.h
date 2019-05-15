#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_fechaNacimiento (char *msg, char *msgError, char minimo, char maximo, int reintentos, char *resultado); ///ANDA
int utn_isValidFecha(char *cadena);

int utn_getCuit (char *msg, char *msgError, char minimo, char maximo, int reintentos, char *resultado);
int utn_isValidCuit (char *cadena);

int utn_getDni (char *msg, char *msgError, char minimo, char maximo, int reintentos, char *resultado);
int utn_isValidDni (char *cadena);

int utn_getTelefono (char *msg, char *msgError, char minimo, char maximo, int reintentos, char *resultado); ///ANDA
int utn_isValidTelephone(char* cadena);

int utn_getInt (char *msg, char *msgError, char minimo, char maximo, int reintentos, int *resultado);
int utn_isValidInt (char *cadena);

int utn_getFecha (char *msg, char *msgError, char minimo, char maximo, int reintentos, int *resultado);
int utn_isValidMes (char *cadena);
int utn_isValidAnio (char *cadena);
int utn_isValidDia (char *cadena);

int utn_getInSimple (char msg[]);

float utn_getFloat (char * mensaje, char * mensajeError, float minimo, float maximo, float intentos, float * resultado);
float utn_isValidFloat (float *numero, float minimo, float maximo);

int utn_getSex(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado); ///anda
int  utn_isValidSex (char letra, char maximo, char minimo);

//char utn_getChar (const char * mensaje, const char * mensajeError, const char * minimo, const char * maximo, int reintentos, char * pResultado);
int isValidChar(char letra, char minimo, char maximo);
int getChar(char *msj, char *errorMsj, char minimo, char maximo, int reintentos, char *resultado);
int utn_getString ( char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);

int utn_getName (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);

int utn_isValidName (char *cadena);
int utn_tieneEspacio (char *cadena); ///anda con nombre compuesto

int utn_getMail (char *msg, char *msgError,int minimo, int maximo, int reintentos, char *dato);
int utn_isValidMail (char *cadena);

#endif // UTN_H_INCLUDED
