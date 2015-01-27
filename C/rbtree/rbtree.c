#include <stdio.h>
#include <stdlib.h>

#include "rbtree.h"

void left_rotate (rb_tree* tree, rb_node* node) {
    rb_node* temp = node -> right;
    node -> right = temp -> left;

    if (temp -> left)
        temp -> left -> parent = node;

    temp -> parent = node -> parent;

    if (node -> parent == NULL)
        tree -> root = temp;
    else if (node == node -> parent -> left)
        node -> parent -> left = temp;
    else
        node -> parent -> right = temp;

    temp -> left = node;
    node -> parent = temp;
}

void right_rotate (rb_tree* tree, rb_node* node) {
    rb_node* temp = node -> left;
    node -> left = temp -> right;

    if (temp -> right)
        temp -> right -> parent = node;

    temp -> parent = node -> parent;

    if (node -> parent == NULL)
        tree -> root = temp;
    else if (node == node -> parent -> left)
        node -> parent -> left = temp;
    else
        node -> parent -> right = temp;

    temp -> right = node;
    node -> parent = temp;
}

rb_node* rb_find (rb_tree* tree, void* data, COMPARE compare) {
    rb_node* y = NULL;
    rb_node* x = tree -> root;

    while (x) {
        y = x;
        switch (compare (data, x -> data)) {
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

    rb_node* y = rb_find (tree, data, compare);
    if (!y)
        return 1;

    new_node -> data = data;
    new_node -> parent = y;
    if (y == NULL)
        tree -> root = new_node;
    else if (compare (data, y -> data) == 1)
        y -> left = new_node;
    else
        y -> right = new_node;

    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> color = 1;

    rb_insert_fix (tree, new_node);
    return 0;
}

void rb_insert_fix (rb_tree* tree, rb_node* node) {
    rb_node* temp = NULL;
    while (node -> parent -> color) {
        if (node -> parent = node -> parent -> parent -> left) {
            temp = node -> parent -> parent -> right;
            if (temp -> color) {
                node -> parent -> color = 0;
                temp -> color = 0;
                node -> parent -> parent -> color = 1;
                node = node -> parent -> parent;
            }
            else if (node = node -> parent -> right) {
                node = node -> parent;
                left_rotate (tree, node);
            }
            node -> parent -> color = 0;
            node -> parent -> parent -> color = 1;
            right_rotate (tree, node -> parent -> parent);
        }
        else {
            temp = node -> parent -> parent -> left;
            if (temp -> color) {
                node -> parent -> color = 0;
                temp -> color = 0;
                node -> parent -> parent -> color = 1;
                node = node -> parent -> parent;
            }
            else if (node = node -> parent -> left) {
                node = node -> parent;
                right_rotate (tree, node);
            }
            node -> parent -> color = 0;
            node -> parent -> parent -> color = 1;
            left_rotate (tree, node -> parent -> parent);
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
    y -> parent = x -> parent;
}

rb_node* rb_min (rb_tree* tree) {
    rb_node* min = tree -> root;
    while (min -> left)
        min = min -> left;
    return min;
}
    

int rb_delete (rb_tree* tree, void* data, COMPARE compare) {
    rb_node* temp = rb_find (tree, data, compare);
    if (!temp)
        return 1;

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
        y = rb_min (tree);
        col = y -> color;
        x = y -> right;

        if (y -> parent == temp)
            x -> parent = y;
        else {
            rb_transplant (tree, y, y -> right);
            y -> right = z -> right;
            y -> right -> parent = y;
        }

        y -> left = temp -> left;
        y -> left -> parent = y;
        y -> color = temp -> color;

    }

    if (!col)
        rb_delete_fix (tree, x);
    return 0;
}

void rb_delete_fix (rb_tree* tree, rb_node* node) {
    
            


            
    
