#include "counter_stim.hpp"

void counter_stim::stimgen()
{
  int i;
  std::cout<<name()<<" Starting simulation...\n";

  reset = sc_dt::sc_logic(1);

  en = sc_dt::sc_logic(1);
  std::cout<<"@ "<<sc_core::sc_time_stamp<<" reset = 1, en = 1"<<std::endl;
  wait(1,sc_core::SC_NS);

  for (i=0;i<8;i++) {
    clk = sc_dt::sc_logic(0);
    wait(1, sc_core::SC_NS);
    std::cout<<"@ "<< sc_core::sc_time_stamp()<<" clk is "<<clk.read()<<std::endl;
    clk = sc_dt::sc_logic(1);
    wait(1, sc_core::SC_NS);
    std::cout<<"@ "<< sc_core::sc_time_stamp()<<" clk is "<<clk.read()<<std::endl;
  }

  wait(1,sc_core::SC_NS);
  reset = sc_dt::sc_logic(0);
  std::cout<<"@ "<<sc_core::sc_time_stamp()<<" reset = 0"<<std::endl;

  for (i=0;i<8;i++) {
    clk = sc_dt::sc_logic(0);
    wait(1, sc_core::SC_NS);
    std::cout<<"@ "<< sc_core::sc_time_stamp()<<" clk is "<<clk.read()<<std::endl;
    clk = sc_dt::sc_logic(1);
    wait(1, sc_core::SC_NS);
    std::cout<<"@ "<< sc_core::sc_time_stamp()<<" clk is "<<clk.read()<<std::endl;
  }
  std::cout<<"@"<<sc_core::sc_time_stamp()<<std::endl;
  wait(10,sc_core::SC_NS);
  wait(10,sc_core::SC_NS);
  
}
