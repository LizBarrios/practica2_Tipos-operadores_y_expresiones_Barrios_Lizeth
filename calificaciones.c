#include <stdio.h>

int main()
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
    return 0;
}
