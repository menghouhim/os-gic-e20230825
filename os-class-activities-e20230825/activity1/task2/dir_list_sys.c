#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h> 

int main() {
    char buffer[512];
    DIR *dir = opendir(".");
    if (dir == NULL) return 1;
    
    struct dirent *entry;
    struct stat fileStat;

    // Header
    int len = snprintf(buffer, sizeof(buffer), "%-30s %10s\n", "Filename", "Size (bytes)");
    write(1, buffer, len);
    len = snprintf(buffer, sizeof(buffer), "%-30s %10s\n", "------------------------------", "----------");
    write(1, buffer, len);

    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &fileStat) == 0) {
            // Format string using snprintf, then write to screen
            len = snprintf(buffer, sizeof(buffer), "%-30s %10ld\n", entry->d_name, (long)fileStat.st_size);
            write(1, buffer, len);
        }
    }
    closedir(dir);
    return 0;
}
