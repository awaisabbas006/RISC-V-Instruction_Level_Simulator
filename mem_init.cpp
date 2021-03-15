
#include "mem_init.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

init_mem::init_mem() {
}

init_mem::~init_mem() {
}

void init_mem::memory_initialize(System_Memories& mem){
    // initializing the instruction and data memory to known value
    for(int init = 0; init<=WORDS_IN_MEM/4; init++){
        mem.INST_MEMORY[init][0] = 0;
        mem.INST_MEMORY[init][1] = 0;
        mem.INST_MEMORY[init][2] = 0;
        mem.INST_MEMORY[init][3] = 0;

        mem.DATA_MEMORY[init][0] = 0;
        mem.DATA_MEMORY[init][1] = 0;
        mem.DATA_MEMORY[init][2] = 0;
        mem.DATA_MEMORY[init][3] = 0;
    }
}
void init_mem::load_program(vector<string>user_input, System_Memories& mem,int argc) {
	ifstream inst_file;
	i = 0;
	string file = user_input.at(0); // name of files containing machine code
	inst_file.open(file);
		while (getline(inst_file, data)) {
			data = data.substr(data.find('x') + 1, data.length() + 1);  // Ignore 0x from machine code
			long long  word = stoll(data, nullptr, 16);                 // Convert string in hexadecimal format to integer
			mem.INST_MEMORY[i][0]=  word & 0x000000FF;                  // Load Program into instruction memory
            mem.INST_MEMORY[i][1]= (word & 0x0000FF00)>>8;
            mem.INST_MEMORY[i][2]= (word & 0x00FF0000)>>16;
            mem.INST_MEMORY[i][3]= (word & 0xFF000000)>>24;
			i++;
		}
	inst_file.close();	
}