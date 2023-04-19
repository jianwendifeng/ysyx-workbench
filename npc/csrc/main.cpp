#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated_vcd_c.h"
#include "verilated.h"
#include <nvboard.h>
double sc_time_stamp() { return 0;}		//Legacy function required only so liking works o Cygwin and MSVC++

static TOP_NAME dut;

void nvboard_bind_all_pins(Vtop* top);

static void single_cycle() {
  dut.clk = 0; dut.eval();
  dut.clk = 1; dut.eval();
}

int main(int argc,char *argv[]) {
	nvboard_bind_all_pins(&dut);
	nvboard_init();

	//const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
	VerilatedContext* contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);

	//Verilated::traceEverOn(true);		//Before any evaluation,need to know to calculate those signals only used for tracing
	VerilatedVcdC* tfp = new VerilatedVcdC;		//wave dir
	Verilated::traceEverOn(true);		//Before any evaluation,need to know to calculate those signals only used for tracing
Vtop *top = new Vtop{contextp};

	top->trace(tfp,99);
	tfp->open("wave.vcd");
	
	while (!contextp->gotFinish()) { 
		nvboard_update();
		single_cycle();
		
		top->eval(); 
		int a = rand() & 1;
		int b = rand() & 1;
		top->a = a;
			
		top->b = b;
		top->eval();
		printf("a = %d, b = %d, f = %d\n", a, b, top->f);
		assert(top->f == (a ^ b));

		contextp->timeInc(1);
		top->eval();
		tfp->dump(contextp->time());

		nvboard_update();
		
	}
	tfp->close();
	delete top;
	delete contextp;
	nvboard_quit();
	return 0;
}
