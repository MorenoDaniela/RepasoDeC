#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int i;
    int option = 0;
    int lenth=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        getInt("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
                "3. Alta de empleado.\n4. Modificar datos de empleado.\n5. Baja de empleado.\n6. Listar empleados\n7. Ordenar empleados.\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
                "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
                "10. Salir\n","Error, opcion incorrecta.\n",1,10,3,&option);
                system("clear");
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                lenth = ll_len(listaEmpleados);
                for (i=0;i<lenth;i++)
                {
                    ll_get(listaEmpleados,i);

                }
            break;
        }
    }while(option != 10);
    return 0;
}
