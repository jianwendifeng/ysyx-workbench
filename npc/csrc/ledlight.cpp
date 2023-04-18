//#include <stdio.h>
#include <nvboard.h>
#include "Vtop.h"
//#include "verilated_vcd_c.h"
//#include "verilated.h"

static top dut;

void nvboard_bind_all_pins(Vtop* top);

static void single_cycle() {
  dut->clk = 0; dut->eval();
  dut->clk = 1; dut->eval();
}

static void reset(int n) {
  dut->rst = 1;
  while (n -- > 0) single_cycle();
  dut->rst = 0;
}

int main(){
	nvboard_bind_all_pins(&dut);
	nvboard_int();
	
	reset(10);  // 复位10个周期

	while(1) { 
		single_cycle();
		nvboard_update;
	}

	nvboard_quit();
	return 0;
}
