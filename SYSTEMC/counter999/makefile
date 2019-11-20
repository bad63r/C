all: f2
f2:  main.cpp counter.cpp counter_stim.cpp display.cpp
	g++ -std=c++11 -I /home/bad63r/${SYSTEMC}/include -L${SYSTEMC}/lib-linux64 -lsystemc-2.3.0 -o f2 main.cpp counter.cpp counter_stim.cpp display.cpp

.PHONY: clean
clean:
	rm f2_*
