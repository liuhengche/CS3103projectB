#include "fs.h"
#include "named_pipe.h"
#include "kmalloc.h"
#include "string.h"
#include "process.h"
#include "page.h"
#include "kernel/types.h"

#define NAMED_PIPE_SIZE PAGE_SIZE




struct named_pipe {
    char *fname;
    struct fs_dirent *file;
    char *mes;
    
};

static struct named_pipe *named_pipes[10];
static int index = 0;

void create_file_at_path(char* full_path) {
    // Find the last slash in the path
    char* last_slash = strchr(full_path, '/');
    if (!last_slash) {
        // Handle error: the path does not include a directory
        return;
    }

    // Temporarily replace the last slash with a null terminator to split the path
    *last_slash = '\0';

    // Resolve the directory
    struct fs_dirent *dir = fs_resolve(full_path);
    if (!dir) {
        // Handle error: the directory does not exist
        return;
    }

    // Restore the slash in the path and get the filename
    *last_slash = '/';
    char* filename = last_slash + 1;

    // Create the file
    struct fs_dirent *file = fs_dirent_mkfile(dir, filename);
    if (!file) {
        // Handle error: the file could not be created
        return;
    }

    // Close the directory and file when you're done with them
    fs_dirent_close(dir);
    fs_dirent_close(file);
}



struct named_pipe *named_pipe_create(char *fname) {
    // the default location of named_pipe is bin/named_pipe
    struct fs_dirent *dir = fs_resolve("bin");
    if (!dir) {
        // Handle error: the directory "bin" does not exist
        printf("Uh oh, the directory does not exist");
    }

    struct fs_dirent *file = fs_dirent_mkfile(dir, "named_pipe");
    if (!file) {
        // Handle error: the file could not be created
        printf("Uh oh, the file could not be created");
    }

    struct named_pipe *np = kmalloc(sizeof(struct named_pipe));
    if (!np) {
        // Handle error: memory allocation failed
        printf("Uh oh, memory allocation failed");
    }

    np->fname = kmalloc(strlen(fname) + 1);
    strcpy(np->fname, fname);
    np->file = file;
    np->mes = kmalloc(NAMED_PIPE_SIZE);
    named_pipes[index] = np;
    index++;
    

    return np;
    
}

struct named_pipe *named_pipe_open(char *fname) {
    for (int i = 0; i < index; i++) {
        if (strcmp(named_pipes[i]->fname, fname) == 0) {
            return named_pipes[i];
        }
    }
    return named_pipes[0];
}



















// // kernel/named_pipe.c

// #include <kernel/named_pipe.h>
// #include <kernel/fs.h>
// #include <kernel/kobject.h>
// #include <kernel/errno.h>
// #include <kernel/process.h>

// // Create a new named pipe
// int create_named_pipe(const char *fname) {
//     // Create a new file for the named pipe
//     struct file *file = fs_dirent_mkfile(fname, S_IFIFO | S_IRUSR | S_IWUSR);
//     if (!file) {
//         return -ENOENT; // Error creating the file
//     }

//     // Allocate memory for the named pipe structure
//     struct named_pipe *pipe = kmalloc(sizeof(struct named_pipe));
//     if (!pipe) {
//         return -ENOMEM; // Memory allocation failed
//     }

//     // Initialize the named pipe structure
//     pipe->file = file;
//     pipe->read_pos = 0;
//     pipe->write_pos = 0;

//     // Add the named pipe to the kobject list
//     kobject_add(&pipe->file->kobj);

//     return 0; // Success
// }

// // Open an existing named pipe
// int open_named_pipe(const char *fname) {
//     // Find the file associated with the named pipe
//     struct file *file = fs_dirent_lookup(fname);
//     if (!file || !(file->mode & S_IFIFO)) {
//         return -ENOENT; // Named pipe not found
//     }

//     // Allocate memory for the named pipe structure
//     struct named_pipe *pipe = kmalloc(sizeof(struct named_pipe));
//     if (!pipe) {
//         return -ENOMEM; // Memory allocation failed
//     }

//     // Initialize the named pipe structure
//     pipe->file = file;
//     pipe->read_pos = 0;
//     pipe->write_pos = 0;

//     // Add the named pipe to the kobject list
//     kobject_add(&pipe->file->kobj);

//     return 0; // Success
// }

struct fs_dirent *rootDir() {
    static struct fs_dirent *root;
    if (!root) {
        struct fs *f = fs_lookup("diskfs");
        struct device *dev = device_open("ata", 0);
    }
    return root;
}