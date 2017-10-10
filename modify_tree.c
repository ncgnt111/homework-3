#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "tree.h"

enum {
    ERR_NOERR = 0,
    ERR_ERR = 1
};

int modify_tree(struct node **root, char sign, const char *word) {
    if (sign == '+') {
        struct node *temp = insert_node((*root), word);
        if (temp == NULL) {
            fprintf(stderr, "ERROR: in 'insert_node'\n");
            return ERR_ERR;
        } else {
            (*root) = temp;
        }
        traverse_inorder(*root);
        printf("\n");
    } else if (sign == '-') {
        (*root) = delete_node((*root), word);
        traverse_inorder(*root);
        printf("\n");
    } else if (sign == '?') {
        if (search_node((*root), word) != NULL) {
            printf("%s Yes\n", word);
        } else {
            printf("%s No\n", word);
        }
    }
    return ERR_NOERR;
}
