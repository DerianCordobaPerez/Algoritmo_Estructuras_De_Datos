#include "../definiciones/definiciones.h"

extern void error(char *mensaje) {
    perror(mensaje);
    exit(0);
}

extern int factorial(int numero) {
    if(numero == 1)
        return 1;
    return numero * factorial(numero - 1);
}

extern void *asignacion_de_memoria(int cantidad) {
    void *tmp;
    if((tmp = (void *)malloc(cantidad * sizeof(void))) == NULL)
        error("Error al asignar memoria");
    return tmp;
}

extern char *replazar(char *palabra, char buscado, char remplazo) {
    *(strchr(palabra, buscado)) = remplazo;
    return palabra;
}

extern int cantidadCuadros(int numero) {
    return numero <= 1 ? 1 : cantidadCuadros(numero - 1) + ((numero - 1) * 4);
}

extern void reversaPalabra(char *palabra, int posicion, unsigned int tamanio) {
    if (posicion == tamanio / 2) {
        return;
    }

    char temp = palabra[posicion];
    palabra[posicion] = palabra[tamanio - posicion];
    palabra[tamanio - posicion] = temp;

    reversaPalabra(palabra, posicion + 1, tamanio);

}

extern void torreHanoi(int disco, char inicio, char temp, char final) {
    if(disco <= 1) {
        printf("Se movio el disco %i desde el poste %c hasta %c\n", disco, inicio, final);
        return;
    }

    torreHanoi(disco - 1, inicio, final, temp);
    printf("Se movio el disco %i desde el poste %c hasta %c\n", disco, inicio, final);
    torreHanoi(disco - 1, temp, inicio, final);
}