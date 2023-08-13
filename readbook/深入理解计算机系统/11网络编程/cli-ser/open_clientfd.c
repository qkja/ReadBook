/**
* User: Qkj
* Description: 
* Date: 2023-08-13
* Time: 22:14
*/
#include "open_clientfd.h"

int open_clientfd(char* server_ip, int port)
{
  if(server_ip == NULL)
    exit(-1);
  int clientfd = -1;
  struct sockaddr_in server_sockaddr;

  // 创建套接字
  clientfd = socket(AF_INET, SOCK_STREAM, 0);
  if(clientfd < 0)
    exit(-2);

  // 填充server
  bzero(&server_sockaddr, sizeof(server_sockaddr));
  server_sockaddr.sin_family = AF_INET;
  server_sockaddr.sin_port = htons(port);
  inet_aton(server_ip, &(server_sockaddr.sin_addr));
  //server_sockaddr.sin_addr.s_addr = htonl(inet_addr(server_ip));
  
  //发起请求 链接
  if(connect(clientfd, (const struct sockaddr*)&server_sockaddr, sizeof(server_sockaddr)) < 0)
    exit(-3);
  return clientfd;
}
