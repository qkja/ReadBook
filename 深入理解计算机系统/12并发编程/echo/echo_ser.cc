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
#include <signal.h>

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

// void wait_all_id(int *ids, int len, int id)
// {
//   for (int i = 0; i < 10; i++)
//   {
//     if (ids[i] == -1)
//     {
//       ids[i] = id;
//       break;
//     }
//   }

//   for (int i = 0; i < len; i++)
//   {
//     if (ids[i] != -1)
//     {
//       int ret = waitpid(ids[i], NULL, WNOHANG);
//       if (ret > 0)
//       {
//         ids[i] = -1;
//       }
//     }
//   }
// }
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
//   int ids[10] = {-1};
//   memset(ids, -1, sizeof(ids));
//   for (int i = 0; i < 10; i++)
//   {
//     printf("%d ", ids[i]);
//   }
//   printf("监听套接字打开成功%d\n", listen_fd);

//   while (1)
//   {
//     socklen_t client_len = sizeof(clientaddr);
//     // 创建链接描述符
//     int connfd = accept(listen_fd, (struct sockaddr *)&clientaddr, &client_len);
//     // 创建进程
//     pid_t id = fork();
//     if (id == 0)
//     {
//       close(listen_fd);
//       // printf("我是子进程 %d\n", getpid());
//       // // 子进程
//       while (1)
//       {
//         if (echo(connfd) == -1)
//           break;
//       }
//       close(connfd);
//       return 0;
//     }
//     else if (id < 0)
//     {
//       // 错误
//       continue;
//     }

//     // printf("我是父进程 %d\n", id);
//     // 这里一定是父进程
//     close(connfd);
//     // printf("我是父进程 %d\n", id);

//     wait_all_id(ids, sizeof(ids) / sizeof(ids[0]), id);
//   }

//   wait_all_id(ids, sizeof(ids) / sizeof(ids[0]), -1);
//   close(listen_fd);
//   return 0;
// }
// void hander(int sig)
// {
//   // 9号信号我们可以默认忽略,但是如果向自己处理,那么必须可以wait
//   waitpid(-1, NULL, WNOHANG); // 使用-1 阻塞任意进程
//   while ( waitpid(-1, NULL, WNOHANG) > 0)
//   {
//   // 之所以使用while,是应为在处理一个信号的时候,阻塞信号机会变成1,这里我们避免大量子进程一次性退出
//   }

//   // printf("我捕捉了一个信号");
// }
// int main(int argc, char **argv)
// {

//   if (argc != 2)
//   {
//     printf("Usage:\n\t./server server_port\n");
//     exit(1);
//   }

//   signal(SIGCHLD, hander);

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
//     // 创建进程
//     pid_t id = fork();
//     if (id == 0)
//     {
//       close(listen_fd);
//       // printf("我是子进程 %d\n", getpid());
//       // // 子进程
//       echo(connfd);
//       close(connfd);
//       exit(0);
//     }
//     else if (id < 0)
//     {
//       // 错误
//       continue;
//     }
//     close(connfd);
//   }
//   close(listen_fd);
//   return 0;
// }
// 忽略SIGCHLD信号
// int main(int argc, char **argv)
// {

//   if (argc != 2)
//   {
//     printf("Usage:\n\t./server server_port\n");
//     exit(1);
//   }

//   signal(SIGCHLD, SIG_IGN);

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
//     // 创建进程
//     pid_t id = fork();
//     if (id == 0)
//     {
//       close(listen_fd);
//       // printf("我是子进程 %d\n", getpid());
//       // // 子进程
//       echo(connfd);
//       close(connfd);
//       exit(0);
//     }
//     else if (id < 0)
//     {
//       // 错误
//       continue;
//     }
//     close(connfd);
//   }
//   close(listen_fd);
//   return 0;
// }

// 让孙子进程称为孤儿进程
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
//     // 创建进程
//     pid_t id = fork();
//     if (id == 0)
//     {
//       pid_t idd = fork();
//       if (idd == 0)
//       {

//         close(listen_fd);
//         // printf("我是子进程 %d\n", getpid());
//         // // 子进程
//         echo(connfd);
//         close(connfd);
//         exit(0);
//       }
//       else if (idd < 0)
//       {
//       }
//       // 子进程直接推出,孙子进程变成孤儿进程
//       exit(0);
//     }
//     else if (id < 0)
//     {
//       // 错误
//       continue;
//     }
//     waitpid(id, NULL, 0); // 这里是可以阻塞等待的,毕竟子进程的作用就是 创建孙子进程
//     close(connfd);
//   }
//   close(listen_fd);
//   return 0;
// }
#include "../threadPool/threadPool.hpp"
#include "../task/task.hpp"

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

  ThreadPool<Task> *tp = ThreadPool<Task>::getInstance();
  tp->start();
  printf("线程池启动成功\n");

  while (1)
  {
    socklen_t client_len = sizeof(clientaddr);
    // 创建链接描述符
    int connfd = accept(listen_fd, (struct sockaddr *)&clientaddr, &client_len);
    // 创建进程
    // Task(int sock, std::string ip, uint16_t port, callback_t func)

    Task t(connfd, inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port), echo); // 拿到一个任务,
    tp->push(t);
  }
  close(listen_fd);
  return 0;
}
