#include "adjacency_list.h"
#include <stdlib.h>

void adjListInit(AdjList *list) {
  list->edges = NULL;
  list->count = 0;
  list->capacity = 0;
}

void adjListAdd(AdjList *list, int to, int weight) {
  if (list->count == list->capacity) {
    list->capacity = (list->capacity == 0) ? 4 : list->capacity * 2;
    list->edges = realloc(list->edges, list->capacity * sizeof(Edge));
  }
  list->edges[list->count].to = to;
  list->edges[list->count].weight = weight;
  list->count++;
}

void adjListFree(AdjList *list) { free(list->edges); }
