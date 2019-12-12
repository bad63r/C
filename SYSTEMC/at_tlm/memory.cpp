#include "memory.hpp"
#include <cmath>

using namespace sc_core;
using namespace tlm;
using namespace sc_dt;

memory::memory(sc_module_name name) :
	sc_module(name),
	tsoc("tsoc"),
	m_peq(this, &memory::cb_peq),
	resp_in_progess(false)
{
	tsoc(*this);
	for (int i = 0; i != RAM_SIZE; ++i)
		ram[i] = 0;

  //my_code
  SC_THREAD(count);
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
      if (ram_fl[199] == 1){
        s0.notify();
      }
		}

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

//my code
void memory::count()
{
  float rezultat;
  float* ram_fl = reinterpret_cast<float*>(ram);
  //float x_in = ram_fl[48];

  wait(s0); //waiting for start = 1

  float x_in = ram_fl[48];
  float x_offset_in = ram_fl[49];
  float x_set;
  float x_samp_addr;
  float sf_x_in = ram_fl[50];
  float xN = ram_fl[52];
  float x_addr_down;
  float x_addr_up;
  float x_coef_interpolation;

  float y_in = ram_fl[53];
  float y_offset_in = ram_fl[54];
  float y_set;
  float y_samp_addr;
  float sf_y_in = ram_fl[55];
  float yN = ram_fl[57];
  float y_addr_down;
  float y_addr_up;
  float y_coef_interpolation;

  float z_in = ram_fl[58];
  float z_offset_in = ram_fl[59];
  float z_set;
  float z_samp_addr;
  float sf_z_in = ram_fl[60];
  float zN = ram_fl[62];
  float z_addr_down;
  float z_addr_up;
  float z_coef_interpolation;


  x_set = (x_in + x_offset_in);
  x_samp_addr = x_set * sf_x_in;


  if (x_samp_addr < 0){
    x_samp_addr = 0;
  }else if (x_samp_addr >= xN -1){
    x_samp_addr = xN - 1;}


  x_addr_down = floor(x_samp_addr);
  x_coef_interpolation = x_samp_addr - x_addr_down;
  if (x_coef_interpolation){
    x_addr_up = x_addr_down + 1;
  }else {
    x_addr_up = x_addr_down;
    x_coef_interpolation = 0;
        }

  if (x_coef_interpolation){
    x_addr_up = x_addr_down + 1;
  }else{
    x_addr_up = x_addr_down;
    x_coef_interpolation = 0;
  }
  std::cout<< "\nx_in: "<<x_in<<std::endl;
  std::cout<< "x_set: "<<x_set<<std::endl;
  std::cout<< "x_samp_addr: "<<x_samp_addr<<std::endl;
  std::cout<< "x_coef_interpolation je: "<<x_coef_interpolation<<std::endl;

//Y axis

y_set = (y_in + y_offset_in);
y_samp_addr = y_set * sf_y_in;


if (y_samp_addr < 0){
  y_samp_addr = 0;
 }else if (y_samp_addr >= yN -1){
  y_samp_addr = yN - 1;
 }

y_addr_down = floor(y_samp_addr);
y_coef_interpolation = y_samp_addr - y_addr_down;
if (y_coef_interpolation){
  y_addr_up = y_addr_down + 1;
 }else{
  y_addr_up = y_addr_down;
  y_coef_interpolation = 0;
 }

 std::cout<< "\ny_in: "<<y_in<<std::endl;
 std::cout<< "y_set: "<<y_set<<std::endl;
 std::cout<< "y_samp_addr: "<<y_samp_addr<<std::endl;
 std::cout<< "y_coef_interpolation je: "<<y_coef_interpolation<<std::endl;


 //Z axis
 z_set = (z_in + z_offset_in);
 z_samp_addr = z_set*sf_z_in;


 if (z_samp_addr < 0){
   z_samp_addr = 0;
 }else if (z_samp_addr >= zN -1){
   z_samp_addr = zN - 1;
 }

 z_addr_down = floor(z_samp_addr);
 z_coef_interpolation = z_samp_addr - z_addr_down;
 if (z_coef_interpolation){
   z_addr_up = z_addr_down + 1;
 }else{
   z_addr_up = z_addr_down;
   z_coef_interpolation = 0;
 }


 std::cout<< "\nz_in: "<<z_in<<std::endl;
 std::cout<< "z_set: "<<z_set<<std::endl;
 std::cout<< "z_samp_addr: "<<z_samp_addr<<std::endl;
 std::cout<< "z_coef_interpolation je: "<<z_coef_interpolation<<std::endl;


 std::cout<< "\nx_addr_down: "<<x_addr_down<<" x_addr_up: "<<x_addr_up<<std::endl;
 std::cout<< "\ny_addr_down: "<<y_addr_down<<" y_addr_up: "<<y_addr_up<<std::endl;
 std::cout<< "\nz_addr_down: "<<z_addr_down<<" z_addr_up: "<<z_addr_up<<std::endl;

 // Interpolation

 std::cout<<"DOING INTERPOLATION:\n"<<std::endl;

c100 = lut1D[int(x_addr_up) + int(y_addr_down*xN) + int(z_addr_down*yN*xN)]
c000 = lut1D[int(x_addr_down) + int(y_addr_down)*xN + int(z_addr_down)*yN*xN]
c101 = lut1D[int(x_addr_up) + int(y_addr_down*xN) + int(z_addr_up*yN*xN)]
c001 = lut1D[int(x_addr_down) + int(y_addr_down*xN) + int(z_addr_up*yN*xN)]
c110 = lut1D[int(x_addr_up) + int(y_addr_up*xN) + int(z_addr_down*yN*xN)]
c010 = lut1D[int(x_addr_down) + int(y_addr_up*xN) + int(z_addr_down*yN*xN)]
c111 = lut1D[int(x_addr_up) + int(y_addr_up*xN) + int(z_addr_up*yN*xN)]
c011 = lut1D[int(x_addr_down) + int(y_addr_up*xN) + int(z_addr_up*yN*xN)]

}




