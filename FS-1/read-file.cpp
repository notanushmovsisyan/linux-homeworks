#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUFFER_SIZE 12
int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "File Path Not Given" << std::endl;
        exit(1);
    }

    char* path = argv[1];
    int fd = open(path, O_RDONLY);

    if (fd < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    char* buffer = new char[BUFFER_SIZE + 1];

    while (true) {
        int read_bytes = read(fd, buffer, BUFFER_SIZE);

        if (read_bytes < 0) {
            std::cerr << strerror(errno) << std::endl;
            exit(errno);
        }

        if (read_bytes == 0) 
            break;

        buffer[read_bytes] = '\0';
    }

    int closed_desc = close(fd);

    if (closed_desc < 0) {
        std::cerr << strerror(errno) << std::endl;
    }

    delete[] buffer;
    return 0;
}