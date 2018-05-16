#include <iostream>
#include <map>
#include <string>
#include <iterator> // std::end

int main(int argc, char *argv[])
{
  std::map<std::string, std::size_t> m{ {"b", 1}, {"c", 2}, {"d", 3} };  

  auto insert_it(std::end(m));
  
  for(const auto &s : {"z", "y", "x", "w"}){
    insert_it = m.insert(insert_it, {s, 1}); // O(1)退化成O(log(n))
  }

  m.insert(std::end(m), "a");

  for(const auto &[key, value] : m){
    std::cout << "\"" << key << "\": " << value << ", ";
  }
  std::cout << '\n';



  return 0;
}
