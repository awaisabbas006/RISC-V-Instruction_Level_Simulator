#pragma once
#ifndef init_mem_HPP
#define init_mem_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "global_variable.h"

using namespace std;

class init_mem {
private:
	string file_name;
	string data;
    int i{};
    
public:
	init_mem();		// Constructor
	~init_mem();	// Destructor

    void memory_initialize(System_Memories& mem);	// Initialze Instruction and Data memory to known value
    void load_program(vector<string>user_input, System_Memories& mem, int argc);	// Load program into instruction memory
};

#endif //init_mem_HPP