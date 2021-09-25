
#include <stdio.h>
#include <stdlib.h>
#include "PrototiposCalculadora.h"
int main()
{
setbuf (stdout,NULL);
int flagValidacionOperadorUno = 1;
int flagValidacionOperadorDos = 1;
int ejecutarOpcion;
float numeroUno = 0;
float numeroDos = 0;


    do{
    MostrarMenu(numeroUno, numeroDos);
    ejecutarOpcion = ValidadorDeOpciones(flagValidacionOperadorUno, flagValidacionOperadorDos);

      if (ejecutarOpcion == 1)
     {
        system("cls");
        printf ("Ingresar 1er operando (A)\n");
        numeroUno = IngresarOperando();
        flagValidacionOperadorUno = 0;
        system("cls");
     }

    if (ejecutarOpcion == 2)
     {
    	system("cls");
        printf ("Ingresar 2do operando (B)\n");
         numeroDos = IngresarOperando();
        flagValidacionOperadorDos = 0;
        system("cls");
     }
     OpcionSeleccionada(ejecutarOpcion, numeroUno, numeroDos);
     system("cls");
    }while (ejecutarOpcion !=5);

    return EXIT_SUCCESS;
}


/*
              .@.                                    .
              @m@,.                                 .@
             .@m%nm@,.                            .@m@
            .@nvv%vnmm@,.                      .@mn%n@
           .@mnvvv%vvnnmm@,.                .@mmnv%vn@,
           @mmnnvvv%vvvvvnnmm@,.        .@mmnnvvv%vvnm@
           @mmnnvvvvv%vvvvvvnnmm@, ;;;@mmnnvvvvv%vvvnm@,
           `@mmnnvvvvvv%vvvvvnnmmm;;@mmnnvvvvvv%vvvvnmm@
            `@mmmnnvvvvvv%vvvnnmmm;%mmnnvvvvvv%vvvvnnmm@
              `@m%v%v%v%v%v;%;%;%;%;%;%;%%%vv%vvvvnnnmm@
              .,mm@@@@@mm%;;@@m@m@@m@@m@mm;;%%vvvnnnmm@;@,.
           .,@mmmmmmvv%%;;@@vmvvvvvvvvvmvm@@;;%%vvnnm@;%mmm@,
        .,@mmnnvvvvv%%;;@@vvvvv%%%%%%%vvvvmm@@;;%%mm@;%%nnnnm@,
     .,@mnnvv%v%v%v%%;;@mmvvvv%%;*;*;%%vvvvmmm@;;%m;%%v%v%v%vmm@,.
',@mnnvv%v%v%v%v%v%v%;;@@vvvv%%;*   *;%%vvvvm@@;;m%%%v%v%v%v%v%vnnm@,
      `@mnnvv%v%v%v%%;;@mvvvvv%%;;*;;%%vvvmmmm@;;%m;%%v%v%v%vmm@'    '
         `@mmnnvvvvv%%;;@@mvvvv%%%%%%%vvvvmm@@;;%%mm@;%%nnnnm@'
            `@mmmmmmvv%%;;@@mvvvvvvvvvvmmm@@;;%%mmnmm@;%mmm@'
               `mm@@@@@mm%;;@m@@m@m@m@@m@@;;%%vvvvvnmm@;@'
              ,@m%v%v%v%v%v;%;%;%;%;%;%;%;%vv%vvvvvnnmm@
            . @mmnnvvvvvvv%vvvvnnmm%mmnnvvvvvvv%vvvvnnmm@
            .@mmnnvvvvvv%vvvvvvnnmm'`@mmnnvvvvvv%vvvnnmm@
            @mmnvvvvv%vvvvvvnnmm@':%::`@mmnnvvvv%vvvnmm@'
           @mmnnvvv%vvvvvnnmm@'          `@mmnnvv%vvmm@
           `@mnvvvvv%vvnnmm@'                `@mvv%vm@'
           `@mnvv%vnnm@'                        `@n%n@
            `@mmm%m@'                             `@m@
              @m@'                                  `@
              `@'                                    '
               `                                                */
