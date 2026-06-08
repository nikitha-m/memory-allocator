void hello();

// This gives a pointer the the first block of memory allocated
void* malloc(int size);
/*
// This frees the memory that was allocated. 
// Identifier is the pointer that was given during malloc
void free(void *ptr);

// This also allocates memory. But, sets it to 0 which adds overhead.
// Apparently, there is some optimization now for this by modern OS for large requests 
// This prevents multiplication overhead unlike malloc
void* calloc(int size, int count);

// This just reallocates 
// You need to return a new pointer because sometimes the data might be moved to a new block 
// Your old data + some new memory that you requested for, interesting
void* realloc(void *ptr, int size);
*/





