#include "tree.h"
void printLevelOrder(tree *root){
    int height = tree_height(root);
    for(int i = 1; i <= height; i++){
        printGivenLevel(root, i);
        puts("");
    }
}
void printGivenLevel(tree* root, int level){
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d ", root->val);
    else if(level > 1){
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
int tree_height(tree* node){
    if(node == NULL)
        return 0;
    int left_height = tree_height(node->left);
    int right_height = tree_height(node->right);
    
    if(left_height > right_height)
        return left_height+1;
    else
        return right_height+1;
}
tree* newNode(int data){
    tree * node = (tree*)malloc(sizeof(tree));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}