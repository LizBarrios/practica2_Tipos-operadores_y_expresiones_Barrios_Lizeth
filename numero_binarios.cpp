#include <stdio.h>

int main() 
{
    int num, bits;
    
    printf("Ingresa un numero entero: ");
    scanf("%d", &num);
    
    printf("Ingresa el numero de bits a considerar: ");
    scanf("%d", &bits);
    
    if (bits <= 0) 
    {
        printf("El numero de bits debe ser mayor que cero.\n");
        return 1;
    }
    
    int num_bits_encendidos = 0;
    
    for (int i = 0; i < bits; i++) {
        num_bits_encendidos += (num >> i) & 1;
    }
    
    printf("Representacion binaria: ");
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\nNumero de bits encendidos: %d\n", num_bits_encendidos);
    
    return 0;
}