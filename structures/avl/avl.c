#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

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

int height(BinaryTree *bt){
    if(bt == NULL) return -1;
    else return 1 + max(height(bt->left), height(bt->right));
}

int balance_factor(BinaryTree *bt){
  if (bt == NULL) {
    return 0;
  } 
  else if ((bt->left != NULL) && (bt->right != NULL)) {
    return (bt->left->h - bt->right->h);
  } 
  else if ((bt->left != NULL) && (bt->right == NULL)) {
    return (1 + bt->left->h);
  } 
  else {
    return (-bt->right->h - 1);
  }
}

int is_balanced(BinaryTree *bt){
  int bf = height(bt->left) – height(bt->right);
  return ((-1 <= bf) && (bf <= 1));
}

BinaryTree* rotate_left(BinaryTree *bt){
  BinaryTree *subtree_root = NULL;
  if (bt != NULL && bt->right != NULL) {
    subtree_root = bt->right;
    bt->right = subtree_root->left;
    subtree_root->left = bt;
  }
  subtree_root->h = height(subtree_root);
  bt->h = height(bt);
  return subtree_root;
}

BinaryTree* rotate_right(BinaryTree *bt){
  BinaryTree *subtree_root = NULL;
  if (bt != NULL && bt->left != NULL) {
    subtree_root = bt->left;
    bt->left = subtree_root->right;
    subtree_root->right = bt;
  }
  subtree_root->h = height(subtree_root);
  bt->h = height(bt);
  return subtree_root;
}

BinaryTree* add(BinaryTree *bt, int item){
  if (bt == NULL) {
    return create_binary_tree(item, NULL, NULL);
  } 
  else if (bt->item > item) {
    bt->left = add(bt->left, item);
  } 
  else {
    bt->right = add(bt->right, item);
  }
  bt->h = h(bt);
  BinaryTree *child;
  if (balance_factor(bt) == 2 || balance_factor(bt) == -2) {
    if (balance_factor(bt) == 2) {
      child = bt->left;
      if (balance_factor(child) == -1) {
        bt->left = rotate_left(child);
      }
      bt = rotate_right(bt);
    } 
    else if (balance_factor(bt) == -2) {
      child = bt->right;
      if (balance_factor(child) == 1) {
        bt->right = rotate_right(child);
      }
      bt = rotate_left(bt);
    }
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



void free_binary_tree(BinaryTree *bt) {
  if(bt == NULL) return;
  free_binary_tree(bt->left);
  free_binary_tree(bt->right);
  free(bt);
}