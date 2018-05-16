#include <iostream>
#include <unordered_map>
#include <functional>
struct coord{
  int x;int y;
};

struct key_hash {
  std::size_t operator()(const coord &c) const {
    return std::hash<int>()(c.x) ^ (std::hash<int>()(c.y) << 1);
  }
};

struct key_equal {
  bool operator()(const coord &l, const coord &r) const {
    return l.x == r.x && l.y ==r.y;
  }
};

int main(int argc, char *argv[])
{
  //                 key    value
  std::unordered_map<coord, int, ::key_hash, ::key_equal> m {
    { {0,0}, 1 },
    { {0,1}, 2 },
    { {2,1}, 3 }
  };

  for(const auto &[key, value] : m){
    std::cout << "{(" << key.x <<", " << key.y << "): " << value << "}";
  }
  std::cout << std::endl;

  std::cout << std::hash<std::string>()("435ufd") << std::endl;



  return 0;
}
