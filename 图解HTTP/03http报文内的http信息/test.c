/**
* User: Qkj
* Description: 
* Date: 2023-08-16
* Time: 06:15
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
  int count = 10;
  while(count--)
  {
    printf("我是新手\r");
    sleep(1);
  }
  return 0;
}
