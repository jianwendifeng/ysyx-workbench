#include <common.h>

extern uint64_t g_nr_guest_inst;
FILE *elf_fp = NULL;

void init_elf(const char *elf_file) {
  elf_fp = stdout;
  if (elf_file != NULL) {
    FILE *fp = fopen(elf_file, "w");
    Assert(fp, "Can not open '%s'", elf_file);
    elf_fp = fp;
  }
  Log("Log is written to %s", elf_file ? elf_file : "stdout");
}

bool elf_enable() {
  return MUXDEF(CONFIG_TRACE, (g_nr_guest_inst >= CONFIG_TRACE_START) &&
         (g_nr_guest_inst <= CONFIG_TRACE_END), false);
}

