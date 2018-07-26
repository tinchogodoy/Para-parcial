#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "venta.h"
#include "utn.h"

static int isValidCantidadVendida(int cantidadVendida);
static int isValidPrecioTotal(float precioTotal);
static int isValIdCliente(int idCliente);

Venta* venta_new(void)
{
    Venta* returnAux = NULL;
    returnAux = (Venta*) malloc(sizeof(Venta));
    return returnAux;

}

Venta* venta_newParametros(int* idCliente, int* codigoProducto, int* cantidadVendida, int* idVenta)
{
    Venta* auxVenta = venta_new();
    if(     !venta_setIdCliente(auxVenta,idCliente)
       &&   !venta_setCodigoProducto(auxVenta, codigoProducto)
       &&   !venta_setCantidadVendida(auxVenta, cantidadVendida)
       &&   !venta_setIdVenta(auxVenta, idVenta))
    {
        return auxVenta;
    }
    cliente_delete(auxVenta);
    return NULL;
}

int venta_newEnterParametros(int* idCliente, int* codigoProducto, int* cantidadVendida)
{
    int retorno = -1;
    int exito;
    exito = getValidInt("\nID Cliente: ","\nCaracteres Invalidos\n", idCliente, 0,1000,2);
    if(!exito)
    {
        exito = getValidInt("Codigo Producto: ","\nCaracteres Invalidos\n", codigoProducto, 0,1000,2);
        if(!exito)
        {
            exito = getValidInt("Cantidad de unidades: ","\nCaracteres Invalidos\n", cantidadVendida, 0,1000,2);
            if(!exito)
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}


/*
Venta* venta_newParametrosString(Cliente* pArrayCliente, int idCliente, int idVenta, int codigoProducto, int cantidadVendida)
{
    Venta* this = venta_new();;
    int idClienteAux;

    venta_setIdVenta(this,idVenta);
    for (i=0;al_len(pArrayCliente);i++)
    {
        cliente_getId(this,idClienteAux);
        if (idClienteAux == idCliente)
        {
            venta_setIdCliente(idCliente);
        }
    }

    venta_setCantidadVendida(this,cantidadVendida);
    venta_set

static int isValIdCliente(int idCliente)
    return this;
}*/

void venta_delete(Venta* this)
{
    if(this != NULL)
        free(this);
}


int venta_setCantidadVendida(Venta* this, int cantidadVendida)
{
    int retorno = -1;
    if(this != NULL && isValidCantidadVendida(cantidadVendida))
    {
            retorno = 0;
            this->cantidadVendida = cantidadVendida;
    }
    return retorno;
}


int venta_setPrecioTotal(Venta* this, float precioTotal)
{
    int retorno=-1;
    if(this != NULL && isValidPrecioTotal(precioTotal))
    {
            retorno = 0;
            this->precioTotal = precioTotal;
    }
    return retorno;
}


int venta_setIdCliente(Venta* this, int idCliente)
{
    int retorno=-1;
    if(this != NULL && isValIdCliente(idCliente))
    {
            retorno = 0;
            this->idCliente = idCliente;
    }
    return retorno;
}

int venta_setCodigoProducto(Venta* this, int codigoProducto)
{
    int retorno=-1;
    if(this != NULL /*&& isValidCodigoProducto(codigoProducto)*/)
    {
            retorno = 0;
            this->codigoProducto = codigoProducto;
    }
    return retorno;
}


int venta_getCodigoProducto(Venta* this, int* codigoProducto)
{
    int retorno=-1;
    if(this != NULL && codigoProducto != NULL)
    {
            retorno = 0;
            *codigoProducto = this->codigoProducto;
    }
    return retorno;
}


int venta_getIdCliente(Venta* this, int* idCliente)
{
    int retorno=-1;
    if(this != NULL)
    {
            retorno = 0;
            *idCliente = this->idCliente;
    }
    return retorno;
}

int venta_getPrecioTotal(Venta* this, float* precioTotal)
{
    int retorno=-1;
    if(this != NULL)
    {
            retorno = 0;
            *precioTotal = this->precioTotal;
    }
    return retorno;
}


int venta_getCantidadVendida(Venta* this, int* cantidadVendida)
{
    int retorno=-1;
    if(this != NULL && cantidadVendida != NULL)
    {
            retorno = 0;
            *cantidadVendida = this->cantidadVendida;
    }
    return retorno;
}


int venta_setIdVenta(Venta* this, int id)
{
    static int ultimoId = -1;
    int retorno=-1;
    if(this != NULL)
    {
        retorno = 0;
        if(id > 0)
        {
            this->idVenta = id;
            if(id > ultimoId)
                ultimoId = id;
        }
        else
        {
            ultimoId++;
            this->idVenta =  ultimoId;
        }
    }
    return retorno;
}

int venta_getIdVenta(Venta* this,int* id)
{
    int retorno=-1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->idVenta;
    }
    return retorno;
}


/*
int venta_ordenarNombreApellido(void* ventaA,void* ventaB)
{
    char nombreA[64];
    char nombreB[64];
    int retorno;
    venta_getNombre(ventaA,nombreA);
    venta_getNombre(ventaB,nombreB);
    retorno = strcmp(nombreA,nombreB);
    if(!retorno)
    {
        char apellidoA[64];
        char apellidoB[64];
        venta_getApellido(ventaA,apellidoA);
        venta_getApellido(ventaB,apellidoB);
        retorno = strcmp(apellidoA,apellidoB);
    }
    return retorno;
}
*/

static int isValidCantidadVendida(int cantidadVendida)
{
    return 1;
}

static int isValidPrecioTotal(float precioTotal)
{
    return 1;
}

static int isValIdCliente(int idCliente)
{
    return 1;
}
