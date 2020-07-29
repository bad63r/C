#ifndef INITIATOR_2_H
#define INITIATOR_2_H

#include"systemc.h"


#define SC_INCLUDE_DYNAMIC_PROCESS

#include"tlm.h"
#include"tlm_utils/simple_initiator_socket.h"


struct initiator_two :sc_module
{
	tlm_utils::simple_initiator_socket<initiator_two> i2_socket;

	///adding clock
	sc_in<bool>i2_clk;
	//sc_in<int>i_clk;


	SC_CTOR(initiator_two) :i2_socket("i2_socket")
	{

	//	wait(10, SC_NS);
		SC_THREAD(diff2_process);
		sensitive << i2_clk.pos();
		dont_initialize(); //this funcion stops the execution of thread
		
	}


	/*
	SC_HAS_PROCESS(initiator);
	initiator::initiator(sc_module_name nm) :sc_module(nm), i_socket("isocket")
	{

	SC_THREAD(diff_process);


	}
	*/
	void diff2_process()
	{
			wait(100, SC_NS);
//		while (1)
//		{
			std::cout << "data getting initialised at i2_clk" << std::endl;
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

				i2_socket->b_transport(*trans, delay); ///passing a function & RETURNING BACK,arguments are payload and time
			//	std::cout << "\n" << std::endl;
			//	std::cout << "\n" << std::endl;
			//	std::cout << "\n" << std::endl;

			//	std::cout << "......................new operation........................................." << std::endl;
				std::cout << "2nd stage cmd= " << (cmd ? 'W' : 'R') << "...data= " << data << "..time= " << sc_time_stamp() << "  delay= " << delay << std::endl;

				wait(100, SC_NS);//changed the delay

			}

		}
//	}
	int data; 

};
#endif
