#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    // 1. Read mode (r) - Existing file, read-only
    printf("** Read Mode (r) **\n");
    fp = fopen("existing_file.txt", "r");
    if (fp != NULL) {
        printf("File opened successfully for reading.\n");
        while ((ch = fgetc(fp)) != EOF) {
            printf("%c", ch);
        }
        fclose(fp);
    } else {
        printf("Error opening file for reading.\n");
    }

    // 2. Write mode (w) - New file, create and write, existing file content overwritten
    printf("\n\n** Write Mode (w) **\n");
    fp = fopen("new_file.txt", "w");
    if (fp != NULL) {
        fputs("This is some new content written to the file.\n", fp);
        fclose(fp);
        printf("Successfully wrote content to new_file.txt.\n");
    } else {
        printf("Error opening file for writing.\n");
    }

    // 3. Append mode (a) - Existing file, append to the end
    printf("\n\n** Append Mode (a) **\n");
    fp = fopen("existing_file.txt", "a");
    if (fp != NULL) {
        fputs("This is appended content.\n", fp);
        fclose(fp);
        printf("Successfully appended content to existing_file.txt.\n");
    } else {
        printf("Error opening file for appending.\n");
    }

    // 4. Read and Write mode (r+) - Existing file, read and write (careful with seeking)
    printf("\n\n** Read and Write Mode (r+) **\n");
    fp = fopen("existing_file.txt", "r+");
    if (fp != NULL) {
        printf("File opened for reading and writing.\n");
        // Read existing content (example)
        while ((ch = fgetc(fp)) != EOF) {
            printf("%c", ch);
        }
        // Seek to beginning for potential overwrite (be cautious)
        fseek(fp, 0, SEEK_SET);
        fputs("This overwrites existing content (be careful with r+).\n", fp);
        fclose(fp);
    } else {
        printf("Error opening file for reading and writing.\n");
    }

    // 5. Append and Read mode (a+) - Existing file, append and read (careful with seeking)
    printf("\n\n** Append and Read Mode (a+) **\n");
    fp = fopen("existing_file.txt", "a+");
    if (fp != NULL) {
        printf("File opened for appending and reading.\n");
        // Append content (example)
        fputs(" This is further appended content.\n", fp);
        // Seek to beginning for potential reading (be cautious)
        fseek(fp, 0, SEEK_SET);
        printf("Reading appended content:\n");
        while ((ch = fgetc(fp)) != EOF) {
            printf("%c", ch);
        }
        fclose(fp);
    } else {
        printf("Error opening file for appending and reading.\n");
    }

    return 0;
}
