#include <iostream>
#include <queue>
#include <tuple>
#include <string>

int main(int argc, char *argv[])
{
  using item_type = std::pair<int, std::string>;
  
  std::priority_queue<item_type> q;

  std::initializer_list<item_type> i1 {
    {1, "dishes"},
    {0, "watch tv"},
    {2, "do homework"},
    {0, "read comics"}
  };

  for(const auto &p : i1){
    q.push(p);
  }


  while(!q.empty()){
    std::cout << q.top().first << ": " << q.top().second << '\n';
    q.pop();
  }
  std::cout << '\n';

  return 0;
}
