#include "../librerias/cabeceras/cabeceras.h"

int main(int argc, char const **argv) {

    if(argc != 2)
        error("Error con la cantidad de parametros");

    char *temp = (char *)asignacion_de_memoria(strlen(argv[1]));
    strcpy(temp, argv[1]);
    reversaPalabra(temp, 0, (unsigned int)strlen(temp) - 1);

    printf("La palabra original es %s y ordenada es %s\n", argv[1], temp);
    
    free(temp);
    return 0;
}