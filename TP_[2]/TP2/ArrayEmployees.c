#include "ArrayEmployees.h"

/// @param employeeList
/// @param len
/// @return
int initEmployees(sEmployee employeeList[], int len)
{
    int flagIsEmpty = -1;
    for(int i=0; i<len ; i++)
    {
        employeeList[i].isEmpty = EMPTY;
        flagIsEmpty = 0;

    }
    return flagIsEmpty;
}

/// @param employeeList
/// @param len
/// @param idValue
/// @param idAux
/// @param sectorList
/// @param len_sector
/// @return
int addEmployee(sEmployee employeeList[], int len, int* idValue, int idAux, sEmployeeType sectorList[], int len_sector)
{

    int id=0;
    int flagMemory = -1;
     id = idAux;
    for(int i=0; i<len;i++)
    {

            if(employeeList[i].isEmpty == EMPTY)
            {
            flagMemory = 0;
            id ++;
            employeeList[i].id = id;
            system("cls");

            EnterString("Ingrese el nombre del empleado: ", employeeList[i].name);
            system("cls");

            EnterString("Ingrese el apellido del empleado: ",employeeList[i].lastName);
            system("cls");
            employeeList[i].salary = EnterNumberFloat("Ingrese el salario del empleado: ");
            system("cls");
            DisplayEmployeeSector(sectorList,len_sector);
            employeeList[i].sector = EnterNumberInt("Ingrese el sector del empleado: ", len_sector,1);
            employeeList[i].isEmpty = LOADED;
            break;
            }
    }
    *idValue = id;
    return flagMemory;
}

/// @param sectorList
/// @param len
void DisplayEmployeeSector(sEmployeeType sectorList [],int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d- %s: \n",sectorList[i].idType, sectorList[i].description);
    }
}

/// @param employee
/// @param employeeType
/// @param len_sector
void displayEmployee(sEmployee employee, sEmployeeType employeeType[], int len_sector)
{
    for(int i=0;i<len_sector;i++)
    {
        if(employeeType[i].idType==employee.sector)
        {
            printf("%d %20s %20s         %10.2f  %4s\n",employee.id, employee.name, employee.lastName, employee.salary, employeeType[i].description);
        }
    }
}

/// @param employeeList
/// @param len
/// @param employeeType
/// @param len_sector
void displayEmployeeList(sEmployee employeeList[],int len, sEmployeeType employeeType[], int len_sector )
{
    printf("ID              NOMBRE             APELLIDO            SALARIO    SECTOR\n");
    for(int i=0 ; i<len ; i++)
    {
        if (employeeList[i].isEmpty==LOADED)
        {
            displayEmployee(employeeList[i], employeeType, len_sector);
        }
    }
}

/// @param employeeList
/// @param len
/// @param employeeType
/// @param len_sector
/// @param enteredId
/// @return
int removeEmployee(sEmployee employeeList[], int len, sEmployeeType employeeType[], int len_sector, int enteredId)
{
    int flagEmpty = -1;
        for(int i=0;i<len;i++)
        {
            if(employeeList[i].isEmpty!=EMPTY && employeeList[i].id==enteredId)
            {
                employeeList[i].isEmpty=EMPTY;
                flagEmpty =0;
                break;
            }
        }

    return flagEmpty;
}

/// @param employeeList
/// @param len
/// @param employeeType
/// @param len_sector
/// @param id
/// @return
int findEmployeeById(sEmployee employeeList[], int len, sEmployeeType employeeType[], int len_sector, int id)
{
    int enteredId;
    displayEmployeeList(employeeList, len, employeeType, len_sector);
    enteredId = EnterNumberInt("Ingrese ID: ",id,1);
    return enteredId;
}

/// @param employeeList
/// @param len
/// @param sectorList
/// @param len_sector
/// @param enteredId
/// @return
int modifyEmployees(sEmployee employeeList[], int len, sEmployeeType sectorList[], int len_sector, int enteredId)
{
    int flagModify = -1;
    int option;

    for(int i=0; i<len; i++)
    {

        if(employeeList[i].isEmpty != EMPTY && employeeList[i].id == enteredId)
        {
            flagModify = 0;
            option = EnterNumberInt ("\n1-NOMBRE\n2-APELLIDO\n3-SALARIO\n4-SECTOR\nSeleccione la opcion a modificar: \n",4,1);

    system("cls");
      switch(option)
      {

        case 1:
            if(employeeList[i].isEmpty != EMPTY && employeeList[i].id == enteredId)
            {
                EnterString("Ingrese el nombre a modificar: \n",employeeList[i].name);
            }
        break;

        case 2:

            if(employeeList[i].isEmpty != EMPTY && employeeList[i].id == enteredId)
            {
                EnterString("Ingrese el apellido a modificar: \n",employeeList[i].lastName);
            }
        break;

        case 3:
            if(employeeList[i].isEmpty != EMPTY && employeeList[i].id == enteredId)
            {
                employeeList[i].salary=EnterNumberFloat("Ingrese el salario a modificar: ");
            }
        break;

        case 4:
            if(employeeList[i].isEmpty != EMPTY && employeeList[i].id == enteredId)
            {

                DisplayEmployeeSector(sectorList,len_sector);
                employeeList[i].sector=EnterNumberInt("Ingrese el sector del empleado: ",len_sector,1);

            }
        break;

      	  }
        }

    }
    return flagModify;
}

/// @param employeeList
/// @param len
/// @return
int CheckListStatus(sEmployee employeeList[], int len)
{
    int flagStatus = -1;
    for(int i=0; i<len; i++)
    {
        if(employeeList[i].isEmpty == LOADED)
        {
            flagStatus = 0;
            break;
        }
    }

    return flagStatus;
}

/// @param employeeList
/// @param len
/// @param order
/// @return
int sortEmployeesByLastName(sEmployee employeeList[], int len, int order)
{

    sEmployee aux;
    int flagSort = -1;
    if(order == 1)
    {
        for(int i=0 ; i < len - 1 ; i++)
        {
          for (int j = i + 1; j < len ; j++)
           {
             if (strcmp (employeeList[i].lastName, employeeList[j].lastName) > 0)
              {
                  aux=employeeList[i];
                  employeeList[i]=employeeList[j];
                 employeeList[j]=aux;
                 flagSort = 0;
              }

              if(strcmp (employeeList[i].lastName, employeeList[j].lastName) == 0)
              {
                   if(strcmp(employeeList[i].name, employeeList[j].name) > 0)
                   {
                        aux=employeeList[i];
                        employeeList[i]=employeeList[j];
                        employeeList[j]=aux;
                        flagSort = 0;
                    }

                }
            }

        }
    }
    if(order == 2)
    {
        for(int i=0 ; i < len - 1 ; i++)
        {
            for (int j = i + 1; j < len ; j++)
            {
                if (strcmp (employeeList[i].lastName, employeeList[j].lastName) < 0)
                {
                    aux=employeeList[i];
                    employeeList[i]=employeeList[j];
                    employeeList[j]=aux;
                    flagSort = 0;
                }

                if(strcmp (employeeList[i].lastName, employeeList[j].lastName) == 0)
                {
                    if(strcmp(employeeList[i].name, employeeList[j].name) < 0)
                    {
                        aux=employeeList[i];
                        employeeList[i]=employeeList[j];
                        employeeList[j]=aux;
                        flagSort = 0;
                    }

                }
            }
        }
    }


    return flagSort;

}

/// @param employeeList
/// @param len
/// @param sectorList
/// @param len_sector
void ReportSubMenu(sEmployee employeeList[], int len, sEmployeeType sectorList[], int len_sector)
{
    int option;
    int sortedList;
    float salaryAcumm = 0;
    float averageSalary = 0;

    int order;
    system("cls");
    printf("1- Ordenar alfabeticamente empleados por apellido y sector\n");
    printf("2- Total de los Salario, promedios de los mismos, cuales empleados superan el salario promedio\n\n");
    printf("0- Para volver al menu");
    option = EnterNumberInt("Seleccione una opcion: ",2,0);

    system("cls");
     switch(option)
        {
            case 1:
            printf("Selecione un metodo de ordenamiento\n");
            printf("1-Ordenar listado alfabaeticamente de A-Z\n");
            printf("2-Ordenar listado alfabeticamente de Z-A\n");
            printf("0-Volver al menu principal\n\n");
            order = EnterNumberInt("Selecione una opcion: \n",2,0);
            sortedList = sortEmployeesByLastName(employeeList, len, order);
            if(sortedList == -1)
            {
                break;
            }
            else
            {
                displayEmployeesSortedBySector(employeeList, len, sectorList, len_sector);
            }

            break;

            case 2:
            averageSalary=AverageWage(employeeList, len, &salaryAcumm);

            printf("El total de salarios es: $%.2f\n",salaryAcumm);
            printf("El promedio de los salarios es: $%.2f\n",averageSalary);
            printf("Los empleados que superan el salario promedio son: \n");
            printf("ID              NOMBRE             APELLIDO            SALARIO    SECTOR\n");
            employeesExcedingAverageSalary(employeeList, len, sectorList, len_sector, averageSalary);

            break;

            case 0:
            break;
         }

}

/// @param employeeList
/// @param len_employees
/// @param sectorList
/// @param len_sector
void displayEmployeesSortedBySector(sEmployee employeeList[], int len_employees, sEmployeeType sectorList[], int len_sector)
{   system("cls");
    printf("SECTOR      ID          NOMBRE             APELLIDO            SALARIO    \n");
    for(int i=0;i<len_sector;i++)
    {

        printf("\n\n%s \n",sectorList[i].description);

        for(int j= 0; j<len_employees ; j++)
        {
            if(sectorList[i].idType == employeeList[j].sector && employeeList[j].isEmpty==LOADED)
            {
            printf("%13d %17s %20s        $%10.2f\n",employeeList[j].id, employeeList[j].name, employeeList[j].lastName, employeeList[j].salary);
            }
        }
    }

}

/// @param employeeList
/// @param len
/// @param salaryAcumm
/// @return
float AverageWage(sEmployee employeeList[], int len, float* salaryAcumm)
{
    int salaryAcounttant = 0;
    float wageAccumulator = 0;
    float averageWage = 0;

    for (int i= 0; i< len ; i++)
    {
        if (employeeList[i].isEmpty == LOADED)
        {
            wageAccumulator = wageAccumulator + employeeList[i].salary ;
            salaryAcounttant++;
        }
    }
    averageWage=wageAccumulator/salaryAcounttant;

    *salaryAcumm = wageAccumulator;
    return averageWage;
}

/// @param employee
/// @param len
/// @param sectorList
/// @param len_sector
/// @param averageSalary
void employeesExcedingAverageSalary(sEmployee employee[], int len, sEmployeeType sectorList[], int len_sector, float averageSalary)
{
   for (int i=0 ; i < len ; i++)
   {
       if (employee[i].salary >= averageSalary && employee[i].isEmpty == LOADED
    		   )
       {
            displayEmployee(employee[i], sectorList,len_sector);
       }
    }
}
