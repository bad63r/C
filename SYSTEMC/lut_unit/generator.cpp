#include "generator.hpp"

using namespace sc_core;
using namespace sc_dt;
using namespace tlm;

SC_HAS_PROCESS(generator);

generator::generator(sc_module_name name) :
	sc_module(name),
	isoc("isoc"),
	req_in_progess(false),
	m_peq(this, &generator::cb_peq)
{
	SC_THREAD(gen);
	isoc(*this);
}


void generator::gen()
{
	phase_t phase;
	sc_time delay = sc_time(4, SC_NS);
	tlm_sync_enum rsp;
	unsigned plnum = 0;
  std::string msg;

  //unsigned int data_length = 3;
  unsigned int addr;

		pl_t* pl = mm.alloc();
		unsigned char* data = pl->get_data_ptr();
    float* data_fl = reinterpret_cast<float*>(data);


    float my_lut[48] = {1, 3, 5, 2.17, 7,10,12, 12.12, 15, 20, 23, 30, 47, 50, 52, 60,4, 7, 2, 0.5, 1, 9, 2.61, 2.9, 3, 7.43, 12, 14, 16, 18, 20, 22.2,4,7,9,3,0,6,7,1,4.4,3,1.97,10,15,20,25,30};

    for (int i = 0; i<48;++i)
      {
        if(req_in_progess)
          wait(req_done);
        req_in_progess = true;

        data_fl[0] = my_lut[i];
        addr = i*4;
        std::cout << "i: "<<i<<std::endl;
        std::cout << "lut[i]: "<<my_lut[i]<<std::endl;

        pl->set_command         ( TLM_WRITE_COMMAND       );
        pl->set_address         ( addr                       );
        pl->set_data_length     ( 4                       );
        pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
        pl->acquire();


        plnum++;
        phase = BEGIN_REQ;
        msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
        SC_REPORT_INFO("generator", msg.c_str());

        rsp = isoc->nb_transport_fw(*pl, phase, delay);

        assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);
      }

    /*x input, x_offset, x_scaling_factor, x_max_address, x_no_of_elem,... same goes for y and z axis */
    float lut_config[15] = {7.1, 0, 0.3, 3, 4, 6.2, 0, 0.15, 3, 4, 3.3, -1, 0.66667,0, 3};
    for (int c = 48; c<63;c++)
      {
        if(req_in_progess)
          wait(req_done);
        req_in_progess = true;

        data_fl[0] = lut_config[c-48];
        addr = c*4;

        pl->set_command         ( TLM_WRITE_COMMAND       );
        pl->set_address         ( addr                       );
        pl->set_data_length     ( 4                       );
        pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
        pl->acquire();


        plnum++;
        phase = BEGIN_REQ;
        msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
        SC_REPORT_INFO("generator", msg.c_str());

        rsp = isoc->nb_transport_fw(*pl, phase, delay);

        assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);
      }


    //start je 1/0

    unsigned char start_array[2] = {1,0};
    for(int s = 0;s<2;s++)
      {
        if(req_in_progess)
          wait(req_done);
        req_in_progess = true;

        data[0] = start_array[s];
        addr = 796;

        pl->set_command         ( TLM_WRITE_COMMAND       );
        pl->set_address         ( addr                       );
        pl->set_data_length     ( 1                       );
        pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
        pl->acquire();


        plnum++;
        phase = BEGIN_REQ;
        msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
        SC_REPORT_INFO("generator", msg.c_str());

        rsp = isoc->nb_transport_fw(*pl, phase, delay);

        assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);

        wait(20,sc_core::SC_NS);
      }


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
