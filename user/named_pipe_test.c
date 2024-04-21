#include "library/syscalls.h"
#include "library/string.h"
#include "library/stdio.h"

// int senderProgram() {
//     printf("Hi! I am the sender.\n");
//     const char* fileName = "bin/named_pipe";
//     char buffer[] = "Hello World!\n";

//     int res = syscall_make_named_pipe(fileName);
//     int fd = syscall_open_named_pipe(fileName);

//     syscall_object_write(fd, buffer, strlen(buffer),0);
    

//     printf("I have sent the data!\n");
//     return 1;
// }

// int receiverProgram() {
//     printf("Hi! I am the receiver.\n");
//     const char* fileName = "bin/named_pipe";
    
//     int res;
//     int fd = syscall_open_named_pipe(fileName);
//     if (fd >= 0) {
//         char buffer[20];

//         res = syscall_object_read(fd, buffer, 20, 0);
//         if (res > 0) {
//             buffer[res] = '\0';
//             printf("I have received the message! The message is: %s\n", buffer);
//         } else {
//             printf("Error in receiving the message!\n");
//         }
//         syscall_object_close(fd);
//         printf("I have received the data!\n");
//     }
//     else {
//         printf("Error in opening the named pipe!\n");
//     }
//     return 1;

// }


int main(int argc, char *argv[]) {
    printf("This is the named pipe test program!\n");
    const char* fileName = "bin/named_pipe";
    syscall_make_named_pipe(fileName);
    int w = syscall_open_named_pipe(fileName);
    int x = syscall_process_fork();
    if (x) {
        printf("I am the sender!\n");
        char buf[] = "Hello World\n";
        syscall_object_write(w, buf, strlen(buf), 0);
        printf("I have sent the data!\n");
        syscall_process_sleep(1000);
    } else {
        printf("I am the receiver!\n");
        int r;
        char buf[20];
        syscall_object_read(w, buf, 20, 0);
        printf("I have received the message! The message is: %s\n", buf);
    }
    return 0;

}


// int main(int argc, char* argv[]) {
//     printf("This is the named pipe test program!\n");
    
    
//     senderProgram();
//     receiverProgram();
    

//     printf("Exiting named pipe test program!\n");
//     return 1;

// }