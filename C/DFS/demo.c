#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "dfs.h"

/* create adj list function */
node* adjacent (vertex* v, int, ...);


int main (void) {
    /* array of vertexes */
    vertex* g = (vertex*) malloc (sizeof (vertex) * 6);
    for (int i = 0; i < 6; i++) {
        g[i].color = 2;
        g[i].disc = 0;
        g[i].pred = NULL;
    }

    /* create adjacency list for every node */
    g[0].adj = adjacent (g, 2, 1, 3);
    g[1].adj = adjacent (g, 2, 0, 2);
    g[2].adj = adjacent (g, 2, 1, 3);
    g[3].adj = adjacent (g, 3, 0, 2, 4);
    g[4].adj = adjacent (g, 2, 3, 5);
    g[5].adj = adjacent (g, 1, 4);

    /* run dfs and show discovery time for every node */
    if (dfs (&g[0], 6) == 0) {
        for (int i = 0; i < 6; i++) {
            printf ("vertex %d = %d\n", i, g[i].disc);
        }
    }
    
    return 0;
}

node* adjacent (vertex* v, int n, ...) {
    va_list args;
    va_start (args, n);

    node* list = (node*) malloc (sizeof (node) * (n + 1));
 
    for (int i = 0; i < n; i++) {
        list[i].vert = &v[va_arg (args, int)];
        list[i].next = &list[i + 1];
    }
    list[n - 1].next = NULL;
    va_end (args);
    return list;
}
    
    
