/**
* User: Qkj
* Description: 
* Date: 2023-07-30
* Time: 22:09
*/
#include <stdio.h>
typedef unsigned char* byte_pointer;
void show_bytes(byte_pointer start, int len)
{
  int i = 0;
  for(; i < len; i++)
  {
    printf("%.2x ", start[i]);
  }
  printf("\n");
}
int main()
{
  float f = 1.0f;
  ~f;
  return 0;
}

//int main()
//{
//  char ret = 1;
//  show_bytes(&ret, (int)sizeof(ret));
//  return 0;
//}
//int main()
//{
//  printf("%d\n", (int)sizeof(long int));
//  printf("%d\n", (int)sizeof(long long));
//  return 0;
//}
