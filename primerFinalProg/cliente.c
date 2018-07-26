#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "utn.h"


static int isValidNombre(char* nombre);
static int isValidLastName(char* lastName);
/*
static int isValidEmail(char* email);
static int isValidGenero(char genero);
static int isValidProfesion(char* profesion);
static int isValidNacionalidad(char* nacionalidad);
static int isValidUsuario(char* usuario);*/

Cliente* cliente_new()
{
    return (Cliente*) malloc(sizeof(Cliente));
}

void cliente_delete(Cliente* this)
{
    free(this);
}

Cliente* cliente_newParametros(char* nombre, char* apellido, char* dni,/*char* email, char* genero, char* profesion, char* nacionalidad, char* usuario,*/ char* id)
{
    Cliente* auxCliente = cliente_new();
    if(     !cliente_setNombre(auxCliente, nombre)
       &&   !cliente_setApellido(auxCliente, apellido)
       &&   !cliente_setDni(auxCliente, dni)
    /* &&   !cliente_setEmail(auxCliente, email)
       &&   !cliente_setGenero(auxCliente, genero[0])
       &&   !cliente_setProfesion(auxCliente, profesion)
       &&   !cliente_setNacionalidad(auxCliente, nacionalidad)
       &&   !cliente_setUsuario(auxCliente, usuario) */
       &&   !cliente_setId(auxCliente, id))
    {
        return auxCliente;
    }
    cliente_delete(auxCliente);
    return NULL;
}

int cliente_newEnterParametros(char* nombre,char* apellido,char* dni)
{
    int retorno = -1;
    int exito;
    exito = getValidString("Nombre: ","\nCaracteres Invalidos!\n","\nDemasiados Caracteres\n", nombre,64,2);
    if(!exito)
    {
        exito = getValidString("Apellido: ","\nCaracteres Invalidos!\n","\nDemasiados Caracteres\n", apellido,64,2);
        if(!exito)
        {
            exito =  getValidStringNumerico("DNI: ","\nIngrese numeros!\n","\nDemasiados Caracteres\n", dni,10,2);
            if(!exito)
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

int cliente_setNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL && isValidNombre(nombre))
    {
        retorno = 0;
        strcpy(this->nombre, nombre);
    }
    return retorno;
}
int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre, this->nombre);
    }
    return retorno;
}
int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL && isValidLastName(apellido))
    {
        retorno = 0;
        strcpy(this->apellido, apellido);
    }
    return retorno;
}
int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        retorno = 0;
        strcpy(apellido, this->apellido);
    }
    return retorno;
}
int cliente_setDni(Cliente* this, char* dni)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->dni = atoi(dni);
        retorno = 0;
    }
    return retorno;
}
int cliente_getDni(Cliente* this, int* dni)
{
    int retorno = -1;
    if(this != NULL)
    {
        *dni = this->dni;
        retorno = 0;
    }
    return retorno;
}
/*int cliente_setEmail(Cliente* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL && isValidEmail(email))
    {
        retorno = 0;
        strcpy(this->email, email);
    }
    return retorno;
}
int cliente_getEmail(Cliente* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL)
    {
        retorno = 0;
        strcpy(email, this->email);
    }
    return retorno;
}
int cliente_setGenero(Cliente* this, char genero)
{
    int retorno = -1;
    if(this != NULL && isValidGenero(genero))
    {
        retorno = 0;
        this->genero = genero;
    }
    return retorno;
}
int cliente_getGenero(Cliente* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        retorno = 0;
        *genero = this->genero;
    }
    return retorno;
}
int cliente_setProfesion(Cliente* this, char* profesion)
{
    int retorno = -1;
    if(this != NULL && profesion != NULL && isValidProfesion(profesion))
    {
        retorno = 0;
        strcpy(this->profesion, profesion);
    }
    return retorno;
}
int cliente_getProfesion(Cliente* this, char* profesion)
{
    int retorno = -1;
    if(this != NULL && profesion != NULL)
    {
        retorno = 0;
        strcpy(profesion, this->profesion);
    }
    return retorno;
}
int cliente_setNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno = -1;
    if(this != NULL && nacionalidad != NULL && isValidNacionalidad(nacionalidad))
    {
        retorno = 0;
        strcpy(this->nacionalidad, nacionalidad);
    }
    return retorno;
}
int cliente_getNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno = -1;
    if(this != NULL && nacionalidad != NULL)
    {
        retorno = 0;
        strcpy(nacionalidad, this->nacionalidad);
    }
    return retorno;
}*/

int cliente_setId(Cliente* this, char* id)
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
int cliente_getId(Cliente* this, int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}
/*int cliente_setUsuario(Cliente* this, char* usuario)
{
    int retorno = -1;
    if(this != NULL && usuario != NULL && isValidUsuario(usuario))
    {
        retorno = 0;
        strcpy(this->usuario, usuario);
    }
    return retorno;
}
int cliente_getUsuario(Cliente* this, char* usuario)
{
    int retorno = -1;
    if(this != NULL && usuario != NULL)
    {
        retorno = 0;
        strcpy(usuario, this->usuario);
    }
    return retorno;
}*/

static int isValidNombre(char* nombre)
{
    int retorno=1;
    if(nombre != NULL && !esSoloLetras(nombre))
    {
        retorno=0;
    }
    return retorno;
}

static int isValidLastName(char* nombre)
{
    int retorno=1;
    if(nombre != NULL && !esSoloLetras(nombre))
    {
        retorno=0;
    }
    return retorno;
}

/*static int isValidEmail(char* email)
{
    return 1;
}

static int isValidGenero(char genero)
{
    return 1;
}

static int isValidProfesion(char* profesion)
{
    return 1;
}

static int isValidNacionalidad(char* nacionalidad)
{
    return 1;
}

static int isValidUsuario(char* usuario)
{
    return 1;
*/

int cliente_ordenarNombreApellido(Cliente* clienteA, Cliente* clienteB)
{
    char nombreA[64];
    char nombreB[64];
    char apellidoA[64];
    char apellidoB[64];

    cliente_getNombre(clienteA,nombreA);
    cliente_getNombre(clienteB,nombreB);

    if(!strcmp(nombreA,nombreB))
    {
        cliente_getApellido(clienteA,apellidoA);
        cliente_getApellido(clienteB,apellidoB);
        return strcmp(apellidoA,apellidoB);
    }
    return strcmp(nombreA,nombreB);
}
int cliente_ordenarApellidoNombre(Cliente* clienteA, Cliente* clienteB)
{
    char nombreA[64];
    char nombreB[64];
    char apellidoA[64];
    char apellidoB[64];

    cliente_getApellido(clienteA,apellidoA);
    cliente_getApellido(clienteB,apellidoB);

    if(!strcmp(apellidoA,apellidoB))
    {
        cliente_getNombre(clienteA,nombreA);
        cliente_getNombre(clienteB,nombreB);
        return strcmp(nombreA,nombreB);
    }
    return strcmp(apellidoA,apellidoB);
}
