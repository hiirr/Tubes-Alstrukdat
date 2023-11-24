#include <stdio.h>
#include <stdlib.h>
#include "GraphMatrix.h"

#define MAX_USERS 20

typedef struct DSU {
    int parent[MAX_USERS];
    int rank[MAX_USERS];
} DSU;

void initialize_dsu(DSU *dsu);

int find(DSU *dsu, int x);

void unite(DSU *dsu, int x, int y);

void form_friend_circles(GraphMatrix *m, DSU *dsu);