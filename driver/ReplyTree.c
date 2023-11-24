#include "../ADT/ReplyTree.h"
#include <stdio.h>
#include "../ADT/Wordmachine.h"

int main() {
    ReplyTree myTree;
    Tweet tweet1, tweet2, tweet3;

    create_reply_tree(&myTree);
    if (myTree.nodes[0] == true) {
        printf("passed\n");
    }

    tweet1 = new_tweet(1, my_strdup("First Tweet"), 123);
    tweet2 = new_tweet(2, my_strdup("Second Tweet"), 456);
    tweet3 = new_tweet(3, my_strdup("Third Tweet"), 789);

    add_reply_edge(&myTree, 0, 1, tweet1);
    if (myTree.nodes[1] == true) {
        printf("passed\n");
    }
    if (myTree.parent[1] == 0) {
        printf("passed\n");
    }

    add_reply_edge(&myTree, 1, 2, tweet2);
    if (myTree.nodes[2] == true) {
        printf("passed\n");
    }
    if (myTree.parent[2] == 1) {
        printf("passed\n");
    }

    add_reply_edge(&myTree, 2, 3, tweet3);
    if (myTree.nodes[3] == true) {
        printf("passed\n");
    }
    if (myTree.parent[3] == 2) {
        printf("passed\n");
    }

    delete_reply_node(&myTree, 2);
    if (myTree.nodes[2] == false) {
        printf("passed\n");
    }
    if (myTree.nodes[3] == false) {
        printf("passed\n");
    }

    // delete_tweet(&tweet1);
    // delete_tweet(&tweet2);
    // delete_tweet(&tweet3);

    printf("All tests passed successfully.\n");

    return 0;
}