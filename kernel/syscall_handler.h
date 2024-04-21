/*
Copyright (C) 2016-2019 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#ifndef SYSCALL_HANDLER_H
#define SYSCALL_HANDLER_H
#include "named_pipe.h"

/* Only kernel/syscall.handlers invoked by other parts of kernel code should be declared here. */

int sys_process_run( int fd, int argc, const char **argv);
int sys_process_exec( int fd, int argc, const char **argv);
int sys_process_sleep(unsigned int ms);

int sys_open_file( int fd, const char *path, int mode, kernel_flags_t flags );
int sys_mkdir( int fd, const char *path);
int sys_rmdir(int fd, const char *path);
int sys_object_close( int fd );

int sys_open_window(int wd, int x, int y, int w, int h);
int sys_process_object_max();

#endif
