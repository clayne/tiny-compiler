#include <stdlib.h>

#include "defs.h"
#include "input.h"
#include "lex.h"
#include "parser.h"
#include "gen.h"
#include "vm.h"
#include "asm.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        fatal("No file provided! Usage: compiler <source>");
    }

    byte *bytecode;
    open_file(argv[1]);
    bytecode = compile(parse(lex()));
    close_file();

    puts("Generated ASM:");
    disassemble(bytecode);

    puts("Execution result:");
    run(bytecode);

    return EXIT_SUCCESS;
}
