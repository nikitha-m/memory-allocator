#include<stdio.h> 
#include "../inc/allocator.h" 
#include <sys/mman.h>

void hello() {
  printf("Printing hello from my library");
}

void* malloc(int size) {
  return mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
}
