#include <common.h>
#include <unistd.h>
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <gelf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define elf_func_num 64

extern uint64_t g_nr_guest_inst;


// static struct {
//   const char* name;
//   uint64_t size;
//   uint64_t address;
// } elf_func[elf_func_num];


void init_ftrace(const char *elf_file) {
  int fp = open(elf_file,O_RDONLY);
  Elf *elf = elf_begin(fp, ELF_C_READ, NULL);   //open elf file
  //FILE *elf = fopen(elf_file, "w");
  //assert(elf, "Can not open '%s'", elf_file);

  //Elf64_Ehdr *ehdr = elf64_getehdr(elf);    //get elf head
  //assert(elf, "Can not open '%s'head", elf);

  Elf64_Phdr *phdr = elf64_getphdr(elf);    //get elf program head table
  size_t phdr_count = 0;
  elf_getphdrnum(elf,&phdr_count);     //get the number of pht

  static int i = 0;
  for (i = 0; i < phdr_count; i++) {
   if(phdr[i].p_type == SHT_STRTAB){
    Elf64_Addr  strtab_addr = 0;
    Elf64_Xword strtab_size = 0;
      strtab_addr = phdr[i].p_vaddr;
      strtab_size = phdr[i].p_filesz;
      printf("strtab.addr%ld\tsize%ld\n",strtab_addr,strtab_size);
   }
   else if(phdr[i].p_type == SHT_SYMTAB){
      Elf64_Sym*  symtab_addr = 0;        // 符号表的起始地址
       Elf64_Xword symtab_size = 0;        // 符号表的大小
      symtab_addr = (Elf64_Sym*)phdr[i].p_vaddr;
      symtab_size = phdr[i].p_filesz;
      int symtab_count = symtab_size / sizeof(Elf64_Sym);   //the number of symtab member
      static int j;
      for(j = 0 ; j < symtab_count ; j++ ){
        Elf64_Sym* sym = (Elf64_Sym*)(symtab_addr + j * sizeof(Elf64_Sym));
        if (ELF64_ST_TYPE(sym->st_info) == STT_FUNC) {
          printf("ftrace:%d\n",ELF64_ST_TYPE(sym->st_info));
      }

   }
  }
  }
}



bool ftrace_enable() {
  return MUXDEF(CONFIG_TRACE, (g_nr_guest_inst >= CONFIG_TRACE_START) &&
         (g_nr_guest_inst <= CONFIG_TRACE_END), false);
}

