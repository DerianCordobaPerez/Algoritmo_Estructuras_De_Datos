#include "cabecera.h"

void error(char *mensaje) {
    perror(mensaje);
    exit(0);
}

extern FILE *abrirFichero(char *nombre, char *formato) {
    FILE *archivo;

    // Verificamos que el fichero que intentemos abrir no sea NULL
    if((archivo = fopen(nombre, formato)) == NULL)
        error("Error al intentar abrir el fichero");

    // Retornamos el fichero una vez sea encontrado o creado
    return archivo;
}