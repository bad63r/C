#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <iostream>
#include <systemc>

SC_MODULE(display)
{
  //input
  sc_core::sc_in<sc_dt::sc_logic> q;

  void watchthemall();

  SC_CTOR(display)
  {
    SC_METHOD(watchthemall);
    sensitive<<q;
  }
};

#endif
