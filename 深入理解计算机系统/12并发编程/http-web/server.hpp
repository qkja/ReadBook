#pragma once
#include <string>
#include <netinet/in.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

class Server
{
public:
  void Listen(int port, const std::string ip = "")
  {
    int listen_fd = -1;
    struct sockaddr_in clientaddr;
    listen_fd = open_listenfd(port, ip);

    while (true)
    {
      socklen_t client_len = sizeof(clientaddr);
      // 创建链接描述符
      int connfd = accept(listen_fd, (struct sockaddr *)&clientaddr, &client_len);
      // 创建进程
      pid_t id = fork();
      if (id == 0)
      {
        // 这是父进程
        pid_t idd = fork();
        if (idd == 0)
        {
          // 这是孙子进程
          close(listen_fd);
          // 这里提供服务
          provide_services(connfd);
          close(connfd);
          exit(0);
        }
        else if (idd < 0)
        {
        }
        // 子进程直接推出,孙子进程变成孤儿进程
        exit(0);
      }
      else if (id < 0)
      {
        // 错误

        continue;
      }
      // 这里是爷爷进程,在等待父进程
      waitpid(id, NULL, 0); // 这里是可以阻塞等待的,毕竟子进程的作用就是 创建孙子进程
      close(connfd);
    }
    close(listen_fd);
  }

private:
  void provide_services(int connfd)
  {
    // 这个是给客户端提供服务的
  }
  // 设置监听套接字
  int open_listenfd(int port, const std::string ip = "")
  {
    int listenfd = -1;
    int optval = 1;
    struct sockaddr_in server;

    // 1. 创建套接字
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0)
      exit(-1);
    // 2. 让服务器立即重启
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int)) < 0)
      exit(-2);

    // 3. 填充服务器信息
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    // IP地址转换
    server.sin_addr.s_addr = ip.empty() ? htonl(INADDR_ANY) : inet_addr(ip.c_str());
    server.sin_port = htons((unsigned short)port);

    // 4. 绑定 服务器信息和套接字
    if (bind(listenfd, (const struct sockaddr *)&server, sizeof(server)) < 0)
      exit(-3);

    // 5. 监听 把套接字变为监听套接字
    if (listen(listenfd, 50) < 0)
      exit(-4);
    return listenfd;
  }

private:
  std::string root; // 这是跟目录
};
