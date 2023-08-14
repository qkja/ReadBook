/**
 * User: Qkj
 * Description:
 * Date: 2023-08-13
 * Time: 23:27
 */
#include <stdio.h>
#include <unistd.h>
#include "../open_fd/open_listenfd.h"
#include "task.hpp"
#include <sys/types.h>
#include <sys/wait.h>

// ./server server_port
// 1 单进程版本
// int main(int argc, char **argv)
// {
//   if (argc != 2)
//   {
//     printf("Usage:\n\t./server server_port\n");
//     exit(1);
//   }
//   int listen_fd = -1;
//   int port = atoi(argv[1]);
//   struct sockaddr_in clientaddr;
//   listen_fd = open_listenfd(port);
//   printf("监听套接字打开成功%d\n", listen_fd);
//   while (1)
//   {
//     socklen_t client_len = sizeof(clientaddr);
//     // 创建链接描述符
//     int connfd = accept(listen_fd, (struct sockaddr *)&clientaddr, &client_len);
//     printf("open fd %d success\n", connfd);
//     close(connfd);

//     printf("close fd %d success\n", connfd);
//     // printf("=======================\n");
//     // if(connfd == )先不关系创建失败的问题
//     //  处理任务
//     // 1 单进程版本
//     while (1)
//     {
//       if (echo(connfd) == -1)
//         break;
//     }
//   }
//   return 0;
// }
// 2.多进程版本,非阻塞版本

void wait_all_id(int *ids, int len, int id)
{
  for (int i = 0; i < 10; i++)
  {
    if (ids[i] == -1)
    {
      ids[i] = id;
      break;
    }
  }

  for (int i = 0; i < len; i++)
  {
    if (ids[i] != -1)
    {
      int ret = waitpid(ids[i], NULL, WNOHANG);
      if (ret > 0)
      {
        ids[i] = -1;
      }
    }
  }
}
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
  int ids[10] = {-1};
  memset(ids, -1, sizeof(ids));
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", ids[i]);
  }
  printf("监听套接字打开成功%d\n", listen_fd);

  while (1)
  {
    socklen_t client_len = sizeof(clientaddr);
    // 创建链接描述符
    int connfd = accept(listen_fd, (struct sockaddr *)&clientaddr, &client_len);
    // 创建进程
    pid_t id = fork();
    if (id == 0)
    {
      close(listen_fd);
      // printf("我是子进程 %d\n", getpid());
      // // 子进程
      while (1)
      {
        if (echo(connfd) == -1)
          break;
      }
      close(connfd);
      return 0;
    }
    else if (id < 0)
    {
      // 错误
      continue;
    }

    // printf("我是父进程 %d\n", id);
    // 这里一定是父进程
    close(connfd);
    // printf("我是父进程 %d\n", id);

    wait_all_id(ids, sizeof(ids) / sizeof(ids[0]), id);
  }

  wait_all_id(ids, sizeof(ids) / sizeof(ids[0]), -1);
  close(listen_fd);
  return 0;
}
