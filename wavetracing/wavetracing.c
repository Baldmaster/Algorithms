#include "wavetracing.h"

/* Coordinates increment */

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


/* looking for path in maze */
int find_path (int* maze, int width, int height, wave_node *start, wave_node *target) {
    /* initializing a list of utmost points in wavefront list*/
    wave_node* wavefront = (wave_node*) malloc (sizeof (wave_node));
    /* temp pointer*/
    wave_node* wave;
    /* insert starting point to wavefront */
    insert (&wavefront, start -> x, start -> y);
    /* mark number */
    int n = 2;
    /* temp variables */
    int j, temp_x, temp_y;
    /* setting starting point to 1 */
    *(maze + ((start -> y) * height) + (start -> x)) = 1;

    /* while there are points in wavefront */
    while (wavefront) {

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
		    *(maze + (temp_y * height) + temp_x) = n;
		    /* free wavefront list */
		    empty_wavefront (&wavefront);
		    free (wavefront);
		    /* return success value */
		    printf ("\n----- Path found! Length: %d -----\n", n);
		    return 0;
		}
		
		/* if out of bounds goto next side checking */
		if (temp_x < 0 || temp_x > width || temp_y < 0 || temp_y > height)
		    continue;
		
	        /* if point is free, mark it and insert new point to wavefront */
		if (*(maze + (temp_y * height) + temp_x) == 0) {
		    *(maze + (temp_y * height) + temp_x) = n;
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
	/* incrementing mark number */
	n++;
    }
    /* if there are no more free points and target point not reached, return failure */
    printf ("\n----- PATH NOT FOUND -----\n");
    /* free wavefront list */
    empty_wavefront (&wavefront);
    free (wavefront);
    /* return fail value */
    return 1;
}


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

void empty_wavefront (wave_node** start) {
    wave_node* temp = (*start);
    wave_node* next = (*start);
    while (temp != NULL) {
	next = next -> next;
	free (temp);
	temp = next;
    }
}
