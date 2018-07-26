#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoSueldos(char* fileName,ArrayList* listaEmpleados);

int main()
{
    // Definir lista de empleados
    ArrayList* listaEmpleados;

    // Crear lista empledos
    listaEmpleados=al_newArrayList();

    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados("data.csv",listaEmpleados)==1)
    {
        //parser_listarEmpleados(listaEmpleados);
        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");
        al_map(listaEmpleados,em_calcularSueldo);

        // Generar archivo de salida
        if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyando empleados\n");


    return 0;
}


int generarArchivoSueldos(char* fileName, ArrayList* listaEmpleados)
{
    int retorno = -1;
    int i;
    Empleado* auxEmpleado;
    int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
  /*char email[256];
    char genero;
    char profesion[256];
    char nacionalidad[256];
    char usuario[64];*/
    FILE* pFile;
    pFile = fopen(fileName,"w");
    if(pFile != NULL)
    {
    retorno=1;
    printf("\nGuardando archivo: %s...\n",fileName);
    fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0;i<al_len(listaEmpleados);i++)
        {
            auxEmpleado = al_get(listaEmpleados,i);
            em_getId(auxEmpleado,&id);
            em_getNombre(auxEmpleado,nombre);
            em_getHorasTrabajadas(auxEmpleado,&horasTrabajadas);
            em_getSueldo(auxEmpleado,&sueldo);
           // cliente_getEmail(auxEmpleado,email);
           // cliente_getGenero(auxEmpleado,&genero);
          //  cliente_getProfesion(auxEmpleado,profesion);
           // cliente_getNacionalidad(auxEmpleado,nacionalidad);
           // cliente_getUsuario(auxEmpleado,usuario);
            fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
            //fprintf(stdout,"%d,%s,%s,%d\n",id,nombre,apellido,sueldo);
        }
    }
    fclose(pFile);
    printf("\nArchivo: %s guardado!\n",fileName);
    return retorno;
}
