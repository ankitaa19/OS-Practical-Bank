#include <stdio.h>

int main() {
    FILE *fp;
    char ch;
    int line_count = 0;

    fp = fopen("/Users/ankitalokhande/Desktop/1.txt", "r"); 
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            line_count++;
        }
    }


    fclose(fp);

    printf("The file has %d lines.\n", line_count);

    return 0;
}
