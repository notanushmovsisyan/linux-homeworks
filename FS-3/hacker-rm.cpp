#include <iostream>
#include <fcntl.h>
#include <sys/errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 16
int main(int argc, char** argv) {

    if (argc < 2) {
        std::cerr << "File path is not given" << std::endl;
        exit(1);
    }

    char* path = argv[1];
    int fd = open(path, O_WRONLY);

    if (fd < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    char* buffer = new char[BUFFER_SIZE];
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = '\0';
    }

    while(true) {
        int written_bytes = write(fd, buffer, BUFFER_SIZE);

        if (written_bytes < 0) {
            std::cerr << strerror(errno) << std::endl;
            exit(errno);
        }

        if(written_bytes == 0) {
            break;
        }
    }

    int removed_file = unlink(path);

    if (removed_file < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    return 0;
}