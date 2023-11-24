#include "dsu.h"

void initialize_dsu(DSU *dsu) {
    for (int i = 0; i < MAX_USERS; i++) {
        dsu->parent[i] = i; 
        dsu->rank[i] = 0; 
    }
}

int find(DSU *dsu, int x) {
    if (dsu->parent[x] != x) {
        dsu->parent[x] = find(dsu, dsu->parent[x]);
    }
    return dsu->parent[x];
}

void unite(DSU *dsu, int id1, int id2) {
    int root_1 = find(dsu, id1);
    int root_2 = find(dsu, id2);

    if (root_1 != root_2) {
        if (dsu->rank[root_1] < dsu->rank[root_2]) {
            dsu->parent[root_1] = root_2;
        } else if (dsu->rank[root_1] > dsu->rank[root_2]) {
            dsu->parent[root_2] = root_1;
        } else {
            dsu->parent[root_2] = root_1;
            dsu->rank[root_1]++;
        }
    }
}

void form_friend_circles(GraphMatrix *m, DSU *dsu) {
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < m->col; j++) {
            if (m->matrix[i][j] == 1) {
                unite(dsu, i, j);
            }
        }
    }
}