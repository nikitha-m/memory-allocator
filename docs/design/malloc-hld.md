# HLD: Custom malloc Allocator

## 1. System Overview
I am building my own ```malloc```, ```free```, ```calloc``` and ```realloc```. ```malloc``` and ```calloc``` are used to allocate some bytes of memory. ```free``` is used to deallocate the memory that was previously allocated by ```malloc``` or ```calloc```. ```realloc``` is used to resize the previously allocated memory. 

## 2. Components
- User Code
    - This is where my code is used. 
    - The user gives the requirements to my code. 
    - My code gives back the pointer to the first memory code once its done. 
- My code: 
    - This has to talk to the OS and actually get the free memory or provide the user the memory if it doesnt have enough. 
    - It gets a page(4096 bytes) from the OS. Communication to be done via ```nmap```.
    - Fun fact: nmap will always give me multiples of 4096 bytes. I can request for whatever but I will get it in multiples of 4096 only. 
- OS:
    - This gets request via nmap for memory and it allocates the memory. Happens in the form of pages 
    - Then, my code, will manage this page that it got from the OS. 

## 3. Data Flow
   - What happens when user calls malloc(100)?
        - malloc is called in user code. The user code should call an API in my code. My code should check if I have enough memeory with me or should there be a nmap call to the OS requesting for more data. 
        - The memory management needs to be done, if I have enough. I Could give it the data, if not, I have to get more from the OS. 
        - So, once the memory allocation is done, ptr to the first memory block is returned. 
   - What happens when user calls free(ptr)?
   - What happens when the free list is empty?

The previous part explains I guess. Will add more later

## 4. Internal Data Structures
   High-level description (no struct syntax yet):
   - How blocks are organized
   - What metadata each block needs
   - How the free list works

## 5. Memory Layout Diagram
   ASCII art:
   How blocks sit in memory. Header vs payload.
   What the heap looks like after alloc/free.

## 6. Edge Cases & Error Handling
   What happens when:
   - mmap fails
   - User calls free(NULL)
   - User calls malloc(0)
   - No free block large enough exists

## 7. Trade-offs & Rationale
   Why did you make the choices you did?
   - Why first-fit? Why not best-fit?
   - Why mmap over sbrk?
   - Why an implicit free list vs an explicit one?
🚀 Your assignment
1. Create docs/designs/hld-malloc.md
2. Write Sections 1, 2, and 3 for now (Overview, Components, Data Flow)
3. Push to GitHub
4. Tell me it's ready for review
I will not write it for you. I will review what you wrote and tell you what you missed. You iterate.
Go. 🎯
▣  Pm · Big Pickle · 16.5s
how to copy your text? alloc, free, 
   (2-3 sentences: what is this, what does it do)

## 2. Components
   List every "thing" in the system. For each:
   - Name
   - Responsibility (one line)
   - What it needs from other components
   - What it provides to other components

## 3. Data Flow
   Step-by-step narrative of:
   - What happens when user calls malloc(100)?
   - What happens when user calls free(ptr)?
   - What happens when the free list is empty?

## 4. Internal Data Structures
   High-level description (no struct syntax yet):
   - How blocks are organized
   - What metadata each block needs
   - How the free list works

## 5. Memory Layout Diagram
   ASCII art:
   How blocks sit in memory. Header vs payload.
   What the heap looks like after alloc/free.

## 6. Edge Cases & Error Handling
   What happens when:
   - mmap fails
   - User calls free(NULL)
   - User calls malloc(0)
   - No free block large enough exists

## 7. Trade-offs & Rationale
   Why did you make the choices you did?
   - Why first-fit? Why not best-fit?
   - Why mmap over sbrk?
   - Why an implicit free list vs an explicit one?
🚀 Your assignment
1. Create docs/designs/hld-malloc.md
2. Write Sections 1, 2, and 3 for now (Overview, Components, Data Flow)
3. Push to GitHub
4. Tell me it's ready for review
I will not write it for you. I will review what you wrote and tell you what you missed. You iterate.
Go. 🎯
▣  Pm · Big Pickle · 16.5s
how to copy your text? 
