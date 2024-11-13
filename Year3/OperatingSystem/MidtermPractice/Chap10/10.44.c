#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PAGES 10      // Range of page numbers (0 to 9)
#define MAX_REFERENCES 20 // Length of the page reference string

// Function to generate a random page reference string
void generate_page_references(int *references, int length) {
  for (int i = 0; i < length; i++) {
    references[i] = rand() % MAX_PAGES;
  }
}

// FIFO Page Replacement Algorithm
int fifo(int *references, int num_pages, int num_frames) {
  int frame[num_frames];
  int page_faults = 0;
  int index = 0;
  int is_page_present;

  for (int i = 0; i < num_pages; i++) {
    is_page_present = 0;
    // Check if page is already in one of the frames
    for (int j = 0; j < num_frames; j++) {
      if (frame[j] == references[i]) {
        is_page_present = 1;
        break;
      }
    }

    // Page fault occurs
    if (!is_page_present) {
      frame[index] = references[i];
      index = (index + 1) % num_frames; // Circular increment
      page_faults++;
    }
  }
  return page_faults;
}

// LRU Page Replacement Algorithm
int lru(int *references, int num_pages, int num_frames) {
  int frame[num_frames];
  int page_faults = 0;
  int last_used[MAX_PAGES] = {0};

  for (int i = 0; i < num_pages; i++) {
    int is_page_present = 0;
    // Check if page is already in one of the frames
    for (int j = 0; j < num_frames; j++) {
      if (frame[j] == references[i]) {
        is_page_present = 1;
        last_used[j] = i; // Update last used index
        break;
      }
    }

    // Page fault occurs
    if (!is_page_present) {
      int lru_index = 0;
      for (int j = 1; j < num_frames; j++) {
        if (last_used[frame[lru_index]] < last_used[frame[j]]) {
          lru_index = j;
        }
      }
      frame[lru_index] = references[i];
      last_used[lru_index] = i; // Update last used index
      page_faults++;
    }
  }
  return page_faults;
}

// Optimal Page Replacement Algorithm
int optimal(int *references, int num_pages, int num_frames) {
  int frame[num_frames];
  int page_faults = 0;

  for (int i = 0; i < num_pages; i++) {
    int is_page_present = 0;
    // Check if page is already in one of the frames
    for (int j = 0; j < num_frames; j++) {
      if (frame[j] == references[i]) {
        is_page_present = 1;
        break;
      }
    }

    // Page fault occurs
    if (!is_page_present) {
      // Check if there is an empty frame
      int empty_index = -1;
      for (int j = 0; j < num_frames; j++) {
        if (frame[j] == -1) {
          empty_index = j;
          break;
        }
      }

      // Use the empty frame if available
      if (empty_index != -1) {
        frame[empty_index] = references[i];
        page_faults++;
      } else {
        // Replace the page that will not be used for the longest period
        int farthest_index = 0;
        for (int j = 0; j < num_frames; j++) {
          int next_use = -1;
          for (int k = i + 1; k < num_pages; k++) {
            if (frame[j] == references[k]) {
              next_use = k;
              break;
            }
          }
          if (next_use == -1) {
            farthest_index = j;
            break;
          } else if (next_use > i) {
            if (farthest_index == 0 || next_use > next_use) {
              farthest_index = j;
            }
          }
        }
        frame[farthest_index] = references[i];
        page_faults++;
      }
    }
  }
  return page_faults;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <number_of_frames>\n", argv[0]);
    return 1;
  }

  int num_frames = atoi(argv[1]);
  if (num_frames <= 0 || num_frames > MAX_PAGES) {
    printf("Number of frames must be between 1 and %d.\n", MAX_PAGES);
    return 1;
  }

  srand(time(NULL)); // Seed for random number generation

  // Generate random page reference string
  int references[MAX_REFERENCES];
  generate_page_references(references, MAX_REFERENCES);

  // Output generated page reference string
  printf("Generated page reference string: ");
  for (int i = 0; i < MAX_REFERENCES; i++) {
    printf("%d ", references[i]);
  }
  printf("\n");

  // Apply FIFO, LRU, and Optimal algorithms
  int fifo_faults = fifo(references, MAX_REFERENCES, num_frames);
  int lru_faults = lru(references, MAX_REFERENCES, num_frames);
  int optimal_faults = optimal(references, MAX_REFERENCES, num_frames);

  // Output the results
  printf("Page faults incurred:\n");
  printf("FIFO: %d\n", fifo_faults);
  printf("LRU: %d\n", lru_faults);
  printf("Optimal: %d\n", optimal_faults);

  return 0;
}
