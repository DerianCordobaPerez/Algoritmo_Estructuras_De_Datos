#include "cabecera.h"

int main(int argc, char const **argv) {
    
    FILE *fichero;
    int caracter;

    if((fichero = fopen(argv[1], "w+")) == NULL) {
        perror("ERROR: No se pudo abrir el fichero");
        exit(0);
    }

    printf("Ingrese todo el texto deseado\nPara finalizar pulse .\n\n");

    while((caracter = getchar()) != EOF) {
        if(caracter != '.') {
            fputc(caracter, fichero);
            continue;
        }
        break;
    }

    fclose(fichero);

    return 0;
}
