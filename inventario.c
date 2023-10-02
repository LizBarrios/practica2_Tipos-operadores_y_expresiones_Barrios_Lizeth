#include <stdio.h>

#define CAPACIDAD_MAXIMA 100
void agregarElemento();
void retirarElemento();
void mostrarInventario();

int inventario[CAPACIDAD_MAXIMA];
int cantidadElementos = 0;

int main()
{
    int opcion;
    while (1)
    {
        printf("\n--- Menú de Inventario ---\n");
        printf("1. Agregar elemento\n");
        printf("2. Retirar elemento\n");
        printf("3. Mostrar inventario\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregarElemento();
            break;
        case 2:
            retirarElemento();
            break;
        case 3:
            mostrarInventario();
            break;
        case 4:
            printf("Saliendo del programa.\n");
            return 0;
        default:
            printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }
    }
    return 0;
}

void agregarElemento()
{
    if (cantidadElementos < CAPACIDAD_MAXIMA)
    {
        int cantidad;
        printf("Ingrese la cantidad a agregar: ");
        scanf("%d", &cantidad);
        inventario[cantidadElementos] = cantidad;
        cantidadElementos++;
        printf("Elemento agregado al inventario.\n");
    }
    else
    {
        printf("El inventario está lleno. No se pueden agregar más elementos.\n");
    }
}

void retirarElemento()
{
    if (cantidadElementos > 0)
    {
        int cantidad, total;
        printf("Ingrese la cantidad a retirar: ");
        scanf("%d", &cantidad);
        total = inventario[cantidadElementos - 1];

        if (cantidad <= total)
        {
            inventario[cantidadElementos - 1] -= cantidad;
            printf("Elemento retirado del inventario.\n");
            if (inventario[cantidadElementos - 1] == 0)
            {
                cantidadElementos--;
            }
        }
        else
        {
            printf("No hay suficiente cantidad para retirar.\n");
        }
    }
    else
    {
        printf("El inventario está vacío. No se pueden retirar elementos.\n");
    }
}

void mostrarInventario()
{
    printf("\n--- Inventario ---\n");
    for (int i = 0; i < cantidadElementos; i++)
    {
        printf("Elemento %d: %d\n", i + 1, inventario[i]);
    }
}