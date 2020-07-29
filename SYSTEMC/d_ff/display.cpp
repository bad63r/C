#include "display.hpp"

void display::watchthemall()
{
  std::cout<<"@ "<<sc_core::sc_time_stamp()<<" q is "<<q.read()<<std::endl;


}
