#include "Tree.h"

#include <stdio.h>
#include "../boolean.h"

void create_tree(Tree *t) {
    for (int i = 0; i < 1000; ++i) {
        create_dynamic_list(&(t->adj[i]), 1);
    }
}

void add_edge(Tree *t, int parent, int child) {
    t->nodes[child] = true;
    insert_last_dynamic_list(&(t->adj[parent]), child);
    t->parent[child] = parent;
}

void delete_node(Tree *t, int node) {
    t->nodes[node] = false;
    for (int i = 0; i < t->adj[node].length; ++i) {
        delete_node(t, t->adj[node].list[i]);
    }
    erase_all_dynamic_list(&(t->adj[node]));
    
    int parent = t->parent[node];
    remove_by_value_dynamic_list(&(t->adj[parent]), node);
}

void print_tree_from_any(Tree *t, int node, int space) {
    for (int i = 0; i < space; ++i) printf("\t");
    printf("%d\n", node);

    for (int i = 0; i < t->adj[node].length; ++i) {
        print_tree_from_any(t, t->adj[node].list[i], space + 1);
    }
}

void print_tree(Tree *t) {
    print_tree_from_any(t, 0, 0);
}
