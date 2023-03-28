#include <iostream>
int main()
{


  // 有人说 初始化为0的全局静态变量或者是全局变量在未初始化的区域,这里应该是对的,
  // 我们之前说过全局变量未初始化是0,这里证明一下 静态的就可以了
  static int a;
  std::cout << "a " << a << std::endl;
  //std::cout <<"hello" << std::endl;
  return 0;
}
