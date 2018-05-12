#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> &v){
  for(int i:v){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}

template<typename T>
void quick_remove_at(std::vector<T> &v, std::size_t idx){
  if(idx < v.size()){
    v[idx] = std::move(v.back());
    v.pop_back();
  }
}

template<typename T>
void quick_remove_at(std::vector<T> &v, typename std::vector<T>::iterator it){
  if(it != v.end()){
    *it = std::move(v.back());
    v.pop_back();
  }
}

int main(){
  std::vector<int> v{123,456,789,100,200};
  quick_remove_at(v, 2);
  print(v);

  quick_remove_at(v, std::find(v.begin(), v.end(), 123));
  print(v);
}
