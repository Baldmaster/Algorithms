#include <stdio.h>
#include <stdlib.h>

#include "wavetracing.h"

/* Coordinates increment */
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

/*------------------------------------------------------------*/

/* looking for path in maze */
int find_path (unsigned char* maze, int width, int height, list_node* start, list_node* target) {
    /* initializing a list of utmost points */
    list_node* wavefront = (list_node*) malloc (sizeof (list_node));
    /* temp pointer points to current node of wavefront */
    list_node* current_node = NULL;
    /* insert starting point to wavefront */
    insert (&wavefront, start -> x, start -> y);
    /* mark value */
    int mark = 1;
    /* temp variables */
    int j, temp_x, temp_y;
    /* mark starting point as 'S' */
    *(maze + ((start -> y) * height) + (start -> x)) = 'S';

    /* while wavefront is not empty */
    while (wavefront) {
        /* assing head of wavefront list to current_node pointer */
	current_node = wavefront;
	
	/* traversing all points in list */
	while (current_node) {
	    
	    /* check all four sides */
	    for (j = 0; j < 4; j++) {
		
		/* adding increment values to coordinates */
		temp_x = (current_node -> x) + dx[j];
		temp_y = (current_node -> y) + dy[j];
		
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
		    
		    /* if insertion failed, free wavefront list and return failure value */
		    if (insert (&wavefront, temp_x, temp_y)) {
			empty_wavefront (&wavefront);
			return 2;
		    }
		}
	    }
	    /* delete current point from list and goto next point*/
	    list_node* temp = current_node;
	    current_node = current_node -> next;
	    delete (&wavefront, &temp);
	}
	/* incrementing mark value */
	mark++;
    }
    /* if there are no more free points and target point not reached, return failure */
    printf ("\n----- PATH NOT FOUND -----\n");
    
    /* free wavefront pointer */
    free (wavefront);
    
    /* return fail value */
    return 1;
}

/*------------------------------------------------------------*/

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
	
/*------------------------------------------------------------*/

/* insert new node into wavefront points list */
int insert (list_node** start, int x, int y) {
    list_node* node = (list_node*) malloc (sizeof (list_node));
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

/*------------------------------------------------------------*/

/* delete node from wavefront points list */
void delete (list_node** start, list_node** current) {
    if (*start == *current) {
	free (*current);
	*start = NULL;
    }
    else {
        list_node* prev = (*current) -> prev;
        list_node* next = (*current) -> next;
	prev -> next = next;
	if (next)
	    next -> prev = prev;
	free (*current);
    }

}

/*------------------------------------------------------------*/

/* delete all nodes from list and free memory */
void empty_wavefront (list_node** start) {
    list_node* temp = (*start);
    list_node* next = (*start);
    while (temp != NULL) {
	next = next -> next;
	free (temp);
	temp = next;
    }
}
