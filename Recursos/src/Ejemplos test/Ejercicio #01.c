#include <assert.h>
#include <stdbool.h>
#include <string.h>

bool esPalindroma(char *, int, int);

void main(void) {
    
    // Si la palabra no es palindroma pasara el test
    assert(!esPalindroma("Hola", 0, strlen("Hola") - 1));

    // Si la palabra es palindroma pasara el test
    assert(esPalindroma("abba", 0, strlen("abba") - 1));
    
    assert(esPalindroma("anona", 0, strlen("anona") - 1));

}

bool esPalindroma(char *palabra, int posicion, int tamanio) {

    if(posicion > tamanio / 2)
        return true;

    if(palabra[posicion] != palabra[tamanio - posicion])
        return false;

    return esPalindroma(palabra, posicion + 1, tamanio);
}