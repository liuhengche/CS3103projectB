#include "library/syscalls.h"
#include "library/stdio.h"

void runForSeconds(int seconds)
{
    unsigned int startTime; // seconds
    syscall_system_time(&startTime);
    unsigned int timeElapsed;
    do
    {
        syscall_system_time(&timeElapsed);
        timeElapsed -= startTime;
    } while (timeElapsed < seconds);
}

int main(int argc, char const *argv[])
{
    runForSeconds(3);
    printf("process1 with pid: %d done\n", syscall_process_self());

    return 0;
}
