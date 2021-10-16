#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//#include <stdio_ext.h>
#include "biblioteca.h"

#define EJECUTIVES 1
#define TECHNICIANS 2
#define LOGISTICS 3
#define COMERCIALS 4
#define LEN_EMPLOYEES 1000
#define LEN_SECTOR 4
#define EMPTY 0
#define LOADED 1


typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} sEmployee;

typedef struct
{
 int idType;
 char description[51];
} sEmployeeType;


typedef struct
{
    int id;
    float count;
}sAux;

/// @param employeeList
/// @param len
/// @return
int initEmployees(sEmployee employeeList[], int len);

/// @param employeeList
/// @param len
/// @param idValue
/// @param idAux
/// @param sectorList
/// @param len_sector
/// @return
int addEmployee(sEmployee employeeList [], int len, int* idValue, int idAux, sEmployeeType sectorList[], int len_sector);

/// @param employee
/// @param employeeType
/// @param len_sector
void displayEmployee(sEmployee employee, sEmployeeType employeeType[], int len_sector);

/// @param employeeList
/// @param tam
/// @param sectorList
/// @param len_sector
void displayEmployeeList(sEmployee employeeList[],int tam, sEmployeeType sectorList[], int len_sector);

/// @param sectorList
/// @param len
void DisplayEmployeeSector(sEmployeeType sectorList [],int len);

/// @param employeeList
/// @param len
/// @param sectorList
/// @param len_sector
/// @param id
/// @return
int findEmployeeById(sEmployee employeeList[], int len, sEmployeeType sectorList[], int len_sector, int id);

/// @param employeeList
/// @param len
/// @param sectorList
/// @param len_sector
/// @param enteredId
/// @return
int removeEmployee(sEmployee employeeList[], int len, sEmployeeType sectorList[], int len_sector, int enteredId);

/// @param employeeList
/// @param len
/// @param sectorList
/// @param len_sector
/// @param enteredId
/// @return
int modifyEmployees(sEmployee employeeList[], int len, sEmployeeType sectorList[], int len_sector, int enteredId);

/// @param employeeList
/// @param len
/// @return
int CheckListStatus(sEmployee employeeList[], int len);

/// @param employeeList
/// @param len
/// @param order
/// @return
int sortEmployeesByLastName(sEmployee employeeList[], int len, int order);

/// @param employeeList
/// @param len
/// @param sectorList
/// @param len_sector
void ReportSubMenu(sEmployee employeeList[], int len, sEmployeeType sectorList[], int len_sector);

/// @param employeeList
/// @param len_employees
/// @param sectorList
/// @param len_sector
void displayEmployeesSortedBySector(sEmployee employeeList[], int len_employees, sEmployeeType sectorList[], int len_sector);

/// @param employeeList
/// @param len
/// @param salaryAcumm
/// @return
float AverageWage(sEmployee employeeList[], int len, float* salaryAcumm);

/// @param employee
/// @param len
/// @param sectorList
/// @param len_sector
/// @param averageSalary
void employeesExcedingAverageSalary(sEmployee employee[], int len, sEmployeeType sectorList[], int len_sector, float averageSalary);



#endif /* ARRAYEMPLOYEES_H_ */
