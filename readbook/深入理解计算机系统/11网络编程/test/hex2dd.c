/**
* User: Qkj
* Description: 
* Date: 2023-08-13
* Time: 20:13
*/
#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
struct my_in_addr 
{
  unsigned int s_addr;
};

// 十六进制转化为 点分十进制
char* my_inet_ntoa(struct my_in_addr in)
{
  // 拿到,注意由于我们不知道是大端还是小端,此时同意转换位大端
  unsigned int it = htonl(in.s_addr);
  unsigned char * p = (unsigned char*)&it;
  unsigned char* str = (unsigned char*)malloc(15);
  memset(str, '\0', sizeof(str));
  for(int i = 0; i < 4; i++)
  {
    sprintf(str+strlen(str), "%d", p[i]);
    if(i != 3)
    str[strlen(str)] = '.';
  }
  return str;
}

int main(int argc, char* argv[])
{
  if(argc != 2)
    return -1;

  struct my_in_addr s;
  s.s_addr = strtol(argv[1], NULL, 16);
  char* str = my_inet_ntoa(s);
  printf("%s\n", str);
  free(str);
  return 0;
}
