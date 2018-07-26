#ifndef _CLIENTE_H
#define _CLIENTE_H
struct
{
    int cantidadVendida;
    float precioTotal;
    int idVenta;
    int codigoProducto;
    int idCliente;

}typedef Venta;
#endif // _CLIENTE_H

Venta* venta_new(void);
Venta* venta_newParametrosString(int idProducto, int idVenta, int codigoProducto);
void venta_delete(Venta* this);
int venta_setIdVenta(Venta* this, int id);
int venta_getIdVenta(Venta* this,int* id);
