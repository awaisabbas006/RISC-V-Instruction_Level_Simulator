#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "global_variable.h"
#include "mem_init.h"
using namespace std;

ofstream dumpsim_file("sim_out.txt", ofstream::out);

System_Memories mem;

void initialize (vector<string>user_input, int argc){

    init_mem init_mem;
    init_mem.memory_initialize(mem);                  // initialize the instruction and data memory to known value
    init_mem.load_program(user_input,mem,argc);       // load machine code/instruction to instruction memory
}
int main(int argc, char* argv[]) {
	cout << "================================================" << endl << "\t\t"
		<< "RISC-V Simulator" << endl << "================================================" << endl;
	vector<string>user_input;
	if (argc > 1) {
        user_input.assign(argv + 1, argv + argc);
    }
	initialize(user_input, argc);
	
	//while (true) 
	//	get_command(&dumpsim_file,argc);
	return 0;
}