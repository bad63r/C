#include "d_ff.hpp"
#include "d_ff_stim.hpp"
#include "display.hpp"

int sc_main(int argc, char* argv[])
{
  //signals
  sc_core::sc_signal<bool> CLK;
  sc_core::sc_signal<sc_dt::sc_logic> D;
  sc_core::sc_signal<sc_dt::sc_logic> Q;


  //instances of modules

  d_ff u_d_ff("u_d_ff");
  u_d_ff.clk(CLK);
  u_d_ff.d(D);
  u_d_ff.q(Q);
  
  d_ff_stim u_d_ff_stim("d_ff_stim");
  u_d_ff_stim.clk(CLK);
  u_d_ff_stim.d(D);

  display u_display("u_display");
  u_display.q(Q);


  sc_core::sc_trace_file *wf = sc_core::sc_create_vcd_trace_file("d_ff_vcd");
  sc_core::sc_trace(wf, u_d_ff.clk, "clk");
  sc_core::sc_trace(wf, u_d_ff.d, "d");
  sc_core::sc_trace(wf, u_d_ff.q, "q");

  sc_start(30, sc_core::SC_NS);

  sc_core::sc_close_vcd_trace_file(wf);
  return 0;
}
