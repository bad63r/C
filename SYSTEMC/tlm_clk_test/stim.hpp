#ifndef _STIM_HPP_
#define _STIM_HPP_

#include <iostream>
#include <systemc>

SC_MODULE(stim)
{
  //ports
  sc_core::sc_out<bool> clk;

  void stimgen();

  SC_CTOR(stim)
  {
    SC_THREAD(stimgen);
  }


};

#endif
