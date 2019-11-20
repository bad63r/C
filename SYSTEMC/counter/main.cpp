#include "display.hpp"
#include "counter_stim.hpp"
#include "counter.hpp"

int sc_main(int argc, char* argv[])
{
  sc_core::sc_signal<sc_dt::sc_logic> CLK;
  sc_core::sc_signal<sc_dt::sc_logic> RESET;
  sc_core::sc_signal<sc_dt::sc_logic> EN;
  sc_core::sc_signal<sc_dt::sc_logic> PULSE;
  sc_core::sc_signal<sc_dt::sc_uint<4> > Q;

  sc_core::sc_clock CLOCK("clock", 20, sc_core::SC_NS);

  counter u_counter("counter");
  u_counter.clk(CLK);
  u_counter.reset(RESET);
  u_counter.en(EN);
  u_counter.pulse(PULSE);
  u_counter.q(Q);

  counter_stim u_counter_stim("counter_stim");
  u_counter_stim.reset(RESET);
  u_counter_stim.en(EN);
  u_counter_stim.pulse(PULSE);
  u_counter_stim.clk(CLK);
 
  display u_display("display");
  u_display.q(Q);

  sc_core::sc_trace_file *wf = sc_core::sc_create_vcd_trace_file("counter_vcd");
  sc_core::sc_trace(wf, u_counter.clk, "clk");
  sc_core::sc_trace(wf, u_counter.reset, "reset");
  sc_core::sc_trace(wf, u_counter.en, "en");
  sc_core::sc_trace(wf, u_counter.pulse, "pulse");
  sc_core::sc_trace(wf, u_counter.q, "q");

  sc_start(300, sc_core::SC_NS);

  sc_core::sc_close_vcd_trace_file(wf);

  return 0;
}
