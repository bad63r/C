#ifndef _COUNTER_HPP_
#define _COUNTER_HPP_

#include <iostream>
#include <systemc>

SC_MODULE(counter)
{
  //inputs
  sc_core::sc_in<sc_dt::sc_logic> clk;
  sc_core::sc_in<sc_dt::sc_logic> en;
  sc_core::sc_in<sc_dt::sc_logic> reset;
  sc_core::sc_in<sc_dt::sc_logic> pulse;
  //outputs
  sc_core::sc_out<sc_dt::sc_uint<4> > q;


  //variables
  sc_dt::sc_uint<4> count_val;


  void do_process();

  SC_CTOR(counter){
    SC_METHOD(do_process);
    sensitive<<reset<<clk.pos();
  }
};

#endif
