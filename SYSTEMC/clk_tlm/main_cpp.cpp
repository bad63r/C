#include"systemc.h"

#include"systemc.h"
//#include"initiator.h"
//#include"target.h"
#include"top.h"

//#include"top.h"

int sc_main(int agrc, char* argv[])
{
	top t("t");


//	sc_start(100,SC_NS);

	sc_start();

	return 0;
}

int main(int argc, char* argv[])
{
	int scresult = sc_core::sc_elab_and_sim(argc, argv);
	getchar();
	return 0;
}