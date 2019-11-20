#ifndef _COUNTER_STIM_HPP_
#define _COUNTER_STIM_HPP_

#include <iostream>
#include <systemc>

SC_MODULE(counter_stim)
{
  //ports
  sc_core::sc_out<sc_dt::sc_logic> en;
  sc_core::sc_out<sc_dt::sc_logic> reset;
  sc_core::sc_out<sc_dt::sc_logic> clk;

  void stimgen();

  SC_CTOR(counter_stim)
  {
    SC_THREAD(stimgen);
    sensitive<<clk.pos();
  }


};

#endif
