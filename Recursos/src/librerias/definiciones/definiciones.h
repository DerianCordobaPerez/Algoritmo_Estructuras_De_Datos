#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#define LONGITUD 10
#define LONGITUD_CARACTERES 15

/**
 * Estructura Persona
 * 
 * @param char* nombre
 * @param int edad
 * @param float altura
*/
typedef struct {
    char *nombre;
    int edad;
    double altura;
} Persona;

#endif