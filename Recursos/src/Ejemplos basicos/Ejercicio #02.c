#include "../librerias/cabeceras/cabeceras.h"

int main(int argc, char const **argv) {
    
    int numero;

    do {
        printf("Ingrese el numero: ");
        scanf("%i", &numero);
    } while(numero < 1);

    printf("El factorial del numero %i es: %i\n", numero, factorial(numero));

    return 0;
}