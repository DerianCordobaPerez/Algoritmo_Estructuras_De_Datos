#include "funciones.h"

ArrayList *initialiseWithCapacity(int initialCapacity) {
    ArrayList *arrayList = (ArrayList *)malloc(sizeof *arrayList);
    
    arrayList->capacity = initialCapacity;
    arrayList->arr = (int *)malloc(arrayList->capacity * sizeof *(arrayList->arr));
    arrayList->size = 0;

    return arrayList;
}

ArrayList *initialise() {
    return initialiseWithCapacity(5);
}

ArrayList *initialiseWithArray(int *arr) {
    int length = sizeof(arr) / sizeof(int);
    ArrayList *arrayList = initialiseWithCapacity(length);

    for(int i = 0; i < length; ++i)
        arrayList->arr[arrayList->size++] = arr[i];

    return arrayList;
}

ArrayList *values(int length, ...) {
    va_list valist;
    va_start(valist, length);
    ArrayList *arrayList = initialiseWithCapacity(length);

    for(int i = 0; i < length; ++i)
        arrayList->arr[arrayList->size++] = va_arg(valist, int);
    
    va_end(valist);
    return arrayList;
}

ArrayList *range(int start, int stop, int step) {
    if(step == 0)
        return initialiseWithCapacity(0);

    ArrayList *arrayList = initialiseWithCapacity(abs(stop - start) / abs(step) + 1);
    
    for(int i = start; step > 0 ? i < stop : i > stop; i += step)
        arrayList->arr[arrayList->size++] = i;
    
    return arrayList;
}

ArrayList *slice(ArrayList *array, int start, int stop, int step) {
    if(step == 0 || start < 0 || stop < -1 || start >= array->size || stop >= array->size)
        return initialiseWithCapacity(0);

    ArrayList *arrayList = initialiseWithCapacity(abs(stop - start) / abs(step) + 1);

    for(int i = start; step > 0 ? i < stop : i > stop; i += step)
        arrayList->arr[arrayList->size++] = array->arr[i];

    return arrayList;
}

bool clear(ArrayList *arrayList) {
    free(arrayList->arr);

    arrayList->arr = NULL;
    arrayList->capacity = 0;
    arrayList->size = 0;
    return true;

}

bool ensureCapacity(ArrayList *arrayList, int minCapacity) {
    if(minCapacity > arrayList->capacity) {
        arrayList += (arrayList->capacity >> 1);
        
        if(arrayList->capacity < minCapacity)
            arrayList->capacity = minCapacity;
        
        arrayList->arr = (int *)realloc(arrayList->arr, arrayList->capacity * sizeof *(arrayList->arr));
    }

    return true;
}

bool trimToSize(ArrayList *arrayList) {
    arrayList->capacity = arrayList->size;
    arrayList->arr = (int *)realloc(arrayList->arr, arrayList->capacity * sizeof *(arrayList->arr));
    
    return true;
}

bool fill(ArrayList *arrayList, int value, int length) {
    ensureCapacity(arrayList, length);
    arrayList->size = length;

    for(int i = 0; i < length; ++i)
        arrayList->arr[i] = value;

    return true;
}

bool append(ArrayList *arrayList, int number) {
    ensureCapacity(arrayList, arrayList->size + 1);
    
    arrayList->arr[arrayList->size++] = number;
    
    return true;
}

bool extendWithArray(ArrayList *arrayList, int* array, int length) {
    ensureCapacity(arrayList, arrayList->size + length);
    
    for(int i = 0; i < length; ++i)
        arrayList->arr[arrayList->size++] = array[i];
    
    return true;
}

bool extend(ArrayList *array, ArrayList *extend) {
    extendWithArray(array, extend->arr, extend->size);
    
    return true;
}