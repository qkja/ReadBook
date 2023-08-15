#pragma once
#include <iostream>
std::ostream &Log()
{
  std::cout << "For Debug | "
            << " timestamp " << (std::uint32_t)time(nullptr)
            << "| Thread [" << pthread_self() << "] | ";
  return std::cout;
}