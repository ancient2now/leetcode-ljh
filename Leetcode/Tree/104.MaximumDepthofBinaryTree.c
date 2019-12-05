#include "tree.h"

int maxDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    int left = 0;
    left += maxDepth(root->left)+1;
    int right = 0;
    right += maxDepth(root->right)+1;
    return left > right ? left : right;
}

int main(int argc, char const *argv[])
{
    tree * root = newNode(1);
    tree * node1 = newNode(2);
    tree * node2 = newNode(3);
    tree * node3 = newNode(4);
    node2->right = node3;

    root->left = node1;
    root->right = node2;
    int ret = maxDepth(root);
    printf("%d\n", ret);
    return 0;
}
