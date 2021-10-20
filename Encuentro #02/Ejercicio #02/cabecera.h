#ifndef CABECERA_H
#define CABECERA_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Detenemos la ejecucion de la aplicacion mandando un error
 * 
 * @param char * Mensaje que se vera mostrado en el error
*/
void error(char *);

/**
 * Retornamos el fichero que intentamos abrir
 * 
 * @param char * Nombre del fichero abrir
 * @param char * Formato del fichero abrir
 * @return FILE *
*/
extern FILE *abrirFichero(char *, char *);

#endif