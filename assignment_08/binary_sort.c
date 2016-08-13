//Binary tree
#include<stdlib.h>
#include<stdio.h>

struct bin_tree {
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}


void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}


void main()
{
    node *root;
    node *tmp;
    int n,nn;
    int i;

    root = NULL;
    /* Inserting nodes into tree */
    printf("enter number of element to be inserted:");
    scanf("%d",&nn);
    printf("\n");
    for(i=0;i<nn;i++){
    printf("\nenter element to be inserted:");
    scanf("%d",&n);
    insert(&root, n);
    }

    /* Printing nodes of tree in sorted form*/


    printf("Sorted array:\n");
    print_inorder(root);

}

