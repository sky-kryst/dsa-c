#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdbool.h>

/* ---------- Min-heap of (weight, vertex) pairs ---------- */

typedef struct {
    int weight;
    int vertex;
} HeapNode;

typedef struct {
    HeapNode *data;
    int size;
    int capacity;
} MinHeap;

void heapInit(MinHeap *h, int capacity);
void heapFree(MinHeap *h);
void heapPush(MinHeap *h, HeapNode node);
HeapNode heapPop(MinHeap *h);
HeapNode createHeapNode(int weight, int vertex);
bool heapEmpty(MinHeap *h);

#endif // MINHEAP_H
