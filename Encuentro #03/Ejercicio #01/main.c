#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const **argv) {
    
    int *arr = (int*)malloc(10 * sizeof arr), buscado;
    bool bandera = false;

    for(int i = 0; i < 10; ++i) {
        printf("Ingrese el valor en la posicion %i: ", i + 1);
        scanf("%i", &arr[i]);
    }

    printf("Ingrese el numero a buscar: ");
    scanf("%i", &buscado);

    for(int i = 0; i < 10; ++i) {
        if(buscado == arr[i]) {
            printf("El numero buscado %i se encontro en la posicion %i\n", buscado, i + 1);
            bandera = true;
            break;
        }
    }

    if(!bandera)
        printf("El valor buscado no se encontro dentro del conjunto de datos\n");

    return 0;
}
