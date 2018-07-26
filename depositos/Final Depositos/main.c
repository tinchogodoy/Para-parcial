#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Parser.h"
#include "depositos.h"
#include "utn.h"
int main()
{
    ArrayList* listaDeposito1;
    ArrayList* listaDeposito2;
    listaDeposito1=al_newArrayList();
    listaDeposito2=al_newArrayList();

    int menuOpcionElegida;
    int menu;
    char menuPrinsipalMensaje[] =
                "   \n\n1. Cargar depositos\
                    \n2. Listar productos de deposito\
                    \n3. Mover productos a deposito\
                    \n4. Descontar productos de depositos\
                    \n5. Agregar productos a deposito\
                    \n6. Salir\n\
                    \nIngrese opcion: ";

    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 6";

    do
    {
        menuOpcionElegida = 0;
        getValidInt(menuPrinsipalMensaje,menuPrinsipalMensajeError, &menuOpcionElegida , 0 , 6 , 2 );

        switch(menuOpcionElegida)
        {
        case 1:
            //printf("\n\tALTA CLIENTE:\n");
            if(parser_parseDepositos("dep3.csv",listaDeposito1)==1 && parser_parseDepositos("dep4.csv",listaDeposito2)==1)

            break;
        case 2:
            //printf("\n\tMODIFICAR DATOS CLIENTE:\n");
            getValidInt("\nlistar deposito 1 o 2?","\nERROR!", &menu, 0 , 2 , 2 );
            if(menu==1)
            {
              parser_listarDepositos(listaDeposito1);
            }
            else if(menu==2)
            {
              parser_listarDepositos(listaDeposito2);
            }
            break;
        case 3:
            //printf("\n\tBAJA CLIENTE:\n");
            if(parser_moverDepositos(listaDeposito1,listaDeposito2))
            {
                parser_guardarArchivosDepositos("dep3.csv",listaDeposito1);
                parser_guardarArchivosDepositos("dep4.csv",listaDeposito2);
            }

            break;
        case 4:
            //printf("\n\tLISTAR CLIENTES:\n");
            if(parser_descontarProductos(listaDeposito1,listaDeposito2))
            {
                parser_guardarArchivosDepositos("dep3.csv",listaDeposito1);
                parser_guardarArchivosDepositos("dep4.csv",listaDeposito2);
            }

            break;
        case 5:
            //printf("\n\tREALIZAR UNA VENTA:\n");
            if((parser_agregarProductos(listaDeposito1,listaDeposito2))==0)
            {
                parser_guardarArchivosDepositos("dep3.csv",listaDeposito1);
                parser_guardarArchivosDepositos("dep4.csv",listaDeposito2);
            }

            break;
        case 6:
                parser_guardarArchivosDepositos("dep3.csv",listaDeposito1);
                parser_guardarArchivosDepositos("dep4.csv",listaDeposito2);
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

