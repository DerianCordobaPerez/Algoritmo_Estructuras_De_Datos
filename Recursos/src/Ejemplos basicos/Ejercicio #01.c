#include "../librerias/cabeceras/cabeceras.h"

int main(int argc, char const **argv) {
    
    int i;
    char *numero = (char *)asignacion_de_memoria(LONGITUD_CARACTERES + 1), *numeros = (char *)asignacion_de_memoria(LONGITUD);
    strcpy(numero, "(xxx) xxx-xxxx");

    for(i = 0; i < LONGITUD; ++i) {
        printf("Ingresa el numero en la posicion %i: ", (i + 1));
        scanf(" %c", &numeros[i]);
    }

    for(i = 0; i < LONGITUD; ++i)
        numero = replazar(numero, 'x', numeros[i]);

    printf("\n\nEl numero de telefono es: %s\n\n", numero);

    free(numero);
    free(numeros);

    return 0;
}