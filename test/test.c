#include<stdio.h> 
#include "../inc/allocator.h" 

int main() {
  hello();  
  int *ptr = malloc(10);
  int *ptr2 = malloc(20);
  printf("\n%d", ptr);
  printf("\ncalled malloc");
}
