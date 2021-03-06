#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"
#include "Controller.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile = NULL;

    if (path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen (path, "r");
        if (pFile!=NULL)
        {
            if (!parser_EmployeeFromText(pFile,pArrayListEmployee))
            {
                retorno=0;
                printf ("Carga ok.\n");
            }
        }
        fclose (pFile);
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* pAuxEmployee = employee_new();
    int bufferSueldo;
    int bufferHoras;
    char bufferName[500];
    int ID;
    ID=controller_maxId(pArrayListEmployee);

    if (pArrayListEmployee!=NULL && pAuxEmployee!=NULL && ID>0)
    {
        employee_setId(pAuxEmployee,ID);//esta linea va adentro del if de abajo

        if (getName("\nIngrese nombre: \n","Error, nombre no valido.\n",2,35,3,bufferName)==0 &&
            getInt("Ingrese cantidad horas trabajdas: ","Error, horas no validas.\n",1,300,3,&bufferHoras)==0 &&
            getInt("Ingrese sueldo: ","Error, sueldo no valido.\n",1,1000000,3,&bufferSueldo)==0)
            {
                employee_setNombre(pAuxEmployee,bufferName);
                employee_setHorasTrabajadas(pAuxEmployee,bufferHoras);
                employee_setSueldo(pAuxEmployee,bufferSueldo);
                //employee_newParametros((char)ID,bufferName,bufferHoras,bufferSueldo);
                ll_add(pArrayListEmployee,pAuxEmployee);
                printf ("Carga ok.\n");
                retorno=0;
            }
    }
    return retorno;
}
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int bufferSueldo;
    int bufferHoras;
    char bufferNombre[500];
    int ID;
    int index;
    int opcion;
    Employee* pAux;

    if (pArrayListEmployee!=NULL)
    {
        if (getInt("Ingrese id del empleado para modificar sus datos: \n","Error, id no valido.",1,2000,3,&ID)==0)
        {
            index = controller_returnIndex(pArrayListEmployee,&ID);
            pAux = ll_get(pArrayListEmployee,index);
            //printf ("Index: %d ID %d",index,ID);
            if (index!=-1 && pAux!=NULL)//mirar aca pAux si no funciona sacarlo
            {
                getInt ("Ingrese opcion a modificar 1-Nombre 2-Sueldo 3-Horas trabajadas: \n","Error, opcion no valida.\n",1,3,3,&opcion);
                switch (opcion)
                {
                case 1:
                    getName("Ingrese nuevo nombre del empleado: \n","Error, nombre no valido.\n",2,50,3,bufferNombre);
                    employee_setNombre(pAux,bufferNombre);
                    retorno=0;
                    break;
                case 2:
                    getInt("Ingrese nuevo sueldo: \n","Error, sueldo no valido.\n",1,1000000,3,&bufferSueldo);
                    employee_setSueldo(pAux,bufferSueldo);
                    retorno=0;
                    break;
                case 3:
                    getInt("Ingrese horas trabajadas nuevas: \n","Error, horas no validas.\n",1,300,3,&bufferHoras);
                    employee_setHorasTrabajadas(pAux,bufferHoras);
                    retorno=0;
                    break;
                default:
                    break;
                }
            }
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int ID;
    int index;
    Employee* pAux;

    if (pArrayListEmployee!=NULL)
    {
        if (getInt("Ingrese id del empleado a dar de baja: ","Error, id no valido.\n",1,2000,3,&ID)==0)
        {
            index=controller_returnIndex(pArrayListEmployee,&ID);
            pAux=ll_pop(pArrayListEmployee,index);
            if (index!=-1 && pAux!=NULL)
            {
                employee_delete(pAux);
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* pEmpleado;
    int auxId;
    int auxSueldo;
    int auxHoras;
    char bufferName[500];
    int lenth;
    int i;

    if (pArrayListEmployee!=NULL)
    {
        lenth=ll_len(pArrayListEmployee);
        for (i=0;i<lenth;i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&auxId);
            employee_getNombre(pEmpleado, bufferName);
            employee_getSueldo(pEmpleado,&auxSueldo);
            employee_getHorasTrabajadas(pEmpleado,&auxHoras);

            printf("%d -%s -%d -$%d\n",auxId, bufferName, auxHoras, auxSueldo);
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{


}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_maxId(LinkedList* pArrayEmployee)
{
    int retorno=-1;
    int lenth;
    int ID;
    int maxID=0;
    int i;
    Employee* pAuxEmployee;

    lenth= ll_len(pArrayEmployee);

    if (pArrayEmployee!=NULL)
    {
        for (i=0;i<lenth;i++)
        {
            pAuxEmployee=ll_get(pArrayEmployee,i);
            employee_getId(pAuxEmployee,&ID);
            if (ID>maxID)
            {
                maxID=ID;
            }
        }
        maxID=maxID+1;
        retorno=maxID;
    }
    return retorno;
}

int controller_returnIndex(LinkedList* pArrayEmployee,int* valorBuscado)
{
    int retorno=-1;
    int i;
    int ID;
    int lenth = ll_len(pArrayEmployee);
    Employee* pAuxEmployee;

    if (pArrayEmployee!=NULL && valorBuscado!=NULL)
    {
        for (i=0;i<lenth;i++)
        {
            pAuxEmployee= ll_get(pArrayEmployee,i);
            employee_getId(pAuxEmployee,&ID);
            if (ID==*valorBuscado)
            {
                *valorBuscado=ID;
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

