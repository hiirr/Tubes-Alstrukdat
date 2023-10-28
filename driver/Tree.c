#include "ADT/Tree.h"

int main() {
    Tree t;
    create_tree(&t);

    add_edge(&t, 0, 1);
    add_edge(&t, 0, 2);
    add_edge(&t, 0, 3);
        add_edge(&t, 3, 6);
        add_edge(&t, 3, 7);
        add_edge(&t, 3, 8);
    add_edge(&t, 0, 4);
    add_edge(&t, 0, 5);
        add_edge(&t, 5, 9);
        add_edge(&t, 5, 10);
            add_edge(&t, 10, 12);
            add_edge(&t, 10, 13);
        add_edge(&t, 5, 11);
    add_edge(&t, 0, 14);
    print_tree(&t);


}