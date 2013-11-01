#include "fib.hpp"

int main()
{
  return lazy_fib<int_<3> >::type::value;
}

