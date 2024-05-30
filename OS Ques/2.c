#include <stdio.h>
#include <stdlib.h>

int main() {
    // File pointer
    FILE *file;

    // Create and open the file in write mode
    file = fopen("/Users/ankitalokhande/Desktop/1.txt", "w");
    if (file == NULL) {
        perror("Error creating file");
        return EXIT_FAILURE;
    }

    // Write some content to the file
    const char *content = "This is a sample text file.";
    if (fprintf(file, "%s", content) < 0) {
        perror("Error writing to file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Close the file
    if (fclose(file) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    printf("File created, written to, and closed successfully.\n");

    // Open the file in read mode
    file = fopen("/Users/ankitalokhande/Desktop/1.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Close the file
    if (fclose(file) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    printf("File opened and closed successfully.\n");

    return EXIT_SUCCESS;
}
