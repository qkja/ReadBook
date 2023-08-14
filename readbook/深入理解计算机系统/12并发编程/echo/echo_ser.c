/**
 * User: Qkj
 * Description:
 * Date: 2023-08-13
 * Time: 23:27
 */
#include <stdio.h>
#include "../open_fd/open_listenfd.h"
#include "task.hpp"
// ./server server_port
// 1 单进程版本
int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Usage:\n\t./server server_port\n");
    exit(1);
  }
  int listen_fd = -1;
  int port = atoi(argv[1]);
  struct sockaddr_in clientaddr;
  listen_fd = open_listenfd(port);
  printf("监听套接字打开成功%d\n", listen_fd);
  while (1)
  {
    socklen_t client_len = sizeof(clientaddr);
    // 创建链接描述符
    int connfd = accept(listen_fd, (struct sockaddr *)&clientaddr, &client_len);
    printf("open fd %d success\n", connfd);
    close(connfd);

    printf("close fd %d success\n", connfd);
    // printf("=======================\n");
    // if(connfd == )先不关系创建失败的问题
    //  处理任务
    // 1 单进程版本
    while (1)
    {
      if (echo(connfd) == -1)
        break;
    }
  }
  return 0;
}
