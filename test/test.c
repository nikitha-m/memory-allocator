#include<stdio.h> 
#include "../inc/allocator.h" 

int main() {
  hello();  
  int *ptr = malloc(10);
  printf("%d", ptr);
  printf("called malloc");
}
