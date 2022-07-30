#include<stdio.h>
#include<stdlib.h>
typedef struct tree {
    int key;
    int data;
    struct tree* left;
    struct tree* right;
};


  struct tree* getnode(int data)
{
   struct tree* root = ( struct tree*)malloc(sizeof( struct tree));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return (root);
}
 struct tree* BST_in(struct tree**root,int key)
{
    if((*root)==NULL)
        (*root)=getnode(key);
    else if(key<(*root)->data)
       BST_in((*root)->left,key);
    else if(key>(*root)->data)
       BST_in((*root)->right,key);
}
int inorder(struct tree* root)
{
    /*if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
   */
    if(root!=NULL){
        if(root->left!=NULL)
        inorder(root->left);
        if(root->right!=NULL)
        inorder(root->right);
        printf("%d",root->data);
}
}
int main()
{
    int key;
     struct tree* root=NULL;
     root=getnode(50);
     getnode(30);
     getnode(20);
     getnode(40);
     getnode(70);
     getnode(60);
     getnode(80);
    BST_in(root,key);
     inorder(root);
    return 0;
}
