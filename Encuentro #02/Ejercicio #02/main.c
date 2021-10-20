#include "funciones.c"

int main(int argc, char const **argv) {
    
    // Validamos que se le pase el numero de parametros necesarios
    if(argc != 3)
        error("La ejecucion no cuenta con los parametros necesarios");

    // Intentamos abrir el fichero
    FILE *archivo = abrirFichero(argv[1], argv[2]);
    
    // Variable donde iremos guardando la letra actual del fichero leido
    char caracter;

    while((caracter = fgetc(archivo)) != EOF) {
        
    }

    return 0;
}
