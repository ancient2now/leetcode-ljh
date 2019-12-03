#ifndef __TREE_H__
#define __TREE_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int data_type;
typedef struct TreeNode {
    data_type val;
    struct TreeNode *left;
    struct TreeNode *right;
}tree;

extern void printLevelOrder(tree *root);
extern void printGivenLevel(tree* root, int level); 
extern int tree_height(tree* node); 
extern tree* newNode(data_type data); 


#endif