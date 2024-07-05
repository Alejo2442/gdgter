#include "funciones.h"
#include <stdio.h>
#include <string.h>

void guardarInventarioEnArchivo(struct Ropa inventario[], int tamano) {
    FILE *archivo = fopen("inventario.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < tamano; i++) {
        if (strlen(inventario[i].nombre) > 0) {
            fprintf(archivo, "%s %d %.2f\n", inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
        }
    }

    fclose(archivo);
}

void cargarInventarioDesdeArchivo(struct Ropa inventario[], int tamano) {
    FILE *archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
        printf("No se encontró el archivo de inventario.\n");
        return;
    }

    int i = 0;
    while (fscanf(archivo, "%19s %d %f", inventario[i].nombre, &inventario[i].cantidad, &inventario[i].precio) == 3) {
        i++;
        if (i >= tamano) break; // Evitar desbordamiento del arreglo
    }

    fclose(archivo);
}

void ingresarNuevaRopa(struct Ropa inventario[], int tamano) {
    char RopaIngresada[MAX_NOMBRE];
    int UnidadRopa;
    float PrecioRopa;

    printf("¿Qué tipo de ropa quieres ingresar?\n");
    scanf("%s", RopaIngresada);

    printf("¿Cuántas unidades de %s quieres ingresar?\n", RopaIngresada);
    scanf("%d", &UnidadRopa);

    printf("¿Cuál es el precio de %s?\n", RopaIngresada);
    scanf("%f", &PrecioRopa);

    int indiceRopa = buscarXNombre(inventario, tamano, RopaIngresada);

    if (indiceRopa != -1) {
        inventario[indiceRopa].precio = PrecioRopa;
        inventario[indiceRopa].cantidad += UnidadRopa;
        printf("Se han agregado %d unidades de %s al inventario.\n", UnidadRopa, RopaIngresada);
    } else {
        for (int i = 0; i < tamano; i++) {
            if (strlen(inventario[i].nombre) == 0) {
                strcpy(inventario[i].nombre, RopaIngresada);
                inventario[i].cantidad = UnidadRopa;
                inventario[i].precio = PrecioRopa;
                printf("Se han agregado %d unidades de %s al inventario.\n", UnidadRopa, RopaIngresada);
                break;
            }
        }
    }

    guardarInventarioEnArchivo(inventario, tamano);
}

void editarPrenda(struct Ropa inventario[], int tamano) {
    char nombreABuscar[MAX_NOMBRE];
    int nuevoValor;
    float nuevoPrecio;

    printf("Ingrese el nombre de la prenda que desea editar: ");
    scanf("%s", nombreABuscar);

    int index = buscarXNombre(inventario, tamano, nombreABuscar);

    if (index != -1) {
        printf("Ingrese la nueva cantidad: ");
        scanf("%d", &nuevoValor);

        printf("Ingrese el nuevo precio: ");
        scanf("%f", &nuevoPrecio);

        inventario[index].cantidad = nuevoValor;
        inventario[index].precio = nuevoPrecio;

        printf("Prenda actualizada exitosamente.\n");
    } else {
        printf("El nombre buscado no existe.\n");
    }

    guardarInventarioEnArchivo(inventario, tamano);
}

void mostrarInventario(struct Ropa inventario[], int tamano) {
    FILE *archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
        printf("No se encontró el archivo de inventario.\n");
        return;
    }

    printf("Inventario de Ropa:\n");
    printf("==============================================\n");

    char nombre[MAX_NOMBRE];
    int cantidad;
    float precio;

    while (fscanf(archivo, "%19s %d %f", nombre, &cantidad, &precio) == 3) {
        printf("%s - Cantidad: %d - Precio: %.2f\n", nombre, cantidad, precio);
    }

    fclose(archivo);
}

int buscarXNombre(struct Ropa inventario[], int tamano, char nombreABuscar[]) {
    for (int i = 0; i < tamano; i++) {
        if (strcmp(inventario[i].nombre, nombreABuscar) == 0) {
            return i;
        }
    }
    return -1;
}

void buscarRopa(struct Ropa inventario[], int tamano) {
    char nombreABuscar[MAX_NOMBRE];

    printf("Ingrese el nombre de la prenda que desea buscar: ");
    scanf("%s", nombreABuscar);

    int indice = buscarXNombre(inventario, tamano, nombreABuscar);

    if (indice != -1) {
        printf("Ropa encontrada:\n");
        printf("Nombre: %s\n", inventario[indice].nombre);
        printf("Cantidad: %d\n", inventario[indice].cantidad);
        printf("Precio: %.2f\n", inventario[indice].precio);
    } else {
        printf("La prenda buscada no se encuentra en el inventario.\n");
    }
}
