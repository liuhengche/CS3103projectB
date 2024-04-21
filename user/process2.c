void runForSeconds(int seconds) 
{
  unsigned int startTime; // seconds syscall_system_time(&startTime);
  unsigned int timeElapsed;
  do { syscall_system_time(&timeElapsed); timeElapsed -= startTime;
  } while(timeElapsed < seconds); 
}
int main(int argc, char const *argv[])
{
    runForSeconds(5);
    printf("finished process2: pid %d \n", syscall_process_self());
    return 0;
}
