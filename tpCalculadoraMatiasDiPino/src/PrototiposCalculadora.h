

#ifndef PROTOTIPOSCALCULADORA_H_
#define PROTOTIPOSCALCULADORA_H_

#include <stdio.h>
#include <stdlib.h>
/// @param numeroUno
/// @param numeroDos
void MostrarMenu(float numeroUno, float numeroDos);
/// @param flagValidacionOperadorUno
/// @param flagValidacionOperadorDos
/// @return
int ValidadorDeOpciones (int flagValidacionOperadorUno, int flagValidacionOperadorDos);
/// @param ejecutarOpcion
/// @param numeroUno
/// @param numeroDos
void  OpcionSeleccionada (int ejecutarOpcion, float numeroUno, float numeroDos);
/// @return
float IngresarOperando ();
/// @param numeroUno
/// @param numeroDos
/// @return
float SumarOperandos(float numeroUno, float numeroDos);
/// @param numeroUno
/// @param numeroDos
/// @return
float RestarOperandos(float numeroUno, float numeroDos);
/// @param numeroUno
/// @param numeroDos
/// @return
float MultiplicarOperandos(float numeroUno, float numeroDos);
/// @param numeroUno
/// @param numeroDos
/// @return
float DividirOperandos(float numeroUno, float numeroDos);
/// @param numeroUno
/// @return
float FactorialOperandoUno(float numeroUno);
/// @param numeroDos
/// @return
float FactorialOperandoDos(float numeroDos);




#endif
