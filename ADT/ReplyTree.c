#include "ReplyTree.h"

#include "../assets/Tweet.h"

#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"

void create_reply_tree(ReplyTree *t) {
    for (int i = 0; i < 1000; ++i) {
        create_dynamic_list(&(t->adj[i]), 1);
    }
    for (int i = 0; i < 1000; ++i) {
        t->tweets[i].text = malloc(sizeof(char));
        t->tweets[i].datetime = malloc(sizeof(char));
    }
}

void add_reply_edge(ReplyTree *t, int parent, int child, Tweet child_tweet) {
    t->nodes[child] = true;
    insert_last_dynamic_list(&(t->adj[parent]), child);
    t->parent[child] = parent;
    t->tweets[child] = child_tweet;
}

void delete_reply_node(ReplyTree *t, int node) {
    t->nodes[node] = false;
    for (int i = 0; i < t->adj[node].length; ++i) {
        delete_reply_node(t, t->adj[node].list[i]);
    }
    erase_all_dynamic_list(&(t->adj[node]));
    
    int parent = t->parent[node];
    remove_by_value_dynamic_list(&(t->adj[parent]), node);

    free(t->tweets[node].text);
    free(t->tweets[node].datetime);
    t->tweets[node].text = malloc(sizeof(char));
    t->tweets[node].datetime = malloc(sizeof(char));
}

void print_reply_tree_from_any_node(ReplyTree *t, int node, int space) {
    // for (int i = 0; i < space; ++i) printf("\t");
    print_tweet(&t->tweets[node], space);

    for (int i = 0; i < t->adj[node].length; ++i) {
        print_reply_tree_from_any_node(t, t->adj[node].list[i], space + 1);
    }
}

void print_reply_tree(ReplyTree *t) {
    print_reply_tree_from_any_node(t, 0, 0);
}
