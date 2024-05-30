#include <stdio.h>

int main() {
    FILE *fp_source, *fp_dest;
    char ch;


    // Open source file in read mode
    fp_source = fopen("/Users/ankitalokhande/Desktop/1.txt", "r"); 
    if (fp_source == NULL) {
        perror("Error opening source file");
        return 1;
    }


    fp_dest = fopen("/Users/ankitalokhande/Desktop/newfile.txt", "w"); 
    if (fp_dest == NULL) {
        perror("Error opening destination file");
        fclose(fp_source); 
        return 1;
    }

    while ((ch = fgetc(fp_source)) != EOF) {
        fputc(ch, fp_dest);
    }

    fclose(fp_source);
    fclose(fp_dest);

    printf("Successfully copied contents of source file to destination file.\n");

    return 0;
}
