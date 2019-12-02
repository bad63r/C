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
    std::cout<<"dmi_mem addr:    "<<&dmi_mem<<std::endl;
    std::cout<<"dmi_mem_fl addr: "<<&dmi_mem_fl<<std::endl;

    dmi_mem_fl[0] = 1; //x_in
    dmi_mem_fl[1] = 2.2; //x_offset
    dmi_mem_fl[2] = 3.5; //sf_x_in
    dmi_mem_fl[3] = 44; //xN
    dmi_mem_fl[4] = 17.3; //y_in
    dmi_mem_fl[5] = 6; //y_offset
    // dmi_mem[6] = 7; //sf_y_in
    // dmi_mem[7] = 7; //yN
    // dmi_mem[8] = 7; //z_in
    // dmi_mem[9] = 7; //z_offset
    // dmi_mem[10] = 7; //sf_z_in
    // dmi_mem[11] = 1.23; //zN
	}


	#ifdef QUANTUM
	tlm_utils::tlm_quantumkeeper qk;
	qk.reset();
	#endif

	// Normal TLM transport interface.
	for (unsigned int i = 0; i != 40; ++i)
	{
		unsigned int data_length = 1 + rand() % 4;
		unsigned int addr = rand() % 200;
		tlm_command cmd = i < 20 ? TLM_WRITE_COMMAND : TLM_READ_COMMAND;
		std::string msg = cmd == TLM_WRITE_COMMAND ? "Write " : "Read  ";
		if (cmd == TLM_WRITE_COMMAND)
			for (unsigned i = 0; i != data_length; ++i)
			{
				buf[i] = rand() % 100;
				msg += std::to_string(buf[i]);
				msg += " ";
			}
		msg += "- address ";
		msg += std::to_string(addr);
		msg += " ";

		pl.set_command         ( cmd                     );
		pl.set_address         ( addr                    );
		pl.set_data_ptr        ( buf                     );
		pl.set_data_length     ( data_length             );
		pl.set_response_status ( TLM_INCOMPLETE_RESPONSE );

		#ifdef QUANTUM
		qk.inc(sc_time(4, SC_NS));
		offset = qk.get_local_time();
		#else
		offset += sc_time(4, SC_NS);
		#endif

		isoc->b_transport(pl, offset);
		if (cmd == TLM_READ_COMMAND)
			for (unsigned i = 0; i != data_length; ++i)
			{
				msg += std::to_string(buf[i]);
				msg += " ";
			}
		SC_REPORT_INFO("generator", msg.c_str());

		#ifdef QUANTUM
		qk.set_and_sync(offset);
		#endif

		/*
		  Print debugging information using method call for debugging
		  purpose.
		 */
		isoc->transport_dbg(dbg_pl);
		msg = " RAM at time " + sc_time_stamp().to_string();
		msg += "\n";
    float* test = reinterpret_cast<float*>(dbg_pl.get_data_ptr());
    std::cout<<"broj od char: "<<sizeof(dbg_pl.get_data_ptr()[1])<<std::endl;
    std::cout<<"broj od floata: "<<sizeof(test[1])<<std::endl;
		for (int i = 0; i != 200; ++i)
		{

			msg += std::to_string(test[i]);
			msg += " ";
		}
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
