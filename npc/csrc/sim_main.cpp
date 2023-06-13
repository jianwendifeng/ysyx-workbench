#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include "Vtop.h"
#include "verilated_vcd_c.h"
#include "verilated.h"

vluint64_t sim_time = 0;

int main(int argc,char** argv) {
	Vtop *dut = new Vtop;

	Verilated::traceEverOn(true);		//Before any evaluation,need to know to calculate those signals only used for tracing

	VerilatedVcdC *m_trace = new VerilatedVcdC;  
    dut->trace(m_trace, 5);               
    m_trace->open("waveform.vcd");
	dut->clk = 1;
	dut->rst = 1;
	int i=0;
	while (sim_time < 64) { 
 		if(i <= 2) {
			dut->rst = !dut->rst;
			i++;
		}
		dut->clk = !dut->clk;
		dut->eval();
		m_trace->dump(sim_time++);
	}
	m_trace->close();
	delete dut;
	return 0;
}

