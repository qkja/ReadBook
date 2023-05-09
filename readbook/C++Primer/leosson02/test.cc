/**
 * User: Qkj
 * Description:C++ Primer 第二章
 * Date: 2023-05-09
 * Time: 08:22
 */

// #include <iostream>
// #include <algorithm>
// using namespace std;

// class IntArray
// {
// public:
//   IntArray(int size = 0);
//   IntArray(int arr[], int size);

//   // 相等与不相等操作 #2b
//   bool operator==(const IntArray &) const;
//   bool operator!=(const IntArray &) const;
//   int operator[](int) const;
//   // 赋值操作符 #2a
//   IntArray &operator=(const IntArray &);
//   int size() const;          // #1
//   void sort();               // #4
//   int min() const;           // #3a
//   int max() const;           // #3b
//   int find(int value) const; // #3c
// private:
//   int *_arr;    // 空间
//   size_t _size; // 有效数据的个数
//   size_t _cap;  // 容量
// };

// // 1.数组类的实现中有内置的自我意识首先它知道自己的大小
// int IntArray::size() const
// {
//   return this->_size;
// }
// // 2.数组类支持数组之间的赋值以及两个数组之间的相等和不相等的比较操作
// bool IntArray::operator==(const IntArray &arr) const
// {
//   // 这里我们认为只要他们所有的元素都相等我们就相等
//   if (this->_size != arr._size)
//     return false;
//   for (size_t i = 0; i < this->_size; i++)
//   {
//     if (this->_arr[i] != arr._arr[i])
//       return false;
//   }
//   return true;
// }

// bool IntArray::operator!=(const IntArray &arr) const
// {
//   return !((*this) == arr);
// }

// // 赋值操作符 #2a
// IntArray &IntArray::operator=(const IntArray &arr)
// {
//   // 说实话这个判断在下面没有必要,可是我有点害怕
//   if (arr.size() == 0)
//   {
//     _size = 0;
//     return *this;
//   }

//   // 判断是不是要扩容
//   if (_cap < arr.size())
//   {
//     // 扩容
//     int *p = new int[arr.size()];
//     delete[] _arr;
//     _arr = p;
//     _cap = arr.size();
//   }

//   for (size_t i = 0; i < arr.size(); i++)
//   {
//     _arr[i] = arr._arr[i];
//   }

//   _size = arr.size();
//   return *this;
// }

// // 3.数组类应该支持对其所含的值进行下列查询操作数组中最小值是什么最大值是什
// int IntArray::min() const
// {
//   if (_size == 0)
//     return -1;
//   int minNum = _arr[0];
//   for (size_t i = 1; i < _size; i++)
//   {
//     if (_arr[i] < minNum)
//       minNum = _arr[i];
//   }
//   return minNum;
// }
// int IntArray::max() const
// {
//   if (_size == 0)
//     return -1;
//   int maxNum = _arr[0];
//   for (size_t i = 1; i < _size; i++)
//   {
//     if (_arr[i] > maxNum)
//       maxNum = _arr[i];
//   }
//   return maxNum;
// }

// int IntArray::find(int value) const
// {
//   for (size_t i = 0; i < _size; i++)
//   {
//     if (_arr[i] == value)
//       return i;
//   }
//   return -1;
// }

// // 4.数组类支持自排序为了便于讨论假定存在一群用户他们认为数组支持排序的功能很重要而另外一些人对此却不以为然
// void IntArray::sort()
// {
//   int *begin = _arr;
//   int *end = _arr + _size;
//   std::sort(begin, end, std::greater<int>());
// }
// // 5.能够指定长度以此来创建数组这个值无需在编译时刻知道
// IntArray::IntArray(int size)
// {
//   _size = 0;
//   _cap = size;
//   _arr = new int[_cap];
// }
// // 6.能够用一组值初始化数组
// IntArray::IntArray(int arr[], int size)
// {
//   _size = size;
//   _cap = size;
//   _arr = new int[_cap];
//   for (size_t i = 0; i < size; i++)
//   {
//     _arr[i] = arr[i];
//   }
// }
// // 7.能够通过一个索引来访问数组中的单个元素为便于讨论假设用户强烈要求用数组下标操作符来实现这项功能
// int IntArray::operator[](int index) const
// {
//   if (index >= 0 && index <= _size)
//     return _arr[index];
// }

// int main()
// {
//   IntArray arr1;
//   cout << arr1.size() << endl;
//   int a[10] = {1, 2, 1, 3, 4, 6, 4, 0};
//   IntArray arr2(a, 10);
//   arr2.sort();

//   // if (arr1 == arr2)
//   // {
//   //   cout << " == " << endl;
//   // }
//   arr1 = arr2;

//   if (arr1 == arr2)
//   {
//     cout << " == " << endl;
//   }
//   for (size_t i = 0; i < arr1.size(); i++)
//   {
//     cout << arr2[i] << " ";
//   }
//   cout << endl;

//   return 0;
// }

// class classname
// {
// public:
//   // 公有操作集合
// private:
//   // 私有实现代码
// };

// int main()
// {
//   int *pi = new int(10);
//   int *pia = new int[10];
//   while (*pi < 10)
//   {
//     pia[*pi] = *pi;
//     *pi = *pi + 1;
//   }
//   delete pi;
//   delete[] pia;
//   cout << "ff" <<endl;
//   return 0;
// }
// int main()
// {
//   int* pint = new int(1);
//   int* pintarr = new int[10];

//   delete pint;
//   delete[] pintarr;
//   return 0;
// }
// #include <iostream>
// using namespace std;

// void func(int arr[10])
// {
//   cout << sizeof(arr) << endl;
// }
// int main()
// {
//   int arr[10] = {0};
//   cout << sizeof(arr) << endl;
//   func(arr);
//   return 0;
// }

// int main()
// {
//   int ia[10];
//   int index;
//   for (index = 0; index < 10; ++index)
//     // ia[0] = 0, ia[1] = 1, 等等
//     ia[index] = index;

//   for (index = 9; index >= 0; --index)
//     cout << ia[index] << " ";
//   cout << endl;
//   return 0;
// }
// int main()
// {
//   return 0;
// }