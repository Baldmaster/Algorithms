/************************************************************
   Red-Black tree.


   Skupoy Sergey. sergey.archlinux@gmail.com, 2015
 ************************************************************/

#findef RBTREE_H
#define RBTREE_H

typedef int (*COMPARE) (void*, void*);


typedef struct _rb_node {
    char* color;
    void* data;
    struct _rb_node* parent;
    struct _rb_node* left;
    struct _rb_node* right;
} rb_node;


int rb_insert (rb_node** root, void* data, COMPARE compare);

void left_rotate (rb_node** tree);
void right_rotate (rb_node** tree);

int rb_insert_fix (rb_node** tree, COMPARE compare);

void rb_transplant (rb_node** x, rb_node** y);

int rb_delete (rb_node** node);
int rb_delete_fix (rb
    
    




#endif
