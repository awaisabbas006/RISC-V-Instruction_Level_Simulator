
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
init_mem::init_mem(std::string file_name, int start, int stop, int m_type)
	:file_name(file_name), start(start), stop(stop), m_type(m_type) {
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
    cout<<user_input.at(0)<<endl;
	inst_file.open(file);
	cout<<"==================================================="<<endl;
		while (getline(inst_file, data)) {
			data = data.substr(data.find('x') + 1, data.length() + 1);
			long long  word = stoll(data, nullptr, 16);
            cout <<hex<< word << endl;
			mem.INST_MEMORY[i][0]= word & 0x000000FF;
            mem.INST_MEMORY[i][1]= word & 0x0000FF00;
            mem.INST_MEMORY[i][2]= word & 0x00FF0000;
            mem.INST_MEMORY[i][3]= word & 0xFF000000;
			i++;
		}
	inst_file.close();	
}