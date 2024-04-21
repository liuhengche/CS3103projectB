//start-up program

void create_process_priority(const char *exec, int priority){
  int pfd = syscall_open_file(KNO_STDDIR,exec,0,0);
  if(pfd>=0) {
    int pid = syscall_process_prun(pfd, 0, &exec, priority); // new syscall with one more "priority" parameter
    if(pid > 0) {
      printf("started process %d\n", pid); } 
    else {
      printf("couldn't run %s: %s\n", exec,strerror(pid));}
    syscall_object_close(pfd);}
  else {
    printf("couldn't find %s: %s\n", exec,strerror(pfd));
  }
}

int main(int argc, char const *argv[])
{
   
  create_process_priority("bin/process1.exe", 9);//put process with priority in to priority_waiting_list
  create_process_priority("bin/process2.exe", 7);
  create_process_priority("bin/process3.exe", 2);
  create_process_priority("bin/process4.exe", 1);
  create_process_priority("bin/process5.exe", 5);
  syscall_prun_all();//put process in ready list in order of priority
  return 0;
}
