#ifndef _D_FF_STIM_HPP_
#define _D_FF_STIM_HPP_

#include <iostream>
#include <systemc>

SC_MODULE(d_ff_stim)
{
  //ports
  sc_core::sc_out<bool> clk;
  sc_core::sc_out<sc_dt::sc_logic> d;

  void stimgen();

  SC_CTOR(d_ff_stim)
  {
    SC_THREAD(stimgen);
  }
};



#endif
