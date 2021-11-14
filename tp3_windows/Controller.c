#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Validations.h"
#include "parser.h"

int increaseId(char* path)
{
	FILE* pIdFile = NULL;
	int idAux;

	pIdFile = fopen(path, "rb");

	if(pIdFile !=NULL)
	{
		fread(&idAux,sizeof(int),1,pIdFile);
		idAux ++;
	}
	fclose(pIdFile);

	pIdFile = fopen(path, "wb");
	if(pIdFile != NULL)
	{
		fwrite(&idAux,sizeof(int),1,pIdFile);
	}
	fclose(pIdFile);
	return idAux;
}

int id_Max(char* path)
{
	FILE* pFile = NULL;
	pFile = fopen(path,"r");
	int idAux;
	if(pFile !=NULL)
	{
		fread(&idAux,sizeof(int),1,pFile);
	}
	fclose(pFile);

	return idAux;
}

int CheckListStatus(LinkedList* pArrayListEmployee)
{

	int status = -1;
	if(ll_isEmpty(pArrayListEmployee) == 0 )
	{
		status = 0;
	}
	return status;
}

int CheckOverwriteData(LinkedList* pList)
{
	int flagRetorno;
	int option;
	if(ll_isEmpty(pList) == 1)
	{
		printf("No se cargo la lista previamente\n¿Estas seguro que quieres dar el alta a un empleado?\nPuede que los datos se sobrescriban\n1-CONTINUAR\n2-SALIR ");
		option=EnterNumberInt("Selecciona una opcion: ", "\nError, selecciona una opcion valida\n", 2,1);
		switch(option)
		{
		case 1:
			flagRetorno =-1;
			break;
		case 2:
			flagRetorno = 0;
		}
	}
	return flagRetorno;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile = NULL;
	int flagRetorno = -1;
	int listaCargada;

	pFile = fopen(path,"r");
	if(pFile != NULL)
	{
		listaCargada = parser_EmployeeFromText(pFile, pArrayListEmployee);
		if(listaCargada == 0 )
		{
			flagRetorno = 0;
		}
	}

	fclose(pFile);
    return flagRetorno;
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
	FILE* pFile;
	int flagRetorno = -1 ;
	int listaBinariaCargada;

	pFile = fopen(path,"rb");
	if(pFile != NULL)
	{
		listaBinariaCargada = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		if (listaBinariaCargada == 0)
		{
			flagRetorno = 0;
		}
	}
	fclose(pFile);

    return flagRetorno;
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

	int flagRetorno = -1;
	printf("  ID                Nombre          Horas     Sueldo\n");
	if(pArrayListEmployee != NULL)
	{
		for(int i= 0; i < ll_len(pArrayListEmployee); i ++)
		{
				  employee_print(pArrayListEmployee, i);
				  flagRetorno = 0;
		}
	}
    return flagRetorno;
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
	Employee* pEmployee;
	int flagRetorno = -1;

	char nombre[100];
	char id[100];
	char horas[100];
	char sueldo[100];
	int auxHoras;
	int auxSueldo;
	int auxId;



	if(pArrayListEmployee != NULL)
	{
	printf("*ALTA DE EMPLEADOS*\n");

	  	auxId = increaseId("idFile.bin");
	  	printf("USER ID: %d\n",auxId);

	  	EnterString("Ingrese el nombre del nuevo empleado: ", nombre);
	  	NormalizeString(nombre);

	  	auxHoras = EnterNumberInt("Ingrese las horas mensuales trabajadas: "
	  			,"\nError, verifique que los datos sean correctos\n",744,1);

	  	auxSueldo = EnterNumberInt("Ingrese el sueldo del empleado: "
	  			,"\nError, verifique que los datos sean correctos\n",10000000,1);
	  	itoa(auxId,id,10);
	  	itoa(auxHoras,horas,10);
	  	itoa(auxSueldo,sueldo,10);
	  	pEmployee = employee_newParametros(id, nombre, horas, sueldo);
	  	if(pEmployee != NULL)
	  	{
	  	ll_add(pArrayListEmployee, pEmployee);
	  	flagRetorno = 0;
	  	}
	}

    return flagRetorno;
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
  Employee* pEmployee = NULL;
  int flagRetorno = -1;
  int id;
  int option;
  int index;
  char auxNombre[50];
  int auxHoras;
  int auxSueldo;
  int idMax;

  idMax = id_Max("idFile.bin");
  if(pArrayListEmployee != NULL)
  {

   controller_ListEmployee(pArrayListEmployee);
   id = EnterNumberInt("Ingrese el ID del usuario a modificar: "
		   ,"\nError. El id ingresado no existe\n", idMax, 1);

   index = employee_searchForId(pArrayListEmployee,id);
   pEmployee = ll_get(pArrayListEmployee, index);

	 if(id == pEmployee->id && pEmployee != NULL)
	 {
		 printf("\n1-Nombre\n2-Horas Trabajadas\n3-Sueldo\n0-Salir\n");
		 option = EnterNumberInt("Ingrese que desea modificar: "
		,"\nError, verifique que la opcion ingresada sea valida\n", 3, 0);

				switch(option)
				{
				case 1:
					EnterString("Ingrese el nombre del usuario a modificar: ", auxNombre);
					NormalizeString(auxNombre);
					employee_setNombre(pEmployee, auxNombre);
					flagRetorno = 0;
					break;
				case 2:
					auxHoras = EnterNumberInt("Ingrese las horas trabajadas a modificar: ",
							"\nError, verifique que los datos sean correctos\n",744, 1);
					employee_setHorasTrabajadas(pEmployee, auxHoras);
					flagRetorno = 0;
					break;

				case 3:
					auxSueldo = EnterNumberInt("Ingrese el sueldo a cambiar: ",
							"\nError, verifique que los datos sean correctos\n", 10000000, 1);
					employee_setSueldo(pEmployee, auxSueldo);
					flagRetorno = 0;
					break;

				case 0:
					flagRetorno = 1;
					break;
				}
		}
  }
  return flagRetorno;
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
	int flagRetorno = -1;
	int id;
	int index;
	Employee* pEmployee;
	int idMax;
	int option;

	 idMax = id_Max("idFile.bin");
	if(pArrayListEmployee != NULL)
	  {
	printf("||ID                Nombre          Horas     Sueldo||\n");
	   controller_ListEmployee(pArrayListEmployee);
	   id = EnterNumberInt("Ingrese el ID del usuario a modificar"
			   ,"\nError. El id ingresado no existe\n", idMax, 1);
	   index = employee_searchForId(pArrayListEmployee,id);
	   pEmployee = ll_get(pArrayListEmployee, index);

				if(id == pEmployee->id && pEmployee != NULL)
				{
					printf("  ID                Nombre          Horas     Sueldo\n");
					employee_print(pArrayListEmployee, index);
					option= EnterNumberInt("Esta seguro que desea elminiar al empleado?\n1-Si\n2-No", "Error, seleccione una opcion valida", 2, 1);

					switch(option)
					{
					case 1:

						ll_remove(pArrayListEmployee, index);
					    employee_delete(pEmployee);
					    flagRetorno = 0;
					    break;

					case 2:
						flagRetorno = 1;
						break;
					}
				}

	  }
    return flagRetorno;
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
	int option;
	int flagRetorno;
	printf("Ordenar lista por\n1-Nombre.\n2-ID\n3-Sueldo\n4-Horas trabajadas\n0-Volver al menu principal");
	option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 4, 0);
	if(pArrayListEmployee != NULL)
	{
		switch(option)
		{
			case 1:
				printf("\nOrdenar por nombre\n1-De manera ascendente(A-Z)\n2-De manera descendente(Z-A)");
				option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 2, 1);
				switch(option)
				{
					case 1:
						printf("Esto puede demorar unos segundos...");
						ll_sort(pArrayListEmployee,employee_SortByName,1);
						flagRetorno = 0;
						break;
					case 2:
						printf("Esto puede demorar unos segundos...");
						ll_sort(pArrayListEmployee,employee_SortByName,0);
						flagRetorno = 0;
						break;
				}
				break;

			case 2:
				printf("\nOrdenar ID\n1-De manera ascendente\n2-De manera descendente\n");
				option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 2, 1);
				switch(option)
				{
					case 1:
						printf("Esto puede demorar unos segundos...");
						ll_sort(pArrayListEmployee,employee_SortById,1);
						flagRetorno = 0;
						break;
					case 2:
						printf("Esto puede demorar unos segundos...");
						ll_sort(pArrayListEmployee,employee_SortById,0);
						flagRetorno = 0;
						break;
				}
				break;
			case 3:
			printf("\nOrdenar Sueldo\n1-De manera ascendente\n2-De manera descendente\n");
			option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 2, 1);
					switch(option)
					{
						case 1:
							printf("Esto puede demorar unos segundos...");
							ll_sort(pArrayListEmployee,employee_SortBySalary,1);
							flagRetorno = 0;
							break;
						case 2:
							printf("Esto puede demorar unos segundos...");
							ll_sort(pArrayListEmployee,employee_SortBySalary,0);
							flagRetorno = 0;
							break;
					}
				break;
			case 4:
			printf("\nOrdenar Horas Trabajadas\n1-De manera ascendente\n2-De manera descendente\n");
			option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 2, 1);
					switch(option)
					{
						case 1:
							printf("Esto puede demorar unos segundos...");
							ll_sort(pArrayListEmployee,employee_SortByHours,1);
							flagRetorno = 0;
							break;
						case 2:
							printf("Esto puede demorar unos segundos...");
							ll_sort(pArrayListEmployee,employee_SortByHours,0);
							flagRetorno = 0;
							break;
					}
			   break;
			   case 0 :
				   flagRetorno = -1;
				   break;
		}

	}
    return flagRetorno;
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
	FILE* pFile = NULL;
	int flagRetorno = -1;
	Employee* pEmployee = NULL;
	int auxId;
	char auxNombre[100];
	int auxHoras;
	int auxSueldo;

	if(pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
			for(int i=0; i<ll_len(pArrayListEmployee); i ++)
			{
				pEmployee = ll_get(pArrayListEmployee, i);
				if(pEmployee != NULL)
				{
					if(employee_getId(pEmployee, &auxId)== 0 &&
						employee_getNombre(pEmployee, auxNombre) == 0 &&
						employee_getHorasTrabajadas(pEmployee, &auxHoras) == 0 &&
						employee_getSueldo(pEmployee, &auxSueldo)== 0)
					{
						fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
						flagRetorno = 0;
					}

				}

			}
		}
		fclose(pFile);
	}
    return flagRetorno;
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
	FILE* pFile = NULL;
	int flagRetorno = -1;
	Employee* pEmployee = NULL;

	if(pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"wb");
		if(pFile !=NULL)
		{


			for(int i = 0; i<ll_len(pArrayListEmployee); i++)
			{
				pEmployee = ll_get(pArrayListEmployee,i);
				if(pEmployee !=NULL)
				{
					fwrite(pEmployee,sizeof(Employee),1,pFile);
					flagRetorno = 0;
				}
			}
		}
	}
    return flagRetorno;
}

int controller_overWriteText(LinkedList* pList)
{
	int option;
	int flagRetorno = 0;
	printf("Estas a punto de sobrescribir los datos, ¿Deseas continuar?\n1-CONTINUAR\n2-SALIR\n");
	option=EnterNumberInt("Selecciona una opcion: ", "\nError, selecciona una opcion valida\n", 2,1);
		switch(option)
		{
		case 1:
		  if(controller_saveAsText("data.csv", pList) == 0)
		  {
			  flagRetorno = -1;
			  printf("\nSe guardo correctamente el archivo\n\n");
		  }
		  break;


		case 2:
		break;
		}
		return flagRetorno;
}
int controller_overWriteBin(LinkedList* pList)
{
	int option;
	int flagRetorno = 0;
	printf("Estas a punto de sobrescribir los datos, ¿Deseas continuar?\n1-CONTINUAR\n2-SALIR\n");
    option=EnterNumberInt("Selecciona una opcion: ", "\nError, selecciona una opcion valida\n", 2,1);
	   switch(option)
	  {
	  case 1:
		 if(controller_saveAsBinary("data.bin", pList) == 0)
		 {
			 	 flagRetorno = -1;
			  printf("\nSe guardo correctamente el archivo\n\n");
		 }
	  break;
	  case 2:
		  break;
	  }
	   return flagRetorno;
}

int controller_exit(LinkedList* pList, int flagSave)
{
	int option;
	int flagRetorno = -1;
	if(flagSave != 0)
	{
		printf("No se guardaron los cambios. ¿Desea salir?\n1-SI\n2-NO\n");
		option=EnterNumberInt("Selecciona una opcion: ", "\nError, selecciona una opcion valida\n", 2,1);
		switch(option)
		{
		case 1:
			ll_deleteLinkedList(pList);
			flagRetorno = -1;
		break;

		case 2:
			flagRetorno = 0;
			break;
		}
	}
	return flagRetorno;
}
