/************************************************************
   Lee algorithm usage example.
 ************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "wavetracing.h"

#define LIMIT 32

int init (FILE*, int* width, int* height, int* x1, int* y1, int* x2, int* y2);

int main (int argc, char* argv[]) {
    FILE* in;
    if (argc != 2) {
        printf ("Usage: %s filename\n", argv[0]);
        exit (EXIT_FAILURE);
    }
  
    if ((in = fopen (argv[1], "r")) == NULL) {
        printf ("Failed to open file \"%s\"! Does it exist?", argv[1]);
        exit (EXIT_FAILURE);
    }
    char str[LIMIT + 1];
    int width, height, j, i = 0;
    int start_x, start_y, target_x, target_y;

    if (init (in, &width, &height, &start_x, &start_y, &target_x, &target_y)) {
        printf ("Check your input file!\n");
        exit (EXIT_FAILURE);
    }

    unsigned char maze[height][width];
    i = 0;
    while ((fscanf (in, "%s", str)) == 1) {
        j = 0;
        while (str[j] != '\0') {
            maze[i][j] = str[j];
            j++;
        }
        i++;
    }

    list_node start, target;
    start.x = start_x;
    start.y = start_y;
    start.next = NULL;
    start.prev = NULL;

    target.x = target_x;
    target.y = target_y;
    target.next = NULL;
    target.prev = NULL;
    
    if (find_path (&maze[0][0], width, height, &start, &target) == 0)
        show_path (&maze[0][0], width, height, target.x, target.y);
	   
    return 0;
}

int init (FILE* in, int* width, int* height, int* x1, int* y1, int* x2, int* y2) {

    char str[LIMIT + 1];
    fgets (str, 33, in);
    if (sscanf (str, "%d", width) != 1) {
        return 1;
    }

    fgets (str, 33, in);
    if (sscanf (str, "%d", height) != 1) {
        return 1;
    }

    fgets (str, 32, in);
    if (sscanf (str, "%d %d", x1, y1) != 2) {
        return 1;
    }
    
    fgets (str, 32, in);
    if (sscanf (str, "%d %d", x2, y2) != 2) {
        return 1;
    }

    if (*width < 10 || *width > LIMIT || *height < 10 || *height > 32 ||
        *x1 < 0 || *x1 > *width || *y1 < 0 || *y1 > *height ||
        *x2 < 0 || *x2 > *width || *y2 < 0 || *y2 > *height)
        return 1;

    return 0;
}
