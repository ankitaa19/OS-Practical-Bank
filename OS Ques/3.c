#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[11]; 
    int bytes_to_read, bytes_read;
    long offset;

    // Open the file in read mode
    fp = fopen("/Users/ankitalokhande/Desktop/1.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Get the file size
    if (fseek(fp, 0, SEEK_END) != 0) {
        perror("Error seeking file end");
        fclose(fp);
        return 1;
    }
    offset = ftell(fp);

    
    bytes_to_read = (offset < 10) ? offset : 10;

    
    if (fseek(fp, -bytes_to_read, SEEK_END) != 0) {
        perror("Error seeking to position");
        fclose(fp);
        return 1;
    }

    // Read the bytes into the buffer
    bytes_read = fread(buffer, 1, bytes_to_read, fp);
    if (bytes_read != bytes_to_read) {
        perror("Error reading bytes");
        fclose(fp);
        return 1;
    }

    buffer[bytes_to_read] = '\0';


    printf("Last %d bytes: %s\n", bytes_to_read, buffer);

    fclose(fp);

    return 0;
}
