#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[100]; 

    fp = fopen("/Users/ankitalokhande/Desktop/1.txt", "r"); 
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {

        printf("%s", fgets(buffer, sizeof(buffer), fp) ? buffer : "");
    }

    fclose(fp);

    return 0;
}
