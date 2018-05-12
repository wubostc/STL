// compiling with 64bit
//
#include <iostream>
#include <memory>
#include <assert.h>

class Base{
  virtual void vfunc1(){
    std::cout << "Base::vfunc1" << std::endl;
  };
  virtual void vfunc2(){
    std::cout << "Base::vfunc2" << std::endl;
  };
  int a;
public:
  virtual ~Base(){
    std::cout << "Base::~Base" << std::endl;
  }
};


class DerivedA: public Base{
  virtual void vfunc1(){
    std::cout << "DerivedA::vfunc1" << std::endl;
  }
public:
  virtual ~DerivedA(){
    std::cout << "DerivedA::~DerivedA" << std::endl;
  }
};



int main(){
  Base *pbase = new Base();

  std::cout << "sizeof(*pbase): " << sizeof(Base) << std::endl;

  typedef void (*PF)();
  
  PF pf1 = (PF)*((std::uint64_t *)*(std::uint64_t *)pbase + 0);
  pf1();

  PF pf2 = (PF)*((std::uint64_t *)*(std::uint64_t *)pbase + 1);
  pf2();
  
  delete pbase;


  Base *pa = new DerivedA();
  std::cout << "sizeof(*pa): " << sizeof(*pa) << std::endl;

  PF paf = (PF)*((std::uint64_t *)*(std::uint64_t *)pa + 0);

  paf();

  delete pa;



}
