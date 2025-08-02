#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* root;
    int size;
} BST;

void bst_init(BST* tree);
bool bst_is_empty(const BST* tree);
void bst_insert(BST* tree, int value);
bool bst_search(const BST* tree, int value);
void bst_remove(BST* tree, int value);
int bst_size(const BST* tree);
void bst_clear(BST* tree);
void bst_pre_order(const BST* tree, void (*callback)(int));
void bst_in_order(const BST* tree, void (*callback)(int));
void bst_post_order(const BST* tree, void (*callback)(int));
int bst_min(const BST* tree, bool* success);
int bst_max(const BST* tree, bool* success);

#endif
