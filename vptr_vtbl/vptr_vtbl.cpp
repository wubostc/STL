// compiling with 64bit
// sizeof(ptr) is 8
#include <iostream>

class A{
  virtual void test(){
    std::cout << "A::test" << std::endl;
  };
  virtual void test2(){
    std::cout << "A::test2" << std::endl;
  };
public:
  void print() const {
    // a = 10;
    std::cout << a << std::endl; 
  }
private: 
  int a;
};


class B{
  std::uint32_t a;
};

class C{
  void f1(){}
  void f2(){}
  void f3(){}
  std::uint32_t a;
  std::uint32_t b;
public:
  void print() const {
    std::cout << "a: " << std::dec << a << std::endl;
    std::cout << "b: " << std::dec << b << std::endl;
  }

  void ch() const {
   *((std::uint32_t *)this + 1) = 999;
  }
};

int main(){
  A a;
  std::cout << "sizeof(a): " << sizeof(a) << std::endl;

  std::cout << "object address: " << (std::uint64_t *)&a << std::endl;
  std::cout << "vptr address: " << (std::uint64_t *)&a + 0 << std::endl;
  std::cout << "vptr value: " << std::hex << /*(void *)*/*((std::uint64_t *)&a + 0) << std::endl;
  std::cout << "vtbl address: " << std::hex << (std::uint64_t *)*((std::uint64_t *)&a + 0) << std::endl;
  
  typedef void (*PF)();

  PF p = (PF)*((std::uint64_t *)*((std::uint64_t *)&a + 0) + 0);
  p(); // output: A::test
  PF p2 = (PF)*((std::uint64_t *)*((std::uint64_t *)&a + 0) + 1);
  p2(); // output: A::test2


  B b;
  std::cout << "sizeof(b): " << sizeof(b) << std::endl;
  C c;
  std::cout << "sizeof(c): " << sizeof(c) << std::endl;
  

  *((std::uint32_t *)&c + 0) = 10;
  *((std::uint32_t *)&c + 1) = 330;
  c.print();
  

  std::cout << "b will be change in func const\n";
  c.ch();
  c.print();
}
