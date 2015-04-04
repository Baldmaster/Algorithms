#include "Dijkstra.h"
#include <stdlib.h>
#include <stdio.h>

void dijkstra (bin_heap* heap, COMPARE compare, SWAP swap) {
    while (heap -> size) {
        vertex* temp = extract (heap, (COMPARE) compare, (SWAP) swap);
        for (node* n = temp -> adj; n; n = n -> next) {
            if ((n -> vert -> dist) > (temp -> dist + n -> weight)) {
                (n -> vert -> dist) = (temp -> dist + n -> weight);
                n -> vert -> p = temp;
                change_key (heap, n -> vert, (SWAP) swap);
            }
        }
    }
}

void heapify (bin_heap* heap, int index, COMPARE compare, SWAP swap) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int temp = index;

    if (left < (heap -> size) &&
        compare ((heap -> data)[left], (heap -> data)[index]))
 
        temp = left;
    else
        temp = index;

    if (right < (heap -> size) &&
        compare ((heap -> data)[right], (heap -> data)[temp]))
        temp = right;

    if (temp != index) {
        swap (&((heap -> data)[index]), &((heap -> data)[ temp]));
        heapify (heap, temp, compare, swap);
    }
}

void build_heap (bin_heap* heap, COMPARE compare, SWAP swap) {
    int i;
    for (i = (heap -> size / 2) - 1; i >= 0; i--)
        heapify (heap, i, compare, swap);
}


void sort_heap (bin_heap* heap, COMPARE compare, SWAP swap) {
     build_heap (heap, compare, swap);

    int i, heap_size = heap -> size;
    
    for (i = (heap -> size) - 1; i; i--) {
        swap (&((heap -> data)[0]), &((heap -> data)[ i ]));
        (heap -> size)--;
        heapify (heap, 0, compare, swap);
    }
    heap -> size = heap_size;
}


int parent (int n) {
    return n % 2 ? n / 2 : n / 2 - 1;
}

int push (node** stack, vertex* v, int w) {
    node* new_node = (node*) malloc (sizeof (node));

    if (!new_node) {
        printf ("No memory!\n");
        return 1;
    }
    
    new_node -> vert = v;
    new_node -> weight = w;

    if (*stack)
        new_node -> next = *stack;
    else
        new_node -> next = NULL;

    *stack = new_node;
    
    return 0;
}

vertex* pop (node** stack) {
    if (*stack) {
        node* temp = *stack;
        vertex* v = temp -> vert;
        *stack = (*stack) -> next;
        free (temp);
        return v;
    }
    else
        return NULL;
}

vertex* extract (bin_heap* h, COMPARE compare, SWAP swap) {
    vertex* min = (h -> data)[0];
    swap (&((h -> data)[0]) , &((h -> data)[h -> size - 1]));
    h -> size = h -> size - 1;
    heapify (h, 0, compare, swap);
    return min;
}


void change_key (bin_heap* h, vertex* v, SWAP swap) {
    int i = v -> q_number;
    while (i > 0 && (h -> data)[parent(i)] -> dist >
           ((h -> data)[i]) -> dist) {
        swap (&((h -> data)[parent(i)]), &((h -> data)[i]));
        i = (h -> data)[parent(i)] -> q_number;
    }
}
