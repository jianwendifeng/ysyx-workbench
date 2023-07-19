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
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

// static void memory_copy(void *dest, void *src, size_t n){
//   uint64_t *mc_dest = (uint64_t*) dest; 
//   uint64_t *mc_src = (uint64_t*) src;
//   if()
// }

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  // if(direction == DIFFTEST_TO_REF){
  //   memory_copy(guest_to_host(addr),buf,n); //copy to ref
  // }else{
  //   memory_copy(buf,guest_to_host(addr),n); //copy to dut
  // }
  assert(0);
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  assert(0);
}

__EXPORT void difftest_exec(uint64_t n) {
  assert(0);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
