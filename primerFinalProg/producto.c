#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "utn.h"

static int isValidDescripcion(char* descripcion);
static int isValidPrecio(float precio);

Producto* producto_new(void)
{
    Producto* returnAux = NULL;
    returnAux = (Producto*) malloc(sizeof(Producto));
    return returnAux;

}

Producto* producto_newParametrosString(int codigoProducto, char* descripcion, float precio)
{
    Producto* this = producto_new();;

    producto_setCodigoProducto(this, codigoProducto);
    producto_setDescripcion(this, descripcion);
    producto_setPrecio(this, precio);
    return this;
}

void producto_delete(Producto* this)
{
    if(this != NULL)
        free(this);
}



int producto_setCodigoProducto(Producto* this,int codigoProducto)
{
    static int ultimoCodigoProducto = -1;
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        if(codigoProducto > 0)
        {
            this->codigoProducto = codigoProducto;
            if(codigoProducto > ultimoCodigoProducto)
                ultimoCodigoProducto = codigoProducto;
        }
        else
        {
            ultimoCodigoProducto++;
            this->codigoProducto =  ultimoCodigoProducto;
        }
    }
    return retorno;
}

int producto_getCodigoProducto(Producto* this,int* codigoProducto)
{
    int retorno=-1;
    if(this != NULL && codigoProducto != NULL)
    {
        retorno = 0;
        *codigoProducto = this->codigoProducto;
    }
    return retorno;
}

int producto_setDescripcion(Producto* this, char* descripcion)
{
    int retorno=-1;
    if(this != NULL && descripcion != NULL && isValidDescripcion(descripcion))
    {
            retorno = 0;
            strcpy(this->descripcion,descripcion);
    }
    return retorno;
}


int producto_setPrecio(Producto* this, float precio)
{
    int retorno=-1;
    if(this != NULL && isValidPrecio(precio))
    {
            retorno = 0;
            this->precio = precio;
    }
    return retorno;
}



int producto_getDescripcion(Producto* this, char* descripcion)
{
    int retorno=-1;
    if(this != NULL && descripcion != NULL)
    {
            retorno = 0;
            strcpy(descripcion,this->descripcion);
    }
    return retorno;
}



int producto_getPrecio(Producto* this, float precio)
{
    int retorno=-1;
    if(this != NULL)
    {
            retorno = 0;
            precio = this->precio;
    }
    return retorno;
}

static int isValidDescripcion(char* descripcion)
{
    return 1;
}


static int isValidPrecio(float precio)
{
    return 1;
}


