#ifndef ADJLIST_H
#define ADJLIST_H

/* ---------- Adjacency list ---------- */

typedef struct {
    int to;
    int weight;
} Edge;

typedef struct {
    Edge *edges;
    int count;
    int capacity;
} AdjList;

void adjListInit(AdjList *list);
void adjListAdd(AdjList *list, int to, int weight);
void adjListFree(AdjList *list);

#endif // ADJLIST_H
