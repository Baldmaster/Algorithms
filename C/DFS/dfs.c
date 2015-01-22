#include <stdio.h>
#include <stdlib.h>

#include "dfs.h"

int dfs (vertex* g, int len) {
    int time = -1;

    /* for each vertex */
    for (int i = 0; i < len; i++)
        /* if it is not discovered, explore it */
        if (g[i].color == 2)
            dfs_visit (&g[i], &time);
    return 0;
}

void dfs_visit (vertex* v, int* time) {
    (*time)++;
    v -> disc = *time;
    v -> color = 1;
    
    /* explore edges (v, i)*/
    for (node* i = v -> adj; i; i = i -> next) {
        /* if vertex is not discovered, explore it */
        if (i -> vert -> color == 2) {
            i -> vert -> pred = v;
            dfs_visit (i -> vert, time);
        }
    }
    
    /* blacken vertex */
    v -> color = 0;
    
    (*time)++;
}
    
