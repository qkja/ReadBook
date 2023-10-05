/**
* User: Qkj
* Description: 
* Date: 2023-08-13
* Time: 22:51
*/
// 返回一个监听套接字
#include "open_listenfd.h"

int open_listenfd(int port)
{
  int listenfd = -1;
  int optval = 1;
  struct sockaddr_in server;


  // 1. 创建套接字
  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if(listenfd < 0)
    exit(-1);
  // 2. 让服务器立即重启
  if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void*)&optval, sizeof(int)) < 0)
    exit(-2);

  // 3. 填充服务器信息
  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  server.sin_port = htons((unsigned short)port);
  
  // 4. 绑定 服务器信息和套接字
  if(bind(listenfd, (const struct sockaddr*)&server, sizeof(server)) < 0)
    exit(-3);

  // 5. 监听 把套接字变为监听套接字
  if(listen(listenfd, 50) < 0)
    exit(-4);
  return listenfd;
}
