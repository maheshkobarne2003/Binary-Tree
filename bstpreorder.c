#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left,*right;
};

struct node *create(struct node *root)
{
    int i,n,num;
    struct node *parent,*newnode,*temp;
    printf("enter limit:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter value:");
        scanf("%d",&num);
        newnode->data=num;
        newnode->left=NULL;
        newnode->right=NULL;
        if(root==NULL)
        {
            root=newnode;
            continue;
        } 
        temp=root; 
        while(temp!=NULL) 
        {
            parent=temp;  
            if(num<temp->data)
               temp=temp->left;
            else
               temp=temp->right;
        }
        if(num<parent->data)
           parent->left=newnode;
        else
           parent->right=newnode;
    }
    return root;
}

void preorder(struct node *root)
{
    struct node *temp=root;
    if(temp!=NULL)
    {
        printf("%d\t",temp->data);
        preorder(temp->left); 
        preorder(temp->right);
    }
}

int main()
{
    struct node *root=NULL;
    root=create(root);
    printf("\ndisplay preorder:");
    preorder(root);
}