#include <iostream>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <assert.h>

// ./UDPClient server_ip server_port
static void Usage(std::string name)
{
  std::cout << "Usage:\n\t" << name << " server_ip server_port" << std::endl;
}
int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    Usage(argv[0]);
    exit(1);
  }
  // 1. 根据命令行，设置要访问的服务器IP
  std::string server_ip = argv[1];
  uint16_t server_port = atoi(argv[2]);

  // 2. 创建 客户端的套接字
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  assert(sockfd > 0);

  // 3. 填充服务器信息
  struct sockaddr_in server;
  bzero(&server, sizeof server);
  server.sin_family = AF_INET;
  server.sin_port = htons(server_port);
  server.sin_addr.s_addr = inet_addr(server_ip.c_str());

  std::string buffer;
  while (true)
  {
    std::cerr << "Please Enter# ";
    std::getline(std::cin, buffer);
    // 发送消息给server
    //std::cout << buffer <<std::endl;
    sendto(sockfd, buffer.c_str(), buffer.size(), 0,
           (const struct sockaddr *)&server, sizeof(server)); // 首次调用sendto函数的时候，我们的client会自动bind自己的ip和port
  }
  return 0;
}
