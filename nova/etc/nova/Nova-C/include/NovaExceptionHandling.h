#ifndef NOVA_EXCEPTION_HANDLING
#define NOVA_EXCEPTION_HANDLING

#include <stdio.h>

#ifdef _WIN32

#include <Windows.h>
#include <imagehlp.h>
#include <MacroLib.h>

void setProgramName(char* name);
int addr2line(char const * const program_name, void const * const addr);
void nova_print_stacktrace(CONTEXT* context);
LONG WINAPI nova_exception_handler(EXCEPTION_POINTERS * ExceptionInfo);
void nova_signal_handler(int code);

#endif

#endif