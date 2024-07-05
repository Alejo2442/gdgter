#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#define MAX_NOMBRE 20
#define MAX_INVENTARIO 13

struct Ropa {
    char nombre[MAX_NOMBRE];
    int cantidad;
    float precio;
};

void cargarInventarioDesdeArchivo(struct Ropa inventario[], int tamano);
void guardarInventarioEnArchivo(struct Ropa inventario[], int tamano);
void ingresarNuevaRopa(struct Ropa inventario[], int tamano);
void editarPrenda(struct Ropa inventario[], int tamano);
void mostrarInventario(struct Ropa inventario[], int tamano);
int buscarXNombre(struct Ropa inventario[], int tamano, char nombreABuscar[]);

#endif /* FUNCIONES_H_ */
