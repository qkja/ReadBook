/**
* User: Qkj
* Description: 
* Date: 2023-08-13
* Time: 23:27
*/
#include <stdio.h>
#include <unistd.h>
#include "../open_fd/open_clientfd.h"
#include <string.h>
// .client server_ip server_port
int main(int argc, char** argv)
{
  if(argc != 3)
  {
    printf("Usage:\n\t ./client server_ip server_port\n");
    exit(1);
  }
  char* server_ip = argv[1];
  int server_port = atoi(argv[2]);
  int client_fd = 0;
  client_fd = open_clientfd(server_ip, server_port);
  printf("套接字打开成功%d\n", client_fd);
#define NUM 1024
  char send_buf[NUM] = {0};
  char read_buf[NUM] = {0};
  while(1)
  {
    ssize_t s = read(0, send_buf, sizeof(send_buf)-1);
    if(s == 0)
    {
      printf("客户端退出了\n");
      break;
    }
    send_buf[s-1] = '\0';
    // 发送给服务器
    write(client_fd, send_buf, strlen(send_buf));
    ssize_t ss = read(client_fd, read_buf, sizeof(read_buf)-1);
    read_buf[ss] = '\0';
    printf("[%s:%d]: %s\n", server_ip, server_port, read_buf);
  }
  close(client_fd);
  return 0;
}
