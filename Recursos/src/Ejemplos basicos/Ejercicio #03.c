#include "../librerias/cabeceras/cabeceras.h"

int main(int argc, char const **argv) {
    
    int numero;
    
    printf("Ingrese el numero: ");
    scanf("%i", &numero);

    printf("La cantidad de cuadrados son: %i\n", cantidadCuadros(numero));

    return 0;
}