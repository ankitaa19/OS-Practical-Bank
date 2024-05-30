#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file;
    char buffer[11];

    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    size_t bytesRead = fread(buffer, sizeof(char), 10, file);
    if (bytesRead < 10 && ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return EXIT_FAILURE;
    }

    buffer[bytesRead] = '\0';

    printf("First 10 bytes: %s\n", buffer);

    fclose(file);

    return EXIT_SUCCESS;
}
