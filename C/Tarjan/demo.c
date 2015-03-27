#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "tarjan.h"

/* create adj list function */
node* adjacent (vertex* v, int, ...);


int main (void) {
    /* array of vertexes */
    vertex* g = (vertex*) malloc (sizeof (vertex) * 6);
    for (int i = 0; i < 6; i++) {
        g[i].index = 0;
        g[i].low = 0;
        g[i].name = 65 + i;
        g[i].in_stack = 0;
    }

    /* create adjacency list for every node */
    g[0].adj = adjacent (g, 1, 1);
    g[1].adj = adjacent (g, 1, 2);
    g[2].adj = adjacent (g, 1, 3);
    g[3].adj = adjacent (g, 1, 2);
    g[4].adj = adjacent (g, 2, 5, 3);
    g[5].adj = adjacent (g, 1, 4);

    components* c = tarjan (&g[0], 6);

    while (c) {
        node* temp = c -> component;
        while (temp) {
            printf ("%c -> ", temp -> vert -> name);
            temp = temp -> next;
        }
        printf ("\n");
        c = c -> next;
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
    
    
