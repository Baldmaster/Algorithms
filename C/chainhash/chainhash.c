#include <stdio.h>
#include <stdlib.h>

#include "chainhash.h"

int hash_insert (hash_table* table, void* data,
                 HASHFUNC hashfunc, COMPARE compare) {
    
    hash_node* new_node = (hash_node*) malloc (sizeof (hash_node));
    
    if (!new_node) {
        printf ("Error! No memory available.\n");
        return 1;
    }

    new_node -> prev = NULL;
    new_node -> data = data;
    unsigned int location = hashfunc (data, table -> size);
    
    if ((table -> table)[location] == NULL) {
        new_node -> next = NULL;
        (table -> table)[location] = new_node;
    }
    else {
        hash_node* temp = (table -> table)[location];
        for (; temp && compare ((temp -> data), data); temp = temp -> next);
        
        if (temp)
            return 1;
        else {
            new_node -> next = (table -> table)[location];
            (table -> table)[location] -> prev = new_node;
            (table -> table)[location] = new_node;
        }

    }
    return 0;
}
    
int hash_delete (hash_table* table, void* data,
                 HASHFUNC hashfunc, COMPARE compare) {

    unsigned int location = hashfunc (data, table -> size);

    hash_node* temp = (table -> table)[location];
    for (;temp && compare ((temp -> data), data); temp = temp -> next);
    
    if (temp == (table -> table)[location]) {
        if (temp -> next == NULL)
            (table -> table)[location] = NULL;
        else {
            temp -> next -> prev = NULL;
            (table -> table)[location] = temp -> next;
        }
    }
    else if (temp) {
        temp -> prev -> next = temp -> next;
        if (temp -> next)
            temp -> next -> prev = temp -> prev;
    }        
    else
        return 1;

    free (temp);
    return 0;
}
        
void hash_display (hash_table* table, DISPLAY display) {
    int i;
    hash_node* temp = NULL;
    for (i = 0; i < table -> size; i++) {
        printf ("%2d -- ", i);
        temp = (table -> table)[i];
        while (temp) {
            display (temp -> data);
            temp = temp -> next;
        }
        printf ("\n");
    }
    printf ("-- NULL -- \n");
}


    
