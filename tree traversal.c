#include <stdio.h>
#include <stdlib.h>

 typedef struct tree {
    int val;
    struct tree* left;
    struct tree* right;
};

typedef struct tree TreeNode;

TreeNode* newTree(int data)
{
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = data;
    root->left = NULL;
    root->right = NULL;
    return (root);
}

void preorder(TreeNode* root)
{

    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}
void postorder(TreeNode* root){
    if(root!=NULL){
        if(root->left!=NULL)
        postorder(root->left);
        printf("%d",root->val);
        if(root->right!=NULL)
        postorder(root->right);
    }
}
void inorder(TreeNode *root){
    if(root!=NULL){
        if(root->left!=NULL)
        inorder(root->left);
        if(root->right!=NULL)
        inorder(root->right);
        printf("%d",root->val);
    }
}

int main()
{
    //building the tree
    TreeNode* t = newTree(1);
    t->left = newTree(2);
    t->left->left = newTree(3);
    t->left->right = newTree(4);
    t->left->right->left = newTree(5);
    t->left->right->right = newTree(6);
    t->left->right->right->left = newTree(7);
    t->left->right->right->right = newTree(8);
    t->right = newTree(9);
    t->right->left = newTree(10);
    t->right->right = newTree(11);
    printf("\n\n------ALL TREE TRAVERSAL IS-------\n\n");
    printf("Preorder traversal of the above tree is:\nj\n");
    preorder(t);
    printf("\npostorder traversal of the above tree is:\n\n");
    postorder(t);
    printf("\ninorder traversal of the above tree is:\n\n");
    inorder(t);

    return 0;
}
