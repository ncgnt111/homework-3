#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process_file.h"

int main (int argc, char *argv[]) {
    if (argc == 1) {
        printf(" The program %s must have at least one argument!\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; ++i) {
        int result_process = process_file(argv[i]);

        if (result_process == ERR_ERR) {
            fprintf(stderr, "ERROR: in 'process_file'\n");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

