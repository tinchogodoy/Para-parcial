#include "reparto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EReparto* reparto_new()
{
    EReparto* this;
    this=malloc(sizeof(EReparto));
    return this;
}

void reparto_delete(EReparto* this)
{
    free(this);
}

int reparto_setId(EReparto* this, char* id)
{
    int retorno = -1;
    int bId;
    static int maximoId = -1;
    if(this!=NULL && id!=NULL )
    {
        bId=atoi(id);
        retorno = 0;
        if(bId >= 0)
        {
            this->id = bId;
            if(bId > maximoId)
                maximoId = bId;
        }
        else
        {
            maximoId++;
            this->id = maximoId;
        }
    }
    return retorno;
}

int reparto_getId(EReparto* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int reparto_setProducto(EReparto* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(this->producto,producto);
        retorno=0;
    }
    return retorno;
}

int reparto_getProducto(EReparto* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(producto,this->producto);
        retorno=0;
    }
    return retorno;
}

int reparto_setDireccion(EReparto* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(this->direccion,direccion);
        retorno=0;
    }
    return retorno;
}

int reparto_getDireccion(EReparto* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(direccion,this->direccion);
        retorno=0;
    }
    return retorno;
}

int reparto_setLocalidad(EReparto* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(this->localidad,localidad);
        retorno=0;
    }
    return retorno;
}

int reparto_getLocalidad(EReparto* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(localidad,this->localidad);
        retorno=0;
    }
    return retorno;
}

int reparto_setRecibe(EReparto* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(this->recibe,recibe);
        retorno=0;
    }
    return retorno;
}

int reparto_getRecibe(EReparto* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(recibe,this->recibe);
        retorno=0;
    }
    return retorno;
}

EReparto* reparto_newParametros(char* id, char* producto, char* direccion, char* localidad, char* recibe)
{
    EReparto* auxReparto = reparto_new();
    if(     !reparto_setId(auxReparto,id)
       &&   !reparto_setProducto(auxReparto,producto)
       &&   !reparto_setDireccion(auxReparto, direccion)
       &&   !reparto_setLocalidad(auxReparto, localidad)
       /*&&   !cliente_setProfesion(auxDepositos, profesion)
       &&   !cliente_setNacionalidad(auxDepositos, nacionalidad)
       &&   !cliente_setUsuario(auxDepositos, usuario) */
       &&   !reparto_setRecibe(auxReparto, recibe))
    {
        return auxReparto;
    }
    //printf("Datos con Errores: - %s - %s - %s\n",IdProducto, descripcion, cantidad);
    reparto_delete(auxReparto);
    return NULL;
}



