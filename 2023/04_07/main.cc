// 这里是 深入理解操作系统
// 1. 对于多字节的对象,我们要考虑他的地址是什么,和存储器如何排列这些数据
//    回答--> 对于大多数机器,我们把最小地址的地址作为对象的地址, -->这里引出的大小端问题

#include <iostream>
#include <cstdio>
#include <arpa/inet.h>
//
//int main()
//{
//  int a = 1;      // 00 00 00 01
//  // 低地址       高地址
//  //00 00 00 01 --> 这里是大端法
//  //01 00 00 00 --> 这里是小端法
//  printf("%d\n", *((char*)&a));
//  std::cout <<*((char*)(&a))<<std::endl;
//  fflush(stdout);
//  return 0;
//}

// 强制类型转换只会让编译器以一种另外的视角来看待被只想的的数据
//int main()
//{
//  int a = 10;
//  float f = (float)a;
//  // 这里的强制类型转化一定涉及到了临时对象的开辟,毕竟我们的整形和浮点型的存储规则不一样
//  printf("%d %f %f\n", a, f, static_cast<float>(a));
//  return 0;
//}
typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, int n)
{
  for(int i = 0; i < n; i++)
  {
    printf("%.2x ", start[i]);
  }
  printf("\n");
}

void test(int val)
{
  //byte_pointer ptr = static_cast<byte_pointer>(&val);
  byte_pointer ptr = reinterpret_cast<byte_pointer>(&val);// 强制类型转换

  show_bytes(ptr, 1);
  show_bytes(ptr, 2);
  show_bytes(ptr, 3);
}


int main()
{
  int val = 0x87654321;
  printf("小端: \n");
  test(val);

  printf("大端: \n");

  val = htonl(val);

  test(val);
  return 0;
}












