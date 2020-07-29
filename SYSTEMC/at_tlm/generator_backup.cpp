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

    //writing table data into module
    //first transaction
		data_fl[0] = 1;
    addr = 0;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         ( 0                    );
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

    //second transaction

		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;


		data_fl[0] = 3;
    addr = 4/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         ( 4                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);

    //third transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;


		data_fl[0] = 5;
    addr = 8/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         ( 8                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);

    //forth transaction - indicate start of calculation
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 2.17;
    addr = 12/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (12                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);

    //5 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 7;
    addr = 16/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (16                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);

    //6 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 10;
    addr = 20/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (20                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //7 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 12;
    addr = 24/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (24                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //8 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 12.12;
    addr = 28/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (28                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //9 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 15;
    addr = 32/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (32                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //10 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 20;
    addr = 36/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (36                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //11 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 23;
    addr = 40/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (40                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //12 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 30;
    addr = 44/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (44                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //13 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 47;
    addr = 48/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (48                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //14 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 50;
    addr = 52/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (52                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //15 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 52;
    addr = 56/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (56                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //16 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 60;
    addr = 60/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (60                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //17 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 4;
    addr = 64/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (64                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //18 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 7;
    addr = 68/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (68                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //19 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 2;
    addr = 72/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (72                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //20 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 0.5;
    addr = 76/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (76                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //21 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 1;
    addr = 80/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (80                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //22 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 9;
    addr = 84/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (84                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);

    
    //23 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 2.61;
    addr = 88/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (88                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //24 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 2.9;
    addr = 92/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (92                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //25 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 3;
    addr = 96/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (96                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //26 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 7.43;
    addr = 100/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (100                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //27 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 12;
    addr = 104/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (104                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //28 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 14;
    addr = 108/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (108                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //29 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 16;
    addr = 112/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (112                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //30 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 18;
    addr = 116/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (116                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //31 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 20;
    addr = 120/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (120                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //32 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 22.2;
    addr = 124/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (124                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //33 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 4;
    addr = 128/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (128                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //34 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 7;
    addr = 132/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (132                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //35 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 9;
    addr = 136/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (136                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //36 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 3;
    addr = 140/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (140                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //37 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 0;
    addr = 144/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (144                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //38 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 6;
    addr = 148/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (148                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //39 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 7;
    addr = 152/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (152                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //40 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 1;
    addr = 156/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (156                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //41 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 4.4;
    addr = 160/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (160                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //42 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 3;
    addr = 164/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (164                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //43 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 1.97;
    addr = 168/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (168                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //44 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 10;
    addr = 172/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (172                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //45 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 15;
    addr = 176/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (176                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //46 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 20;
    addr = 180/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (180                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //47 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 25;
    addr = 184/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (184                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //48 transaction
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 30;
    addr = 188/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (188                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);

    //X axis
    //*****************

    // X input - 7.1
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 7.1;
    addr = 192/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (192                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    // X offset - 0
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 0;
    addr = 196/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (196                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    // X scaling factor - 0.3
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 0.3;
    addr = 200/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (200                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    // X max address - 3
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 3;
    addr = 204/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (204                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    // X num of elements - 4
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 4;
    addr = 208/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (208                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    //Y axis
    //**************
    // Y input - 6.2
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 6.2;
    addr = 212/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (212                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    // Y offset - 0
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 0;
    addr = 216/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (216                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    // Y scaling factor - 0.15
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 0.15;
    addr = 220/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (220                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    // Y max address - 3
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 3;
    addr = 224/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (224                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    // Y num of elements - 4
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 4;
    addr = 228/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (228                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    // Z axis
    //**********************

    // Z input - 3.3
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 3.3;
    addr = 232/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (232                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    // Z offset - -1
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = -1;
    addr = 236/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (236                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    // Z scaling factor - 0.66667
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 0.66667;
    addr = 240/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (240                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    // Z max address - 2
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 2;
    addr = 244/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (244                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);


    // Z num of elements - 3
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 3;
    addr = 248/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (248                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);

    // test
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 1;
    addr = 796/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (796                       );
		pl->set_data_length     ( 4                       );
		pl->set_response_status ( TLM_INCOMPLETE_RESPONSE );
		pl->acquire();

		plnum++;
		phase = BEGIN_REQ;
		msg = "Send " + std::to_string(plnum) + " payload to address " + std::to_string(addr);
		SC_REPORT_INFO("generator", msg.c_str());

		rsp = isoc->nb_transport_fw(*pl, phase, delay);

		assert(rsp == TLM_ACCEPTED && pl->get_response_status() == TLM_OK_RESPONSE);

    wait(20,sc_core::SC_NS);

    // put start on 0
		if(req_in_progess)
			wait(req_done);
		req_in_progess = true;

		data_fl[0] = 0;
    addr = 796/4;

		pl->set_command         ( TLM_WRITE_COMMAND       );
		pl->set_address         (796                       );
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
