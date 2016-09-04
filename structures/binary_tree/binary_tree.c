#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

struct binary_tree{
    int value;
    BinaryTree *left;
    BinaryTree *right;
};

int max(int a, int b){
    return (a > b) ? a : b;
}

BinaryTree* create_empty_binary_tree(){
    return NULL;
}

BinaryTree* create_binary_tree(int value, BinaryTree *left, BinaryTree *right){
    BinaryTree *bt = (BinaryTree*) malloc(sizeof(BinaryTree));
    bt->value = value;
    bt->left = left;
    bt->right = right;
    return bt;
}

BinaryTree* add(BinaryTree *bt, int value){
    if (bt == NULL){
        bt = create_binary_tree(value, NULL, NULL);
    } 
    else if (bt->value > value){
        bt->left = add(bt->left, value);
    }
    else{
        bt->right = add(bt->right, value);
    }
    return bt;
}

BinaryTree* search(BinaryTree *bt, int value){
    if((bt == NULL) || (bt->value == value)){
        return bt;
    } 
    else if(bt->value > value){
        return search(bt->left, value);
    } 
    else{
        return search(bt->right, value);
    }
}

int is_empty(BinaryTree *bt) {
  return (bt == NULL);
}

void print_in_order(BinaryTree *bt){
    if (!is_empty(bt)) {
        print_in_order(bt->left);
        printf("%d", bt->value);
        print_in_order(bt->right);
    }
}

void print_pre_order(BinaryTree *bt){
    if (!is_empty(bt)) {
        printf("%d", bt->value);
        print_pre_order(bt->left);
        print_pre_order(bt->right);
    }
}

void print_post_order(BinaryTree *bt){
    if (!is_empty(bt)) {
        print_post_order(bt->left);
        print_post_order(bt->right);
        printf("%d", bt->value);
    }
}

int height(BinaryTree *bt){
    if(bt == NULL) return -1;
    else return 1 + max(height(bt->left), height(bt->right));
}

void free_binary_tree(BinaryTree *bt) {
  if(bt == NULL) return;
  free_binary_tree(bt->left);
  free_binary_tree(bt->right);
  free(bt);
}