#ifndef TOP_H
#define TOP_H

#include"systemc.h"
#include"initiator.h"
#include"target.h"


/////
#include"initiator_2.h"
#include"target_2.h"


#include"string.h"

#include"tlm.h"
//using namespace sc_core;


// struct top :sc_module
SC_MODULE(top)
{
	initiator* init;
	target* targ;

	initiator_two* init2;
	target_two* targ2;



	//sc_time =delay(10, SC_NS);
	//instantiating the clock
	sc_clock clk;
	//sc_clock clk("clk", 10, 0.5, SC_ZERO_TIME, true);
  // sc_clock clk("clk",delay,0.5);
  // sc_clock("clk");
	

	//SC_CTOR(top)

	SC_HAS_PROCESS(top);
	top(sc_module_name nm) :sc_module(nm),clk("clk", 10, SC_NS, 0.5)

	{

		init = new initiator("init");
		targ = new target("targ");

		init->i_socket.bind(targ->t_socket);
		init->i_clk(clk);
	//	targ->t_clk(clk);


		////defining for 2nd module//////


		init2 = new initiator_two("init");
		targ2 = new target_two("targ");



		init2->i2_socket.bind(targ2->t2_socket);
		init2->i2_clk(clk);
//		targ2->t2_clk(clk);



		std::cout << "clk defined" << std::endl;
	}


//	sc_trace_file* tf = sc_create_vcd_trace_file("b_transport");
//	sc_trace(tf, clk, "clk");

};
#endif