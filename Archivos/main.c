#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#define MAX_PERSONA 1000
#include "persona.h"

int main()
{
    Persona* pArrayPersona[MAX_PERSONA];
    //int ultimoElementoArrayPersona = 0;
    int indiceActual=0;
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferEstado[4096];
    //int auxInt;
    /*
    char auxApellido[50];
    char auxNombre[50];
    int auxEstado;*/

    //indiceActual = ultimoElementoArrayPersona;

    //pArrayPersona[indiceActual] = Pers_new();

    /*
    if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        printf("OK");
        if(!Pers_setId(pArrayPersona[indiceActual],14))
        {
            Pers_getId(pArrayPersona[indiceActual], &auxInt);
            printf("\nEl id es %d",auxInt);

            if (!Pers_setApellido(pArrayPersona[indiceActual],"Arrieta"))
            {
                Pers_getApellido(pArrayPersona[indiceActual],auxApellido);
                printf("\nEl apellido es: %s ",auxApellido);

                if (!Pers_setNombre(pArrayPersona[indiceActual],"Marcos"))
                {
                    Pers_getNombre(pArrayPersona[indiceActual],auxNombre);
                    printf ("\nEl nombre es: %s",auxNombre);

                    if (!Pers_setEstado(pArrayPersona[indiceActual],0))
                    {
                        Pers_getEstado(pArrayPersona[indiceActual],&auxEstado);
                        printf ("\nEl estado es: %d \n",auxEstado);
                    }
                }
            }

        }

    }*/





    FILE *pFile = NULL;
    FILE *pFileBkp=NULL;
    pFile=fopen("datos.csv","r");
    pFileBkp=fopen("data_bkp.csv","w");

    if (pFile != NULL && pFileBkp !=NULL)
    {
        //ultimoElementoArrayPersona++;
        while (!feof(pFile))
        {

            //Pers_newStr(bufferId,bufferNombre,bufferApellido,bufferEstado);
            fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferEstado);
            //Pers_newStr(bufferId,bufferNombre,bufferApellido,bufferEstado);
            pArrayPersona[indiceActual] =  Pers_newStr(bufferId,bufferNombre,bufferApellido,bufferEstado);
            indiceActual++;
            printf ("%s- %s - %s - %s \n",bufferId,bufferNombre,bufferApellido,bufferEstado);
        }
        fclose(pFile);
        fclose(pFileBkp);
    }
    return 0;
}
