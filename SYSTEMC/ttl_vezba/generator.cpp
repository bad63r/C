#include "generator.hpp"
#include <tlm_utils/tlm_quantumkeeper.h>

using namespace sc_core;
using namespace sc_dt;
using namespace tlm;

SC_HAS_PROCESS(generator);

generator::generator(sc_module_name name) :
	sc_module(name),
	isoc("isoc"),
	dmi_valid(false)
{
	SC_THREAD(gen);
	isoc(*this);
}


void generator::gen()
{
	tlm_generic_payload pl;
	sc_time offset = SC_ZERO_TIME;
	unsigned char buf[4];

	// This is used only for debugging
	unsigned char dbg_buf[10000];
	tlm_generic_payload dbg_pl;
	dbg_pl.set_data_ptr(dbg_buf);
	dbg_pl.set_command(TLM_READ_COMMAND);

	// Init first 20 locations to FF with DMI access
	tlm_dmi dmi;
	dmi_valid = isoc->get_direct_mem_ptr(pl, dmi);
	if (dmi_valid)
	{
		dmi_mem = dmi.get_dmi_ptr();
    float* fl_ptr = reinterpret_cast<float*>(dmi_mem); //ovo sam ja pisao
		for (int i = 0; i != 20; ++i)
			fl_ptr[i] = 12.7;
    //dmi_mem[i] = 0xFF;
	}

	#ifdef QUANTUM
	tlm_utils::tlm_quantumkeeper qk;
	qk.reset();
	#endif

	// Normal TLM transport interface.
	for (unsigned int i = 0; i != 24; ++i)
	{
		unsigned int data_length = 4;
		unsigned int addr = rand() % 200;
		tlm_command cmd = i < 20 ? TLM_WRITE_COMMAND : TLM_READ_COMMAND;
		std::string msg = cmd == TLM_WRITE_COMMAND ? "Write " : "Read  ";

    //OK, so whene you you want to write with regular mode into array, you should know that float value is 4 byte
    //and unsigned char is 1 byte. To be able to write float to unsigned char array, you must cast unsigned char array
    //to char array.
    float* buf_fl = reinterpret_cast<float*>(buf);

    buf_fl[0]=555.23;

    
		pl.set_command         ( TLM_WRITE_COMMAND       );
		pl.set_address         ( 8                     );//targeting ram[2]
		pl.set_data_ptr        (buf );
		pl.set_data_length     ( 4                       );
		pl.set_response_status ( TLM_INCOMPLETE_RESPONSE );


		 isoc->b_transport(pl, offset);


     buf_fl[0]=777.23;
     pl.set_command         ( TLM_WRITE_COMMAND       );
     pl.set_address         ( 20                      );//targeting ram[5]
     pl.set_data_ptr        (buf );
     pl.set_data_length     ( 4                       );
     pl.set_response_status ( TLM_INCOMPLETE_RESPONSE );
		 isoc->b_transport(pl, offset);


     buf_fl[0]=654.321;
     pl.set_command         ( TLM_WRITE_COMMAND       );
     pl.set_address         ( 796                      );//targeting ram[199]
     pl.set_data_ptr        (buf );
     pl.set_data_length     ( 4                       );
     pl.set_response_status ( TLM_INCOMPLETE_RESPONSE );
		 isoc->b_transport(pl, offset);




		 /* Print debugging information using method call for debugging
		  purpose.
		 */
		isoc->transport_dbg(dbg_pl);
		msg = " RAM at time " + sc_time_stamp().to_string();
		msg += "\n";
    unsigned char *moj_p;
    moj_p = dbg_pl.get_data_ptr();
    float* moj_p_fl = reinterpret_cast<float*>(moj_p);
    std::cout << "it was written: "<<std::endl;

    std::cout<<"teting location 2 and 199: "<<moj_p_fl[2]<<"  "<<moj_p_fl[199]<<std::endl;

		// for (int i = 0; i != 200; ++i)
		// {
		// 	msg += std::to_string(moj_p_fl[i]);
		// 	msg += " ";
		// }
		SC_REPORT_INFO("generator", msg.c_str());
	}
}

tlm_sync_enum generator::nb_transport_bw(pl_t& pl, phase_t& phase, sc_time& offset)
{
	return TLM_ACCEPTED;
}

void generator::invalidate_direct_mem_ptr(uint64 start, uint64 end)
{
	dmi_valid = false;
}
