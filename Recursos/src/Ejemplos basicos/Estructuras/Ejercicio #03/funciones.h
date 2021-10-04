#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int capacity, size, *arr;
} ArrayList;

ArrayList *initialiseWithCapacity(int);

ArrayList *initialise();

ArrayList *initialiseWithArray(int *);

ArrayList *values(int, ...);

ArrayList *range(int, int, int);

ArrayList *slice(ArrayList *, int, int, int);

bool clear(ArrayList *);

bool ensureCapacity(ArrayList *, int);

bool trimToSize(ArrayList *);

bool fill(ArrayList *, int, int);

bool append(ArrayList *, int);

bool extendWithArray(ArrayList *, int *, int);

bool extend(ArrayList *, ArrayList *);

bool insert(ArrayList *, int, int);

ArrayList *copy(ArrayList *);

int indexOf(ArrayList *, int);

int lastIndexOf(ArrayList *, int);

int binarySearch(ArrayList *, int);

bool contains(ArrayList *, int);

bool isEmpty(ArrayList *);

bool isEqual(ArrayList *, ArrayList *);

bool pop(ArrayList *, int);

bool remove(ArrayList *, int);

int get(ArrayList *, int);

bool set(ArrayList *, int, int);

bool reverse(ArrayList *);

bool replace(ArrayList *, int, int);

int comparisonFunctionAscending (const void *, const void *);

int comparisonFunctionDescending (const void *, const void *);

bool sort(ArrayList *);

bool sortReverse(ArrayList *);

int count(ArrayList *, int);

int sum(ArrayList *);

int length(ArrayList *);

int capacity(ArrayList *);

int *toArray(ArrayList *);

char *toString(ArrayList *);

bool display(ArrayList *);

#endif