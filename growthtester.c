#include "types.h"
#include "user.h"

void recursive_function(int count) {
  if (count % 1000 == 0) {
    printf(1, "Stack depth: %d\n", count);
  }
  char buffer[4096];
  memset(buffer, 0, sizeof(buffer));
  recursive_function(count + 1);
}

int main() {
  printf(1, "Allocating memory on the heap...\n");
  char *heap_memory = (char *)malloc(4096 * 4096);
  if (heap_memory == 0) {
    printf(1, "Failed to allocate heap memory\n");
    exit();
  }
  printf(1, "Heap memory allocated at %p\n", heap_memory);

  printf(1, "Calling the recursive function to grow the stack...\n");
  recursive_function(0);

  free(heap_memory);
  exit();
}
