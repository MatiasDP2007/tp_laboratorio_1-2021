#include "Employee.h"
#include "LinkedList.h"
#include "Validations.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Employee* employee_new()
{
	Employee* newEmployee = NULL;

	newEmployee = (Employee*) malloc (sizeof(Employee));

	return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

	Employee* nuevoEmpleado = employee_new();


	if(nuevoEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
	employee_setId(nuevoEmpleado, atoi(idStr));
	employee_setNombre(nuevoEmpleado,nombreStr);
	employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr));
	employee_setSueldo(nuevoEmpleado, atoi(sueldoStr));
	}

	return nuevoEmpleado;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

int employee_setId(Employee* this,int id)
{
	int flagRetorno = -1;

	if (this != NULL && id >= 0)
	{
	 this->id=id ;
	flagRetorno = 0;
	}
	return flagRetorno;
}

int employee_getId(Employee* this,int* id)
{
	int flagRetorno = -1;

		if (this != NULL && id != NULL)
		{
		*id = this->id;
		flagRetorno = 0;
		}
		return flagRetorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int flagRetorno = -1;

	if (this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		flagRetorno = 0;
	}
return flagRetorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int flagRetorno = -1;

	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		flagRetorno = 0;
	}
return flagRetorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int flagRetorno = -1;

	if(this != NULL && horasTrabajadas >= 0)
	{
		this -> horasTrabajadas = horasTrabajadas;
		flagRetorno = 0;
	}
return flagRetorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int flagRetorno = -1;

		if(this != NULL && horasTrabajadas != NULL)
		{
			*horasTrabajadas = this -> horasTrabajadas;
			flagRetorno = 0;
		}
	return flagRetorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int flagRetorno = -1;

		if(this != NULL && sueldo >= 0)
		{
			this -> sueldo =  sueldo;
			flagRetorno = 0;
		}
	return flagRetorno;

}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int flagRetorno = -1;

		if(this != NULL && sueldo != NULL)
		{
			 *sueldo = this -> sueldo;
			 flagRetorno = 0;
		}
	return flagRetorno;
}

void employee_print(LinkedList* pArrayEmployee, int index)
{
	Employee* pEmployee = NULL;
	int id;
	char nombre[100];
	int horas;
	int sueldo;

	if(pArrayEmployee != NULL && index >= 0)
	{
		pEmployee = ll_get(pArrayEmployee, index);
		if(pEmployee != NULL &&
		   employee_getId(pEmployee,&id) == 0 &&
		   employee_getNombre(pEmployee, nombre) == 0 &&
		   employee_getHorasTrabajadas(pEmployee, &horas) == 0 &&
		   employee_getSueldo(pEmployee, &sueldo) == 0)
		{
			printf("%4d %20s %15d     $%-10d\n",id,nombre,horas,sueldo);

		}
	}
}

int employee_searchForId(LinkedList* pArrayListEmployee, int id)
{
	Employee* pEmployee = NULL;
	int idAux;
	int returnedIndex;



if(pArrayListEmployee != NULL)
{
	for(int i= 0; i < ll_len(pArrayListEmployee); i++)
	{
		pEmployee = ll_get(pArrayListEmployee,i);
		if(pEmployee != NULL && employee_getId(pEmployee, &idAux) == 0 && id == idAux)
		{
			returnedIndex = i;
		}
	}
}
	return returnedIndex;
}


int employee_SortByName(void* elementOne, void* elementTwo)
{

	char nombreUno[50];
	char nombreDos[50];
	int flagRetorno;

	employee_getNombre(elementOne, nombreUno);
	employee_getNombre(elementTwo, nombreDos);

	flagRetorno = strcmp(nombreUno,nombreDos);


	return flagRetorno;
}

int employee_SortById(void* elementOne, void* elementTwo)
{
	int auxIdUno;
	int auxIdDos;
	int flagRetorno = 0;

	employee_getId(elementOne, &auxIdUno);
	employee_getId(elementTwo,&auxIdDos);

	if(auxIdUno > auxIdDos)
	{
		flagRetorno = 1;
	}
	if(auxIdUno < auxIdDos)
	{
		flagRetorno = -1;
	}

	return flagRetorno;
}

int employee_SortBySalary(void* elementOne, void* elementTwo)
{
	int auxSueldoUno;
	int auxSueldoDos;
	int flagRetorno = 0;

		employee_getSueldo(elementOne, &auxSueldoUno);
		employee_getSueldo(elementTwo,&auxSueldoDos);

		if(auxSueldoUno > auxSueldoDos)
		{
			flagRetorno = 1;
		}
		if(auxSueldoUno < auxSueldoDos)
		{
			flagRetorno = -1;
		}

	return flagRetorno;
}

int employee_SortByHours(void* elementOne, void* elementTwo)
{
	int auxHorasUno;
	int auxHorasDos;
	int flagRetorno = 0;

		employee_getHorasTrabajadas(elementOne, &auxHorasUno);
		employee_getHorasTrabajadas(elementTwo,&auxHorasDos);

		if(auxHorasUno > auxHorasDos)
		{
			flagRetorno = 1;
		}
		if(auxHorasUno < auxHorasDos)
		{
			flagRetorno = -1;
		}

	return flagRetorno;
}
