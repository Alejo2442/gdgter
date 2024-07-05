#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    int OpcionInicial;
    struct Ropa inventario[MAX_INVENTARIO] = {0};

    cargarInventarioDesdeArchivo(inventario, MAX_INVENTARIO);

    printf("=========== Bienvenido a Zara ===========\n");

    do {
        printf("\nSeleccione una opción:\n");
        printf("1. Añadir al stock\n");
        printf("2. Mostrar Inventario\n");
        printf("3. Buscar Ropa\n");
        printf("4. Editar Ropa\n");
        printf("5. Salir\n");
        printf(">> ");
        scanf("%d", &OpcionInicial);

        switch (OpcionInicial) {
            case 1:
                ingresarNuevaRopa(inventario, MAX_INVENTARIO);
                break;
            case 2:
                mostrarInventario(inventario, MAX_INVENTARIO);
                break;
            case 3:
                buscarRopa(inventario, MAX_INVENTARIO);
                break;
            case 4:
                editarPrenda(inventario, MAX_INVENTARIO);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Por favor, ingrese un número entre 1 y 5.\n");
                break;
        }
    } while (OpcionInicial != 5);

    return 0;
}
