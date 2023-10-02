#include <stdio.h>
#define CAPACIDAD_MAXIMA 100
void binario();
void calificaciones();
void inven();
void agregarElemento();
void retirarElemento();
void mostrarInventario();
int inventario[CAPACIDAD_MAXIMA];
int cantidadElementos = 0;
int validarNumero(char mensaje[], int ri, int rf);

int main()
{
    int op;
    op=validarNumero("Ingrese el número de la operación que desea realizar:\n1. Numero binario\n2. Calificacion\n3. Inventarios\n",1,3);
    switch (op)
    {
    case 1:
        binario();
        break;

    case 2:
        calificaciones();
        break;
    case 3:
        inven();
        break;
    }
    return 0;
}
void binario()
{
    int num, bits;
    printf("Ingresa un numero entero: ");
    scanf("%d", &num);

    printf("Ingresa el numero de bits a considerar: ");
    scanf("%d", &bits);

    if (bits <= 0)
    {
        printf("El numero de bits debe ser mayor que cero.\n");
    }

    int num_bits_encendidos = 0;

    for (int i = 0; i < bits; i++)
    {
        num_bits_encendidos += (num >> i) & 1;
    }

    printf("Representacion binaria: ");
    for (int i = bits - 1; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\nNumero de bits encendidos: %d\n", num_bits_encendidos);
}
void calificaciones()
{
    int cali;
    char letra;

    printf("Ingrese una calificacion numerica entre 0 y 100: ");
    scanf("%d", &cali);

    if (cali < 0 || cali > 100)
    {
        printf("ERROR: La calificacion debe estar entre 0 y 100.\n");
    }
    else
    {
        if (cali < 60)
        {
            letra = 'F';
        }
        else if (cali < 70)
        {
            letra = 'D';
        }
        else if (cali < 80)
        {
            letra = 'C';
        }
        else if (cali < 90)
        {
            letra = 'B';
        }
        else
        {
            letra = 'A';
        }
    }
    printf("La calificacion numerica:  %d\n", cali);
    printf("La calificacion en letra:  %c", letra);
}
void inven()
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
            break;
        default:
            printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }
    }

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
int validarNumero(char mensaje[], int ri, int rf)
{
    int num;
    do
    {
        printf("%s", mensaje);
        scanf("%d", &num);
        if (num < ri || num > rf)
        {
            printf("Ingrese un numero valido en el rango [%d, %d].\n", ri, rf);
        }
    } while (num < ri || num > rf);
    return num;
}