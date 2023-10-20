#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUFFER_SIZE 10
int main(int argc, char** argv) {
    if(argc < 3) {
        std::cerr << "File Path is not given" << std::endl;
        exit(1);
    }

    char* source_file = argv[1];
    char* destination_file = argv[2];

    int source_fd = open(source_file, O_RDONLY);
    
    if (source_fd < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    int destination_fd = open(destination_file, O_WRONLY | O_CREAT, S_IWUSR| S_IRUSR | S_IRGRP | S_IROTH);

    if (destination_fd < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    char* buffer = new char[BUFFER_SIZE + 1];

    while(true) {
        int read_bytes = read(source_fd, buffer, BUFFER_SIZE);

        if (read_bytes < 0) {
            std::cerr << strerror(errno) << std::endl;
            exit(errno);
        }

        if(read_bytes = 0) 
            break;

        int written_bytes = read (destination_fd, buffer, BUFFER_SIZE);

        if (written_bytes < 0) {
            std::cerr << strerror(errno) << std::endl;
            exit(errno);
        }


    }
    return 0;
}