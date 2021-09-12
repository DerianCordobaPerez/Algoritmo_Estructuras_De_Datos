#ifndef FUNCIONES_H
#define FUNCIONES_H

/**
 * Manda un mensaje de error y termina el programa
 * 
 * @param void
 * @return void
*/
extern void error(char *);

/**
 * Obtiene el factorial de un numero
 * 
 * @param int numero
 * @return int
*/
extern int factorial(int);

/**
 * Devuelve la memoria asignada para cualquier tipo de datos
 * 
 * @param int
 * @return void *
*/
extern void *asignacion_de_memoria(int);

/**
 * Remplaza un caracter en especifico por otro dentro de una
 * cadena de caracteres
 * 
 * @param char *
 * @param char
 * @param char
 * @return char *
*/
extern char *replazar(char *, char, char);

/**
 * Devuelve la cantidad de cuadrados anidados desde un
 * punto medio
 * 
 * @param int
 * @return int
*/
extern int cantidadCuadros(int);

/**
 * Coloca de reversa la cadena
 * 
 * @param char *
 * @param int
 * @param unsigned int
 * @return void
*/
extern void reversaPalabra(char *, int, unsigned int);

/**
 * Devuelve el resultado del algoritmo Hanoi
 * 
 * @param int
 * @param char
 * @param char
 * @param char
 * @return void
*/
extern void torreHanoi(int, char, char, char);

#endif