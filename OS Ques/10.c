#include <stdio.h>

int main() {
    const char *filename = "/Users/ankitalokhande/Desktop/1.txt";
    FILE *file = fopen(filename, "r");

    if (file) {
        printf("File exists and opened successfully.\n");
        fclose(file);
    } else {
        printf("File does not exist.\n");
    }

    return 0;
}