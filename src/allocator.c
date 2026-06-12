#include <stddef.h>
#include<stdio.h> 
#include "../inc/allocator.h" 
#include <sys/mman.h>
#include<stdlib.h>

#define HEADER_SIZE 16
#define MAX_ENTRIES 64

int headerCount = 0; 
int pageCount = 0;

struct header {
  int offset; 
  int size; 
};

struct pages {
  struct header headers[HEADER_SIZE];
  void* addr; 
};

struct pages pages[MAX_ENTRIES];

void hello() {
  printf("Printing hello from my library");
}

int cmp(const void *a, const void *b) {
  struct header *ha = (struct header *)a;
  struct header *hb = (struct header *)b;
  return ha->offset - hb->offset;
}

void* cus_malloc(int size) {
  qsort(pages[pageCount].headers, HEADER_SIZE, sizeof(struct header), cmp());
  for(int i = 0; i < pageCount; i++) {
    for(int j = 0; j < headerCount; j++) {
      if(pages[i].headers[j].size >= size) {
        
      }
    }
  }
  return mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
}
