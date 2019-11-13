#include <iostream>
#include <systemc>

#include "counter.cpp"

SC_MODULE(counter_tb)
{
 public:
  SC_HAS_PROCESS(counter_tb);
  counter_tb(sc_core::sc_module_name n);
 protected:
  //initialize design --vhdl: component
  counter uut;
  //signals
  sc_core::sc_signal<bool> clk;
  sc_core::sc_signal<bool> reset;
  sc_core::sc_signal<bool> en;
  sc_core::sc_signal<sc_dt::sc_uint<4>> q;

  void driver();
  void monitor();
};


counter_tb::counter_tb(sc_core::sc_module_name n)
  //vhdl: port map
  :sc_module(n), uut("UUT")
{
  std::cout<<name()<<" constructed.\n";
  uut.clk(clk);
  uut.reset(reset);
  uut.en(en);
  uut.q(q);

  SC_THREAD(driver);
  SC_METHOD(monitor);
  sensitive<<clk<<reset<<en<<q;
}


void counter_tb::driver()
{
  int i = 0;
  reset = 1;
  en = 1;
  for (i=0;i<5;i++) {
    clk = 0; 
    sc_start(1, sc_core::SC_NS);
    clk = 1; 
    sc_start(1, sc_core::SC_NS);
  }
  reset = 0;
  for (i=0;i<5;i++) {
    clk = 0; 
    sc_start(1, sc_core::SC_NS);
    clk = 1; 
    sc_start(1, sc_core::SC_NS);
  }

}

void counter_tb::monitor()
{
  std::cout<<"At "<<sc_core::sc_time_stamp()<<" clk:"<<uut.clk->read()<<" reset:"<<uut.reset->read()<<" en:"<<uut.en->read()<<" output:"<<uut.q->read()<<std::endl;
}

 
int sc_main(int argc, char* argv[])
{
  counter_tb tb("TB");
  sc_start(80, sc_core::SC_NS);

  return 0;


}







