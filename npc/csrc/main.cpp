#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated_vcd_c.h"
#include "verilated.h"

double sc_time_stamp() {return 0;}
 
 
int main(int argc, char** argv)
{
		VerilatedContext* contextp = new VerilatedContext; 
		contextp->commandArgs(argc, argv);

		VerilatedVcdC* tfp = new VerilatedVcdC; //wave dir
		Verilated::traceEverOn(true);

		Vtop *top = new Vtop{contextp};

    top->trace(tfp, 99);   
    tfp->open("wave.vcd"); //open vcd
 
    while	(!contextp->gotFinish())	{
		top->eval();		
		int a = rand() & 1;
		int b = rand() & 1;
		top->a = a;
		top->b = b;
		top->eval();
		printf("a = %d, b = %d, f = %d\n", a, b, top->f);
    assert(top->f == (a^b));

		contextp->timeInc(1);
		top->eval();
    tfp->dump(contextp->time());
		}

		tfp->close();
		delete top;
		delete contextp;
 
    return 0;
}

