/**
* User: Qkj
* Description: 
* Date: 2023-08-12
* Time: 10:37
*/
#include <stdio.h>

int exchange(int* xp, int y)
{
  int x = *xp;
  *xp = y;
  return x;
}
int main()
{
  int a = 10;
  exchange(&a, 10);
  printf("%p\n", &a);
  return 0;
}
