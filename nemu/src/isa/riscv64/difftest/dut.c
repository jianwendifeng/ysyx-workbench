/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/difftest.h>
#include "../local-include/reg.h"

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) 
{
	int i;
	for(i=0;i<32;i++)
		{
			//printf("%dreg_name:\t%ld:\t%#lx\t\tpc_name:\t%ld\t%#lx\n",i,ref_r->gpr[i],ref_r->gpr[i],cpu.gpr[i],cpu.gpr[i]);
			if(ref_r->pc != pc ){
				//printf("Wrong pc:%#lx\tRight pc:%#lx\nWrong reg value:%#lx\tRight value:%#lx\n",ref_r->pc,ref_r->pc,cpu.gpr[i],ref_r->gpr[i]);
			//	printf("Wrong pc:%#lx\tRight pc:%#lx\nWrong reg value:%#lx\tRight value:%#lx\n",ref_r->pc,pc,cpu.gpr[i],ref_r->gpr[i]);
				
				//isa_reg_display();
			return false;
			}
		}
	return true;
}

void isa_difftest_attach() {
}
