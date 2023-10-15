#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq->size==0)return NULL;
    void *aTop = pq->heapArray[0].data;
    return aTop;}
void heap_push(Heap* pq, void* data, int priority){
  if(pq->size==pq->capac){
    pq->capac=pq->capac*2+1;
    pq->heapArray=(heapElem*)realloc(pq->heapArray,sizeof(heapElem)*pq->capac);}
  int nuevoD = pq->size;
  pq->heapArray[nuevoD].data=data;
  pq->heapArray[nuevoD].priority=priority;
  pq->size = pq->size+1;
  heapElem padre,aux;
  while(nuevoD!=0){
    padre=pq->heapArray[(nuevoD-1)/2];
    if(padre.priority<=pq->heapArray[nuevoD].priority)break;
    aux=padre;
    pq->heapArray[(nuevoD-1)]=pq->heapArray[nuevoD];
    pq->heapArray[nuevoD]=aux;
    nuevoD = (nuevoD-1)/2;
    
  }
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap * heap=(Heap*)malloc(sizeof(Heap));
  heap->capac=3;
  heap->size=0;
  heap->heapArray=(heapElem*)malloc(sizeof(heapElem)*heap->capac);

   return heap;
}
