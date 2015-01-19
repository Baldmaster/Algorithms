#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"

void quicksort (void* array, size_t type_size,
                int p, int r,
                COMPARE compare, SWAP swap) {
    if (p < r) {
        int q = partition (array, type_size, p, r, compare, swap);
        quicksort (array, type_size, p, q - 1, compare, swap);
        quicksort (array, type_size, q + 1, r, compare, swap);
    }
}

int partition (void* array, size_t type_size,
               int p, int r,
               COMPARE compare, SWAP swap) {
    void* x = (array + r * type_size);
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (compare (array + j * type_size, x)) {
            i++;
            swap ((array + i * type_size), (array + j * type_size));
        }
    }
    i++;
    swap ((array + i * type_size), (array + r * type_size));
    return i;
}
            
