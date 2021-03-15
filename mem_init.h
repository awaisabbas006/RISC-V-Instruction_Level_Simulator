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
	int start{};
	int stop{};
	int m_type{};
    int i{};
    string data;
public:
	init_mem();
	init_mem(string file_name, int start, int stop, int m_type);
	~init_mem();

    void memory_initialize(System_Memories& mem);
    void load_program(vector<string>user_input, System_Memories& mem, int argc);
};

#endif //init_mem_HPP