#ifndef TARGET_2_H
#define TARGET_2_H

#include"systemc.h"




#include"tlm.h"
#include"tlm_utils/simple_target_socket.h"


struct target_two :sc_module
{
	tlm_utils::simple_target_socket<target_two> t2_socket;
	enum { size = 256 };
	int mem[256];

	///adding clock
//	sc_in<bool>t2_clk;
	//sc_in<int>t_clk;


	virtual void b_transport(tlm::tlm_generic_payload& trans, sc_time& delay)
	{

		//	i_socket->b_transport(*trans, delay);

		tlm::tlm_command cmd = trans.get_command();
		sc_dt::uint64 addr = trans.get_address();
		unsigned int len = trans.get_data_length();
		unsigned char* ptr = trans.get_data_ptr();
		unsigned int wid = trans.get_streaming_width();
		unsigned char* byt = trans.get_byte_enable_ptr();





		if (addr > sc_dt::uint64(size) || len < 4 || wid < len)
		{

			SC_REPORT_ERROR("error", "no response");

		}


		if (cmd == tlm::TLM_WRITE_COMMAND)
		{
			memcpy(&mem[addr], ptr, len);


		}


		if (cmd == tlm::TLM_READ_COMMAND)
		{
			memcpy(ptr, &mem[addr], len);


			trans.set_response_status(tlm::TLM_OK_RESPONSE);


		}

	}






	SC_CTOR(target_two) :t2_socket("t2_socket")
	{

		t2_socket.register_b_transport(this, &target_two::b_transport); //b_transport(     this    ,pointer to memb. function)


		for (int i = 0; i < 10; i++)
		{

			mem[i] = i;


		}

	//	sensitive << t2_clk;
	//	dont_initialize();
//		std::cout << "data getting initialised at t2_clk" << std::endl;

	}



	/*
	SC_HAS_PROCESS(target);
	target::target(sc_module_name nm) :sc_module(nm), t_socket("tsocket")
	{


	t_socket.register_b_transport(this, &target::b_transport);

	for (int i = 0; i < 10; i++)
	{

	mem[i] = i;


	}

	}
	*/




};
#endif