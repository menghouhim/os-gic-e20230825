#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const int SIZE = 4096;
    const char *name = "OS-menghou";
    int shm_fd;
    void *ptr;

    shm_fd = shm_open(name, O_RDONLY, 0666);
    if (shm_fd == -1) { perror("shm_open"); exit(EXIT_FAILURE); }
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) { perror("mmap"); exit(EXIT_FAILURE); }

    printf("Consumer: message = \"%s\"\n", (char *)ptr);
    shm_unlink(name);
    return 0;
}
