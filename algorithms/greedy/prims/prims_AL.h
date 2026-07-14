#ifndef PRIMS_H
#define PRIMS_H

#include "../../../data_structures/graph/adjacency_list.h"

#define MAX_VERTICES 5

// Returns total weight of the Minimum Spanning Tree
int prims_AL(int V, AdjList adj[]);

#endif // PRIMS_H
