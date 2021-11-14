#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "Validations.h"

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

	setbuf(stdout,NULL);
    int option = 0;
    int status;
    int flagRetorno;
    int flagOverwrite;
    int flagSave = -1;



    LinkedList* listaEmpleados = ll_newLinkedList();

   /* if(generateIdFile("idFile.bin")==0) // Genero el valor del id en el archivo.bin
    {
    	printf("Se creo la lista Binaria\n");
    }
    else
    {
    	printf("Error al crear la lista Binaria\n");
    }*/




    do{

        	printf("*****************************************************\n");
        	printf(" Menu:\n");
        	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        	printf("3. Alta de empleado\n");
        	printf("4. Modificar datos de empleado\n");
        	printf("5. Baja de empleado\n");
        	printf("6. Listar empleados\n");
        	printf("7. Ordenar empleados\n");
        	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        	printf("10. Salir\n");
        	printf("*****************************************************\n");
        	option = EnterNumberInt("Ingrese una opcion: ","\nError, verifique que sea una opcion valida\n",10,1);
        	status = CheckListStatus(listaEmpleados);
        	while ((option != 3 && option != 1 && option != 2 &&  option != 10) && status == -1)
        	{
        		option = EnterNumberInt("Primero debe cargar un empleado para poder utilzar todas las funciones.\nIngrese una opcion: ",
        				"Error. Primero debe cargar un empleado para poder utilzar todas las funciones.\n",10,1);
        	}



        	switch(option)
        	{
            case 1:

            	flagOverwrite =controller_loadFromText("data.csv",listaEmpleados);
                if(flagOverwrite == 0)
                {

                	printf("\nLa lista se cargo correctamente\n\n");
                }
                else
                {
                	printf("\nEror, la lista se cargo previamente\n\n");
                }
                break;

            case 2:

            	flagOverwrite = controller_loadFromBinary("data.bin", listaEmpleados);
            	if(flagOverwrite == 0)
            	{

            		printf("\nLa lista se cargo correctamente\n\n");
                }
            	else
            	{
          	      	printf("\nError, la lista se cargo previamente\n\n");
            	}
                break;

            case 3:
            	flagOverwrite = CheckOverwriteData(listaEmpleados);
            	if(flagOverwrite == -1 || ll_isEmpty(listaEmpleados)== 0)
            	{
            		if(controller_addEmployee(listaEmpleados) == 0)
            		{
            			printf("\nSe cargo al empleado correctamente\n\n");
            		}
            		else
            		{
            			printf("\nHubo un error al cargar el empleado\n\n");
            		}
            		break;
            	}break;
            case 4:
            	flagRetorno = controller_editEmployee(listaEmpleados);
            	if(flagRetorno==0)
            	{
            		printf("\n Se modifico al empleado correctamente\n\n");

            	}
            	else if(flagRetorno==1)
            	{
            		printf("\nSe cancelo la operacion\n\n");

            	}
            	else
            	{
            		printf("\n No se ha encontrado al usuario\n\n");
            	}
            	break;

            case 5:
            	flagRetorno=controller_removeEmployee(listaEmpleados);
            	if(flagRetorno==0)
            	{
            		printf("\n Se removio al empleado correctamente\n\n");
            	}
            	else if(flagRetorno == 1)
				{
            		printf("\nSe ha cancelado la operacion\n\n");
				}
            	else
            	{
            		printf("\n No se ha encontrado al usuario\n\n");
            	}


            	break;
            case 6:
            	 if(controller_ListEmployee(listaEmpleados) == 0)
            	 {
            		 printf("\nLa lista se cargo correctamente\n\n");
            	 }
            	 else
            	 {
            		 printf("\nError al cargar la lista\n\n");
            	 }
            	 break;
            case 7:
				if(controller_sortEmployee(listaEmpleados)==0)
				{
					printf("\nLa lista se ordeno correctamente\n\n");

				}
				else
				{
					printf("\nSe cancelo la operacion\n\n");
				}
				break;
            case 8:
            	if(flagOverwrite!= 0)
            	{
            		if(controller_overWriteText(listaEmpleados)== 0)
            		{
            			printf("\nSe ha cancelado la operacion\n");
            		}
            		else
            		{
            			flagSave = 0;

            		}
            	break;
            	}
            	if(controller_saveAsText("data.csv", listaEmpleados) == 0)
            	{
            		flagSave = 0;
            		printf("\nSe guardo correctamente el archivo\n\n");
            	}
            	break;
            case 9:
            	if(flagOverwrite != 0)
               	{
            	   if(controller_overWriteBin(listaEmpleados)==0)
            	   {
            		   printf("\nSe ha cancelado la operacion\n");
            	   }
            	   else
            	   {
            		   flagSave = 0;
            	   }
            	   break;
               	}
            	   if(controller_saveAsBinary("data.bin", listaEmpleados) == 0)
            	   {
            		   flagSave = 0;
            		   printf("\nSe guardo correctamente el archivo\n\n");
            	   }

            	break;

            case 10:
            	if(ll_isEmpty(listaEmpleados) == 0)
            	{
            		if(controller_exit(listaEmpleados,flagSave)== 0)
            		{

            			printf("\nSe ha cancelado la operacion\n\n");
            			option = 0;
            		}
            	}
            	break;


        }
    }while(option != 10);
    return EXIT_SUCCESS;
}

