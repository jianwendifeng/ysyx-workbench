#include <common.h>
#include <unistd.h>

extern uint64_t g_nr_guest_inst;
FILE *elf_fp = NULL;

void init_ftrace(const char *ftrace_file) {
  elf_fp = stdout;
  if (ftrace_file != NULL) {
    FILE *fp = fopen(ftrace_file, "w");
    Assert(fp, "Can not open '%s'", ftrace_file);
    elf_fp = fp;
  }
  Log("Log is written to %s", ftrace_file ? ftrace_file : "stdout");
}

bool ftrace_enable() {
  return MUXDEF(CONFIG_TRACE, (g_nr_guest_inst >= CONFIG_TRACE_START) &&
         (g_nr_guest_inst <= CONFIG_TRACE_END), false);
}

