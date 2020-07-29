#include "generator.hpp"

using namespace sc_core;
using namespace sc_dt;
using namespace tlm;

//SC_HAS_PROCESS(generator);

generator::generator(sc_module_name name) :
	sc_module(name),
	isoc("isoc"),
	req_in_progess(false),
	m_peq(this, &generator::cb_peq)
{
	isoc(*this);
}


void generator::gen()
{
	phase_t phase;
	sc_time delay = sc_time(4, SC_NS);
	tlm_sync_enum rsp;
	unsigned plnum = 0;
  std::string msg;

		unsigned int addr = 9;

		pl_t* pl = mm.alloc();
		unsigned char* data = pl->get_data_ptr();

      float* data_fl = reinterpret_cast<float*>(data);


      data_fl[0] = 188.43;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         ( 36                      );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


		addr = 199;
    data_fl[0] = 402.3;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         ( 796                      );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);

}

tlm_sync_enum generator::nb_transport_bw(pl_t& pl, phase_t& phase, sc_time& delay)
{
	assert(phase == END_REQ || phase == BEGIN_RESP);
	m_peq.notify(pl, phase);

	return TLM_ACCEPTED;
}

void generator::cb_peq(tlm_generic_payload& pl, const tlm_phase& phase)
{
	switch(phase)
	{
	case END_REQ:
	{
		SC_REPORT_INFO("generator", "Request accepted.");
		req_in_progess = false;
		req_done.notify();
		return;
	}
	case BEGIN_RESP:
	{
		tlm_phase ret_phase = END_RESP;
		sc_time delay(1, SC_NS);
		isoc->nb_transport_fw(pl, ret_phase, delay);
		return;
	}
	default:
		SC_REPORT_FATAL("generator", "Bad phase");
	}
}

void generator::invalidate_direct_mem_ptr(uint64 start, uint64 end)
{

}
