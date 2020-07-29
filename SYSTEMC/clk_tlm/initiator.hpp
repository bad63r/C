#ifndef INITIATOR_H
#define INITIATOR_H

#include"systemc.h"


#define SC_INCLUDE_DYNAMIC_PROCESS

#include"tlm.h"
#include"tlm_utils/simple_initiator_socket.h"


struct initiator :sc_module
{
	tlm_utils::simple_initiator_socket<initiator> i_socket;

	///adding clock
	sc_in<bool>i_clk;
	//sc_in<int>i_clk;


	SC_CTOR(initiator) :i_socket("i_socket")
	{


		SC_THREAD(diff_process);
		
	//	sensitive << i_clk.pos();
		dont_initialize(); //this function stops the execution of the thread
		
	}


	/*
	SC_HAS_PROCESS(initiator);
	initiator::initiator(sc_module_name nm) :sc_module(nm), i_socket("isocket")
	{

	SC_THREAD(diff_process);


	}
	*/
	void diff_process()
	{
	//	while (1)
	//	{
		std::cout << "data getting initialised at i_clk" << std::endl;
			tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload; //declaring new space of memory along with a pointer
			sc_time delay = sc_time(10, SC_NS);

			for (int i = 0; i < 10; i++)
			{



				tlm::tlm_command cmd = static_cast<tlm::tlm_command>(rand() % 2);

				//	if (cmd == tlm::TLM_READ_COMMAND)
				//	data = i+10

				if (cmd == tlm::TLM_WRITE_COMMAND)
				{
					data = i;
					//	std::cout << "write command sent = " << cmd << std::endl;

				}

				trans->set_command(cmd);
				trans->set_address(i);
				//	trans->set_data(i);
				trans->set_data_ptr(reinterpret_cast<unsigned char*>(&data));
				trans->set_byte_enable_ptr(0);
				trans->set_data_length(4);
				trans->set_streaming_width(4);

				trans->set_dmi_allowed(false);
				trans->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

				//	std::cout <<"before sending..... "<< "cmd= " << (cmd ? 'W' : 'R') << "...data= " << data << "..time= " << sc_time_stamp() << std::endl;

				i_socket->b_transport(*trans, delay); ///passing a function & RETURNING BACK,arguments are payload and time

				std::cout << "cmd= " << (cmd ? 'W' : 'R') << "...data= " << data << "..time= " << sc_time_stamp() << "  delay= " << delay << std::endl;

				wait(delay);

			
			}
	//	}
	}

	int data;//act as buffer fo temperory storage

};
#endif