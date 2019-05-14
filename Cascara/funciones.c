#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>
#include "validaciones.h"

int getInt(char *msj, char *errorMsj, int minimo, int maximo, int reintentos, int *resultado)
{
    int retorno = -1;
    int buffer;
    if(msj != NULL && errorMsj != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", msj);
            scanf("%d", &buffer);
            if(isValidInt(buffer, minimo, maximo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }else
            {
                printf("%s", errorMsj);
            }
            reintentos--;
        }while(reintentos >= 0);
    }
    return retorno;
}

int getFloat(char *msj, char *errorMsj, float minimo, float maximo, int reintentos, float *resultado)
{
    int retorno = -1;
    float buffer;
    if(msj != NULL && errorMsj != NULL && resultado != NULL && maximo>=minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", msj);
            scanf("%f", &buffer);
            if(isValidFloat(buffer, minimo, maximo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }else
            {
                printf("%s", errorMsj);
            }
            reintentos--;
        }while(reintentos >= 0);
    }
    return retorno;
}

int getChar(char *msj, char *errorMsj, char minimo, char maximo, int reintentos, char *resultado)
{
    char buffer;
    int retorno = -1;
    if(msj != NULL && errorMsj != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", msj);
            fflush(stdin);//
            //__fpurge(stdin);
            scanf("%c", &buffer);
            if(isValidChar(buffer, minimo, maximo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }else
            {
                printf("%s", errorMsj);
            }
            reintentos--;
        }while(reintentos >= 0);
    }
    return retorno;
}

int getString(char* msj, char* errorMsj, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msj != NULL && errorMsj != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        do
        {
            printf("%s",msj);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",errorMsj);
        }while(reintentos>=0);
    }
    return retorno;
}

int getName (char* msj, char* errorMsj, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msj != NULL && errorMsj != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        if(!getString(msj,errorMsj,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
            else
            {
                printf (errorMsj);
                reintentos--;
            }
        }
    }
    return retorno;
}

int getApellido (char* msj, char* errorMsj, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msj != NULL && errorMsj != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
            if(!getString(msj,errorMsj,minimo,maximo,reintentos,bufferStr))
            {
                if(isValidApellido(bufferStr))
                {
                    strncpy(resultado, bufferStr,maximo);
                    retorno = 0;
                }
                else
                {
                    printf (errorMsj);
                    reintentos--;
                }
            }
    }
    return retorno;
}

int getDni (char* msj, char* errorMsj,int minimo, int maximo, int reintentos, char* resultado)
{
    char bufferString[50];
    int retorno=-1;
    while(retorno==-1 && reintentos>0)
    {
        if(!getString(msj,errorMsj,minimo,maximo,reintentos,bufferString)&&(resultado!=NULL)&&(isDni(bufferString)))
        {
            strncpy(resultado,bufferString,50);
            retorno=0;
        }
        else
        {
            printf("%s",errorMsj);
            reintentos--;
        }
    }
    return retorno;
}

int getCuit (char* msj, char* msjError,int minimo, int maximo,int reintentos,char* resultado)
{
    char bufferString[20];
    int retorno=-1;
    while(retorno==-1 && reintentos>0)
    {
        if(!getString(msj,msjError,minimo,maximo,reintentos,bufferString)&&(resultado!=NULL)&&(isCuit(bufferString)))
        {
            strncpy(resultado,bufferString,20);
            retorno=0;
        }
        else
        {
            printf("%s",msjError);
            reintentos--;
        }
    }
    return retorno;
}

int getTelefono (char* msj, char* msjError,int minimo, int maximo,int reintentos,char* resultado)
{
    char bufferString[maximo];
    int retorno=-1;
    while(retorno==-1 && reintentos>0)
    {
        if(!getString(msj,msjError,minimo,maximo,reintentos,bufferString)&&(resultado!=NULL)&&(isTelefono(bufferString)))
        {
            strncpy(resultado,bufferString,maximo);
            retorno=0;
        }
        else
        {
            printf("%s",msjError);
            reintentos--;
        }
    }
    return retorno;
}

int getSex(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado)
{
    char buffer;
    int retorno = -1;
    //int control;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            fflush (stdin);
            //__fpurge(stdin);
            printf("%s", mensaje);
            scanf("%c", &buffer);

            //printf("Lo ingresado es: %c\n\n", buffer);

            //control = isValidSex(buffer, maximo, minimo);
            //printf("isValidSex: %d\n\n", control);
            if(isValidSex(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int getEmail(char* msj, char* msjError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[70];

    if(msj!=NULL && msjError!=NULL && minimo<maximo && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msj,msjError,minimo,maximo,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidEmail(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,maximo);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msjError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int getAlfanumerico(char* msj, char* msjError, int minSize, int maxSize, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msj!=NULL && msjError!=NULL && minSize<maxSize && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msj,msjError,minSize,maxSize,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidAlphanumeric(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msjError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_getCUIT(char* msg, char* msgError, int reintentos, char* input)
{
    int maxSize=14; //con guiones 13 elementos
    int minSize=11;  // sin puntos
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidCUIT(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int getFecha(char *msg, char *msgError, int minSize, int maxSize, int reintentos, int *resultadoMes, int *resultadoDia, int *resultadoAnio)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && resultadoMes!=NULL && resultadoDia!=NULL && resultadoAnio!=NULL)
    {
        do
        {
            printf("%s", msg);
            if(!getString("\nMes: ",msgError,minSize,maxSize,reintentos,bufferStr))
            {
                if(isValidNumber(bufferStr)==1)
                {
                    *resultadoMes=atoi(bufferStr);

                }
                else
                {
                    printf("%s",msgError);
                    break;
                }
                if(!getString("\nDia: ",msgError,minSize,maxSize,reintentos,bufferStr))
                {
//                    printf("%d", isValidDia(resultadoMes))
                    if(isValidNumber(bufferStr)==1 /*&& isValidDia(*resultadoMes, atoi(bufferStr)) == 0 */)
                    {
                        *resultadoDia=atoi(bufferStr);

                    }
                    else
                    {
                        printf("%s",msgError);
                        break;
                    }
                }
                else
                {
                    printf("%s",msgError);
                    break;
                }
                if(!getString("\nAnio: ",msgError,minSize,maxSize,reintentos,bufferStr))
                {
                    if(isValidNumber(bufferStr)==1)
                    {
                        *resultadoAnio=atoi(bufferStr);
                        retorno=0;
                        break;
                    }

                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
#endif // FUNCIONES_C_INCLUDED
