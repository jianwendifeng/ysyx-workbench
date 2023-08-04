#include <iostream>
#include <bitset>

#include <verilated.h>
#include "Vtop.h"
#include <stdio.h>
#ifdef VCD
	#include "verilated_vcd_c.h"
	VerilatedVcdC* tfp = nullptr;
#endif

#include "sim.h"

using namespace std; 

// init pointers
const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
const std::unique_ptr<Vtop> top{new Vtop{contextp.get(), "TOP"}};

/* sim initial */
void sim_init(int argc, char *argv[]) {
	top->reset = 1;
	top->clock = 0;
#ifdef VCD
	Verilated::mkdir("logs");
	contextp->traceEverOn(true);
	tfp = new VerilatedVcdC;
	top->trace(tfp, 99);
    tfp->open("logs/top.vcd");
#endif
	Verilated::commandArgs(argc,argv);
}

/* sim exit */
void sim_exit() {
	// finish work, delete pointer
	top->final();
#if VCD
	tfp->close();
	tfp = nullptr;
#endif
}

void single_cycle() {
	contextp->timeInc(1);
	top->clock = 0; top->eval();
#ifdef VCD
 tfp->dump(contextp->time());
#endif

	contextp->timeInc(1);
	top->clock = 1; top->eval();
#ifdef VCD
 tfp->dump(contextp->time());
#endif
}

void reset(int n) {
	top->reset = 1;
	while (n-- > 0) single_cycle();
	top->reset = 0;
	top->eval();
}

void sim_main(int argc, char *argv[]) {
	sim_init(argc, argv);
	reset(1);

	/* main simulation*/
	 int sim_time = 0;
	// int seq_ptr = 0;
	// int seq[] = {1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0};
	//long int inst[] = { 0x008000EF,0x00110113,0x000101B3,0xffffffff};
	uint32_t inst[] = 
		{
			0xff010113,          	//addi	sp,sp,-16
			0,0,0,0,
			0x0009e117,          	//auipc	sp,0x9e
			0,0,0,0,
			0x40e50533,          	//sub	a0,a0,a4
			0,0,0,0,
			0x00240413,         	//addi	s0,s0,2
			0,0,0,0,
			0x00868693,          	//addi	a3,a3,8
			0,0,0,0
		};	//指令
	/* main loop */
	while (!contextp->gotFinish() && (sim_time <= 128)) {
		single_cycle();
		//io_inst端口输入指令
		int num = (sim_time % 25);
		top->io_inst = inst[num];
		 sim_time++;
	}

	sim_exit();
}

