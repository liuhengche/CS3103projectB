#include "kernel/types.h"

struct fs_dirent *create_file_at_path(char* full_path);
struct named_pipe *named_pipe_create(char *fname);
struct named_pipe *named_pipe_open(char *fname);
struct fs_dirent *rootDir();

// // kernel/named_pipe.h

// #ifndef NAMED_PIPE_H
// #define NAMED_PIPE_H

// #include <kernel/fs.h> // Include necessary file system headers

// // Define the maximum size of the named pipe buffer
// #define NAMED_PIPE_BUFFER_SIZE 1024

// // Named pipe structure
// struct named_pipe {
//     struct file *file; // File associated with the named pipe
//     char buffer[NAMED_PIPE_BUFFER_SIZE]; // Buffer for data storage
//     int read_pos; // Read position in the buffer
//     int write_pos; // Write position in the buffer
// };

// // Function to create a new named pipe
// int create_named_pipe(const char *fname);

// // Function to open an existing named pipe
// int open_named_pipe(const char *fname);

// #endif // NAMED_PIPE_H