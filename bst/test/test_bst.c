#include "../src/bst.h"
#include <assert.h>
#include <stdio.h>

static void print_value(int value) {
    printf("%d ", value);
}

void test_bst_operations() {
    BST tree;
    bst_init(&tree);
    bool success;
    
    assert(bst_is_empty(&tree));
    assert(bst_size(&tree) == 0);
    
    bst_insert(&tree, 50);
    assert(!bst_is_empty(&tree));
    assert(bst_size(&tree) == 1);
    assert(bst_search(&tree, 50));
    
    bst_insert(&tree, 30);
    bst_insert(&tree, 70);
    bst_insert(&tree, 20);
    bst_insert(&tree, 40);
    bst_insert(&tree, 60);
    bst_insert(&tree, 80);
    
    assert(bst_size(&tree) == 7);
    
    assert(bst_search(&tree, 30));
    assert(bst_search(&tree, 80));
    assert(!bst_search(&tree, 100));
    
    assert(bst_min(&tree, &success) == 20);
    assert(success);
    assert(bst_max(&tree, &success) == 80);
    assert(success);
    
    bst_remove(&tree, 20);
    assert(!bst_search(&tree, 20));
    assert(bst_size(&tree) == 6);
    
    bst_remove(&tree, 30); 
    assert(!bst_search(&tree, 30));
    assert(bst_search(&tree, 40));
    assert(bst_size(&tree) == 5);
    
    bst_remove(&tree, 50);
    assert(!bst_search(&tree, 50));
    assert(bst_search(&tree, 60));
    assert(bst_size(&tree) == 4);
    
    printf("In-order traversal: ");
    bst_in_order(&tree, print_value);
    printf("\n");
    
    printf("Pre-order traversal: ");
    bst_pre_order(&tree, print_value);
    printf("\n");
    
    printf("Post-order traversal: ");
    bst_post_order(&tree, print_value);
    printf("\n");
    
    bst_clear(&tree);
    assert(bst_is_empty(&tree));
    assert(bst_size(&tree) == 0);
    
    printf("BST tests passed!\n");
}

int main() {
    test_bst_operations();
    return 0;
}
