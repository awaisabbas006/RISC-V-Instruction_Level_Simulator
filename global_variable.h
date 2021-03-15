#pragma once
#define CONTROL_STORE_ROWS 		64
#define RISC_V_REGS 			32
#define WORDS_IN_MEM    		0x40000 
#include <vector>
using namespace std;


/***********************************************************************
                        Memory declaration
************************************************************************/

typedef struct Memories{
	// int CONTROL_STORE[CONTROL_STORE_ROWS][no_control_signals]{};
	int INST_MEMORY[WORDS_IN_MEM][4]{};
    int DATA_MEMORY[WORDS_IN_MEM][4]{};
	
}System_Memories;
