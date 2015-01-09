#include <stdio.h>
#include <stdlib.h>

#include "wavetracing.h"

/* Coordinates increment */
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

/* looking for path in maze */
int find_path (unsigned char* maze, int width, int height, wave_node *start, wave_node *target) {
    /* initializing a list of utmost points in wavefront list*/
    wave_node* wavefront = (wave_node*) malloc (sizeof (wave_node));
    /* temp pointer points to current node of wavefront */
    wave_node* wave;
    /* insert starting point to wavefront */
    insert (&wavefront, start -> x, start -> y);
    /* mark value */
    int mark = 1;
    /* temp variables */
    int j, temp_x, temp_y;
    /* mark starting point as 'S' */
    *(maze + ((start -> y) * height) + (start -> x)) = 'S';

    /* while there are points in wavefront */
    while (wavefront) {
    /* assing head of wavefront list */
	wave = wavefront;
	/* traversing all points in list */
	while (wave) {
	    /* check all four sides */
	    for (j = 0; j < 4; j++) {
		/* adding increment values to coordinates */
		temp_x = (wave -> x) + dx[j];
		temp_y = (wave -> y) + dy[j];
		
		/* return success if reached target point */
		if (temp_x == target -> x && temp_y == target -> y) {
		    *(maze + (temp_y * height) + temp_x) = mark;
		    /* free wavefront list */
		    empty_wavefront (&wavefront);
		    /* return success value */
		    printf ("\n----- Path found! Length: %d -----\n", mark);
		    return 0;
		}
		
		/* if out of bounds goto next side checking */
		if (temp_x < 0 || temp_x > width || temp_y < 0 || temp_y > height)
		    continue;
		
	        /* if nearby point is free, mark it and insert new point to head of wavefront */
		if (*(maze + (temp_y * height) + temp_x) == '-') {
		    *(maze + (temp_y * height) + temp_x) = mark;
		    /* if insertion failed return failure value */
		    if (insert (&wavefront, temp_x, temp_y))
			return 2;
		}
	    }
	    /* delete current point from list and goto next point*/
	    wave_node* temp = wave;
	    wave = wave -> next;
	    delete (&wavefront, &temp);
	}
	/* incrementing mark value */
	mark++;
    }
    /* if there are no more free points and target point not reached, return failure */
    printf ("\n----- PATH NOT FOUND -----\n");
    /* free wavefront list */
    free (wavefront);
    /* return fail value */
    return 1;
}

/* show path from starting point to final */
void show_path (unsigned char* maze, int width, int height, int x, int y) {
    int count = *(maze + (y * height) + x);
    *(maze + (y * height) + x) = 'F';
    int i, j, temp_x, temp_y;
    while (count) {
	for (j = 0; j < 4; j++) {
	    /* adding increment values to coordinates */
	    temp_x = x + dx[j];
	    temp_y = y + dy[j];
	    /* if out of bounds goto next side checking */
	    if (temp_x < 0 || temp_x > width || temp_y < 0 || temp_y > height)
		    continue;	    
	    /* mark path point with letter showing next step direction
             * u - up, d - down, l - left, r - right                  */
	    if (*(maze + (temp_y * height) + temp_x) == count) {
	        switch (j) {
	    	    case 0:
	    	        *(maze + (temp_y * height) + temp_x) = 'l';
	    	        break;
	    	    case 1:
	    	        *(maze + (temp_y * height) + temp_x) = 'u';
	    	        break;
	    	    case 2:
	    	        *(maze + (temp_y * height) + temp_x) = 'r';
	    	        break;
	    	    case 3:
	    	        *(maze + (temp_y * height) + temp_x) = 'd';
	        }
		x = temp_x;
		y = temp_y;
	        break;	    
	    }		
	}
        count--;
    }
    /* display maze with path */
    for (i = 0; i < height; i++) {
	for (j = 0; j < width; j++)
	    printf ("%2c", *(maze + (i* height) + j) < 33 ?
		    '-' : *(maze + (i* height) + j));
	printf ("\n");
    }
}
	
    


/* insert new node into wavefront points list */
int insert (wave_node** start, int x, int y) {
    wave_node* node = (wave_node*) malloc (sizeof (wave_node));
    if (node == NULL)
	return 1;
    else {
	node -> x = x;
	node -> y = y;
	if ((*start) == NULL) {
	    node -> next = NULL;
	}
	else {
	    node -> next = *start;
	    (*start) -> prev = node;
	}
	node -> prev = NULL;
	*start = node;
	return 0;
    }
}

/* delete node from wavefront points list */
void delete (wave_node** start, wave_node** wave) {
    if (*start == *wave) {
	free (*wave);
	*start = NULL;
    }
    else {
	wave_node* prev = (*wave) -> prev;
	wave_node* next = (*wave) -> next;
	prev -> next = next;
	if (next)
	    next -> prev = prev;
	free (*wave);
    }

}

/* delete all nodes from list and free memory */
void empty_wavefront (wave_node** start) {
    wave_node* temp = (*start);
    wave_node* next = (*start);
    while (temp != NULL) {
	next = next -> next;
	free (temp);
	temp = next;
    }
}
