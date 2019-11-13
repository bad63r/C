//both .hpp and .cpp are in the same file bcs design is too small
#include <iostream>
#include <systemc>

//and_gate.hpp file
SC_MODULE(and_gate)
{
 public:
  sc_core::sc_in<bool> a;
  sc_core::sc_in<bool> b;
  sc_core::sc_out<bool> res;

  SC_HAS_PROCESS(and_gate);
  and_gate(sc_core::sc_module_name n);
 protected:
  void do_func();

};

//and_gate.cpp file

and_gate::and_gate(sc_core::sc_module_name n)
  :sc_module(n)
{

  SC_METHOD(do_func);
  sensitive<< a<<b;

}

void and_gate::do_func()
{
  res.write((a.read() && b.read()));
}




