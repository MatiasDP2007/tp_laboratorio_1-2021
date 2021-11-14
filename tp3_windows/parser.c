#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Validations.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int flagRet = -1;
	char id[130];
	char nombre[130];
	char horasTrabajadas[130];
	char sueldo[130];
	int idValidado;
	int nombreValidado;
	int sueldoValidado;
	int horasValidadas;

	if(pFile !=NULL && pArrayListEmployee != NULL)
	{

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
		do{

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
			idValidado = ValidateNumberInt(id);
			nombreValidado = ValidateString(nombre);
			sueldoValidado = ValidateNumberInt(sueldo);
			horasValidadas = ValidateNumberInt(horasTrabajadas);
			printf("%4s %20s %15s     $%-10s\n",id,nombre,horasTrabajadas,sueldo);
			if(idValidado != -1 && nombreValidado != -1 && sueldoValidado != -1 && horasValidadas != -1) //Se valida que la lista no venga con un error previo
			{
				pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				if(pEmployee != NULL)
				{
					ll_add(pArrayListEmployee, pEmployee);
					flagRet = 0;
				}
			}

		}while(feof (pFile) == 0);
	}

    return flagRet;
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
	Employee* pEmployee= NULL;
	int flagRetorno = -1;

	if(pArrayListEmployee != NULL && pFile !=NULL)
	{
		do
		{
		pEmployee = employee_new();
			if(pEmployee != NULL)
				{
				if(fread(pEmployee,sizeof(Employee),1,pFile)== 1)
				{

					ll_add(pArrayListEmployee, pEmployee);
					flagRetorno = 0;
				}
			}
		}while(!feof(pFile));

	}
    return flagRetorno;
}

/*int generateIdFile(char* path)
{
	FILE* pGenerateId;
	int mainId = 1000;
	int flagRetorno = -1;

	pGenerateId = fopen(path,"wb");
	if(pGenerateId != NULL)
	{
		fwrite(&mainId,sizeof(int),1,pGenerateId);
		flagRetorno = 0;
	}
	fclose(pGenerateId);

	return flagRetorno;
}
*/
