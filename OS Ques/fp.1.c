#include <stdio.h>
#include <sys/stat.h>

int main() {
    char filename[] = "/Users/ankitalokhande/Desktop/1.txt"; 
    mode_t new_permissions = 0755; 

   
    if (chmod(filename, new_permissions) == -1) {
        perror("chmod");
        return 1;
    }

    printf("File permissions for \"%s\" set to %o.\n", filename, new_permissions);

    return 0;
}
