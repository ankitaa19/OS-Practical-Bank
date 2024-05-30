#include <stdio.h>
#include <sys/stat.h>

int main() {
    char filename[] = "/Users/ankitalokhande/Desktop/1.txt"; // Replace with your filename
    struct stat file_info;

    // Attempt to get file status using stat
    if (stat(filename, &file_info) == -1) {
        perror("stat");
        return 1;
    }

    // Print some basic file information
    printf("File: %s\n", filename);
    printf("File size: %ld bytes\n", file_info.st_size);
    printf("File permissions: %o\n", (int)file_info.st_mode);

    return 0;
}
