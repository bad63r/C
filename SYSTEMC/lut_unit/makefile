all: f2
f2:  main.cpp lut.cpp generator.cpp mem_manager.cpp
	g++ -I${SYSTEMC}/include -L${SYSTEMC}/lib-linux64 -lsystemc -o f2 main.cpp lut.cpp generator.cpp mem_manager.cpp

.PHONY: clean
clean:
	rm f2_*
