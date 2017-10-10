#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct node {
    const char *key;
    struct node *left, *right;
};

int compare(const char *first, const char *second) {
    return strcmp(first, second);
}

// Create a new node
struct node *create_new_node(const char *key) {
    struct node *temp =  malloc(sizeof(struct node));
    if (temp == NULL) {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return NULL;
    }

    temp->key = strdup(key);
    if (temp->key == NULL) {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        free(temp);
        return NULL;
    }

    temp->left = temp->right = NULL;
    return temp;
}

// Insert a new node
struct node *insert_node(struct node *root, const char *key) {
    // if the tree is empty, return a new node
    if (root == NULL) {
        struct node *temp = create_new_node(key);
        if (temp != NULL) {
            return temp;
        } else {
            fprintf(stderr, "ERROR: in 'create_new_node'\n");
            return NULL;
        }
    }

    // otherwise, recur down the tree
    if (compare(key, root->key) < 0) {
        root->left  = insert_node(root->left, key);
    } else if (compare(key, root->key) > 0) {
        root->right = insert_node(root->right, key);
    }

    // return the unchanged node pointer
    return root;
}

// Find the node with minimum key
struct node *find_min_key_node(struct node *root) {
    struct node *current = root;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Delete the node with given key
struct node *delete_node(struct node *root, const char *key) {
    if (root == NULL) {
        return root;
    }

    if (compare(key, root->key) < 0) {
        root->left = delete_node(root->left, key);
    } else if (compare(key, root->key) > 0) {
        root->right = delete_node(root->right, key);
    } else {
        // if only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free((void *)root->key);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free((void *)root->key);
            free(root);
            return temp;
        }

        // if two children: find the node which is next in order
        //(smallest in the right subtree)
        struct node *temp = find_min_key_node(root->right);

        // copy key of the node, which is next in order, to this node
        root->key = temp->key;

        // delete the node which is next in order
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

// Search node with given key
struct node *search_node(struct node *root, const char *key) {
    // base cases: root is null or key is present at root
    if (root == NULL || (compare(key, root->key) == 0)) {
       return root;
    }

    // key is greater than root's key
    if (compare(key, root->key) > 0) {
       return search_node(root->right, key);
    }

    // key is smaller than root's key
    return search_node(root->left, key);
}

// Free tree
void free_tree(struct node *root) {
    if(root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free((void *)root->key);
        free(root);
    }
}

// Pre-order traverse tree
void traverse_preorder(struct node *root) {
    if (root != NULL) {
        printf("%s ", root->key);
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }
}

// In-order traverse tree
void traverse_inorder(struct node *root) {
    if (root != NULL) {
        traverse_inorder(root->left);
        printf("%s ", root->key);
        traverse_inorder(root->right);
    }
}

// Post-order traverse tree
void traverse_postorder(struct node *root) {
    if (root != NULL) {
        traverse_postorder(root->left);
        traverse_postorder(root->right);
        printf("%s ", root->key);
    }
}


