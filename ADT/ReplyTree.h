#ifndef REPLY_TREE_H
#define REPLY_TREE_H

#include "DynamicList.h"
#include "boolean.h"
#include "../assets/Tweet.h"

#define REPLY_TREE_CAPACITY 1000

typedef struct ReplyTree {
    DynamicList adj[REPLY_TREE_CAPACITY]; // Adjacency list. Root at 0
    boolean nodes[REPLY_TREE_CAPACITY];
    int parent[REPLY_TREE_CAPACITY];
    Tweet tweets[REPLY_TREE_CAPACITY];
} ReplyTree;

void create_reply_tree(ReplyTree *t);

void add_reply_edge(ReplyTree *t, int parent, int child, Tweet child_tweet);

void delete_reply_node(ReplyTree *t, int node);

void print_reply_tree_from_any_node(ReplyTree *t, int node, int space);

void print_reply_tree(ReplyTree *t);

void deallocate_reply_tree(ReplyTree *t);

#endif