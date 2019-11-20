#include "display.hpp"

void display::watchthemall()
{
  std::cout<<"@ "<<sc_core::sc_time_stamp()<<" q is "<<q.read()<<" q2 is "<<q2.read()<<" q3 is "<<q3.read()<<std::endl;


}
