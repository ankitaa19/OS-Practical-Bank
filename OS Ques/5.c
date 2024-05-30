#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("/Users/ankitalokhande/Desktop/1.txt", "w");
    if (fp != NULL) {
        fputs("Hello, World!", fp);
        fclose(fp);
        printf("Successfully wrote \"Hello, World!\" to new_file.txt.\n");
    } else {
        printf("Error opening file for writing.\n");
    }

    return 0;
}
