#pragma once

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <string>

// using callback_t = std::function<void(int, std::string, uint16_t)>;
int echo(int sock_fd, std::string ip, std::uint16_t port)
{
#define NUM 1024
  char read_buf[NUM] = {0};
  // 读取 内容
  while (1)
  {
    ssize_t s = read(sock_fd, read_buf, sizeof(read_buf) - 1);
    if (s == 0)
      break;
    read_buf[s] = '\0';
    printf("%s\n", read_buf);
    write(sock_fd, read_buf, strlen(read_buf));
  }
}
