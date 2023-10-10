/*
Nombre del archivo: 1.c
Autor: Lizeth Barrios Retana
Fecha de creación: 27 de Agosto de 2023
Descripción: Este codigo contiene 3 opciones para ejecutar el codigo:
    1.Un programa que permita a los usuarios ingresar un número entero, especificar el número de bits que se deben considerar y luego analizar el número en términos de bits encendidos, posiciones y representación binaria.
    2.Crear un programa que tome una calificación numérica y la convierta en una calificación en letra utilizando operadores ternarios.
    3.El objetivo de este ejercicio es simular un sistema básico de gestión de inventario en C, donde los usuarios pueden agregar y retirar elementos del inventario.
*/
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
int inventario[CAPACIDAD_MAXIMA]; // Arreglo para almacenar el inventario de elementos
int cantidadElementos = 0;        // Variable global para llevar un registro de la cantidad actual de elementos en el inventario
int validarNumero(char mensaje[], int ri, int rf);

int main()
{
    char op;

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
    char cali;
    char letra;

    // Solicitar al usuario que ingrese una calificación numérica entre 0 y 100
    cali = validarNumero("Ingrese una calificacion numerica entre 0 y 100: ", 0, 100);

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
        opcion = validarNumero(" \n--- Menú de Inventario ---\n1. Agregar elemento\n2. Retirar elemento\n3. Mostrar inventario\n4. Salir\nSeleccione una opción:\n", 1, 4);

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
