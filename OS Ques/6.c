#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("/Users/ankitalokhande/Desktop/1.txt", "a");

    if (fp != NULL) {
     
        fputs("End of File\n", fp);
        fclose(fp);
        printf("Successfully appended \"End of File\" to existing_file.txt.\n");
    } else {
        perror("Error opening file for appending");
    }

    return 0;
}
