#ifndef TREE_H
#define TREE_H

#include "DynamicList.h"
#include "../boolean.h"

typedef struct Tree {
    DynamicList adj[1000]; // Adjacency list. Root at 0
    boolean nodes[1000]; 
} Tree;

void create_tree(Tree *t);

void add_edge(Tree *t, int parent, int child);

void delete_node(Tree *t, int node);

void print_tree_from_any(Tree *t, int node, int space);

void print_tree(Tree *t);

#endif