#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "modify_tree.h"
#include "tree.h"

int process_file(const char *filename) {
    FILE *fp = NULL;
    fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return ERR_ERR;
    }

    char sign;
    char word[1024];

    struct node *root = NULL;

    int result_fscanf = 0;

    while ((result_fscanf = fscanf(fp, " %[+-?] %1023[a-zA-Z]", &sign, word)) != EOF) {
        if (result_fscanf < 2) {
            fprintf(stderr, "ERROR: in 'fscanf' - expected 2 items, found %d\n", result_fscanf);
            free_tree(root);
            fclose(fp);
            return ERR_ERR;
        } else {
            int result_modify_tree = modify_tree(&root, sign, word);
            if (result_modify_tree == ERR_ERR) {
                fprintf(stderr, "ERROR: in 'modify_tree'\n");
                free_tree(root);
                fclose(fp);
                return ERR_ERR;
            }
        }
    }

    free_tree(root);
    fclose(fp);
    return ERR_NOERR;
}
