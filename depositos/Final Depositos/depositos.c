#include "depositos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Depositos* depositos_new()
{
    Depositos* this;
    this=malloc(sizeof(Depositos));
    return this;
}

void depositos_delete(Depositos* this)
{
    free(this);
}

int depositos_setIdProducto(Depositos* this, char* IdProducto)
{
    int retorno = -1;
    int bId;
    static int maximoId = -1;
    if(this!=NULL && IdProducto!=NULL )
    {
        bId=atoi(IdProducto);
        retorno = 0;
        if(bId >= 0)
        {
            this->IdProducto = bId;
            if(bId > maximoId)
                maximoId = bId;
        }
        else
        {
            maximoId++;
            this->IdProducto = maximoId;
        }
    }
    return retorno;
}

int depositos_getIdProducto(Depositos* this,int* IdProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *IdProducto=this->IdProducto;
        retorno=0;
    }
    return retorno;
}



int depositos_setDescripcion(Depositos* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno=0;
    }
    return retorno;
}

int depositos_getDescripcion(Depositos* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(descripcion,this->descripcion);
        retorno=0;
    }
    return retorno;
}

int depositos_setCantidad(Depositos* this,char* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=atoi(cantidad);
        retorno=0;
    }
    return retorno;
}

int depositos_setCantidadInt(Depositos* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int depositos_getCantidad(Depositos* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

Depositos* depositos_newParametros(char* IdProducto, char* descripcion, char* cantidad/*,int sueldo, char* email, char* genero, char* profesion, char* nacionalidad, char* usuario,*/ )
{
    Depositos* auxDepositos = depositos_new();
    if(     !depositos_setIdProducto(auxDepositos,IdProducto)
       &&   !depositos_setDescripcion(auxDepositos,descripcion)
       //&&   !em_setSueldo(auxDepositos, sueldo)
    /* &&   !cliente_setEmail(auxDepositos, email)
       &&   !cliente_setGenero(auxDepositos, genero[0])
       &&   !cliente_setProfesion(auxDepositos, profesion)
       &&   !cliente_setNacionalidad(auxDepositos, nacionalidad)
       &&   !cliente_setUsuario(auxDepositos, usuario) */
       &&   !depositos_setCantidad(auxDepositos, cantidad))
    {
        return auxDepositos;
    }
    printf("Datos con Errores: - %s - %s - %s\n",IdProducto, descripcion, cantidad);
    depositos_delete(auxDepositos);
    return NULL;
}
