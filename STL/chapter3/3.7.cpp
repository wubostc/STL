#include <iostream>
#include <vector>
int main(int argc, char *argv[])
{
  std::vector<int> v{1,2,3};
  v.shrink_to_fit();
  const auto it{std::begin(v)};
  std::cout << *it << std::endl;

  v.push_back(123);
  std::cout << *it << std::endl;
  return 0;
}
