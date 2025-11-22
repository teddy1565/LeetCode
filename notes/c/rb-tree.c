#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>
#include <math.h>
#include <stdalign.h>
#include <assert.h>
#include <limits.h>

#define BLACK 1
#define RED 0

struct Node {

    int key;
    int value;
    bool color;

    struct Node *left_tree;
    struct Node *right_tree;
    struct Node *parent;

    struct Node* (*get_grand_parent)(struct Node *self);
    struct Node* (*get_uncle)(struct Node *self);
    struct Node* (*get_sibling)(struct Node *self);

} Node;

struct Node* get_grand_parent(struct Node *self) {
    if (self->parent == NULL) {
        return NULL;
    }
    return self->parent->parent;
}

struct Node* get_uncle(struct Node *self) {
    if (self->get_grand_parent(self) == NULL) {
        return NULL;
    }
    if (self->parent == self->get_grand_parent(self)->right_tree) {
        return self->get_grand_parent(self)->left_tree;
    } else {
        return self->get_grand_parent(self)->right_tree;
    }
}

struct Node* get_sibling(struct Node *self) {
    if (self->parent->left_tree == self) {
        return self->parent->right_tree;
    } else {
        return self->parent->left_tree;
    }
}

/**
 * @brief Create a node object | just basic
 * 
 * @param key 
 * @param value 
 * @return struct Node* 
 */
struct Node* create_node(int key, int value) {
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));
    node->key = key;
    node->value = value;
    node->color = RED;
    node->get_grand_parent = get_grand_parent;
    node->get_sibling = get_sibling;
    node->get_uncle = get_uncle;
    node->right_tree = NULL;
    node->left_tree = NULL;
    node->parent = NULL;
    return node;
}

struct BST {
    struct Node *root_node;
    struct Node *nil_node;

    void            (*inner_rotate_right)         (struct BST *self, struct Node *node);
    void            (*inner_rotate_left)          (struct BST *self, struct Node *node);
    void            (*inner_show_inorder)         (struct BST *self, struct Node *node, int stack);
    struct Node*    (*inner_get_smallest_child)   (struct BST *self, struct Node *node);
    bool            (*inner_delete_child)         (struct BST *self, struct Node *node, int key);
    void            (*inner_delete_one_child)     (struct BST *self, struct Node *node);
    void            (*inner_delete_case)          (struct BST *self, struct Node *node);
    void            (*inner_insert)               (struct BST *self, struct Node *node, int key, int value);
    void            (*inner_insert_case)          (struct BST *self, struct Node *node);
    void            (*inner_delete_tree)          (struct BST *self, struct Node *node);

    int *           (*inner_search)               (struct BST *self, struct Node *node, int key);
    void            (*inner_update)               (struct BST *self, struct Node *node, int key, int value);

    void            (*show_inorder)               (struct BST *self);
    int *           (*query)                      (struct BST *self, int key);
    void            (*insert)                     (struct BST *self, int key, int value);
    void            (*update)                     (struct BST *self, int key, int value);
    void            (*delete)                     (struct BST *self, int key);
    
} BST;


int* bst_inner_search(struct BST *self, struct Node *node, int key) {

    if (node == NULL) {
        return NULL;
    } else if (node->key == key) {
        return &(node->value);
    }

    if (node->key > key) {
        return self->inner_search(self, node->left_tree, key);
    }

    return self->inner_search(self, node->right_tree, key);
}

int* bst_outer_query(struct BST *self, int key) {
    if (self->root_node == NULL) {
        return NULL;
    }
    return self->inner_search(self, self->root_node, key);
}

void bst_inner_rorate_right(struct BST *self, struct Node *node) {
    struct Node *grand_parent = node->get_grand_parent(node);
    struct Node *parent = node->parent;
    struct Node *y = node->right_tree;

    parent->left_tree = y;
    if (y != self->nil_node) {
        y->parent = parent;
    }
    node->right_tree = parent;
    parent->parent = node;

    if (self->root_node == parent) {
        self->root_node = node;
    }
    node->parent = grand_parent;

    if (grand_parent != NULL) {
        if (grand_parent->left_tree == parent) {
            grand_parent->left_tree = node;
        } else {
            grand_parent->right_tree = node;
        }
    }
}

void bst_inner_rorate_left(struct BST *self, struct Node *node) {
    if (node->parent == NULL) {
        self->root_node =  node;
        return;
    }

    struct Node *grand_parent = node->get_grand_parent(node);
    struct Node *parent = node->parent;
    struct Node *y = node->left_tree;

    parent->right_tree = y;

    if (y != self->nil_node) {
        y->parent = parent;
    }
    node->left_tree = parent;
    parent->parent = node;

    if (self->root_node == parent) {
        self->root_node = node;
    }
    node->parent = grand_parent;

    if (grand_parent != NULL) {
        if (grand_parent->left_tree == parent) {
            grand_parent->left_tree = node;
        } else {
            grand_parent->right_tree = node;
        }
    }
}

struct Node* bst_inner_get_smallest_child(struct BST *self, struct Node *node) {
    if (node->left_tree == self->nil_node) {
        return node;
    }
    return self->inner_get_smallest_child(self, node->left_tree);
}

void bst_inner_delete_case(struct BST *self, struct Node *node) {
    if (node->parent == NULL) {
        node->color = BLACK;
        return;
    }

    if (node->get_sibling(node)->color == RED) {

        node->parent->color = RED;
        node->get_sibling(node)->color = BLACK;

        if (node == node->parent->left_tree) {

            self->inner_rotate_left(self, node->parent);

        } else {

            self->inner_rotate_right(self, node->parent);

        }
    }

    if (    
            node->parent->color == BLACK &&
            node->get_sibling(node)->color == BLACK && 
            node->get_sibling(node)->left_tree->color == BLACK &&
            node->get_sibling(node)->right_tree->color == BLACK

    ) {

        node->get_sibling(node)->color = RED;
        self->inner_delete_case(self, node->parent);
    
    } else if (
                node->parent->color == RED &&
                node->get_sibling(node)->color == BLACK &&
                node->get_sibling(node)->left_tree->color == BLACK &&
                node->get_sibling(node)->right_tree->color == BLACK
    ) {

        node->get_sibling(node)->color = RED;
        node->parent->color = BLACK;

    } else {
        if (node->get_sibling(node)->color == BLACK) {
            if (
                node == node->parent->left_tree &&
                node->get_sibling(node)->left_tree->color == RED &&
                node->get_sibling(node)->right_tree->color == BLACK
            )
            {

                node->get_sibling(node)->color = RED;
                node->get_sibling(node)->left_tree->color = BLACK;
                self->inner_rotate_right(self, node->get_sibling(node)->left_tree);

            } else if (
                        node == node->parent->right_tree &&
                        node->get_sibling(node)->left_tree->color == BLACK &&
                        node->get_sibling(node)->right_tree->color == RED
            )
            {
                node->get_sibling(node)->color = RED;
                node->get_sibling(node)->right_tree->color = BLACK;
                self->inner_rotate_left(self, node->get_sibling(node)->right_tree);
            }
        }

        node->get_sibling(node)->color = node->parent->color;
        node->parent->color = BLACK;

        if (node == node->parent->left_tree) {
            node->get_sibling(node)->right_tree->color = BLACK;
            self->inner_rotate_left(self, node->get_sibling(node));
        } else {
            node->get_sibling(node)->left_tree->color = BLACK;
            self->inner_rotate_right(self, node->get_sibling(node));
        }
    } 
}

void bst_inner_insert(struct BST *self, struct Node *node, int key, int value) {
    if (node->key == key) {
        node->value = value;
    } else if (node->key > key) {
        if (node->left_tree != self->nil_node) {
            self->inner_insert(self, node->left_tree, key, value);
        } else {
            struct Node *tmp_node = create_node(key, value);
            tmp_node->left_tree = self->nil_node;
            tmp_node->right_tree = self->nil_node;
            tmp_node->parent = node;
            node->left_tree = tmp_node;
            self->inner_insert_case(self, tmp_node);
        }
    } else {
        if (node->right_tree != self->nil_node) {
            self->inner_insert(self, node->right_tree, key, value);
        } else {
            struct Node *tmp_node = create_node(key, value);
            tmp_node->left_tree = self->nil_node;
            tmp_node->right_tree = self->nil_node;
            tmp_node->parent = node;
            node->right_tree = tmp_node;
            self->inner_insert_case(self, tmp_node);
        }
    }
}

void bst_inner_insert_case(struct BST *self, struct Node *node) {
    if (node->parent == NULL) {
        self->root_node = node;
        node->color = BLACK;
        return;
    }

    if (node->parent->color == RED) {
        if (node->get_uncle(node)->color == RED) {

            node->parent->color = BLACK;
            node->get_uncle(node)->color = BLACK;
            node->get_grand_parent(node)->color = RED;
            self->inner_insert_case(self, node->get_grand_parent(node));

        } else {
            if (node->parent->right_tree == node && node->get_grand_parent(node)->left_tree == node->parent) {
                
                self->inner_rotate_left(self, node);
                node->color = BLACK;
                node->parent->color = RED;
                self->inner_rotate_right(self, node);

            } else if (node->parent->left_tree == node && node->get_grand_parent(node)->right_tree == node->parent) {
                
                self->inner_rotate_right(self, node);
                node->color = BLACK;
                node->parent->color = RED;
                self->inner_rotate_left(self, node);

            } else if (node->parent->left_tree == node && node->get_grand_parent(node)->left_tree == node->parent) {
                
                node->parent->color = BLACK;
                node->get_grand_parent(node)->color = RED;
                self->inner_rotate_right(self, node->parent);

            } else if (node->parent->right_tree == node && node->get_grand_parent(node)->right_tree == node->parent) {
                
                node->parent->color = BLACK;
                node->get_grand_parent(node)->color = RED;
                self->inner_rotate_left(self, node->parent);

            }
        }
    }
}

void bst_inner_delete_tree(struct BST *self, struct Node *node) {
    if (node == NULL || node == self->nil_node) {
        return;
    }
    self->inner_delete_tree(self, node->left_tree);
    self->inner_delete_tree(self, node->right_tree);

    free(node);
    node = NULL;
}

void bst_inner_delete_one_child(struct BST *self, struct Node *node) {
    struct Node *child = node->left_tree;
    if (node->left_tree == self->nil_node) {
        child = node->right_tree;
    }

    if (node->parent == NULL && node->left_tree == self->nil_node && node->right_tree == self->nil_node) {
        free(node);
        node = NULL;
        self->root_node = NULL;
        return;
    }
    
    if (node->parent == NULL) {
        child->parent = NULL;
        self->root_node = child;
        self->root_node->color = BLACK;
        free(node);
        node = NULL;
        return;
    }

    if (node->parent->left_tree == node) {
        node->parent->left_tree = child;
    } else {
        node->parent->right_tree = child;
    }
    child->parent = node->parent;

    if (node->color == BLACK) {
        if (child->color == RED) {
            child->color = BLACK;
        } else {
            self->inner_delete_case(self, child);
        }
    }

    free(node);
    node = NULL;
}

bool bst_inner_delete_child(struct BST* self, struct Node *node, int key) {
    if (node->key > key) {

        if (node->left_tree == self->nil_node) {
            return false;
        }
        return self->inner_delete_child(self, node->left_tree, key);

    } else if (node->key < key) {

        if (node->right_tree == self->nil_node) {
            return false;
        }
        return self->inner_delete_child(self, node->right_tree, key);

    } else if (node->key == key) {

        if (node->right_tree == self->nil_node) {
            self->inner_delete_one_child(self, node);
            return true;
        }
        
        struct Node *smallest = self->inner_get_smallest_child(self, node->right_tree);
        int tmp_k = node->key;
        int tmp_v = node->value;

        node->key = smallest->key;
        node->value = smallest->value;

        smallest->key = tmp_k;
        smallest->value = tmp_v;

        self->inner_delete_one_child(self, smallest);
        return true;
    } else {
        return false;
    }
}

void bst_inner_show_inorder(struct BST* self, struct Node *node, int stack) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < stack; i++) {
        printf("        ");
    }
    printf("%d: %d\n", node->key, node->value);

    if (node->left_tree != NULL) {
        self->inner_show_inorder(self, node->left_tree, stack + 1);
    }

    if (node->right_tree != NULL) {
        self->inner_show_inorder(self, node->right_tree, stack + 1);
    }
}

void bst_outer_insert(struct BST* self, int key, int value) {
    if (self->root_node == NULL) {
        self->root_node = create_node(key, value);
        self->root_node->left_tree = self->nil_node;
        self->root_node->right_tree = self->nil_node;
        self->root_node->color = BLACK;
    } else {
        self->inner_insert(self, self->root_node, key, value);
    }
}

void bst_outer_show_inorder(struct BST* self) {
    if (self->root_node == NULL) {
        return;
    }
    self->inner_show_inorder(self, self->root_node, 0);
    printf("\n");
}

struct BST* create_bst() {
    struct BST* bst = (struct BST *) malloc(sizeof(struct BST));
    bst->root_node = NULL;
    bst->nil_node = create_node(INT_MIN, 0);
    bst->nil_node->color = BLACK;

    bst->inner_delete_case = bst_inner_delete_case;
    bst->inner_delete_child = bst_inner_delete_child;
    bst->inner_delete_one_child = bst_inner_delete_one_child;
    bst->inner_delete_tree = bst_inner_delete_tree;
    bst->inner_get_smallest_child = bst_inner_get_smallest_child;
    bst->inner_insert_case = bst_inner_insert_case;
    bst->inner_insert = bst_inner_insert;
    bst->inner_rotate_left = bst_inner_rorate_left;
    bst->inner_rotate_right = bst_inner_rorate_right;
    bst->inner_search = bst_inner_search;

    bst->show_inorder = bst_outer_show_inorder;
    bst->inner_show_inorder = bst_inner_show_inorder;
    bst->insert = bst_outer_insert;
    bst->query = bst_outer_query;
    return bst;
}

void free_bst(struct BST *bst) {
    if (bst != NULL && bst->root_node != NULL) {
        bst->inner_delete_tree(bst, bst->root_node);
    }
    
    if (bst->nil_node != NULL) {
        free(bst->nil_node);
        bst->nil_node = NULL;
    }

    if (bst != NULL) {
        free(bst);
        bst = NULL;
    }
}

int main(void) {
    struct BST* bst = create_bst();
    bst->insert(bst, 7, 1);
    bst->insert(bst, 14, 2);
    bst->insert(bst, -4, 3);
    bst->insert(bst, 7, 2);


    bst->show_inorder(bst);

    bst->insert(bst, 15, 3);
    bst->insert(bst, 101, 3);
    bst->insert(bst, 93, 3);
    bst->insert(bst, 88, 3);
    
    bst->show_inorder(bst);
    int *n = bst->query(bst, 7);
    if (n != NULL) {
        printf("key: %d, val: %d\n", 7, (*n));
    }

    free_bst(bst);
    return 0;
}