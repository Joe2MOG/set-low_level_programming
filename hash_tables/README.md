# Hash Tables in C

This project implements a hash table data structure in C using the djb2 hashing algorithm and chaining for collision resolution.

## Data Structures

```c
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
```
