/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include "tree.h"

struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL)
        return NULL;
    struct TreeNode * temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}