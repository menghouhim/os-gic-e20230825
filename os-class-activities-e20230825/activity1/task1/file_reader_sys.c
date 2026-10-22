#include <fcntl.h>
#include <unistd.h>
int main() {
    char buffer[256];
    int fd = open("output.txt", O_RDONLY);
    if (fd < 0) return 1;
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytesRead);
    }
    close(fd);
    return 0;
}
