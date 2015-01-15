/************************************************************
  Hashing with chaining.


  Skupoy Sergey. sergey.archlinux@gmail.com, 2015
 ************************************************************/

#ifndef CHAINHASH_H
#define CHAINHASH_H

/************************************************************
   Function pointers to hash, compare and show functions
   all of them must be implemented separately according to 
   certain datatype.
 ************************************************************/
typedef unsigned int (*HASHFUNC) (void*, unsigned int); 
typedef int (*COMPARE) (const void*, const void*);
typedef void (*DISPLAY) (const void*);

/************************************************************
   Hash node structure
 ************************************************************/
typedef struct _hash_node {
    void* data;
    struct _hash_node* next;
    struct _hash_node* prev;
} hash_node;

/************************************************************
   Hash table structure
 ************************************************************/
typedef struct _hash_table {
    hash_node** table;
    unsigned int size;
} hash_table;

/************************************************************
   Insert function.
   Return values:
   0 - success,
   1 - no memory,
   2 - node with such data is present in table.
 ************************************************************/
int hash_insert (hash_table* table, void* data, HASHFUNC hashfunc, COMPARE compare); 

/************************************************************
   Delete function.
   Return values:
   0 - success,
   1 - no such data.
 ************************************************************/
int hash_delete (hash_table* table, void* data, HASHFUNC hashfunc, COMPARE compare);

/************************************************************
   Search function.
 ************************************************************/
int hash_search (hash_table* table, void* data, HASHFUNC hashfunc, COMPARE compare);

/************************************************************
   Init hashtable.
 ************************************************************/
int hash_init (hash_table* table, unsigned int size);

/************************************************************
   Display hash
 ************************************************************/
void hash_display (hash_table* table, DISPLAY display);

#endif
