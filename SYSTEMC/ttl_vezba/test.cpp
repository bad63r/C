#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  float x = 13.2;

  unsigned char my_array[16];

  float* my_array_fl = reinterpret_cast<float*>(my_array);
  my_array_fl[0] = x;
  my_array_fl[1] = 137.2;
  my_array_fl[2] = 13.13;
  my_array_fl[3] = 63.2;
  my_array_fl[4] = 100.2;

  cout << "my_array_fl: "<<my_array_fl[4]<<endl;

  float* my_array_fl2= reinterpret_cast<float*>(my_array);

  cout << "I my array koje je preradjen je: : "<<my_array_fl2[17]<<endl;




  return 0;
}
