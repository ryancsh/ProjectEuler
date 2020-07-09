#include "stdio.h"

int printarr(int arr[]){
  printf("[ ");
  for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
    printf("%d ", arr[i]);
  }
  printf("]");
}

typedef struct Array{
  int *items;
  int maxSize;
  int currentSize;
};

struct Array* newArray(){
  return newArray(16);
}

struct Array* newArray(int capacity){
  struct Array* pt = (struct Array*) malloc(sizeof(struct Array));

  pt->maxSize = capacity;
  pt->currentSize = 0;
  pt->items = (int*)malloc(sizeof(int) * capacity);

  return pt;
}

int size(struct Array* pt){
  return pt->currentSize;
}

int isFull(struct Array* pt){
  return pt->currentSize >= pt->maxSize;
}

int get(struct Array* pt, int index){
  return pt->items[index];
}

void set(struct Array* pt, int index, int value){
  pt->items[index] = value;
}

int removeLast(struct Array* pt){
  pt->currentSize--;
  return get(pt, pt->currentSize);
}

void add(struct Array* pt, int value){
  if(isFull(pt)){
    pt->maxSize *= 2;
    pt->items = (int*)realloc(pt->items, pt->maxSize * sizeof(int));
  }
  pt->items[pt->currentSize] = value;
  pt->currentSize++;
}