#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated_vcd_c.h"
#include "verilated.h"
#include <nvboard.h>
double sc_time_stamp() { return 0;}		//Legacy function required only so liking works o Cygwin and MSVC++

static Vtop top;

void nvboard_bind_all_pins(Vtop* top);


static void single_cycle() {
  top.clk = 0; top.eval();
  top.clk = 1; top.eval();
}

static void reset(int n) {
  top.rst = 1;
  while (n -- > 0) single_cycle();
  top.rst = 0;
}

int main() {
	nvboard_bind_all_pins(&top);
	nvboard_init();	//initial nvboard
	reset(10);
 
	//const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
	VerilatedContext* contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);

	//Verilated::traceEverOn(true);		//Before any evaluation,need to know to calculate those signals only used for tracing
	VerilatedVcdC* tfp = new VerilatedVcdC;		//wave dir
	Verilated::traceEverOn(true);		//Before any evaluation,need to know to calculate those signals only used for tracing
Vtop *top = new Vtop{contextp};

	top->trace(tfp,99);
	tfp->open("wave.vcd");
	
	
	//while (!contextp->gotFinish()) { 
	while(1) {  
		//nvboard_update();
		//single_cycle();
		top->eval();
		contextp->timeInc(1);
		tfp->dump(contextp->time());
		single_cycle();
		nvboard_update();
		
	}
	tfp->close();
	delete top;
	delete contextp;
	nvboard_quit();
	return 0;
}
