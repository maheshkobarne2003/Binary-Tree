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

void inorder(struct node *root)
{
    struct node *temp=root;
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
    }
}

struct node *treecopy(struct node *root)
{
    struct node *newnode,*temp=root;
    if(temp!=NULL)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=temp->data;
        newnode->left=treecopy(temp->left);
        newnode->right=treecopy(temp->right);
        return newnode;
    }
    else 
    return NULL;
}

int main()
{
    struct node *root1=NULL,*root2=NULL;
    root1=create(root1);
    printf("\ndisplay");
    inorder(root1);
    root2=treecopy(root1);
    printf("\ncopied tree");
    inorder(root2);

}