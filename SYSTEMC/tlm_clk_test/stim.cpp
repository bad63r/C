#include "stim.hpp"

void stim::stimgen()
{
  int i;
  std::cout<<name()<<" Starting simulation...\n";

  

  for (i=0;i<8;i++) {
    clk = 0;
    wait(10, sc_core::SC_NS);
    std::cout<<"@ "<< sc_core::sc_time_stamp()<<" clk is "<<clk.read()<<std::endl;
    clk = 1;
    wait(10, sc_core::SC_NS);
    std::cout<<"@ "<< sc_core::sc_time_stamp()<<" clk is "<<clk.read()<<std::endl;
  }

  wait(1,sc_core::SC_NS);
}
