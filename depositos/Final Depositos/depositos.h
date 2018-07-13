#ifndef DEPOSITOS_H_INCLUDED
#define DEPOSITOS_H_INCLUDED
typedef struct
{
    int IdProducto;
    char descripcion[64];
    int cantidad;
}Depositos;

Depositos* depositos_new();
void depositos_delete();

int depositos_setIdProducto(Depositos* this,char* IdProducto);
int depositos_getIdProducto(Depositos* this,int* IdProducto);

int depositos_setDescripcion(Depositos* this,char* descripcion);
int depositos_getDescripcion(Depositos* this,char* descripcion);

int depositos_setCantidad(Depositos* this,char* cantidad);
int depositos_getCantidad(Depositos* this,int* cantidad);

#endif // DEPOSITOS_H_INCLUDED
