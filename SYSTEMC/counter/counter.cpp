#include "counter.hpp"

void counter::do_process()
{
  if (reset.read() == 1)
    {
      count_val = 0;
    } else
    if (en.read() == 1){
      if (clk.event()){
        count_val = count_val + 1;
      }
  }
  q.write(count_val);
}
