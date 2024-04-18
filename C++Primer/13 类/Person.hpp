#include <iostream>
#include <string>

// 练习 13.1
// 给出一个类Person 它有下列两个数据成员
// string _name;
// string _address;
// 以及下列成员函数
// Person( const string &n, const string &a )
// : _name( n ), _address( a ) { }
// string name() { return _name; }
// string address() { return _address; }
// 你会把哪些成员声明在公有区内哪些声明在私有区内说明理由

class Person
{
public:
    Person(const std::string &n, const std::string &a)
        : _name(n), _address(a)
    {
    }
    std::string name()
    {
        return _name;
    }
    std::string address()
    {
        return _address;
    }

private:
    std::string _name;
    std::string _address;
};

// 你会把哪些成员声明在公有区内哪些声明在私有区内说明理由
// _name, _address 成员变量声明在私有区, name, address成员函数在共有区
// 私有的是为了保护我们的成员变量在其他的地方不可以随意的被修改,
// 共有的是因为我们无法直接访问私有的成员,为了得到值,就可以了

// 练习 13.2
// 请说明类定义与类声明之间的区别什么时候用类声明什么时候用类定义

//  声明就是告知有这个东西,但是具体是什么还没有说, 定义就是真正的填充我们细节
//  声明最好在头文件使用,定义最好不要在头文件,为了避免重复定义