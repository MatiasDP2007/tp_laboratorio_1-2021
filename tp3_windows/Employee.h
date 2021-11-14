#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void employee_print(LinkedList* pArrayEmployee, int index);
int employee_searchForId(LinkedList* pArrayListEmployee, int id);

int employee_SortByName(void* elementOne, void* elementTwo);
int employee_SortById(void* elementOne, void* elementTwo);
int employee_SortBySalary(void* elementOne, void* elementTwo);
int employee_SortByHours(void* elementOne, void* elementTwo);
#endif // employee_H_INCLUDED
