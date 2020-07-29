#include "memory.hpp"

using namespace sc_core;
using namespace tlm;
using namespace sc_dt;


SC_HAS_PROCESS(memory);
memory::memory(sc_module_name name) :
	sc_module(name),
	tsoc("tsoc"),
	m_peq(this, &memory::cb_peq),
	resp_in_progess(false)
{
	tsoc(*this);
	for (int i = 0; i != RAM_SIZE; ++i){
		ram[i] = 0;
  }


}

void memory::b_transport(pl_t& pl, sc_time& delay)
{

}

tlm_sync_enum memory::nb_transport_fw(pl_t& pl, phase_t& phase, sc_time& delay)
{
	m_peq.notify(pl, phase, delay);
	pl.set_response_status(TLM_OK_RESPONSE);
	return TLM_ACCEPTED;
}

void memory::cb_peq(tlm_generic_payload& pl, const tlm_phase& phase)
{
	switch(phase)
	{
	case BEGIN_REQ:
	{

		tlm_command cmd    = pl.get_command();
		uint64 adr         = pl.get_address();
		unsigned char *buf = pl.get_data_ptr();
		unsigned int len   = pl.get_data_length();
		std::string msg;

		switch(cmd)
		{
		case TLM_WRITE_COMMAND:
			for (unsigned int i = 0; i != len; ++i)
				ram[adr++] = buf[i];
			msg = "Write ";
			break;
		case TLM_READ_COMMAND:
			for (unsigned int i = 0; i != len; ++i)
				buf[i] = ram[adr++];
			msg = "Read ";
			break;
		default:
			pl.set_response_status( TLM_COMMAND_ERROR_RESPONSE );
		}

		msg += " at time " + sc_time_stamp().to_string();
		msg += " to address " + std::to_string(adr) + " :\n";

        float* ram_fl = reinterpret_cast<float*>(ram);
		for (int i = 0; i != 200; i++)
		{
			msg += std::to_string(ram_fl[i]);
			msg += " ";
		}
    std::cout<<"IT IS WORKING 9: "<<ram_fl[9]<<std::endl;

		SC_REPORT_INFO("memory status", msg.c_str());

		sc_time delay(5, SC_NS);
		tlm_phase ret_phase = END_REQ;
		tlm_sync_enum rsp = tsoc->nb_transport_bw(pl, ret_phase, delay);

		assert(rsp == TLM_ACCEPTED);
		sc_time fw_delay(10, SC_NS);
		tlm_phase fw_phase = BEGIN_RESP;
		m_peq.notify(pl, fw_phase, fw_delay);

		break;

	}

	case BEGIN_RESP:
	{
		if(resp_in_progess)
			wait(resp_done);
		resp_in_progess = true;
		sc_time delay(3, SC_NS);
		tlm_phase fw_phase = BEGIN_RESP;
		tsoc->nb_transport_bw(pl, fw_phase, delay);
		break;
	}

	case END_RESP:
	{
		resp_in_progess = false;
		resp_done.notify();
		SC_REPORT_INFO("memory", "Transaction finished.");
		pl.release();
		break;
	}

	default:
		SC_REPORT_FATAL("memory", "Bad phase");
	}
}

bool memory::get_direct_mem_ptr(pl_t& pl, tlm_dmi& dmi)
{
	return false;
}

unsigned int memory::transport_dbg(pl_t& pl)
{
	return 0;
}


