#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Parser.h"
#include "reparto.h"
#include "utn.h"
int main()
{
    ArrayList* listaReparto;
   // ArrayList* listaDeposito2;
    listaReparto=al_newArrayList();
   // listaDeposito2=al_newArrayList();

    int menuOpcionElegida;
    int menu;
    char menuPrinsipalMensaje[] =
                "   \n\n1. Cargar archivo\
                    \n2. Imprimir entregas\
                    \n3. Imprimir localidades\
                    \n4. Generar archivo de reparto\
                    \n5. Salir\n\
                    \nIngrese opcion: ";

    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 5";

    do
    {
        menuOpcionElegida = 0;
        getValidInt(menuPrinsipalMensaje,menuPrinsipalMensajeError, &menuOpcionElegida , 0 , 5 , 2 );

        switch(menuOpcionElegida)
        {
        case 1:
            //printf("\n\tALTA CLIENTE:\n");
            //if(parser_parseDepositos("dep3.csv",listaReparto)==1 && parser_parseDepositos("dep4.csv",listaDeposito2)==1)
            parser_parseReparto("DATA_FINAL_V3.csv", listaReparto);

            break;
        case 2:
            //printf("\n\tMODIFICAR DATOS CLIENTE:\n");
           // getValidInt("\nlistar deposito 1 o 2?","\nERROR!", &menu, 0 , 2 , 2 );
           // if(menu==1)
          //  {
              parser_listarReparto(listaReparto);
           // }
          //  else if(menu==2)
          //  {
             // parser_listarDepositos(listaDeposito2);
          //  }
            break;
        case 3:
            //printf("\n\tBAJA CLIENTE:\n");
          parser_listarLocalidades(listaReparto);
          /*  if(parser_moverDepositos(listaReparto,listaDeposito2))
            {
                parser_guardarArchivosDepositos("dep3.csv",listaReparto);
                parser_guardarArchivosDepositos("dep4.csv",listaDeposito2);
            }*/

            break;
        case 4:
            //printf("\n\tLISTAR CLIENTES:\n");
          /*  if(parser_descontarProductos(listaReparto,listaDeposito2))
            {
                parser_guardarArchivosDepositos("dep3.csv",listaReparto);
                parser_guardarArchivosDepositos("dep4.csv",listaDeposito2);
            }*/

            break;
        case 5:
            //printf("\n\tREALIZAR UNA VENTA:\n");
          /*  if((parser_agregarProductos(listaReparto,listaDeposito2))==0)
            {
                parser_guardarArchivosDepositos("dep3.csv",listaReparto);
                parser_guardarArchivosDepositos("dep4.csv",listaDeposito2);
            }*/

            break;
        case 6:
         /*       parser_guardarArchivosDepositos("dep3.csv",listaReparto);
                parser_guardarArchivosDepositos("dep4.csv",listaDeposito2);*/
            exit(1);
            break;
        default:
            printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
            pause();
            break;
        }

    }while(menuOpcionElegida != 6);

    return 0;
    }
