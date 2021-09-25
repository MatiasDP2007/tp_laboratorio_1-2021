#include "PrototiposCalculadora.h"
/// @param numeroUno
/// @param numeroDos
void MostrarMenu (float numeroUno,float  numeroDos)
{

    printf("///Calculadora/// \n");
    printf("1. Ingresar 1er operando (A=%.2f)\n",numeroUno);
    printf("2. Ingresar 2do operando (B=%.2f)\n",numeroDos);
    printf("3. Calcular todas las operaciones \n");
    printf(" a) Calcular la suma (A+B)\n");
    printf(" b) Calcular la resta (A-B)\n");
    printf(" c) Calcular la division (A/B)\n");
    printf(" d) Calcular la multiplicacion (A*B)\n");
    printf(" e) Calcular el factorial (A!)\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n");
    printf("\n");
    printf("\n");
    printf("Opcion: ");

}


/// @param flagValidacionOperadorUno
/// @param flagValidacionOperadorDos
/// @return
int ValidadorDeOpciones (int flagValidacionOperadorUno,int flagValidacionOperadorDos)
{
    int opcion;

    scanf("%d", &opcion);

    while ((opcion < 1 ||  opcion > 5 ) || ((flagValidacionOperadorUno || flagValidacionOperadorDos)  && (opcion == 3 || opcion == 4)))
    {

        if (opcion < 1 || opcion > 5)
        {
        printf("Error. Seleccione una opcion valida\n");
        }
        else
        {
        printf("Error. No se puede realizar una operacion sin ingresar operandos\n");
        }
        scanf("%d", &opcion);
    }
    return opcion;
}
/// @return
float IngresarOperando()
{
    float numeroIngresado;
    scanf("%f", &numeroIngresado);
    return numeroIngresado;
}
/// @param ejecutarOpcion
/// @param numeroUno
/// @param numeroDos
void OpcionSeleccionada(int ejecutarOpcion, float numeroUno, float numeroDos)
{
 float sumaOperandos;
 float restaOperandos;
 float multiplicacionOperandos;
 float divisionOperandos;
 float factoreoOperandoUno;
 float factoreoOperandoDos;
 int numeroEnteroFactoreoUno;
 int numeroEnteroFactoreoDos;

 switch (ejecutarOpcion)
 {

    case 3:

    system("cls");
    printf(" El calculo de las las operaciones es: \n");
    printf(" Calcular la suma de (%.2f+%.2f)\n",numeroUno, numeroDos);
    printf(" Calcular la resta de (%.2f-%.2f)\n",numeroUno, numeroDos);
    printf(" Calcular la division de (%.2f/%.2f\n",numeroUno, numeroDos);
    printf(" Calcular la multiplicaon de (%.2f*%.2f)\n",numeroUno, numeroDos);
    printf(" Calcular el factorial de (!%.2f y !%.2f)\n",numeroUno, numeroDos);
    printf("\n");
    printf("\n");
    break;

    case 4:

    system("cls");
     sumaOperandos = SumarOperandos(numeroUno, numeroDos);
     printf("El resultado de %.2f+%.2f es: %.2f\n",numeroUno,numeroDos,sumaOperandos);

     restaOperandos = RestarOperandos(numeroUno,numeroDos);
     printf("El resultado de %.2f-%.2f es: %.2f\n",numeroUno,numeroDos,restaOperandos);

     multiplicacionOperandos = MultiplicarOperandos(numeroUno, numeroDos);
     printf("El resultado de %.2f*%.2f es: %.2f\n",numeroUno,numeroDos,multiplicacionOperandos);

     divisionOperandos = DividirOperandos(numeroUno, numeroDos);

     if(numeroDos==0)
     {
        printf("No es posible dividir por 0\n");
     }
     else
     {
     printf("El resultado de %.2f/%.2f es: %.2f\n",numeroUno,numeroDos,divisionOperandos);
     }

     factoreoOperandoUno = FactorialOperandoUno(numeroUno);
     factoreoOperandoDos = FactorialOperandoDos(numeroDos);

     numeroEnteroFactoreoUno=numeroUno;
     numeroEnteroFactoreoDos=numeroDos;

      if(numeroEnteroFactoreoUno - numeroUno != 0 || numeroEnteroFactoreoDos  - numeroDos != 0)
     {
         printf("No se puede calcular un factorial con un numero decimal\n");
     }
     else
     {
      if ( numeroUno  > 12)
      {
       printf("Numero factorial muy alto\n");
      }
      else
      {
     printf("El factorial de A (%.2f) es: %.0lf \n",numeroUno,factoreoOperandoUno);
      }
     if (numeroDos > 12)
      {
       printf("Numero factorial muy alto\n");
      }
     else if (numeroEnteroFactoreoDos - numeroDos == 0)
     {
     printf("El factorial de B (%.2f) es: %.0lf\n",numeroDos,factoreoOperandoDos);
     }
     printf("\n");
     printf("\n");
     break;
  }
 }
}
/// @param numeroUno
/// @param numeroDos
/// @return
float SumarOperandos(float numeroUno,float numeroDos)
{
float resultado;
resultado = numeroUno + numeroDos;
return resultado;
}
/// @param numeroUno
/// @param numeroDos
/// @return
float RestarOperandos(float numeroUno,float numeroDos)
{
 float resultado;
 resultado = numeroUno - numeroDos;
 return resultado;
}
/// @param numeroUno
/// @param numeroDos
/// @return
float MultiplicarOperandos(float numeroUno, float numeroDos)
{
float resultado;
resultado = numeroUno * numeroDos ;
return resultado;
}
/// @param numeroUno
/// @param numeroDos
/// @return
float DividirOperandos(float numeroUno, float numeroDos)
{
    float resultado;
     resultado = numeroUno/numeroDos;
    return resultado;
}
/// @param numeroUno
/// @return
float FactorialOperandoUno(float numeroUno)
{
    int resultadoNumeroUno;

    resultadoNumeroUno = 1;
    if (numeroUno>1)
    {
    while(numeroUno > 1 )
      {
       resultadoNumeroUno *= numeroUno;
       numeroUno--;
      }

    }
    else
    {
        while(numeroUno < -1)
      {
       resultadoNumeroUno *= numeroUno;
       numeroUno++;
      }
      if (resultadoNumeroUno > 0)
      {
       resultadoNumeroUno *= -1;
      }
    }
    return resultadoNumeroUno;
}
/// @param numeroDos
/// @return
float FactorialOperandoDos(float numeroDos)
{
    int resultadoNumeroDos;

    resultadoNumeroDos = 1;
    if (numeroDos > 1)
    {
     while(numeroDos > 1 )
     {
       resultadoNumeroDos *= numeroDos;
       numeroDos--;
     }

    }
    else
    {
        while(numeroDos < -1 )
      {
       resultadoNumeroDos *= numeroDos;
       numeroDos++;
      }
     if(resultadoNumeroDos > 0)
     {
     resultadoNumeroDos *= -1 ;
     }
    }
     return resultadoNumeroDos;
}

