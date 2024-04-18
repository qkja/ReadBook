#include <iostream>
#include "Screen.hpp"
using namespace std;

bool isEqual(Screen& s1, Screen* s2)
{
    if(s1.height() != s2->height())  return  false;
    for(int ix = 0; ix < s1.height(); ++ix)
    {
        for(int iy = 0; iy< s2->width(); ++iy)
        {
            if(s1.get(ix, iy) !=  s2->get(ix, iy))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
  std::cout << "hello" << std::endl;
  return 0;
}



