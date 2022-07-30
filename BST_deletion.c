#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
    struct tree*left;
    struct tree*right;
    int data;
    };
struct tree* getnode(int data){

   struct tree* temp=(struct tree*)malloc(sizeof(struct tree));
   temp->data=data;
   temp->left=temp->right=NULL;
   return temp;
    }
    struct tree* insert(struct tree* root,int key){
        if((root)==NULL)
            return getnode(key);
        else if((root)->data>key)
            (root)->left=insert((root)->left,key);
        else if((root)->data<key)
            (root)->right=insert((root)->right,key);
            else
                return root;
        }
   struct tree*inorder(struct tree* root){
        if(root!=NULL)
        {
                inorder( root->left);
            printf("%d",root->data);
                inorder(root->right);
        }
        }
        struct tree* minValueNode(struct tree* node)
{
    struct tree* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
        struct tree* deleteNode(struct tree* root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct tree* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct tree* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct tree* temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int main()
{
   struct tree* root=(struct tree*)malloc(sizeof(struct tree));
   root=NULL;
    int data;
    root=insert(root,10);
    insert(root,3);
    insert(root,14);
    insert(root,2);
    insert(root,8);

    printf("BEFORE INSERTION::");
    inorder(root);

    printf("\nAFTER DELETION::");
    root=deleteNode(root,8);
    inorder(root);
    return 0;
}

