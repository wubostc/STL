#include <vector>
#include <algorithm>
#include <iostream>

void print(std::vector<int> &v){
  for(auto x:v){
    std::cout << x <<", ";
  }
  std::cout << std::endl;
}

int main(){
  std::cout << "init: ";
  std::vector<int> v{1,2,3,4,5,6,7,2,2,9};
  print(v);

  std::cout << "remove: ";
  auto new_end(std::remove(v.begin(), v.end(), 2)); 
  print(v);

  std::cout << "erase: ";
  v.erase(new_end, v.end());
  print(v);

}
