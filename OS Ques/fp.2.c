#include <stdio.h>
#include <unistd.h>

int main() {
    char filename[] = "/Users/ankitalokhande/Desktop/1.txt"; 
    uid_t new_owner = 1000; 
    gid_t new_group = 1000;
  
  
    if (chown(filename, new_owner, new_group) == -1) {
        perror("chown");
        return 1;
    }

    printf("Owner and group of \"%s\" changed.\n", filename);

    return 0;
}
