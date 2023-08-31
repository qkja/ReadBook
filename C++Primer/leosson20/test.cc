/**
* User: Qkj
* Description: 
* Date: 2023-05-08
* Time: 14:58
*/


//#include <iostream>
//
//class Node
//{
//  public:                    
//friend std::ostream& operator<<(std::ostream& out, const Node& n);        
//  private:                   
//    int _x = 0;              
//    int _y = 1;              
//};                           
//                             
//std::ostream& operator<<(std::ostream& out, const Node& n){       
//  out << n._x << " " << n._y;
//  return out;                    
//}                            
//                             
//int main()                   
//{                                                         
//  Node n1;                   
//  std::cout << n1 << std::endl;
//  return 0;
//}                            
//int main()
//{
//  int a = 10;
//  const char* str = "hello";
//  std::cout << "&a: " << &a << std::endl;
//  std::cout << str << std::endl;             
//  return 0;
//}
//
//
//#include <iostream>
//#include <vector>  
//#include <string>  
//using namespace std;  
//  
//void print_addr(const char* p)
//{                                                                                            
//  printf("%p\n", p);                                                             
//}                                                                                
//                                                                                 
//void max_num(int x, double d)                                                    
//{                                                                                
//  cout << (x < d ? x : d) << endl;                                               
//}                                                                                
//                                                                                 
//int main()                                                                       
//{     
//  // 我把第一问给省了,注意是太麻烦,但是不难
//  string robin( "christopher robin" );                                           
//  const char *pc = robin.c_str();                                                
//  int ival = 1024;                                                               
//  double dval = 3.14159;                                                         
//  print_addr(pc);                                                                
//  max_num(ival, dval);
//  return 0;
//}
//#include <iostream>    
//#include <vector>    
//#include <string>    
//using namespace std;    
//    
//    
//int main()    
//{    
//  int n = 0;    
//  while(cin >> n)    
//  {    
//                                                                                                                                
//  }        
//  return 0;                         
//}  
//#include <iostream>
//#include <string>
//using namespace std;  
//int main()
//{
//  int a = 0;
//  int b = 0;
//  int c = 0;
//  cin >> a >> b >> c;
//                                                               
//  cout << "a: " << a << endl;
//  cout << "b: " << b << endl;
//  cout << "c: " << c << endl;
//  return 0;       
//}                            
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//  string str;
//  cin >> str;
//  cout << str << endl;
//  return 0;
//}
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//  string str;
//  char ch = 0;
//  while (cin.get(ch))
//  {
//    cout.put(ch);
//  }
//
//  return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//  string str;
//  char ch = 0;
//  while (cin.get(ch))
//  {
//    cout.put(ch);
//    if (ch == '\n')
//      break;
//  }
//
//  return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Myclass
//{
//  friend ostream &operator<<(ostream &os, const Myclass &node);
//
//private:
//  int x = 0;
//  int y = 1;
//};
//
//ostream &operator<<(ostream &os, const Myclass &node)
//{
//  os << node.x << " " << node.y;
//  return os;
//}
//
//int main()
//{
//  Myclass node;
//  cout << node << endl;
//  return 0;
//}
//using namespace std;
//
//class Myclass
//{
//  friend ostream &operator<<(ostream &os, const Myclass &node);
//  friend istream &operator>>(istream &os, Myclass &node);
//
//private:
//  int x = 0;
//  int y = 1;
//};
//
//ostream &operator<<(ostream &os, const Myclass &node)
//{
//  os << node.x << " " << node.y;
//  return os;
//}
//istream &operator>>(istream &in, Myclass &node)
//{
//  in >> node.x >> node.y;
//  return in;
//}
//
//int main()
//{
//  Myclass node;
//  return 0;
//}
//#include <iostream>
//#include <string>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//  ifstream in("file.txt");
//  if (!in.is_open())
//    return -1;
//  char ch = 0;
//  while (in.get(ch))
//  {
//    cout << ch;
//  }
//
//  return 0;
//}
//#include <iostream>
//#include <string>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//  // std::ios::out 是 把原本内容清空,默认就是它
//  ofstream out("file.txt", std::ios::app);
//  if (!out.is_open())
//    return -1;
//
//  string str = "这是追加";
//  out << str;
//  return 0;
//}
//
//#include <iostream>
//#include <string>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//  fstream in_out;
//  in_out.open("file.txt", std::ios::in);
//  string str;
//  while (std::getline(in_out, str))
//  {
//    cout << str;
//    cout << endl;
//  }
//
//  in_out.close();
//  in_out.open("file.txt", std::ios::out);
//  str = "这是截断";
//  in_out << str;
//  in_out.close();
//
//  return 0;
//}
//
//int main()
//{
//  int val = 0;
//  cin >> val;
//
//  return 0;
//}
//int main()
//{
//  int val = 0;
//  while (cin >> val)
//  {
//  }
//
//  return 0;
//}
//struct Node
//{
//  int x;
//};
//
//int main()
//{
//  int val = 0;
//  Node n;
//  while (n)
//  {
//  }
//
//  return 0;
//}
//#include <iostream>
//#include <string>
//#include <fstream>
//using namespace std;
//
//struct Node
//{
//  int x;
//  operator bool()
//  {
//    return true;
//  }
//};
//
//int main()
//{
//  int val = 0;
//  Node n;
//  while (n)
//  {
//    cout << "hello" << endl;
//    break;
//  }
//
//  return 0;
//}
//
//#include <iostream>
//#include <string>
//#include <fstream>
//using namespace std;
//
//struct Node
//{
//  int x;
//  operator int()
//  {
//    return 1;
//  }
//};
//
//int main()
//{
//  int val = 0;
//  Node n;
//
//  int ret = n;
//  cout << ret << endl;
//
//  return 0;
//}
//
//
//
//int main()
//{
//  int ret = 0;
//  cin >> ret;
//  while (!cin)
//  {
//    cout << "hello" << endl;
//    break;
//  }
//
//  return 0;
//}
//
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <iostream>
//using namespace std;
//struct Node
//{
//  int x = 1;
//  int y = 2;
//};
//
//int main()
//{
//  Node n;
//  ostringstream out;
//  out << "x: " << n.x << "\n"
//      << "y: " << n.y << "\n";
//  cout << out.str();
//  return 0;
//}
//
//struct Node
//{
//  int x = 1;
//  int y = 2;
//};
//
//istream &operator>>(istream &os, Node &n)
//{
//  os >> n.x >> n.y;
//}
//
//int main()
//{
//  string str = "10 20";
//  istringstream in(str);
//  Node n;
//  in >> n;
//
//  cout << n.x << " " << n.y << endl;
//  return 0;
//}
