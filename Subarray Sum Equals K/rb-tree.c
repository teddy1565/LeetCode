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
    return node;
}

struct BST {
    struct Node *root_node;
    struct Node *nil_node;

    void            (*inner_rotate_right)         (struct BST *self, struct Node *node);
    void            (*inner_rotate_left)          (struct BST *self, struct Node *node);
    void            (*inner_show_inorder)         (struct BST *self);
    struct Node*    (*inner_get_smallest_child)   (struct BST *self, struct Node *node);
    bool            (*inner_delete_child)         (struct BST *self, struct Node *node, int key);
    void            (*inner_delete_one_child)     (struct BST *self, struct Node *node);
    void            (*inner_delete_case)          (struct BST *self, struct Node *node);
    void            (*inner_insert)               (struct BST *self, struct Node *node, int key, int value);
    void            (*inner_insert_case)          (struct BST *self, struct Node *node);
    void            (*inner_delete_tree)          (struct BST *self, struct Node *node);

    void            (*inner_search)               (struct BST *self, struct Node *node, int key);
    void            (*inner_update)               (struct BST *self, struct Node *node, int key, int value);

    void            (*show_inorder)               (struct BST *self);
    void            (*query)                      (struct BST *self, int key);
    void            (*insert)                     (struct BST *self, int key, int value);
    void            (*update)                     (struct BST *self, int key, int value);
    void            (*delete)                     (struct BST *self, int key);
    
} BST;

void bst_inner_rorate_right(struct BST *self, struct Node *node) {
    struct Node *grand_parent = node->get_grand_parent(node);
    struct Node *parent = node->parent;
    struct Node *y = node->right_tree;

    parent->left_tree = y;
    if (y != NULL) {
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

    if (y != NULL) {
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
    if (node->left_tree == NULL) {
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
                self->inner_rotate_left(self, node->get_sibling(node)->left_tree);

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

struct Node* bst_inner_insert(struct BST *self, struct Node *node, int key, int value) {
    if (node->key >= key) {
        if (node->left_tree != NULL) {
            self->inner_insert(self, node->left_tree, key, value);
        } else {
            struct Node *tmp_node = create_node(key, value);
            tmp_node->left_tree = NULL;
            tmp_node->right_tree = NULL;
            tmp_node->parent = node;
            node->left_tree = tmp_node;
            self->inner_insert_case(self, tmp_node);
        }
    } else {
        if (node->right_tree != NULL) {
            self->inner_insert(self, node->right_tree, key, value);
        } else {
            struct Node *tmp_node = create_node(key, value);
            tmp_node->left_tree = NULL;
            tmp_node->right_tree = NULL;
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
    if (node == NULL) {
        return;
    }
    self->inner_delete_tree(self, node->left_tree);
    self->inner_delete_tree(self, node->right_tree);

    free(node);
}


int main(void) {
    return 0;
}