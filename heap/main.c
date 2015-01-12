#include "heap.h"
#include <stdio.h>

/* compare <=. Build min-heap */
int compare_smaller (const int*, const int*);

/* compare >=. Build max-heap */
int compare_larger (const int*, const int*);

/* swap values */
void swap (int*, int*);


int main() {
    bin_heap h;
    int j;

    int array[] = {2,3,45,6,7,8,1,23,43,78,234,98,92,11,32};

    h.data = array;
    h.size = sizeof (array) / sizeof (array[0]);

    /* build max-heap */  
    build_heap (&h, sizeof (array[0]), (COMPARE) compare_larger, (SWAP) swap);

    printf ("--- Max-Heap ---\n");
    
    for (j = 0; j < h.size; j++)
        printf ("%d\n", array[j]);

    /*build min-heap */
    build_heap (&h, sizeof (array[0]), (COMPARE) compare_smaller, (SWAP) swap);
    
    printf ("--- Min-Heap ---\n");

    for (j = 0; j < h.size; j++)
        printf ("%d\n", array[j]);
    
    
    return 0;
}

int compare_larger (const int* a, const int* b) {
    return *a >= *b;
}

int compare_smaller (const int* a, const int* b) {
    return *a <= *b;
}


void swap (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
