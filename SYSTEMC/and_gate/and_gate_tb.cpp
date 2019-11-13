#include <iostream>
#include <systemc>
#include "and_gate.cpp"

SC_MODULE(and_gate_tb)
{
 public:
  SC_HAS_PROCESS(and_gate_tb);
  and_gate_tb(sc_core::sc_module_name n);
 protected:
  //initialize design -- vhdl: component
  and_gate uut;
  //signals
  sc_core::sc_signal<bool> a;
  sc_core::sc_signal<bool> b;
  sc_core::sc_signal<bool> res;

  void driver();
  void monitor();

};

and_gate_tb::and_gate_tb(sc_core::sc_module_name n)
  //vhdl: port map
  :sc_module(n),uut("UUT")
{
  std::cout<<name()<<" counstructed.\n";
  uut.a(a);
  uut.b(b);
  uut.res(res);
  SC_THREAD(driver);
  SC_METHOD(monitor);
  sensitive<<a<<b<<res;
}

void and_gate_tb::driver()
{
  a.write(0);
  b.write(0);
  //std::cout<<"At "<<sc_core::sc_time_stamp()<<" inputs:"<<uut.a->read()<<uut.b->read()<<" output:"<<uut.res->read()<<std::endl;
  wait(5,sc_core::SC_NS);

  a.write(1);
  b.write(0);
  //std::cout<<"At "<<sc_core::sc_time_stamp()<<" inputs:"<<uut.a->read()<<uut.b->read()<<" output:"<<uut.res->read()<<std::endl;
  wait(5,sc_core::SC_NS);

  a.write(0);
  b.write(1);
  //std::cout<<"At "<<sc_core::sc_time_stamp()<<" inputs:"<<uut.a->read()<<uut.b->read()<<" output:"<<uut.res->read()<<std::endl;
  wait(5,sc_core::SC_NS);

  a.write(1);
  b.write(1);
  //std::cout<<"At "<<sc_core::sc_time_stamp()<<" inputs:"<<uut.a->read()<<uut.b->read()<<" output:"<<uut.res->read()<<std::endl;
  wait(5,sc_core::SC_NS);

}

void and_gate_tb::monitor()
{
  std::cout<<"At "<<sc_core::sc_time_stamp()<<" inputs:"<<uut.a->read()<<uut.b->read()<<" output:"<<uut.res->read()<<std::endl;
}

int sc_main(int argc, char* argv[])
{
  and_gate_tb tb("TB");
  sc_start(40, sc_core::SC_NS);

  return 0;


}
