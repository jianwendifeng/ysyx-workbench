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
  FILE *file = fopen(elf_file,"rb");
  if(!file){
    printf("Don't open ELF file\n");
    //assert(1);
  }

        
  // 读取 ELF 文件头
  Elf64_Ehdr elf_header;
  if(fread(&elf_header, sizeof(Elf64_Ehdr), 1, file) != 1){
    printf("Error reading ELF header\n");
    //assert(1);
  }

  // 定位节头表
  fseek(file, elf_header.e_shoff, SEEK_SET);

  Elf64_Shdr sectionHeader;
  int stringTableIndex = -1;
    for (int i = 0; i < elf_header.e_shnum; i++) {
      if (fread(&sectionHeader, sizeof(Elf64_Shdr), 1, file) != 1) {
          printf("Error reading section header");
          fclose(file);
          //assert(1);
        }
      if (sectionHeader.sh_type == SHT_SYMTAB || sectionHeader.sh_type == SHT_DYNSYM) {
            stringTableIndex = sectionHeader.sh_link;
            break;
        }
    }

    if (stringTableIndex == -1) {
        printf("No symbol table found.\n");
        fclose(file);
        //assert(1);
    }

    fseek(file, sectionHeader.sh_offset, SEEK_SET);

    Elf64_Sym symbol;
    while (fread(&symbol, sizeof(Elf64_Sym), 1, file) == 1) {
        if (ELF64_ST_TYPE(symbol.st_info) == STT_FUNC) {
            char name[256];
            fseek(file, sectionHeader.sh_offset + stringTableIndex + symbol.st_name, SEEK_SET);
            if (fgets(name, sizeof(name), file) != NULL) {
                printf("Function: %s\n", name);
            }
        }
    }
}



