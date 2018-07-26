#ifndef _CLIENTE_H
#define _CLIENTE_H
struct
{
    char descripcion[50];
    int precio;
    int codigoProducto;

}typedef Producto;
#endif // _CLIENTE_H

Producto* producto_new(void);
Producto* producto_newParametrosString(int codigoProducto, char* descripcion, float precio);
void producto_delete(Producto* this);
int producto_setCodigoProducto(Producto* this, int codigoProducto);
int producto_getCodigoProducto(Producto* this,int* codigoProducto);
int producto_setDescripcion(Producto* this, char* descripcion);
int producto_getDescripcion(Producto* this, char* descripcion);
int producto_setPrecio(Producto* this, float precio);
int producto_getPrecio(Producto* this, float precio);



