#ifndef MODIFY_TREE
#define MODIFY_TREE

#include "tree.h"

enum {
    ERR_NOERR = 0,
    ERR_ERR = 1
};

int modify_tree(struct node **root, char sign, const char *word);

#endif // MODIFY_TREE

