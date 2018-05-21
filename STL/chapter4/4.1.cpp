#include <iostream>


int main(int argc, char *argv[])
{
  auto counter(
    [count = 0]() mutable { return ++count; }    
  );
  
  for(size_t i{0}; i < 5; ++i){
    std::cout << counter() << ", ";
  }

  return 0;
}
