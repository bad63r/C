#ifndef _D_FF_HPP_
#define _D_FF_HPP_

#include <iostream>
#include <systemc>

SC_MODULE(d_ff)
{
  //ports
    //in
  sc_core::sc_in<bool> clk; //ako stavim sc_clock onda se buni na clk.pos(),
  //kao ne postiji takav clan funkcije
  sc_core::sc_in<sc_dt::sc_logic> d;
    //out
  sc_core::sc_out<sc_dt::sc_logic> q;

  void put_inside();

  SC_CTOR(d_ff)
  {
    SC_METHOD(put_inside);
    sensitive<<clk.pos();
  }

};





#endif
