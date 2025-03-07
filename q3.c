#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    printf("Demo of dup()\n");

    int f1, f2;
    f1 = open("Output.dat", O_CREAT | O_WRONLY, 0644);
    if (f1 == -1) {
        perror("Error opening file");
        return 1;
    }

    close(1);  // Close stdout (file descriptor 1)
    f2 = dup(f1);  // Duplicate f1 to lowest available FD (which is 1 now)

    printf("Redirection\n"); // This now writes to Output.dat

    close(f1);
    return 0;
}
