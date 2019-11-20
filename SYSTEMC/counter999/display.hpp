#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <iostream>
#include <systemc>

SC_MODULE(display)
{
  //input
  sc_core::sc_in<sc_dt::sc_uint<4> > q;
  sc_core::sc_in<sc_dt::sc_uint<4> > q2;
  sc_core::sc_in<sc_dt::sc_uint<4> > q3;

  void watchthemall();

  SC_CTOR(display)
  {
    SC_METHOD(watchthemall);
    sensitive<<q<<q2<<q3;
  }
};

#endif
