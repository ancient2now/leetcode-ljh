#include "tree.h"

int main(int argc, char const *argv[])
{
    struct TreeNode *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    
    printLevelOrder(root);
    return 0;
}
