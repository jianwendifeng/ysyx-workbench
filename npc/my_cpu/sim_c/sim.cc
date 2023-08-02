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
		0x00010433,0x00010433,0x0183c2b3,0x01c402b3,0x020542b3,0,0,0,0,0,0,0x024642b3,0x028742b3,0x02c842b3,0x034a42b3,0x030942b3,
		//# ADD 类型
		0x020542b3, 0,0,0,0,0,// ADD x2, x5, x9
		0x030942b3, // ADD x2, x9, x3
		0x03aa22b3, // ADD x7, x10, x8
		0x038a22b3, // ADD x7, x10, x8
		0x008282b3, // ADD x8, x4, x8

		//# SUB 类型
		0x024642b3, // SUB x4, x6, x9
		0x02e822b3, // SUB x14, x8, x9
		0x03ba22b3, // SUB x7, x10, x8
		0x010222b3, // SUB x4, x2, x2
		0x011222b3, // SUB x7, x17, x2

		//# SLL 类型
		0x028742b3, // SLL x8, x7, x9
		0x021522b3, // SLL x2, x5, x9
		0x03ca22b3, // SLL x7, x10, x8
		0x001202b3, // SLL x1, x0, x2
		0x002202b3, // SLL x1, x0, x2

		//# SRL 类型
		0x026622b3, // SRL x2, x6, x9
		0x017222b3, // SRL x7, x23, x2
		0x00f222b3, // SRL x7, x15, x2
		0x018282b3, // SRL x7, x2, x8
		0x019282b3, // SRL x7, x2, x8

		//# XOR 类型
		0x034a42b3, // XOR x3, x10, x9
		0x015222b3, // XOR x7, x21, x2
		0x03a282b3, // XOR x7, x10, x8
		0x004202b3, // XOR x1, x0, x2
		0x013222b3  // XOR x7, x19, x2

	};	//指令
	/* main loop */
	while (!contextp->gotFinish() && (sim_time <= 128)) {
		// seq_ptr = (seq_ptr + 1) % 14;
		// top->io_wdata = seq[seq_ptr];
		// top->io_waddr = 4*seq_ptr;
		// top->io_wen = 1;
		// if(seq_ptr > 4){
		// 	top->io_raddr1 = 4*seq_ptr - 16;
		// 	top->io_raddr2 = 4*seq_ptr - 12;
		// }
		single_cycle();
		//io_inst端口输入指令
		int num = (sim_time % 35);
		top->io_inst = inst[num];
		printf("exit:%d\n",top->io_exit);
		printf("idu_op:%d\n",top->io_idu_op);
		printf("exu_data1:%d\n",top->io_exu_data1);
		printf("exu_data2:%d\n",top->io_exu_data2);
		printf("exu_data:%d\n",top->io_exu_data);
		printf("mem_data:%d\n",top->io_mem_data);
		printf("wbu_data:%d\n",top->io_wbu_data);
		printf("----------\n");
		
		// cout << "in: " << seq[seq_ptr] << "\t";	<<endl;
		// cout << "out1: " << bitset<1>(top->io_rdata1); <<endl;
		// cout << "out2: " << bitset<1>(top->io_rdata2); <<endl;
		// printf("io_wdata:%d\t",top->io_wdata);
		// printf("io_rdata1:%d\t",top->io_rdata1);
		// printf("io_rdata2:%d\n",top->io_rdata2);

		 sim_time++;
	}

	sim_exit();
}

