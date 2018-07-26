#ifndef REPARTO_H_INCLUDED
#define REPARTO_H_INCLUDED
typedef struct
{
    int id;
    char producto[40];
    char direccion[128];
    char localidad[40];
    char recibe[40];
}EReparto;

EReparto* reparto_new();
void reparto_delete();
EReparto* reparto_newParametros(char* id, char* producto, char* direccion, char* localidad, char* recibe);
int reparto_setId(EReparto* this, char* id);
int reparto_getId(EReparto* this,int* id);

int reparto_setProducto(EReparto* this,char* producto);
int reparto_getProducto(EReparto* this,char* producto);

int reparto_setDireccion(EReparto* this,char* direccion);
int reparto_getDireccion(EReparto* this,char* direccion);

int reparto_setLocalidad(EReparto* this,char* localidad);
int reparto_getLocalidad(EReparto* this,char* localidad);

int reparto_setRecibe(EReparto* this,char* recibe);
int reparto_getRecibe(EReparto* this,char* recibe);

#endif // REPARTO_H_INCLUDED
