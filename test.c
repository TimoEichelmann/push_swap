#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_elements = 500; // Change this to the number of unique random integers you want
    int min_value = 1;      // Minimum value of the random integers
    int max_value = 1000;   // Maximum value of the random integers

    if (num_elements > (max_value - min_value + 1)) {
        printf("Error: The range of possible unique values is smaller than the requested number of elements.\n");
        return 1;
    }

    int *unique_randoms = (int *)malloc(num_elements * sizeof(int));

    if (unique_randoms == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Seed the random number generator with the current time
    srand(time(NULL));

    for (int i = 0; i < num_elements; i++) {
        // Generate a random number within the specified range
        int random_num = rand() % (max_value - min_value + 1) + min_value;

        // Check if the number is already in the array
        int is_duplicate = 0;
        for (int j = 0; j < i; j++) {
            if (unique_randoms[j] == random_num) {
                is_duplicate = 1;
                break;
            }
        }

        // If it's a duplicate, generate a new random number
        if (is_duplicate) {
            i--;
        } else {
            unique_randoms[i] = random_num;
        }
    }

    // Print the unique random integers
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", unique_randoms[i]);
    }

    // Free allocated memory
    free(unique_randoms);

    return 0;
}
