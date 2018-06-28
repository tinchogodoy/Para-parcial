#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "utn.h"
#include "cliente.h"


int controller_leerArchivoClientes(char* path, ArrayList* pArrayClientes)
{
    char bNombre[4096];
    char bApellido[4096];
    char bDni[4096];
   /* char bEmail[4096];
    char bGenero[4096];
    char bProfesion[4096];
    char bNacionalidad[4096];
    char bUsuario[4096];*/
    char bId[4096];
    Cliente* pAuxiliarCliente;
    FILE* pFile;
    int retorno = -1;
    pFile = fopen(path,"r");
    if(pFile != NULL)
    {
        retorno = 0;
        fscanf(pFile," %[^,],%[^,],\
                %[^,],%[^\n]\n",
                    bId,
                    bNombre,
                    bApellido,
                    bDni
                   /* bEmail,
                    bGenero,
                    bProfesion,
                    bUsuario,
                    bNacionalidad*/
                    );

        while(!feof(pFile))
        {
            fscanf(pFile,"  %[^,],%[^,],\
                            %[^,],%[^\n]\n",
                                bId,
                                bNombre,
                                bApellido,
                                bDni
                              /*  bEmail,
                                bGenero,
                                bProfesion,
                                bUsuario,
                                bNacionalidad*/
                                );

            pAuxiliarCliente = cliente_newParametros(   bNombre,
                                                        bApellido,
                                                        atoi(bDni),
                                                    /*  bEmail,
                                                        bGenero,
                                                        bProfesion,
                                                        bNacionalidad,
                                                        bUsuario,*/
                                                        atoi(bId));

            al_add(pArrayClientes,pAuxiliarCliente);
        }
    }
    fclose(pFile);
    printf("\n archivo cargado!\n");
    return retorno;
}

/*int controller_altaCliente(ArrayList* pArrayClientes)
{
    Cliente* pAuxiliarCliente;
    int retorno = -1;
    char nombre[64];
    char apellido[64];
    char dni[14];

    if(pArrayClientes != NULL)
    {
        retorno = 0;
        cliente_setParametros(nombre,apellido,dni);
        pAuxiliarCliente = cliente_newParametrosString(-1,nombre,apellido,dni);
        al_add(pArrayClientes,pAuxiliarCliente);
    }
    return retorno;
}*/
int controller_listarClientes(ArrayList* pArrayClientes)
{
    int retorno = -1;
    int i;
    Cliente* auxiliarCliente;
    char nombre[64];
    char apellido[64];
    int dni;
   // char email[256];
   // char genero;
   // char profesion[256];
   // char nacionalidad[256];
  //  char usuario[64];
    int id;
    printf("\nId_cliente\tNombre_cliente\tApellido_cliente\tDni_cliente\n");
    for(i=0;i<al_len(pArrayClientes);i++)
    {
        auxiliarCliente = al_get(pArrayClientes,i);
        cliente_getId(auxiliarCliente,&id);
        cliente_getNombre(auxiliarCliente,nombre);
        cliente_getApellido(auxiliarCliente,apellido);
        cliente_getDni(auxiliarCliente,&dni);
        printf("\n%10d\t%14s\t%16s\t%11d",id,nombre,apellido,dni);
    }
    return retorno;
}

int controller_ordenarClientesNombreApellido(ArrayList* pArrayClientes)
{
    int retorno = -1;
    if(pArrayClientes != NULL)
    {
        retorno = 0;
        al_sort(pArrayClientes,cliente_ordenarNombreApellido,1);
    }
    return retorno;
}

int controller_ordenarClientesApellidoNombre(ArrayList* pArrayClientes)
{
    int retorno = -1;
    if(pArrayClientes != NULL)
    {
        retorno = 0;
        al_sort(pArrayClientes,cliente_ordenarApellidoNombre,1);
    }
    return retorno;
}

int controller_guardarClientesArchivo(char* path, ArrayList* pArrayClientes)
{
    int retorno = -1;
    int i;
    Cliente* auxiliarCliente;
    char nombre[64];
    char apellido[64];
    int dni;
  /*char email[256];
    char genero;
    char profesion[256];
    char nacionalidad[256];
    char usuario[64];*/
    int id;
    FILE* pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL)
    {
    printf("\nGuardando archivo: %s...\n",path);
    fprintf(pFile,"id,nombre,apellido,dni\n");
        for(i=0;i<al_len(pArrayClientes);i++)
        {
            auxiliarCliente = al_get(pArrayClientes,i);
            cliente_getId(auxiliarCliente,&id);
            cliente_getNombre(auxiliarCliente,nombre);
            cliente_getApellido(auxiliarCliente,apellido);
            cliente_getDni(auxiliarCliente,&dni);
           // cliente_getEmail(auxiliarCliente,email);
           // cliente_getGenero(auxiliarCliente,&genero);
          //  cliente_getProfesion(auxiliarCliente,profesion);
           // cliente_getNacionalidad(auxiliarCliente,nacionalidad);
           // cliente_getUsuario(auxiliarCliente,usuario);
            fprintf(pFile,"%d,%s,%s,%d\n",id,nombre,apellido,dni);
            //fprintf(stdout,"%d,%s,%s,%d\n",id,nombre,apellido,dni);
        }
    }
    fclose(pFile);
    printf("\nArchivo: %s guardado!\n",path);
    return retorno;
}
