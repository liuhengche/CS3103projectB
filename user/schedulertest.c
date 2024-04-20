//startup code for the five test programs, namely "process1.c", "process2.c", "process3.c", "process4.c", and "process5.c". 

#include "library/syscalls.h"
#include "library/string.h"
#include "library/stdio.h"
#include "library/kernel_object_string.h"
#include "library/nwindow.h"
#include "library/errno.h"
#include "library/stdlib.h"


int main() {
    const char * exec1 = "bin/process1";
    const char * exec2 = "bin/process2";
    const char * exec3 = "bin/process3";
    const char * exec4 = "bin/process4";
    const char * exec5 = "bin/process5";

    int argc;
    const char * argv1[3];
    argv1[0] = exec1;

    const char * argv2[3];
    argv2[0] = exec2;

    const char * argv3[3];
    argv3[0] = exec3;

    const char * argv4[3];
    argv4[0] = exec4;

    const char * argv5[3];
    argv5[0] = exec5;

    int pfd1 = syscall_open_file(KNO_STDDIR, exec1, 0, 0);
    int pfd2 = syscall_open_file(KNO_STDDIR, exec2, 0, 0);
    int pfd3 = syscall_open_file(KNO_STDDIR, exec3, 0, 0);
    int pfd4 = syscall_open_file(KNO_STDDIR, exec4, 0, 0);
    int pfd5 = syscall_open_file(KNO_STDDIR, exec5, 0, 0);

}

