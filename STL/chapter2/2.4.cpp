#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

int main(){
  vector<string> v{"some", "random", "words", "without", "order", "aaa", "yyy"};
  assert(!is_sorted(begin(v), end(v)));

  sort(begin(v), end(v));
}
