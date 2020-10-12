
#include <stdio.h>
#include "../inc/spi.h"

int main (int argc, const char** argv) {
  
  spi::string test_string1 {"TEST1"};
  spi::string test_string2 {"TEST2"};
  spi::string test_string3 {"TEST3"};
  
  spi::array<spi::string> test_array {test_string1, test_string2, test_string3};
  spi::list<spi::string> test_list;

  for (const auto& str : test_array)
    test_list.add (str);

  for (const auto& str : test_list)
    printf ("%s\n", str.c_str ());

  test_string1 << test_string2;
  printf ("%s\n", test_string1.c_str ());

  return 0;
};
