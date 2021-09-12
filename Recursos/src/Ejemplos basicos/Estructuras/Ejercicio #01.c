#include "../../librerias/cabeceras/cabeceras.h"

Persona crearPersona();
void mostrarPersona(Persona);

int main(int argc, char const **argv) {
    
    if(argc != 2)
        error("Error a la cantidad de la parametros");

    int i = 0;

    Persona *personas = (Persona *)asignacion_de_memoria(atoi(argv[1]));

    while(i < atoi(argv[1])) {
        
        printf("Ingrese a la persona numero %i\n", (i + 1));
        *(personas + i) = crearPersona();
        
        ++i;
    }

    putchar('\n');

    for(i = 0; i < atoi(argv[1]); ++i)
        mostrarPersona(personas[i]);

    free(personas);

    return 0;
}

Persona crearPersona() {
    Persona persona;
    char *cadena = (char *)asignacion_de_memoria(20);

    printf("Ingrese el nombre de la persona: ");
    scanf("%s", cadena);
    persona.nombre = (char *)asignacion_de_memoria(strlen(cadena) + 1);
    strcpy(persona.nombre, cadena);

    printf("Ingrese la edad de la persona: ");
    scanf("%i", &persona.edad);

    printf("Ingrese la altura de la persona: ");
    scanf("%lf", &persona.altura);

    free(cadena);

    return persona;
}

void mostrarPersona(Persona persona) {
    printf("Nombre: %10s - Edad: %2i - Altura: %2.2lf\n", persona.nombre, persona.edad, persona.altura);
}
