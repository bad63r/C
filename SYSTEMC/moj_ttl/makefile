all: f2
f2:  main.cpp generator.cpp memory.cpp 
	g++ -I${SYSTEMC}/include -L${SYSTEMC}/lib-linux64 -lsystemc -o f2 main.cpp generator.cpp memory 

.PHONY: clean
clean:
	rm f2_*
