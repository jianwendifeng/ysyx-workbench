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
	reset(10);

	/* main simulation*/
	int sim_time = 0;
	int seq_ptr = 0;
	int seq[] = {1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0};

	/* main loop */
	while (!contextp->gotFinish() && (sim_time <= 20)) {
		seq_ptr = (seq_ptr + 1) % 14;
		top->io_wdata = seq[seq_ptr];
		top->io_waddr = 4*seq_ptr;
		top->io_wen = 1;
		if(seq_ptr > 4){
			top->io_raddr1 = 4*seq_ptr - 16;
			top->io_raddr2 = 4*seq_ptr - 12;
		}
		single_cycle();
		// cout << "in: " << seq[seq_ptr] << "\t";	<<endl;
		// cout << "out1: " << bitset<1>(top->io_rdata1); <<endl;
		// cout << "out2: " << bitset<1>(top->io_rdata2); <<endl;
		printf("io_wdata:%d\t",top->io_wdata);
		printf("io_rdata1:%d\t",top->io_rdata1);
		printf("io_rdata2:%d\n",top->io_rdata2);

		sim_time++;
	}

	sim_exit();
}

