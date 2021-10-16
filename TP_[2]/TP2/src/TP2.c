#include <stdio.h>

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
//#include  <stdio_ext.h>
#include "biblioteca.h"



#define EJECUTIVES 1
#define TECHNICIANS 2
#define LOGISTICS 3
#define COMERCIALS 4
#define LEN_EMPLOYEES 1000
#define LEN_SECTOR 4
#define EMPTY 0
#define LOADED 1
#define OPTIONS 4


int main()
{
    int option;
    int idValue = 0;
    int idAux = 0;
    int loadedEmployee = -1;
    int enteredId=0;
    int removedEmployee = 0;
    int modifiedEmployee=0;
    int listStatus ;


    sEmployee employeeList[LEN_EMPLOYEES];
    sEmployeeType sectorList[LEN_SECTOR]={{1,"EJECUTIVOS"},{2,"TECNICOS"},{3,"LOGISTICA"},{4,"COMERCIALES"}};


    setbuf(stdout,NULL);



    initEmployees(employeeList,LEN_EMPLOYEES);
    do{
    idAux=idValue;
    printf("\nMENU\n");
    printf("1-ALTA empleados\n");
    printf("2-MODIFICAR lista de empleados\n");
    printf("3-BAJA de empleados\n");
    printf("4-INFORMAR\n");
   // printf("5-LISTA DE EMPLEADOS\n");
    printf("0-SALIR\n\n");
    option = EnterNumberInt("Seleccione una opcion:",OPTIONS,0);

    listStatus = CheckListStatus(employeeList,LEN_EMPLOYEES);
    while ((option != 1 && option != 0) && listStatus == -1)
    {
     option = EnterNumberInt("No se han ingresado empleados anteriormente. Debera cargar al menos uno\n", OPTIONS,0);
    }



    switch(option)
    {
        case 1:
        system("cls");
        loadedEmployee = addEmployee(employeeList, LEN_EMPLOYEES, &idValue, idAux, sectorList, LEN_SECTOR);
        system("cls");
        if (loadedEmployee == 0)
        {

            printf("Empleado cargado correctamente\n\n");
        }
        else
        {
            printf("Error. Memoria llena\n\n");
        }

        break;


        case 2:
        system("cls");
        enteredId=findEmployeeById(employeeList, LEN_EMPLOYEES, sectorList, LEN_SECTOR, idAux);
        modifiedEmployee=modifyEmployees(employeeList, LEN_EMPLOYEES, sectorList, LEN_SECTOR, enteredId);

        if(modifiedEmployee == 0)
        {
            printf("Se han modificado los datos correctamente\n\n");
        }
        else
        {
            printf("No se ha encontrado al empleado\n\n");
        }


        break;

        case 3:
        system("cls");
        enteredId=findEmployeeById(employeeList, LEN_EMPLOYEES, sectorList, LEN_SECTOR, idAux);
        removedEmployee=removeEmployee(employeeList, LEN_EMPLOYEES, sectorList, LEN_SECTOR, enteredId);
        system("cls");
        if(removedEmployee==0)
        {
            printf("El empleado se ha removido correctamente\n\n");
        }
        else
        {
            printf("No se ha encontrado al empleado\n\n");
        }

        break;

        case 4:
        ReportSubMenu(employeeList,LEN_EMPLOYEES, sectorList,LEN_SECTOR);

        break;

       /*  case 5:
        system("cls");
        displayEmployeeList(employeeList,LEN_EMPLOYEES, sectorList, LEN_SECTOR);
        break;*/
    }



    } while (option != 0);

    return EXIT_SUCCESS;
}
