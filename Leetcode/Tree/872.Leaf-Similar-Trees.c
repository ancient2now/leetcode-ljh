#include "tree.h"

typedef struct StackNode{
    tree * tree_node;
    struct StackNode * next;
}stack;
struct TreeNode* pop(stack ** s);
bool isEmptyStack(stack * s);
void push(stack ** s, struct TreeNode * t);


bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    stack * t1 = NULL;
    stack * t2 = NULL;
    int count1[63] = {0};
    int count2[63] = {0};
    int index1 = 0;
    int index2 = 0;
    struct TreeNode* temp1 = root1;
    struct TreeNode* temp2 = root2;

    while(true){
        if(temp1 != NULL)
        {
            push(&t1, temp1);
            temp1 = temp1->left;
        }else
        {
            if(!isEmptyStack(t1)){
                temp1 = pop(&t1);
                if(temp1->right == NULL && temp1->left == NULL){
                    count1[index1++] = temp1->val;
                }
                temp1 = temp1->right;
            }else
            {
                break;
            }
        }
    }
    while(true){
        if(temp2 != NULL)
        {
            push(&t2, temp2);
            temp2 = temp2->left;
        }else
        {
            if(!isEmptyStack(t2)){
                temp2 = pop(&t2);
                if(temp2->right == NULL && temp2->left == NULL){
                    count2[index2++] = temp2->val;
                }
                temp2 = temp2->right;
            }else
            {
                break;
            }
        }
    }
    if(index1 != index2)
        return false;
    for(int i = 0; i < index1; i++){
        if(count1[i] != count2[i])
            return false;
    }
    return true;
}

bool isEmptyStack(stack * s){
    return s == NULL ? true : false;
}
void push(stack ** s, struct TreeNode * t){
    stack * new = malloc(sizeof(stack));
    new->tree_node = t;

    new->next = *s;
    *s = new;
    
}
struct TreeNode * pop(stack ** s){
    if(isEmptyStack(*s))
        return NULL;
    struct TreeNode * ret = (*s)->tree_node;
    *s = (*s)->next;
    return ret;
}

int main(int argc, char const *argv[])
{
    tree * root1 = newNode(1);
    tree * root2 = newNode(2);

    tree * root3 = newNode(2);
    tree * root4 = newNode(2);

    root1->left = root2;
    root1->right = NULL;

    root3->left = root4;
    root3->right = NULL;


    bool ret = leafSimilar(root1, root3);
    printf(ret ? "true\n":"false\n");

    return 0;
}

