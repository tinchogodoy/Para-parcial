#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "depositos.h"
#include "arrayList.h"

/*int parser_newParserBlackList(char*fileName, ArrayList* listaEmpleados)
{

    FILE* pFile = NULL;
    int auxReturn = -1;
    int id;
    char nombre[128];
    int horasTrabajadas;
    Empleado* auxEmpleado;
    pFile = fopen(fileName,"w");
    if(pFile!=NULL && listaEmpleados!=NULL && fileName!=NULL)
    {
        auxReturn = 0;
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas);
            //printf("\n%s-%s", nombre, horas);
            auxEmpleado = em_new();
            em_setId(auxEmpleado, id);
            em_setNombre(auxEmpleado, nombre);
            em_setHorasTrabajadas(auxEmpleado, horasTrabajadas);
            al_add(listaEmpleados, auxEmpleado);

        }
        fclose(pFile);
    }
    return auxReturn;
}
*/
int parser_parseDepositos(char* path, ArrayList* listaDepositos)
{
    char bIdProducto[4096];
    char bDescripcion[4096];
    char bCantidad[4096];

    Depositos* auxDepositos;
    FILE* pFile;
    int i=0;
    int retorno = -1;
    pFile = fopen(path,"r");
    if(pFile != NULL)
    {
        retorno = 1;
        fscanf(pFile," %[^,],%[^,],%[^\n]\n", bIdProducto, bDescripcion, bCantidad);
        while(!feof(pFile))
        {
            fscanf(pFile,"  %[^,],%[^,],%[^\n]\n", bIdProducto, bDescripcion, bCantidad);
            auxDepositos = depositos_newParametros( bIdProducto, bDescripcion, bCantidad);
            al_add(listaDepositos,auxDepositos);
            i++;
        }
        fclose(pFile);
    }
    printf("\nFilas leidas desde archivo:%d\n",i);
    printf("\nArchivo cargado!\n");
    return retorno;
}

/*int parser_parseEmpleadosConErrores(char* path, ArrayList* listaEmpleados, ArrayList* listaErroresEmpleados)
{
    char bId[4096];
    char bNombre[4096];
    char bHorasTrabajadas[4096];
    char bDni[4096];
    char bApellido[4096];
    char bDni[4096];
    char bEmail[4096];
    char bGenero[4096];
    char bProfesion[4096];
    char bNacionalidad[4096];
    char bUsuario[4096];

    Empleado* auxEmpleado;
    FILE* pFile;
    int i=0;
    int retorno = -1;
    pFile = fopen(path,"r");
    if(pFile != NULL)
    {
        retorno = 1;
        fscanf(pFile," %[^,],%[^,],%[^\n]\n",\
                    bId,
                    bNombre,
                    bHorasTrabajadas
                    bDni
                    bEmail,
                    bGenero,
                    bProfesion,
                    bUsuario,
                    bNacionalidad
                    );
        while(!feof(pFile))
        {
            fscanf(pFile,"  %[^,],%[^,],%[^\n]\n",\
                                bId,
                                bNombre,
                                bHorasTrabajadas
                                bDni,
                                bEmail,
                                bGenero,
                                bProfesion,
                                bUsuario,
                                bNacionalidad
                                );

            auxEmpleado = em_newParametros(     //atoi(bId),
                                                bId,
                                                bNombre,
                                                bHorasTrabajadas
                                                //atoi(bHorasTrabajadas)
                                                bEmail,
                                                bGenero,
                                                bProfesion,
                                                bNacionalidad,
                                                bUsuario,
                                                );
            if(auxEmpleado==NULL)
            {


                al_add(listaErroresEmpleados, auxErrorEmpleado);
            }
            al_add(listaEmpleados,auxEmpleado);
            i++;
        }
        fclose(pFile);
    }
    printf("\nFilas leidas desde archivo:%d\n",i);
    printf("\nArchivo cargado!\n");
    return retorno;
}
*/

int parser_listarDepositos(ArrayList* listaDepositos)
{
    int retorno = -1;
    int i;
    int IdProducto;
    char descripcion[64];
    int cantidad;

    Depositos* auxDepositos;

   // char email[256];
   // char genero;
   // char profesion[256];
   // char nacionalidad[256];
  //  char usuario[64];
    printf("\nId_producto\tdescripcion\tcantidad");
    for(i=0;i<al_len(listaDepositos);i++)
    {
        auxDepositos = al_get(listaDepositos,i);
        depositos_getIdProducto(auxDepositos,&IdProducto);
        depositos_getDescripcion(auxDepositos,descripcion);
        depositos_getCantidad(auxDepositos, &cantidad);

        printf("\n%d - %s - %d",IdProducto, descripcion, cantidad);
    }
    return retorno;
}

int parser_moverDepositos(ArrayList* listaDeposito1, ArrayList* listaDeposito2)
{

    ArrayList* listaDepositoOrigen = NULL;
    ArrayList* listaDepositoDestino = NULL;
    Depositos* auxDepositos;
    int retorno = -1;
    int id;
    int IdProducto;
    char descripcion[64];
    int cantidad;
    int exito;
    int depOrigen;
    int depDestino;
    int i;

    if (listaDeposito1 != NULL && listaDeposito2 != NULL)
    {
        printf("entra");
        exito = getValidInt("\nDeposito de origen: 1 o 2?","\nERROR!", &depOrigen, 0 , 2 , 2 );
        if(depOrigen==1)
        {
            listaDepositoOrigen = listaDeposito1;
        }else if(depOrigen==2)
        {
            listaDepositoOrigen = listaDeposito2;
        }
        if (!exito)
        {
            exito = getValidInt("\nDeposito de origen: 1 o 2?","\nERROR!", &depDestino, 0 , 2 , 2 );
            if(depDestino==1 && depOrigen==2)
            {
                listaDepositoDestino = listaDeposito1;
            }else if(depDestino==2 && depOrigen==1)
            {
                listaDepositoDestino = listaDeposito2;
            }else
            {
                exito=-1;
            }
            if (!exito)
            {
                exito =  getValidInt("\nIngrese el ID: ","\nIngrese un caracter valido!",&id,0,1000,2);
                if (!exito)
                {
                    for(i=0;i<al_len(listaDepositoOrigen);i++)
                    {
                        retorno = -2;
                        auxDepositos = al_get(listaDepositoOrigen,i);
                        depositos_getIdProducto(auxDepositos, &IdProducto);
                        if(id == IdProducto)
                        {
                            auxDepositos = al_pop(listaDepositoOrigen,i);
                            depositos_setIdProducto(auxDepositos,"-1");
                            al_add(listaDepositoDestino,auxDepositos);
                            al_remove(listaDepositoOrigen,i);
                        }
                    }
                }
            }
        }
    }
    //cliente_delete(auxDepositos);
    return retorno;
}

int parser_descontarProductos(ArrayList* listaDeposito1, ArrayList* listaDeposito2)
{
    Depositos* auxDepositos;
    int retorno = -1;
    int id;
    char cant;
    int cantidad;
    int descontar;
    int IdProducto;
    char descripcion[64];
    int exito;
    int i;

    if (listaDeposito1 != NULL && listaDeposito2 != NULL)
    {
        exito = getValidInt("\nIngrese el ID: ","\nIngrese un caracter valido!",&id,0,1000,2);
        if (!exito)
        {
                for(i=0;i<al_len(listaDeposito1);i++)
                {
                    retorno = -2;
                    auxDepositos = al_get(listaDeposito1,i);
                    depositos_getIdProducto(auxDepositos,&IdProducto);
                    if(id == IdProducto)
                    {
                        retorno = 0;
                        depositos_getCantidad(auxDepositos,&cantidad);
                        getValidInt("\nIngrese cantidad a descontar: ","\nIngrese un caracter valido!",&descontar,0,cantidad,2);
                        cantidad = cantidad - descontar;
                        depositos_setCantidadInt(auxDepositos,cantidad);
                        break;
                    }
                }
                if(retorno==-2)
                {
                     for(i=0;i<al_len(listaDeposito2);i++)
                     {
                        auxDepositos = al_get(listaDeposito2,i);
                        depositos_getIdProducto(auxDepositos, &IdProducto);
                        if(id == IdProducto)
                        {
                            retorno = 0;
                            depositos_getCantidad(auxDepositos,&cantidad);
                            getValidInt("\nIngrese cantidad a descontar: ","\nIngrese un caracter valido!",&descontar,0,cantidad,2);
                            cantidad = cantidad - descontar;
                            depositos_setCantidadInt(auxDepositos,cantidad);
                            break;
                        }
                      }
                }
         }
    }
    return retorno;
}

int parser_agregarProductos(ArrayList* listaDeposito1, ArrayList* listaDeposito2)
{
    Depositos* auxDepositos;
    int retorno = -1;
    int id;
    char cant;
    int cantidad;
    int agregar;
    int IdProducto;
    char descripcion[64];
    int exito;
    int i;

    if (listaDeposito1 != NULL && listaDeposito2 != NULL)
    {
        exito = getValidInt("\nIngrese el ID: ","\nIngrese un caracter valido!",&id,0,1000,2);
        if (!exito)
        {
                for(i=0;i<al_len(listaDeposito1);i++)
                {
                    retorno = -2;
                    auxDepositos = al_get(listaDeposito1,i);
                    depositos_getIdProducto(auxDepositos,&IdProducto);
                    if(id == IdProducto)
                    {
                        retorno = 0;
                        depositos_getCantidad(auxDepositos,&cantidad);
                        getValidInt("\nIngrese cantidad a agregar: ","\nIngrese un caracter valido!",&agregar,0,cantidad,2);
                        cantidad = cantidad + agregar;
                        depositos_setCantidadInt(auxDepositos,cantidad);
                        break;
                    }
                }
                if(retorno==-2)
                {
                     for(i=0;i<al_len(listaDeposito2);i++)
                     {
                        auxDepositos = al_get(listaDeposito2,i);
                        depositos_getIdProducto(auxDepositos, &IdProducto);
                        if(id == IdProducto)
                        {
                            retorno = 0;
                            depositos_getCantidad(auxDepositos,&cantidad);
                            getValidInt("\nIngrese cantidad a agregar: ","\nIngrese un caracter valido!",&agregar,0,cantidad,2);
                            cantidad = cantidad + agregar;
                            depositos_setCantidadInt(auxDepositos,cantidad);
                            break;
                        }
                      }
                }
         }
    }
    return retorno;
}

int parser_guardarArchivosDepositos(char* path, ArrayList* listaDepositos)
{
    Depositos* auxDepositos;
    int IdProducto;
    char descripcion[64];
    int cantidad;
    int retorno = -1;
    int i;
    FILE* pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL)
    {
        retorno=1;
        printf("\nGuardando archivo: %s...\n",path);
        fprintf(pFile,"producto,descripcion,cantidad\n");
        for(i=0;i<al_len(listaDepositos);i++)
        {
            auxDepositos = al_get(listaDepositos,i);
            depositos_getIdProducto(auxDepositos,&IdProducto);
            depositos_getDescripcion(auxDepositos,descripcion);
            depositos_getCantidad(auxDepositos,&cantidad);
           // cliente_getEmail(auxDepositos,email);
           // cliente_getGenero(auxDepositos,&genero);
          //  cliente_getProfesion(auxDepositos,profesion);
           // cliente_getNacionalidad(auxDepositos,nacionalidad);
           // cliente_getUsuario(auxDepositos,usuario);
            fprintf(pFile,"%d,%s,%d\n",IdProducto,descripcion,cantidad);
            //fprintf(stdout,"%d,%s,%s,%d\n",id,nombre,apellido,sueldo);
        }
    }
    fclose(pFile);
    printf("\nArchivo: %s guardado!\n",path);
    return retorno;
}


