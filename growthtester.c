#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4096

int main() {
    char stack_var;
    char* stack_ptr = &stack_var;
    char* heap_ptr = malloc(1);

    printf("Stack pointer before growth: %p\n", stack_ptr);

    while (stack_ptr > heap_ptr) {
        *stack_ptr = 0;
        stack_ptr -= PAGE_SIZE;
    }

    printf("Stack pointer after growth: %p\n", stack_ptr);

    free(heap_ptr);

    return 0;
}


// #include "types.h"
// #include "user.h"

// void recursive_function(int count) {
//   if (count % 1000 == 0) {
//     printf(1, "Stack depth: %d\n", count);
//   }
//   char buffer[1024];
//   memset(buffer, 0, sizeof(buffer));
//   recursive_function(count + 1);
// }

// int main() {
//   printf(1, "Allocating memory on the heap...\n");
//   char *heap_memory = (char *)malloc(1024 * 1024);
//   if (heap_memory == 0) {
//     printf(1, "Failed to allocate heap memory\n");
//     exit();
//   }
//   printf(1, "Heap memory allocated at %p\n", heap_memory);

//   printf(1, "Calling the recursive function to grow the stack...\n");
//   recursive_function(0);

//   free(heap_memory);
//   exit();
// }
