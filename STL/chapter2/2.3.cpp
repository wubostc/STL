#include <vector>
#include <iostream>

int main(){
  const size_t container_size{1000};
  std::vector<int> v(container_size, 123);
  
  std::cout << "out of range element value: " << v[container_size + 10] << std::endl;

  try{
    std::cout << "out of range element value: " << v.at(container_size + 10) << std::endl;
  } catch(const std::out_of_range &e) {
    std::cout << "Oops.. \n" << e.what() << std::endl;
  }
}
