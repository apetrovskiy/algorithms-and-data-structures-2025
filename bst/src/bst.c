#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

static TreeNode* create_node(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node) {
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

static TreeNode* insert_node(TreeNode* node, int value) {
    if (!node) return create_node(value);
    
    if (value < node->value) {
        node->left = insert_node(node->left, value);
    } else if (value > node->value) {
        node->right = insert_node(node->right, value);
    }
    
    return node;
}

static bool search_node(const TreeNode* node, int value) {
    if (!node) return false;
    if (value == node->value) return true;
    if (value < node->value) return search_node(node->left, value);
    return search_node(node->right, value);
}

static TreeNode* find_min_node(TreeNode* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

static TreeNode* remove_node(TreeNode* node, int value, int* size) {
    if (!node) return NULL;
    
    if (value < node->value) {
        node->left = remove_node(node->left, value, size);
    } else if (value > node->value) {
        node->right = remove_node(node->right, value, size);
    } else {
        if (!node->left) {
            TreeNode* temp = node->right;
            free(node);
            (*size)--;
            return temp;
        } else if (!node->right) {
            TreeNode* temp = node->left;
            free(node);
            (*size)--;
            return temp;
        }
        
        TreeNode* temp = find_min_node(node->right);
        node->value = temp->value;
        node->right = remove_node(node->right, temp->value, size);
    }
    
    return node;
}

static void clear_nodes(TreeNode* node) {
    if (node) {
        clear_nodes(node->left);
        clear_nodes(node->right);
        free(node);
    }
}

static void pre_order_traversal(const TreeNode* node, void (*callback)(int)) {
    if (node) {
        callback(node->value);
        pre_order_traversal(node->left, callback);
        pre_order_traversal(node->right, callback);
    }
}

static void in_order_traversal(const TreeNode* node, void (*callback)(int)) {
    if (node) {
        in_order_traversal(node->left, callback);
        callback(node->value);
        in_order_traversal(node->right, callback);
    }
}

static void post_order_traversal(const TreeNode* node, void (*callback)(int)) {
    if (node) {
        post_order_traversal(node->left, callback);
        post_order_traversal(node->right, callback);
        callback(node->value);
    }
}

void bst_init(BST* tree) {
    tree->root = NULL;
    tree->size = 0;
}

bool bst_is_empty(const BST* tree) {
    return tree->root == NULL;
}

void bst_insert(BST* tree, int value) {
    tree->root = insert_node(tree->root, value);
    tree->size++;
}

bool bst_search(const BST* tree, int value) {
    return search_node(tree->root, value);
}

void bst_remove(BST* tree, int value) {
    tree->root = remove_node(tree->root, value, &tree->size);
}

int bst_size(const BST* tree) {
    return tree->size;
}

void bst_clear(BST* tree) {
    clear_nodes(tree->root);
    tree->root = NULL;
    tree->size = 0;
}

void bst_pre_order(const BST* tree, void (*callback)(int)) {
    pre_order_traversal(tree->root, callback);
}

void bst_in_order(const BST* tree, void (*callback)(int)) {
    in_order_traversal(tree->root, callback);
}

void bst_post_order(const BST* tree, void (*callback)(int)) {
    post_order_traversal(tree->root, callback);
}

int bst_min(const BST* tree, bool* success) {
    TreeNode* node = tree->root;
    if (!node) {
        *success = false;
        return 0;
    }
    
    while (node->left) {
        node = node->left;
    }
    
    *success = true;
    return node->value;
}

int bst_max(const BST* tree, bool* success) {
    TreeNode* node = tree->root;
    if (!node) {
        *success = false;
        return 0;
    }
    
    while (node->right) {
        node = node->right;
    }
    
    *success = true;
    return node->value;
}
