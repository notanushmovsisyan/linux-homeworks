#include <iostream>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <unistd.h>

int main(int argc, char** argv) {
  if (argc < 3) {
    std::cerr << "Path was not given" << std::endl;
    exit(0);
  }
  char* source_path = argv[1];
  char* destination_path = argv[2];

  int source_fd = open(source_path, O_RDONLY);

  if (source_fd < 0) {
    std::cerr << strerror(errno) << std::endl;
    exit(errno);
  }

  int destination_fd = open(destination_path, O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);

  if (destination_fd < 0) {
    std::cerr << strerror(errno) << std::endl;
    exit(errno);
  }

  int file_size = lseek(source_fd, 0, SEEK_END);

  if(file_size < 0) {
    std::cerr << strerror(errno) << std::endl;
    exit(errno);
  }

  char* buffer = new char[file_size];
  int copied_bytes, data_bytes, hole_bytes, read_bytes, written_bytes;

  while ((read_bytes = read(source_fd, buffer, file_size)) > 0) {
    for (int i = 0; i < file_size; i++) {
      copied_bytes++;
      if (buffer[i] != '\0') {
        written_bytes = write(destination_fd, &buffer[i], 1);
        if (written_bytes < 0) { 
          std::cerr << strerror(errno) << std::endl;
          exit(errno);
        }
        data_bytes++;
      } else {
        hole_bytes++;
      }
    }
  }

  if (read_bytes < 0) {
    std::cerr << strerror(errno) << std::endl;
  }

  int closed_source = close(source_fd);
  if (closed_source < 0) {
    std::cerr << strerror(errno) << std::endl;
    exit(errno);
  }

  int closed_destination = close(destination_fd);
  if (closed_destination < 0) {
    std::cerr << strerror(errno) << std::endl;
    exit(errno);
  }

  std::cout << "Successfully copied " << copied_bytes << 
    " bytes (data: " << data_bytes << ", hole: " 
    << hole_bytes << ")." << std::endl;

  return 0;
}