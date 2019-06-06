#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char auxNombre[500];
    char auxId[500];
    char auxHoras[500];
    char auxSueldo[500];
    int flag=0;

    Employee* pAuxEmployee;

    if (pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while (!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);

            if (flag==0)
            {
                flag++;
                continue;
            }
            pAuxEmployee = employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);
            if (pAuxEmployee !=NULL)
            {
                ll_add(pArrayListEmployee,pAuxEmployee);
                retorno=0;
            }
        }
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
