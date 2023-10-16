#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
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
    if(padre.priority>pq->heapArray[nuevoD].priority)break;
    aux=padre;
    pq->heapArray[(nuevoD-1)/2]=pq->heapArray[nuevoD];
    pq->heapArray[nuevoD]=aux;
    nuevoD = (nuevoD-1)/2;
    
  }
}


void heap_pop(Heap* pq){
  pq->heapArray[0]=pq->heapArray[pq->size-1];
  pq->size=pq->size-1;

  int aux=0;
  int hijoI , hijoD,padre;
  while(true){
    hijoI=2*aux+1;
    hijoD=2*aux+1;
    if(hijoI< pq->size && pq->heapArray[hijoI].priority > pq->heapArray[aux].priority)padre=hijoI;
    else padre=aux;

    if(hijoD< pq->size && pq->heapArray[hijoD].priority > pq->heapArray[padre].priority)padre=hijoD;

    if(aux==padre)break;

    heapElem nuevo=pq->heapArray[aux];
    pq->heapArray[aux]=pq->heapArray[padre];
    pq->heapArray[padre]=nuevo;
    aux=padre;
  }

}

Heap* createHeap(){
  Heap * heap=(Heap*)malloc(sizeof(Heap));
  heap->capac=3;
  heap->size=0;
  heap->heapArray=(heapElem*)malloc(sizeof(heapElem)*heap->capac);

   return heap;
}
