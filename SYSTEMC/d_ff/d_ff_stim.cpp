#include "d_ff_stim.hpp"

void d_ff_stim::stimgen()
{
  int i;
  std::cout<<"@ "<<sc_core::sc_time_stamp()<<" Starting simulation... "<<std::endl;

  for(i=0;i<5;i++)
    {
      clk = 0;
      wait(1,sc_core::SC_NS);
      std::cout<<"@ "<<sc_core::sc_time_stamp()<<" clk: "<<clk.read()<<std::endl;
      clk = 1;
      std::cout<<"@ "<<sc_core::sc_time_stamp()<<" clk: "<<clk.read()<<std::endl;
      wait(1,sc_core::SC_NS);
    }

  d = sc_dt::sc_logic(1);
  std::cout<<"@ "<<sc_core::sc_time_stamp()<<" d: "<<d.read()<<std::endl;


  for(i=0;i<2;i++)
    {
      clk = 0;
      wait(1,sc_core::SC_NS);
      std::cout<<"@ "<<sc_core::sc_time_stamp()<<" clk: "<<clk.read()<<std::endl;
      clk = 1;
      std::cout<<"@ "<<sc_core::sc_time_stamp()<<" clk: "<<clk.read()<<std::endl;
      wait(1,sc_core::SC_NS);
    }

}
