#ifndef AVL_H
#define AVL_H

typedef struct binary_tree BinaryTree;

struct binary_tree{
    int value;
    int h;
    BinaryTree *left;
    BinaryTree *right;
};

int max(int a, int b);

BinaryTree* create_empty_binary_tree();
BinaryTree* create_binary_tree(int value, BinaryTree *left, BinaryTree *right);
BinaryTree* add(BinaryTree *bt, int value);
BinaryTree* search(BinaryTree *bt, int value);
int is_empty(BinaryTree *bt);
void print_in_order(BinaryTree *bt);
void print_pre_order(BinaryTree *bt);
void print_post_order(BinaryTree *bt);
int height(BinaryTree *bt);
int is_balanced(binary_tree *bt);
int balance_factor(BinaryTree *bt);
BinatyTree* rotate_left(BinaryTree *bt);
BinatyTree* rotate_left(BinaryTree *bt);
void free_binary_tree(BinaryTree *bt);

#endif /* AVL_H */
