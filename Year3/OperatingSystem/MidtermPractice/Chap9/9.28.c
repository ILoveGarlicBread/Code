#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4096 // 4 KB page size

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <virtual_address>\n", argv[0]);
    return 1;
  }

  // Parse the input virtual address as an unsigned long
  unsigned long virtual_address = strtoul(argv[1], NULL, 10);

  // Calculate page number and offset
  unsigned long page_number = virtual_address / PAGE_SIZE;
  unsigned long offset = virtual_address % PAGE_SIZE;

  // Output the results
  printf("The address %lu contains:\n", virtual_address);
  printf("page number = %lu\n", page_number);
  printf("offset = %lu\n", offset);

  return 0;
}
