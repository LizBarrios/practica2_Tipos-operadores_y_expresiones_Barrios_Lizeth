#include <stdio.h>

// Definición de una macro para la capacidad máxima del inventario
#define CAPACIDAD_MAXIMA 100

// Prototipos de funciones
void binario();
void calificaciones();
void inven();
void agregarElemento();
void retirarElemento();
void mostrarInventario();
int inventario[CAPACIDAD_MAXIMA];  // Arreglo para almacenar el inventario de elementos
int cantidadElementos = 0;        // Variable global para llevar un registro de la cantidad actual de elementos en el inventario
int validarNumero(char mensaje[], int ri, int rf);

int main()
{
    int op;

    // Solicitar al usuario que ingrese una opción válida utilizando la función validarNumero
    op = validarNumero("Ingrese el número de la operación que desea realizar:\n1. Numero binario\n2. Calificacion\n3. Inventarios\n", 1, 3);

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

// Función para calcular la representación binaria de un número y contar bits encendidos
void binario()
{
    int num, bits;

    // Solicitar al usuario que ingrese un número entero
    printf("Ingresa un numero entero: ");
    scanf("%d", &num);

    // Solicitar al usuario que ingrese el número de bits a considerar
    printf("Ingresa el numero de bits a considerar: ");
    scanf("%d", &bits);

    // Verificar si el número de bits es válido (mayor que cero)
    if (bits <= 0)
    {
        printf("El numero de bits debe ser mayor que cero.\n");
        return;
    }

    int num_bits_encendidos = 0;

    // Calcular la representación binaria y contar bits encendidos
    for (int i = 0; i < bits; i++)
    {
        num_bits_encendidos += (num >> i) & 1;
    }

    // Mostrar la representación binaria y la cantidad de bits encendidos
    printf("Representacion binaria: ");
    for (int i = bits - 1; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\nNumero de bits encendidos: %d\n", num_bits_encendidos);
}

// Función para convertir una calificación numérica en una calificación en letra
void calificaciones()
{
    int cali;
    char letra;

    // Solicitar al usuario que ingrese una calificación numérica entre 0 y 100
    printf("Ingrese una calificacion numerica entre 0 y 100: ");
    scanf("%d", &cali);

    // Verificar si la calificación está dentro del rango válido (0-100)
    if (cali < 0 || cali > 100)
    {
        printf("ERROR: La calificacion debe estar entre 0 y 100.\n");
        return;
    }
    else
    {
        // Asignar la calificación en letra según rangos predefinidos
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

    // Mostrar la calificación numérica y la calificación en letra
    printf("La calificacion numerica:  %d\n", cali);
    printf("La calificacion en letra:  %c", letra);
}

// Función principal para gestionar un inventario de elementos
void inven()
{
    int opcion;

    while (1)
    {
        // Mostrar el menú de opciones
        printf("\n--- Menú de Inventario ---\n");
        printf("1. Agregar elemento\n");
        printf("2. Retirar elemento\n");
        printf("3. Mostrar inventario\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        // Evaluar la opción seleccionada por el usuario
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
            return;
        default:
            printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }
    }
}

// Función para agregar elementos al inventario
void agregarElemento()
{
    if (cantidadElementos < CAPACIDAD_MAXIMA)
    {
        int cantidad;

        // Solicitar al usuario la cantidad a agregar
        printf("Ingrese la cantidad a agregar: ");
        scanf("%d", &cantidad);

        // Almacenar la cantidad en el inventario y actualizar la cantidad de elementos
        inventario[cantidadElementos] = cantidad;
        cantidadElementos++;
        printf("Elemento agregado al inventario.\n");
    }
    else
    {
        printf("El inventario está lleno. No se pueden agregar más elementos.\n");
    }
}

// Función para retirar elementos del inventario
void retirarElemento()
{
    if (cantidadElementos > 0)
    {
        int cantidad, total;

        // Solicitar al usuario la cantidad a retirar
        printf("Ingrese la cantidad a retirar: ");
        scanf("%d", &cantidad);

        // Obtener la cantidad total del último elemento del inventario
        total = inventario[cantidadElementos - 1];

        // Verificar si la cantidad a retirar es válida
        if (cantidad <= total)
        {
            // Restar la cantidad del inventario y actualizar la cantidad de elementos
            inventario[cantidadElementos - 1] -= cantidad;
            printf("Elemento retirado del inventario.\n");

            // Si la cantidad se reduce a cero, reducir la cantidad de elementos
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

// Función para mostrar el contenido actual del inventario
void mostrarInventario()
{
    printf("\n--- Inventario ---\n");

    for (int i = 0; i < cantidadElementos; i++)
    {
        printf("Elemento %d: %d\n", i + 1, inventario[i]);
    }
}

// Función para validar un número en un rango específico
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
