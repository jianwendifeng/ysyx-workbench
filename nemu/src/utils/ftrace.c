#include <common.h>
#include <unistd.h>
#include <elf.h>



#define elf_func_num 64

extern uint64_t g_nr_guest_inst;


// static struct {
//   const char* name;
//   uint64_t size;
//   uint64_t address;
// } elf_func[elf_func_num];


void init_ftrace(const char *elf_file) {
  // FILE *elf_fp = fopen(elf_file, "rb");
  //   if (elf_fp) {
        
  //   // 读取 ELF 文件头
  //   Elf64_Ehdr elf_header;
  //   fread(&elf_header, sizeof(Elf64_Ehdr), 1, elf_fp);

  //   // 定位节头表
  //   fseek(elf_fp, elf_header.e_shoff, SEEK_SET);

  //   // 读取节头表
  //   Elf64_Shdr section_header;
  //   fread(&section_header, sizeof(Elf64_Shdr), 1, elf_fp);

  //   // 定位到符号表节
  //   int symbol_table_index = -1;
  //   for (int i = 0; i < elf_header.e_shnum; i++) {
  //       if (section_header.sh_type == SHT_SYMTAB) {
  //           symbol_table_index = i;
  //           break;
  //       }
  //       fread(&section_header, sizeof(Elf64_Shdr), 1, elf_fp);
  //   }

  //   if (symbol_table_index == -1) {
  //       // 找不到符号表节，处理错误情况
  //       fclose(elf_fp);
  //       return 1;
  //   }

  //   // 获取符号表节信息
  //   fseek(elf_fp, elf_header.e_shoff + symbol_table_index * sizeof(Elf64_Shdr), SEEK_SET);
  //   fread(&section_header, sizeof(Elf64_Shdr), 1, elf_fp);

  //  // 定位到字符串表节，用于获取符号名称
  //   fseek(elf_fp, elf_header.e_shoff + elf_header.e_shstrndx * sizeof(Elf64_Shdr), SEEK_SET);
  //   fread(&section_header, sizeof(Elf64_Shdr), 1, elf_fp);
  //   char *strtab = malloc(section_header.sh_size);
  //   fseek(elf_fp, section_header.sh_offset, SEEK_SET);
  //   fread(strtab, section_header.sh_size, 1, elf_fp);

  //   // 定位到符号表
  //   fseek(elf_fp, section_header.sh_offset, SEEK_SET);

  //   // 读取符号表
  //   Elf64_Sym symbol;
  //   for (int i = 0; i < section_header.sh_size / sizeof(Elf64_Sym); i++) {
  //       fread(&symbol, sizeof(Elf64_Sym), 1, elf_fp);

  //       // 筛选出 FUNC 类型的符号
  //       if (ELF64_ST_TYPE(symbol.st_info) == STT_FUNC) {
  //           // 获取函数符号的名称和地址等信息
  //           const char *symbol_name = &strtab[symbol.st_name];
  //           Elf64_Addr symbol_addr = symbol.st_value;
  //           // 其他信息，根据需要获取
  //           // ...

  //           // 在这里可以对函数符号进行进一步处理，或者将信息打印出来
  //           printf("Function: %s\n", symbol_name);
  //           printf("Address: 0x%llx\n", (unsigned long long)symbol_addr);
  //       }
  //   }

  //   free(strtab); // 释放字符串表内存
  //   fclose(elf_fp); // 关闭文件
  //   }

}



  // int fp = open(elf_file,O_RDONLY);
  // Elf *elf = elf_begin(fp, ELF_C_READ, NULL);   //open elf file
  // //FILE *elf = fopen(elf_file, "w");
  // //assert(elf, "Can not open '%s'", elf_file);

  // //Elf64_Ehdr *ehdr = elf64_getehdr(elf);    //get elf head
  // //assert(elf, "Can not open '%s'head", elf);

  // Elf64_Phdr *phdr = elf64_getphdr(elf);    //get elf program head table
  // size_t phdr_count = 0;
  // elf_getphdrnum(elf,&phdr_count);     //get the number of pht

  // static int i = 0;
  // for (i = 0; i < phdr_count; i++) {
  //  if(phdr[i].p_type == SHT_STRTAB){
  //   Elf64_Addr  strtab_addr = 0;
  //   Elf64_Xword strtab_size = 0;
  //     strtab_addr = phdr[i].p_vaddr;
  //     strtab_size = phdr[i].p_filesz;
  //     printf("strtab.addr%ld\tsize%ld\n",strtab_addr,strtab_size);
  //  }
  //  else if(phdr[i].p_type == SHT_SYMTAB){
  //     Elf64_Sym*  symtab_addr = 0;        // 符号表的起始地址
  //      Elf64_Xword symtab_size = 0;        // 符号表的大小
  //     symtab_addr = (Elf64_Sym*)phdr[i].p_vaddr;
  //     symtab_size = phdr[i].p_filesz;
  //     int symtab_count = symtab_size / sizeof(Elf64_Sym);   //the number of symtab member
  //     static int j;
  //     for(j = 0 ; j < symtab_count ; j++ ){
  //       Elf64_Sym* sym = (Elf64_Sym*)(symtab_addr + j * sizeof(Elf64_Sym));
  //       if (ELF64_ST_TYPE(sym->st_info) == STT_FUNC) {
  //         printf("ftrace:%d\n",ELF64_ST_TYPE(sym->st_info));
  //     }

  //  }
  // }
  // }


