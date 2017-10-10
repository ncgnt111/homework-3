#ifndef TREE
#define TREE

struct node
{
    const char *key;
    struct node *left, *right;
};

int compare(const char *first, const char *second);

struct node *create_new_node(const char *key);

struct node *insert_node(struct node *root, const char *key);

struct node *delete_node(struct node *root, const char *key);

struct node *search_node(struct node *root, const char *key);

struct node *find_min_key_node(struct node *root);

void traverse_preorder(struct node *root);

void traverse_inorder(struct node *root);

void traverse_postorder(struct node *root);

void free_tree(struct node *root);

#endif // TREE

