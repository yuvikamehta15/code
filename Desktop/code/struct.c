#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create()
{
    struct node *p;
    int item;
    printf("Enter data(-1 for no data):");
    scanf("%d",&item);

    if(item==-1)
        return NULL;

    p=(struct node*)malloc(sizeof(struct node));
    p->data=item;

    printf("Enter left child of %d:\n",item);
    p->left=create();

    printf("Enter right child of %d:\n",item);
    p->right=create();

    return p;
}
void preorder(struct node *p)        //address of root node
{
    if(p!=NULL)
    {
        printf("\t%d",p->data);        //visit the root
        preorder(p->left);        //preorder traversal on left subtree
        preorder(p->right);        //preorder traversal om right subtree
    }
}
void postorder(struct node *p)        //address of root node
{
    if(p!=NULL)
    {
        postorder(p->left);        //postorder traversal on left subtree
        postorder(p->right);        //postorder traversal om right subtree
        printf("\t%d",p->data);        //visit the root
    }
}

void inorder(struct node *p)        //address of root node
{
    if(p!=NULL)
    {
        inorder(p->left);        //inorder traversal on left subtree
        printf("\t%d",p->data);        //visit the root
        inorder(p->right);        //inorder traversal om right subtree
    }
}
int main()
{
    struct node *root;
    root=create();
    printf("\nThe Preorder traversal of tree is:\n");
    preorder(root);

    printf("\nThe Postorder traversal of tree is:\n");
    postorder(root);

    printf("\nThe Inorder traversal of tree is:\n");
    inorder(root);

    return 0;
}
