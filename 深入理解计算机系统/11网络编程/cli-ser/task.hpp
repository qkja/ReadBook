#ifndef __TASK_HPP__
#define __TASK_HPP__
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int echo(int sock_fd)
{
#define NUM 1024
  char read_buf[NUM] = {0}; 
  // 读取 内容
  ssize_t s =  read(sock_fd, read_buf, sizeof(read_buf)-1);
  if(s == 0)
    return -1;
  read_buf[s] = '\0';
  printf("%s\n", read_buf);
  write(sock_fd, read_buf, strlen(read_buf));
  return 0;
}
#endif
