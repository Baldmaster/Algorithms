#include <stdio.h>
#include <stdlib.h>

#include "rbtree.h"

void left_rotate (rb_tree* tree, rb_node* x) {
    rb_node* y = x -> right;
    x -> right = y -> left;

    if (y -> left)
        y -> left -> parent = x;

    y -> parent = x -> parent;

    if (x -> parent == NULL) {
        tree -> root = y;
    }
    else if (x == x -> parent -> left)
        x -> parent -> left = y;
    else
        x -> parent -> right = y;

    y -> left = x;
    x -> parent = y;
}

void right_rotate (rb_tree* tree, rb_node* x) {
    rb_node* y = x -> left;
    x -> left = y -> right;

    if (y -> right)
        y -> right -> parent = x;

    y -> parent = x -> parent;

    if (x -> parent == NULL)
        tree -> root = y;
    else if (x == x -> parent -> right)
        x -> parent -> right = y;
    else
        x -> parent -> left = y;

    y -> right = x;
    x -> parent = y;
}

rb_node* rb_find (rb_tree* tree, void* data, COMPARE compare) {
    rb_node* y = NULL;
    rb_node* x = tree -> root;
    while (x) {
        y = x;
        switch (compare (x -> data, data)) {
            case 1:
                x = x -> left;
                break;
            case 2:
                x = x -> right;
                break;
            default:
                return NULL;
        }
    }
    
    return y;
}

    

int rb_insert (rb_tree* tree, void* data, COMPARE compare) {
    rb_node* new_node = (rb_node*) malloc (sizeof (rb_node));
    
    if (!new_node) {
        printf ("No memory available!\n");
        return 1;
    }
    
    new_node -> parent = NULL;
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> color = 1;
    
    if (tree -> root == NULL) {
        new_node -> color = 0;
        tree -> root = new_node;
    }
    
    else {
        rb_node* y = rb_find (tree, data, compare);
        
        if (y == NULL) {
            free (new_node);
            return 1;
        }
        
        new_node -> parent = y;
        
        if (compare (y -> data, data) == 1)
            y -> left = new_node;
        else
            y -> right = new_node;

        rb_insert_fix (tree, new_node);
    }
    
    return 0;
}

void rb_insert_fix (rb_tree* tree, rb_node* node) {
    rb_node* z = node;
    rb_node* y = NULL;
    while (z != (tree -> root) && (z -> parent -> color)) {
        if (z -> parent == z -> parent -> parent -> left) {
            y = z -> parent -> parent -> right;
            if (y && y -> color) {
                z -> parent -> color = 0;
                y -> color = 0;
                z -> parent -> parent -> color = 1;
                z = z -> parent -> parent;
            }
            else {
                if (z == z -> parent -> right) {
                    z = z -> parent;
                    left_rotate (tree, z);
                }
                z -> parent -> color = 0;
                z -> parent -> parent -> color = 1;
                right_rotate (tree, z -> parent -> parent);
            }
        }
        else {
            y = z -> parent -> parent -> left;
            if (y && y -> color) {
                z -> parent -> color = 0;
                y -> color = 0;
                z -> parent -> parent -> color = 1;
                z = z -> parent -> parent;
            }
            else {
                if (z == z -> parent -> left) {
                    z = z -> parent;
                    right_rotate (tree, z);
                }
                z -> parent -> color = 0;
                z -> parent -> parent -> color = 1;
                left_rotate (tree, z -> parent -> parent);
            }
        }
    }

    tree -> root -> color = 0;
}

void rb_transplant (rb_tree* tree, rb_node* x, rb_node* y) {

    if (x -> parent == NULL)
        tree -> root = y;

    else if (x == x -> parent -> left)
        x -> parent -> left = y;
    else
        x -> parent -> right = y;

    if (y)
        y -> parent = x -> parent;
}

rb_node* rb_min (rb_node* tree) {
    rb_node* min = tree;
    while (min -> left)
        min = min -> left;
    return min;
}
    

int rb_delete (rb_tree* tree, void* data, COMPARE compare) {
    rb_node* temp = tree -> root;
    int i;
    while ((i = compare (temp -> data, data))) {
        if (i == 1)
            temp = temp -> left;
        else
            temp = temp -> right;
    }
    
    rb_node* y = temp;
    rb_node* x = NULL;
    int col = y -> color;

    if (temp -> left == NULL) {
        x = temp -> right;
        rb_transplant (tree, temp, temp -> right);
    }
    else if (temp -> right == NULL) {
        x = temp -> left;
        rb_transplant (tree, temp, temp -> left);
    }
    else {
        y = rb_min (temp -> right);
        col = y -> color;
        x = y -> right;

        if (y -> parent == temp) {
            if (x)
                x -> parent = y;
        }
        else {
            rb_transplant (tree, y, y -> right);
            y -> right = temp -> right;
            y -> right -> parent = y;
        }
        rb_transplant (tree, temp, y);
        y -> left = temp -> left;
        y -> left -> parent = y;
        y -> color = temp -> color;

    }

    if (col == 0 && x)
        rb_delete_fix (tree, x);

    free (temp);
    return 0;
}

void rb_delete_fix (rb_tree* tree, rb_node* node) {
    rb_node* x = node;
    rb_node* w = NULL;
    while ((x != (tree -> root)) && ((x -> color) == 0)) {
        if (x == x -> parent -> left) {
            w = x -> parent -> right;
            if (w && w -> color) {
                w -> color = 0;
                x -> parent -> color = 1;
                left_rotate (tree, x -> parent);
                w = x -> parent -> right;
            }
            if ((w -> left == NULL || w -> left -> color == 0 ) &&
                (w -> right == NULL || w -> right -> color == 0 )) {
                w -> color = 1;
                x = x -> parent;
            }
            else {
                if ((w -> right -> color == 0) || ( w -> right == NULL)) {
                    if (w -> left)
                        w -> left -> color = 0;
                    w -> color = 1;
                    right_rotate (tree, x -> parent);
                    w = x -> parent -> right;
                }

                w -> color = x -> parent -> color;
                x -> parent -> color = 0;
                if (w -> right)
                    w -> right -> color = 0;
                left_rotate (tree, x -> parent);
                x = tree -> root;
            }
        }
        else {
            w = x -> parent -> left;
            
            if (w && w -> color) {
                w -> color = 0;
                x -> parent -> color = 1;
                right_rotate (tree, x -> parent);
                w = x -> parent -> left;
            }
            
            if ((w -> right == NULL || w -> right -> color == 0) &&
                (w -> left == NULL || w -> right -> color == 0)) {
                w -> color = 1;
                x = x -> parent;
            }
            else {
                if (w -> left -> color == 0) {
                    if (w -> right)
                        w -> right -> color = 0;
                    w -> color = 1;
                    left_rotate (tree, x -> parent);
                    w = x -> parent -> left;
                }

                w -> color = x -> parent -> color;
                x -> parent -> color = 0;
                if (w -> left)
                    w -> left -> color = 0;
                right_rotate (tree, x -> parent);
                x = tree -> root;
            }
        }
    }
    if (x)
    x -> color = 0;
}
            
void rb_inorder (rb_node* root, DISPLAY display) {
    if (root != NULL) {
	rb_inorder (root -> left, display);
	display (root -> data);
	rb_inorder (root -> right, display);
    }
}
            


            
    
