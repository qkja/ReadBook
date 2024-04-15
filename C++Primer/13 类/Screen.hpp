#pragma once

#include <iostream>
#include <string>
class Screen
{
    friend std::istream& operator>>(std::istream&, Screen&);
    friend std::ostream& operator<<(std::ostream&, const Screen&);
public:
    Screen(/* args */);
    ~Screen();
    short height()
    {
        return _height;
    }
    short width()
    {
        return _width;
    }
    void home()
    {
        _cursor = 0;
    }
    char get()
    {
        return _screen[_cursor];
    }
    char get(int x, int y)
    {
        // 这里不做参数检测
        return _screen[x * _height + y];
    }

private:
    std::string _screen;
    std::string::size_type _cursor;
    short _height;
    short _width;
};

std::istream& operator>>(std::istream& ifs, Screen& s)
{
    ifs >> s._screen >> s._cursor >> s._height >> s._width;
    return ifs;
}
std::ostream& operator<<(std::ostream& ofs, const Screen& s)
{
    ofs << "<" << s._height << "," << s._width << ">";
    ofs << s._screen;
    return ofs;
}

