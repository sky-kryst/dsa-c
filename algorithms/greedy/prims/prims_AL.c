#include "prims_AL.h"
#include "../../../data_structures/heap/min_heap.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Returns total weight of the Minimum Spanning Tree
int prims_AL(int V, AdjList adj[]) {
  assert(V <= MAX_VERTICES && "spanningTree: V exceeds fixed array capacity");

  MinHeap pq;
  heapInit(&pq, MAX_VERTICES);

  bool visited[MAX_VERTICES];
  // initialize all vertices as not visited - O(v)
  for (int i = 0; i < V; i++) {
    visited[i] = false;
  }

  int final_weight = 0;

  // Start from node 0
  heapPush(&pq, createHeapNode(0, 0)); // {weight, vertex}

  while (!heapEmpty(&pq)) {
    HeapNode p = heapPop(&pq);

    int wt = p.weight;
    int u = p.vertex;

    if (visited[u]) {
      continue;
    }

    final_weight += wt;
    visited[u] = true;

    // Traverse all adjacent edges and vertices - O(v + e)
    for (int i = 0; i < adj[u].count; i++) {
      Edge e = adj[u].edges[i];
      if (!visited[e.to]) {
        // Push adjacent edges - O(log(v))
        heapPush(&pq, createHeapNode(e.weight, e.to));
      }
    }
  }

  return final_weight;
}

int main(void) {
  int V = 3;
  AdjList
      adj[MAX_VERTICES]; // fixed-size array, up to MAX_VERTICES (5) vertices

  for (int i = 0; i < V; i++)
    adjListInit(&adj[i]);

  adjListAdd(&adj[0], 1, 5);
  adjListAdd(&adj[1], 0, 5);

  adjListAdd(&adj[1], 2, 3);
  adjListAdd(&adj[2], 1, 3);

  adjListAdd(&adj[0], 2, 1);
  adjListAdd(&adj[2], 0, 1);

  printf("%d\n", prims_AL(V, adj));

  return 0;
}
