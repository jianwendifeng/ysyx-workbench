#include <common.h>
#include <unistd.h>
#include <elf.h>
#include <stdio.h>

#ifdef MTRACE

#define func_num_max 64

typedef struct
{
    char name[64];
    Elf64_Addr start;
    Elf64_Addr end;
}FunctionInfo;

FunctionInfo func_info[func_num_max];
int func_num = 0;

// 读取字符串表和符号表的内容

void read_symbol_table(char *data,Elf64_Shdr *strtab,Elf64_Shdr *symtab){
    Elf64_Sym *symbols = (Elf64_Sym *)(data + symtab->sh_offset);
    assert(symbols);

    char *strings = data + strtab->sh_offset;
    assert(strings);

    int num_symbols = symtab->sh_size / sizeof(Elf64_Sym);
    assert(num_symbols);

    for(int i = 0; i < num_symbols; i++){
        unsigned char type = ELF64_ST_TYPE(symbols[i].st_info);
        if(type ==  STT_FUNC){ //符号表中func的项
            snprintf(func_info[func_num].name, sizeof(func_info[func_num].name), "%s", &strings[symbols[i].st_name]);
                func_info[func_num].start = symbols[i].st_value;
                func_info[func_num].end = symbols[i].st_value + symbols[i].st_size;
                func_num++;
        }
    }
}

void init_ftrace(const char* elf_file){
    FILE *file = fopen(elf_file,"rb");
    if(file == NULL){
        printf("Can't open elf_file.\n");
        assert(0);
    }

    // 获取文件大小，读取整个 ELF 文件到内存中
    fseek(file, 0, SEEK_END);   //指针移动到文件尾部
    long size = ftell(file);    //移动到文件尾部，得到ftell会返回文件的大小，字节为单位
    fseek(file, 0, SEEK_SET);   //将指针移回文件的开头

    char *data = (char *)malloc(size);  //内存块用于存储整个 ELF 文件的内容
    if (fread(data, 1, size, file) != size) {
        printf("Failed to read the file: %s\n", elf_file);
        fclose(file);
        free(data);
        assert(0);
    }
    fclose(file);

    // 获取 ELF 文件头
    Elf64_Ehdr *elf_header = (Elf64_Ehdr *)data;
    //ELF 文件的魔数，它们的值分别是：0x7F、'E'、'L' 和 'F'，用来判断elf文件是否有效
    if (elf_header->e_ident[EI_MAG0] != ELFMAG0 || elf_header->e_ident[EI_MAG1] != ELFMAG1 || elf_header->e_ident[EI_MAG2] != ELFMAG2 || elf_header->e_ident[EI_MAG3] != ELFMAG3) 
        { 
            printf("Invalid ELF file: %s\n", elf_file);
            free(data);
            assert(0);
        }

     // 获取节头表
    Elf64_Shdr *sections = (Elf64_Shdr *)(data + elf_header->e_shoff);

    // 获取字符串表和符号表节头表项
    Elf64_Shdr *symtab = NULL;
    Elf64_Shdr *strtab = NULL;
    for (int i = 0; i < elf_header->e_shnum; i++) {
        if (sections[i].sh_type == SHT_SYMTAB) {
            symtab = &sections[i];
        } else if (sections[i].sh_type == SHT_STRTAB) {
            strtab = &sections[i];
        }

        if (symtab != NULL && strtab != NULL) {
            break;
        }
    }

    if (symtab == NULL || strtab == NULL) {
        printf("Symbol table or string table not found in the ELF file: %s\n", elf_file);
        free(data);
        assert(0);
    }
    read_symbol_table(data,strtab,symtab);
    free(data);
}

char* find_name(vaddr_t dnpc){
    
    for (int i = 0; i < func_num; i++) {
        Elf64_Addr func_start = func_info[i].start;
        Elf64_Addr func_end = func_info[i].end;
        if ((dnpc >= func_start) && (dnpc <= func_end)) {
            return func_info[i].name;
        }
    }
    return "????";
}

int ftrace_num = 0; 

extern void ftrace_call(vaddr_t pc,vaddr_t dnpc){
    printf("pc:0x%lx",pc);
    for(int i = 0 ; i < ftrace_num ; i++){
        printf(" "); 
    }
    char *func_name = find_name(dnpc);
    assert(func_name);
    printf(" call [%s@0x%#lx]\n\n",func_name,dnpc);
    ftrace_num++;
}

extern void ftrace_ret(vaddr_t pc,vaddr_t dnpc){
    printf("pc:0x%lx",pc);
    for(int i = 0 ; i < ftrace_num ; i++){
        printf(" ");
    }
    char* func_name = find_name(dnpc);
    assert(func_name);
    printf(" ret [%s@0x]\n\n",func_name);
    ftrace_num--;
}

#endif





