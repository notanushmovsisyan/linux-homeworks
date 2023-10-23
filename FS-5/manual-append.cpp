#include <iostream>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 11
int main(int argc, char** argv) {

    if (argc < 2) {
        std::cerr << "File Path Not Given" << std::endl;
        exit(1);
    }

    char* path = argv[1];
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    char buffer1[11] = {'f', 'i', 'r', 's', 't', ' ', 'l', 'i', 'n', 'e', '\0'};
    char buffer2[10] = {'l', 'a', 's', 't', ' ', 'l', 'i', 'n', 'e', '\0'};

    int duplicate = dup(fd);

    if (duplicate < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    while(true) {
        int written_bytes_1 = write(fd, buffer1, BUFFER_SIZE);

        if (written_bytes_1 < 0) {
            std::cerr << strerror(errno) << std::endl;
            exit(errno);
        }

        int written_bytes_2 = write(fd, buffer2, BUFFER_SIZE);

        if (written_bytes_2 < 0) {
            std::cerr << strerror(errno) << std::endl;
            exit(errno);
        }

        if (written_bytes_1 == 0 || written_bytes_2 == 0) 
            break;

    }

    int closed_desc = close(fd);

    if (closed_desc < 0) {
        std::cerr << strerror(errno) << std::endl;
    }

    return 0;
}