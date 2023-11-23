#include <stdio.h>
void f();
int main()
{
  f(10);
  return 0;
}

void f(int x)
{
  printf("eee\n");
}

//int main()
//{
//  int feet = 0;
//  int fathoms  = 0;
//
//  fathoms = 2;
//  feet = 6 * fathoms;
//  printf("There are %d feet in %d fathoms!\n", feet, fathoms);
//  printf("Yes, I said %d feet!\n", 6 * fathoms);
//  return 0;
//}
