#include <iostream>
#include <systemc>

SC_MODULE(counter)
{
 public:
  sc_core::sc_in_clk clk;
  sc_core::sc_in<bool> en;
  sc_core::sc_in<bool> reset;

  sc_core::sc_out<sc_dt::sc_uint<4> > q;

  SC_HAS_PROCESS(counter);
  counter(sc_core::sc_module_name n);
 protected:
  //signals
  sc_dt::sc_uint<4> count_sig;
  void do_process();
};

counter::counter(sc_core::sc_module_name n)
  :sc_module(n)
{
  SC_METHOD(do_process);
  sensitive<<reset<<clk.pos();
}

void counter::do_process()
{
  if (reset.read() == 1)
    {
      count_sig = 0;
      q.write(count_sig);
    } else if (en.read() == 1){
    count_sig = count_sig + 1;//ovde je sve ok ali ne radi increment
    //count_sig = count_sig + 1; //ako ovo vazi onda vraca gresku da nije dobro preklopljen operator
    q.write(count_sig);
  }
}
