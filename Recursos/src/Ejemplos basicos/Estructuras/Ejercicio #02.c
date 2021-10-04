#include <stdio.h>
#include <stdlib.h>
#define TAMANIO_DICCIONARIO 30

/**
 * Estructura HashMap
 * 
 * @param int dato
 * @param int clave
 * 
*/
typedef struct {
    int dato, clave;
} Diccionario;

// Variables globales para el uso del diccionario
Diccionario *diccionario[TAMANIO_DICCIONARIO], *temporal;

/**
 * Devuelve el hashCode que se encuentre con la clave buscada
 * 
 * @param int clave
 * @return int hashCode el item encontrado
*/
extern const int codigoHash(const int);

/**
 * Inserta un dato dentro del diccionario
 * 
 * @param int dato
 * @param int clave
 * @return void
*/
extern const void insertar(const int, const int);

/**
 * Muestra por pantalla el contenido del diccionario
 * 
 * @return void
*/
extern const void mostrar();

/**
 * Elimina dentro del diccionario el item buscado
 * 
 * @param Diccionario *
 * @return Diccionario *
*/
extern Diccionario *eliminar(const Diccionario *); 

/**
 * Devuelve el item encontrado con la clave buscada
 * 
 * @param int clave
 * @return Direccionario *
*/
extern Diccionario *buscar(const int);

int main(int argc, char const **argv) {

    temporal = (Diccionario *)malloc(sizeof(Diccionario));
    temporal->dato = -1;
    temporal->clave = -1;

    insertar(1, 20);
    insertar(2, 70);
    insertar(3, 80);
    insertar(4, 25);

    mostrar();
    Diccionario *buscado = buscar(3);

    buscado != NULL ? printf("Clave encontrada con su dato: %d\n", buscado->dato) : printf("Clave no encontrada\n");

    eliminar (buscado);
    printf("Se ha eliminado la clave 3\n");

    buscado = buscar(3);

    buscado != NULL ? printf("Clave encontrada con su dato: %d\n", buscado->dato) : printf("Clave no encontrada\n");

    insertar(4, 50);
    mostrar();
    
}

extern const int codigoHash(const int clave) {
    return clave % TAMANIO_DICCIONARIO;
}

extern const void insertar(const int clave, const int dato) {

    if(buscar(clave) != NULL) {
        printf("\nLa clave existe ya existe no se agregara\n");
        return;
    }

    Diccionario *nuevo = (Diccionario *)malloc(sizeof(Diccionario));
    nuevo->dato = dato;
    nuevo->clave = clave;

    int indice = codigoHash(clave);

    while (diccionario[indice] != NULL && diccionario[indice]->clave != -1) {
        ++indice;
        indice %= TAMANIO_DICCIONARIO;
    }

    diccionario[indice] = nuevo;
}

extern const void mostrar() {
    int i;

    for (i = 0; i < TAMANIO_DICCIONARIO; i++)
        if (diccionario[i] != NULL && diccionario[i]->clave != -1)
            printf("%i. clave: %i dato: %i\n", i, diccionario[i]->clave, diccionario[i]->dato);

    putchar('\n');
}

extern Diccionario *buscar(const int clave) {
    int indice = codigoHash(clave);

    while (diccionario[indice] != NULL) {

        if (diccionario[indice]->clave == clave)
            return diccionario[indice];

        ++indice;
        indice %= TAMANIO_DICCIONARIO;
    }

    return NULL;
}

extern Diccionario *eliminar (const Diccionario *temp) {
    int indice = codigoHash(temp->clave);

    while (diccionario[indice] != NULL) {

        if (diccionario[indice]->clave == temp->clave) {
            Diccionario *temp = diccionario[indice];
            diccionario[indice] = temporal;
            return temp;
        }

        ++indice;
        indice %= TAMANIO_DICCIONARIO;
    }

    return NULL;
}