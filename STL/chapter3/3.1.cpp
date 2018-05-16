#include <iostream>

class num_iterator{
  int i;
public:
  explicit num_iterator(int position = 0) : i(position) {}

  int operator*() const { return i; }

  num_iterator &operator++(){
    ++i;
    return *this;
  }

  bool operator!=(const num_iterator &other) const {
    return this->i != other.i;
  }
};

class num_range{
  int a;
  int b;
public:
  num_range(int from, int to) :
    a(from), 
    b(to) {}

  num_iterator begin() const { return num_iterator(a); }
  num_iterator end() const { return num_iterator(b); }
};


int main(int argc, char *argv[])
{
  num_range nr(100, 110);
  for(auto it = nr.begin(); it != nr.end(); ++it){
    std::cout << *it << std::endl;
  }
  std::cout << std::endl;

  for(auto it:nr){ 
    std::cout << it << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
