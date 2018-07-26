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
    int i=0;
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
                              /*bEmail,
                                bGenero,
                                bProfesion,
                                bUsuario,
                                bNacionalidad*/
                                );

            pAuxiliarCliente = cliente_newParametros(   bNombre,
                                                        bApellido,
                                                        bDni,
                                                    /*  bEmail,
                                                        bGenero,
                                                        bProfesion,
                                                        bNacionalidad,
                                                        bUsuario,*/
                                                        bId);

            al_add(pArrayClientes,pAuxiliarCliente);
            i++;
        }
        fclose(pFile);
       // cliente_delete(pAuxiliarCliente);
    }
    printf("\nFilas leidas desde archivo:%d\n",i);
    printf("\n archivo cargado!\n");
    return retorno;
}

int controller_altaCliente(ArrayList* pArrayClientes)
{
    Cliente* pAuxiliarCliente;
    int retorno = -1;
    char nombre[64];
    char apellido[64];
    char dni[14];

    if(pArrayClientes != NULL)
    {
        if(!cliente_newEnterParametros(nombre,apellido,dni))
        {
            retorno = 0;
            pAuxiliarCliente = cliente_newParametros(   nombre,
                                                        apellido,
                                                        dni,
                                                    /*  email,
                                                        genero,
                                                        profesion,
                                                        nacionalidad,
                                                        usuario,*/
                                                        "-1");
            al_add(pArrayClientes,pAuxiliarCliente);
            printf("Cliente cargado!\r\n");
        }else
        {
            printf("Cliente no fue cargado!\r\n");
        }
    }
    //cliente_delete(pAuxiliarCliente);
    return retorno;
}

int controller_modificarCliente(ArrayList* pArrayClientes)
{
    Cliente* pAuxiliarCliente;
    int retorno = -1;
    int id;
    int idCliente;
    char idChar[64];
    char nombre[64];
    char apellido[64];
    char dni[14];
    int exito;
    int i;

    if (pArrayClientes != NULL)
    {
        exito = getValidInt("\nIngrese el ID: ","\nIngrese un caracter valido!",&id,0,al_len(pArrayClientes)+1,2);
        if (!exito)
        {
            for(i=0;i<al_len(pArrayClientes);i++)
            {
                retorno = -2;
                pAuxiliarCliente = al_get(pArrayClientes,i);
                cliente_getId(pAuxiliarCliente,&idCliente);
                if(id == idCliente)
                {
                    retorno=-3;
                    itoa(idCliente,idChar,10);
                    if(!cliente_newEnterParametros(nombre,apellido,dni))
                    {
                        pAuxiliarCliente = cliente_newParametros( nombre,
                                                            apellido,
                                                            dni,
                                                        /*  email,
                                                            genero,
                                                            profesion,
                                                            nacionalidad,
                                                            usuario,*/
                                                            idChar);//cliente_newParametrosString(idCliente,nombre,apellido,dni);
                        al_set(pArrayClientes,i,pAuxiliarCliente);
                        retorno = 0;
                        printf("Cliente modificado!\r\n");
                        break;
                    }else
                    {
                        printf("Cliente no fue modificado!\r\n");
                        break;
                    }
                }
            }
             if(retorno==-2)
             {
                printf("No existe cliente con ese ID!\r\n");
             }
        }
    }
    //cliente_delete(pAuxiliarCliente);
    return retorno;
}

int controller_bajaCliente(ArrayList* pArrayClientes)
{
    Cliente* pAuxiliarCliente;
    int retorno = -1;
    int id;
    int idCliente;
    int exito;
    int i;

    if (pArrayClientes != NULL)
    {
        exito = getValidInt("\nIngrese el ID: ","\nIngrese un caracter valido!",&id,0,al_len(pArrayClientes),2);
        if (!exito)
        {
            for(i=0;i<al_len(pArrayClientes);i++)
            {
                pAuxiliarCliente = al_get(pArrayClientes,i);
                cliente_getId(pAuxiliarCliente,&idCliente);
                if(id == idCliente)
                {
                    retorno = 0;
                    al_remove(pArrayClientes,i);
                    break;
                }
            }
        }
    }
   //cliente_delete(pAuxiliarCliente);
    return retorno;
}

int controller_listarClientes(ArrayList* pArrayClientes)
{
    int retorno = -1;
    int i;
    Cliente* pAuxiliarCliente;
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
        pAuxiliarCliente = al_get(pArrayClientes,i);
        cliente_getId(pAuxiliarCliente,&id);
        cliente_getNombre(pAuxiliarCliente,nombre);
        cliente_getApellido(pAuxiliarCliente,apellido);
        cliente_getDni(pAuxiliarCliente,&dni);
        printf("\n%10d\t%14s\t%16s\t%11d",id,nombre,apellido,dni);
    }
   // cliente_delete(pAuxiliarCliente);
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
    Cliente* pAuxiliarCliente;
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
            pAuxiliarCliente = al_get(pArrayClientes,i);
            cliente_getId(pAuxiliarCliente,&id);
            cliente_getNombre(pAuxiliarCliente,nombre);
            cliente_getApellido(pAuxiliarCliente,apellido);
            cliente_getDni(pAuxiliarCliente,&dni);
           // cliente_getEmail(pAuxiliarCliente,email);
           // cliente_getGenero(pAuxiliarCliente,&genero);
          //  cliente_getProfesion(pAuxiliarCliente,profesion);
           // cliente_getNacionalidad(pAuxiliarCliente,nacionalidad);
           // cliente_getUsuario(pAuxiliarCliente,usuario);
            fprintf(pFile,"%d,%s,%s,%d\n",id,nombre,apellido,dni);
            //fprintf(stdout,"%d,%s,%s,%d\n",id,nombre,apellido,dni);
        }
    }
    fclose(pFile);
    printf("\nArchivo: %s guardado!\n",path);
    return retorno;
}


controller_altaVenta(ArrayList* pArrayVentas)
{
    Cliente* pAuxiliarVenta;
    int retorno = -1;
    int cantidadVendida;
    float precioTotal;
    int idVenta;
    int codigoProducto;
    int idCliente;

    if(pArrayVentas != NULL)
    {
        if(!venta_newEnterParametros(idCliente, codigoProducto, cantidadVendida))
        {
            retorno = 0;
            pAuxiliarVenta = venta_newParametros( idCliente, codigoProducto, cantidadVendida, "-1");
            al_add(pArrayVentas, pAuxiliarVenta);
            printf("Cliente cargado!\r\n");
        }else
        {
            printf("Cliente no fue cargado!\r\n");
        }
    }
    //cliente_delete(pAuxiliarCliente);
    return retorno;
}
