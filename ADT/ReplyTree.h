#ifndef REPLY_TREE_H
#define REPLY_TREE_H

#include "DynamicList.h"
#include "boolean.h"
#include "../assets/Tweet.h"

typedef struct ReplyTree {
    DynamicList adj[1000]; // Adjacency list. Root at 0
    boolean nodes[1000];
    int parent[1000];
    Tweet tweets[1000];
} ReplyTree;

void create_reply_tree(ReplyTree *t);

void add_reply_edge(ReplyTree *t, int parent, int child, Tweet child_tweet);

void delete_reply_node(ReplyTree *t, int node);

void print_reply_tree_from_any_node(ReplyTree *t, int node, int space);

void print_reply_tree(ReplyTree *t);

#endif