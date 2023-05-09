/**
 * User: Qkj
 * Description:
 * Date: 2023-05-08
 * Time: 15:21
 */

// 指针传参和引用传入参数
#include <iostream>
using namespace std;

int main()
{
  const int n = 10;
  int arr[n];
  cout << sizeof(arr) / sizeof(arr[0]) << endl;
  return 0;
}