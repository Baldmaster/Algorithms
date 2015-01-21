#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "bfs.h"

node* adjacent (vertex* v, int, ...);


int main (void) {
    vertex* g = (vertex*) malloc (sizeof (vertex) * 6);
    for (int i = 0; i < 6; i++) {
        g[i].color = 2;
        g[i].d = 0;
    }

    g[0].adjacent = adjacent (g, 2, 1, 3);
    g[1].adjacent = adjacent (g, 2, 0, 2);
    g[2].adjacent = adjacent (g, 2, 1, 3);
    g[3].adjacent = adjacent (g, 3, 0, 2, 4);
    g[4].adjacent = adjacent (g, 2, 3, 5);
    g[5].adjacent = adjacent (g, 1, 4);

    if (bfs (g, &g[0]) == 0) {
        for (int i = 0; i < 6; i++) {
            printf ("vertex %d - d = %d\n", i, g[i].d);
        }
    }
    
    return 0;
}

struct _node* adjacent (vertex* v, int n, ...) {
    va_list args;
    va_start (args, n);

    struct _node* list = (node*) malloc (sizeof (node) * (n + 1));
 
    for (int i = 0; i < n; i++) {
        list[i].vert = &v[va_arg (args, int)];
        list[i].next = &list[i + 1];
    }
    list[n - 1].next = NULL;
    va_end (args);
    return list;
}
    
    
