#include <systemc>
#include "generator.hpp"
#include "lut.hpp"
//#include "stim.hpp"

using namespace sc_core;
using namespace tlm;

int sc_main(int argc, char* argv[])
{
  //sc_core::sc_signal<bool> CLK;
	lut lookup ("3d");
	generator gen("generator_u");
  //stim sti("stimulus");
	gen.isoc(lookup.tsoc);

  //sti.clk(CLK);
  //lookup.clk(CLK);

	sc_start(320, SC_NS);
    return 0;
}
