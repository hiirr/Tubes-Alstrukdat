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
