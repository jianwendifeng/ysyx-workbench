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
//   FILE *file = fopen(elf_file,"rb");
//   if(file){
//     // 读取 ELF 文件头
//   Elf64_Ehdr elf_header;
//   if(fread(&elf_header, sizeof(Elf64_Ehdr), 1, file) != 1){
//     printf("Error reading ELF header\n");
//     //assert(1);
//   }

//   // 定位节头表
//   fseek(file, elf_header.e_shoff, SEEK_SET);

//   Elf64_Shdr sectionHeader;
//   Elf64_Shdr symbolTableHeader;

//   int stringTableIndex = -1;

//   for (int i = 0; i < elf_header.e_shnum; i++) {      //e_shnum 此成员保存节标题表中的条目数
//     if (fread(&sectionHeader, sizeof(Elf64_Shdr), 1, file) != 1) {
//         printf("Error reading section header");
//         fclose(file);
//         //assert(1);
//       }
//     if (sectionHeader.sh_type == SHT_SYMTAB ) {     //SHT_SYMTAB 此部分包含符号表。
//         stringTableIndex = sectionHeader.sh_link;
//         symbolTableHeader = sectionHeader;
//         break;
//       }
//     }FILE *file = fopen(elf_file,"rb");
//   if(file){
//     // 读取 ELF 文件头
//   Elf64_Ehdr elf_header;
//   if(fread(&elf_header, sizeof(Elf64_Ehdr), 1, file) != 1){
//     printf("Error reading ELF header\n");
//     //assert(1);
//   }

//   // 定位节头表
//   fseek(file, elf_header.e_shoff, SEEK_SET);

//   Elf64_Shdr sectionHeader;
//   Elf64_Shdr symbolTableHeader;

//   int stringTableIndex = -1;

//   for (int i = 0; i < elf_header.e_shnum; i++) {      //e_shnum 此成员保存节标题表中的条目数
//     if (fread(&sectionHeader, sizeof(Elf64_Shdr), 1, file) != 1) {
//         printf("Error reading section header");
//         fclose(file);
//         //assert(1);
//       }
//     if (sectionHeader.sh_type == SHT_SYMTAB ) {     //SHT_SYMTAB 此部分包含符号表。
//         stringTableIndex = sectionHeader.sh_link;
//         symbolTableHeader = sectionHeader;
//         break;
//       }
//     }

//     if (stringTableIndex == -1) {
//         printf("No symbol table found.\n");
//         fclose(file);
//         //assert(1);
//     }

//     fseek(file, sectionHeader.sh_offset, SEEK_SET);

//     Elf64_Sym symbol;
//     char *function_name = NULL;
//     while (fread(&symbol, sizeof(Elf64_Sym), 1, file) == 1) {
//         if (ELF64_ST_TYPE(symbol.st_info) == STT_FUNC) {
//             Elf64_Addr symbol_start = symbol.st_value;
//             Elf64_Addr symbol_end = symbol.st_value + symbol.st_size;

//             // if (address >= symbol_start && address < symbol_end) {
//             //     function_name = (char *)malloc(MAX_FUNCTION_NAME_LENGTH);
//             //     if (!function_name) {
//             //         printf("Memory allocation error\n");
//             //         fclose(file);
//             //         //return NULL;
//             //     }
//             fseek(file, symbolTableHeader.sh_offset + stringTableIndex + symbol.st_name, SEEK_SET);
//                 if (fgets(function_name, MAX_FUNCTION_NAME_LENGTH, file) != NULL) {
//                     // Remove newline character from the end of the function name
//                     char *newline = strchr(function_name, '\n');
//                     if (newline) {
//                         *newline = '\0';
//                     }
//                 }
//                 break;
//         }
//     }
//   }


//     fclose(file);

//     if (function_name) {
//         printf("FUNCTION:%s\n",function_name);
//     } else {
//         printf("Don't find FUNCTION\n");
//     }
//   // else{
//   //    printf("Don't open ELF file\n");
//   //   //assert(1);
//   // }
//   //   fclose(file);
// }

//     if (stringTableIndex == -1) {
//         printf("No symbol table found.\n");
//         fclose(file);
//         //assert(1);
//     }

//     fseek(file, sectionHeader.sh_offset, SEEK_SET);

//     Elf64_Sym symbol;
//     char *function_name = NULL;
//     while (fread(&symbol, sizeof(Elf64_Sym), 1, file) == 1) {
//         if (ELF64_ST_TYPE(symbol.st_info) == STT_FUNC) {
//             Elf64_Addr symbol_start = symbol.st_value;
//             Elf64_Addr symbol_end = symbol.st_value + symbol.st_size;

//             // if (address >= symbol_start && address < symbol_end) {
//             //     function_name = (char *)malloc(MAX_FUNCTION_NAME_LENGTH);
//             //     if (!function_name) {
//             //         printf("Memory allocation error\n");
//             //         fclose(file);
//             //         //return NULL;
//             //     }
//             fseek(file, symbolTableHeader.sh_offset + stringTableIndex + symbol.st_name, SEEK_SET);
//                 if (fgets(function_name, MAX_FUNCTION_NAME_LENGTH, file) != NULL) {
//                     // Remove newline character from the end of the function name
//                     char *newline = strchr(function_name, '\n');
//                     if (newline) {
//                         *newline = '\0';
//                     }
//                 }
//                 break;
//         }
//     }
//   }


//     fclose(file);

//     if (function_name) {
//         printf("FUNCTION:%s\n",function_name);
//     } else {
//         printf("Don't find FUNCTION\n");
//     }
//   // else{
//   //    printf("Don't open ELF file\n");
//   //   //assert(1);
//   // }
//   //   fclose(file);
// }
}



