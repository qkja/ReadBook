/**
* User: Qkj
* Description: 
* Date: 2023-08-13
* Time: 20:00
*/
#include <arpa/inet.h>
#include <stdio.h>
int main()
{
  int a = 1;
  uint32_t it = htonl(a);

  char* p = (char*)&it;
  char ch = it;// 截断
  printf("%d\n", *p);
  printf("%d\n", ch);
  // 00 00 00 01
  //char* p = (char*)&a;
  //printf("%d\n", *p);
  return 0;
}
