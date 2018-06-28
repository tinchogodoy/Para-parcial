#ifndef CONTROLER_H_INCLUDED
#define CONTROLER_H_INCLUDED


#endif // CONTROLER_H_INCLUDED

int controller_leerArchivoClientes(char* path, ArrayList* pArrayClientes);
int controller_listarClientes(ArrayList* pArrayClientes);
int controller_ordenarClientesNombreApellido(ArrayList* pArrayClientes);
int controller_ordenarClientesApellidoNombre(ArrayList* pArrayClientes);
int controller_guardarClientesArchivo(char* path, ArrayList* pArrayClientes);
