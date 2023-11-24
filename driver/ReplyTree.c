#include "../ADT/ReplyTree.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

int main() {
    ReplyTree myTree;
    Tweet tweet1, tweet2, tweet3;

    create_reply_tree(&myTree);
    assert(myTree.nodes[0] == true);

    tweet1 = new_tweet(1, strdup("First Tweet"), 123);
    tweet2 = new_tweet(2, strdup("Second Tweet"), 456);
    tweet3 = new_tweet(3, strdup("Third Tweet"), 789);

    add_reply_edge(&myTree, 0, 1, tweet1);
    assert(myTree.nodes[1] == true);
    assert(myTree.parent[1] == 0);

    add_reply_edge(&myTree, 1, 2, tweet2);
    assert(myTree.nodes[2] == true);
    assert(myTree.parent[2] == 1);

    add_reply_edge(&myTree, 2, 3, tweet3);
    assert(myTree.nodes[3] == true);
    assert(myTree.parent[3] == 2);

    delete_reply_node(&myTree, 2);
    assert(myTree.nodes[2] == false);
    assert(myTree.nodes[3] == false);

    // delete_tweet(&tweet1);
    // delete_tweet(&tweet2);
    // delete_tweet(&tweet3);

    printf("All tests passed successfully.\n");

    return 0;
}