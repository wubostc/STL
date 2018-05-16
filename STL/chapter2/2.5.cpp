#include <iostream>
#include <functional>
#include <list>
#include <map>
#include <utility> // pair
using namespace std;

struct billionaire{
  string name;
  double dollars;
  string country;
};


int main(int argc, char *argv[])
{
  list<::billionaire> billionaires {
    {"Bill Gates", 86.0, "USA"},
    {"Warren Buffet",75.6,"USA"},
    {"Amancio Ortega", 71.3, "Spain"},
    {"Mark Zuckerberg", 56.0, "USA"},
    {"Carlos Slim", 54.5, "Mexico"},
    {"Bernard Arnault", 41.5, "France"},
    {"Liliane Bettencourt", 39.5, "France"},
    {"Wang Jianlin", 31.3, "China"},
    {"Li Ka-shing", 31.2, "Hong Kong"}
  };

  map<string, pair<const ::billionaire, std::size_t>> m;
  map<string, pair<const ::billionaire, std::size_t>> m_copy;

  for(const auto &b : billionaires){
    auto [itor, success] = m.try_emplace(b.country, b, 1); 
    if(!success){
      itor->second.second += 1;
    }
  }

  for(auto it = billionaires.begin(); it != billionaires.end(); ++it){
    pair<map<string, pair<const ::billionaire, std::size_t>>::iterator, bool> res = m_copy.try_emplace(it->country, *it, 1);
    if(!res.second){
      res.first->second.second += 1;
    }
  }

  for(const auto &[key, value] : m){
    const auto &[b, count] = value;
    std::cout 
        << b.country << " : " << count
        << " billionaires. Richest is "
        << b.name << " with " << b.dollars << " B$\n"; 
  }

  cout << "--------\n";
  for(const auto &[key, value] : m_copy){
    // const auto &[b, count] = value;
    pair<const ::billionaire, std::size_t> p = value;
    auto &b = p.first; 
    auto &count = p.second;
    std::cout 
        << b.country << " : " << count
        << " billionaires. Richest is "
        << b.name << " with " << b.dollars << " B$\n"; 
  }

  return 0;
}
