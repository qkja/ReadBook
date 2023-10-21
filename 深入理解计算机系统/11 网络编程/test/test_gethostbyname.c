/**
* User: Qkj
* Description: 
* Date: 2023-08-13
* Time: 21:11
*/
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv)
{
  char** pp = NULL;
  struct in_addr addr; // IP地址
  struct hostent* hostp = NULL;

  if(argc != 2)
  {
    fprintf(stderr, "usage: %s <domain name or dotted-decimal>\n", argv[0]);
    exit(0);
  }

  if(inet_aton(argv[1], &addr) != 0)
    hostp = gethostbyaddr((const void*)&addr, sizeof(addr), AF_INET);// 点分十进制转化位 32位数字成功
  else 
    hostp = gethostbyname(argv[1]);
  printf("official hostname: %s\n", hostp->h_name);
  for(pp = hostp->h_aliases; *pp != NULL; pp++)
    printf("alias: %s\n", *pp);

  for(pp = hostp->h_addr_list; *pp != NULL; pp++)
  {
    addr.s_addr = ((struct in_addr*)*pp)->s_addr;
    printf("address %s\n", inet_ntoa(addr));
  }

}
